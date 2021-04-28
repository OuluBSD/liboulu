#ifndef _EcsCore_EntityStore_h_
#define _EcsCore_EntityStore_h_


NAMESPACE_OULU_BEGIN


class EntityStore : public System<EntityStore> {
	EntityPoolVec					root;
	LinkedList<PoolComponentBase*>	refresh_poolcomps[2];
	Mutex							lock;
	
	enum {
		READ,
		WRITE
	};
public:
	using System::System;
	
	EntityStore(Machine& m) : System<EntityStore>(m) {
		root.Add()->SetMachine(machine);
	}
	
	EntityPoolRef GetRoot()	{return *root.begin();}
	EntityPoolVec& GetRootVec()	{return root;}
	
	
	int64 PostRefresh(int64 last_refresh, PoolComponentBase* comp);
	
protected:
	void Update(double) override;
	bool Initialize() override;
	void Uninitialize() override;
	
	
};

typedef Ref<EntityStore> EntityStoreRef;


NAMESPACE_OULU_END


#endif
