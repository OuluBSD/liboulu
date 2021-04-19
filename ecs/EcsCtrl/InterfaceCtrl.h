#ifndef _EcsCtrl_InterfaceCtrl_h_
#define _EcsCtrl_InterfaceCtrl_h_


NAMESPACE_OULU_BEGIN


class InterfaceCtrl : public ParentCtrl {
	
	
public:
	typedef InterfaceCtrl CLASSNAME;
	InterfaceCtrl() {}
	
	virtual void SetInterface(ComponentBase& c, InterfaceBase& b) = 0;
	
};

typedef InterfaceCtrl*(*InterfaceCtrlFactory)();
typedef VectorMap<TypeId, InterfaceCtrlFactory> InterfaceCtrlFactoryMap;

void RegisterInterfaceCtrlFactory(TypeId iface, InterfaceCtrlFactory fac);
InterfaceCtrl* NewInterfaceCtrl(TypeId iface);

template <class T> InterfaceCtrl* InterfaceCtrlFactoryFn() {return new T();}
template <class I, class C> void MakeInterfaceCtrlFactory() {
	RegisterInterfaceCtrlFactory(typeid(I), &InterfaceCtrlFactoryFn<C>);
}

NAMESPACE_OULU_END

#endif
