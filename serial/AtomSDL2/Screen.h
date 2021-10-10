#ifndef _AtomSDL2_Screen_h_
#define _AtomSDL2_Screen_h_

NAMESPACE_SERIAL_BEGIN


#ifdef flagGUI

class SDL2ScreenBase :
	public SDL2BaseT<SDL2ScreenBase>,
	public OglBufferBase,
	public FramePollerBase
{
	One<OOSDL2::Screen>	obj;
    Serial::Format		fmt;
	OOSDL2::Events*		ev = 0;
	
public:
	RTTI_DECL3(SDL2ScreenBase, AltBaseT, OglBufferBase, FramePollerBase)
	COPY_PANIC(SDL2ScreenBase)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<AltBaseT>(this); vis.VisitThis<OglBufferBase>(this); vis.VisitThis<FramePollerBase>(this);}
	
	SDL2ScreenBase() = default;
	
	bool			Initialize(const Script::WorldState& ws) override;
	void			Uninitialize() override;
	void			StorePacket(int sink_ch, int src_ch, const Packet& in, Packet& out) override;
	bool			LoadPacket(int sink_ch, const Packet& in, Vector<int>& fwd_src_chs) override;
	
	OOSDL2::Component& GetObj() override {return *obj;}
	OOSDL2::Screen* GetOOSDL2() {return &*obj;}
	
	void SetFPS(int fps) {fmt.vid.SetFPS(fps); FramePollerBase::SetFPS(fps);}
	
};

#endif


NAMESPACE_SERIAL_END

#endif
