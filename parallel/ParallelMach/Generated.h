#ifndef _ParallelMach_Generated_h_
#define _ParallelMach_Generated_h_

// This file is generated. Do not modify this file.

namespace TS {

namespace Parallel {

#define ATOM_TYPE_LIST \
	ATOM_TYPE(CENTER_CUSTOMER) \
	ATOM_TYPE(TEST_REALTIME_SRC) \
	ATOM_TYPE(TEST_REALTIME_SINK) \
	ATOM_TYPE(TEST_POLLER_SINK) \
	ATOM_TYPE(PORTAUDIO_SINK) \
	ATOM_TYPE(AUDIO_DBG_SRC) \
	ATOM_TYPE(AUDIO_SPLITTER) \
	ATOM_TYPE(AUDIO_SPLITTER_USER) \
	ATOM_TYPE(AUDIO_JOINER) \
	ATOM_TYPE(AUDIO_JOINER_USER) \
	ATOM_TYPE(AUDIO_JOINER2_USER) \
	ATOM_TYPE(SDL_EVENT_ATOM) \
	ATOM_TYPE(EVENT_STATE) \
	ATOM_TYPE(TEST_EVENT_SRC_PIPE) \
	ATOM_TYPE(VOLUME_LOADER_ATOM) \


#define ATOM_CLASS_LIST \
	ATOM_CLASS(CenterCustomer) \
	ATOM_CLASS(TestRealtimeSrc) \
	ATOM_CLASS(TestRealtimeSink) \
	ATOM_CLASS(TestPollerSink) \
	ATOM_CLASS(PortaudioSink) \
	ATOM_CLASS(AudioDbgSrc) \
	ATOM_CLASS(AudioSplitter) \
	ATOM_CLASS(AudioSplitterUser) \
	ATOM_CLASS(AudioJoiner) \
	ATOM_CLASS(AudioJoinerUser) \
	ATOM_CLASS(AudioJoiner2User) \
	ATOM_CLASS(SdlEventAtom) \
	ATOM_CLASS(EventState) \
	ATOM_CLASS(TestEventSrcPipe) \
	ATOM_CLASS(VolumeLoaderAtom) \


#define flagFFMPEG_ATOM_TYPE_LIST \
	ATOM_TYPE(AUDIO_DECODER_SRC) \
	ATOM_TYPE(AUDIO_LOADER_ATOM) \
	ATOM_TYPE(VIDEO_LOADER_ATOM) \


#define flagFFMPEG_ATOM_CLASS_LIST \
	ATOM_CLASS(AudioDecoderSrc) \
	ATOM_CLASS(AudioLoaderAtom) \
	ATOM_CLASS(VideoLoaderAtom) \


#define flagSCREEN_ATOM_TYPE_LIST \
	ATOM_TYPE(VIDEO_DBG_SRC) \
	ATOM_TYPE(EVENT_STATE_PIPE) \
	ATOM_TYPE(ECS_EVENTS_ATOM) \
	ATOM_TYPE(ECS_CPU_VIDEO_PIPE) \
	ATOM_TYPE(ECS_PROG_VIDEO) \
	ATOM_TYPE(ECS_OGL_FBO_PIPE) \
	ATOM_TYPE(ECS_CPU_VIDEO) \
	ATOM_TYPE(ECS_OGL_FBO) \
	ATOM_TYPE(X11_SW_FBO_PROG) \
	ATOM_TYPE(X11_SW_SHADER_PIPE) \
	ATOM_TYPE(X11_SW_FBO_ATOM_PIPE) \
	ATOM_TYPE(OGL_CUSTOMER) \
	ATOM_TYPE(X11_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(X11_SW_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(X11_SW_FBO_ATOM_S_A) \
	ATOM_TYPE(SDL_OGL_FBO_PIPE_SIDE) \
	ATOM_TYPE(SDL_VIDEO_PROG_ATOM) \
	ATOM_TYPE(SDL_VIDEO_ATOM_S_A) \
	ATOM_TYPE(OGL_VOLUME_SOURCE) \
	ATOM_TYPE(OGL_KEYBOARD_SOURCE) \
	ATOM_TYPE(CPU_KEYBOARD_SOURCE) \


#define flagSCREEN_ATOM_CLASS_LIST \
	ATOM_CLASS(VideoDbgSrc) \
	ATOM_CLASS(EventStatePipe) \
	ATOM_CLASS(EcsEventsAtom) \
	ATOM_CLASS(EcsCpuVideoPipe) \
	ATOM_CLASS(EcsProgVideo) \
	ATOM_CLASS(EcsOglFboPipe) \
	ATOM_CLASS(EcsCpuVideo) \
	ATOM_CLASS(EcsOglFbo) \
	ATOM_CLASS(X11SwFboProg) \
	ATOM_CLASS(X11SwShaderPipe) \
	ATOM_CLASS(X11SwFboAtomPipe) \
	ATOM_CLASS(OglCustomer) \
	ATOM_CLASS(X11VideoAtomPipe) \
	ATOM_CLASS(X11SwVideoAtomPipe) \
	ATOM_CLASS(X11SwFboAtomSA) \
	ATOM_CLASS(SdlOglFboPipeSide) \
	ATOM_CLASS(SdlVideoProgAtom) \
	ATOM_CLASS(SdlVideoAtomSA) \
	ATOM_CLASS(OglVolumeSource) \
	ATOM_CLASS(OglKeyboardSource) \
	ATOM_CLASS(CpuKeyboardSource) \


#define flagOPENCV_ATOM_TYPE_LIST \


#define flagOPENCV_ATOM_CLASS_LIST \


#define flagLINUX_ATOM_TYPE_LIST \
	ATOM_TYPE(WEBCAM_PIPE) \
	ATOM_TYPE(WEBCAM_ATOM) \


#define flagLINUX_ATOM_CLASS_LIST \
	ATOM_CLASS(WebcamPipe) \
	ATOM_CLASS(WebcamAtom) \


#define flagOGL_ATOM_TYPE_LIST \
	ATOM_TYPE(X11_OGL_FBO_PROG) \
	ATOM_TYPE(X11_OGL_SHADER_PIPE) \
	ATOM_TYPE(X11_OGL_FBO_ATOM_PIPE) \
	ATOM_TYPE(X11_OGL_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(X11_OGL_FBO_ATOM_S_A) \
	ATOM_TYPE(SDL_OGL_FBO_ATOM_S_A) \
	ATOM_TYPE(SDL_OGL_FBO_PIPE) \
	ATOM_TYPE(SDL_OGL_FBO_ATOM) \
	ATOM_TYPE(SDL_OGL_TEXTURE_SOURCE) \
	ATOM_TYPE(SDL_OGL_AUDIO_SINK) \


#define flagOGL_ATOM_CLASS_LIST \
	ATOM_CLASS(X11OglFboProg) \
	ATOM_CLASS(X11OglShaderPipe) \
	ATOM_CLASS(X11OglFboAtomPipe) \
	ATOM_CLASS(X11OglVideoAtomPipe) \
	ATOM_CLASS(X11OglFboAtomSA) \
	ATOM_CLASS(SdlOglFboAtomSA) \
	ATOM_CLASS(SdlOglFboPipe) \
	ATOM_CLASS(SdlOglFboAtom) \
	ATOM_CLASS(SdlOglTextureSource) \
	ATOM_CLASS(SdlOglAudioSink) \


#define flagSDL2_ATOM_TYPE_LIST \
	ATOM_TYPE(SDL_OGL_SHADER_PROG) \
	ATOM_TYPE(SDL_OGL_SHADER_PIPE) \
	ATOM_TYPE(SDL_OGL_FBO_ATOM_PIPE) \
	ATOM_TYPE(SDL_CONTEXT_ATOM) \
	ATOM_TYPE(SDL_EVENT_ATOM_PIPE) \
	ATOM_TYPE(SDL_IMAGE_LOADER) \
	ATOM_TYPE(SDL_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(SDL_VIDEO_ATOM) \
	ATOM_TYPE(SDL_AUDIO_ATOM) \
	ATOM_TYPE(SDL_OGL_SHADER_ATOM) \
	ATOM_TYPE(SDL_OGL_SHADER_ATOM_S_A) \
	ATOM_TYPE(SDL_OGL_AUDIO_SOURCE) \


#define flagSDL2_ATOM_CLASS_LIST \
	ATOM_CLASS(SdlOglShaderProg) \
	ATOM_CLASS(SdlOglShaderPipe) \
	ATOM_CLASS(SdlOglFboAtomPipe) \
	ATOM_CLASS(SdlContextAtom) \
	ATOM_CLASS(SdlEventAtomPipe) \
	ATOM_CLASS(SdlImageLoader) \
	ATOM_CLASS(SdlVideoAtomPipe) \
	ATOM_CLASS(SdlVideoAtom) \
	ATOM_CLASS(SdlAudioAtom) \
	ATOM_CLASS(SdlOglShaderAtom) \
	ATOM_CLASS(SdlOglShaderAtomSA) \
	ATOM_CLASS(SdlOglAudioSource) \


}

}



#endif
