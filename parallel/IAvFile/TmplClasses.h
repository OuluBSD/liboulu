// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.31 23:44:55

#ifndef _IAvFile_TmplClasses_h_
#define _IAvFile_TmplClasses_h_

NAMESPACE_PARALLEL_BEGIN

template <class AV> struct AvFileAVFileT;


template <class AV>
struct AvFileAVFileT : AVAVFile {
	using CLASSNAME = AvFileAVFileT<AV>;
	RTTI_DECL1(CLASSNAME, AVAVFile)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<AVAVFile>(this);}
	
	typename AV::NativeAVFile file;
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!AV::AVFile_Initialize(file, *this, ws))
			return false;
		return true;
	}

	bool PostInitialize() override {
		if (!AV::AVFile_PostInitialize(file))
			return false;
		return true;
	}

	bool Start() override {
		return AV::AVFile_Start(file);
	}

	void Stop() override {
		AV::AVFile_Stop(file);
	}

	void Uninitialize() override {
		AV::AVFile_Uninitialize(file);
	}

	bool ProcessPacket(PacketValue& v) override {
		if (!AV::AVFile_ProcessPacket(file, v))
			return false;
		return true;
	}

	bool CreateAVFile() {
		return AV::AVFile_CreateAVFile(this->file);
	}
	
	void ClearAVFile() {
		AV::AVFile_ClearAVFile(this->file);
	}
	
	
};


NAMESPACE_PARALLEL_END



#endif

