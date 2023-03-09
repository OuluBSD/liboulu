#include "GuboShell.h"


NAMESPACE_TOPSIDE_BEGIN


void VguiMain() {
	#if IS_UPP_CORE
	SetLanguage(LNG_ENGLISH);
	SetDefaultCharset(CHARSET_UTF8);
	
	ChClassicSkin();
	#endif
	
	
	Gu::EventsTester app;
	//GuiTesterApp app;
	//CtrlTesterApp app;
	app.OpenMain();
	//app.SetRect(RectC(10,10,640,480));
	Surface::EventLoop();
}

void DesktopMain() {
	using namespace Parallel;
	
	Surface::SetDebugDraw(true);
	Gubo::SetDebugDraw(true);
	
	AtomVirtualGui3D gui;
	gui.Create(RectC(100, 100, 1024, 768), "Libtopside Virtual Gui Test");

	RunVirtualGui(gui, callback(VguiMain));
	
}


NAMESPACE_TOPSIDE_END



CONSOLE_APP_MAIN {
	using namespace TS;
	Serial::Machine::WhenInitialize << callback(DefaultSerialInitializer);
	Serial::Machine::WhenPreFirstUpdate << callback(DefaultStartup);
	Serial::Machine::WhenUserProgram << callback(DesktopMain);
	
	SingleMachine mach;
	if (mach.Start()) {
		DefaultRunner(0, "Gui App", GUI_EON);
		
		mach.Stop();
	}
}