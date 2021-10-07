#include "SerialMach.h"

NAMESPACE_SERIAL_BEGIN


void AudioFormat::Set(SoundSample::Type type, int channels, int freq, int sample_rate) {
	SampleBase<SoundSample>::SetType(type);
	DimBase<1>::SetSize(channels);
	TimeSeriesBase::SetTimeSeries(freq, sample_rate);
}

String AudioFormat::ToString() const {
	return		SampleBase<SoundSample>::ToString() + ", " +
				DimBase<1>::ToString() + ", " +
				TimeSeriesBase::ToString();
}

int AudioFormat::GetFrameSize() const {
	return		DimBase<1>::GetArea() *
				TimeSeriesBase::GetSampleRate() *
				SampleBase<SoundSample>::GetSampleSize();
}

bool AudioFormat::IsValid() const {
	return		TimeSeriesBase::IsValid() && \
				SampleBase<SoundSample>::IsValid() && \
				DimBase<1>::IsValid();
}

bool AudioFormat::IsSame(const AudioFormat& b) const {
	return		TimeSeriesBase::IsSame(b) &&
				SampleBase<SoundSample>::IsCopyCompatible(b) &&
				DimBase<1>::IsSame(b);
}









void VideoFormat::Set(LightSampleFD::Type type, int w, int h, int freq, int sample_rate) {
	SampleBase<LightSampleFD>::SetType(type);
	DimBase<2>::operator=(Size(w,h));
	TimeSeriesBase::SetTimeSeries(freq, sample_rate);
}

int VideoFormat::GetFrameSize() const {
	return		SampleBase<LightSampleFD>::GetSampleSize() *
				DimBase<2>::GetArea() *
				TimeSeriesBase::GetSampleRate();
}

String VideoFormat::ToString() const {
	return		SampleBase<LightSampleFD>::ToString() + ", " +
				DimBase<2>::ToString() + ", " +
				TimeSeriesBase::ToString();
}

bool VideoFormat::IsValid() const {
	return		TimeSeriesBase::IsValid() && \
				SampleBase<LightSampleFD>::IsValid() && \
				DimBase<2>::IsValid();
}

bool VideoFormat::IsSame(const VideoFormat& b) const {
	return		TimeSeriesBase::IsSame(b) &&
				SampleBase<LightSampleFD>::IsCopyCompatible(b) &&
				DimBase<2 >::IsSame(b);
}




void FboFormat::Set(LightSampleFD::Type type, int w, int h, int freq, int sample_rate) {
	SampleBase<LightSampleFD>::SetType(type);
	DimBase<2>::operator=(Size(w,h));
	TimeSeriesBase::SetTimeSeries(freq, sample_rate);
}

int FboFormat::GetFrameSize() const {
	return		SampleBase<LightSampleFD>::GetSampleSize() *
				DimBase<2>::GetArea() *
				TimeSeriesBase::GetSampleRate();
}

String FboFormat::ToString() const {
	return		SampleBase<LightSampleFD>::ToString() + ", " +
				DimBase<2>::ToString() + ", " +
				TimeSeriesBase::ToString();
}

bool FboFormat::IsValid() const {
	return		TimeSeriesBase::IsValid() && \
				SampleBase<LightSampleFD>::IsValid() && \
				DimBase<2>::IsValid();
}

bool FboFormat::IsSame(const FboFormat& b) const {
	return		TimeSeriesBase::IsSame(b) &&
				SampleBase<LightSampleFD>::IsCopyCompatible(b) &&
				DimBase<2 >::IsSame(b);
}




int MidiFormat::GetFrameSize() const {
	TODO
}

String MidiFormat::ToString() const {
	TODO
}

bool MidiFormat::IsValid() const {
	return true;
}

bool MidiFormat::IsSame(const MidiFormat& fmt) const {
	return true;
}







String EventFormat::ToString() const{
	TODO
}

bool EventFormat::IsValid() const {
	return true;
}

bool EventFormat::IsSame(const EventFormat& fmt) const {
	return true;
}

int EventFormat::GetFrameSize() const {
	return		DimBase<1>::GetArea() *
				SparseTimeSeriesBase::GetSampleRate() *
				SampleBase<EventSample>::GetSampleSize();
}








#define PROXY(x) \
	if (IsAudio()) return aud.x(); \
	if (IsVideo()) return vid.x(); \
	if (IsMidi())  return mid.x(); \
	if (IsEvent()) return ev.x(); \
	if (IsFbo())   return fbo.x(); \
	PANIC("Invalid type");

#define PROXY_(x,y) \
	if (IsAudio()) return aud.x((const AudioFormat&)y); \
	if (IsVideo()) return vid.x((const VideoFormat&)y); \
	if (IsMidi())  return mid.x((const MidiFormat&)y); \
	if (IsEvent()) return ev.x((const EventFormat&)y); \
	if (IsFbo())   return fbo.x((const FboFormat&)y); \
	PANIC("Invalid type");

#define PROXY_CHK(x) ASSERT(IsValid()); PROXY(x)

#define PROXY_CHK_(x,y) ASSERT(IsValid()); PROXY_(x,y)

String Format::ToString() const {
	if (IsAudio()) return "AudioFormat(" + vd.ToString() + ", " + aud.ToString() + ")";
	if (IsVideo()) return "VideoFormat(" + vd.ToString() + ", " + vid.ToString() + ")";
	if (IsMidi())  return "MidiFormat(" + vd.ToString() + ", " + vid.ToString() + ")";
	if (IsEvent()) return "EventFormat(" + vd.ToString() + ", " + vid.ToString() + ")";
	if (IsFbo())   return "FboFormat(" + vd.ToString() + ", " + vid.ToString() + ")";
	if (vd.val.type == ValCls::ORDER) return "OrderFormat";
	if (vd.val.type == ValCls::RECEIPT) return "ReceiptFormat";
	return "Invalid Format";
}

int Format::GetSampleSize() const {
	PROXY_CHK(GetSampleSize)
}

int Format::GetArea() const {
	PROXY_CHK(GetArea)
}

int Format::GetFrameSize() const {
	PROXY_CHK(GetFrameSize)
}

double Format::GetFrameSeconds() const {
	PROXY_CHK(GetFrameSeconds)
}

bool Format::HasData() const {
	return	vd.val != ValCls::ORDER &&
			vd.val != ValCls::RECEIPT;
}

bool Format::IsValid() const {
	if (!vd.IsValid()) return false;
	if (!HasData()) return true;
	PROXY(IsValid)
}

bool Format::IsSame(const Format& f) const {
	if (vd != f.vd) return false;
	if (!HasData()) return true;
	PROXY_CHK_(IsSame, f)
}

bool Format::IsCopyCompatible(const Format& f) const {
	if (vd != f.vd) return false;
	if (!HasData()) return true;
	PROXY_CHK_(IsCopyCompatible, f)
}

bool Format::operator ==(const Format& f) {
	return IsSame(f);
}

bool Format::operator !=(const Format& f) {
	return !IsSame(f);
}

void Format::SetDefault(ValDevCls t) {
	TODO
}

void Format::Clear() {
	vd.Clear();
	memset(data, 0, sizeof(data));
}


void Format::SetAudio(DevCls dev, SoundSample::Type t, int channels, int freq, int sample_rate) {
	vd.dev = dev;
	vd.val = ValCls::AUDIO;
	memset(data, 0, sizeof(data));
	aud.Set(t, channels, freq, sample_rate);
}

void Format::SetOrder(DevCls dev) {
	vd.dev = dev;
	vd.val = ValCls::ORDER;
	memset(data, 0, sizeof(data));
}

void Format::SetReceipt(DevCls dev) {
	vd.dev = dev;
	vd.val = ValCls::RECEIPT;
	memset(data, 0, sizeof(data));
}

void Format::SetMidi(DevCls dev) {
	vd.dev = dev;
	vd.val = ValCls::MIDI;
	memset(data, 0, sizeof(data));
	mid.SetDefault();
}

void Format::SetVideo(DevCls dev, LightSampleFD::Type t, int w, int h, int freq, int sample_rate) {
	vd.dev = dev;
	vd.val = ValCls::VIDEO;
	memset(data, 0, sizeof(data));
	vid.Set(t, w, h, freq, sample_rate);
}

void Format::SetFbo(DevCls dev, LightSampleFD::Type t, int w, int h, int freq, int sample_rate) {
	vd.dev = dev;
	vd.val = ValCls::FBO;
	memset(data, 0, sizeof(data));
	fbo.Set(t, w, h, freq, sample_rate);
}

void Format::SetEvent(DevCls dev) {
	vd.dev = dev;
	vd.val = ValCls::EVENT;
	memset(data, 0, sizeof(data));
}

void Format::operator=(const Format& f) {
	vd = f.vd;
	memcpy(data, f.data, sizeof(data));
}


NAMESPACE_SERIAL_END
