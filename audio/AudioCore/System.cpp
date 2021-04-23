#include "System.h"


NAMESPACE_OULU_BEGIN








MixerContextComponent::MixerContextComponent() {
	
}

void MixerContextComponent::Initialize() {
	
}

void MixerContextComponent::Uninitialize() {
	
}



MixerChannelContextComponent::MixerChannelContextComponent() {
	
}

void MixerChannelContextComponent::Initialize() {
	
}

void MixerChannelContextComponent::Uninitialize() {
	
}



MixerChannelInputComponent::MixerChannelInputComponent() {
	
}

void MixerChannelInputComponent::Initialize() {
	
}

void MixerChannelInputComponent::Uninitialize() {
	
}

const FusionComponentInput& MixerChannelInputComponent::GetHeader() const {
	TODO
}



MixerChannelOutputComponent::MixerChannelOutputComponent() {
	
}

void MixerChannelOutputComponent::Initialize() {
	
}

void MixerChannelOutputComponent::Uninitialize() {
	
}

const FusionComponentInput& MixerChannelOutputComponent::GetHeader() const {
	TODO
}



MixerAudioSourceComponent::MixerAudioSourceComponent() {
	
}

void MixerAudioSourceComponent::Initialize() {
	
}

void MixerAudioSourceComponent::Uninitialize() {
	
}

void MixerAudioSourceComponent::EmitAudioSource(float dt) {
	
}

void MixerAudioSourceComponent::Play(const AudioSinkConfig& config, Sound& snd) {
	
}



MidiFileComponent::MidiFileComponent() {
	MidiSource::SetMultiConnection();
	
}

void MidiFileComponent::Initialize() {
	Ref<EventSystem> es = GetEntity().GetMachine().TryGet<EventSystem>();
	if (es)
		es->AddMidi(*this);
}

void MidiFileComponent::Uninitialize() {
	Ref<EventSystem> es = GetEntity().GetMachine().TryGet<EventSystem>();
	if (es)
		es->RemoveMidi(*this);
}

void MidiFileComponent::Clear() {
	last_error.Clear();
	song_dt = -1;
	track_i.SetCount(0);
}

bool MidiFileComponent::OpenFilePath(String path) {
	Clear();
	
	if (!FileExists(path)) {
		last_error = "file does not exist: " + path;
		return false;
	}
	
	if (!file.Open(path)) {
		last_error = file.GetLastError();
		return false;
	}
	
	file.DoTimeAnalysis();
	file.LinkNotePairs();
	
	track_i.SetCount(file.GetTrackCount(), 0);
	
	// DumpMidiFile();
	
	return true;
}

void MidiFileComponent::DumpMidiFile() {
	int track_count = file.GetTrackCount();
	LOG("TPQ: " << file.GetTicksPerQuarterNote());
	if (track_count > 1) {
		LOG("TRACKS: " << track_count);
	}
	for (int track = 0; track < track_count; track++) {
		if (track_count > 1) {
			LOG("\nTrack " << track);
		}
		LOG("Tick\tSeconds\tDur\tMessage");
		const auto& t = file[track];
		for (int event = 0; event < t.GetCount(); event++) {
			const auto& e = t[event];
			LOG(IntStr(e.tick));
			LOG("\t" << DblStr(e.seconds));
			String s = "\t";
			if (e.IsNoteOn()) {
				s << DblStr(e.GetDurationInSeconds());
			}
			for (int i = 0; i < e.GetCount(); i++)
				s << "\t" << IntStr(e[i]);
			LOG(s);
		}
	}
}

void MidiFileComponent::EmitMidi(float dt) {
	
	// The first update is often laggy, so wait until the second one
	if (song_dt < 0) {
		song_dt = 0;
		return;
	}
	
	song_dt += dt;
	//LOG("midi song dt: " << song_dt);
	
	tmp.midi.Reserve(1000);
	
	for(int i = 0; i < file.GetTrackCount(); i++) {
		CollectTrackEvents(i);
		EmitTrack(i);
	}
	
}

State* MidiFileComponent::OnLink(InterfaceBase* iface) {
	ComponentBase* comp = iface->AsComponentBase();
	ASSERT(comp);
	MidiSink* sink = comp->AsMidiSink();
	ASSERT(sink);
	sink->Configure(file);
	return NULL;
}

void MidiFileComponent::CollectTrackEvents(int i) {
	if (i >= track_i.GetCount())
		track_i.SetCount(i+1,0);
	
	int& iter = track_i[i];
	const auto& t = file[i];
	
	tmp.Reset();
	while (iter < t.GetCount()) {
		const auto& e = t[iter];
		if (e.seconds <= song_dt) {
			iter++;
			tmp.midi.Add(&e);
		}
		else break;
	}
}

void MidiFileComponent::EmitTrack(int i) {
	if (tmp.midi.IsEmpty())
		return;
	
	//for(const Midi::Event* ev : tmp.midi) {LOG("track " << i << ": " << ev->ToString());}
	
	for (const auto& c : MidiSource::GetSinks())
		if (c.sink->AcceptsTrack(i))
			c.sink->RecvMidi(tmp);
	
}



NAMESPACE_OULU_END
