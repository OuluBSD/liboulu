#include "EcsCore.h"

NAMESPACE_TOPSIDE_BEGIN


Entity::Entity() {
	DBG_CONSTRUCT
}

Entity::~Entity() {
	Destroy();
	DBG_DESTRUCT
}

EntityId Entity::GetNextId() {
	static Atomic64 next_id;
	return ++next_id;
}

void Entity::OnChange() {
	changed = GetMachine().GetTicks();
}

void Entity::InitializeComponents() {
	for(auto& comp : comps.GetValues())
		InitializeComponent(*comp);
}

void Entity::InitializeComponent(ComponentBase& comp) {
	comp.Initialize();
}

void Entity::UninitializeComponents() {
	auto& comps = this->comps.GetValues();
	int dbg_i = 0;
	for (auto it = comps.rbegin(); it != comps.rend(); --it) {
		it().Uninitialize();
		dbg_i++;
	}
}

void Entity::ClearComponents() {
	ComponentStoreRef sys = GetMachine().Get<ComponentStore>();
	for (auto iter = comps.rbegin(); iter; --iter)
		sys->ReturnComponent(comps.Detach(iter));
	ASSERT(comps.IsEmpty());
}

EntityRef Entity::Clone() const {
	EntityRef ent = GetPool().Clone(*this);
	ent->InitializeComponents();
	return ent;
}

void Entity::Destroy() {
	Destroyable::Destroy();
	
	for (auto& component : comps.GetValues()) {
		component->Destroy();
	}
}

void Entity::SetEnabled(bool enable) {
	Enableable::SetEnabled(enable);
	
	for (auto& component : comps.GetValues()) {
		component->SetEnabled(enable);
	}
}

Machine& Entity::GetMachine() {
	return GetPool().GetMachine();
}

const Machine& Entity::GetMachine() const {
	return GetPool().GetMachine();
}

Pool& Entity::GetPool() const {
	Pool* p = RefScopeParent<EntityParent>::GetParent().o;
	ASSERT(p);
	return *p;
}

void Entity::VisitSinks(RuntimeVisitor& vis) {
	for(ComponentBaseRef& c : comps)
		c->VisitSinks(vis);
}

void Entity::VisitSources(RuntimeVisitor& vis){
	for(ComponentBaseRef& c : comps)
		c->VisitSources(vis);
}

int Entity::GetPoolDepth() const {
	int d = 0;
	Pool* p = &GetPool();
	while (1) {
		p = p->GetParent();
		if (!p) break;
		++d;
	}
	return d;
}

bool Entity::HasPoolParent(PoolRef pool) const {
	Pool* p = &GetPool();
	while (p) {
		if (p == &*pool)
			return true;
		p = p->GetParent();
	}
	return false;
}






bool EntityHashVisitor::OnEntry(TypeId type, void* mem, LockedScopeRefCounter* ref) {
	if (type == AsTypeCls<Entity>()) {
		Entity& e = *(Entity*)mem;
		ch.Put(1);
		ch.Put(e.GetId());
	}
	else if (type == AsTypeCls<Pool>()) {
		Pool& p = *(Pool*)mem;
		ch.Put(2);
		ch.Put(p.GetId());
	}
	return true;
}


NAMESPACE_TOPSIDE_END
