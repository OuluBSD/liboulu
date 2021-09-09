
#define USE_DUMMY 1

HEADER2(			CenterCustomer,		CustomerBaseT,	customer,	CenterReceipt,	CenterOrder)
HEADER_ACTION(		CenterCustomer,		center.customer)
//HEADER_INHERITS(	CenterCustomer,		CustomerBase)

HEADER2(			TestRealtimeSrc,	CenterSourceAsync,	source,		CenterOrder,	CenterAudio)
HEADER2(			TestRealtimeSink,	CenterSinkSync,		sink,		CenterAudio,	CenterReceipt)
HEADER_ACTION(		TestRealtimeSrc,	center.audio.src.test)
HEADER_ACTION(		TestRealtimeSink,	center.audio.sink.test.realtime)

HEADER2(			AudioHardwareSink,	CenterSinkPolling,		sink,		CenterAudio,	CenterReceipt)
HEADER_ACTION(		AudioHardwareSink,	center.audio.sink.hw)
HEADER_INHERITS(	AudioHardwareSink,	PortaudioSink)
HEADER_ARG(			AudioHardwareSink,	ALT_LINK,	1)

HEADER2(			AudioDecoderSrc,	CenterSourceAsync,		source,		CenterOrder,	CenterAudio)
HEADER_ACTION(		AudioDecoderSrc,	perma.audio.source.decoder)
HEADER_INHERITS(	AudioDecoderSrc,	FfmpegAtomBase)
HEADER_ARG(			AudioDecoderSrc,	ALT_LINK,	1)
HEADER_ARG(			AudioDecoderSrc,	ALT_FWD,	1)

HEADER2(			AudioDbgSrc,		CenterSourceAsync,		source,		CenterOrder,	CenterAudio)
HEADER_ACTION(		AudioDbgSrc,		center.audio.src.dbg_generator)
HEADER_INHERITS(	AudioDbgSrc,		AudioGenBase)
HEADER_ARG(			AudioDbgSrc,		ALT_LINK,	1)
HEADER_ARG(			AudioDbgSrc,		ALT_FWD,	1)



HEADER2(			AccelCustomer,		CustomerBaseT,			customer,	AccelReceipt,	AccelOrder)
HEADER_ACTION(		AccelCustomer,		accel.customer)
//HEADER_INHERITS(	AccelCustomer,		CustomerBase)

HEADER2(			VideoHardwareSink,	AccelSideAsync,			sink,		AccelVideo,		AccelReceipt)
HEADER_ACTION(		VideoHardwareSink,	accel.video.sink.hw)
HEADER_ARG(			VideoHardwareSink,	ALT_LINK,	1)

HEADER2(			VideoShaderSrc,		AccelSideAsync,			source,		AccelOrder,		AccelVideo)
HEADER_ACTION(		VideoShaderSrc,		accel.video.src)
HEADER_ARG(			VideoShaderSrc,		ALT_LINK,	1)
HEADER_ARG(			VideoShaderSrc,		ALT_FWD,	1)

HEADER2(			VideoShaderBuffer,	AccelSideAsync,			side_pipe,	AccelOrder,		AccelReceipt)
HEADER_ACTION(		VideoShaderBuffer,	accel.video.buffer)
HEADER_ARG(			VideoShaderBuffer,	ALT_LINK,	1)

#if USE_DUMMY
HEADER_INHERITS(	VideoHardwareSink,	DummyAlt)
HEADER_INHERITS(	VideoShaderSrc,		DummyAlt)
HEADER_INHERITS(	VideoShaderBuffer,	DummyAlt)
#else
HEADER_INHERITS(	VideoHardwareSink,	SystemVideoSink)
HEADER_INHERITS(	VideoShaderSrc,		SystemVideoSink)
HEADER_INHERITS(	VideoShaderBuffer,	SystemVideoSink)
#endif


HEADER2(			SdlContextAtom,		CenterSideAsync,		side_pipe,	CenterReceipt,	CenterOrder)
HEADER2(			SdlEventAtom,		CenterSideAsync,		side_pipe,	CenterReceipt,	CenterOrder)
HEADER2(			SdlVideoAtom,		CenterSideAsync,		side_pipe,	CenterReceipt,	CenterOrder)
HEADER2(			SdlAudioAtom,		CenterSideAsync,		side_pipe,	CenterReceipt,	CenterOrder)
HEADER_ACTION(		SdlContextAtom,		sdl.context)
HEADER_ACTION(		SdlEventAtom,		sdl.event)
HEADER_ACTION(		SdlVideoAtom,		sdl.video)
HEADER_ACTION(		SdlAudioAtom,		sdl.audio)


//HEADER(AccelCustomer,		AccelReceiptOrder)s
//HEADER(NetCustomer,		NetReceiptOrder)