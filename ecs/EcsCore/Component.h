#ifndef _EcsCore_Component_h_
#define _EcsCore_Component_h_

NAMESPACE_ECS_BEGIN


class ComponentBase;


class ComponentExtBase :
	RTTIBase,
	public RefScopeEnabler<ComponentExtBase, ComponentBase>
{
protected:
	
public:
	RTTI_DECL0(ComponentExtBase)
	
	virtual void Initialize() {}
	virtual void Uninitialize() {}
	virtual void Visit(RuntimeVisitor& vis) = 0;
	virtual void Forward(FwdScope& fwd) = 0;
	
	Ref<ComponentExtBase> AsRefT() {return Ref<ComponentExtBase>(GetParent(), this);}
	
};

using ComponentExtBaseRef = Ref<ComponentExtBase, RefParent1<ComponentBase>>;




template <class T> inline RefT_Entity<T> ComponentBase_Static_As(ComponentBase*) {return RefT_Entity<T>();}

class ComponentBase :
	public Destroyable,
	public Enableable,
	virtual public PacketForwarder,
	public RefScopeEnabler<ComponentBase,Entity>
{
protected:
	friend class Entity;
	
public:
	virtual EcsTypeCls GetType() const = 0;
	virtual void SetType(const TypeCompCls& cls) = 0;
	virtual void CopyTo(ComponentBase* component) const = 0;
	virtual void Visit(RuntimeVisitor& vis) = 0;
	virtual void VisitSource(RuntimeVisitor& vis) = 0;
	virtual void VisitSink(RuntimeVisitor& vis) = 0;
	virtual void ClearSinkSource() = 0;
	virtual InterfaceSourceRef GetSource() = 0;
	virtual InterfaceSinkRef GetSink() = 0;
	virtual void Initialize() {};
	virtual void Uninitialize() {};
	virtual String ToString() const;
	virtual bool SetExtension(ComponentExtBase* ext) {return false;}
	virtual void ClearExtension() {}
	virtual ComponentExtBaseRef GetExtension() {return ComponentExtBaseRef();}
	
	ValCls GetValSpec() const {return GetType().val;}
	bool IsValSpec(ValCls t) const {return t == GetType().val;}
	
	ComponentExtBaseRef SetExtensionTypeCls(EcsTypeCls ext);
	
	static bool AllowDuplicates() {return false;}
	
	Machine& GetMachine();
	void UninitializeWithExt();
	
	
public:
	RTTI_DECL_R3(ComponentBase, Destroyable, Enableable, PacketForwarder)
	ComponentBase();
	virtual ~ComponentBase();
	
	EntityRef GetEntity();
	
	//InterfaceSourceRef FindSource(ValDevCls t);
	//InterfaceSinkRef FindSink(ValDevCls t);
	
	template <class T> RefT_Entity<T> As() {return ComponentBase_Static_As<T>(this);}
	
	/*#define IFACE(x) \
	RefT_Entity<x##Source> As##x##Source() {return As<x##Source>();} \
	RefT_Entity<x##Sink>   As##x##Sink()   {return As<x##Sink>();}
	IFACE_LIST
	#undef IFACE*/
	RefT_Entity<ValSource>	AsSource();
	RefT_Entity<ValSink>	AsSink();
	
	
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
	
	
	template <class ValDevSpec, class T> bool LinkManually(T& o, String* err_msg=0);
	
};




template<typename T, typename Ext>
struct Component :
	public ComponentBase,
	public ValSink,
	public ValSource
{
	using ComponentT = Component<T,Ext>;
	
	RTTI_DECL3(ComponentT, ComponentBase, ValSink, ValSource)
	void Visit(RuntimeVisitor& vis) override {
		vis.VisitThis<ValSink>(this);
		vis.VisitThis<ValSource>(this);
		if (ext) vis % *ext;
	}
	
	
	EcsTypeCls GetType() const override {return AsEcsTypeCls<T>(vd);}
	void SetType(const TypeCompCls& cls) override {ValSink::iface = cls.sink; vd = cls.side; ValSource::iface = cls.src;}
	
	void CopyTo(ComponentBase* target) const override {
		ASSERT(target->GetType() == GetType());
	    
		*static_cast<T*>(target) = *static_cast<const T*>(this);
	}
	void VisitSource(RuntimeVisitor& vis) override {vis.VisitThis<ValSource>(this);}
	void VisitSink(RuntimeVisitor& vis) override {vis.VisitThis<ValSink>(this);}
	
private:
	void ClearSinkSource() override {
		ValSink::ClearSink();
		ValSource::ClearSource();
	}
protected:
	One<Ext>	ext;
	EcsTypeCls	vd;
	
public:
	~Component() {ASSERT(ext.IsEmpty());}
	
	bool SetExtension(ComponentExtBase* c) override {
		ext.Clear();
		Ext* o = CastPtr<Ext>(c);
		ASSERT(o);
		if (!o)
			return false;
		ext = o;
		c->SetParent(this);
		c->Initialize();
		return true;
	}
	
	void ClearExtension() override {
		if (ext) {
			ext->Uninitialize();
			ext.Clear();
		}
	}
	
	ComponentExtBaseRef GetExtension() override {
		return ext ? ext->template AsRef<ComponentExtBase>() : ComponentExtBaseRef();
	}
	
	
	InterfaceSourceRef GetSource() override {return InterfaceSourceRef(GetParentUnsafe(), (InterfaceSource*)this);}
	InterfaceSinkRef GetSink() override {return InterfaceSinkRef(GetParentUnsafe(), (InterfaceSink*)this);}
	
};

#define COMP_RTTI(x)  RTTI_DECL1(x, Component<x>)

using ComponentMapBase	= RefEcsTypeMapIndirect<ComponentBase>;
using ComponentRefMap	= ArrayMap<EcsTypeCls,Ref<ComponentBase>>;

class ComponentMap : public ComponentMapBase {
	
	void ReturnComponent(ComponentStore& s, ComponentBase* c);
	
public:
	
	ComponentMap() {}
	
	#define IS_EMPTY_SHAREDPTR(x) (x.IsEmpty())
	
	void Dump();
	
	template<typename ComponentT>
	RefT_Entity<ComponentT> Get() {
		CXX2A_STATIC_ASSERT(ComponentStore::IsComponent<ComponentT>::value, "T should derive from Component");
		
		ComponentMapBase::Iterator it = ComponentMapBase::Find(AsEcsTypeCls<ComponentT>());
		ASSERT(!IS_EMPTY_SHAREDPTR(it));
		if (it.IsEmpty())
			THROW(Exc("Could not find component " + AsTypeString<ComponentT>()));
		
		return it->AsRef<ComponentT>();
	}
	
	template<typename ComponentT>
	RefT_Entity<ComponentT> Find() {
		CXX2A_STATIC_ASSERT(ComponentStore::IsComponent<ComponentT>::value, "T should derive from Component");
		
		ComponentMapBase::Iterator it = ComponentMapBase::Find(AsEcsTypeCls<ComponentT>());
		if (IS_EMPTY_SHAREDPTR(it))
			return Null;
		else
			return it->AsRef<ComponentT>();
	}
	
	template<typename ComponentT>
	void Add(ComponentT* component) {
		CXX2A_STATIC_ASSERT(ComponentStore::IsComponent<ComponentT>::value, "T should derive from Component");
		
		EcsTypeCls type = component->GetType();
		ASSERT(type.IsValid());
		ComponentMapBase::Iterator it = ComponentMapBase::Find(type);
		ASSERT_(IS_EMPTY_SHAREDPTR(it) || ComponentT::AllowDuplicates(), "Cannot have duplicate componnets");
		ComponentMapBase::Add(type, component);
	}
	
	template<typename ComponentT>
	void Remove(ComponentStoreRef s) {
		CXX2A_STATIC_ASSERT(ComponentStore::IsComponent<ComponentT>::value, "T should derive from Component");
		
		ComponentMapBase::Iterator iter = ComponentMapBase::Find(AsEcsTypeCls<ComponentT>());
		ASSERT_(iter, "Tried to remove non-existent component");
		
		iter.value().UninitializeWithExt();
		iter.value().Destroy();
		
		ReturnComponent(*s, iter.value.GetItem()->value.Detach());
		ComponentMapBase::Remove(iter);
	}
	
	void AddBase(ComponentBase* component) {
		CXX2A_STATIC_ASSERT(ComponentStore::IsComponent<ComponentT>::value, "T should derive from Component");
		EcsTypeCls type = component->GetType();
		ComponentMapBase::Iterator it = ComponentMapBase::Find(type);
		ComponentMapBase::Add(type, component);
	}
	
	#undef IS_EMPTY_SHAREDPTR
	
};


NAMESPACE_ECS_END

#endif
