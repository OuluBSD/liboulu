// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!

#ifndef _IHal_IHal_h_
#define _IHal_IHal_h_

#include <ParallelLib/ParallelLib.h>
#include <IGraphics/IGraphics.h>

NAMESPACE_PARALLEL_BEGIN

#define HAL_CLS_LIST(x) \
	HAL_CLS(AudioSinkDevice, x) \
	HAL_CLS(CenterVideoSinkDevice, x) \
	HAL_CLS(CenterFboSinkDevice, x) \
	HAL_CLS(OglVideoSinkDevice, x) \
	HAL_CLS(ContextBase, x) \
	HAL_CLS(EventsBase, x) \

#define HAL_VNDR_LIST \
	HAL_VNDR(HalSdl) \

#define HAL_CLS(x, v) struct v##x;
#define HAL_VNDR(x) HAL_CLS_LIST(x)
HAL_VNDR_LIST
#undef HAL_VNDR
#undef HAL_CLS

#if defined flagSDL2
struct HalSdl {
	struct NativeAudioSinkDevice;
	struct NativeCenterVideoSinkDevice;
	struct NativeCenterFboSinkDevice;
	#if defined flagOGL
	struct NativeOglVideoSinkDevice;
	#endif
	struct NativeContextBase;
	struct NativeEventsBase;
	
	struct Thread {
		
	};
	
	static Thread& Local() {thread_local static Thread t; return t;}
	
	#include "IfaceFuncs.inl"
	
};
#endif

struct HalAudioSinkDevice : public Atom {
	RTTI_DECL1(HalAudioSinkDevice, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalAudioSinkDevice() {}
};

struct HalCenterVideoSinkDevice : public Atom {
	RTTI_DECL1(HalCenterVideoSinkDevice, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalCenterVideoSinkDevice() {}
};

struct HalCenterFboSinkDevice : public Atom {
	RTTI_DECL1(HalCenterFboSinkDevice, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalCenterFboSinkDevice() {}
};

#if defined flagOGL
struct HalOglVideoSinkDevice : public Atom {
	RTTI_DECL1(HalOglVideoSinkDevice, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalOglVideoSinkDevice() {}
};
#endif

struct HalContextBase : public Atom {
	RTTI_DECL1(HalContextBase, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalContextBase() {}
};

struct HalEventsBase : public Atom {
	RTTI_DECL1(HalEventsBase, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalEventsBase() {}
};


template <class Hal> struct HalAudioSinkDeviceT : HalAudioSinkDevice {
	using CLASSNAME = HalAudioSinkDeviceT<Hal>;
	RTTI_DECL1(CLASSNAME, HalAudioSinkDevice)
	void Visit(RuntimeVisitor& vis) override {
		if (dev) Hal::AudioSinkDevice_Visit(*dev, *this, vis);
		vis.VisitThis<HalAudioSinkDevice>(this);
	}
	One<typename Hal::NativeAudioSinkDevice> dev;
	bool Initialize(const Script::WorldState& ws) override {
		if (!Hal::AudioSinkDevice_Create(dev))
			return false;
		if (!Hal::AudioSinkDevice_Initialize(*dev, *this, ws))
			return false;
		return true;
	}
	bool PostInitialize() override {
		if (!Hal::AudioSinkDevice_PostInitialize(*dev, *this))
			return false;
		return true;
	}
	bool Start() override {
		return Hal::AudioSinkDevice_Start(*dev, *this);
	}
	void Stop() override {
		Hal::AudioSinkDevice_Stop(*dev, *this);
	}
	void Uninitialize() override {
		Hal::AudioSinkDevice_Uninitialize(*dev, *this);
		Hal::AudioSinkDevice_Destroy(dev);
	}
	bool Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) override {
		if (!Hal::AudioSinkDevice_Send(*dev, *this, cfg, out, src_ch))
			return false;
		return true;
	}
	bool Recv(int sink_ch, const Packet& in) override {
		return Hal::AudioSinkDevice_Recv(*dev, *this, sink_ch, in);
	}
	void Finalize(RealtimeSourceConfig& cfg) override {
		return Hal::AudioSinkDevice_Finalize(*dev, *this, cfg);
	}
	void Update(double dt) override {
		return Hal::AudioSinkDevice_Update(*dev, *this, dt);
	}
	bool IsReady(PacketIO& io) override {
		return Hal::AudioSinkDevice_IsReady(*dev, *this, io);
	}
	bool AttachContext(AtomBase& a) override {
		return Hal::AudioSinkDevice_AttachContext(*dev, *this, a);
	}
	void DetachContext(AtomBase& a) override {
		Hal::AudioSinkDevice_DetachContext(*dev, *this, a);
	}
};
template <class Hal> struct HalCenterVideoSinkDeviceT : HalCenterVideoSinkDevice {
	using CLASSNAME = HalCenterVideoSinkDeviceT<Hal>;
	RTTI_DECL1(CLASSNAME, HalCenterVideoSinkDevice)
	void Visit(RuntimeVisitor& vis) override {
		if (dev) Hal::CenterVideoSinkDevice_Visit(*dev, *this, vis);
		vis.VisitThis<HalCenterVideoSinkDevice>(this);
	}
	One<typename Hal::NativeCenterVideoSinkDevice> dev;
	bool Initialize(const Script::WorldState& ws) override {
		if (!Hal::CenterVideoSinkDevice_Create(dev))
			return false;
		if (!Hal::CenterVideoSinkDevice_Initialize(*dev, *this, ws))
			return false;
		return true;
	}
	bool PostInitialize() override {
		if (!Hal::CenterVideoSinkDevice_PostInitialize(*dev, *this))
			return false;
		return true;
	}
	bool Start() override {
		return Hal::CenterVideoSinkDevice_Start(*dev, *this);
	}
	void Stop() override {
		Hal::CenterVideoSinkDevice_Stop(*dev, *this);
	}
	void Uninitialize() override {
		Hal::CenterVideoSinkDevice_Uninitialize(*dev, *this);
		Hal::CenterVideoSinkDevice_Destroy(dev);
	}
	bool Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) override {
		if (!Hal::CenterVideoSinkDevice_Send(*dev, *this, cfg, out, src_ch))
			return false;
		return true;
	}
	bool Recv(int sink_ch, const Packet& in) override {
		return Hal::CenterVideoSinkDevice_Recv(*dev, *this, sink_ch, in);
	}
	void Finalize(RealtimeSourceConfig& cfg) override {
		return Hal::CenterVideoSinkDevice_Finalize(*dev, *this, cfg);
	}
	void Update(double dt) override {
		return Hal::CenterVideoSinkDevice_Update(*dev, *this, dt);
	}
	bool IsReady(PacketIO& io) override {
		return Hal::CenterVideoSinkDevice_IsReady(*dev, *this, io);
	}
	bool AttachContext(AtomBase& a) override {
		return Hal::CenterVideoSinkDevice_AttachContext(*dev, *this, a);
	}
	void DetachContext(AtomBase& a) override {
		Hal::CenterVideoSinkDevice_DetachContext(*dev, *this, a);
	}
};
template <class Hal> struct HalCenterFboSinkDeviceT : HalCenterFboSinkDevice {
	using CLASSNAME = HalCenterFboSinkDeviceT<Hal>;
	RTTI_DECL1(CLASSNAME, HalCenterFboSinkDevice)
	void Visit(RuntimeVisitor& vis) override {
		if (dev) Hal::CenterFboSinkDevice_Visit(*dev, *this, vis);
		vis.VisitThis<HalCenterFboSinkDevice>(this);
	}
	One<typename Hal::NativeCenterFboSinkDevice> dev;
	bool Initialize(const Script::WorldState& ws) override {
		if (!Hal::CenterFboSinkDevice_Create(dev))
			return false;
		if (!Hal::CenterFboSinkDevice_Initialize(*dev, *this, ws))
			return false;
		return true;
	}
	bool PostInitialize() override {
		if (!Hal::CenterFboSinkDevice_PostInitialize(*dev, *this))
			return false;
		return true;
	}
	bool Start() override {
		return Hal::CenterFboSinkDevice_Start(*dev, *this);
	}
	void Stop() override {
		Hal::CenterFboSinkDevice_Stop(*dev, *this);
	}
	void Uninitialize() override {
		Hal::CenterFboSinkDevice_Uninitialize(*dev, *this);
		Hal::CenterFboSinkDevice_Destroy(dev);
	}
	bool Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) override {
		if (!Hal::CenterFboSinkDevice_Send(*dev, *this, cfg, out, src_ch))
			return false;
		return true;
	}
	bool Recv(int sink_ch, const Packet& in) override {
		return Hal::CenterFboSinkDevice_Recv(*dev, *this, sink_ch, in);
	}
	void Finalize(RealtimeSourceConfig& cfg) override {
		return Hal::CenterFboSinkDevice_Finalize(*dev, *this, cfg);
	}
	void Update(double dt) override {
		return Hal::CenterFboSinkDevice_Update(*dev, *this, dt);
	}
	bool IsReady(PacketIO& io) override {
		return Hal::CenterFboSinkDevice_IsReady(*dev, *this, io);
	}
	bool AttachContext(AtomBase& a) override {
		return Hal::CenterFboSinkDevice_AttachContext(*dev, *this, a);
	}
	void DetachContext(AtomBase& a) override {
		Hal::CenterFboSinkDevice_DetachContext(*dev, *this, a);
	}
};
#if defined flagOGL
template <class Hal> struct HalOglVideoSinkDeviceT : HalOglVideoSinkDevice {
	using CLASSNAME = HalOglVideoSinkDeviceT<Hal>;
	RTTI_DECL1(CLASSNAME, HalOglVideoSinkDevice)
	void Visit(RuntimeVisitor& vis) override {
		if (dev) Hal::OglVideoSinkDevice_Visit(*dev, *this, vis);
		vis.VisitThis<HalOglVideoSinkDevice>(this);
	}
	One<typename Hal::NativeOglVideoSinkDevice> dev;
	bool Initialize(const Script::WorldState& ws) override {
		if (!Hal::OglVideoSinkDevice_Create(dev))
			return false;
		if (!Hal::OglVideoSinkDevice_Initialize(*dev, *this, ws))
			return false;
		return true;
	}
	bool PostInitialize() override {
		if (!Hal::OglVideoSinkDevice_PostInitialize(*dev, *this))
			return false;
		return true;
	}
	bool Start() override {
		return Hal::OglVideoSinkDevice_Start(*dev, *this);
	}
	void Stop() override {
		Hal::OglVideoSinkDevice_Stop(*dev, *this);
	}
	void Uninitialize() override {
		Hal::OglVideoSinkDevice_Uninitialize(*dev, *this);
		Hal::OglVideoSinkDevice_Destroy(dev);
	}
	bool Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) override {
		if (!Hal::OglVideoSinkDevice_Send(*dev, *this, cfg, out, src_ch))
			return false;
		return true;
	}
	bool Recv(int sink_ch, const Packet& in) override {
		return Hal::OglVideoSinkDevice_Recv(*dev, *this, sink_ch, in);
	}
	void Finalize(RealtimeSourceConfig& cfg) override {
		return Hal::OglVideoSinkDevice_Finalize(*dev, *this, cfg);
	}
	void Update(double dt) override {
		return Hal::OglVideoSinkDevice_Update(*dev, *this, dt);
	}
	bool IsReady(PacketIO& io) override {
		return Hal::OglVideoSinkDevice_IsReady(*dev, *this, io);
	}
	bool AttachContext(AtomBase& a) override {
		return Hal::OglVideoSinkDevice_AttachContext(*dev, *this, a);
	}
	void DetachContext(AtomBase& a) override {
		Hal::OglVideoSinkDevice_DetachContext(*dev, *this, a);
	}
};
#endif
template <class Hal> struct HalContextBaseT : HalContextBase {
	using CLASSNAME = HalContextBaseT<Hal>;
	RTTI_DECL1(CLASSNAME, HalContextBase)
	void Visit(RuntimeVisitor& vis) override {
		if (dev) Hal::ContextBase_Visit(*dev, *this, vis);
		vis.VisitThis<HalContextBase>(this);
	}
	One<typename Hal::NativeContextBase> dev;
	bool Initialize(const Script::WorldState& ws) override {
		if (!Hal::ContextBase_Create(dev))
			return false;
		if (!Hal::ContextBase_Initialize(*dev, *this, ws))
			return false;
		return true;
	}
	bool PostInitialize() override {
		if (!Hal::ContextBase_PostInitialize(*dev, *this))
			return false;
		return true;
	}
	bool Start() override {
		return Hal::ContextBase_Start(*dev, *this);
	}
	void Stop() override {
		Hal::ContextBase_Stop(*dev, *this);
	}
	void Uninitialize() override {
		Hal::ContextBase_Uninitialize(*dev, *this);
		Hal::ContextBase_Destroy(dev);
	}
	bool Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) override {
		if (!Hal::ContextBase_Send(*dev, *this, cfg, out, src_ch))
			return false;
		return true;
	}
	bool Recv(int sink_ch, const Packet& in) override {
		return Hal::ContextBase_Recv(*dev, *this, sink_ch, in);
	}
	void Finalize(RealtimeSourceConfig& cfg) override {
		return Hal::ContextBase_Finalize(*dev, *this, cfg);
	}
	void Update(double dt) override {
		return Hal::ContextBase_Update(*dev, *this, dt);
	}
	bool IsReady(PacketIO& io) override {
		return Hal::ContextBase_IsReady(*dev, *this, io);
	}
	bool AttachContext(AtomBase& a) override {
		return Hal::ContextBase_AttachContext(*dev, *this, a);
	}
	void DetachContext(AtomBase& a) override {
		Hal::ContextBase_DetachContext(*dev, *this, a);
	}
};
template <class Hal> struct HalEventsBaseT : HalEventsBase {
	using CLASSNAME = HalEventsBaseT<Hal>;
	RTTI_DECL1(CLASSNAME, HalEventsBase)
	void Visit(RuntimeVisitor& vis) override {
		if (dev) Hal::EventsBase_Visit(*dev, *this, vis);
		vis.VisitThis<HalEventsBase>(this);
	}
	One<typename Hal::NativeEventsBase> dev;
	bool Initialize(const Script::WorldState& ws) override {
		if (!Hal::EventsBase_Create(dev))
			return false;
		if (!Hal::EventsBase_Initialize(*dev, *this, ws))
			return false;
		return true;
	}
	bool PostInitialize() override {
		if (!Hal::EventsBase_PostInitialize(*dev, *this))
			return false;
		return true;
	}
	bool Start() override {
		return Hal::EventsBase_Start(*dev, *this);
	}
	void Stop() override {
		Hal::EventsBase_Stop(*dev, *this);
	}
	void Uninitialize() override {
		Hal::EventsBase_Uninitialize(*dev, *this);
		Hal::EventsBase_Destroy(dev);
	}
	bool Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) override {
		if (!Hal::EventsBase_Send(*dev, *this, cfg, out, src_ch))
			return false;
		return true;
	}
	bool Recv(int sink_ch, const Packet& in) override {
		return Hal::EventsBase_Recv(*dev, *this, sink_ch, in);
	}
	void Finalize(RealtimeSourceConfig& cfg) override {
		return Hal::EventsBase_Finalize(*dev, *this, cfg);
	}
	void Update(double dt) override {
		return Hal::EventsBase_Update(*dev, *this, dt);
	}
	bool IsReady(PacketIO& io) override {
		return Hal::EventsBase_IsReady(*dev, *this, io);
	}
	bool AttachContext(AtomBase& a) override {
		return Hal::EventsBase_AttachContext(*dev, *this, a);
	}
	void DetachContext(AtomBase& a) override {
		Hal::EventsBase_DetachContext(*dev, *this, a);
	}
};

#if defined flagSDL2
using SdlAudioSinkDevice = HalAudioSinkDeviceT<HalSdl>;
using SdlCenterVideoSinkDevice = HalCenterVideoSinkDeviceT<HalSdl>;
using SdlCenterFboSinkDevice = HalCenterFboSinkDeviceT<HalSdl>;
#if defined flagOGL
using SdlOglVideoSinkDevice = HalOglVideoSinkDeviceT<HalSdl>;
#endif
using SdlContextBase = HalContextBaseT<HalSdl>;
using SdlEventsBase = HalEventsBaseT<HalSdl>;
#endif

NAMESPACE_PARALLEL_END

#endif
