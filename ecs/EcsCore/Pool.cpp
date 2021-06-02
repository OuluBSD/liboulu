#include "EcsCore.h"


NAMESPACE_TOPSIDE_BEGIN


PoolRef GetConnectorBasePool(ConnectorBase* conn) {return conn->GetPool();}
Machine& GetPoolMachine(PoolRef pool) {return pool->GetMachine();}
//EntityStoreRef GetMachineEntityStore(Machine& m) {return m.Get<EntityStore>();}



Pool::Pool() {
	DBG_CONSTRUCT
}

Pool::~Pool() {
	DBG_DESTRUCT
}

PoolId Pool::GetNextId() {
	static Atomic64 next_id;
	return ++next_id;
}

Pool* Pool::GetParent() const {
	return RefScopeParent<PoolParent>::GetParent().b;
}

Machine& Pool::GetMachine() {
	if (machine)
		return *machine;
	Pool* p = this;
	int levels = 0;
	while (p && levels++ < 1000) {
		const PoolParent& par = p->RefScopeParent<PoolParent>::GetParent();
		if (par.a) {
			machine = &par.a->GetMachine();
			ASSERT(machine);
			return *machine;
		}
		ASSERT(p != par.b);
		p = par.b;
	}
	THROW(Exc("Machine ptr not found"));
}

void Pool::Initialize(Entity& e, String prefab) {
	uint64 ticks = GetMachine().GetTicks();
	e.SetPrefab(prefab);
	e.SetCreated(ticks);
	e.SetChanged(ticks);
	
}

EntityRef Pool::CreateEmpty() {
	Entity& e = objects.Add();
	e.SetParent(this);
	e.SetId(GetNextId());
	Initialize(e);
	return e;
}

EntityRef Pool::Clone(const Entity& c) {
	EntityRef e = CreateEmpty();
	e->CopyHeader(c);
	GetMachine().Get<ComponentStore>()->Clone(*e, c);
	return e;
}

void Pool::UnlinkDeep() {
	for (auto it = pools.rbegin(); it != pools.rend(); --it) {
		it().UnlinkDeep();
	}
	
	for (auto it = comps.rbegin(); it != comps.rend(); --it) {
		it().UnlinkAll();
	}
}

void Pool::UnrefDeep() {
	RefClearVisitor vis;
	vis.Visit(*this);
}

void Pool::UninitializeComponentsDeep() {
	for (PoolRef& p : pools)
		p->UninitializeComponentsDeep();
	
	for (auto it = objects.rbegin(); it != objects.rend(); --it) {
		it().UninitializeComponents();
	}
	
	for (auto it = comps.rbegin(); it != comps.rend(); --it) {
		it().Uninitialize();
	}
}

void Pool::ClearComponentsDeep() {
	for (PoolRef& p : pools)
		p->ClearComponentsDeep();
	
	for (auto it = objects.rbegin(); it != objects.rend(); --it) {
		it().ClearComponents();
	}
	
	if (!comps.IsEmpty()) {
		ConnectorStoreRef sys = GetMachine().Get<ConnectorStore>();
		for (auto iter = comps.rbegin(); iter; --iter)
			sys->ReturnComponent(comps.Detach(iter));
		ASSERT(comps.IsEmpty());
	}
}

void Pool::ClearDeep() {
	for (PoolRef& p : pools)
		p->ClearDeep();
	pools.Clear();
	
	objects.Clear();
}

void Pool::ReverseEntities() {
	objects.Reverse();
}

void Pool::Clear() {
	UnrefDeep();
	UnlinkDeep();
	UninitializeComponentsDeep();
	ClearComponentsDeep();
	ClearDeep();
}

void Pool::PruneFromContainer() {
	for (auto& pool : pools)
		pool->PruneFromContainer();
	Destroyable::PruneFromContainer(objects);
}

void Pool::InitializeComponent(ConnectorBase& comp) {
	comp.Initialize();
}

void Pool::AddConnectEverything() {
	Add<ConnectAllDevInterfaces<CenterSpec>>();
}

void Pool::ConnectEverything() {
	Find<ConnectAllDevInterfaces<CenterSpec>>()->Update();
}

void Pool::AddConnectEverythingWithAccel() {
	Add<ConnectAllDevInterfaces<CenterSpec>>();
	Add<ConnectAllDevInterfaces<AccelSpec>>();
}





bool PoolHashVisitor::OnEntry(const RTTI& type, void* mem, LockedScopeRefCounter* ref) {
	if (type == AsTypeCls<Pool>()) {
		Pool& p = *(Pool*)mem;
		ch.Put(p.GetId());
	}
	return true;
}






NAMESPACE_TOPSIDE_END
