#include "AtomLocal.h"

#if HAVE_FFMPEG

NAMESPACE_SERIAL_BEGIN


FfmpegAtomBase::FfmpegAtomBase() {
	def_cap_sz = Size(1280,720);
	def_cap_fps = 30;
	
	file_in.SetParent(this);
	file_in.WhenStopped << THISBACK(OnStop);
}

void FfmpegAtomBase::SetError(String s) {
	last_error = s;
	LOG("FfmpegAtomBase: error: " << s);
	OnError();
}

bool FfmpegAtomBase::Initialize(const Script::WorldState& ws) {
	//TODO // DevComponent::Initialize
	AtomTypeCls type = GetType();
	
	//DUMP(ws);
	
	
	if (type.iface.src().val.type == ValCls::AUDIO) {
		if (ws.IsTrue(".stop_machine"))
			stops_machine = true;
	}
	else if (type.iface.src().val.type == ValCls::VIDEO) {
		if (ws.IsTrue(".stop_machine"))
			stops_machine = true;
	}
	else {
		SetError("Invalid ExtComponent type");
		return false;
	}
	
	
	file_path = ws.Get(".filepath");
	if (file_path.IsEmpty()) {
		SetError("no file path given");
		return false;
	}
	//DUMP(file_path);
	
	if (!LoadFileAny(file_path))
		return false;
	
	
	//AddToContext<CenterSpec>(AsRef<CenterSource>());
	return true;
}

void FfmpegAtomBase::Uninitialize() {
	file_in.Clear();
	
	//RemoveFromContext<CenterSpec>(AsRef<CenterSource>());
}

void FfmpegAtomBase::OnError() {
	if (stops_machine)
		GetParent().GetMachine().SetNotRunning();
}

void FfmpegAtomBase::OnStop() {
	if (stops_machine)
		GetParent().GetMachine().SetNotRunning();
	WhenStopped();
}

bool FfmpegAtomBase::LoadFileAny(String path) {
	vi.Stop();
	
	mode = INVALID_MODE;
	
	const int src_ch_i = 0;
	
	file_in.SetFormat(GetSource()->GetSourceValue(src_ch_i).GetFormat());
	// TODO side-connection format
	
	if (file_in.OpenFile(path)) {
		if (file_in.Open()) {
			if (file_in.IsOpenAudio() && file_in.IsOpenVideo()) {
				mode = AUDIOVIDEO;
				vi.SetCap(
					file_in.GetAudio().AsRefT(),
					file_in.GetVideo().AsRefT());
			}
			else if (file_in.IsOpenAudio()) {
				mode = AUDIO_ONLY;
				vi.SetCap(
					file_in.GetAudio().AsRefT(),
					VideoInputFrameRef());
			}
			else {
				mode = VIDEO_ONLY;
				vi.SetCap(
					AudioInputFrameRef(),
					file_in.GetVideo().AsRefT());
			}

			vi.Start(false);
			
			return true;
		}
		else {
			SetError("couldn't open file " + path);
		}
	}
	else {
		SetError("couldn't open file " + path);
	}
	
	
	return false;
}

void FfmpegAtomBase::Forward(FwdScope& fwd) {
	if (mode == AUDIO_ONLY)
		file_in.FillAudioBuffer();
	else
		TODO
}

bool FfmpegAtomBase::IsReady(PacketIO& io) {
	if (mode == AUDIO_ONLY)
		return file_in.GetAudio().buf.GetCount();
	else
		TODO
}

bool FfmpegAtomBase::ProcessPackets(PacketIO& io) {
	TODO
	#if 0
	if (mode == AUDIO_ONLY)
		file_in.GetAudio().StorePacket(sink_ch, src_ch, in, out);
	else
		TODO
	#endif
}


NAMESPACE_SERIAL_END

#endif
