#include "EcsLib.h"


#if (defined flagPOSIX && defined flagSCREEN && defined flagOGL)
NAMESPACE_PARALLEL_BEGIN
GfxAccelAtom<X11OglGfx>& Get_ScrX11Ogl_Ogl(One<ScrX11Ogl::NativeSinkDevice>& dev);
NAMESPACE_PARALLEL_END
#endif


NAMESPACE_ECS_BEGIN


void Renderable::Initialize() {
	Engine& e = GetEngine();
	RenderingSystemRef rend = e.TryGet<RenderingSystem>();
	if (rend)
		rend->AddRenderable(AsRef<ComponentBase>());
}

void Renderable::Uninitialize() {
	Engine& e = GetEngine();
	RenderingSystemRef rend = e.TryGet<RenderingSystem>();
	if (rend)
		rend->RemoveRenderable(AsRef<ComponentBase>());
}



bool RenderingSystem::Initialize() {
	return true;
}

ModelRef RenderingSystem::GetAddModelFile(String path) {
	int i = model_cache.Find(path);
	if (i >= 0)
		return model_cache[i].GetModel();
	ModelLoader& l = model_cache.Add(path);
	l.LoadModel(path);
	return l.GetModel();
}

#ifdef flagSDL2
void RenderingSystem::Attach(String key, Parallel::BufferT<SdlSwGfx>* b) {
	if (key != "ecs") {
		RTLOG("RenderingSystem::Attach: warning: skipping unrelated key '" << key << "'");
		return;
	}
	
	TODO
	
}
#ifdef flagOGL
void RenderingSystem::Attach(String key, Parallel::BufferT<SdlOglGfx>* b) {
	if (key != "ecs") {
		RTLOG("RenderingSystem::Attach: warning: skipping unrelated key '" << key << "'");
		return;
	}
	
	TODO
	
}
#endif
#endif

void RenderingSystem::AddViewable(ViewableRef v) {
	ASSERT(v);
	ArrayFindAdd(views, v);
}

void RenderingSystem::RemoveViewable(ViewableRef v) {
	ASSERT(v);
	ArrayRemoveKey(views, v);
}

void RenderingSystem::AddRenderable(RenderableRef b) {
	ASSERT(b);
	ArrayFindAdd(rends, b);
}

void RenderingSystem::RemoveRenderable(RenderableRef b) {
	ASSERT(b);
	ArrayRemoveKey(rends, b);
}

void RenderingSystem::AddModel(ModelComponentRef m) {
	ASSERT(m);
	ArrayFindAdd(models, m);
}

void RenderingSystem::RemoveModel(ModelComponentRef m) {
	ASSERT(m);
	ArrayRemoveKey(models, m);
}

void RenderingSystem::AddCamera(CameraBase& c) {
	VectorFindAdd(cams, &c);
}

void RenderingSystem::RemoveCamera(CameraBase& c) {
	VectorRemoveKey(cams, &c);
}

void RenderingSystem::Start() {
	
}


void RenderingSystem::Update(double dt) {
	time += dt;
	
	if (is_dummy)
		return;
	
	if (!state) {
		Serial::Machine& mach = Serial::GetActiveMachine();
		SpaceStoreRef ents = mach.Get<SpaceStore>();
		
		#if (defined flagPOSIX && defined flagSCREEN)
		RefT_Atom<X11SwFboProg> x11_fbo = ents->GetRoot()->FindDeep<X11SwFboProg>();
		if (!state && x11_fbo) {
			state = &x11_fbo->data;
		}
		#ifdef flagOGL
		RefT_Atom<X11OglFboProg> x11_ogl_fbo = ents->GetRoot()->FindDeep<X11OglFboProg>();
		if (!state && x11_ogl_fbo) {
			state = &x11_ogl_fbo->data;
		}
		RefT_Atom<X11OglSinkDevice> x11_ogl_sink = ents->GetRoot()->FindDeep<X11OglSinkDevice>();
		if (!state && x11_ogl_sink) {
			state = &Get_ScrX11Ogl_Ogl(x11_ogl_sink->dev).GetBuffer().GetState();
		}
		#endif
		#endif
		
		#ifdef flagSDL2
		#ifdef flagOGL
		RefT_Atom<SdlOglFboProg> sdl2_ogl_fbo = ents->GetRoot()->FindDeep<SdlOglFboProg>();
		if (!state && sdl2_ogl_fbo) {
			state = &sdl2_ogl_fbo->data;
		}
		#endif
		#endif
		#ifdef flagVR
		
		#endif
		if (!state) return;
	}
	
	#if 1
	double phase_time = 3.0;
	float f = time / phase_time;
	float f2 = 1 - fabs(2 * f - 1);
	float angle = f * (2.0 * M_PI);
	state->light_dir = vec3 {sin(angle), 0.0, cos(angle)};
	#endif
	
	for (ModelComponentRef& m : models) {
		
		m->Load(*state);
		
	}
	
	for (CameraBase* cb : cams) {
		if (calib.is_enabled) {
			cb->calib = calib;
			cb->UpdateCalibration();
		}
		
		cb->Load(*state);
	}
	
}

void RenderingSystem::Stop() {
	
}

void RenderingSystem::Uninitialize() {
	ASSERT_(rends.IsEmpty(), "RenderingSystem must be added to Engine before EntityStore");
	
}

bool RenderingSystem::Arg(String key, Object value) {
	
	if (key == "dummy")
		is_dummy = value.ToString() == "true";
	
	return true;
}

void RenderingSystem::Render(GfxDataState& data) {
	
	TODO
	
}

void RenderingSystem::CalibrationEvent(CtrlEvent& ev) {
	
	if (ev.type == EVENT_HOLO_CALIB) {
		calib.is_enabled = true;
		
		switch (ev.n) {
			case HOLO_CALIB_FOV:		calib.fov += ev.fvalue; break;
			case HOLO_CALIB_SCALE:		calib.scale += ev.fvalue; break;
			case HOLO_CALIB_EYE_DIST:	calib.eye_dist += ev.fvalue; break;
			case HOLO_CALIB_X:			calib.position[0] += ev.fvalue; break;
			case HOLO_CALIB_Y:			calib.position[1] += ev.fvalue; break;
			case HOLO_CALIB_Z:			calib.position[2] += ev.fvalue; break;
			case HOLO_CALIB_YAW:		calib.axes[0] += ev.fvalue; break;
			case HOLO_CALIB_PITCH:		calib.axes[1] += ev.fvalue; break;
			case HOLO_CALIB_ROLL:		calib.axes[2] += ev.fvalue; break;
			default: Panic("invalid holographic calibration subtype");
		}
		
		calib.Dump();
	}
	
}



NAMESPACE_ECS_END