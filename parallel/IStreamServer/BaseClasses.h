// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!

#ifndef _IStreamServer_BaseClasses_h_
#define _IStreamServer_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct SvrStreamServer : public Atom {
	RTTI_DECL1(SvrStreamServer, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~SvrStreamServer() {}

};

NAMESPACE_PARALLEL_END



#endif

