#ifndef _EcsCore_EntityStore_h_
#define _EcsCore_EntityStore_h_


NAMESPACE_OULU_BEGIN



class EntityPool {
	Machine& machine;
	EntityPool* parent = 0;
	BitField<dword> freeze_bits;
	String name;
	
	SharedEntity CreateFromComponentMap(ComponentMap components);
	
public:
	typedef EntityPool CLASSNAME;
	EntityPool(Machine& m);
	
	typedef enum {
		BIT_CONNECTOR,
		BIT_CONNECTOR3D,
		BIT_TRANSFORM,
	} Bit;
	
	
	static Entity::EntityId GetNextId();
	
	void SetName(String s) {name = s;}
	void FreezeConnector() {freeze_bits.Set(BIT_CONNECTOR, true);}
	void FreezeOverlap() {freeze_bits.Set(BIT_CONNECTOR3D, true);}
	bool IsFrozenConnector() const {return freeze_bits.Is(BIT_CONNECTOR);}
	bool IsFrozenOverlap() const {return freeze_bits.Is(BIT_CONNECTOR3D);}
	
	void				Clear();
	void				PruneFromContainer();
	
	EntityPool*			GetParent() const {return parent;}
	Machine&			GetMachine() {return machine;}
	int					GetPoolCount() const {return pools.GetCount();}
	EntityPool&			GetPool(int i) {return pools[i];}
	const EntityPool&	GetPool(int i) const {return pools[i];}
	int					GetCount() const {return objects.GetCount();}
	SharedEntity&		Get(int i) {return objects[i];}
	const SharedEntity&	Get(int i) const {return objects[i];}
	
	void				Initialize(Entity& e, String prefab="Custom");
	SharedEntity		CreateEmpty();
	SharedEntity		Clone(const Entity& e);
	
	template<typename PrefabT>
	SharedEntity Create() {
		static_assert(RTupleAllComponents<typename PrefabT::Components>::value, "Prefab should have a list of Components");
		
		SharedEntity e = CreateFromComponentMap(PrefabT::Make(*machine.Get<ComponentStore>()));
		if (e)
			Initialize(*e, TypeId(typeid(PrefabT)).CleanDemangledName());
		
		return e;
	}
	
	template<typename PrefabT>
	SharedEntity CreateConnected() {
		static_assert(RTupleAllComponents<typename PrefabT::Components>::value, "Prefab should have a list of Components");
		
		SharedEntity e = CreateFromComponentMap(PrefabT::Make(*machine.Get<ComponentStore>()));
		if (e)
			Initialize(*e, TypeId(typeid(PrefabT)).CleanDemangledName());
		
		return e;
	}
	
	template<typename... ComponentTs>
	Vector < RTuple < Entity*, ComponentTs*... >> GetComponentsWithEntity() {
		static_assert(sizeof...(ComponentTs) > 0, "Need at least one component");
		static_assert(AllComponents<ComponentTs...>::value, "Ts should all derive from Component");
		
		Vector < RTuple < Entity*, ComponentTs*... >> components;
		
		for (auto& object : objects) {
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
		
		for (auto& object : objects) {
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
		for (auto& object : objects) {
			T* t = object->Find<T>();
			if (t == component)
				return object.Get();
		}
		return 0;
	}
	
	void ReleaseEntity(Entity& ent) {
		for (int i = 0; i < objects.GetCount(); i++) {
			if (objects[i].Get() == &ent)
				objects.Remove(i--);
		}
	}
	
	template<typename Tuple>
	bool AllValidComponents(const Tuple& components) {
		bool all_valid_components = true;
		components.ForEach([&](auto* component) {
			all_valid_components &= component != nullptr && !component->IsDestroyed() && component->IsEnabled();
		});
		return all_valid_components;
	}
	
	Vector<SharedEntity>& GetEntities() {return objects;}
	
	EntityPool& AddPool(String name="") {
		EntityPool& p = pools.Add(new EntityPool(machine));
		p.parent = this;
		p.SetName(name);
		return p;
	}
	
private:
	
	Vector<SharedEntity>	objects;
	Array<EntityPool>		pools;
	
	SharedEntity AddEntity(SharedEntity obj);
	
};


class EntityVisitor {
	struct Item : Moveable<Item> {
		int pool_pos;
		EntityPool* pool;
		int ent_pos;
		Entity* ent;
	};
	
	EntityPool& base;
	BitField<dword> freeze_checks;
	Vector<Item> stack;
	Entity* cur = 0;
	
protected:
	bool FindNextDepthFirst();
	bool NewPoolNextDepthFirst();
	void PoolIncPopWhileTop();
	void PoolPushSub(int pos);
	bool PoolFindNextDepthFirst();
public:
	EntityVisitor(EntityPool& pool);
	EntityVisitor(Machine& m);
	
	void Reset();
	void Skip(EntityPool::Bit entpool_bit);
	Entity* GetCurrent() const {return cur;}
	
	Entity* operator->();
	Entity* operator*();
	operator bool() const;
	void operator++(int);
	
};


class EntityParentVisitor {
	EntityPool& base;
	BitField<dword> freeze_checks;
	EntityPool* cur_pool;
	int ent_pos = -1;
	Entity* cur = 0;
	
	bool FindNextChildFirst();
	
public:
	EntityParentVisitor(EntityPool& pool);
	
	void Reset();
	void Skip(EntityPool::Bit entpool_bit);
	Entity* GetCurrent() const {return cur;}
	
	Entity* operator->();
	Entity* operator*();
	operator bool() const;
	void operator++(int);
	
};


template<typename... ComponentTs>
class EntityComponentVisitor : public EntityVisitor {
	RTuple<ComponentTs*...> cur_comps;
	
	bool FindComps() {
		Entity& e = *GetCurrent();
		cur_comps = e.TryGetComponents<ComponentTs...>();
		bool has_value = true;
		cur_comps.ForEach([&has_value](void* ptr){if (!ptr) has_value = false;});
		return has_value;
	}
	bool FindNextDepthFirstWithComps() {
		while (FindNextDepthFirst()) {
			if (FindComps())
				return true;
		}
		return false;
	}
	
	void Init() {
		if (!FindComps())
			FindNextDepthFirstWithComps();
	}
public:
	EntityComponentVisitor(EntityPool& pool) : EntityVisitor(pool) {Init();}
	EntityComponentVisitor(Machine& m) : EntityVisitor(m) {Init();}
	
	
	template<typename ComponentT> ComponentT* Get() {return cur_comps.template Find<ComponentT>();}
	
	void operator++(int) {FindNextDepthFirstWithComps();}
	
};


class EntityStore : public System<EntityStore> {
	EntityPool			root;
	
public:
	using System::System;
	
	EntityStore(Machine& m) : root(m), System<EntityStore>(m) {}
	
	EntityPool& GetRoot()	{return root;}
	
protected:
	void Update(float) override;
	bool Initialize() override;
	void Uninitialize() override;
	
	
};


NAMESPACE_OULU_END


#endif
