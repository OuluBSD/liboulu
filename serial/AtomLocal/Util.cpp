#include "AtomLocal.h"

NAMESPACE_SERIAL_BEGIN


bool CustomerBase::AltInitialize(const Script::WorldState& ws) {
	RTLOG("CustomerBase::AltInitialize");
	
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

bool CustomerBase::AltPostInitialize() {
	packet_thrds = GetSink()->GetValue(0).GetMinPackets();
	
	return true;
}

void CustomerBase::AltUninitialize() {
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

void CustomerBase::AltForward(FwdScope& fwd) {
	//RTLOG("CustomerBase::AltForward");
	
	while (packet_count < packet_thrds) {
		RTLOG("CustomerBase::AltForward: create packet");
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
		
		//PacketTracker::Track(TrackerInfo("CustomerBase::AltForward", __FILE__, __LINE__), *p);
		sink_val.GetBuffer().Add(p);
		
		packet_count++;
	}
	
}

bool CustomerBase::LoadPacket(int ch_i, const Packet& p) {
	RTLOG("CustomerBase::LoadPacket");
	
	//if (p->seq >= 0) {
	PacketTracker::StopTracking(TrackerInfo("CustomerBase::AltForward", __FILE__, __LINE__), *p);
	//}
	return ch_i == 0;
}

void CustomerBase::AltStorePacket(int sink_ch,  int src_ch, Packet& p) {
	RTLOG("CustomerBase::AltStorePacket");
	
	p->SetOffset(off_gen.Create());
	PacketTracker::Track(TrackerInfo("CustomerBase::AltForward", __FILE__, __LINE__), *p);
	
}



JoinerBase::JoinerBase() {
	
}

bool JoinerBase::AltInitialize(const Script::WorldState& ws) {
	
	return true;
}

void JoinerBase::AltUninitialize() {
	
}

void JoinerBase::AltForward(FwdScope& fwd) {
	RTLOG("JoinerBase::AltForward");
	cur_side.Clear();
}

bool JoinerBase::LoadPacket(int ch_i, const Packet& p) {
	if (ch_i == 1) {
		RTLOG("JoinerBase::LoadPacket: active ch-1 packet" << p->ToString());
		cur_side = p;
	}
	else {
		RTLOG("JoinerBase::LoadPacket: skipping ch-" << ch_i << " packet");
	}
	return true;
}

void JoinerBase::AltStorePacket(int sink_ch, int src_ch, Packet& p) {
	if (sink_ch == 0) {
		RTLOG("JoinerBase::AltStorePacket: (" << sink_ch << "," << src_ch << "): " << p->ToString());
		p = cur_side;
	}
	else {
		RTLOG("JoinerBase::AltStorePacket: (" << sink_ch << "," << src_ch << "): skipping packet");
		p.Clear();
	}
}



SplitterBase::SplitterBase() {
	
}

bool SplitterBase::AltInitialize(const Script::WorldState& ws) {
	
	return true;
}

void SplitterBase::AltUninitialize() {
	
}

void SplitterBase::AltForward(FwdScope& fwd) {
	cur_side.Clear();
}

bool SplitterBase::LoadPacket(int ch_i, const Packet& p) {
	cur_side.Clear();
	
	Format p_fmt = p->GetFormat();
	Format sink_fmt = GetSink()->GetValue(0).GetFormat();
	if (p_fmt.IsCopyCompatible(sink_fmt)) {
		cur_side = p;
		RTLOG("SplitterBase::LoadPacket: active copy-compatible packet: " << cur_side->ToString());
	}
	else {
		cur_side = CreatePacket(p->GetOffset());
		cur_side->SetFormat(sink_fmt);
		if (Convert(p, cur_side)) {
			RTLOG("SplitterBase::LoadPacket: active converted packet: " << cur_side->ToString());
		}
		else {
			RTLOG("SplitterBase::LoadPacket: packet conversion failed from " << p->ToString());
			cur_side.Clear();
		}
			
	}
	
	return true;
}

void SplitterBase::AltStorePacket(int sink_ch, int src_ch, Packet& p) {
	if (src_ch > 0) {
		if (cur_side) {
			p = cur_side;
			RTLOG("SplitterBase::AltStorePacket: forwarded packet (" << sink_ch << ", " << src_ch << "): " << p->ToString());
		}
		else {
			RTLOG("SplitterBase::AltStorePacket: store packet failed");
		}
	}
	else {
		RTLOG("SplitterBase::AltStorePacket: skipping src 0");
	}
}


#ifdef flagGUI

OglShaderBase::OglShaderBase() {
	
}

bool OglShaderBase::AltInitialize(const Script::WorldState& ws) {
	String shader_path = ws.Get(".filepath");
	if (!buf.LoadFragmentShaderFile(shader_path))
		return false;
	
	buf.SetBufferId(ws.Get(".name"));
	
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

bool OglShaderBase::AltPostInitialize() {
	buf.is_win_fbo = false;
	buf.fb_size = Size(1280,720);
	//buf.fb_sampletype = OglBuffer::SAMPLE_FLOAT;
	if (!buf.Initialize())
		return false;
	
	return true;
}

void OglShaderBase::AltUninitialize() {
	last_packet.Clear();
}

void OglShaderBase::AltForward(FwdScope& fwd) {
	/*const int sink_ch_i = 0;
	const int src_ch_i = 0;
	
	Value& src_val = this->GetSource()->GetSourceValue(src_ch_i);
	Value& sink_val = this->GetSink()->GetValue(sink_ch_i);
	PacketBuffer& sink_buf = sink_val.GetBuffer();
	
	if (src_val.GetQueueSize() == 0 && sink_buf.GetCount()){
		RTLOG("OglShaderBase::AltForward: render");
		
		Packet p = sink_buf.First();
		sink_buf.RemoveFirst();
		PacketConsumed(p);
		last_packet = p;
	}
	else {
		RTLOG("OglShaderBase::AltForward: wait");
	}*/
}

bool OglShaderBase::LoadPacket(int ch_i, const Packet& p) {
	bool succ = true;
	Format fmt = p->GetFormat();
	if (fmt.IsVideo()) {
		if (p->IsData<InternalPacketData>()) {
			succ = buf.LoadOutputLink(p->GetData<InternalPacketData>());
		}
		else {
			RTLOG("OglShaderBase::LoadPacket: cannot handle packet: " << p->ToString());
		}
	}
	
	if (ch_i == 0)
		last_packet = p;
	
	return succ;
}

bool OglShaderBase::AltIsReady(ValDevCls vd) {
	/*const int src_ch_i = 0;
	
	Value& src_val = this->GetSource()->GetSourceValue(src_ch_i);
	return src_val.GetQueueSize() == 0;*/
	return true;
}

void OglShaderBase::AltStorePacket(int sink_ch,  int src_ch, Packet& p) {
	RTLOG("OglShaderBase::AltStorePacket: " << sink_ch << ", " << src_ch << ": " << p->ToString());
	
	if (sink_ch == 0 && src_ch == 0) {
		ASSERT(last_packet);
		
		//BeginDraw();
		buf.ProcessStage(*last_cfg);
		//CommitDraw();
		
		last_packet.Clear();
		ASSERT(p->GetFormat().IsValid());
	}
	
	Format fmt = p->GetFormat();
	if (fmt.vd == VD(ACCEL,VIDEO)) {
		PacketValue& val = *p;
		InternalPacketData& data = val.GetData<InternalPacketData>();
		GetBuffer().StoreOutputLink(data);
	}
}

#endif

NAMESPACE_SERIAL_END
