#include "ProtoVM.h"


CONSOLE_APP_MAIN {
	Machine		mach;
	int			max_ticks = 10;
	
	mach.Init();
	
	for(int i = 0; i < max_ticks; i++) {
		
		mach.Tick();
		
	}
	
}
