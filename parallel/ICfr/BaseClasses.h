// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.7 0:44:33

#ifndef _ICfr_BaseClasses_h_
#define _ICfr_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct CfrSystem : public Atom {
	RTTI_DECL1(CfrSystem, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~CfrSystem() {}

};

NAMESPACE_PARALLEL_END



#endif

