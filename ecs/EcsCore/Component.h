#ifndef _EcsCore_Component_h_
#define _EcsCore_Component_h_

NAMESPACE_TOPSIDE_BEGIN



template <class T> inline RefT_Entity<T> ComponenBase_Static_As(ComponentBase*) {return RefT_Entity<T>();}

class ComponentBase :
	public Destroyable,
	public Enableable,
	public RefScopeEnabler<ComponentBase,Entity>
{
protected:
	friend class Entity;
	
public:
	virtual TypeId GetType() const = 0;
	virtual void CopyTo(ComponentBase* component) const = 0;
	virtual void Visit(RuntimeVisitor& vis) = 0;
	virtual void VisitSources(RuntimeVisitor& vis) = 0;
	virtual void VisitSinks(RuntimeVisitor& vis) = 0;
	virtual void Initialize() {};
	virtual void Uninitialize() {};
	virtual String ToString() const {return "<not implemented>";}
	
	static bool AllowDuplicates() {return false;}
	
	Machine& GetMachine();
	
public:
	RTTI_DECL_R2(ComponentBase, Destroyable, Enableable)
	ComponentBase();
	virtual ~ComponentBase();
	
	EntityRef GetEntity();
	
	template <class T> RefT_Entity<T> As() {return ComponenBase_Static_As<T>(this);}
	
	#define IFACE(x) \
	virtual RefT_Entity<x##Source> As##x##Source() {return Null;} \
	virtual RefT_Entity<x##Sink>   As##x##Sink()   {return Null;}
	IFACE_LIST
	#undef IFACE
	
	
	template <class S, class R>
	void AddToSystem(R ref) {
		Ref<S> sys = GetMachine().Get<S>();
		if (sys)
			sys->Add(ref);
	}
	
	template <class S, class R>
	void RemoveFromSystem(R ref) {
		Ref<S> sys = GetMachine().Get<S>();
		if (sys)
			sys->Remove(ref);
	}
	
	template <class Source, class T> bool LinkManually(T& o);
	
};

#define IFACE(x) \
template<> inline RefT_Entity<x##Source> ComponenBase_Static_As(ComponentBase* c) {return c->As##x##Source();} \
template<> inline RefT_Entity<x##Sink>   ComponenBase_Static_As(ComponentBase* c) {return c->As##x##Sink();}
IFACE_LIST
#undef IFACE


template<typename T>
struct Component :
	ComponentBase
{
	using ComponentT = Component<T>;
	
	RTTI_DECL1(ComponentT, ComponentBase)

	TypeId GetType() const override {
		return AsTypeCls<T>();
	}
	
	void CopyTo(ComponentBase* target) const override {
		ASSERT(target->GetType() == GetType());
	    
		*static_cast<T*>(target) = *static_cast<const T*>(this);
	}
};

#define COMP_RTTI(x)  RTTI_DECL1(x, Component<x>)

using ComponentMapBase	= RefTypeMapIndirect<ComponentBase>;
using ComponentRefMap	= ArrayMap<TypeId,Ref<ComponentBase>>;

class ComponentMap : public ComponentMapBase {
	
	void ReturnComponent(ComponentStore& s, ComponentBase* c);
	
public:
	
	ComponentMap() {}
	
	#define IS_EMPTY_SHAREDPTR(x) (x.IsEmpty())
	
	void Dump();
	
	template<typename ComponentT>
	RefT_Entity<ComponentT> Get() {
		CXX2A_STATIC_ASSERT(IsComponent<ComponentT>::value, "T should derive from Component");
		
		ComponentMapBase::Iterator it = ComponentMapBase::Find(AsTypeCls<ComponentT>());
		ASSERT(!IS_EMPTY_SHAREDPTR(it));
		if (it.IsEmpty())
			THROW(Exc("Could not find component " + AsTypeString<ComponentT>()));
		
		return it->AsRef<ComponentT>();
	}
	
	template<typename ComponentT>
	RefT_Entity<ComponentT> Find() {
		CXX2A_STATIC_ASSERT(IsComponent<ComponentT>::value, "T should derive from Component");
		
		ComponentMapBase::Iterator it = ComponentMapBase::Find(AsTypeCls<ComponentT>());
		if (IS_EMPTY_SHAREDPTR(it))
			return Null;
		else
			return it->AsRef<ComponentT>();
	}
	
	template<typename ComponentT>
	void Add(ComponentT* component) {
		CXX2A_STATIC_ASSERT(IsComponent<ComponentT>::value, "T should derive from Component");
		
		const TypeId type = AsTypeCls<ComponentT>();
		const TypeId actual_type = component->GetType();
		ASSERT_(actual_type == type, "ComponentRef type does not match " + AsTypeString<ComponentT>());
		
		ComponentMapBase::Iterator it = ComponentMapBase::Find(type);
		ASSERT_(IS_EMPTY_SHAREDPTR(it) || ComponentT::AllowDuplicates(), "Cannot have duplicate componnets");
		ComponentMapBase::Add(type, component);
	}
	
	template<typename ComponentT>
	void Remove(ComponentStoreRef s) {
		CXX2A_STATIC_ASSERT(IsComponent<ComponentT>::value, "T should derive from Component");
		
		ComponentMapBase::Iterator iter = ComponentMapBase::Find(AsTypeCls<ComponentT>());
		ASSERT_(iter, "Tried to remove non-existent component");
		
		iter.value().Uninitialize();
		iter.value().Destroy();
		
		ReturnComponent(*s, iter.value.GetItem()->value.Detach());
		ComponentMapBase::Remove(iter);
	}
	
	#undef IS_EMPTY_SHAREDPTR
	
};


NAMESPACE_TOPSIDE_END

#endif
