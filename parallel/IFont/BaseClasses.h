// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.31 14:22:11

#ifndef _IFont_BaseClasses_h_
#define _IFont_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct FntFont : public Atom {
	RTTI_DECL1(FntFont, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~FntFont() {}

};

NAMESPACE_PARALLEL_END



#endif

