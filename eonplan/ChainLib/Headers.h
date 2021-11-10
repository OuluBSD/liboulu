
#define USE_DUMMY 1

HEADER11(			CenterCustomer,		CustomerBase,				customer,	CenterOrder,	CenterReceipt,	CenterOrder)
HEADER_ACTION(		CenterCustomer,		center.customer)

HEADER11(			TestRealtimeSrc,	RollingValueBase,			pipe,		CenterAudio,	CenterOrder,	CenterAudio)
HEADER_ACTION(		TestRealtimeSrc,	center.audio.src.test)

HEADER11(			TestRealtimeSink,	VoidSinkBase,				pipe,		CenterAudio,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		TestRealtimeSink,	center.audio.sink)
HEADER_ACTION(		TestRealtimeSink,	center.audio.sink.test.realtime)

HEADER11(			TestPollerSink,		VoidPollerSinkBase,			pipe,		CenterAudio,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		TestPollerSink,		center.audio.sink)
HEADER_ACTION(		TestPollerSink,		center.audio.sink.test.poller)

HEADER11(			AudioHardwareSink,	PortaudioSink,				pipe,		CenterAudio,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		AudioHardwareSink,	center.audio.sink)
HEADER_ACTION(		AudioHardwareSink,	center.audio.sink.hw)

HEADER11(			AudioDecoderSrc,	FfmpegAtomBase,				pipe,		CenterAudio,	CenterOrder,	CenterAudio)
HEADER_ACTION(		AudioDecoderSrc,	perma.audio.source.decoder)

HEADER11(			AudioDbgSrc,		AudioGenBase,				pipe,		CenterAudio,	CenterOrder,	CenterAudio)
HEADER_ACTION(		AudioDbgSrc,		center.audio.src.dbg_generator)

HEADER12(			AudioSplitter,		SplitterBase,				pipe,		CenterAudio,	CenterAudio,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		AudioSplitter,		center.audio.side.src)
HEADER_ACTION(		AudioSplitter,		center.audio.side.src.center)

HEADER12_U01(		AudioSplitterUser,	SplitterBase,				pipe,		CenterAudio,	CenterAudio,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		AudioSplitterUser,	center.audio.side.src)
HEADER_ACTION(		AudioSplitterUser,	center.audio.side.src.center.user)

HEADER21(			AudioJoiner,		JoinerBase,					pipe,		CenterAudio,	CenterOrder,	CenterAudio,	CenterAudio)
HEADER_ACTION(		AudioJoiner,		center.audio.side.sink)
HEADER_ACTION(		AudioJoiner,		center.audio.side.sink.center)

HEADER21_U10(		AudioJoinerUser,	JoinerBase,					pipe,		CenterAudio,	CenterOrder,	CenterAudio,	CenterAudio)
HEADER_ACTION(		AudioJoinerUser,	center.audio.side.sink)
HEADER_ACTION(		AudioJoinerUser,	center.audio.side.sink.center.user)

HEADER31_U20(		AudioJoiner2User,	JoinerBase,					pipe,		CenterAudio,	CenterOrder,	CenterAudio,	CenterAudio,	CenterAudio)
HEADER_ACTION(		AudioJoiner2User,	center.audio.side.sink)
HEADER_ACTION(		AudioJoiner2User,	center.audio.side.sink2.center.user)

HEADER11(			VideoDbgSrc,		VideoGenBase,				pipe,		CenterVideo,	CenterOrder,	CenterVideo)
HEADER_ACTION(		VideoDbgSrc,		center.video.src.dbg_generator)
HEADER_ARG(			VideoDbgSrc,		reqdef_flagGUI,		1)

HEADER11(			WebcamPipe,			OpenCVBase,					pipe,		CenterVideo,	CenterOrder,	CenterVideo)
HEADER_ACTION(		WebcamPipe,			center.video.webcam.pipe)
HEADER_ARG(			WebcamPipe,			reqdef_HAVE_OPENCV,	1)

HEADER12_U01(		WebcamAtom,			OpenCVBase,					pipe,		CenterVideo,	CenterOrder,	CenterVideo,	CenterReceipt)
HEADER_ACTION(		WebcamAtom,			center.video.webcam)
HEADER_ARG(			WebcamAtom,			reqdef_HAVE_OPENCV,	1)

HEADER12_U01(		AudioLoaderAtom,	FfmpegAtomBase,				pipe,		CenterAudio,	CenterOrder,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		AudioLoaderAtom,	center.audio.loader)
HEADER_ARG(			AudioLoaderAtom,	reqdef_flagGUI,	1)

HEADER13_U02(		VideoLoaderAtom,	FfmpegAtomBase,				pipe,		CenterVideo,	CenterOrder,	CenterVideo,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		VideoLoaderAtom,	center.video.loader)
HEADER_ARG(			VideoLoaderAtom,	reqdef_flagGUI,	1)

HEADER11(			EventStatePipe,		EventStateBase,			driver_pipe,	CenterEvent,	CenterEvent,	CenterReceipt)
HEADER_ACTION(		EventStatePipe,		state.event.pipe)




HEADER11(			OglCustomer,		CustomerBase,				customer,	OglOrder,		OglReceipt,		OglOrder)
HEADER_ACTION(		OglCustomer,		ogl.customer)
HEADER_ARG(			OglCustomer,		reqdef_flagGUI,		1)

HEADER11(			SdlContextAtom,		SDL2ContextBase,			driver,		CenterReceipt,	CenterReceipt,	CenterReceipt)
HEADER_ACTION(		SdlContextAtom,		sdl.context)

HEADER11(			SdlEventAtomPipe,	SDL2EventsBase,				pipe,		CenterEvent,	CenterOrder,	CenterEvent)
HEADER_ACTION(		SdlEventAtomPipe,	sdl.event.pipe)

HEADER12(			SdlEventAtom,		SDL2EventsBase,				pipe,		CenterEvent,	CenterOrder,	CenterEvent,	CenterEvent)
HEADER_ACTION(		SdlEventAtom,		sdl.event)

HEADER21(			EventState,			EventStateBase,			driver_pipe,	CenterEvent,	CenterEvent,	CenterEvent,	CenterReceipt)
HEADER_ACTION(		EventState,			state.event)

HEADER11(			TestEventSrcPipe,	TestEventSrcBase,			pipe,		CenterEvent,	CenterOrder,	CenterEvent)
HEADER_ACTION(		TestEventSrcPipe,	event.src.test.pipe)

HEADER12_U01(		SdlImageLoader,		SDL2ImageBase,				pipe,		CenterVideo,	CenterOrder,	CenterVideo,	CenterReceipt)
HEADER_ACTION(		SdlImageLoader,		center.image.loader)
HEADER_ARG(			SdlImageLoader,		reqdef_flagGUI,		1)

HEADER12_U01(		VolumeLoaderAtom,	VolumeLoaderBase,			pipe,		CenterVolume,	CenterOrder,	CenterVolume,	CenterReceipt)
HEADER_ACTION(		VolumeLoaderAtom,	center.volume.loader)
HEADER_ARG(			VolumeLoaderAtom,	reqdef_flagGUI,		1)



HEADER11(			SdlFboAtomSA,		SDL2ScreenBase,				pipe,		OglFbo,			OglOrder,		OglReceipt)
HEADER_ACTION(		SdlFboAtomSA,		sdl.fbo.standalone)
HEADER_ARG(			SdlFboAtomSA,		reqdef_flagGUI,		1)

HEADER11(			SdlFboPipe,			SDL2ScreenBase,				pipe,		OglFbo,			OglFbo,			OglReceipt)
HEADER_ACTION(		SdlFboPipe,			sdl.fbo.pipe)
HEADER_ARG(			SdlFboPipe,			reqdef_flagGUI,		1)

HEADER21(			SdlFboPipeSide,		SDL2ScreenBase,				pipe,		OglFbo,			OglOrder,		OglFbo,		OglReceipt)
HEADER_ACTION(		SdlFboPipeSide,		sdl.fbo.pipe.side)
HEADER_ARG(			SdlFboPipeSide,		reqdef_flagGUI,		1)

HEADER55_U44(		SdlFboAtom,			SDL2ScreenBase,				pipe,		OglFbo,			OglOrder,		OglFbo,		OglReceipt)
HEADER_ACTION(		SdlFboAtom,			sdl.fbo)
HEADER_ARG(			SdlFboAtom,			reqdef_flagGUI,		1)

HEADER11(			SdlVideoAtom,		SDL2SwScreenBase,			pipe,		CenterVideo,	CenterVideo,	CenterReceipt)
HEADER_ACTION(		SdlVideoAtom,		sdl.video)
HEADER_ARG(			SdlVideoAtom,		reqdef_flagGUI,		1)



HEADER11 (			SdlAudioAtom,		SDL2AudioOutputBase,		pipe,		CenterAudio,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		SdlAudioAtom,		center.audio.sink)
HEADER_ACTION(		SdlAudioAtom,		sdl.audio)

HEADER11(			OglShaderPipe,		OglShaderBase,				pipe,		OglFbo,			OglOrder,		OglFbo)
HEADER_ACTION(		OglShaderPipe,		ogl.fbo.source.pipe)
HEADER_ARG(			OglShaderPipe,		reqdef_flagGUI,		1)

HEADER55_U44(		OglShaderAtom,		OglShaderBase,				pipe,		OglFbo,			OglOrder,		OglFbo,		OglReceipt)
HEADER_ACTION(		OglShaderAtom,		ogl.fbo.source)
HEADER_ARG(			OglShaderAtom,		reqdef_flagGUI,		1)

HEADER11(			OglShaderAtomSA,	OglShaderBase,				pipe,		OglFbo,			OglOrder,		OglReceipt)
HEADER_ACTION(		OglShaderAtomSA,	ogl.fbo.source.standalone)
HEADER_ARG(			OglShaderAtomSA,	reqdef_flagGUI,		1)

HEADER22_U11(		OglTextureSource,	OglTextureBase,				pipe,		OglFbo,			OglOrder,		CenterVideo,	OglFbo,			OglReceipt)
HEADER_ACTION(		OglTextureSource,	ogl.fbo.image)
HEADER_ARG(			OglTextureSource,	reqdef_flagGUI,		1)

HEADER22_U11(		OglVolumeSource,	OglTextureBase,				pipe,		OglFbo,			OglOrder,		CenterVolume,	OglFbo,			OglReceipt)
HEADER_ACTION(		OglVolumeSource,	ogl.fbo.volume)
HEADER_ARG(			OglVolumeSource,	reqdef_flagGUI,		1)

HEADER22_U11(		OglAudioSink,		OglFboReaderBase,			pipe,		OglFbo,			OglOrder,		OglFbo,			CenterAudio,	OglReceipt)
HEADER_ACTION(		OglAudioSink,		ogl.fbo.center.audio)
HEADER_ARG(			OglAudioSink,		reqdef_flagGUI,		1)

HEADER12_U01(		OglKeyboardSource,	OglKeyboardBase,			pipe,		OglFbo,			OglOrder,		OglFbo,			OglReceipt)
HEADER_ACTION(		OglKeyboardSource,	ogl.fbo.keyboard)
HEADER_ARG(			OglKeyboardSource,	reqdef_flagGUI,		1)

HEADER22_U11(		OglAudioSource,		OglAudioBase,				pipe,		OglFbo,			OglOrder,		CenterAudio,	OglFbo,			OglReceipt)
HEADER_ACTION(		OglAudioSource,		ogl.fbo.audio)
HEADER_ARG(			OglAudioSource,		reqdef_flagGUI,		1)
