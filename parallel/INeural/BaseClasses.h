// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.3 11:11:55

#ifndef _INeural_BaseClasses_h_
#define _INeural_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct NrlNetwork : public Atom {
	RTTI_DECL1(NrlNetwork, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~NrlNetwork() {}

};

NAMESPACE_PARALLEL_END



#endif

