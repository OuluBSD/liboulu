#include "EcsCore.h"

NAMESPACE_OULU_BEGIN


Entity::Entity() {
	DBG_CONSTRUCT
}

Entity::~Entity() {
	Destroy();
	DBG_DESTRUCT
}

void Entity::OnChange() {
	changed = GetMachine().GetTicks();
}

void Entity::InitializeComponents() {
	for(auto& comp : comps.GetValues())
		InitializeComponent(*comp);
}

void Entity::InitializeComponent(ComponentBase& comp) {
	comp.ent = this;
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
	comps.Clear();
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



	
NAMESPACE_OULU_END
