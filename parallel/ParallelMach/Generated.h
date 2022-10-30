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
	ATOM_TYPE(AUDIO_DECODER_SRC) \
	ATOM_TYPE(AUDIO_DBG_SRC) \
	ATOM_TYPE(AUDIO_SPLITTER) \
	ATOM_TYPE(AUDIO_SPLITTER_USER) \
	ATOM_TYPE(AUDIO_JOINER) \
	ATOM_TYPE(AUDIO_JOINER_USER) \
	ATOM_TYPE(AUDIO_JOINER2_USER) \
	ATOM_TYPE(AUDIO_MIXER16) \
	ATOM_TYPE(VIDEO_DBG_SRC) \
	ATOM_TYPE(WEBCAM_PIPE) \
	ATOM_TYPE(WEBCAM_ATOM) \
	ATOM_TYPE(AUDIO_LOADER_ATOM) \
	ATOM_TYPE(VIDEO_LOADER_ATOM) \
	ATOM_TYPE(EVENT_STATE_PIPE) \
	ATOM_TYPE(ECS_PROG_VIDEO) \
	ATOM_TYPE(X11_SW_FBO_PROG) \
	ATOM_TYPE(X11_OGL_FBO_PROG) \
	ATOM_TYPE(SDL_OGL_FBO_PROG) \
	ATOM_TYPE(OPEN_HMDPIPE) \
	ATOM_TYPE(LOCAL_HMDPIPE) \
	ATOM_TYPE(REMOTE_VRSERVER_PIPE) \
	ATOM_TYPE(BLUETOOTH_HOLO_PIPE) \
	ATOM_TYPE(X11_SW_SHADER_PIPE) \
	ATOM_TYPE(X11_OGL_SHADER_PIPE) \
	ATOM_TYPE(SDL_OGL_SHADER_PIPE) \
	ATOM_TYPE(X11_SW_FBO_ATOM_PIPE) \
	ATOM_TYPE(X11_OGL_FBO_ATOM_PIPE) \
	ATOM_TYPE(SDL_OGL_FBO_ATOM_PIPE) \
	ATOM_TYPE(X11_CONTEXT_ATOM) \
	ATOM_TYPE(X11_SW_CONTEXT_ATOM) \
	ATOM_TYPE(X11_OGL_CONTEXT_ATOM) \
	ATOM_TYPE(X11_EVENT_ATOM_PIPE) \
	ATOM_TYPE(OGL_CUSTOMER) \
	ATOM_TYPE(SDL_CONTEXT_ATOM) \
	ATOM_TYPE(SDL_EVENT_ATOM_PIPE) \
	ATOM_TYPE(TEST_EVENT_SRC_PIPE) \
	ATOM_TYPE(SDL_OGL_IMAGE_LOADER) \
	ATOM_TYPE(VOLUME_LOADER_ATOM) \
	ATOM_TYPE(X11_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(X11_OGL_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(X11_OGL_FBO_ATOM_SA) \
	ATOM_TYPE(X11_SW_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(X11_SW_FBO_ATOM_SA) \
	ATOM_TYPE(SDL_OGL_FBO_ATOM_SA) \
	ATOM_TYPE(SDL_OGL_FBO_PIPE) \
	ATOM_TYPE(SDL_OGL_FBO_ATOM) \
	ATOM_TYPE(SDL_VIDEO_ATOM_PIPE) \
	ATOM_TYPE(SDL_PROG_ATOM_PIPE) \
	ATOM_TYPE(SDL_VIDEO_ATOM) \
	ATOM_TYPE(SDL_AUDIO_ATOM) \
	ATOM_TYPE(SDL_OGL_SHADER_ATOM) \
	ATOM_TYPE(SDL_OGL_SHADER_ATOM_SA) \
	ATOM_TYPE(SDL_OGL_TEXTURE_SOURCE) \
	ATOM_TYPE(SDL_OGL_VOLUME_SOURCE) \
	ATOM_TYPE(SDL_OGL_AUDIO_SINK) \
	ATOM_TYPE(SDL_OGL_KEYBOARD_SOURCE) \
	ATOM_TYPE(SDL_OGL_AUDIO_SOURCE) \
	ATOM_TYPE(MIDI_FILE_READER_PIPE) \
	ATOM_TYPE(MIDI_FILE_READER) \
	ATOM_TYPE(MIDI_FILE_READER16) \
	ATOM_TYPE(MIDI_NULL_SINK) \
	ATOM_TYPE(FLUIDSYNTH_PIPE) \
	ATOM_TYPE(SOFT_INSTRUMENT_PIPE) \
	ATOM_TYPE(FM_SYNTH_PIPE) \
	ATOM_TYPE(LV2_INSTRUMENT_PIPE) \
	ATOM_TYPE(CORE_SYNTH_PIPE) \
	ATOM_TYPE(CORE_DRUMMER_PIPE) \
	ATOM_TYPE(CORE_EFFECT_PIPE) \
	ATOM_TYPE(CORE_EFFECT_ATOM) \
	ATOM_TYPE(LV2_EFFECT_PIPE) \
	ATOM_TYPE(PORTMIDI_PIPE) \
	ATOM_TYPE(PORTMIDI_SEND) \
	ATOM_TYPE(CORE_AUDIO_FILE_OUT) \

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
	ATOM_CLASS(AudioMixer16) \
	ATOM_CLASS(VideoDbgSrc) \
	ATOM_CLASS(WebcamPipe) \
	ATOM_CLASS(WebcamAtom) \
	ATOM_CLASS(AudioLoaderAtom) \
	ATOM_CLASS(VideoLoaderAtom) \
	ATOM_CLASS(EventStatePipe) \
	ATOM_CLASS(EcsProgVideo) \
	ATOM_CLASS(X11SwFboProg) \
	ATOM_CLASS(X11OglFboProg) \
	ATOM_CLASS(SdlOglFboProg) \
	ATOM_CLASS(OpenHMDPipe) \
	ATOM_CLASS(LocalHMDPipe) \
	ATOM_CLASS(RemoteVRServerPipe) \
	ATOM_CLASS(BluetoothHoloPipe) \
	ATOM_CLASS(X11SwShaderPipe) \
	ATOM_CLASS(X11OglShaderPipe) \
	ATOM_CLASS(SdlOglShaderPipe) \
	ATOM_CLASS(X11SwFboAtomPipe) \
	ATOM_CLASS(X11OglFboAtomPipe) \
	ATOM_CLASS(SdlOglFboAtomPipe) \
	ATOM_CLASS(X11ContextAtom) \
	ATOM_CLASS(X11SwContextAtom) \
	ATOM_CLASS(X11OglContextAtom) \
	ATOM_CLASS(X11EventAtomPipe) \
	ATOM_CLASS(OglCustomer) \
	ATOM_CLASS(SdlContextAtom) \
	ATOM_CLASS(SdlEventAtomPipe) \
	ATOM_CLASS(TestEventSrcPipe) \
	ATOM_CLASS(SdlOglImageLoader) \
	ATOM_CLASS(VolumeLoaderAtom) \
	ATOM_CLASS(X11VideoAtomPipe) \
	ATOM_CLASS(X11OglVideoAtomPipe) \
	ATOM_CLASS(X11OglFboAtomSA) \
	ATOM_CLASS(X11SwVideoAtomPipe) \
	ATOM_CLASS(X11SwFboAtomSA) \
	ATOM_CLASS(SdlOglFboAtomSA) \
	ATOM_CLASS(SdlOglFboPipe) \
	ATOM_CLASS(SdlOglFboAtom) \
	ATOM_CLASS(SdlVideoAtomPipe) \
	ATOM_CLASS(SdlProgAtomPipe) \
	ATOM_CLASS(SdlVideoAtom) \
	ATOM_CLASS(SdlAudioAtom) \
	ATOM_CLASS(SdlOglShaderAtom) \
	ATOM_CLASS(SdlOglShaderAtomSA) \
	ATOM_CLASS(SdlOglTextureSource) \
	ATOM_CLASS(SdlOglVolumeSource) \
	ATOM_CLASS(SdlOglAudioSink) \
	ATOM_CLASS(SdlOglKeyboardSource) \
	ATOM_CLASS(SdlOglAudioSource) \
	ATOM_CLASS(MidiFileReaderPipe) \
	ATOM_CLASS(MidiFileReader) \
	ATOM_CLASS(MidiFileReader16) \
	ATOM_CLASS(MidiNullSink) \
	ATOM_CLASS(FluidsynthPipe) \
	ATOM_CLASS(SoftInstrumentPipe) \
	ATOM_CLASS(FmSynthPipe) \
	ATOM_CLASS(LV2InstrumentPipe) \
	ATOM_CLASS(CoreSynthPipe) \
	ATOM_CLASS(CoreDrummerPipe) \
	ATOM_CLASS(CoreEffectPipe) \
	ATOM_CLASS(CoreEffectAtom) \
	ATOM_CLASS(LV2EffectPipe) \
	ATOM_CLASS(PortmidiPipe) \
	ATOM_CLASS(PortmidiSend) \
	ATOM_CLASS(CoreAudioFileOut) \

}}

#endif
