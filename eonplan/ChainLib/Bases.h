#ifndef _ChainLib_Bases_h_
#define _ChainLib_Bases_h_

NAMESPACE_PLAN_BEGIN


BASE2(ReceiptOrder,				CenterReceipt,	CenterOrder)
BASE2(OrderAudio,				CenterOrder,	CenterAudio)
BASE2(OrderMidi,				CenterOrder,	CenterMidi)
BASE3(AccelCenterAudioSink,		CenterOrder,	SinkAccelAudio,		CenterAudio)
BASE3(CenterAccelOrderSide,		CenterOrder,	SrcAccelOrder,		CenterReceipt)
BASE3(CenterNetOrderSide,		CenterOrder,	SrcNetOrder,		CenterReceipt)
BASE3(NetCenterAudioSink,		CenterOrder,	SinkNetOrder,		CenterAudio)
BASE2(AudioReceipt,				CenterAudio,	CenterReceipt)
BASE3(AudioReceiptWithAccel,	CenterAudio,	SrcAccelAudio,		CenterReceipt)
BASE3(CenterAccelMidiSrc,		CenterMidi,		SrcAccelMidi,		CenterReceipt)

BASE2(AccelReceiptOrder,		AccelReceipt,	AccelOrder)
BASE3(CenterAccelMidiSink,		AccelOrder,		SinkCenterMidi,		AccelMidi)
BASE2(AccelMidiAudioConv,		AccelMidi,		AccelAudio)
BASE2(AccelAudioPipe,			AccelAudio,		AccelAudio)
BASE3(AccelCenterAudioSrc,		AccelAudio,		SrcAccelAudio,		AccelReceipt)
BASE3(AccelAudioInputMulti,		AccelOrder,		AccelAudio,			AccelAudio)

BASE2(NetReceiptOrder,			NetReceipt,		NetOrder)
BASE3(CenterNetMidiSink,		NetOrder,		SinkNetMidi,		NetMidi)


NAMESPACE_PLAN_END

#endif
