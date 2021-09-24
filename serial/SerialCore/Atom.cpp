#include "Internal.h"


NAMESPACE_SERIAL_BEGIN

// incomplete Script::Plan dtor in header
AtomBase::CustomerData::CustomerData() : cfg(gen) {}
AtomBase::CustomerData::~CustomerData() {}


AtomBase::AtomBase() {
	DBG_CONSTRUCT
}

AtomBase::~AtomBase() {
	DBG_DESTRUCT
}

Machine& AtomBase::GetMachine() {
	return GetParent()->GetMachine();
}

void AtomBase::UninitializeDeep() {
	AltUninitialize();
	Uninitialize();
	ClearSinkSource();
	UninitializeAtom();
}

void AtomBase::PostContinueForward() {
	ASSERT(last_cfg);
	if (last_cfg)
		GetMachine().Get<AtomSystem>()->AddOnce(*this, *last_cfg);
}

LoopRef AtomBase::GetLoop() {
	return GetParent()->AsRefT();
}

String AtomBase::ToString() const {
	return GetDynamicName();
}

void AtomBase::ForwardExchange(FwdScope& fwd) {
	int ch_i = 0;
	
	Value& src_val = GetSource()->GetSourceValue(ch_i);
	//SimpleBufferedValue* src_buf = CastPtr<SimpleBufferedValue>(&src_val);
	//if (src_buf && !src_buf->IsEmpty()) {
	if (src_val.GetQueueSize()) {
		ExchangeSourceProvider* src = CastPtr<ExchangeSourceProvider>(this);
		ASSERT(src);
		ExchangePointRef expt = src->GetExPt();
		ASSERT(expt);
		if (expt) {
			fwd.AddNext(*expt);
		}
	}
}

void AtomBase::ForwardConsumed(FwdScope& fwd) {
	int src_ch_i = 0;
	int sink_ch_i = 0;
	
	Value& src_value = GetSource()->GetSourceValue(src_ch_i);
	Value& sink_value = GetSink()->GetValue(sink_ch_i);
	auto& sink_buf = sink_value.GetBuffer();
	auto& src_buf = src_value.GetBuffer();
	Format src_fmt = src_value.GetFormat();
	AtomTypeCls type = GetType();
	
	RealtimeSourceConfig& cfg = fwd.Cfg();
	
	lock.Enter();
	LinkedList<Packet> consumed_packets;
	MemSwap(this->consumed_packets, consumed_packets);
	lock.Leave();
	
	Index<dword> offs;
	for (auto& in : consumed_packets) {
		off32 off = in->GetOffset();
		if (offs.Find(off.value) >= 0) {
			// receipt is already sent
			continue;
		}
		offs.Add(off.value);
		
		RTLOG("AtomBase::ForwardSink: sending receipt for packet(" << off.ToString() << ")");
		Packet to = CreatePacket(off);
		ASSERT(to->GetOffset() == off);
		to->SetFormat(src_fmt);
		
		InternalPacketData& data = to->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = 1;
		
		if (type.IsRoleSideSource()) {
			WhenEnterCreatedEmptyPacket(to);
			
			RTLOG("AtomBase::ForwardSink: sending empty packet in format: " << src_fmt.ToString());
			//to->SetFormat(src_fmt);
			
			WhenLeaveCreatedEmptyPacket();
		}
		else {
			WhenEnterStorePacket(*this, to);
			
			StorePacket(to);
			
			if (!to->GetFormat().IsValid()) {DUMP(src_fmt); DUMP(to->GetFormat());}
			ASSERT(to->GetFormat().IsValid());
			
			WhenLeaveStorePacket(to);
		}
		
		PacketTracker::Track(TrackerInfo("AtomBase::ForwardSink", __FILE__, __LINE__), *to);
		src_buf.Add(to);
		packets_forwarded++;
	}
	
}

String AtomBase::GetInlineConnectionsString() const {
	String s;
	s << "sink(";
	int i = 0;
	for (AtomBaseRef& iface : side_sink_conn) {
		if (i++ > 0) s << ", ";
		s << HexStr(&*iface);
	}
	s << "), src(";
	i = 0;
	for (AtomBaseRef& iface : side_src_conn) {
		if (i++ > 0) s << ", ";
		s << HexStr(&*iface);
	}
	s << ")";
	return s;
}

bool AtomBase::LinkSideSink(AtomBaseRef sink) {
	//side_src = -1; // SetSideSrc(-1)
	ASSERT(sink);
	//ASSERT(!side_sink_conn);
	if (!sink)
		return false;
	
	AtomTypeCls type = sink->GetType();
	//DUMP(type);
	ASSERT(type.role == AtomRole::SIDE_SINK);
	if (PassLinkSideSink(sink)) {
		side_sink_conn.Add(sink);
		RTLOG(HexStr((void*)this) << " connections: " << GetInlineConnectionsString());
		return true;
	}
	return false;
}

bool AtomBase::LinkSideSource(AtomBaseRef src) {
	//side_sink = -1; // SetSideSink(-1)
	ASSERT(src);
	if (!src)
		return false;
	
	AtomTypeCls type = src->GetType();
	//DUMP(type);
	ASSERT(type.role == AtomRole::SIDE_SOURCE);
	if (PassLinkSideSource(src)) {
		side_src_conn.Add(src);
		RTLOG(HexStr((void*)this) << " connections: " << GetInlineConnectionsString());
		return true;
	}
	return false;
}


void AtomBase::PacketConsumed(const Packet& p) {
	lock.Enter();
	consumed_packets.Add(p);
	lock.Leave();
}

void AtomBase::PacketsConsumed(const LinkedList<Packet>& v) {
	lock.Enter();
	consumed_packets.Append(v);
	lock.Leave();
}








void AtomMap::Dump() {
	auto iter = AtomMapBase::begin();
	for(int i = 0; iter; ++iter, ++i) {
		LOG(i << ": " <<
			iter.value().GetDynamicName() << ": \"" <<
			iter.value().ToString() << "\"");
	}
}

void AtomMap::ReturnAtom(AtomStore& s, AtomBase* c) {
	s.ReturnAtom(c);
}




NAMESPACE_SERIAL_END
