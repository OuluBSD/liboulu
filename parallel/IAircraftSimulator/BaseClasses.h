// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.6 0:00:44

#ifndef _IAircraftSimulator_BaseClasses_h_
#define _IAircraftSimulator_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct AsimSystem : public Atom {
	RTTI_DECL1(AsimSystem, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~AsimSystem() {}

};

NAMESPACE_PARALLEL_END



#endif

