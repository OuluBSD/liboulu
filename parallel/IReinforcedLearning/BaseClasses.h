// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.3 22:44:00

#ifndef _IReinforcedLearning_BaseClasses_h_
#define _IReinforcedLearning_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct RlSystem : public Atom {
	RTTI_DECL1(RlSystem, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~RlSystem() {}

};

NAMESPACE_PARALLEL_END



#endif

