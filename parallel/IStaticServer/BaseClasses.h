// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.30 15:00:33

#ifndef _IStaticServer_BaseClasses_h_
#define _IStaticServer_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct SvtServerInstance : public Atom {
	RTTI_DECL1(SvtServerInstance, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~SvtServerInstance() {}

};

NAMESPACE_PARALLEL_END



#endif

