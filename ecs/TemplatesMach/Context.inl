#define TMPL(x)	template <class Dev> x ContextMachT<Dev>::

NAMESPACE_TOPSIDE_BEGIN









TMPL(void) SimpleValue::Exchange(Ex& e) {
	if (e.IsStoring()) {
		Value& sink = e.Sink();
		const RealtimeSourceConfig& conf = e.SourceConfig();
		
		VolatileBuffer* vol = CastPtr<VolatileBuffer>(&sink);
		if (vol) {
			while (!vol->IsQueueFull()) {
				Packet p = CtxT::CreatePacket();
				p->Set(fmt, offset, time);
				//p->Data().SetCount(fmt.GetFrameBytes(), 0);
				StorePacket(p);
				vol->Put(p, false);
				++offset;
				time += fmt.GetFrameSeconds();
			}
		}
		else TODO
	}
	else TODO
}

TMPL(int) SimpleValue::GetQueueSize() const {
	return 2;
}

TMPL(typename Dev::Value::Format) SimpleValue::GetFormat() const {
	return fmt;
}

TMPL(bool) SimpleValue::IsQueueFull() const {
	return true;
}











TMPL(void) SimpleBufferedValue::Exchange(Ex& e) {
	if (producer.IsEmptySource())
		producer.SetSource(buf);
	if (e.IsStoring()) {
		if (buf.IsEmpty()) {
			e.SetFail();
			return;
		}
		auto frame_iter = buf.begin();
		Packet& p = frame_iter();
		off32 buf_read_pos = p->GetOffset();
		
		// Compare exchange and source formats
		auto cmp_fmt = p->GetFormat();
		auto val_fmt = GetFormat();
		ASSERT(cmp_fmt == val_fmt);
		
		Value& sink = e.Sink();
		const RealtimeSourceConfig& conf = e.SourceConfig();
		
		VolatileBuffer* vol_aud = CastPtr<VolatileBuffer>(&sink);
		if (vol_aud) {
			off32 expected = e.GetOffset();
			RTLOG("SimpleBufferedValue::Exchange: expected offset " << expected.ToString() << " with buffer read position " << buf_read_pos.ToString());
			ASSERT(!sink.IsQueueFull());
			
			/*if (!(p->GetOffset() == expected)) {
				vol_aud->Dump();
			}
			ASSERT(p->GetOffset() == expected);*/
			
			if (1)
				producer.SetOffset(expected);
			else {
				producer.SetOffset(buf_read_pos);
				if (buf_read_pos != expected) {RTLOG("SimpleBufferedValue::Exchange: warning: reading unexpected buffer offset");}
				expected = buf_read_pos;
			}
			
			producer.SetDestination(*vol_aud);
			producer.SetDestinationRealtime(conf.sync);
			producer.ProduceAll();
			producer.ClearDestination();
			
			off32 end = producer.GetOffset();
			e.SetOffset(end);
			
			off32 diff = off32::GetDifference(expected, end);
			RTLOG("SimpleBufferedValue::Exchange: produced count=" << diff.ToString());
			
			sink_offsets.GetAdd(&e.Sink()) = end;
			
			exchange_count += diff.value;
			
			if (!diff)
				e.SetFail();
		}
		else {
			TODO
		}
	}
	else {
		Panic("Invalid Ex in SimpleBufferedValue");
	}
}

TMPL(int) SimpleBufferedValue::GetQueueSize() const {
	return buf.GetCount();
}

TMPL(typename Dev::Value::Format) SimpleBufferedValue::GetFormat() const {
	return fmt;
}

TMPL(bool) SimpleBufferedValue::IsQueueFull() const {
	return GetQueueChannelSamples() >= min_buf_samples;
}

TMPL(int) SimpleBufferedValue::GetQueueChannelSamples() const {
	int size = 0;
	for(auto& p : buf)
		size += p->GetSizeChannelSamples();
	return size;
}

TMPL(int) SimpleBufferedValue::GetQueueTotalSamples() const {
	int size = 0;
	for(auto& p : buf)
		size += p->GetSizeTotalSamples();
	return size;
}

TMPL(void) SimpleBufferedValue::FillBuffersNull() {
	if (!IsQueueFull()) {
		Packet p = CtxT::CreatePacket();
		RTLOG("SimpleBufferedValue::FillBuffersNull: filling buffer with empty packets " << IntStr64(frame_counter));
		off32 offset{frame_counter++};
		p->Set(fmt, offset, -1);
		p->Data().SetCount(fmt.GetFrameSize(), 0);
		buf.Add(p);
	}
}

TMPL(void) SimpleBufferedValue::DropBuffer() {
	if (exchange_count == 0)
		return;
	ASSERT(sink_offsets.GetCount());
	
	// Find sink with lowest read position
	auto sink_iter = sink_offsets.begin();
	off32 end_offset_min = sink_iter();
	for(++sink_iter; sink_iter; ++sink_iter)
		end_offset_min = std::min(end_offset_min, sink_iter());
	
	int rem_count = 0;
	auto pkt_iter = buf.begin();
	off32 anchor = pkt_iter()->GetOffset(); // for integer overflow
	for(; pkt_iter; ++pkt_iter) {
		if (off32::GetDifferenceI64(anchor, pkt_iter()->GetOffset(), end_offset_min) > 0) {
			RTLOG("SimpleBufferedValue::DropBuffer: dropping " << pkt_iter()->GetOffset().ToString());
			++rem_count;
		}
		else break;
	}
	
	if (1) {
		RTLOG("SimpleBufferedValue::DropBuffer: "
			"exchange_count " << exchange_count << ", " <<
			"rem_count " << rem_count << ", " <<
			"end_offset_min " << end_offset_min.ToString());}
	
	if (rem_count) {
		buf.RemoveFirst(rem_count);
		sink_offsets.Clear();
	}
}












TMPL(void) SimpleBufferedStream::FillBuffer() {
	while (!ptr->IsQueueFull() && !IsEof()) {
		if (ReadFrame()) {
			if (ProcessFrame())
				continue;
			if (ProcessOtherFrame())
				continue;
			
			ClearPacketData();
		}
		else break;
	}
	
	if (IsEof())
		ptr->FillBuffersNull();
	
	ClearPacketData();
}







/*TMPL(bool) VolatileBuffer::IsQueueFull() const {
	if (Buffer::IsEmpty())
		return false;
	int sz = Buffer::GetQueueSizeBytes();
	int preferred_sz = preferred_fmt.GetFrameBytes() * 2;
	return sz >= preferred_sz;
}*/

TMPL(void) VolatileBuffer::Exchange(Ex& e) {
	if (e.IsLoading()) {
		Value& aud = e.Source();
		const RealtimeSourceConfig& conf = e.SourceConfig();
		
		
		VolatileBuffer* vol_aud = CastPtr<VolatileBuffer>(&aud);
		if (vol_aud) {
			if (consumer.IsEmpty()) {
				consumer.Create();
				consumer->SetDestination(*this);
			}
			
			if (!consumer->HasLeftover() && (aud.GetQueueSize() == 0 || IsQueueFull())) {
				e.SetFail();
				return;
			}
			
			consumer->TestSetOffset(e.GetOffset()); // should be 0 with consumer, though
			consumer->SetSource(*vol_aud);
			consumer->SetDestinationRealtime(conf.sync);
			consumer->ConsumeAll();
			
			e.SetOffset(consumer->GetOffset());
		}
		else {
			TODO
		}
	}
	else if (e.IsStoring()) {
		TODO
	}
	else
		Panic("Invalid Ex");
}







TMPL(bool) PacketProducer::ProducePacket() {
	if (src->GetCount()) {
		auto iter = src->begin();
		for (; iter; ++iter)
			if (iter()->IsOffset(offset))
				break;
		if (!iter)
			return false;
		Packet p = iter();
		dst->Put(p, dst_realtime);
		internal_written_bytes += p->GetSizeBytes();
		offset = p->GetOffset();
		++offset;
		return true;
	}
	return false;
}

TMPL(void) PacketProducer::ProduceAll(bool blocking) {
	internal_written_bytes = 0;
	while (!IsFinished()) {
		if (!ProducePacket()) {
			if (!blocking) {
				break;
			}
			else {
				while (src->IsEmpty())
					Sleep(1);
			}
		}
	}
}

TMPL(bool) PacketProducer::IsFinished() const {
	return dst->IsQueueFull();
}







TMPL(void) PacketConsumer::SetSource(VolatileBuffer& src) {
	this->src = &src;
}

TMPL(void) PacketConsumer::SetDestination(const Format& fmt, void* dst, int dst_size) {
	dst_fmt = fmt;
	dst_mem = dst;
	dst_buf = 0;
	dst_iter = (byte*)dst;
	dst_iter_end = dst_iter + dst_size;
	this->dst_size = dst_size;
}

TMPL(void) PacketConsumer::SetDestination(VolatileBuffer& dst) {
	dst_fmt = dst.GetFormat();
	dst_mem = 0;
	dst_buf = &dst;
	dst_iter = 0;
	dst_iter_end = 0;
	dst_size = 0;
}

TMPL(void) PacketConsumer::ClearDestination() {
	dst_fmt.Clear();
	dst_mem = 0;
	dst_buf = 0;
	dst_iter = 0;
	dst_iter_end = 0;
	dst_size = 0;
}

TMPL(void) PacketConsumer::TestSetOffset(off32 offset) {
	if (HasLeftover()) {
		if (this->offset != offset) {
			ClearLeftover();
			SetOffset(offset);
		}
	}
	else
		SetOffset(offset);
}

TMPL(void) PacketConsumer::Consume(Packet& src, int src_data_shift) {
	Format src_fmt = src->GetFormat();
	
	if (dst_fmt.IsCopyCompatible(src_fmt)) {
		if (dst_iter) {
			const Vector<byte>& src_data = src->GetData();
			int copy_sz = src_data.GetCount() - src_data_shift;
			ASSERT(copy_sz > 0);
			int dst_remaining = dst_size - internal_written_bytes;
			if (copy_sz < dst_remaining) {
				memcpy(dst_iter, src_data.Begin() + src_data_shift, copy_sz);
				dst_iter += copy_sz;
				ASSERT(dst_iter != dst_iter_end);
			}
			else {
				copy_sz = dst_remaining;
				memcpy(dst_iter, src_data.Begin() + src_data_shift, copy_sz);
				dst_iter += copy_sz;
				ASSERT(dst_iter == dst_iter_end);
			}
			internal_written_bytes += copy_sz;
			leftover_size = src_data.GetCount() - src_data_shift - copy_sz;
			ASSERT(!leftover);
			ASSERT(leftover_size >= 0);
			if (leftover_size > 0)
				leftover = src;
			else {
				++offset;
				++internal_count;
			}
		}
		else {
			internal_written_bytes += src->GetSizeBytes();
			dst_buf->Put(src, internal_count == 0 && dst_realtime);
			++offset;
			++internal_count;
		}
	}
	else {
		Packet src2 = CtxT::CreatePacket();
		src2->Set(dst_fmt, src->GetOffset(), src->GetTime());
		Convert(src, src2);
		if (src_data_shift) {
			int src_sample = src_fmt.GetSampleSize();
			int dst_sample = dst_fmt.GetSampleSize();
			src_data_shift = src_data_shift * dst_sample / src_sample;
		}
		Consume(src2, src_data_shift);
	}
}

TMPL(bool) PacketConsumer::ConsumePacket() {
	ASSERT(dst_buf || internal_written_bytes < dst_size);
	if (leftover) {
		RTLOG("PacketConsumer::ConsumePacket: consume leftover " << leftover->GetOffset().ToString() << ", " << leftover_size << " bytes");
		ASSERT(leftover_size > 0);
		int data_shift = leftover->GetData().GetCount() - leftover_size;
		Packet p;
		Swap(leftover, p);
		Consume(p, data_shift);
		return true;
	}
	else
	if (src->GetQueueSize()) {
		RTLOG("PacketConsumer::ConsumePacket: get " << offset.ToString());
		
		Packet p = src->Get(offset);
		if (p) {
			Consume(p, 0);
			return true;
		}
	}
	return false;
}

TMPL(void) PacketConsumer::ConsumeAll(bool blocking) {
	internal_count = 0;
	internal_written_bytes = 0;
	while (!IsFinished()) {
		if (!ConsumePacket()) {
			if (!blocking) {
				int dst_remaining = dst_size - internal_written_bytes;
				if (dst_iter)
					memset(dst_iter, 0, dst_remaining);
				break;
			}
			else {
				while (!src->GetQueueSize())
					Sleep(1);
			}
		}
	}
}

TMPL(bool) PacketConsumer::IsFinished() const {
	if (dst_mem)
		return internal_written_bytes >= dst_size;
	else
		return dst_buf->IsQueueFull();
}

TMPL(void) Ex::SetOffset(off32 packet_count) {
	//RTLOG("AudioEx::SetOffset: offset " << packet_count.ToString());
	this->offset = packet_count;
}
#undef TMPL

NAMESPACE_TOPSIDE_END
