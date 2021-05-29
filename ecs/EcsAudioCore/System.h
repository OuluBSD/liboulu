#ifndef _AudioCore_System_h_
#define _AudioCore_System_h_


NAMESPACE_TOPSIDE_BEGIN


class MixerContextComponent :
	public Component<MixerContextComponent>
{
	String last_error;
	String post_load_file_path;
	
public:
	RTTI_COMP0(MixerContextComponent)
	VIS_COMP_0_0
	COPY_PANIC(MixerContextComponent);
	
	MixerContextComponent();
	
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {}
	void PostLoadFileAny(String path) {post_load_file_path = path;}
	
	String GetLastError() const {return last_error;}
	
	
	Callback WhenError;
	
};


class MixerChannelContextComponent :
	public Component<MixerChannelContextComponent>
{
	String last_error;
	
public:
	RTTI_COMP0(MixerChannelContextComponent)
	VIS_COMP_0_0
	COPY_PANIC(MixerChannelContextComponent);
	
	MixerChannelContextComponent();
	
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {}
	
	String GetLastError() const {return last_error;}
	
};


class MixerChannelInputComponent :
	public Component<MixerChannelInputComponent>,
	public AudioSource,
	public AudioSink
{
	String last_error;
	
public:
	RTTI_COMP2(MixerChannelInputComponent, AudioSource, AudioSink)
	VIS_COMP_1_1(Audio, Audio)
	COPY_PANIC(MixerChannelInputComponent);
	IFACE_CB(AudioSink);
	IFACE_CB(AudioSource);
	IFACE_GENERIC;
	
	MixerChannelInputComponent();
	
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {}
	//const AudioHeader& GetHeader() const override;
	
	// AudioSource
	AudioStream&	GetStream(AudCtx) override {TODO}
	void				BeginStream(AudCtx) override {TODO}
	void				EndStream(AudCtx) override {TODO}
	
	// AudioSink
	AudioFormat	GetFormat(AudCtx) override {TODO}
	Audio&		GetValue(AudCtx) override {TODO}
	
	String GetLastError() const {return last_error;}
	
};

class MixerChannelOutputComponent :
	public Component<MixerChannelOutputComponent>,
	public AudioSource,
	public AudioSink
{
	String last_error;
	
public:
	RTTI_COMP2(MixerChannelOutputComponent, AudioSource, AudioSink)
	VIS_COMP_1_1(Audio, Audio)
	COPY_PANIC(MixerChannelOutputComponent);
	IFACE_CB(AudioSink);
	IFACE_CB(AudioSource);
	IFACE_GENERIC;
	
	MixerChannelOutputComponent();
	
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {}
	//const AudioHeader& GetHeader() const override;
	
	// AudioSource
	AudioStream&	GetStream(AudCtx) override;
	void				BeginStream(AudCtx) override;
	void				EndStream(AudCtx) override;
	
	// AudioSink
	AudioFormat	GetFormat(AudCtx) override;
	Audio&		GetValue(AudCtx) override;
	
	String GetLastError() const {return last_error;}
	
};


class MixerAudioSourceComponent :
	public Component<MixerAudioSourceComponent>,
	public AudioSource,
	public AudioSink
{
	String last_error;
	
public:
	RTTI_COMP2(MixerAudioSourceComponent, AudioSource, AudioSink)
	VIS_COMP_1_1(Audio, Audio)
	COPY_PANIC(MixerAudioSourceComponent);
	IFACE_CB(AudioSink);
	IFACE_CB(AudioSource);
	IFACE_GENERIC;
	
	MixerAudioSourceComponent();
	
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {}
	
	// AudioSource
	AudioStream&		GetStream(AudCtx) override;
	void				BeginStream(AudCtx) override;
	void				EndStream(AudCtx) override;
	
	// AudioSink
	AudioFormat	GetFormat(AudCtx) override;
	Audio&		GetValue(AudCtx) override;
	
	String GetLastError() const {return last_error;}
	
};




class MidiFileComponent :
	public Component<MidiFileComponent>,
	public DeviceSource
{
	String last_error;
	MidiIO::File file;
	Vector<int> track_i;
	double song_dt = 0;
	MidiFrame tmp;
	
public:
	RTTI_COMP1(MidiFileComponent, DeviceSource)
	VIS_COMP_1_0(Device)
	COPY_PANIC(MidiFileComponent);
	IFACE_CB(DeviceSource);
	IFACE_GENERIC;
	
	MidiFileComponent();
	
	void Initialize() override;
	void Uninitialize() override;
	//void EmitMidi(double dt) override;
	//bool IsSupported(DevType type) override {return true;}
	void OnLink(SinkProv sink, Cookie src_c, Cookie sink_c) override {TODO}
	void Visit(RuntimeVisitor& vis) override {}
	bool OpenFilePath(String path);
	void Clear();
	void CollectTrackEvents(int i);
	void EmitTrack(int i);
	void DumpMidiFile();
	
	// DeviceSource
	DeviceStream&		GetStream(DevCtx) override {TODO}
	void				BeginStream(DevCtx) override {TODO}
	void				EndStream(DevCtx) override {TODO}
	
	String GetLastError() const {return last_error;}
	
	
	Callback WhenError;
	
};





PREFAB_BEGIN(CompleteMixer)
		MixerContextComponent
PREFAB_END;

PREFAB_BEGIN(CompleteMixerChannel)
		MixerChannelContextComponent,
		MixerChannelInputComponent,
		MixerChannelOutputComponent
PREFAB_END;

PREFAB_BEGIN(CompleteMixerOutput)
		MixerChannelContextComponent,
		MixerChannelInputComponent,
		MixerAudioSourceComponent
PREFAB_END;

PREFAB_BEGIN(MidiFileController)
		MidiFileComponent
PREFAB_END;

NAMESPACE_TOPSIDE_END


#endif