#include "LocalPlan.h"

NAMESPACE_TOPSIDE_BEGIN


void InterfaceBuilder::AddEffect() {
	Color(28, 255, 150);
	Dependency("AudioCore");
	Dependency("ParallelLib");
	HaveRecvFinalize();
	HaveIsReady();
	
	Interface("Effect");
	
	Vendor("AudioCore");
	
}


NAMESPACE_TOPSIDE_END
