// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.3 22:44:00

#ifndef _IHal_BaseClasses_h_
#define _IHal_BaseClasses_h_

NAMESPACE_PARALLEL_BEGIN

struct HalAudioSinkDevice : public Atom {
	RTTI_DECL1(HalAudioSinkDevice, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalAudioSinkDevice() {}

};

struct HalWindow : public Atom {
	RTTI_DECL1(HalWindow, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalWindow() {}

};

struct HalRenderer : public Atom {
	RTTI_DECL1(HalRenderer, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalRenderer() {}

};

struct HalCenterVideoSinkDevice : public Atom {
	RTTI_DECL1(HalCenterVideoSinkDevice, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalCenterVideoSinkDevice() {}

};

struct HalContextBase : public Atom {
	RTTI_DECL1(HalContextBase, Atom)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<Atom>(this);}
	
	virtual ~HalContextBase() {}

};

NAMESPACE_PARALLEL_END



#endif

