#include "FusionCore.h"

NAMESPACE_OULU_BEGIN



bool FusionSystem::Initialize() {
	return true;
}

void FusionSystem::Start() {
	
}

void FusionSystem::Update(double dt) {
	DLOG("FusionSystem::Update: begin");
	
	for (FusionComponentRef& comp : comps)
		comp->Update0(dt);
	
	for (FusionContextComponentRef& ctx : ctxs)
		ctx->Update(dt);
	
	DLOG("FusionSystem::Update: end\n");
}

void FusionSystem::Stop() {
	
}

void FusionSystem::Uninitialize() {
	
}

void FusionSystem::AddContext(FusionContextComponentRef ctx) {
	ctxs.FindAdd(ctx);
}

void FusionSystem::RemoveContext(FusionContextComponentRef ctx) {
	ctxs.RemoveKey(ctx);
}

void FusionSystem::AddComponent(FusionComponentRef comp) {
	comps.FindAdd(comp);
}

void FusionSystem::RemoveComponent(FusionComponentRef comp) {
	comps.RemoveKey(comp);
}


NAMESPACE_OULU_END
