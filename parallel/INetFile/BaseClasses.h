// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.8 19:22:44

#ifndef _INetFile_BaseClasses_h_
#define _INetFile_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct NefNetFile : public Atom {
	RTTI_DECL1(NefNetFile, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~NefNetFile() {}

};

NAMESPACE_PARALLEL_END



#endif

