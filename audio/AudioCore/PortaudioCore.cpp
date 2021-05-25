#include "AudioCore.h"


NAMESPACE_TOPSIDE_BEGIN;
namespace Portaudio {

extern "C"{
	//this is a C callable function, to wrap U++ Callback into PaStreamCallback
	int StreamCallback(const void *input, void *output, unsigned long frames,
	          const PaStreamCallbackTimeInfo *timeinfo, unsigned long flags, void *data)
	{
		StreamCallbackData *scd = static_cast<StreamCallbackData*>(data);
		StreamCallbackArgs sca(input, output, frames, timeinfo, flags,scd->data);
		scd->func(sca);
		return(sca.state);
	}

	//this is a C callable function, to wrap WhenFinish into PaStreamFinishedCallback
	void StreamFinishedCallback(void *data){
		StreamCallbackData *scd = static_cast<StreamCallbackData*>(data);
		scd->finish(scd->data);
	}
}











AudioBase::AudioBase() : err(paNoError), flags(SND_NOFLAG){
	fmt.freq = 44100;
	fmt.sample_rate = 1024;
	fmt.channels = 2;
	SetFormat(2, SND_FLOAT32);
	stream = 0;
	AudioSys();
}

void AudioBase::OpenStream(PaStreamCallback* cb, void* data,
                        const StreamParameters& inparam, const StreamParameters& outparam){
	ASSERT(AudioSystem::Exists());
	const PaStreamParameters* noparam=NULL;
	err = Pa_OpenStream(&stream, IsNull(inparam)?noparam:inparam, IsNull(outparam)?noparam:outparam,
	                    fmt.freq, fmt.sample_rate, flags, cb, data);
	CHECK_ERR;
	
	TODO // set fmt values from params
}

void AudioBase::OpenDefaultStream(PaStreamCallback* cb, void* data,
                               int inchannels,int outchannels, SampleFormat format) {
	ASSERT(AudioSystem::Exists());
	SetFormat(outchannels, format);
	err = Pa_OpenDefaultStream(&stream, inchannels, outchannels, format, fmt.freq, fmt.sample_rate, cb, data);
	CHECK_ERR;
}

void AudioBase::SetFormat(int out_ch, SampleFormat format) {
	fmt.channels = out_ch;
	fmt.fmt = format;
}

void AudioBase::Close(){
	if (IsOpen()) {
		err = Pa_CloseStream(stream);
		CHECK_ERR;
		stream = NULL;
	}
}


/*void AudioBase::Exchange(AudioEx& e) {
	TODO
}*/

/*
void AudioBase::Get(void* data, int size) {
	int vars = size / fmt.var_size;
	ASSERT(size % fmt.var_size == 0);
	int samples = vars / fmt.channels;
	ASSERT(vars % fmt.channels == 0);
	int frames = samples / fmt.sample_rate;
	ASSERT(samples % fmt.sample_rate == 0);
	total_frames += frames;
	err = Pa_ReadStream(stream, data, samples);
	CHECK_ERR;
}

void AudioBase::Put(void* data, int size, bool realtime) {
	int vars = size / fmt.var_size;
	ASSERT(size % fmt.var_size == 0);
	int samples = vars / fmt.channels;
	ASSERT(vars % fmt.channels == 0);
	int frames = samples / fmt.sample_rate;
	ASSERT(samples % fmt.sample_rate == 0);
	total_frames += frames;
	err = Pa_WriteStream(stream,data,samples);
	CHECK_ERR;
}
*/

bool AudioBase::IsStopped() const{
	int err = Pa_IsStreamStopped(stream);
	CHECK_ERR;
	return err;
}

bool AudioBase::IsActive() const{
	int err = Pa_IsStreamActive(stream);
	CHECK_ERR;
	return err;
}

double AudioBase::GetInputLatency() const{
	const PaStreamInfo *info = Pa_GetStreamInfo(stream);
	if (info != NULL) return info->inputLatency;
	else return 0;
}

double AudioBase::GetOutputLatency() const{
	const PaStreamInfo *info = Pa_GetStreamInfo(stream);
	if (info != NULL) return info->outputLatency;
	else return 0;
}

double AudioBase::GetFrequency() const{
	const PaStreamInfo *info = Pa_GetStreamInfo(stream);
	if (info != NULL) return info->sampleRate;
	else return 0;
}













void AudioDeviceStream::Open(void* data, const StreamParameters& inparam, const StreamParameters& outparam) {
	scallback = StreamCallbackData(WhenAction, WhenFinished, data);
	OpenStream(&StreamCallback, static_cast<void *>(&scallback), inparam, outparam);
	if (err == paNoError)
		SetFinishCallback();
}


void AudioDeviceStream::Open(const StreamParameters& inparam,const StreamParameters& outparam){
	Open(NULL, inparam, outparam);
}

void AudioDeviceStream::OpenDefault(void* data, int inchannels, int outchannels, SampleFormat format){
	scallback = StreamCallbackData(WhenAction, WhenFinished, data);
	OpenDefaultStream(&StreamCallback, static_cast<void *>(&scallback), inchannels, outchannels, format);
	if (err == paNoError)
		SetFinishCallback();
}


void AudioDeviceStream::OpenDefault(int inchannels, int outchannels, SampleFormat format){
	OpenDefault(NULL, inchannels, outchannels, format);
}

void AudioDeviceStream::SetFinishCallback(){
	err = Pa_SetStreamFinishedCallback(stream, &StreamFinishedCallback);
	CHECK_ERR;
}




}
NAMESPACE_TOPSIDE_END;

