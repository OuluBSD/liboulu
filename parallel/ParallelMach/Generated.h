#ifndef _ParallelMach_Generated_h_
#define _ParallelMach_Generated_h_

// This file is generated. Do not modify this file.
// Last modified: 2022.4.6 12:22:22

namespace TS {

namespace Parallel {

#define ATOM_TYPE_LIST \
	ATOM_TYPE(CENTER_CUSTOMER) \
	ATOM_TYPE(TEST_REALTIME_SRC) \
	ATOM_TYPE(TEST_REALTIME_SINK) \
	ATOM_TYPE(TEST_POLLER_SINK) \
	ATOM_TYPE(PORTAUDIO_SINK) \
	ATOM_TYPE(AUDIO_DECODER_SRC) \
	ATOM_TYPE(AUDIO_DBG_SRC) \
	ATOM_TYPE(AUDIO_SPLITTER) \
	ATOM_TYPE(AUDIO_SPLITTER_USER) \
	ATOM_TYPE(AUDIO_JOINER) \
	ATOM_TYPE(AUDIO_JOINER_USER) \
	ATOM_TYPE(AUDIO_JOINER2_USER) \
	ATOM_TYPE(EVENT_STATE_PIPE) \
	ATOM_TYPE(SDL_EVENT_ATOM_PIPE) \
	ATOM_TYPE(SDL_EVENT_ATOM) \
	ATOM_TYPE(EVENT_STATE) \
	ATOM_TYPE(TEST_EVENT_SRC_PIPE) \


#define ATOM_CLASS_LIST \
	ATOM_CLASS(CenterCustomer) \
	ATOM_CLASS(TestRealtimeSrc) \
	ATOM_CLASS(TestRealtimeSink) \
	ATOM_CLASS(TestPollerSink) \
	ATOM_CLASS(PortaudioSink) \
	ATOM_CLASS(AudioDecoderSrc) \
	ATOM_CLASS(AudioDbgSrc) \
	ATOM_CLASS(AudioSplitter) \
	ATOM_CLASS(AudioSplitterUser) \
	ATOM_CLASS(AudioJoiner) \
	ATOM_CLASS(AudioJoinerUser) \
	ATOM_CLASS(AudioJoiner2User) \
	ATOM_CLASS(EventStatePipe) \
	ATOM_CLASS(SdlEventAtomPipe) \
	ATOM_CLASS(SdlEventAtom) \
	ATOM_CLASS(EventState) \
	ATOM_CLASS(TestEventSrcPipe) \


#define flagSCREEN_ATOM_TYPE_LIST \
	ATOM_TYPE(VIDEO_DBG_SRC) \
	ATOM_TYPE(AUDIO_LOADER_ATOM) \
	ATOM_TYPE(VIDEO_LOADER_ATOM) \
	ATOM_TYPE(ECS_EVENTS_ATOM) \
	ATOM_TYPE(ECS_CPU_VIDEO_PIPE) \
	ATOM_TYPE(ECS_PROG_VIDEO) \
	ATOM_TYPE(ECS_OGL_FBO_PIPE) \
	ATOM_TYPE(ECS_CPU_VIDEO) \
	ATOM_TYPE(ECS_OGL_FBO) \
	ATOM_TYPE(OGL_CUSTOMER) \
	ATOM_TYPE(SDL_IMAGE_LOADER) \
	ATOM_TYPE(VOLUME_LOADER_ATOM) \
	ATOM_TYPE(SDL_FBO_ATOM_S_A) \
	ATOM_TYPE(SDL_FBO_PIPE) \
	ATOM_TYPE(SDL_FBO_PIPE_SIDE) \
	ATOM_TYPE(SDL_FBO_ATOM) \
	ATOM_TYPE(SDL_VIDEO_PROG_ATOM) \
	ATOM_TYPE(SDL_VIDEO_ATOM_S_A) \
	ATOM_TYPE(OGL_SHADER_PIPE) \
	ATOM_TYPE(OGL_SHADER_ATOM) \
	ATOM_TYPE(OGL_SHADER_ATOM_S_A) \
	ATOM_TYPE(OGL_TEXTURE_SOURCE) \
	ATOM_TYPE(OGL_VOLUME_SOURCE) \
	ATOM_TYPE(OGL_AUDIO_SINK) \
	ATOM_TYPE(OGL_KEYBOARD_SOURCE) \
	ATOM_TYPE(OGL_AUDIO_SOURCE) \
	ATOM_TYPE(CPU_KEYBOARD_SOURCE) \


#define flagSCREEN_ATOM_CLASS_LIST \
	ATOM_CLASS(VideoDbgSrc) \
	ATOM_CLASS(AudioLoaderAtom) \
	ATOM_CLASS(VideoLoaderAtom) \
	ATOM_CLASS(EcsEventsAtom) \
	ATOM_CLASS(EcsCpuVideoPipe) \
	ATOM_CLASS(EcsProgVideo) \
	ATOM_CLASS(EcsOglFboPipe) \
	ATOM_CLASS(EcsCpuVideo) \
	ATOM_CLASS(EcsOglFbo) \
	ATOM_CLASS(OglCustomer) \
	ATOM_CLASS(SdlImageLoader) \
	ATOM_CLASS(VolumeLoaderAtom) \
	ATOM_CLASS(SdlFboAtomSA) \
	ATOM_CLASS(SdlFboPipe) \
	ATOM_CLASS(SdlFboPipeSide) \
	ATOM_CLASS(SdlFboAtom) \
	ATOM_CLASS(SdlVideoProgAtom) \
	ATOM_CLASS(SdlVideoAtomSA) \
	ATOM_CLASS(OglShaderPipe) \
	ATOM_CLASS(OglShaderAtom) \
	ATOM_CLASS(OglShaderAtomSA) \
	ATOM_CLASS(OglTextureSource) \
	ATOM_CLASS(OglVolumeSource) \
	ATOM_CLASS(OglAudioSink) \
	ATOM_CLASS(OglKeyboardSource) \
	ATOM_CLASS(OglAudioSource) \
	ATOM_CLASS(CpuKeyboardSource) \


#define HAVE_OPENCV_ATOM_TYPE_LIST \
	ATOM_TYPE(WEBCAM_PIPE) \
	ATOM_TYPE(WEBCAM_ATOM) \


#define HAVE_OPENCV_ATOM_CLASS_LIST \
	ATOM_CLASS(WebcamPipe) \
	ATOM_CLASS(WebcamAtom) \


#define flagSDL2_ATOM_TYPE_LIST \
	ATOM_TYPE(SDL_CONTEXT_ATOM) \
	ATOM_TYPE(SDL_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(SDL_VIDEO_ATOM) \
	ATOM_TYPE(SDL_AUDIO_ATOM) \


#define flagSDL2_ATOM_CLASS_LIST \
	ATOM_CLASS(SdlContextAtom) \
	ATOM_CLASS(SdlVideoAtomPipe) \
	ATOM_CLASS(SdlVideoAtom) \
	ATOM_CLASS(SdlAudioAtom) \


#define flagPOSIX_ATOM_TYPE_LIST \
	ATOM_TYPE(X11_VIDEO_ATOM_PIPE) \


#define flagPOSIX_ATOM_CLASS_LIST \
	ATOM_CLASS(X11VideoAtomPipe) \


}

}



#endif
