#include "Internal.h"

NAMESPACE_SERIAL_BEGIN


void AtomBase::ForwardAtom(FwdScope& fwd) {
	RTLOG("AtomBase::ForwardAtom");
	/*POPO(Pol::Serial::Atom::ConsumerFirst);
	POPO(Pol::Serial::Atom::SkipDulicateExtFwd);
	
	if (fwd.GetPos() > 0) {
		Forward(fwd);
	}
	else {
		RTLOG("AtomBase::ForwardAtom: skip duplicate extension forward");
	}
	
	ForwardConsumed(fwd);*/
	
	
	AtomTypeCls type = GetType();
	switch (type.role) {
		case CUSTOMER:		ForwardCustomer(fwd);	return;
		case SOURCE:		ForwardInput(fwd);		return;
		case SINK:			ForwardOutput(fwd);		return;
		case CONVERTER:		ForwardInput(fwd);		return;
		case SIDE_SOURCE:	ForwardSideOutput(fwd);	return;
		case SIDE_SINK:		ForwardSideInput(fwd);	return;
		default: break;
	}
	
	TODO
}

void AtomBase::ForwardCustomer(FwdScope& fwd) {
	CustomerData* p = GetCustomerData();
	ASSERT(p);
	if (!p) return;
	
	CustomerData& c = *p;
	
	int read_i = fwd.GetPos();
	if (read_i == 0) {
		Value& src_value = GetSource()->GetSourceValue();
		
		if (src_value.IsQueueFull()) {
			RTLOG("AtomBase::ForwardCustomer: customer: skipping order, because queue is full");
			return;
		}
		
		off32 off = c.gen.Create();
		Packet p = CreatePacket(off);
		
		c.unfulfilled_offsets.Add(off.value);
		
		Format fmt = src_value.GetFormat();
		ASSERT(fmt.IsValid());
		RTLOG("AtomBase::ForwardCustomer: customer: sending order " << off.ToString() << " in format: " << fmt.ToString());
		p->SetFormat(fmt);
		
		//DUMP(c.plans.GetCount());
		ASSERT(c.plans.GetCount() == 1);
		Script::Plan& ep = c.plans[0];
		InternalPacketData& data = p->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = ep.plan.GetCount()-1;
		
		WhenEnterCreatedEmptyPacket(p);
		WhenLeaveCreatedEmptyPacket();
		
		PacketTracker::Track(TrackerInfo("AtomBase::ForwardCustomer", __FILE__, __LINE__), *p);
		src_value.GetBuffer().Add(p);
		packets_forwarded++;
	}
	else {
		Value& sink_value = GetSink()->GetValue();
		
		PacketBuffer& buf = sink_value.GetBuffer();
		for (Packet& p : buf) {
			off32 off = p->GetOffset();
			c.unfulfilled_offsets.RemoveKey(off.value);
			RTLOG("AtomBase::ForwardCustomer: customer: removing fulfilled packet " << off.ToString());
		}
		buf.Clear();
		
		
		/*if (c.unfulfilled_offsets.GetCount() > c.max_unfulfilled) {
			LOG("AtomBase::Forward: customer: error: too many unfulfilled packets");
			DUMPC(c.unfulfilled_offsets);
			while (c.unfulfilled_offsets.GetCount() > c.max_unfulfilled)
				c.unfulfilled_offsets.Remove(0);
		}*/
	}
}

void AtomBase::ForwardInput(FwdScope& fwd) {
	
	// From source
	InterfaceSinkRef iface_sink = GetSink();
	Value& sink_val = iface_sink->GetValue();
	SimpleBufferedValue* sink_buf_val;
	SimpleValue* sink_sval;
	PacketBuffer* sink_buf;
	if ((sink_buf_val = CastPtr<SimpleBufferedValue>(&sink_val))) {
		sink_buf = &sink_buf_val->GetBuffer();
	}
	else if ((sink_sval = CastPtr<SimpleValue>(&sink_val))) {
		sink_buf = &sink_sval->GetBuffer();
	}
	else TODO
	
	ForwardInputBuffer(fwd, *sink_buf);
}


void AtomBase::ForwardInputBuffer(FwdScope& fwd, PacketBuffer& sink_buf) {
	
	// To sink
	InterfaceSourceRef iface_src = GetSource();
	Value& val = iface_src->GetStream().Get();
	SimpleValue* sval;
	SimpleBufferedValue* sbcal;
	PacketBuffer* pbuf;
	if ((sval = CastPtr<SimpleValue>(&val))) {
		pbuf = &sval->GetBuffer();
	}
	else if ((sbcal = CastPtr<SimpleBufferedValue>(&val))) {
		pbuf = &sbcal->GetBuffer();
	}
	else TODO
	
	RTLOG("AtomBase::ForwardInput: pre sink=" << sink_buf.GetCount() << ", src=" << val.GetBuffer().GetCount());
	Format fmt = iface_src->GetSourceValue().GetFormat();
	
	while (sink_buf.GetCount() && !val.IsQueueFull()) {
		if (!IsReady(fmt.vd))
			break;
		Packet in = sink_buf.First();
		sink_buf.RemoveFirst();
		
		//int c = sink_buf.IsEmpty() ? 100 : 1;
		
		//for(int i = 0; i < c && !val.IsQueueFull(); i++) {
		off32 off = in->GetOffset();
		RTLOG("AtomBase::ForwardInput: play packet " << off.ToString());
		
		Packet to = CreatePacket(off);
		
		InternalPacketData& data = to->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = 1;
		
		if (1) {
			WhenEnterStorePacket(*this, to);
			
			LoadPacket(in);
			StorePacket(to);
			
			WhenLeaveStorePacket(to);
		}
		else {
			WhenEnterCreatedEmptyPacket(to);
			
			RTLOG("AtomBase::ForwardInput: sending packet in format: " << fmt.ToString());
			to->SetFormat(fmt);
			
			WhenLeaveCreatedEmptyPacket();
		}
		
		PacketTracker::Track(TrackerInfo("AtomBase::ForwardInput", __FILE__, __LINE__), *to);
		pbuf->Add(to);
		packets_forwarded++;
		//}
	}
	
	
	/* BREAKS OFFSET CHECKING!
	if (InterfaceSink::iface.val.type == ValCls::ORDER) {
		sink_buf->Clear();
		RTLOG("AtomBase::ForwardInput: cleared order-sink buffer");
	}*/
	
	{
		int src_total = 0;
		int src_ch_samples = 0;
		for (Packet& p : *pbuf) {
			src_total += p->GetSizeBytes();
			src_ch_samples += p->GetSizeChannelSamples();
		}
		RTLOG("AtomBase::ForwardInput: post sink=" << sink_buf.GetCount() << ", src=" << val.GetBuffer().GetCount() << " (total " << src_total << " bytes, " << src_ch_samples << " ch-samples)");
	}
	
}

void AtomBase::ForwardOutput(FwdScope& fwd) {
	POPO(Pol::Serial::Atom::ConsumerFirst);
	POPO(Pol::Serial::Atom::SkipDulicateExtFwd);
	if (fwd.GetPos() > 0) {
		Forward(fwd);
	}
	else {
		RTLOG("AtomBase::ForwardOutput: skip duplicate extension forward");
	}
	
	
	ForwardConsumed(fwd);
}

/*void AtomBase::ForwardConverter(FwdScope& fwd) {
	POPO(Pol::Serial::Atom::ConsumerFirst);
	POPO(Pol::Serial::Atom::SkipDulicateExtFwd);
	if (fwd.GetPos() > 0) {
		if (this->ext)
			this->ext->Forward(fwd);
	}
	else {
		RTLOG("AtomBase::ForwardOutput: skip duplicate extension forward");
	}
	
	
	ForwardConsumed(fwd);
}*/

void AtomBase::ForwardSideInput(FwdScope& fwd) {
	POPO(Pol::Serial::Atom::ConsumerFirst);
	POPO(Pol::Serial::Atom::SkipDulicateExtFwd);
	if (fwd.GetPos() > 0) {
		Forward(fwd);
	}
	else {
		RTLOG("AtomBase::ForwardSideInput: skip duplicate extension forward");
	}
	
	Value& sink_value = GetSink()->GetValue();
	auto& sink_buf = sink_value.GetBuffer();
	Format sink_fmt = sink_value.GetFormat();
	
	InterfaceSideSinkRef side_sink = GetSideSink();
	ASSERT(side_sink);
	if (!side_sink) return;
	
	Value* side_sink_value = side_sink->GetSideValue();
	ASSERT(side_sink_value);
	if (!side_sink_value) return;
	auto& side_sink_buf = side_sink_value->GetBuffer();
	Format side_sink_fmt = side_sink_value->GetFormat();
	
	Value& src_value = GetSource()->GetSourceValue();
	auto& src_buf = src_value.GetBuffer();
	Format src_fmt = src_value.GetFormat();
	
	while (sink_buf.GetCount() && side_sink_buf.GetCount() && !src_value.IsQueueFull()) {
		Packet side_p = side_sink_buf.First();
		Packet sink_p = sink_buf.First();
		side_sink_buf.RemoveFirst();
		sink_buf.RemoveFirst();
		
		PacketTracker::StopTracking(TrackerInfo("AtomBase::ForwardSideInput", __FILE__, __LINE__), sink_p);
		off32 off = sink_p->GetOffset();
		sink_p.Clear();
		
		RTLOG("AtomBase::ForwardSideInput: forwarding side packet in format: " << side_p->GetFormat().ToString());
		
		if (side_p->GetFormat() == src_fmt) {
			side_p->SetOffset(off);
			src_buf.Add(side_p);
		}
		else {
			Packet dst = CreatePacket(off);
			if (Convert(side_p, dst))
				src_buf.Add(dst);
			else {
				RTLOG("AtomBase::ForwardSideInput: error: packet conversion failed");
			}
		}
	}
}

void AtomBase::ForwardSideOutput(FwdScope& fwd) {
	POPO(Pol::Serial::Atom::ConsumerFirst);
	POPO(Pol::Serial::Atom::SkipDulicateExtFwd);
	if (fwd.GetPos() > 0) {
		Forward(fwd);
	}
	else {
		RTLOG("AtomBase::ForwardOutput: skip duplicate extension forward");
	}
	
	Value& sink_value = GetSink()->GetValue();
	auto& sink_buf = sink_value.GetBuffer();
	
	InterfaceSideSourceRef side_out = GetSideSource();
	ExchangeSideSinkProviderRef side_link_in = side_out->GetSideSourceLink();
	ASSERT(side_link_in);
	InterfaceSideSinkRef side_in = side_link_in;
	ASSERT(side_in);
	//LOG(HexStr((void*)this) << " side_in = " << HexStr(side_in.Get()));
	
	Value* side_sink_value = side_in->GetSideValue();
	ASSERT(side_sink_value);
	auto& side_sink_buf = side_sink_value->GetBuffer();
	Format side_sink_fmt = side_sink_value->GetFormat();
	
	while (sink_buf.GetCount() && !side_sink_value->IsQueueFull()) {
		Packet in = sink_buf.First();
		sink_buf.RemoveFirst();
		
		off32 o = in->GetOffset();
		
		RTLOG("AtomBase::ForwardSideOutput: sending side-out packet(" << o.ToString() << ")");
		
		consumed_packets.Add(in);
		
		if (in->GetFormat() != side_sink_fmt) {
			Packet dst = CreatePacket(o);
			dst->SetFormat(side_sink_fmt);
			Convert(in, dst);
			in = dst;
		}
		
		side_sink_buf.Add(in);
	}
	
	
	ForwardConsumed(fwd);
}

void AtomBase::ForwardVoidSink(FwdScope& fwd) {
	Value& src_value = GetSource()->GetSourceValue();
	Stream& src_stream = GetSource()->GetStream();
	Value& sink_value = GetSink()->GetValue();
	auto& sink_buf = sink_value.GetBuffer();
	auto& src_buf = src_value.GetBuffer();
	RealtimeSourceConfig& cfg = fwd.Cfg();
	AtomTypeCls type = GetType();
	
	lock.Enter();
	
	Index<dword> offs;
	for (auto& in : consumed_packets) {
		off32 o = in->GetOffset();
		if (offs.Find(o.value) >= 0)
			continue;
		offs.Add(o.value);
		
		Packet to = CreatePacket(o);
	
		Format fmt = GetDefaultFormat(type.iface.src);
		RTLOG("AtomBase::ForwardVoidSink: sending packet in format: " << fmt.ToString());
		to->SetFormat(fmt);
		
		InternalPacketData& data = to->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = 1;
		
		StorePacket(to);
		
		PacketTracker::Track(TrackerInfo("AtomBase::ForwardVoidSink", __FILE__, __LINE__), *to);
		src_buf.Add(to);
	}
	
	lock.Leave();
}

bool AtomBase::ForwardMem(void* mem, size_t mem_size) {
	Value& sink_value = GetSink()->GetValue();
	Value& src_value = GetSource()->GetSourceValue();
	
	if (consumer.IsEmptySource())
		consumer.SetSource(sink_value.GetBuffer());
	
	if (mem) {
		Format fmt = sink_value.GetFormat();
		
		int size = fmt.GetFrameSize();
		if (size != mem_size) {
			RTLOG("AtomBase::ForwardMem: error: memsize mismatch (" << size << " != " << mem_size << ")");
			return false;
		}
		
		int qsize = sink_value.GetQueueSize();
		if (qsize > 0 || consumer.HasLeftover()) {
			
			/*off32 begin_offset = buf.GetOffset();
			if (0) {
				RTLOG("BufferedAudioDeviceStream::SinkCallback: trying to consume " << begin_offset.ToString());
				RTLOG("BufferedAudioDeviceStream::SinkCallback: dumping");
				buf.Dump();
			}*/
			
			consumer.SetDestination(fmt, mem, size);
			consumer.ConsumeAll(false);
			consumer.ClearDestination();
			int csize = consumer.GetLastMemoryBytes();
			int consumed_count = consumer.GetCount();
			if (csize != size) {
				RTLOG("AtomBase::ForwardMem: error: consumed " << csize << " (expected " << size << "), packets=" << consumed_count);
			}
			else {
				RTLOG("AtomBase::ForwardMem:  consumed " << csize << ", packets=" << consumed_count);
			}
			
			lock.Enter();
			consumed_packets.Append(consumer.consumed_packets);
			lock.Leave();
			
			CustomerData* cust_data = GetCustomerData();
			if (cust_data)
				GetMachine().Get<AtomSystem>()->AddOnce(*this, cust_data->cfg);
			
			/*off32 end_offset = consumer.GetOffset();
			off32 diff = off32::GetDifference(begin_offset, end_offset);
			if (diff) {
				RTLOG("BufferedAudioDeviceStream::SinkCallback: device consumed count=" << diff.ToString());
				buf.RemoveFirst(diff.value);
			}
			else if (consumer.HasLeftover()) {
				RTLOG("BufferedAudioDeviceStream::SinkCallback: device consumed packet partially");
			}
			else if (!consumer.HasLeftover()) {
				RTLOG("error: BufferedAudioDeviceStream::SinkCallback: device error");
			}*/
			return true;
		}
		else {
			#if DEBUG_RT_PIPE
			RTLOG("error: AtomBase::ForwardMem: got empty data");
			#endif
			
			memset(mem, 0, size);
		}
	}
	return false;
}


NAMESPACE_SERIAL_END
