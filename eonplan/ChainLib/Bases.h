
BASE(CustomerBase)
BASE_ACTION(CustomerBase,			loop.connected)

BASE(RollingValueBase)
BASE(VoidSinkBase)
BASE(VoidPollerSinkBase)
BASE(PortaudioSinkDevice)
BASE(Sdl2AudioSinkDevice)
BASE(FfmpegSourceDevice)
BASE(AudioGenBase)
BASE(VoidBase)
BASE(VideoGenBase)
BASE(OpenCVBase)
BASE(OglVideoGenBase)
BASE(Sdl2ContextBase)
BASE(Sdl2EventsBase)
BASE(Sdl2OglVideoSinkDevice)
BASE(Sdl2CenterVideoSinkDevice)
BASE(SDL2ImageBase)
BASE(SdlOglFboBase)
BASE(EventStateBase)
BASE(TestEventSrcBase)
BASE(OglTextureBase)
BASE(OglFboReaderBase)
BASE(VideoLoaderBase)
BASE(VolumeLoaderBase)
BASE(CpuKeyboardBase)
BASE(OglKeyboardBase)
BASE(OglAudioBase)
BASE(EcsEventsBase)
BASE(EcsVideoBase)
BASE(X11SinkDevice)
BASE(X11OglSinkDevice)
BASE(X11SwSinkDevice)
BASE(X11SwFboBase)
BASE(X11OglFboBase)

BASE(X11SwShaderBase)
BASE(X11OglShaderBase)
BASE(SdlOglShaderBase)
//BASE(EcsOglBase)

//BASE_FLAG(SDL2ContextBase,			forward)
//BASE_ACTION(CenterSinkSync,			center.audio.sink)
//BASE2(ReceiptOrder,				CenterReceipt,	CenterOrder)
//BASE3(CenterOglMidiSink,		OglOrder,		SinkCenterMidi,		OglMidi)
