// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!

#ifndef _IScreen_TmplClasses_h_
#define _IScreen_TmplClasses_h_

NAMESPACE_PARALLEL_BEGIN

template <class Scr> struct ScreenSinkDeviceT;


template <class Scr>
struct ScreenSinkDeviceT : ScrSinkDevice {
	using CLASSNAME = ScreenSinkDeviceT<Scr>;
	RTTI_DECL1(CLASSNAME, ScrSinkDevice)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<ScrSinkDevice>(this);}
	
	typename Scr::NativeSinkDevice dev;
	
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!Scr::SinkDevice_Initialize(dev, *this, ws))
			return false;
		return true;
	}

	bool PostInitialize() override {
		if (!Scr::SinkDevice_PostInitialize(dev, *this))
			return false;
		return true;
	}

	bool Start() override {
		return Scr::SinkDevice_Start(dev, *this);
	}

	void Stop() override {
		Scr::SinkDevice_Stop(dev, *this);
	}

	void Uninitialize() override {
		Scr::SinkDevice_Uninitialize(dev, *this);
	}

	bool ProcessPacket(PacketValue& in, PacketValue& out, int src_ch) override {
		if (!Scr::SinkDevice_ProcessPacket(dev, *this, in, out))
			return false;
		return true;
	}

	bool Recv(int sink_ch, const Packet& in) override {
		return Scr::SinkDevice_Recv(dev, *this, sink_ch, in);
	}

	void Finalize(RealtimeSourceConfig& cfg) override {
		return Scr::SinkDevice_Finalize(dev, *this, cfg);
	}

	bool NegotiateSinkFormat(Serial::Link& link, int sink_ch, const Format& new_fmt) override {
		return Scr::SinkDevice_NegotiateSinkFormat(dev, *this, link, sink_ch, new_fmt);
	}

	
};

#if (defined flagLINUX) || (defined flagFREEBSD)
using X11SinkDevice = ScreenSinkDeviceT<ScrX11>;
#endif

#if (defined flagLINUX) || (defined flagFREEBSD)
using X11SwSinkDevice = ScreenSinkDeviceT<ScrX11Sw>;
#endif

#if defined flagOGL
using X11OglSinkDevice = ScreenSinkDeviceT<ScrX11Ogl>;
#endif


NAMESPACE_PARALLEL_END



#endif

