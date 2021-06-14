#include "EcsLib.h"

NAMESPACE_TOPSIDE_BEGIN



DummySoundGeneratorAudio::DummySoundGeneratorAudio() {
	fmt.channels = 2;
	fmt.sample_rate = 777;
	fmt.freq = 44100;
	fmt.SetType(SoundSample::U8_LE);
	gen.GenerateStereoSine(fmt);
}

void DummySoundGeneratorAudio::StorePacket(AudioPacket& p) {
	int frame = fmt.GetFrameSize();
	dword off = p->GetOffset().value;
	int64 offset = (int64)off * (int64)frame;
	ASSERT(offset < (int64)std::numeric_limits<int>::max());
	double time = off * fmt.GetFrameSeconds();
	p->Set(fmt, time);
	p->Data().SetCount(frame, 0);
	gen.Play((int)offset, p);
}

/*void DummySoundGeneratorAudio::Exchange(AudioEx& e) {
	TODO
	if (e.IsStoring()) {
		Audio& sink = e.Sink();
		const RealtimeSourceConfig& conf = e.SourceConfig();
		
		AudioVolatileBuffer* vol_aud;
		SimpleBufferedAudio* buf_aud;
		if ((vol_aud = CastPtr<AudioVolatileBuffer>(&sink))) {
			while (!vol_aud->IsQueueFull()) {
				off32 offset = og.Create();
				AudioPacket p = CreateAudioPacket(offset);
				AudioPacketTracker::Track(TrackerInfo(this, __FILE__, __LINE__), p);
				p->Set(fmt, time);
				p->Data().SetCount(fmt.GetFrameSize(), 0);
				gen.Play(p);
				vol_aud->Put(p, false);
				time += fmt.GetFrameSeconds();
			}
		}
		else if ((buf_aud = CastPtr<SimpleBufferedAudio>(&sink))) {
			buf_aud->Exchange(e);
		}
		else TODO
	}
	else TODO
}

int DummySoundGeneratorAudio::GetQueueSize() const {
	return 10;
}

AudioFormat DummySoundGeneratorAudio::GetFormat() const {
	return fmt;
}

bool DummySoundGeneratorAudio::IsQueueFull() const {
	return true;
}*/














DummySoundGeneratorComponent::DummySoundGeneratorComponent() {
	
}

void DummySoundGeneratorComponent::Initialize() {
	Component::Initialize();
	//AddToContext<CenterSpec>(AsRef<CenterSource>());
	
	auto fmt = ScopeDevLibT<CenterSpec>::StageComponent::GetDefaultFormat<OrderSpec>();
	sink_value.SetFormat(fmt);
	
	GetStream(AUDCTX).Get().Lock();
}

void DummySoundGeneratorComponent::Uninitialize() {
	Component::Uninitialize();
	
	//RemoveFromContext<CenterSpec>(AsRef<CenterSource>());
}

void DummySoundGeneratorComponent::Forward(FwdScope& fwd) {
	using FromValSpec				= OrderSpec;
	using ToValSpec					= AudioSpec;
	using DevSpec					= CenterSpec;
	
	using DevMach					= ScopeDevMachT<DevSpec>;
	using InternalPacketData		= typename DevMach::InternalPacketData;
	
	using FromValDevSpec			= VD<DevSpec, FromValSpec>;
	using FromValMach				= ScopeValMachT<FromValSpec>;
	using FromValDevMach			= ScopeValDevMachT<FromValDevSpec>;
	using FromValDevCore			= ScopeValDevCoreT<FromValDevSpec>;
	using FromPacket				= typename FromValMach::Packet;
	using FromValue					= typename FromValDevMach::Value;
	using FromPacketBuffer			= typename FromValDevMach::PacketBuffer;
	using FromSimpleValue			= typename FromValDevMach::SimpleValue;
	using FromSimpleBufferedValue	= typename FromValDevMach::SimpleBufferedValue;
	using FromSink					= typename FromValDevCore::ValSink;
	#define FROMCTX (FromValSpec*)0
	
	using ToValDevSpec				= VD<DevSpec, ToValSpec>;
	using ToValMach					= ScopeValMachT<ToValSpec>;
	using ToValDevMach				= ScopeValDevMachT<ToValDevSpec>;
	using ToValDevCore				= ScopeValDevCoreT<ToValDevSpec>;
	using ToValLib					= ScopeValLibT<ToValSpec>;
	using ToPacket					= typename ToValMach::Packet;
	using ToFormat					= typename ToValMach::Format;
	using ToValue					= typename ToValDevMach::Value;
	using ToSimpleBufferedValue		= typename ToValDevMach::SimpleBufferedValue;
	using ToSimpleValue				= typename ToValDevMach::SimpleValue;
	using ToPacketBuffer			= typename ToValDevMach::PacketBuffer;
	using ToSource					= typename ToValDevCore::ValSource;
	using ToSink					= typename ToValDevCore::ValSink;
	using ToSinkRef					= typename ToValDevCore::ValSinkRef;
	using ToPacketTracker			= typename ToValLib::PacketTracker;
	#define TOCTX (ToValSpec*)0
	
	ToSource& iface_src = *this;
	FromSink& iface_sink = *this;
	FromValue& sink_val = iface_sink.GetValue(FROMCTX);
	
	FromSimpleBufferedValue* sink_buf_val;
	FromSimpleValue* sink_sval;
	FromPacketBuffer* sink_buf;
	if ((sink_buf_val = CastPtr<FromSimpleBufferedValue>(&sink_val))) {
		sink_buf = &sink_buf_val->GetBuffer();
	}
	else if ((sink_sval = CastPtr<FromSimpleValue>(&sink_val))) {
		sink_buf = &sink_sval->GetBuffer();
	}
	else TODO
	
	ToValue& val = iface_src.GetStream(TOCTX).Get();
	ToSimpleValue* sval;
	ToSimpleBufferedValue* sbcal;
	ToPacketBuffer* pbuf;
	if ((sval = CastPtr<ToSimpleValue>(&val))) {
		pbuf = &sval->GetBuffer();
	}
	else if ((sbcal = CastPtr<ToSimpleBufferedValue>(&val))) {
		pbuf = &sbcal->GetBuffer();
	}
	else TODO
	
	while (sink_buf->GetCount() && !val.IsQueueFull()) {
		FromPacket in = sink_buf->First();
		sink_buf->RemoveFirst();
		
		off32 off = in->GetOffset();
		RTLOG("DummySoundGeneratorComponent::Forward: play packet " << off.ToString());
		
		ToPacket to = ToValMach::CreatePacket(off);
		
		ToFormat fmt = ScopeDevLibT<DevSpec>::StageComponent::GetDefaultFormat<ToValSpec>();
		RTLOG("DummySoundGeneratorComponent::Forward: sending packet in format: " << fmt.ToString());
		to->SetFormat(fmt);
		
		InternalPacketData& data = to->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = 1;
		
		sval->StorePacket(to);
		
		ToPacketTracker::Track(TrackerInfo("DummySoundGeneratorComponent::Forward", __FILE__, __LINE__), *to);
		pbuf->Add(to);
	}
	
	#undef FROMCTX
	#undef TOCTX
}

void DummySoundGeneratorComponent::ForwardExchange(FwdScope& fwd) {
	AudioSource& src = *this;
	auto& conns = src.GetConnections();
	for(auto& link : conns) {
		ExchangePointRef expt = link.expt;
		ASSERT(expt);
		if (expt) {
			fwd.AddNext(*expt);
		}
	}
}

#if 0

void DummySoundGeneratorComponent::RecvMidi(const MidiFrame& e) {
	TODO
}

void DummySoundGeneratorComponent::Configure(const Midi::File& file) {
	if (mode == MODE_TRACK_NUM) {
		if (track_i >= 0 && track_i < file.GetTrackCount()) {
			Ref<FluidsynthSystem> fs_sys = GetMachine().Get<FluidsynthSystem>();
			fs_sys->Assign(file, track_i, this);
		}
	}
}

#endif

AudioStream& DummySoundGeneratorComponent::GetStream(AudCtx) {
	return gen;
}

void DummySoundGeneratorComponent::BeginStream(AudCtx) {
	TODO
}

void DummySoundGeneratorComponent::EndStream(AudCtx) {
	TODO
}











void DummyAudioSinkComponent::Forward(FwdScope& fwd) {
	using FromValSpec				= AudioSpec;
	using ToValSpec					= ReceiptSpec;
	using DevSpec					= CenterSpec;
	
	using DevMach					= ScopeDevMachT<DevSpec>;
	using InternalPacketData		= typename DevMach::InternalPacketData;
	
	using FromValDevSpec			= VD<DevSpec, FromValSpec>;
	using FromValMach				= ScopeValMachT<FromValSpec>;
	using FromValDevMach			= ScopeValDevMachT<FromValDevSpec>;
	using FromValDevCore			= ScopeValDevCoreT<FromValDevSpec>;
	using FromPacket				= typename FromValMach::Packet;
	
	using ToValDevSpec				= VD<DevSpec, ToValSpec>;
	using ToValMach					= ScopeValMachT<ToValSpec>;
	using ToValDevMach				= ScopeValDevMachT<ToValDevSpec>;
	using ToValDevCore				= ScopeValDevCoreT<ToValDevSpec>;
	using ToValLib					= ScopeValLibT<ToValSpec>;
	using ToPacket					= typename ToValMach::Packet;
	using ToFormat					= typename ToValMach::Format;
	using ToPacketTracker			= typename ToValLib::PacketTracker;
	
	Audio& sink_value = GetValue(AUDCTX);
	//Receipt& src_value = GetStream(RCPCTX).Get();
	auto& sink_buf = sink_value.GetBuffer();
	auto& src_buf = src_value.GetBuffer();
	
	while (sink_buf.GetCount() && !src_value.IsQueueFull()) {
		FromPacket in = sink_buf.First();
		sink_buf.RemoveFirst();
		
		Process(in);
		
		ToPacket to = ToValMach::CreatePacket(in->GetOffset());
		
		ToFormat fmt = ScopeDevLibT<DevSpec>::StageComponent::GetDefaultFormat<ToValSpec>();
		RTLOG("DummyAudioSinkComponent::Forward: sending packet in format: " << fmt.ToString());
		to->SetFormat(fmt);
		
		InternalPacketData& data = to->template SetData<InternalPacketData>();
		data.pos = 0;
		data.count = 1;
		
		src_value.StorePacket(to);
		
		ToPacketTracker::Track(TrackerInfo("DummySoundGeneratorComponent::Forward", __FILE__, __LINE__), *to);
		src_buf.Add(to);
	}
}

void DummyAudioSinkComponent::ForwardExchange(FwdScope& fwd) {
	ReceiptSource& src = *this;
	auto& conns = src.GetConnections();
	for(auto& link : conns) {
		ExchangePointRef expt = link.expt;
		ASSERT(expt);
		if (expt) {
			fwd.AddNext(*expt);
		}
	}
}

void DummyAudioSinkComponent::Process(AudioPacket& p) {
	RTLOG("DummyAudioSinkComponent::Process: omnomnomnomnom... packet " << p->GetOffset().ToString() << " content sunk in the sink hole");
}


NAMESPACE_TOPSIDE_END
