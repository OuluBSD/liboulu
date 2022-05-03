#include "IAudio.h"

#if (defined flagLINUX) || (defined flagFREEBSD) || (defined flagWIN32)
NAMESPACE_PARALLEL_BEGIN


#ifdef LOG_SOUND_ERRORS
  #define CHECK_ERROR(STREAM) if((STREAM).IsError()) LOG(__FILE__<<" (line "<<__LINE__<<"): "<<(STREAM).GetError());
#else
  #define CHECK_ERROR(STREAM)
#endif
#define CHECK_ERR CHECK_ERROR(*this)


enum SampleFormat {
	SND_FLOAT32				= paFloat32,
	SND_INT32				= paInt32,
	SND_INT24				= paInt24,
	SND_INT16				= paInt16,
	SND_INT8				= paInt8,
	SND_UINT8				= paUInt8,
	SND_UNKNOWN				= -1
};

enum PortaudioCallbackResult {
	SND_CONTINUE			= paContinue,
	SND_COMPLETE			= paComplete,
	SND_ABORT				= paAbort
};

struct PortaudioFormat {
	int				channels = 0;
	int				freq = 0;
	int				sample_rate = 0;
	SampleFormat	fmt = SND_UNKNOWN;
};

Format ConvertPortaudioFormat(PortaudioFormat pa_fmt) {
	Format fmt;
	fmt.vd = VD(CENTER,AUDIO);
	AudioFormat& r = fmt;
	r.res[0] = pa_fmt.channels;
	r.freq = pa_fmt.freq;
	r.sample_rate = pa_fmt.sample_rate;
	switch (pa_fmt.fmt) {
		#if CPU_BIG_ENDIAN
		#error TODO
		#endif
		
		case SND_FLOAT32:
			r.SetType(SoundSample::FLT_LE);
			break;
		case SND_INT32:
			r.SetType(SoundSample::S32_LE);
			break;
		case SND_INT24:
			r.SetType(SoundSample::S24_LE);
			break;
		case SND_INT16:
			r.SetType(SoundSample::S16_LE);
			break;
		case SND_INT8:
			r.SetType(SoundSample::S8_LE);
			break;
		case SND_UINT8:
			r.SetType(SoundSample::U8_LE);
			break;
		default:
			THROW(Exc("invalid portaudio sound sample format"));
	}
	return fmt;
}

struct PortaudioTimeInfo {
	double			input_adc;
	double			current;
	double			output_adc;
	
	PortaudioTimeInfo(	const PaStreamCallbackTimeInfo* timeinfo):
						input_adc(timeinfo->inputBufferAdcTime),
						output_adc(timeinfo->outputBufferDacTime),
						current(timeinfo->currentTime){}
	
	operator const PaStreamCallbackTimeInfo*(){
		return reinterpret_cast<const PaStreamCallbackTimeInfo*>(this);
	}
};

struct PortaudioCallbackArgs {
	const void*			input;
	void*				output;
	void*				data;
	int					state;
	unsigned long		fpb;
	PortaudioTimeInfo	timeinfo;
	unsigned long		flags;
	
	PortaudioCallbackArgs(const void *input, void *output, unsigned long fpb,
	                   PortaudioTimeInfo timeinfo, unsigned long flags,
	                   void* data) : input(input),output(output),fpb(fpb),timeinfo(timeinfo),
	                                 flags(flags),data(data),state(SND_CONTINUE){};
};

struct PortaudioCallbackData {
	Callback1<void*>					finish;
	void*								data;
	bool								dbg_async_race;
	PaStream*							dev;
	AtomBase*							atom;
	Serial::Format						fmt;
	
	void Set(PaStream* d, AtomBase* atom, Format fmt,
	         Callback1<void*> whenfinish, void* userdata) {
	    this->atom = atom;
	    this->fmt = fmt;
	    dev = d;
	    finish = whenfinish;
	    data = userdata;
	}
	
	void SinkCallback(PortaudioCallbackArgs& args) {
		if (!args.output) return;
		
		// This is remaining for old code. Probably useless here.
		#ifdef flagDEBUG
		ASSERT(!this->dbg_async_race);
		this->dbg_async_race = true;
		#endif
		
		
		Serial::AudioFormat& afmt = fmt;
		int size = fmt.GetFrameSize();
		if (!Serial_Link_ForwardAsyncMem(atom->GetLink(), (byte*)args.output, size)) {
			RTLOG("PortaudioCallbackData::SinkCallback: reading memory failed");
			memset(args.output, 0, size);
		}
		
		#ifdef flagDEBUG
		this->dbg_async_race = false;
		#endif
	}
	
};

extern "C"{
	//this is a C callable function, to wrap U++ Callback into PaStreamCallback
	int StreamCallback(const void *input, void *output, unsigned long frames,
	          const PaStreamCallbackTimeInfo *timeinfo, unsigned long flags, void *data)
	{
		PortaudioCallbackData *d = static_cast<PortaudioCallbackData*>(data);
		PortaudioCallbackArgs a(input, output, frames, timeinfo, flags, d->data);
		d->SinkCallback(a);
		return a.state;
	}

	//this is a C callable function, to wrap WhenFinish into PaStreamFinishedCallback
	void StreamFinishedCallback(void *data){
		PortaudioCallbackData *d = static_cast<PortaudioCallbackData*>(data);
		d->finish(d->data);
	}
	
}




// PortaudioStatic is used for wrapping static portaudio state for clean destructing

class PortaudioStatic {
	mutable int		err;
	static bool		exists;
	
	Array<PortaudioCallbackData> cb_data;
	
	
public:
	PortaudioStatic() {
		ASSERT_(!exists, "PortaudioStatic already instantiated!");
		err = Pa_Initialize();
		CHECK_ERR;
		exists = true;
	}
	
	~PortaudioStatic() {
		Clear();
	}
	
	void Clear() {
		if (exists) {
			err = Pa_Terminate();
			CHECK_ERR;
			exists = false;
		}
	}
	
	PortaudioCallbackData& Add() {
		return cb_data.Add();
	}
	
	void Remove(PaStream* s) {
		for(int i = 0; i < cb_data.GetCount(); i++)
			if (cb_data[i].dev == s)
				cb_data.Remove(i--);
	}
	
	static bool Exists() {return exists;}
	
};

bool PortaudioStatic::exists = false;

GLOBAL_VAR(PortaudioStatic, PaStatic);









bool AudPortaudio::SinkDevice_Initialize(NativeSinkDevice& dev, AtomBase& a, const Script::WorldState& ws) {
	// Housekeeping vars
	PaError err = paNoError;
	dev = 0;
	
	// Audio format
	PortaudioFormat pa_fmt;
	pa_fmt.freq = 44100;
	pa_fmt.sample_rate = 1024;
	pa_fmt.channels = 2;
	pa_fmt.fmt = SND_FLOAT32;
	int in_channels = 0;
	
	// Adjust sink format
	const int sink_ch_i = 0;
	Value& sink_val = a.GetSink()->GetValue(sink_ch_i);
	Format fmt = ConvertPortaudioFormat(pa_fmt);
	ASSERT(fmt.IsValid());
	sink_val.SetFormat(fmt);
	sink_val.LockFormat();
	
	// Initalize static portaudio instance (if not initialized)
	PaStatic();
	
	// Callbacks (currently unused)
	Callback1<void*> WhenFinished;
	
	// Add static callback data (could be elsewhere than in "PaStatic()". Improve.)
	PortaudioCallbackData& scallback = PaStatic().Add();
	scallback.Set(dev, &a, fmt, WhenFinished, NULL);
	
	// Make our's callback data for native audio sink callback
	PaStreamCallback* cb = &StreamCallback;
	void* data = static_cast<void *>(&scallback);
	
	// Call native stream opener
	ASSERT(PortaudioStatic::Exists());
	err = Pa_OpenDefaultStream(&dev, in_channels, pa_fmt.channels, pa_fmt.fmt, pa_fmt.freq, pa_fmt.sample_rate, cb, data);
	CHECK_ERR;
	if (err != paNoError) // Bail out on errors
		return false;
	
	// Configure native audio stream to have call our finish function on end of stream
	err = Pa_SetStreamFinishedCallback(dev, &StreamFinishedCallback);
	CHECK_ERR;
	if (err != paNoError) // Bail out on errors
		return false;
	
	
	a.GetSink()->GetValue(0).SetMinQueueSize(5);
	
	
	return true;
}

bool AudPortaudio::SinkDevice_PostInitialize(NativeSinkDevice& dev, AtomBase&) {
	return true;
}

bool AudPortaudio::SinkDevice_Start(NativeSinkDevice& dev, AtomBase&) {
	PaError err = paNoError;
	
	err = Pa_StartStream(dev);
	CHECK_ERR;
	if (err != paNoError) // Bail out on errors
		return false;
	
	ASSERT(!Pa_IsStreamStopped(dev));
	return true;
}

void AudPortaudio::SinkDevice_Stop(NativeSinkDevice& dev, AtomBase&) {
	PaError err = paNoError;
	err = Pa_StopStream(dev);
	CHECK_ERR;
}

void AudPortaudio::SinkDevice_Uninitialize(NativeSinkDevice& dev, AtomBase&) {
	PaError err = paNoError;
	
	err = Pa_CloseStream(dev);
	CHECK_ERR;
	
	PaStatic().Remove(dev);
}

bool AudPortaudio::SinkDevice_Send(NativeSinkDevice& dev, AtomBase&, PacketValue& out) {
	Panic("won't implement");
	NEVER();
}

bool AudPortaudio::SinkDevice_NegotiateSinkFormat(NativeSinkDevice& dev, AtomBase& a, Serial::Link& link, int sink_ch, const Format& new_fmt) {
	
	// Accept any audio format! Data is converted automatically for raw audio data!
	
	/*
	// accept all valid video formats for now
	if (new_fmt.IsValid() && new_fmt.IsAudio()) {
		ISinkRef sink = a.GetSink();
		Value& val = sink->GetValue(sink_ch);
		val.SetFormat(new_fmt);
		return true;
	}*/
	
	return false;
}

int AudPortaudio::SinkDevice_GetSinkDeviceCount() {
	TODO
}

bool AudPortaudio::SinkDevice_CreateSinkDevice(int sink_i, NativeSinkDevice& o) {
	TODO
}

void AudPortaudio::SinkDevice_ClearSinkDevice(NativeSinkDevice& o) {
	TODO
}

bool AudPortaudio::SinkDevice_SetSinkCallback(void* data, DataCallbackFn cb) {
	TODO
}

int AudPortaudio::SinkDevice_GetSinkFormatCount(NativeSinkDevice& o) {
	TODO
}

bool AudPortaudio::SinkDevice_GetSinkFormat(NativeSinkDevice& o, int ch_i, int& channels, int& samplerate, int& bytes, bool& is_signed, bool& is_float) {
	TODO
}






bool AudPortaudio::SourceDevice_Initialize(NativeSourceDevice& dev, AtomBase& a, const Script::WorldState& ws) {
	TODO
}

bool AudPortaudio::SourceDevice_Start(NativeSourceDevice& dev, AtomBase&) {
	TODO
}

void AudPortaudio::SourceDevice_Stop(NativeSourceDevice& dev, AtomBase&) {
	TODO
}

void AudPortaudio::SourceDevice_Uninitialize(NativeSourceDevice& dev, AtomBase&) {
	TODO
}

bool AudPortaudio::SourceDevice_Send(NativeSourceDevice& dev, AtomBase&, PacketValue& out) {
	TODO
}

bool AudPortaudio::SourceDevice_NegotiateSinkFormat(NativeSinkDevice& dev, AtomBase&, Serial::Link& link, int sink_ch, const Format& new_fmt) {
	TODO
}

int AudPortaudio::SourceDevice_GetSourceDeviceCount() {
	TODO
}

bool AudPortaudio::SourceDevice_CreateSourceDevice(int sink_i, NativeSourceDevice& o) {
	TODO
}

void AudPortaudio::SourceDevice_ClearSourceDevice(NativeSourceDevice& o) {
	TODO
}

bool AudPortaudio::SourceDevice_SetSourceCallback(void* data, DataCallbackFn cb) {
	TODO
}

int AudPortaudio::SourceDevice_GetSourceFormatCount(NativeSourceDevice& o) {
	TODO
}

bool AudPortaudio::SourceDevice_GetSourceFormat(NativeSourceDevice& o, int ch_i, int& channels, int& samplerate, int& bytes, bool& is_signed, bool& is_float) {
	TODO
}





NAMESPACE_PARALLEL_END
#endif

