// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.30 15:00:33

#ifndef _IFinance_BaseClasses_h_
#define _IFinance_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct FinSystem : public Atom {
	RTTI_DECL1(FinSystem, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~FinSystem() {}

};

NAMESPACE_PARALLEL_END



#endif

