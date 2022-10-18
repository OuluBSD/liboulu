#include "AudioHost.h"


NAMESPACE_TOPSIDE_BEGIN


MidiEonContextLoader::MidiEonContextLoader() {
	
}

void MidiEonContextLoader::Clear() {
	id_counter = 0;
}

void MidiEonContextLoader::OnError(TypeCls type, String fn, String msg) {
	last_error = msg;
	WhenError();
}

void MidiEonContextLoader::OnError(String fn, String msg) {
	LOG("MidiEonContextLoader::" << fn << ": error: " << msg);
	last_error = msg;
	WhenError();
}

bool MidiEonContextLoader::Load(String path, Object& o) {
	LOG("MidiEonContextLoader::Load: " << path);
	
	String ext = GetFileExt(path);
	if (ext == ".mid")
		return LoadFileMidi(path, o);
	
	return false;
}

bool MidiEonContextLoader::LoadFileMidi(String path, Object& dst) {
	const char* fn_name = "LoadFileMidi";
	Clear();
	
	if (!FileExists(path)) {
		String share_path = ShareDirFile(path);
		if (FileExists(share_path))
			path = share_path;
	}
	
	if (!FileExists(path)) {
		OnError(fn_name, "file doesn't exist: " + path);
		return false;
	}
	
	
	MidiIO::File f;
	
	if (!f.Open(path)) {
		OnError(fn_name, "file loading failed: " + path);
		return false;
	}
	
	// Find first patch-change for every track
	VectorMap<int,int> patches;
	int track_count = f.GetTrackCount();
	for(int i = 0; i < track_count; i++) {
		int ev_count = f.GetEventCount(i);
		for(int j = 0; j < ev_count; j++) {
			const MidiIO::Event& ev = f.GetEvent(i, j);
			if (ev.IsPatchChange()) {
				int timbre = ev.GetP1();
				LOG("Track " << i << ": " << MidiIO::GetTimbreName(timbre));
				patches.Add(i,timbre);
				break;
			}
		}
	}
	
	const char* begin = R"eon(
machine midi.app:
	chain program:
		loop event:
			center.customer
			midi.file.reader[][${SIDEOUT}]:
				filepath = "${PATH}"
				close_machine = true
)eon";

	const char* ch_tmpl = R"eon(
		loop ch.${CHANNEL}:
			center.customer
			fluidsynth.pipe[loop == event]:
				verbose = false
				patch = ${PATCH}
			center.audio.side.src.center.user[][loop == mixer]
)eon";

	const char* end = R"eon(
		loop mixer:
			center.customer
			center.audio.mixer16[${SIDEIN}]:
				auto.limit = true
			center.audio.sink.hw
)eon";

	String eon;
	
	eon = begin;
	
	String sideout;
	for(int i = 0; i < track_count; i++) {
		int patch = patches.Get(i, -1);
		if (patch >= 0) {
			String ch = ch_tmpl;
			ch.Replace("${CHANNEL}", IntStr(i));
			ch.Replace("${PATCH}", IntStr(patch));
			eon += ch;
			
			if (sideout.GetCount()) sideout << ", ";
			sideout << "loop == ch." << i;
		}
	}
	
	eon += end;
	
	eon.Replace("${PATH}", path);
	eon.Replace("${SIDEOUT}", sideout);
	eon.Replace("${SIDEIN}", sideout);
	
	
	//LOG(eon);
	
	result = eon;
	
	return true;
}











String SerialMidiEonLoader::LoadFile(String file_path) {
	MidiEonContextLoader mid_loader;
	Object o;
	if (!mid_loader.Load(file_path, o)) {
		LOG("SerialMidiEonLoader::LoadFile: error: toy file loading failed: " << file_path);
		return String();
	}
	
	return mid_loader.GetResult();
}


NAMESPACE_TOPSIDE_END
