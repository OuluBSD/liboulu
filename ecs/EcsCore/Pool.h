#ifndef _EcsCore_Pool_h_
#define _EcsCore_Pool_h_


NAMESPACE_OULU_BEGIN

class Pool;



class Pool :
	public RefScopeEnabler<Pool,EntityStore,RefParent2<EntityStore, Pool>>
{
	Machine*			machine = 0;
	Pool*				parent = 0;
	BitField<dword>		freeze_bits;
	String				name;
	
	
public:
	typedef Pool CLASSNAME;
	
	Pool();
	~Pool();
	
	typedef enum {
		BIT_OVERLAP,
		BIT_TRANSFORM,
	} Bit;
	
	
	static EntityId GetNextId();
	
	void SetMachine(Machine& m)		{machine = &m;}
	void SetName(String s)			{name = s;}
	void FreezeTransform()			{freeze_bits.Set(BIT_TRANSFORM, true);}
	void FreezeOverlap()			{freeze_bits.Set(BIT_OVERLAP, true);}
	bool IsFrozenTransform() const	{return freeze_bits.Is(BIT_TRANSFORM);}
	bool IsFrozenOverlap() const	{return freeze_bits.Is(BIT_OVERLAP);}
	
	void				ReverseEntities();
	void				Clear();
	void				UnlinkDeep();
	void				UninitializeComponentsDeep();
	void				ClearComponentsDeep();
	void				ClearDeep();
	void				PruneFromContainer();
	
	Pool*			GetParent() const {return parent;}
	Machine&			GetMachine() {return *machine;}
	String				GetName() const {return name;}
	bool				HasEntities() const {return !objects.IsEmpty();}
	bool				HasPools() const {return !pools.IsEmpty();}
	
	void				Initialize(Entity& e, String prefab="Custom");
	EntityRef			CreateEmpty();
	EntityRef			Clone(const Entity& e);
	
	template<typename PrefabT>
	EntityRef Create() {
		static_assert(RTupleAllComponents<typename PrefabT::Components>::value, "Prefab should have a list of Components");
		
		EntityRef e = objects.Add();
		e->Init(this, GetNextId());
		PrefabT::Make(*e);
		Initialize(*e, TypeId(typeid(PrefabT)).CleanDemangledName());
		
		return e;
	}
	
	template<typename... ComponentTs>
	Vector < RTuple < Entity*, ComponentTs*... >> GetComponentsWithEntity() {
		static_assert(sizeof...(ComponentTs) > 0, "Need at least one component");
		static_assert(AllComponents<ComponentTs...>::value, "Ts should all derive from Component");
		
		Vector < RTuple < Entity*, ComponentTs*... >> components;
		
		for (EntityRef object : objects) {
			auto requested_components = object->TryGetComponents<ComponentTs...>();
			
			if (AllValidComponents(requested_components)) {
				RTuple<Entity*, ComponentTs*...> t(object.Get(), requested_components);
				components.Add(t);
				//components.Add(TupleCat(Tuple(object.Get()), Pick(requested_components)));
			}
		}
		
		return components;
	}
	
	template<typename... ComponentTs>
	Vector < RTuple < ComponentTs*... >> GetComponents() {
		static_assert(sizeof...(ComponentTs) > 0, "Need at least one component");
		static_assert(AllComponents<ComponentTs...>::value, "Ts should all derive from Component");
		
		Vector < RTuple < ComponentTs*... >> components;
		
		for (EntityRef object : objects) {
			auto requested_components = object->TryGetComponents<ComponentTs...>();
			
			if (AllValidComponents(requested_components)) {
				components.Add(requested_components);
			}
		}
		
		return components;
	}
	
	template <class T>
	Entity* FindEntity(T* component) {
		if (!component)
			return 0;
		for (EntityRef object : objects) {
			T* t = object->Find<T>();
			if (t == component)
				return object.Get();
		}
		return 0;
	}
	
	EntityRef FindEntityByName(String name) {
		for (EntityRef object : objects)
			if (object->GetName() == name)
				return object;
		return EntityRef();
	}
	
	/*void ReleaseEntity(Entity& ent) {
		for (int i = 0; i < objects.GetCount(); i++) {
			if (objects[i].Get() == &ent)
				objects.Remove(i--);
		}
	}*/
	
	template<typename Tuple>
	bool AllValidComponents(const Tuple& components) {
		bool all_valid_components = true;
		components.ForEach([&](auto* component) {
			all_valid_components &= component != nullptr && !component->IsDestroyed() && component->IsEnabled();
		});
		return all_valid_components;
	}
	
	EntityVec& GetEntities() {return objects;}
	PoolVec& GetPools() {return pools;}
	
	PoolRef AddPool(String name="") {
		PoolRef p = pools.Add();
		p->SetMachine(*machine);
		p->parent = this;
		p->SetName(name);
		return p;
	}
	
	PoolRef GetAddPool(String name) {
		for (PoolRef& pool : pools)
			if (pool->GetName() == name)
				return pool;
		return AddPool(name);
	}
	
	EntityVec::Iterator			begin()			{return objects.begin();}
	EntityVec::Iterator			end()			{return objects.end();}
	PoolVec::Iterator			BeginPool()		{return pools.begin();}
	
	
	
	
	template<typename T>
	void Remove() {
		comps.Remove<T>(GetMachine().Get<ConnectorStore>());
	}
	
	template<typename T>
	RefT_Pool<T> Add() {
		T* comp = GetMachine().Get<ConnectorStore>()->CreateComponent<T>();
		ASSERT(comp);
		comps.Add(comp);
		InitializeComponent(*comp);
		return RefT_Pool<T>(this, comp);
	}
	
private:
	ConnectorMap			comps;
	EntityVec				objects;
	PoolVec					pools;
	
	void InitializeComponent(ConnectorBase& comp);
	
};


NAMESPACE_OULU_END

#endif
