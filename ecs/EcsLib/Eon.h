#ifndef _EcsLib_Eon_h_
#define _EcsLib_Eon_h_

NAMESPACE_ECS_BEGIN


class EonLoader;



struct EonError : Moveable<EonError> {
	EonLoopLoader* ll = 0;
	String msg;
	int status = -1;
	
};






/*class EonScope {
protected:
	friend class EonLoader;
	friend class EonLoopLoader;
	
	Eon::WorldState			current_state;
	Eon::LoopDefinition*	loop = 0;
	Eon::ChainDefinition*	chain = 0;
	Eon::Machine*			mach = 0;
	Eon::GlobalScope*		glob = 0;
public:
	EonScope() {}
	
	void SetCurrentState(const Eon::WorldState& s) {current_state = s;}
	
	
};*/



class EonLoopSegment {
public:
	AStar<Eon::ActionNode>		as;
	Eon::Plan					ep;
	Eon::APlanNode*				start_node = 0;
	const Eon::ActionNode*		stop_node = 0;
	EonLoopLoader*				side_conn = 0;
	
	
	String GetTreeString(int id, int indent);
	
};

typedef enum {
	IN_BEGINNING,
	WAITING_SIDE_INPUT_LOOP,
	WAITING_SIDE_OUTPUT_LOOP,
	WAITING_SIDE_INPUT_CHAIN,
	WAITING_SIDE_OUTPUT_CHAIN,
	WAITING_SIDE_INPUT_MACHINE,
	WAITING_SIDE_OUTPUT_MACHINE,
	RETRY,
	SOLVE_INTERNAL_CONNECTIONS,
	READY,
	FAILED,
} EonStatus;


class EonSystemLoader;
class EonMachineLoader;
class EonChainLoader;
class EonLoader;

class EonLoopLoader : RTTIBase {
public:
	RTTI_DECL0(EonLoopLoader)
	
	
protected:
	friend class EonLoader;
	
	EonChainLoader&				parent;
	Eon::LoopDefinition&		def;
	int							id = -1;
	
	Eon::APlanNode				start_node;
	Eon::APlanNode				goal_node;
	Eon::WorldState				start;
	Eon::WorldState				goal;
	
	Array<EonLoopSegment>		segments;
	Eon::ActionPlanner			planner;
	EonStatus					status = IN_BEGINNING;
	const Eon::APlanNode*		accepted_side_node = 0;
	
	Array<ComponentBaseRef>		comps;
	
	
	void SetupSegment(EonLoopSegment& s);
	bool SetWorldState(Eon::WorldState& ws, const Eon::Statement& stmt);
	
public:
	EonLoopLoader(int id, EonChainLoader* loader, Eon::LoopDefinition& def);
	
	void		Visit(RuntimeVisitor& vis) {vis && comps;}
	void		Forward();
	void		InitSegments();
	void		ForwardTopSegment();
	
	
	bool Parse();
	bool Load();
	SideStatus AcceptOutput(EonLoopLoader& out, Eon::ActionPlanner::State*& accepted_in, Eon::ActionPlanner::State*& accepted_out);
	void AddError(String msg);
	void AddSideConnectionSegment(Eon::ActionPlanner::State* n, EonLoopLoader* c, Eon::ActionPlanner::State* side_state);
	void SetStatus(int s) {status = (EonStatus)s;}
	void SetStatusRetry() {status = RETRY;}
	
	bool IsFailed() const {return status == FAILED;}
	bool IsReady() const {return status == READY;}
	//bool IsWaitingSideInput() const {return status == WAITING_SIDE_INPUT;}
	//bool IsWaitingSideOutput() const {return status == WAITING_SIDE_OUTPUT;}
	//bool IsWaitingSide() const {return status == WAITING_SIDE_INPUT || status == WAITING_SIDE_OUTPUT;}
	EonLoopSegment& GetCurrentSegment() {return segments.Top();}
	int			GetId() const {return id;}
	EonStatus	GetStatus() const {return status;}
	bool		IsStatus(EonStatus s) const {return status == s;}
	
	EonLoader&	GetLoader();
	String		GetTreeString(int indent);
};


class EonChainLoader : RTTIBase {
public:
	RTTI_DECL0(EonChainLoader)
	
public:
	Array<EonLoopLoader>		loops;
	Array<EonChainLoader>		chains;
	EonMachineLoader&			mach_parent;
	EonChainLoader*				chain_parent;
	Eon::ChainDefinition&		chain;
	EonStatus					status = EonStatus::IN_BEGINNING;
	int							id = -1;
	
	
	EonChainLoader(EonMachineLoader& mach_parent, EonChainLoader* chain_parent, int id, Eon::ChainDefinition& chain);
	void		Visit(RuntimeVisitor& vis) {vis | loops | chains;}
	void		Forward();
	
	bool		IsReady() const {return status == EonStatus::READY;}
	bool		IsFailed() const {return status == EonStatus::FAILED;}
	EonStatus	GetStatus() const {return status;}
	EonLoader&	GetLoader();
	String		GetTreeString(int indent);
	void		GetLoops(Vector<EonLoopLoader*>& v);
	
};

class EonMachineLoader : RTTIBase {
public:
	RTTI_DECL0(EonMachineLoader)
	
public:
	Array<EonChainLoader>		chains;
	EonSystemLoader&			parent;
	Eon::Machine&				mach;
	EonStatus					status = EonStatus::IN_BEGINNING;
	int							id = -1;
	
	
	EonMachineLoader(EonSystemLoader& parent, int id, Eon::Machine& mach);
	void		Visit(RuntimeVisitor& vis) {vis | chains;}
	void		Forward();
	
	bool		IsReady() const {return status == EonStatus::READY;}
	bool		IsFailed() const {return status == EonStatus::FAILED;}
	EonStatus	GetStatus() const {return status;}
	EonLoader&	GetLoader();
	String		GetTreeString(int indent);
	
};

class EonSystemLoader : RTTIBase {
public:
	RTTI_DECL0(EonSystemLoader)
	
public:
	Array<EonMachineLoader>		machs;
	EonLoader&					parent;
	Eon::GlobalScope&			glob;
	EonStatus					status = EonStatus::IN_BEGINNING;
	int							id = -1;
	
	
	EonSystemLoader(EonLoader& parent, int id, Eon::GlobalScope& glob);
	
	void		Visit(RuntimeVisitor& vis) {vis | machs;}
	void		Forward();
	
	bool		IsReady() const {return status == EonStatus::READY;}
	bool		IsFailed() const {return status == EonStatus::FAILED;}
	EonStatus	GetStatus() const {return status;}
	EonLoader&	GetLoader();
	String		GetTreeString(int indent=0);
	void		Dump() {LOG(GetTreeString());}
	
};

bool TestParseEonCode(String code);

class EonLoader :
	public System<EonLoader>
{
protected:
	friend class EonLoopLoader;
	friend class EonChainLoader;
	static int loop_counter;
	
	//LinkedList<EonScope> scopes;
	Vector<Eon::GlobalScope*> scopes;
	One<EonSystemLoader> loader;
	
	Eon::WorldState def_ws;
	Eon::ActionPlanner def_planner;
	int tmp_side_id_counter = 0;
	
	Vector<String> post_load_file;
	Vector<String> post_load_string;
	Eon::CompilationUnit root;
	EntityStoreRef es;
	
	Vector<EonError> errs;
	bool collect_errors = false;
	
	
	void AddError(String msg);
	void AddError(EonLoopLoader* ll, String msg);
	void ReleaseErrorBuffer();
	void ClearErrorBuffer();
	void CollectErrorBuffer(bool b) {collect_errors = b;}
	//void EnterScope();
	//bool LeaveScope();
	
public:
	SYS_RTTI(EonLoader)
	SYS_CTOR(EonLoader);
	SYS_DEF_VISIT_((vis & es); if (!loader.IsEmpty()) vis % *loader;)
	
	void PostLoadFile(String path) {post_load_file << path;}
	void PostLoadString(String s) {post_load_string << s;}
	
	
	static EcsTypeCls::Type		GetEcsType() {return EcsTypeCls::SYS_EON;}
	
protected:
	
    bool Initialize() override;
    void Start() override;
    void Update(double dt) override;
    void Stop() override;
    void Uninitialize() override;
    
    bool DoPostLoad();
	bool LoadFile(String path);
	bool Load(String content, String filepath="temp");
	bool LoadCompilationUnit(Eon::CompilationUnit& cunit);
	//bool LoadMachine(Eon::Machine& mach);
	bool LoadGlobalScope(Eon::GlobalScope& list);
	//bool LoadChainDefinition(Eon::ChainDefinition& def);
	EntityRef ResolveEntity(Eon::Id& id);
	//bool SolveLoops(Eon::ChainDefinition& def);
	bool ConnectSides(EonLoopLoader& loop0, EonLoopLoader& loop1);
	/*void SolveInsideLoops(Eon::ChainDefinition& chain);
	void SolveInsideChain(Eon::ChainDefinition& chain);
	void SolveBetweenChains(const Vector<Eon::ChainDefinition*>& chains);
	void SolveBetweenMachines(const Vector<Vector<Eon::ChainDefinition*>>& machs);
	void GetChainsDeepestFirst(Eon::Machine& mach, Vector<Eon::ChainDefinition*>& chains);*/
	
	Eon::State* FindState(const Eon::Id& id);
	
	//bool IsNewConnections() const;
	
	
	
};

using EonLoaderRef = Ref<EonLoader, RefParent1<Machine>>;



class EonConnectionSolver {
	Vector<EonLoopLoader*>		loops;
	String						err_str;
	int&						tmp_side_id_counter;
	bool						is_missing_input = false;
	bool						is_missing_output = false;
	
	void SetError(String s) {err_str = s;}
	bool Process();
public:
	
	EonConnectionSolver(int& side_id_counter) : tmp_side_id_counter(side_id_counter) {}
	
	template <class T>
	bool Solve(T* o) {
		loops.SetCount(0);
		o->GetLoops(loops);
		if (loops.IsEmpty()) {
			SetError("Internal error: no loops");
			return false;
		}
		
		return Process();
	}
	
	String	GetError() const {return err_str;}
	bool	IsMissingInput() const {return is_missing_input;}
	bool	IsMissingOutput() const {return is_missing_output;}
	
};

NAMESPACE_ECS_END

NAMESPACE_TOPSIDE_BEGIN


template <>	inline bool TerminalTest<Ecs::Eon::ActionNode>(Node<Ecs::Eon::ActionNode>& n) {
	if (&n == (void*)0x8026C63C0) {
		LOG("");
	}
	
	using namespace Ecs;
	int est = n.GetEstimate();
	if (est <= 0)
		return true;
	Eon::ActionNode& goal = n.GetGoal();
	Eon::WorldState& goal_ws = goal.GetWorldState();
	if (n.Contains(goal))
		return true;
	if (goal.Conflicts(n))
		return false;
	Eon::WorldState& ws = n.GetWorldState();
	Eon::ActionPlanner& ap = n.GetActionPlanner();
	EonLoopLoader& ll = ap.GetLoopLoader();
	EonLoopSegment& seg = ll.GetCurrentSegment();
	
	TypeCompCls comp = ws.GetComponent();
	if (ws.IsAddComponent() && n.GetLinkedCount() && comp.side.vd.val == ValCls::ORDER)
		return false;
	
	bool req_ext = false;
	if (ws.IsAddComponent()) {
		if (comp.sub == SubCompCls::SIDE_INPUT || comp.sub == SubCompCls::SIDE_OUTPUT)
			req_ext = true;
	}
	
	
	if (ws.IsAddExtension()) {
		if (n.GetLinkedCount() > 0) {
			TypeExtCls ext = ws.GetExtension();
			//if (!seg.side_conn) {
			if (ext.sub == SubCompCls::SIDE_INPUT) {
				ap.AddSideInput(seg.as, n);
				return false;
			}
			else if (ext.sub == SubCompCls::SIDE_OUTPUT) {
				POPO(Pol::Ecs::Eon::Loop::SideInIsBeforeSideOutAlways)
				if (goal_ws	.IsTrue	("has.side.in") &&
					ws		.IsFalse("has.side.in"))
					return false;
				
				ap.AddSideOutput(seg.as, n);
				return false;
			}
			/*}
			else {
				const Eon::APlanNode* accepted = ll.GetAcceptedSideNode();
				ASSERT(accepted);
				//if (n.GetWorldState() != accepted->GetWorldState())
				//	return false;
				if (&n != accepted) {
					LOG("Skipped terminal: " << IntStr64(n.GetWorldState().GetHashValue()) << ": " << n.GetWorldState().ToString());
					return false;
				}
				LOG("Found side-ch path: " << accepted->GetWorldState().ToString());
				
			}*/
		}
	}
	
	Array<Ecs::Eon::WorldState*> to;
	Vector<double> action_costs;
	ap.GetPossibleStateTransition(n, to, action_costs);
	
	//LOG("TerminalTest: " << HexStr(&n) << " -> " << to.GetCount() << " (estimate " << n.GetEstimate() << ")");
	for(int i = 0; i < to.GetCount(); i++) {
		Ecs::Eon::WorldState& ws_to = *to[i];
		if (req_ext && ws_to.IsAddComponent())
			continue;
		/*if (req_ext) {
			TypeCompCls to_comp = ws_to.GetComponent();
			ASSERT(to_comp.sink.val != ValCls::RECEIPT);
		}*/
		int64 hash = ws_to.GetHashValue();
		int j = ap.tmp_sub.Find(hash);
		Ecs::Eon::APlanNode* an = 0;
		if (j == -1) {
			Ecs::Eon::APlanNode& sub = ap.tmp_sub.Add(hash);// n.Add();
			sub.IncLinked();
			sub.SetActionPlanner(n.GetActionPlanner());
			sub.SetGoal(n.GetGoal());
			sub.SetWorldState(ws_to);
			sub.SetCost(action_costs[i]);
			n.AddLink(sub);
			an = &sub;
		} else {
			an = &ap.tmp_sub[j];
			an->IncLinked();
			n.AddLink(*an);
		}
		//LOG("\t" << n.GetEstimate() << ": " << HexStr(an) << " -> " << ws_to.ToString());
		
		/*if (ws_to.IsAddComponent()) {
			TypeCompCls t = ws_to.GetComponent();
			if (t.sub == SubCompCls::SIDE_INPUT) {
				ap.AddSideInput(*an);
			}
			else if (t.sub == SubCompCls::SIDE_OUTPUT) {
				ap.AddSideOutput(*an);
			}
		}*/
	}
	//if (n.GetTotalCount())
	//	return false;
	
	return false;
}

NAMESPACE_TOPSIDE_END

#endif
