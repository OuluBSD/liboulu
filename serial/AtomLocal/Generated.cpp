#include "AtomLocal.h"

namespace TS {

namespace Serial {

AtomTypeCls CenterCustomer::GetAtomType()
{
	return ATOM11(CENTER_CUSTOMER, CUSTOMER, CENTER, ORDER, CENTER, RECEIPT, CENTER, ORDER);
}

void CenterCustomer::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CustomerBaseT<CenterCustomer>>(this);
}

AtomTypeCls CenterCustomer::GetType() const
{
	return GetAtomType();
}

AtomTypeCls TestRealtimeSrc::GetAtomType()
{
	return ATOM11(TEST_REALTIME_SRC, SOURCE, CENTER, AUDIO, CENTER, ORDER, CENTER, AUDIO);
}

void TestRealtimeSrc::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSourceAsync<TestRealtimeSrc>>(this);
	vis.VisitThis<RollingValueBase>(this);
}

AtomTypeCls TestRealtimeSrc::GetType() const
{
	return GetAtomType();
}

AtomTypeCls TestRealtimeSink::GetAtomType()
{
	return ATOM11(TEST_REALTIME_SINK, SINK, CENTER, AUDIO, CENTER, AUDIO, CENTER, RECEIPT);
}

void TestRealtimeSink::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSinkPolling<TestRealtimeSink>>(this);
	vis.VisitThis<VoidSinkBase>(this);
}

AtomTypeCls TestRealtimeSink::GetType() const
{
	return GetAtomType();
}

AtomTypeCls AudioHardwareSink::GetAtomType()
{
	return ATOM11(AUDIO_HARDWARE_SINK, SINK, CENTER, AUDIO, CENTER, AUDIO, CENTER, RECEIPT);
}

void AudioHardwareSink::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSinkPolling<AudioHardwareSink>>(this);
	vis.VisitThis<PortaudioSink>(this);
}

AtomTypeCls AudioHardwareSink::GetType() const
{
	return GetAtomType();
}

AtomTypeCls AudioDecoderSrc::GetAtomType()
{
	return ATOM11(AUDIO_DECODER_SRC, SOURCE, CENTER, AUDIO, CENTER, ORDER, CENTER, AUDIO);
}

void AudioDecoderSrc::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSourceAsync<AudioDecoderSrc>>(this);
	vis.VisitThis<FfmpegAtomBase>(this);
}

AtomTypeCls AudioDecoderSrc::GetType() const
{
	return GetAtomType();
}

AtomTypeCls AudioDbgSrc::GetAtomType()
{
	return ATOM11(AUDIO_DBG_SRC, SOURCE, CENTER, AUDIO, CENTER, ORDER, CENTER, AUDIO);
}

void AudioDbgSrc::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSourceAsync<AudioDbgSrc>>(this);
	vis.VisitThis<AudioGenBase>(this);
}

AtomTypeCls AudioDbgSrc::GetType() const
{
	return GetAtomType();
}

AtomTypeCls AudioSplitter::GetAtomType()
{
	return ATOM12(AUDIO_SPLITTER, SIDE_SOURCE, CENTER, AUDIO, CENTER, AUDIO, CENTER, RECEIPT, CENTER, AUDIO);
}

void AudioSplitter::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSourcePolling<AudioSplitter>>(this);
	vis.VisitThis<SplitterBase>(this);
}

AtomTypeCls AudioSplitter::GetType() const
{
	return GetAtomType();
}

AtomTypeCls AudioJoiner::GetAtomType()
{
	return ATOM21(AUDIO_JOINER, SIDE_SINK, CENTER, AUDIO, CENTER, ORDER, CENTER, AUDIO, CENTER, AUDIO);
}

void AudioJoiner::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSinkPolling<AudioJoiner>>(this);
	vis.VisitThis<JoinerBase>(this);
}

AtomTypeCls AudioJoiner::GetType() const
{
	return GetAtomType();
}

AtomTypeCls VideoDbgSrc::GetAtomType()
{
	return ATOM11(VIDEO_DBG_SRC, SOURCE, CENTER, VIDEO, CENTER, ORDER, CENTER, VIDEO);
}

void VideoDbgSrc::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSourceAsync<VideoDbgSrc>>(this);
	vis.VisitThis<VideoGenBase>(this);
}

AtomTypeCls VideoDbgSrc::GetType() const
{
	return GetAtomType();
}

AtomTypeCls AccelVideoDbgSrc::GetAtomType()
{
	return ATOM11(ACCEL_VIDEO_DBG_SRC, SOURCE, ACCEL, VIDEO, ACCEL, ORDER, ACCEL, VIDEO);
}

void AccelVideoDbgSrc::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<AccelSourceAsync<AccelVideoDbgSrc>>(this);
	vis.VisitThis<AccelVideoGenBase>(this);
}

AtomTypeCls AccelVideoDbgSrc::GetType() const
{
	return GetAtomType();
}

AtomTypeCls AccelCustomer::GetAtomType()
{
	return ATOM11(ACCEL_CUSTOMER, CUSTOMER, ACCEL, ORDER, ACCEL, RECEIPT, ACCEL, ORDER);
}

void AccelCustomer::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CustomerBaseT<AccelCustomer>>(this);
}

AtomTypeCls AccelCustomer::GetType() const
{
	return GetAtomType();
}

AtomTypeCls SdlContextAtom::GetAtomType()
{
	return ATOM11(SDL_CONTEXT_ATOM, DRIVER, CENTER, RECEIPT, CENTER, RECEIPT, CENTER, RECEIPT);
}

void SdlContextAtom::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterDriver<SdlContextAtom>>(this);
	vis.VisitThis<SDL2ContextBase>(this);
}

AtomTypeCls SdlContextAtom::GetType() const
{
	return GetAtomType();
}

AtomTypeCls SdlVideoAtom::GetAtomType()
{
	return ATOM11(SDL_VIDEO_ATOM, SINK, ACCEL, VIDEO, ACCEL, VIDEO, ACCEL, RECEIPT);
}

void SdlVideoAtom::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<AccelSinkPolling<SdlVideoAtom>>(this);
	vis.VisitThis<SDL2ScreenBase>(this);
}

AtomTypeCls SdlVideoAtom::GetType() const
{
	return GetAtomType();
}

AtomTypeCls SdlSwVideoAtom::GetAtomType()
{
	return ATOM11(SDL_SW_VIDEO_ATOM, SINK, CENTER, VIDEO, CENTER, VIDEO, CENTER, RECEIPT);
}

void SdlSwVideoAtom::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSinkPolling<SdlSwVideoAtom>>(this);
	vis.VisitThis<SDL2SwScreenBase>(this);
}

AtomTypeCls SdlSwVideoAtom::GetType() const
{
	return GetAtomType();
}

AtomTypeCls SdlAudioAtom::GetAtomType()
{
	return ATOM11(SDL_AUDIO_ATOM, SINK, CENTER, AUDIO, CENTER, AUDIO, CENTER, RECEIPT);
}

void SdlAudioAtom::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<CenterSinkAsync<SdlAudioAtom>>(this);
	vis.VisitThis<SDL2AudioOutputBase>(this);
}

AtomTypeCls SdlAudioAtom::GetType() const
{
	return GetAtomType();
}

}

}

