#include "PortManager.h"


NAMESPACE_OULU_BEGIN


PortManager::PortManager() {
	
	
}


void PortManagerMain() {
	using namespace Upp;
	using namespace Upp;
	SetCoutLog();
	
	PortManager mgr;
	
	String ports_path = GetDataFile("ports.json");
	if (!FileExists) {
		LOG("Could not find ports.json");
		Exit(1);
	}
	
	
}


NAMESPACE_OULU_END


CONSOLE_APP_MAIN {Oulu::PortManagerMain();}
