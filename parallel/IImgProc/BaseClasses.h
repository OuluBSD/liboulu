// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.30 15:00:33

#ifndef _IImgProc_BaseClasses_h_
#define _IImgProc_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct ImpImage : public Atom {
	RTTI_DECL1(ImpImage, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~ImpImage() {}

};

NAMESPACE_PARALLEL_END



#endif

