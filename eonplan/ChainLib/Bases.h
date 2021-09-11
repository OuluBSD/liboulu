
BASE(CenterDriver)
BASE(CustomerBaseT)
BASE(CenterSourceAsync)
BASE(CenterSinkSync)
BASE(CenterSinkPolling)
BASE(CenterSideSourceAsync)
BASE(CenterSideSinkAsync)
BASE(CenterSide)
BASE(DummySideAsync)
BASE(AccelSinkPolling)
BASE(AccelSideAsync)

BASE_FLAG(CenterSourceAsync,		store_packet)
BASE_FLAG(CenterSinkSync,			ival_sink_proc)
//BASE_FLAG(CenterSideAsync,			store_packet)
BASE_FLAG(AccelSideAsync,			store_packet)
BASE_ACTION(CustomerBaseT,			loop.connected)
BASE_ACTION(CenterSinkSync,			center.audio.sink)
BASE_ACTION(CenterSinkPolling,		center.audio.sink)

/*
BASE2(ReceiptOrder,				CenterReceipt,	CenterOrder)
BASE2(OrderAudio,				CenterOrder,	CenterAudio)
BASE2(OrderMidi,				CenterOrder,	CenterMidi)
BASE3(AccelCenterAudioSink,		CenterOrder,	SinkAccelAudio,		CenterAudio)
BASE3(CenterAccelOrderSide,		CenterOrder,	SrcAccelOrder,		CenterReceipt)
BASE3(NetCenterAudioSink,		CenterOrder,	SinkNetOrder,		CenterAudio)
BASE3(CenterNetMidiSide,		CenterOrder,	SrcNetMidi,			CenterReceipt)
BASE2(AudioReceipt,				CenterAudio,	CenterReceipt)
BASE3(AudioReceiptWithAccel,	CenterAudio,	SrcAccelAudio,		CenterReceipt)
BASE3(CenterAccelMidiSrc,		CenterMidi,		SrcAccelMidi,		CenterReceipt)

BASE2(AccelReceiptOrder,		AccelReceipt,	AccelOrder)
BASE3(CenterAccelMidiSink,		AccelOrder,		SinkCenterMidi,		AccelMidi)
BASE2(AccelMidiAudioConv,		AccelMidi,		AccelAudio)
BASE2(AccelAudioPipe,			AccelAudio,		AccelAudio)
BASE3(AccelCenterAudioSrc,		AccelAudio,		SrcCenterAudiof,		AccelReceipt)
BASE3(AccelAudioInputMulti,		AccelOrder,		AccelAudio,			AccelAudio)
BASE3(AccelAudioOutput,			AccelAudio,		SrcAccelAudio,		AccelReceipt)

BASE2(NetReceiptOrder,			NetReceipt,		NetOrder)
BASE3(CenterNetMidiSink,		NetOrder,		SinkNetMidi,		NetMidi)
BASE3(NetCenterAudioSrc,		NetAudio,		SrcCenterAudio,		NetReceipt)
*/