#include "SerialLib.h"

NAMESPACE_PARALLEL_BEGIN


RendererBase::RendererBase() {
	sz = Size(TS::default_width, TS::default_height);
	
	if (0) {
		obj = "cube.obj";
	}
	else {
		obj = "african_head" DIR_SEPS "african_head.obj";
	}
}

void RendererBase::Initialize() {
	//DON'T do something like: Serial::FboAtomT<Gfx>::Latest().AddBinder(this);
}

void RendererBase::Uninitialize() {
	//DON'T do something like: Serial::FboAtomT<Gfx>::Latest().RemoveBinder(this);
	loader.Clear();
}

bool RendererBase::Arg(const String& key, const String& value) {
	
	if (key == "use.pbr") {
		use_pbr = value == "true";
	}
	else if (key == "model") {
		obj = value;
	}
	else if (key == "skybox.diffuse") {
		have_skybox = true;
		skybox_diffuse = value;
	}
	else if (key == "skybox.irradiance") {
		have_skybox = true;
		skybox_irradiance = value;
	}
	else if (key == "width") {
		sz.cx = StrInt(value);
	}
	else if (key == "height") {
		sz.cy = StrInt(value);
	}
	else return false;
	
	return true;
}

bool RendererBase::Render(Draw& fb) {
	using DataState = GfxStateDraw;
	using ModelState = GfxModelState;
	using StateDraw = GfxStateDraw;
	
	StateDraw* sd = CastPtr<StateDraw>(&fb);
	ASSERT(sd);
	if (!sd) return false;
	GfxDataState& state = sd->GetState();
	
	if (frame == 0) {
		
		if (state.GetModelCount() == 0) {
			hash_t env_material_model = 0;
			
			// TODO merge dupliate ModelComponent::Load
			if (have_skybox) {
				GfxModelState& skybox = state.AddModel();
				ASSERT(skybox.id >= 0);
				float skybox_sz = 1e8;
				Index<String> ext_list; ext_list << "" << ".png" << ".jpg";
				Index<String> dir_list; dir_list << "" << "imgs" << "imgs/skybox";
				ModelBuilder mb;
				Mesh& box_mesh = mb.AddBox(vec3(0), vec3(skybox_sz), true, true);
				Model& box = mb;
				
				if (!box.LoadCubemapFile(box_mesh, TEXTYPE_CUBE_DIFFUSE, skybox_diffuse)) {
					LOG("ObjViewProg::Render: error: could not load skybox diffuse image '" << skybox_diffuse << "'");
					return false;
				}
				if (!box.LoadCubemapFile(box_mesh, TEXTYPE_CUBE_IRRADIANCE, skybox_irradiance)) {
					LOG("ObjViewProg::Render: error: could not load skybox irradiance image '" << skybox_irradiance << "'");
					return false;
				}
				
				loader = mb;
				if (!skybox.LoadModel(loader)) {
					RTLOG("ObjViewProg::Render: error: could not load skybox");
					return false;
				}
				
				skybox.env_material = skybox.GetMaterialKey(0);
				skybox.env_material_model = skybox.id;
				env_material_model = skybox.id;
				
				bool b = skybox.SetProgram("sky");
				ASSERT(b);
			}
			
			GfxModelState& mdl = state.AddModel();
			mdl.env_material_model = env_material_model;
			
			String data_dir = ShareDirFile("models");
			String obj_path = AppendFileName(data_dir, obj);
			
			if (!loader.LoadModel(obj_path)) {
				RTLOG("ObjViewProg::Render: error: could not load model file: '" << obj_path << "'");
				return false;
			}
			if (!mdl.LoadModel(loader)) {
				RTLOG("ObjViewProg::Render: error: could not load model state");
				return false;
			}
			
			bool b = mdl.SetProgram("default");
			ASSERT(b);
		}
	}
	
	
	for (RendererContent* rc : RendererContent::Content()) {
		if (!rc->Load(state))
			return false;
	}
	
	
	DrawObj(*sd, true);
	
	iter++;
	frame++;
	if (ts.Seconds() >= phase_time) {
		iter = 0;
		ts.Reset();
		phase = (phase + 1) % phases;
	}
	
	return true;
}

void RendererBase::DrawObj(GfxStateDraw& fb, bool use_texture) {
	ASSERT(fb.HasTarget());
	GfxDataState& state = fb.GetState();
	
	float ratio = (float)sz.cy / (float)sz.cx;
	float eye_ratio = (float)sz.cy / (float)(sz.cx * 0.5);
	//float aspect = (float)sz.cx / (float)sz.cy;
	double f = ts.Seconds() / phase_time;
	float angle = (float)(f * (2.0 * M_PI));
	
	if (!state.user_view) {
		float rad = 1.5f;
		float x = cosf(angle) * rad;
		float z = sinf(angle) * rad * SCALAR_FWD_Zf;
		//float eye_x = cos(angle);
		//float eye_y = sin(angle);
		mat4 proj = Perspective(DEG2RADf(90), 1.0f, 0.1f, 100.0f);
		
		vec3 eye {x, 0, z};
		//vec3 center {0.3f * -eye_x, 0.0f, 0.3f * eye_y};
		vec3 center {0, 0, 0};
		vec3 up = VEC_UP;
		mat4 lookat = LookAt(eye, center, up);
		mat4 port = GetViewport(-1 * ratio, -1, 2 * ratio, 2, 1);
		mat4 base = port * proj;
		
		state.camera_pos = eye;
		state.camera_dir = (center - eye).GetNormalized();
		state.view = base * lookat;
		
		if (1) {
			float eye_dist = 0.08f;
			state.is_stereo = true;
			mat4 eye_port = GetViewport(-1 * eye_ratio, -1, 2 * eye_ratio, 2, 1);
			mat4 base = eye_port * proj;
			vec3 l_eye(-eye_dist, 0, -1 * SCALAR_FWD_Zf);
			vec3 r_eye(+eye_dist, 0, -1 * SCALAR_FWD_Zf);
			vec3 l_center { -eye_dist, 0, 0};
			vec3 r_center { +eye_dist, 0, 0};
			mat4 l_lookat = LookAt(l_eye, l_center, up);
			mat4 r_lookat = LookAt(r_eye, r_center, up);
			state.view_stereo[0] = base * l_lookat;
			state.view_stereo[1] = base * r_lookat;
		}
		
		//state.view_stereo[0] = state.view;
		//state.view_stereo[1] = state.view;
		
		//mat4 rot = rotate(Identity<mat4>(), angle, up);
		//mat4 model = Translate(vec3(0.0, 0.0, 0.0));
		//state.view = port * proj * lookat * model * rot;
		
	}
	#if 0
	state.light_dir = vec3 {sin(angle), 0.0, cos(angle)};
	#else
	state.light_dir = AxesDir(M_PIf/2, M_PIf/4);
	#endif
	
}


NAMESPACE_PARALLEL_END
