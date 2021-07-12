#include "TemplatesLocalTests.h"

NAMESPACE_TOPSIDE_BEGIN
using namespace TS::ECS;



bool SimpleDebugInitializer() {
	SetCoutLog();
	
	return true;
}



/*
To debug reference bugs, uncomment:
	- SetDebugRefVisits
	- RefDebugVisitor::Static().DumpUnvisited();
You'll see something like this in log
	0:	[0x7FFFFFFFE488]
	1:	[0x7FFFFFFFE478]
	2:	[0x7FFFFFFFE460]
	3:	[0x80AE80688]
	4:	[0x80AE57610]
	5:	[0x80AE43230]
	6:	[0x7FFFFFFFE2A8]
	7:	[0x7FFFFFFFE200]
	8:	[0x7FFFFFFFE138]
Take any address and put to BreakRefAdd
*/



void Main() {
	SetCoutLog();
	const auto& cmd = CommandLine();
	if (cmd.IsEmpty()) {
		LOG("App requires eon arguments");
		return;
	}
	String eon_file = cmd[0];
	bool verify = cmd.GetCount() >= 2 && cmd[1] == "verify";
	
	
	Ecs::Factory::Dump();
	
	TypeExtCls t;
	
	
	//BreakRefAdd(0x802859038);
	
	
	if (!SimpleDebugInitializer())
		Exit(1);
	
	MAKE_STATIC(MachineVerifier, verifier);
	if (verify) {
		verifier.AddSystem<RegistrySystem>();
		verifier.AddSystem<EntityStore>();
		verifier.AddSystem<ComponentStore>();
		verifier.AddSystem<ExtSystem>();
		verifier.AddSystem<EonLoader>();
		
		auto& ent		= verifier.GetRoot().AddPool("tester").AddPool("generator").AddEntity();
		auto& customer	= ent.AddExtComponentWith<TestCustomer>		(VD(CENTER,ORDER));
		auto& src		= ent.AddExtComponentWith<TestRealtimeSrc>	(VD(CENTER,AUDIO));
		auto& sink		= ent.AddExtComponentWith<TestRealtimeSink>	(VD(CENTER,RECEIPT));
		customer << src << sink << customer;
		src.SetSourceFormat(GetDefaultFormat(VD(CENTER,AUDIO)));
		sink.SetSinkFormat(GetDefaultFormat(VD(CENTER,AUDIO)));
		
	}
	
	VectorMap<String,Object> args;
	args.Add("MACHINE_TIME_LIMIT", 3);
	
	Ecs::DebugMain(eon_file, args, verify ? &verifier : 0, 0, 0);
}


	
NAMESPACE_TOPSIDE_END


#ifdef flagGUI
GUI_APP_MAIN {TS::Main();}
#else
CONSOLE_APP_MAIN {TS::Main();}
#endif

