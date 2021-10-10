
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

HEADER31_U20(		AudioJoiner2User,	JoinerBase,					pipe,		CenterAudio,	CenterOrder,	CenterAudio,	CenterAudio)
HEADER_ACTION(		AudioJoiner2User,	center.audio.side.sink)
HEADER_ACTION(		AudioJoiner2User,	center.audio.side.sink2.center.user)

HEADER11(			VideoDbgSrc,		VideoGenBase,				pipe,		CenterVideo,	CenterOrder,	CenterVideo)
HEADER_ACTION(		VideoDbgSrc,		center.video.src.dbg_generator)
HEADER_ARG(			VideoDbgSrc,		GUI,		1)




HEADER11(			OglCustomer,		CustomerBase,				customer,	OglOrder,		OglReceipt,		OglOrder)
HEADER_ACTION(		OglCustomer,		ogl.customer)
HEADER_ARG(			OglCustomer,		GUI,		1)

HEADER11(			SdlContextAtom,		SDL2ContextBase,			driver,		CenterReceipt,	CenterReceipt,	CenterReceipt)
HEADER_ACTION(		SdlContextAtom,		sdl.context)

HEADER11(			SdlEventAtomPipe,	SDL2EventsBase,				pipe,		CenterEvent,	CenterOrder,	CenterEvent)
HEADER_ACTION(		SdlEventAtomPipe,	sdl.event.pipe)

HEADER11(			EventStatePipe,		EventStateBase,			driver_pipe,	CenterEvent,	CenterEvent,	CenterReceipt)
HEADER_ACTION(		EventStatePipe,		state.event.pipe)

HEADER12(			SdlEventAtom,		SDL2EventsBase,				pipe,		CenterEvent,	CenterOrder,	CenterEvent,	CenterEvent)
HEADER_ACTION(		SdlEventAtom,		sdl.event)

HEADER21(			EventState,			EventStateBase,			driver_pipe,	CenterEvent,	CenterEvent,	CenterEvent,	CenterReceipt)
HEADER_ACTION(		EventState,			state.event)

HEADER11(			TestEventSrcPipe,	TestEventSrcBase,			pipe,		CenterEvent,	CenterOrder,	CenterEvent)
HEADER_ACTION(		TestEventSrcPipe,	event.src.test.pipe)



HEADER11(			SdlFboAtomSA,		SDL2ScreenBase,				pipe,		OglFbo,			OglOrder,		OglReceipt)
HEADER_ACTION(		SdlFboAtomSA,		sdl.fbo.standalone)
HEADER_ARG(			SdlFboAtomSA,		GUI,		1)

HEADER11(			SdlFboAtom,			SDL2ScreenBase,				pipe,		OglFbo,			OglFbo,			OglReceipt)
HEADER_ACTION(		SdlFboAtom,			sdl.fbo.pipe)
HEADER_ARG(			SdlFboAtom,			GUI,		1)

HEADER21(			SdlFboPipe,			SDL2ScreenBase,				pipe,		OglFbo,			OglOrder,		OglFbo,		OglReceipt)
HEADER_ACTION(		SdlFboPipe,			sdl.fbo)
HEADER_ARG(			SdlFboPipe,			GUI,		1)

HEADER11(			SdlVideoAtom,		SDL2SwScreenBase,			pipe,		CenterVideo,	CenterVideo,	CenterReceipt)
HEADER_ACTION(		SdlVideoAtom,		sdl.video)
HEADER_ARG(			SdlVideoAtom,		GUI,		1)

HEADER11 (			SdlAudioAtom,		SDL2AudioOutputBase,		pipe,		CenterAudio,	CenterAudio,	CenterReceipt)
HEADER_ACTION(		SdlAudioAtom,		center.audio.sink)
HEADER_ACTION(		SdlAudioAtom,		sdl.audio)

HEADER11(			OglShaderPipe,		OglShaderBase,				pipe,		OglFbo,			OglOrder,		OglFbo)
HEADER_ACTION(		OglShaderPipe,		ogl.fbo.source.pipe)
HEADER_ARG(			OglShaderPipe,		GUI,		1)

HEADER44_U44(		OglShaderAtom,		OglShaderBase,				pipe,		OglFbo	,		OglOrder,		OglFbo,		OglReceipt)
HEADER_ACTION(		OglShaderAtom,		ogl.fbo.source)
HEADER_ARG(			OglShaderAtom,		GUI,		1)
