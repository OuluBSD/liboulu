#include "Internal.h"

NAMESPACE_SERIAL_BEGIN


int AtomBase::GetSinkPacketCount() {
	InterfaceSinkRef sink_iface = GetSink();
	int sink_count = sink_iface->GetSinkCount();
	int c = 0;
	for(int i = 0; i < sink_count; i++)
		c += sink_iface->GetValue(i).GetQueueSize();
	return c;
}

int AtomBase::GetSourcePacketCount() {
	InterfaceSourceRef src_iface = GetSource();
	int src_count = src_iface->GetSourceCount();
	int c = 0;
	for(int i = 0; i < src_count; i++)
		c += src_iface->GetSourceValue(i).GetQueueSize();
	return c;
}

void AtomBase::ForwardAtom(FwdScope& fwd) {
	RTLOG("AtomBase::ForwardAtom");
	
	fwd_lock.Enter();
	
	last_cfg = &fwd.Cfg();
	
	#ifdef flagDEBUG
	int ch_i = 0;
	int pre_sink_packet_count = GetSinkPacketCount();
	int pre_src_packet_count = GetSourcePacketCount();
	int pre_consumed_partial = IsConsumedPartialPacket();
	int pre_total =
		  pre_sink_packet_count
		  + pre_src_packet_count
		  - pre_consumed_partial; // partial packet stays in sink while fraction is consumed
	#endif
	
	
	ForwardPipe(fwd);
	
	
	
	#ifdef flagDEBUG
	AtomTypeCls type = GetType();
	int post_sink_packet_count = GetSinkPacketCount();
	int post_src_packet_count = GetSourcePacketCount();
	int post_consumed_partial = IsConsumedPartialPacket();
	int post_total =
		  post_sink_packet_count
		+ post_src_packet_count
		+ skipped_fwd_count
		- post_consumed_partial;
	bool consumed_only_partial =
		pre_sink_packet_count == post_sink_packet_count &&
		pre_src_packet_count == post_src_packet_count &&
		pre_consumed_partial == 1 && post_consumed_partial == 0;
	if (type.role != CUSTOMER) {
		bool is_buffered_consumer = type.iface.content.val == ValCls::AUDIO; // todo: other value formats
		ASSERT_(
			pre_total == post_total ||
			dbg_async_race ||
			consumed_only_partial ||
			is_buffered_consumer,
			"Atom lost packets. Maybe alt class did not call PacketConsumed(...) for the packet?");
		/*
		On fail:
			- have you implemented "IsConsumedPartialPacket() override" while using Value?
		*/
	}
	#endif
	
	fwd_lock.Leave();
}

void AtomBase::ForwardDriver(FwdScope& fwd) {
	Forward(fwd);
}

bool AtomBase::IsAllSideSourcesFull(const Vector<int>& src_chs) {
	auto it = src_chs.Begin();
	auto end = src_chs.End();
	while (it != end) {
		for (Exchange& ex : side_sink_conn) {
			int src_ch = *it;
			if (src_ch == 0) {
				if (!IsPrimarySourceFull())
					return false;
				if (++it == end)
					break;
			}
			if (src_ch == ex.local_ch_i) {
				InterfaceSinkRef sink_iface = ex.other->GetSink();
				Value& sink_val = sink_iface->GetValue(ex.other_ch_i);
				if (!sink_val.IsQueueFull())
					return false;
				if (++it == end)
					break;
			}
		}
	}
	return true;
}

bool AtomBase::IsAnySideSourceFull(const Vector<int>& src_chs) {
	auto it = src_chs.Begin();
	auto end = src_chs.End();
	while (it != end) {
		for (Exchange& ex : side_sink_conn) {
			int src_ch = *it;
			if (src_ch == 0) {
				if (IsPrimarySourceFull())
					return true;
				if (++it == end)
					break;
			}
			if (src_ch == ex.local_ch_i) {
				InterfaceSinkRef sink_iface = ex.other->GetSink();
				Value& sink_val = sink_iface->GetValue(ex.other_ch_i);
				if (sink_val.IsQueueFull())
					return true;
				if (++it == end)
					break;
			}
		}
	}
	return false;
}

bool AtomBase::IsPrimarySourceFull() {
	InterfaceSourceRef src_iface = GetSource();
	Value& src_val = src_iface->GetSourceValue(0);
	return src_val.IsQueueFull();
}

void AtomBase::ForwardPipe(FwdScope& fwd) {
	POPO(Pol::Serial::Atom::ConsumerFirst);
	POPO(Pol::Serial::Atom::SkipDulicateExtFwd);
	
	this->skipped_fwd_count = 0;
	
	AtomTypeCls type = GetType();
	
	Forward(fwd);
	
	InterfaceSinkRef sink_iface = GetSink();
	InterfaceSourceRef src_iface = GetSource();
	int sink_ch_count = sink_iface->GetSinkCount();
	int src_ch_count = src_iface->GetSourceCount();
	ASSERT(src_ch_count);
	if (!src_ch_count) return;
	
	bool is_forwarded = false;
	
	while (1) {
		
		dword active_iface_mask = 0;
		for(int sink_ch = 0; sink_ch < sink_ch_count; sink_ch++) {
			if (sink_iface->GetValue(sink_ch).GetQueueSize() > 0)
				active_iface_mask |= 1 << sink_ch;
		}
		
		if (active_iface_mask == 0) {
			RTLOG("AtomBase::ForwardPipe: skipping, all sinks are empty");
			break;
		}
		
		if (!(active_iface_mask & 1)) {
			RTLOG("AtomBase::ForwardPipe: skipping, primary sink is empty");
			break;
		}
		
		if (IsPrimarySourceFull()) {
			RTLOG("AtomBase::ForwardPipe: skipping, primary source is full");
			break;
		}
		
		TODO
		#if 0
		if (src_ch_count > 1) {
			src_chs.SetCount(0);
			for(int i = 1; i < src_ch_count; i++)
				src_chs.Add(i);
			
			if (IsAnySideSourceFull(src_chs)) {
				RTLOG("AtomBase::ForwardPipe: skipping, at least one side source is full");
				break;
			}
		}
		#endif
		
		if (!IsReady(active_iface_mask))
			break;
		
		
		PacketIO io;
		TODO
		
		if (!ProcessPackets(io)) {
			RTLOG("AtomBase::ForwardPipe: failed to process packets");
			
		}
		
		TODO
		
		#if 0
		RTLOG("AtomBase::ForwardPipe: packet iteration begin");
		bool iter_forwarded = false;
		int primary_fwd_count = 0;
		for (int sink_ch = sink_ch_count-1; sink_ch >= 0; sink_ch--) {
			if (!(active_iface_mask & (1 << sink_ch)))
				continue;
			Value& sink_value = sink_iface->GetValue(sink_ch);
			PacketBuffer& sink_buf = sink_value.GetBuffer();
			Packet in = sink_buf.First();
			
			off32 off = in->GetOffset();
			Format in_fmt = in->GetFormat();
			
			bool is_primary = sink_ch == 0;
			
			bool may_remove = false;
			
			if (!ProcessPackets(io)) {
				RTLOG("AtomBase::ForwardPipe: failed to load sink #" << sink_ch << " packet(" << off.ToString() << "), " << in_fmt.ToString());
				may_remove = !is_primary;
			}
			else {
				// Force sink-0 to src-0 forward because of loop completion
				if (is_primary) {
					bool have_prim_fwd = false;
					for (int src_ch : src_chs)
						have_prim_fwd = have_prim_fwd || src_ch == 0;
					if (!have_prim_fwd)
						src_chs.Add(0);
				}
				
				bool any_src_full = false;
				for(int src_ch : src_chs) {
					Value& src_val = src_iface->GetSourceValue(src_ch);
					if (src_val.IsQueueFull()) {
						any_src_full = true;
						break;
					}
				}
				
				if (any_src_full) {
					RTLOG("AtomBase::ForwardPipe: skipping send after load because of at least one full source");
				}
				else {
					for(int src_ch : src_chs) {
						Value& src_val = src_iface->GetSourceValue(src_ch);
						PacketBuffer& src_buf = src_val.GetBuffer();
						Format src_fmt = src_val.GetFormat();
						
						RTLOG("AtomBase::ForwardPipe: sending sink #" << sink_ch << ", src #" << src_ch << " packet(" << off.ToString() << "), " << src_fmt.ToString());
						
						Packet to;
						
						WhenEnterStorePacket(*this, to);
						StorePacket(sink_ch, src_ch, in, to);
						WhenLeaveStorePacket(to);
						
						if (to) {
							Format to_fmt = to->GetFormat();
							if (!src_fmt.IsCopyCompatible(to_fmt)) {DUMP(to_fmt); DUMP(src_fmt);}
							ASSERT(src_fmt.IsCopyCompatible(to_fmt));
							PacketTracker::Checkpoint(TrackerInfo("AtomBase::ForwardSource", __FILE__, __LINE__), *to);
							to->AddRouteData(sink_ch);
							//to->AddRouteData(src_ch); // not needed while single conn per iface
							src_buf.Add(to);
							is_forwarded = true;
							iter_forwarded = true;
						}
						else {
							RTLOG("AtomBase::ForwardPipe: error: StorePacket returned empty package");
							//StorePacket(sink_ch, src_ch, in, to);
							ASSERT(0);
						}
						
						if (src_ch == 0 && sink_ch == 0)
							primary_fwd_count++;
					}
					
					may_remove = true;
					packets_forwarded++;
				}
			}
			
			if (may_remove)
				sink_buf.RemoveFirst();
		}
		
		ASSERT(primary_fwd_count == 1);
		if (primary_fwd_count != 1)
			Panic("internal error: forwarded primary packets per iteration: " + IntStr(primary_fwd_count));
		
		if (iter_forwarded)
			ForwardSideConnections();
		
		#endif
	}
	
	
	if (is_forwarded) {
		if (fwd.IsOnce())
			PostContinueForward();
	}
	else
		fwd.Break();
	
}

void AtomBase::ForwardSideConnections() {
	InterfaceSourceRef src_iface = GetSource();
	
	for (Exchange& ex : side_sink_conn) {
		Value& src_val = src_iface->GetSourceValue(ex.local_ch_i);
		PacketBuffer& src_buf = src_val.GetBuffer();
		if (src_buf.GetCount()) {
			InterfaceSinkRef sink_iface = ex.other->GetSink();
			Value& sink_val = sink_iface->GetValue(ex.other_ch_i);
			ASSERT(!sink_val.IsQueueFull());
			PacketBuffer& sink_buf = sink_val.GetBuffer();
			sink_buf.PickAppend(src_buf);
			ASSERT(src_buf.IsEmpty());
		}
	}
}

void AtomBase::ForwardAsync() {
	RTLOG("AtomBase::ForwardAsync " << HexStr(last_cfg));
	
	if (!last_cfg)
		return;
	
	FwdScope fwd(this, *last_cfg);
	fwd.SetOnce();
	fwd.Forward();
	
}

Packet AtomBase::InitialPacket(int src_ch, off32 off) {
	Format src_fmt = GetSource()->GetSourceValue(src_ch).GetFormat();
	Packet to = CreatePacket(off);
	to->SetFormat(src_fmt);
	InternalPacketData& data = to->template SetData<InternalPacketData>();
	return to;
}

Packet AtomBase::ReplyPacket(int src_ch, const Packet& in) {
	Format src_fmt = GetSource()->GetSourceValue(src_ch).GetFormat();
	off32 off = in->GetOffset();
	Packet to = CreatePacket(off);
	to->SetFormat(src_fmt);
	to->CopyRouteData(*in);
	InternalPacketData& data = to->template SetData<InternalPacketData>();
	return to;
}

int AtomBase::FindSourceWithValDev(ValDevCls vd) {
	InterfaceSourceRef src = GetSource();
	int c = src->GetSourceCount();
	for(int i = 0; i < c; i++) {
		Value& v = src->GetSourceValue(i);
		Format f = v.GetFormat();
		if (f.vd == vd)
			return i;
	}
	return -1;
}

NAMESPACE_SERIAL_END
