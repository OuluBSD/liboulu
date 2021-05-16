#ifndef _EcsCore_EntityVisitor_h_
#define _EcsCore_EntityVisitor_h_


NAMESPACE_TOPSIDE_BEGIN


class EntityVisitor {
	struct Item : Moveable<Item> {
		int pool_pos;
		PoolVec::Iterator pool;
		EntityVec::Iterator ent;
		bool finished = false;
	};
	
	PoolVec& base;
	BitField<dword> freeze_checks;
	Vector<Item> stack;
	EntityRef cur;
	int mode;
	
protected:
	bool FindNextDepthFirst();
	bool NewPoolNextDepthFirst();
	void PoolIncPopWhileTop();
	void PoolPushSub();
	bool PoolFindNextDepthFirst();
public:
	enum {
		POOL_CURRENT_AND_CHILDREN,
		POOL_CURRENT_ONLY,
		POOL_CHILDREN_ONLY
	};
	
	EntityVisitor(PoolVec& pool, int mode=POOL_CURRENT_AND_CHILDREN);
	EntityVisitor(Machine& m, int mode=POOL_CURRENT_AND_CHILDREN);
	EntityVisitor(Entity& e, int mode=POOL_CURRENT_AND_CHILDREN);
	
	void Reset();
	void Skip(Pool::Bit entpool_bit);
	EntityRef GetCurrent() const {return cur;}
	
	Entity* operator->();
	EntityRef operator*();
	operator bool() const;
	void operator++(int);
	
};


class EntityDummyVisitor {
	Entity& e;
	bool once = true;
public:
	EntityDummyVisitor(Entity& e) : e(e) {}
	void Reset() {once = true;}
	Entity* GetCurrent() const {return &e;}
	Entity* operator->() {return once ? &e : 0;}
	Entity* operator*() {return once ? &e : 0;}
	operator bool() const {return once;}
	void operator++(int) {once = false;}
};

class EntityParentVisitor {
	Pool& base;
	BitField<dword> freeze_checks;
	Pool* cur_pool;
	EntityVec::Iterator cur;
	
	bool FindNextChildFirst();
	
public:
	EntityParentVisitor(Entity& e);
	EntityParentVisitor(Pool& pool);
	
	void Reset();
	void Skip(Pool::Bit entpool_bit);
	EntityRef GetCurrent() const {return *cur;}
	
	Entity* operator->();
	EntityRef operator*();
	operator bool() const;
	void operator++(int);
	
};

class EntityChildrenVisitor : public EntityVisitor {
	
public:
	EntityChildrenVisitor(PoolVec& pool)	: EntityVisitor(pool, POOL_CHILDREN_ONLY) {}
	EntityChildrenVisitor(Machine& m)			: EntityVisitor(m, POOL_CHILDREN_ONLY) {}
	EntityChildrenVisitor(Entity& e)			: EntityVisitor(e, POOL_CHILDREN_ONLY) {}
	
};

class EntityCurrentVisitor : public EntityVisitor {
	
public:
	EntityCurrentVisitor(PoolVec& pool)	: EntityVisitor(pool, POOL_CURRENT_ONLY) {}
	EntityCurrentVisitor(Machine& m)			: EntityVisitor(m, POOL_CURRENT_ONLY) {}
	EntityCurrentVisitor(Entity& e)				: EntityVisitor(e, POOL_CURRENT_ONLY) {}
	
};


template<typename... ComponentTs>
class EntityComponentVisitor : public EntityVisitor {
	RTuple<Ref<ComponentTs>...> cur_comps;
	
	bool FindComps() {
		Entity& e = *GetCurrent();
		cur_comps = e.TryGetComponents<ComponentTs...>();
		bool has_value = true;
		cur_comps.ForEach([&has_value](auto& ref){if (!ref) has_value = false;});
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
	EntityComponentVisitor(PoolVec& pool) : EntityVisitor(pool) {Init();}
	EntityComponentVisitor(Machine& m) : EntityVisitor(m) {Init();}
	
	
	template<typename ComponentT> ComponentT* Get() {return cur_comps.template Find<ComponentT>();}
	
	void operator++(int) {FindNextDepthFirstWithComps();}
	
};


NAMESPACE_TOPSIDE_END


#endif
