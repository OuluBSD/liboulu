#include "ParallelLib.h"


NAMESPACE_PARALLEL_BEGIN


AudioGenBase::AudioGenBase() {
	fmt.SetAudio(DevCls::CENTER, SoundSample::U8_LE, 2, 44100, 777);
	if (1)
		gen.GenerateNoise(fmt);
	else
		gen.GenerateStereoSine(fmt);
	
}

bool AudioGenBase::Initialize(const Script::WorldState& ws) {
	String waveform = ws.Get(".waveform");
	
	if (waveform == "noise")
		gen.GenerateNoise(fmt);
	else
		gen.GenerateStereoSine(fmt);
	
	const int src_ch_i = 0;
	Value& src_val = GetSource()->GetSourceValue(src_ch_i);
	src_val.SetFormat(fmt);
	return true;
}

void AudioGenBase::Uninitialize() {
	
}
bool AudioGenBase::Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	const int sink_ch = 0;
	
	
	int frame = fmt.GetFrameSize();
	dword off = out.GetOffset().value;
	int64 offset = (int64)off * (int64)frame;
	ASSERT(offset < (int64)std::numeric_limits<int>::max());
	double time = off * fmt.GetFrameSeconds();
	out.Set(fmt, time);
	out.Data().SetCount(frame, 0);
	gen.Play((int)offset, out);
	
	RTLOG("AudioGenBase::Send: offset " << (int)off << " " << out.ToStringWithHash());
	
	return true;
}


















AudioMixerBase::AudioMixerBase() {
	
}

bool AudioMixerBase::Initialize(const Script::WorldState& ws) {
	auto_limit = ws.GetBool(".auto.limit", false);
	
	return true;
}

bool AudioMixerBase::PostInitialize() {
	ISinkRef sink = GetSink();
	int sink_count = sink->GetSinkCount();
	for(int i = 1; i < sink_count; i++) {
		Value& v = sink->GetValue(i);
		Format fmt = v.GetFormat();
		ASSERT(fmt.IsAudio());
		if (fmt.IsAudio()) {
			AudioFormat& afmt = fmt;
			afmt.SetType(BinarySample::FLT_LE);
			v.SetFormat(fmt);
		}
	}
	
	ISourceRef src = GetSource();
	Value& v = src->GetSourceValue(0);
	Format fmt = v.GetFormat();
	ASSERT(fmt.IsAudio());
	AudioFormat& afmt = fmt;
	afmt.SetType(BinarySample::FLT_LE);
	v.SetFormat(fmt);
	channels = afmt.GetSize();
	
	return true;
}

void AudioMixerBase::Uninitialize() {
	queue.Clear();
	buf.Clear();
}

bool AudioMixerBase::Recv(int sink_ch, const Packet& in) {
	
	Format fmt = in->GetFormat();
	if (fmt.IsAudio()) {
		if (sink_ch >= queue.GetCount())
			queue.SetCount(sink_ch+1);
		
		Item& it = queue[sink_ch];
		it.packets.Add(in);
	}
	
	return true;
}

void AudioMixerBase::Finalize(RealtimeSourceConfig& cfg) {
	int min_remaining = INT_MAX;
	for (auto& it : queue) {
		if (it.packets.IsEmpty())
			continue;
		Packet& p = it.packets[0];
		it.fmt = p->GetFormat();
		ASSERT(it.fmt.IsAudio());
		AudioFormat& afmt = it.fmt;
		int samples = afmt.GetSampleRate();
		int remaining = samples - it.offset;
		min_remaining = min(remaining, min_remaining);
		//DUMP(remaining);
	}
	
	//DUMP(min_remaining);
	int total_samples = min_remaining * channels;
	buf.SetCount(total_samples);
	float* begin = buf.Begin();
	float* end = begin + total_samples;
	float* dst = begin;
	while (dst != end)
		*dst++ = 0;
	
	for (auto& it : queue) {
		if (it.packets.IsEmpty())
			continue;
		
		AudioFormat& afmt = it.fmt;
		int src_channels = afmt.GetSize();
		int copy_channels = min(channels, src_channels);
		int skip_channels = channels - src_channels;
		int remaining = min_remaining;
		while (!it.packets.IsEmpty() && remaining > 0) {
			Packet& p = it.packets[0];
			int copy = min(afmt.GetSampleRate() - it.offset, remaining);
			remaining -= copy;
			ASSERT(remaining >= 0);
			
			SoundSample::Type st = afmt.GetType();
			if (st == SoundSample::FLT_LE) {
				const Vector<byte>& bdata = p->GetData();
				const float* src = (const float*)(const byte*)bdata.Begin();
				src += it.offset;
				
				dst = begin;
				float* end = dst + copy * src_channels;
				while (dst != end) {
					for(int i = 0; i < copy_channels; i++)
						*dst++ += *src++;
					src += skip_channels;
				}
			}
			/*else if (st == SoundSample::U16_LE) {
				const Vector<byte>& bdata = p->GetData();
				const uint16* src = (const uint16*)(const byte*)bdata.Begin();
				src += it.offset;
				
				dst = begin;
				float* end = dst + copy;
				while (dst != end) {
					*dst++ += ConvertAudioSample<uint16,float>(*src++);
				}
			}*/
			else {
				TODO
				it.packets.Remove(0);
				it.offset = 0;
				continue;
			}
			
			int p_remaining = afmt.GetSampleRate() - copy - it.offset;
			ASSERT(p_remaining >= 0);
			if (p_remaining <= 0) {
				it.packets.Remove(0);
				it.offset = 0;
			}
			else
				it.offset = it.offset + copy;
		}
			
	}
	
	if (auto_limit) {
		float max_value = 0;
		dst = begin;
		while (dst != end)
			max_value = max(max_value, fabs(*dst++));
		//DUMP(max_value);
		dst = begin;
		if (max_value > 1.0f) {
			float mul = 1.0f / max_value;
			while (dst != end)
				*dst++ *= mul;
		}
	}
	
	//DUMPC(buf);
}

bool AudioMixerBase::Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	Format fmt = out.GetFormat();
	if (fmt.IsAudio()) {
		AudioFormat& afmt = fmt;
		ASSERT(afmt.IsSampleFloat());
		Vector<byte>& data = out.Data();
		int samples = this->buf.GetCount() / channels;
		int bytes = this->buf.GetCount() * sizeof(float);
		data.SetCount(bytes);
		if (samples) {
			if (afmt.GetSampleRate() != samples) {
				afmt.SetSampleRate(samples);
				out.SetFormat(fmt);
			}
			int fsz = fmt.GetFrameSize();
			ASSERT(bytes == fsz);
			memcpy((byte*)data.Begin(), (const float*)this->buf.Begin(), bytes);
			return true;
		}
	}
	
	return false;
}



NAMESPACE_PARALLEL_END
