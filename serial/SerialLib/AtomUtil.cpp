#include "SerialLib.h"

NAMESPACE_SERIAL_BEGIN


bool AsyncMemForwarderBase::ForwardAsyncMem(byte* mem, int size)  {
	RTLOG("AsyncMemForwarderBase::ForwardAsyncMem: size " << size << " at " << HexStr(mem));
	ASSERT(size > 0);
	write_mem = mem;
	write_size = size;
	write_pos = 0;
	
	ASSERT(partial_pos == 0 || !partial_packet.IsEmpty());
	if (partial_packet) {
		RTLOG("AsyncMemForwarderBase::ForwardAsyncMem: consuming partial packet");
		Consume(partial_pos, partial_packet);
	}
	else {
		RTLOG("AsyncMemForwarderBase::ForwardAsyncMem: no partial packet");
	}
	
	if (write_pos < size)
		ForwardAsync();
	
	if (write_pos < size) {
		RTLOG("AsyncMemForwarderBase::ForwardAsyncMem: warning: not enough packets to read memory entirely");
	}
	
	bool succ = write_pos == size;
	
	write_mem = 0;
	write_size = 0;
	write_pos = 0;
	
	//RTLOG("AsyncMemForwarderBase::ForwardAsyncMem: returning");
	
	return succ;
}

bool AsyncMemForwarderBase::ProcessPackets(PacketIO& io) {
	TODO
	#if 0
	RTLOG("AsyncMemForwarderBase::LoadPacket: sink #" << sink_ch << " " << in->ToString());
	if (PassLoadPacket(sink_ch, in, fwd_src_chs))
		Consume(sink_ch, in);
	#endif
	return true;
}

#if 0
void AsyncMemForwarderBase::ProcessPackets(PacketIO& io) {
	RTLOG("AsyncMemForwarderBase::StorePacket");
	out = this->ReplyPacket(src_ch, in);
}
#endif

bool AsyncMemForwarderBase::IsReady(dword active_iface_mask) {
	bool b = write_mem != 0 && write_pos < write_size;
	RTLOG("AsyncMemForwarderBase::IsReady: " << (b ? "true" : "false"));
	return b;
}

void AsyncMemForwarderBase::Consume(int data_begin, Packet p) {
	RTLOG("AsyncMemForwarderBase::Consume: " << p->ToString());
	partial_packet.Clear();
	partial_pos = 0;
	
	const Vector<byte>& data = p->GetData();
	int data_sz = data.GetCount();
	int sz = data_sz - data_begin;
	int remaining = write_size - write_pos;
	
	Format fmt = p->GetFormat();
	
	if (sz > 0 && remaining > 0) {
		int cp_sz = min(sz, remaining);
		byte* dst = write_mem + write_pos;
		const byte* src = (const byte*)data.Begin() + data_begin;
		MemoryCopy(dst, src, cp_sz);
		write_pos += cp_sz;
		int p_remaining = data_sz - data_begin - cp_sz;
		ASSERT(p_remaining >= 0);
		RTLOG("AsyncMemForwarderBase::Consume: got " << write_pos << "/" << write_size);
		if (p_remaining > 0) {
			partial_packet = p;
			partial_pos = data_begin + cp_sz;
			RTLOG("AsyncMemForwarderBase::Consume: storing partial packet: remaining " << data_sz-partial_pos << "/" << data_sz);
		}
	}
	
}
















void FramePollerBase::Update(double dt) {
	ASSERT(dt > 0.0);
	frame_age += dt;
	RTLOG("FramePollerBase::Update: dt: " << dt << ", frame_age: " << frame_age);
}

bool FramePollerBase::IsReady(dword active_iface_mask) {
	bool b = frame_age >= dt;
	RTLOG("FramePollerBase::IsReady: " << (b ? "true" : "false"));
	return b;
}




NAMESPACE_SERIAL_END