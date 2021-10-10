#include "AtomLocal.h"

NAMESPACE_SERIAL_BEGIN


bool CustomerBase::Initialize(const Script::WorldState& ws) {
	RTLOG("CustomerBase::Initialize");
	
	AtomTypeCls type = GetType();
	
	//if (type.iface.content.val == ValCls::AUDIO)
	//	packet_thrds = 10;
	
	AtomBase::packets_forwarded = 0;
	customer.Create();
	AtomBaseRef r = AtomBase::AsRefT();
	ASSERT(r);
	AtomSystemRef as = AtomBase::GetMachine().template Get<AtomSystem>();
	as->AddCustomer(r);
	
	return true;
}

bool CustomerBase::PostInitialize() {
	packet_thrds = GetSink()->GetValue(0).GetMinPackets();
	
	return true;
}

void CustomerBase::Uninitialize() {
	AtomBaseRef r = AtomBase::AsRefT();
	ASSERT(r);
	AtomBase::GetMachine().template Get<AtomSystem>()->RemoveCustomer(r);
}

void CustomerBase::UpdateConfig(double dt) {
	ASSERT(customer);
	DefaultInterfaceSourceRef src = this->GetSource();
	ASSERT(src);
	if (src) {
		int count = src->GetSourceCount();
		for(int i = 0; i < count; i++) {
			Value& val = src->GetSourceValue(i);
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
		
		Packet p = CreatePacket(off_gen);
		p->SetFormat(fmt);
		p->seq = -1;
		
		InternalPacketData& data = p->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = 1;
		
		WhenEnterCreatedEmptyPacket(p);
		WhenLeaveCreatedEmptyPacket();
		
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
	sink.may_remove = true;
	src.from_sink_ch = 0;
	src.p = InitialPacket(0, off_gen.Create());
	
	PacketTracker::StopTracking(TrackerInfo("CustomerBase::Forward", __FILE__, __LINE__), *sink.p);
	
	return true;
}




JoinerBase::JoinerBase() {
	
}

bool JoinerBase::Initialize(const Script::WorldState& ws) {
	
	return true;
}

void JoinerBase::Uninitialize() {
	
}

bool JoinerBase::IsReady(PacketIO& io) {
	RTLOG("JoinerBase::IsReady: " << BinStr(io.active_sink_mask));
	// require primary and single side channel
	int src_ch_count = GetSink()->GetSinkCount();
	if (!(io.active_sink_mask & 1))
		return false;
	for(int i = 1; i < src_ch_count; i++)
		if (io.active_sink_mask & (1 << i))
			return true;
	return false;
}

bool JoinerBase::ProcessPackets(PacketIO& io) {
	
	TODO
	#if 0
	if (sink_ch > 0) {
		RTLOG("JoinerBase::LoadPacket: active ch-1 packet" << in->ToString());
		fwd_src_chs.Add(0);
	}
	else {
		RTLOG("JoinerBase::LoadPacket: skipping ch-" << sink_ch << " packet");
	}
	#endif
	
	return true;
}

#if 0
void JoinerBase::ProcessPackets(PacketIO& io) {
	if (!sink_ch && !src_ch) {
		RTLOG("JoinerBase::StorePacket: (" << sink_ch << "," << src_ch << "): default reply to " << in->ToString());
		out = ReplyPacket(src_ch, in);
	}
	else {
		RTLOG("JoinerBase::StorePacket: (" << sink_ch << "," << src_ch << "): in " << in->ToString());
		out = in;
	}
}
#endif


SplitterBase::SplitterBase() {
	
}

bool SplitterBase::Initialize(const Script::WorldState& ws) {
	
	return true;
}

void SplitterBase::Uninitialize() {
	
}

bool SplitterBase::ProcessPackets(PacketIO& io) {
	TODO
	#if 0
	int src_count = GetSource()->GetSourceCount();
	for(int i = 1; i < src_count; i++) {
		fwd_src_chs.Add(i);
	}
	#endif
	return true;
}

#if 0
void SplitterBase::StorePacket(int sink_ch,  int src_ch, const Packet& in, Packet& out) {
	if (src_ch > 0) {
		Format in_fmt = in->GetFormat();
		Format src_fmt = GetSource()->GetSourceValue(src_ch).GetFormat();
		if (in_fmt.IsCopyCompatible(src_fmt)) {
			out = in;
			RTLOG("SplitterBase::StorePacket: active copy-compatible packet: " << out->ToString());
		}
		else {
			out = CreatePacket(in->GetOffset());
			out->SetFormat(src_fmt);
			if (Convert(in, out)) {
				RTLOG("SplitterBase::StorePacket: active converted packet: " << out->ToString());
				out->CopyRouteData(*in);
				out->AddRouteData(sink_ch);
			}
			else {
				RTLOG("SplitterBase::StorePacket: packet conversion failed from " << in->ToString());
				out.Clear();
			}
		}
	}
	else {
		RTLOG("SplitterBase::StorePacket: default reply");
		out = ReplyPacket(src_ch, in);
	}
}
#endif

#ifdef flagGUI

OglShaderBase::OglShaderBase() {
	
}

bool OglShaderBase::Initialize(const Script::WorldState& ws) {
	String shader_path = ws.Get(".filepath");
	if (!buf.LoadFragmentShaderFile(shader_path))
		return false;
	
	InterfaceSinkRef sink_iface = GetSink();
	int c = sink_iface->GetSinkCount();
	for(int i = 0; i < c; i++)
		sink_iface->GetValue(i).SetMaxQueueSize(1);
	
	InterfaceSourceRef src_iface = GetSource();
	c = src_iface->GetSourceCount();
	for(int i = 0; i < c; i++)
		src_iface->GetSourceValue(i).SetMaxQueueSize(1);
	
	return true;
}

bool OglShaderBase::PostInitialize() {
	buf.is_win_fbo = false;
	buf.fb_size = Size(1280,720);
	//buf.fb_sampletype = OglBuffer::SAMPLE_FLOAT;
	if (!buf.Initialize())
		return false;
	
	return true;
}

void OglShaderBase::Uninitialize() {
	last_packet.Clear();
}

bool OglShaderBase::ProcessPackets(PacketIO& io) {
	TODO
	#if 0
	
	bool succ = true;
	Format fmt = in->GetFormat();
	if (fmt.IsFbo()) {
		int base = GetSink()->GetSinkCount() > 1 ? 1 : 0;
		if (in->IsData<InternalPacketData>()) {
			succ = buf.LoadOutputLink(sink_ch - base, in->GetData<InternalPacketData>());
		}
		else {
			RTLOG("OglShaderBase::LoadPacket: cannot handle packet: " << in->ToString());
		}
	}
	
	if (sink_ch == 0)
		last_packet = in;
	
	return succ;
	#endif
}

bool OglShaderBase::IsReady(PacketIO& io) {
	return true;
}

#if 0
void OglShaderBase::ProcessPackets(PacketIO& io) {
	RTLOG("OglShaderBase::StorePacket: " << sink_ch << ", " << src_ch << ": " << in->ToString());
	
	if (sink_ch == 0 && src_ch == 0) {
		ASSERT(last_packet);
		
		//BeginDraw();
		buf.ProcessStage(*last_cfg);
		//CommitDraw();
		
		last_packet.Clear();
		ASSERT(in->GetFormat().IsValid());
	}
	
	Format fmt = in->GetFormat();
	if (fmt.vd == VD(OGL,FBO)) {
		PacketValue& val = *in;
		InternalPacketData& data = val.GetData<InternalPacketData>();
		GetBuffer().StoreOutputLink(data);
	}
}
#endif

#endif













TestEventSrcBase::TestEventSrcBase() {
	
}

bool TestEventSrcBase::Initialize(const Script::WorldState& ws) {
	RTLOG("TestEventSrcBase::Initialize");
	return true;
}

void TestEventSrcBase::Uninitialize() {
	RTLOG("TestEventSrcBase::Uninitialize");
	
}

bool TestEventSrcBase::IsReady(PacketIO& io) {
	return true;
}

bool TestEventSrcBase::ProcessPackets(PacketIO& io) {
	TODO
	#if 0
	RTLOG("TestEventSrcBase::ProcessPackets");
	return true;
	#endif
}

#if 0
void TestEventSrcBase::StorePacket(int sink_ch,  int src_ch, const Packet& in, Packet& out) {
	RTLOG("TestEventSrcBase::StorePacket");
	
	TODO
	
	Format fmt = in->GetFormat();
	ASSERT(fmt.vd.val == ValCls::EVENT);
	if (fmt.vd.val == ValCls::EVENT) {
		CtrlEvent& ev = out->SetData<CtrlEvent>();
		RandomizeEvent(ev);
	}
	
}
#endif










EventStateBase::EventStateBase() {
	
}

bool EventStateBase::Initialize(const Script::WorldState& ws) {
	RTLOG("EventStateBase::Initialize");
	
	return true;
}

bool EventStateBase::PostInitialize() {
	RTLOG("EventStateBase::PostInitialize");
	
	return true;
}

void EventStateBase::Uninitialize() {
	RTLOG("EventStateBase::Uninitialize");
	
}

bool EventStateBase::IsReady(PacketIO& io) {
	return true;
}

bool EventStateBase::ProcessPackets(PacketIO& io) {
	TODO
	#if 0
	RTLOG("EventStateBase::LoadPacket: sink #" << sink_ch << ": " << in->ToString());
	
	TODO
	#endif
	return true;
}

#if 0
void EventStateBase::ProcessPackets(PacketIO& io) {
	RTLOG("EventStateBase::StorePacket: sink #" << sink_ch << ", src #" << src_ch << ": " << out->ToString());
	
	TODO
	
}
#endif



NAMESPACE_SERIAL_END
