#ifndef _EcsCore_EntityStore_h_
#define _EcsCore_EntityStore_h_


NAMESPACE_TOPSIDE_BEGIN


class EntityStore : public System<EntityStore> {
	PoolVec							root;
	
	LinkedList<ConnectorBase*>		refresh_poolcomps[2];
	Mutex							lock;
	
	void Visit(RuntimeVisitor& vis) override {
		vis || root;
	}
	enum {
		READ,
		WRITE
	};
	
	void InitRoot();
public:
	EntityStore(Machine& m) : RefScopeParent<RefParent1<Machine>>(m) {InitRoot();}
	
	PoolRef GetRoot()	{return *root.begin();}
	PoolVec& GetRootVec()	{return root;}
	
	
	int64 PostRefresh(int64 last_refresh, ConnectorBase* comp);
	
protected:
	void Update(double) override;
	bool Initialize() override;
	void Uninitialize() override;
	
	
};


NAMESPACE_TOPSIDE_END


#endif
