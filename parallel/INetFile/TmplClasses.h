// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.30 15:00:33

#ifndef _INetFile_TmplClasses_h_
#define _INetFile_TmplClasses_h_

NAMESPACE_PARALLEL_BEGIN

template <class Nef> struct NetFileNetFileT;


template <class Nef>
struct NetFileNetFileT : NefNetFile {
	using CLASSNAME = NetFileNetFileT<Nef>;
	RTTI_DECL1(CLASSNAME, NefNetFile)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<NefNetFile>(this);}
	
	
	bool Initialize(const Script::WorldState& ws) override {
		return true;
	}

	void Uninitialize() override {
	}

	bool ProcessPacket(PacketValue& v) override {
		return true;
	}

	
};


NAMESPACE_PARALLEL_END



#endif

