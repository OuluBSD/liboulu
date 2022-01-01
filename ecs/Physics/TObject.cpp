#include "Physics.h"

NAMESPACE_TOPSIDE_BEGIN


template <class Fys>
ObjectT<Fys>::ObjectT() {
	//model.LoadModel(ShareDirFile("models" DIR_SEPS "cube.obj"));
	geom = Null;
	body = Null;
	Fys::GetDefaultOrientation(orient);
}

template <class Fys>
ObjectT<Fys>::~ObjectT() {
	Fys::ClearGeom(geom);
	Fys::ClearBody(body);
}

template <class Fys>
void ObjectT<Fys>::AttachContent() {
	ASSERT(geom);
	ASSERT(body);
	
	// Set mass of the physics body
	Fys::SetBodyMass(body, mass);
	
	// Set physics body of a geometry
	Fys::SetGeomBody(geom, body);
	
	// Set orientation of a physics body
	Fys::SetBodyQuaternion(body, orient);
	
	//LOG(ToString());
	
	auto space = this->GetSystem()->GetSpace().GetNative();
	ASSERT(space);
	Fys::AddGeomToSpace(space, geom);
	
}

template <class Fys>
void ObjectT<Fys>::DetachContent() {
	ASSERT(geom);
	ASSERT(body);
	Fys::RemoveGeomFromSpace(this->GetSpace()->GetNative(), geom);
}

template <class Fys>
void ObjectT<Fys>::Refresh() {
	/*if (!fb_obj && !model_err) {
		LOG("Object::Refresh: warning: loading model while painting");
		fb_obj = s.CreateObject();
		if (fb_obj)
			LoadModel(s);
	}*/
	
	ASSERT(fb_obj);
	if (!fb_obj)
		return;
	
	
	/*
	int width = 1280, height = 720;
	mat4 projection = ortho(-width, width, -height, height, -1024.0f, 1024.0f);
    mat4 view = LookAt(vec3(0.0f, 0.0f, -1.0f), vec3(0.0f,0.0f,0.0f), vec3(0.0f, 1.0f, 0.0f));
    mat4 model = identity<mat4>();
	fb_obj->SetMat4("projection", projection);
	fb_obj->SetMat4("model", model);
	fb_obj->SetMat4("view", view);*/
	
	if (is_override_phys_geom) {
		mat4 v = override_geom * model_geom;
		fb_obj->Set(v, identity<mat4>());
	}
	else {
		vec3 v3 = Fys::GetGeomPosition(geom);
		mat4 trans = translate(identity<mat4>(), v3);
		quat q = Fys::GetGeomQuaternion(geom);
		mat4 rot = ToMat4(q);
		mat4 v = trans * rot * model_geom;
		fb_obj->Set(v, identity<mat4>());
	}
}

template <class Fys>
bool ObjectT<Fys>::LoadModel(GfxDataState& s) {
	ASSERT(!fb_obj);
	fb_obj = &s.CreateObject();
	if (!s.LoadModel(loader, *fb_obj))
		Panic("Couldn't load model: ModelComponent");
	if (!s.LoadModelTextures(loader, *fb_obj))
		Panic("Couldn't load model textures: ModelComponent");
	return true;
}
/*
template <class Fys>
void ObjectT<Fys>::LoadModel(CpuDataState& state) {
	auto& o = cpu_obj ? *cpu_obj : state.AddObject();
	cpu_obj = cpu_obj ? cpu_obj : &o;
	fb_obj = cpu_obj;
	if (!state.LoadModel(loader, o))
		Panic("Couldn't load model: ModelComponent");
	if (!state.LoadModelTextures(loader, o))
		Panic("Couldn't load model textures: ModelComponent");
}

template <class Fys>
void ObjectT<Fys>::LoadModel(OglDataState& state) {
	auto& o = ogl_obj ? *ogl_obj : state.AddObject();
	ogl_obj = ogl_obj ? ogl_obj : &o;
	fb_obj = ogl_obj;
	if (!state.LoadModel(loader, o))
		Panic("Couldn't load model: ModelComponent");
	if (!state.LoadModelTextures(loader, o))
		Panic("Couldn't load model textures: ModelComponent");
}
*/

FYS_EXCPLICIT_INITIALIZE_CLASS(ObjectT)

NAMESPACE_TOPSIDE_END
