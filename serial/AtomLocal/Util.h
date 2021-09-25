#ifndef _AtomLocal_Util_h_
#define _AtomLocal_Util_h_

NAMESPACE_SERIAL_BEGIN


class JoinerBase :
	virtual public AtomBase
{
	
	
public:
	JoinerBase();
	bool AltInitialize(const Script::WorldState& ws) override;
	void AltUninitialize() override;
	void AltForward(FwdScope& fwd) override;
	void Visit(RuntimeVisitor& vis) override {}
	
	
};


class SplitterBase :
	virtual public AtomBase
{
	
	
public:
	SplitterBase();
	bool AltInitialize(const Script::WorldState& ws) override;
	void AltUninitialize() override;
	void AltForward(FwdScope& fwd) override;
	void Visit(RuntimeVisitor& vis) override {}
	
	
};


class OglShaderBase :
	public OglBufferBase
{
	Packet		last_packet;
	
public:
	RTTI_DECL1(OglShaderBase, OglBufferBase);
	
	OglShaderBase();
	bool AltInitialize(const Script::WorldState& ws) override;
	bool AltPostInitialize() override;
	void AltUninitialize() override;
	void AltForward(FwdScope& fwd) override;
	bool AltIsReady(ValDevCls vd) override;
	void LoadPacket(const Packet& p) override;
	void AltStorePacket(Packet& p) override;
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<OglBufferBase>(this);}
	
	
};


NAMESPACE_SERIAL_END

#endif