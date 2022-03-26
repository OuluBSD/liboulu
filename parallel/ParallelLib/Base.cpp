#include "ParallelLib.h"


NAMESPACE_PARALLEL_BEGIN


bool CustomerBase::Initialize(const Script::WorldState& ws) {
	RTLOG("CustomerBase::Initialize");
	
	TODO
	/*
	AtomTypeCls type = GetType();
	
	//if (type.iface.content.val == ValCls::AUDIO)
	//	packet_thrds = 10;
	
	AtomBase::packets_forwarded = 0;
	customer.Create();
	AtomBaseRef r = AtomBase::AsRefT();
	ASSERT(r);
	AtomSystemRef as = AtomBase::GetMachine().template Get<AtomSystem>();
	as->AddCustomer(r);
	*/
	return true;
}

#if 0
bool CustomerBase::PostInitialize() {
	packet_thrds = GetSink()->GetValue(0).GetMinPackets();
	
	return true;
}

#endif

void CustomerBase::Uninitialize() {
	TODO
	/*AtomBaseRef r = AtomBase::AsRefT();
	ASSERT(r);
	AtomBase::GetMachine().template Get<AtomSystem>()->RemoveCustomer(r);*/
}

#if 0

void CustomerBase::UpdateConfig(double dt) {
	ASSERT(customer);
	DefaultInterfaceSourceRef src = this->GetSource();
	ASSERT(src);
	if (src) {
		int count = src->GetSourceCount();
		for(int i = 0; i < count; i++) {
			Value& val = src->GetSourceValue(i);
			TODO // wtf is this, where's i usage?
			customer->cfg.Update(dt, val.IsQueueFull());
		}
	}
}

void CustomerBase::Forward(FwdScope& fwd) {
	//RTLOG("CustomerBase::Forward");
	
	while (packet_count < packet_thrds) {
		RTLOG("CustomerBase::Forward: create packet");
		InterfaceSinkRef sink_iface = GetSink();
		
		int sink_count = sink_iface->GetSinkCount();
		ASSERT(sink_count == 1);
		
		Value&			sink_val = sink_iface->GetValue(0);
		PacketBuffer&	sink_buf = sink_val.GetBuffer();
		Format			fmt = sink_val.GetFormat();
		
		off32 init_off(&off_gen, 0);
		Packet p = CreatePacket(init_off);
		p->SetFormat(fmt);
		p->seq = -1;
		
		InternalPacketData& data = p->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = 1;
		
		//PacketTracker::Track(TrackerInfo("CustomerBase::Forward", __FILE__, __LINE__), *p);
		sink_val.GetBuffer().Add(p);
		
		packet_count++;
	}
	
}

bool CustomerBase::ProcessPackets(PacketIO& io) {
	RTLOG("CustomerBase::ProcessPackets");
	
	PacketIO::Sink& sink = io.sink[0];
	PacketIO::Source& src = io.src[0];
	
	ASSERT(sink.p);
	PacketTracker::StopTracking(TrackerInfo("CustomerBase::Forward", __FILE__, __LINE__), *sink.p);
	
	sink.may_remove = true;
	src.from_sink_ch = 0;
	src.p = sink.p;
	src.p->SetFormat(src.val->GetFormat());
	src.p->SetOffset(off_gen.Create());
	
	
	PacketTracker::Track(TrackerInfo("CustomerBase::Forward", __FILE__, __LINE__), *src.p);
	
	return true;
}
#endif













bool RollingValueBase::Initialize(const Script::WorldState& ws) {
	AtomTypeCls type = ((AtomBase*)this)->GetType();
	ValDevCls main_vd = type.iface.src();
	if (main_vd.dev != DevCls::CENTER) {
		RTLOG("RollingValueBase::Initialize: error: invalid device");
		return false;
	}
	if (main_vd.val == ValCls::AUDIO)
		internal_fmt.SetAudio(DevCls::CENTER, SoundSample::U8_LE, 2, 44100, 777);
	else if (main_vd.val == ValCls::VIDEO)
		internal_fmt.SetVideo(DevCls::CENTER, LightSampleFD::U8_LE_ABC, 1280, 720, 60, 1);
	else
		TODO;
	
	TODO
	/*
	int src_ch = FindSourceWithValDev(VD(CENTER,AUDIO));
	if (src_ch < 0)
		return false;
	
	GetSource()->GetSourceValue(src_ch).SetFormat(internal_fmt);
	*/
	time = 0;
	return true;
}
/*
bool RollingValueBase::ProcessPackets(PacketIO& io) {
	ASSERT(internal_fmt.IsValid());
	
	RTLOG("RollingValueBase::ProcessPackets: time=" << time << ", fmt=" << internal_fmt.ToString());
	
	PacketIO::Sink& sink = io.sink[0];
	PacketIO::Source& src = io.src[0];
	ASSERT(sink.p);
	sink.may_remove = true;
	src.from_sink_ch = 0;
	src.p = ReplyPacket(0, sink.p);
	src.p->AddRouteData(src.from_sink_ch);
	
	PacketValue& v = *src.p;
	v.SetFormat(internal_fmt);
	
	if (internal_fmt.IsAudio()) {
		int sz = internal_fmt.GetFrameSize();
		Vector<byte>& data = v.Data();
		data.SetCount(sz);
		for(byte& dst : data)
			dst = rolling_value++;
		
		time += internal_fmt.GetFrameSeconds();
	}
	else if (internal_fmt.IsVideo()) {
		TODO
	}
	else {
		Panic("invalid internal format");
		return false;
	}
	return true;
}*/







bool VoidSinkBase::Initialize(const Script::WorldState& ws) {
	flag.Start(1);
	GetSink()->GetValue(0).SetMinQueueSize(5);
	Thread::Start(THISBACK(IntervalSinkProcess));
	return true;
}

void VoidSinkBase::Uninitialize() {
	flag.Stop();
}

void VoidSinkBase::IntervalSinkProcess() {
	RTLOG("VoidSinkBase::IntervalSinkProcess: starts");
	
	const int sink_ch_i = 0;
	
	InterfaceSinkRef sink = GetSink();
	Value& sink_value = sink->GetValue(sink_ch_i);
	Format fmt = sink_value.GetFormat();
	AudioFormat& afmt = fmt;
	
	Vector<byte> data;
	data.SetCount(fmt.GetFrameSize());
	double step_s = fmt.GetFrameSeconds();
	TimeStop ts;
	
	int dbg_total_samples = 0;
	int dbg_total_bytes = 0;
	bool fail = false;
	
	while (flag.IsRunning()) {
		double t = ts.Seconds();
		
		if (t < step_s) {
			Sleep(1);
			continue;
		}
		ts.Reset();
		
		RTLOG("VoidSinkBase::IntervalSinkProcess: trying to consume " << data.GetCount());
		
		TODO
		/*if (!ForwardAsyncMem(data.Begin(), data.GetCount())) {
			LOG("VoidSinkBase::IntervalSinkProcess: warning: could not get consumable data");
			continue;
		}*/
		
		// Verify data
		TODO
		/*if (afmt.type == TS::Serial::BinarySample::FLT_LE) {
			float* it = (float*)(void*)data.begin();
			float* end = (float*)(void*)data.end();
			int dbg_i = 0;
			int dbg_count = (int)(end - it);
			for (; it != end; ++it, ++dbg_i) {
				float f0 = *it;
				double f1 = rolling_value++ / 255.0 * 2.0 - 1.0;
				ASSERT(IsClose(f0, f1));
			}
			dbg_total_samples += dbg_count;
			dbg_total_bytes += dbg_count * 4;
			
			RTLOG("VoidSinkBase::IntervalSinkProcess: successfully verified frame");
		}
		else {
			LOG("VoidSinkBase::IntervalSinkProcess: error: invalid audio format");
		}*/
	}
	LOG("VoidSinkBase::IntervalSinkProcess: stops. total-samples=" << dbg_total_samples << ", total-bytes=" << dbg_total_bytes);
	if (!fail) {LOG("VoidSinkBase::IntervalSinkProcess: success!");}
	else       {LOG("VoidSinkBase::IntervalSinkProcess: fail :(");}
	
	flag.DecreaseRunning();
}



















bool VoidPollerSinkBase::Initialize(const Script::WorldState& ws) {
	RTLOG("VoidPollerSinkBase::Initialize");
	dt = 1.0/60.0;
	GetSink()->GetValue(0).SetMinQueueSize(5);
	AddAtomToUpdateList();
	return true;
}

void VoidPollerSinkBase::Uninitialize() {
	LOG("VoidPollerSinkBase::Uninitialize: " << HexStr(this));
	LOG("VoidPollerSinkBase::Uninitialize: total-samples=" << dbg_total_samples << ", total-bytes=" << dbg_total_bytes);
	if (!fail) {LOG("VoidPollerSinkBase::Uninitialize: success!");}
	else       {LOG("VoidPollerSinkBase::Uninitialize: fail :(");}
	RemoveAtomFromUpdateList();
}

/*
void VoidPollerSinkBase::Update(double dt) {
	ts += dt;
	RTLOG("VoidPollerSinkBase::Update: dt=" + DblStr(dt) + ", ts=" << DblStr(ts));
	if (ts >= dt)
		PostContinueForward();
}

bool VoidPollerSinkBase::IsReady(PacketIO& io) {
	bool b = false;
	if (ts >= dt) {
		ts = 0;
		b = true;
	}
	RTLOG("VoidPollerSinkBase::IsReady: " << (b ? "true " : "false ") << BinStr(io.active_sink_mask));
	return b;
}

bool VoidPollerSinkBase::ProcessPackets(PacketIO& io) {
	PacketIO::Sink& prim_sink = io.sink[0];
	Packet& in = prim_sink.p;
	
	uint64 route_desc = in->GetRouteDescriptor();
	
	RTLOG("VoidPollerSinkBase::ProcessPackets: sink #0: " << io.sink[0].p->ToString() << ", descriptor " << HexStr(route_desc));
	
	Parallel::Format fmt = in->GetFormat();
	if (fmt.IsAudio()) {
		Serial::AudioFormat& afmt = fmt;
		
		int i = thrds.Find(route_desc);
		if (i < 0) {
			i = thrds.GetCount();
			thrds.Add(route_desc);
			RTLOG("VoidPollerSinkBase::ProcessPackets: creating new thread for route " + IntStr64(route_desc));
		}
		
		Thread& t = thrds[i];
		const Vector<byte>& data = in->GetData();
		if (data.IsEmpty()) {
			LOG("VoidPollerSinkBase::ProcessPackets: error: thrd #" << i << " empty data");
			fail = true;
		}
		else if (afmt.type == TS::Serial::BinarySample::FLT_LE) {
			float* it = (float*)(void*)data.begin();
			float* end = (float*)(void*)data.end();
			int dbg_i = 0;
			int dbg_count = (int)(end - it);
			for (; it != end; ++it, ++dbg_i) {
				float f0 = *it;
				double f1 = t.rolling_value++ / 255.0 * 2.0 - 1.0;
				ASSERT(IsClose(f0, f1));
				if (!IsClose(f0, f1)) {
					fail = true;
					break;
				}
			}
			dbg_total_samples += dbg_count;
			dbg_total_bytes += dbg_count * 4;
			
			RTLOG("VoidPollerSinkBase::ProcessPackets: thrd #" << i << " successfully verified frame size " << data.GetCount());
		}
		else {
			LOG("VoidPollerSinkBase::ProcessPackets: error: thrd #" << i << " invalid audio format");
			fail = true;
		}
	}
	else {
		RTLOG("VoidPollerSinkBase::ProcessPackets: error: unexpected packet " << in->ToString());
	}
	
	prim_sink.may_remove = true;
	
	PacketIO::Source& prim_src = io.src[0];
	prim_src.from_sink_ch = 0;
	prim_src.p = ReplyPacket(0, in);
	return true;
}
*/


NAMESPACE_PARALLEL_END
