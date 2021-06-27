#ifndef _TemplatesLocalTests_TemplatesLocalTests_h_
#define _TemplatesLocalTests_TemplatesLocalTests_h_

#include <TemplatesLocal/TemplatesLocal.h>
#include <EcsDebug/EcsDebug.h>

NAMESPACE_TOPSIDE_BEGIN
using namespace TS::ECS;

class TestCustomer :
	public CustomerExt
{
	
public:
	RTTI_DECL1(TestCustomer, CustomerExt)
	
	void Visit(RuntimeVisitor& vis) override {}
	void Forward(FwdScope& fwd) override {LOG("TestCustomer::Forward");}
	
	COMP_MAKE_ACTION_BEGIN
		COMP_MAKE_ACTION_FALSE_TO_TRUE("customer.id.ABCD")
	COMP_MAKE_ACTION_END
	
	
	static EcsTypeCls::Type		GetEcsType() {return EcsTypeCls::COMP_TEST_CUSTOMER;}
	
};


class TestRealtimeSrc :
	public AudioInputExt
{
	Ecs::Format		internal_fmt;
	double			time = 0;
	byte			rolling_value = 0;
	
public:
	
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {}
	void Forward(FwdScope& fwd) override;
	void StorePacket(Packet& p) override;
	
	COMP_MAKE_ACTION_BEGIN
		COMP_MAKE_ACTION_FALSE_TO_TRUE("customer.id.EFGH")
	COMP_MAKE_ACTION_END
	
	
	static EcsTypeCls::Type		GetEcsType() {return EcsTypeCls::COMP_TEST_AUDIO_IN;}
	
};

class TestRealtimeSink :
	public AudioOutputExt
{
	RunningFlag		flag;
	byte			rolling_value = 0;
	
public:
	RTTI_DECL1(TestRealtimeSink, AudioOutputExt)
	typedef TestRealtimeSink CLASSNAME;
	
	~TestRealtimeSink() {ASSERT(!flag.IsRunning());}
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {}
	void Forward(FwdScope& fwd) override;
	void StorePacket(Packet& p) override;
	void IntervalSinkProcess();
	
	COMP_MAKE_ACTION_BEGIN
		COMP_MAKE_ACTION_FALSE_TO_TRUE("center.audio.sink.realtime")
	COMP_MAKE_ACTION_END
	
	
	static EcsTypeCls::Type		GetEcsType() {return EcsTypeCls::COMP_TEST_AUDIO_OUT;}
	
};

NAMESPACE_TOPSIDE_END

#endif
