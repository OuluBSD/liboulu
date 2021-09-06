#include "AtomDebug.h"


NAMESPACE_SERIAL_BEGIN


void TestRealtimeSrc::StorePacket(Packet& p) {
	ASSERT(internal_fmt.IsValid());
	
	RTLOG("TestRealtimeSrc::StorePacket: time=" << time << ", fmt=" << internal_fmt.ToString());
	ASSERT_(!p->GetFormat().IsValid(), "Packed shouldn't be initialized before this");
	PacketValue& pv = *p;
	pv.SetFormat(internal_fmt);
	
	Vector<byte>& data = pv.Data();
	data.SetCount(internal_fmt.GetFrameSize());
	for(byte& dst : data)
		dst = rolling_value++;
	
	time += internal_fmt.GetFrameSeconds();
}





void TestRealtimeSink::IntervalSinkProcess() {
	RTLOG("TestRealtimeSink::IntervalSinkProcess: starts");
	
	InterfaceSinkRef sink = GetSink();
	Value& sink_value = sink->GetValue();
	Serial::Format fmt = sink_value.GetFormat();
	Serial::AudioFormat& afmt = fmt;
	Vector<byte> data;
	data.SetCount(fmt.GetFrameSize());
	double step_s = fmt.GetFrameSeconds();
	TimeStop ts;
	bool do_log = false;
	#ifdef DEBUG_RT_PIPE
	do_log = true;
	#endif
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
		
		RTLOG("TestRealtimeSink::IntervalSinkProcess: trying to consume " << data.GetCount());
		
		if (do_log) {
			Serial::PacketBuffer& sink_buf = sink_value.GetBuffer();
			int total_bytes = 0;
			int total_ch_samples = 0;
			for(Packet& p : sink_buf) {
				total_bytes += p->GetSizeBytes();
				total_ch_samples += p->GetSizeChannelSamples();
			}
			String s;
			s   << "TestRealtimeSink::IntervalSinkProcess: sink has "
				<< sink_buf.GetCount() << " packets, "
				<< total_bytes << " total bytes, "
				<< total_ch_samples << " total ch samples";
			RTLOG(s);
		}
		
		if (!ForwardMem(data.Begin(), data.GetCount())) {
			RTLOG("TestRealtimeSink::IntervalSinkProcess: error: could not get consumable data");
			fail = true;
			break;
		}
		
		// Verify data
		if (afmt.type == TS::Serial::BinarySample::FLT_LE) {
			float* it = (float*)(void*)data.begin();
			float* end = (float*)(void*)data.end();
			int dbg_i = 0;
			int dbg_count = end - it;
			for (; it != end; ++it, ++dbg_i) {
				float f0 = *it;
				float f1 = rolling_value++ / 255.0 * 2.0 - 1.0;
				ASSERT(IsClose(f0, f1));
			}
			dbg_total_samples += dbg_count;
			dbg_total_bytes += dbg_count * 4;
		}
	}
	RTLOG("TestRealtimeSink::IntervalSinkProcess: stops. total-samples=" << dbg_total_samples << ", total-bytes=" << dbg_total_bytes);
	if (!fail) {LOG("TestRealtimeSink::IntervalSinkProcess: success!");}
	else       {LOG("TestRealtimeSink::IntervalSinkProcess: fail :(");}
	
	flag.DecreaseRunning();
}


NAMESPACE_SERIAL_END


