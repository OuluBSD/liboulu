// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!

#ifndef _IClassifier_TmplClasses_h_
#define _IClassifier_TmplClasses_h_

NAMESPACE_PARALLEL_BEGIN

template <class Cls> struct ClassifierSystemT;


template <class Cls>
struct ClassifierSystemT : ClsSystem {
	using CLASSNAME = ClassifierSystemT<Cls>;
	RTTI_DECL1(CLASSNAME, ClsSystem)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<ClsSystem>(this);}
	
	
	
	bool Initialize(const Script::WorldState& ws) override {
		return true;
	}

	bool PostInitialize() override {
		return true;
	}

	bool Start() override {
	}

	void Stop() override {
	}

	void Uninitialize() override {
	}

	bool ProcessPacket(PacketValue& in, PacketValue& out, int src_ch) override {
		return true;
	}

	
};


NAMESPACE_PARALLEL_END



#endif

