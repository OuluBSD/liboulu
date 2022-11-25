#include "EcsVirtualGui.h"

#if HAVE_WINDOWSYSTEM

NAMESPACE_ECS_BEGIN


WindowSystem::WindowSystem(Engine& m) : SP(m) {
	
}

bool WindowSystem::Initialize() {
	WindowSystemScreen& win = wm.AddScreen<WindowSystemScreen>();
	win.sys = this;
	
	Size sz = VirtualGui3DPtr->GetSize();
	
	win.SetFrameRect0(RectC(0, 0, sz.cx, sz.cy));
	
	return true;
}

void WindowSystem::Start() {

	ents = GetEngine().Get<EntityStore>();
	ASSERT(ents);
	
}

void WindowSystem::Update(double dt) {
	/*Ecs::EventStateBase* ev = Ecs::EventStateBase::Latest();
	if (ev) {
		EnvState& state = ev->GetState();
		
		TODO
	}*/
	
	wm.Update(dt);
	
}

void WindowSystem::Stop() {
	::UPP::Ctrl::CloseTopCtrls();
}

void WindowSystem::Uninitialize() {
	wm.Uninitialize();
}

void WindowSystem::Invalidate() {
	TODO
}

void WindowSystem::SetDesktopSize(Size sz) {
	vdesktop_sz = sz;
}



bool WindowSystemScreen::Init() {
	return true;
}

void WindowSystemScreen::Render() {
	// --> EcsVideoBase
}

void WindowSystemScreen::Shutdown() {
	CloseAll();
}

void WindowSystemScreen::CloseWindow(CoreWindow& cw) {
	TODO
}

bool WindowSystemScreen::Poll(CtrlEvent& e) {
	return false;
}



NAMESPACE_ECS_END

#endif
