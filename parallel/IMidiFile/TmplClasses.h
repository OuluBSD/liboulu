// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 29.3.29 19:55:44

#ifndef _IMidiFile_TmplClasses_h_
#define _IMidiFile_TmplClasses_h_

NAMESPACE_PARALLEL_BEGIN

template <class Mif> struct MidiFileMidiFileT;


template <class Mif>
struct MidiFileMidiFileT : MifMidiFile {
	typename Mif::NativeMidiFile file;
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!Mif::MidiFile_Initialize(file, *this, ws))
			return false;
		return true;
	}

	void Uninitialize() override {
		Mif::MidiFile_Uninitialize(file);
	}

	bool ProcessPacket(PacketValue& v) override {
		if (!Mif::MidiFile_ProcessPacket(file, v))
			return false;
		return true;
	}

	bool CreateMidiFile() {
		return Mif::MidiFile_CreateMidiFile(this->file);
	}
	
	void ClearMidiFile() {
		Mif::MidiFile_ClearMidiFile(this->file);
	}
	
	
};



NAMESPACE_PARALLEL_END



#endif

