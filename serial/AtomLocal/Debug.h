#ifndef _AtomLocal_Debug_h_
#define _AtomLocal_Debug_h_

NAMESPACE_SERIAL_BEGIN


class RollingValueBase :
	virtual public AtomBase
{
	int					rolling_value = 0;
	double				time = 0;
	Serial::Format		internal_fmt;
	
public:
	RTTI_DECL0(RollingValueBase)
	bool AltInitialize(const Script::WorldState& ws) override;
	void AltStorePacket(Packet& p) override;
	void Visit(RuntimeVisitor& vis) override {}
	
	
};


class VoidSinkBase :
	virtual public AtomBase
{
	int					rolling_value = 0;
	Serial::Format		internal_fmt;
	RunningFlag			flag;
	
public:
	RTTI_DECL0(VoidSinkBase)
	typedef VoidSinkBase CLASSNAME;
	~VoidSinkBase() {ASSERT(!flag.IsRunning());}
	bool AltInitialize(const Script::WorldState& ws) override;
	void AltForward(FwdScope& fwd) override {AtomBase::ForwardVoidSink(fwd);}
	void IntervalSinkProcess() override;
	void Visit(RuntimeVisitor& vis) override {}
	
	void IntervalSinkProcess0() {this->IntervalSinkProcess();}
	
	
};


NAMESPACE_SERIAL_END

#endif