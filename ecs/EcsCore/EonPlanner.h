#ifndef _EcsLib_EonPlanner_h_
#define _EcsLib_EonPlanner_h_

NAMESPACE_ECS_BEGIN

class EonLoader;
class EonLoopLoader;

namespace Eon {

class ActionPlanner;
class ActionNode;

class WorldState : public Moveable<WorldState> {

public:
	typedef enum : byte {
		INVALID,
		ADD_COMP,
		ADD_EXT
	} Type;
	
protected:
	friend class ActionPlanner;
	friend class ActionPlannerWrapper;
	friend class ActionNode;
	friend class ::TS::Ecs::EonLoader;
	friend class ::TS::Ecs::EonLoopLoader;
	
	Vector<String>		values;
	Vector<bool>		using_act;
	TypeCompCls			cur_comp;
	TypeExtCls			add_ext;
	Type				type = INVALID;
	ActionPlanner*		ap = 0;
public:
	
	WorldState();
	void Clear();
	
	bool Append(const WorldState& ws, LinkedList<Statement>& ret_list);
	void SetActionPlanner(ActionPlanner& ap) {this->ap = &ap;}
	bool Set(int index, bool value);
	bool Set(int index, String value);
	bool Set(const String& key, bool value);
	bool Set(const String& key, String value);
	void SetTrue(const String& key) {Set(key, true);}
	void SetFalse(const String& key) {Set(key, false);}
	void SetAs_AddExtension(TypeCompCls comp, TypeExtCls ext) {type = ADD_EXT; cur_comp = comp; add_ext = ext;}
	void SetAs_AddComponent(TypeCompCls comp) {type = ADD_COMP; cur_comp = comp;}
	
	ActionPlanner& GetActionPlanner() const {return *ap;}
	bool IsAddComponent() const {return type == ADD_COMP;}
	bool IsAddExtension() const {return type == ADD_EXT;}
	bool IsTrue(const String& key) const;
	bool IsFalse(const String& key) const;
	String Get(const String& key) const;
	int64 GetHashValue();
	TypeCompCls GetComponent() const {return cur_comp;}
	TypeExtCls GetExtension() const {return add_ext;}
	ValDevCls GetInterface() const {ASSERT(cur_comp.IsValid()); return cur_comp.side.vd;}
	String ToString() const;
	bool Contains(const WorldState& ws) const;
	
	WorldState& operator=(const WorldState& src);
	
	
};


class Action : public Moveable<Action> {
	
protected:
	friend class ActionPlanner;
	friend class ActionNode;
	friend class ActionPlannerWrapper;
	friend class Factory;
	
	WorldState precond, postcond;
	double cost;
	
public:

	Action();
	Action(const WorldState& cond) : precond(cond), postcond(cond), cost(0) {}
	
	const WorldState& Pre() const {return precond;}
	const WorldState& Post() const {return postcond;}
	WorldState& Pre() {return precond;}
	WorldState& Post() {return postcond;}
	
	bool IsAddComponent() const {return postcond.IsAddComponent();}
	bool IsAddExtension() const {return postcond.IsAddExtension();}
	
};

class ActionNode : RTTIBase {
	WorldState* ws;
	double cost;
	
	ActionPlanner* ap;
	ActionNode* goal;
	
public:
	RTTI_DECL0(ActionNode)
	
	
	ActionNode();
	
	
	void SetActionPlanner(ActionPlanner& ap_) {ap = &ap_;}
	void SetGoal(ActionNode& ws) {goal = &ws;}
	void SetWorldState(WorldState& ws) {this->ws = &ws;}
	void SetCost(double d) {cost = d;}
	
	ActionPlanner& GetActionPlanner() {return *ap;}
	WorldState& GetWorldState() {return *ws;}
	ActionNode& GetGoal() {return *goal;}
	double GetDistance(const ActionNode& to);
	double GetEstimate();
	double GetCost() const {return cost;}
	
	bool Contains(const ActionNode& n) const;
	
};

typedef Node<ActionNode> APlanNode;


struct Plan : Moveable<Plan> {
	Vector<Eon::ActionNode*> plan;
	
	Plan() {}
	Plan(const Plan& ep) {*this = ep;}
	void operator=(const Plan& ep) {
		plan <<= ep.plan;
	}
};


class ActionPlannerWrapper;

class ActionPlanner {
	
protected:
	friend class ActionNode;
	friend class ActionPlannerWrapper;
	friend class ::TS::Ecs::EonLoader;
	friend class ::TS::Ecs::EonLoopLoader;
	
	struct Atom : Moveable<Atom> {
		Vector<String> id;
		
		String ToString() const {return Join(id, ".");}
	};
	
	VectorMap<String, Atom> atoms;
	Vector<Action> acts;
	ActionPlannerWrapper* wrapper = 0;
	
	Array<WorldState> search_cache;
	
public:
	ArrayMap<hash_t, Node<ActionNode> > tmp_sub;
	
public:
	ActionPlanner();
	
	
	void Clear();
	
	int GetActionCount() const {return acts.GetCount();}
	int GetAtomCount() const {return atoms.GetCount();}
	int GetAddAtom(String id);
	int GetAddAtom(const Id& id);
	const Atom& GetAtom(int i) const {return atoms[i];}
	
	bool SetPreCondition(int action_id, int atom_id, bool value);
	bool SetPostCondition(int action_id, int atom_id, bool value);
	bool SetCost(int action_id, int cost );
	
	void GetPossibleStateTransition(Node<Eon::ActionNode>& n, Array<WorldState*>& dest, Vector<double>& action_costs);
	
};

class ActionPlannerWrapper {
	ActionPlanner& ap;
	Vector<String> atoms, acts;
	
protected:
	friend class ActionPlanner;
	
	void OnResize();
	
public:
	ActionPlannerWrapper(ActionPlanner& planner);
	
	int GetAtomIndex(String atom_name);
	int GetActionIndex(String action_name);
	String GetAtomName(int i) {return atoms[i];}
	String GetActionName(int i) {return acts[i];}
	String GetWorldstateDescription( const WorldState& ws );
	String GetDescription();
	
	void SetAction(int act_i, String s) {acts[act_i] = s;}
	void SetAtom(int atom_i, String s) {atoms[atom_i] = s;}
	bool SetPreCondition(String action_name, String atom_name, bool value);
	bool SetPostCondition(String action_name, String atom_name, bool value);
	bool SetCost(String action_name, int cost );
	
};


}


NAMESPACE_ECS_END


NAMESPACE_TOPSIDE_BEGIN


template <>	inline bool TerminalTest<Ecs::Eon::ActionNode>(Node<Ecs::Eon::ActionNode>& n) {
	if (n.GetEstimate() <= 0)
		return true;
	Ecs::Eon::ActionNode& goal = n.GetGoal();
	if (n.Contains(goal))
		return true;
	Ecs::Eon::WorldState& ws = n.GetWorldState();
	Ecs::Eon::ActionPlanner& ap = n.GetActionPlanner();
	Array<Ecs::Eon::WorldState*> to;
	Vector<double> action_costs;
	ap.GetPossibleStateTransition(n, to, action_costs);
	//LOG("TerminalTest: " << HexStr(&n) << " -> " << to.GetCount() << " (estimate " << n.GetEstimate() << ")");
	for(int i = 0; i < to.GetCount(); i++) {
		Ecs::Eon::WorldState& ws_to = *to[i];
		//LOG("\t" << n.GetEstimate() << ": " << ws_to.ToString());
		int64 hash = ws_to.GetHashValue();
		int j = ap.tmp_sub.Find(hash);
		if (j == -1) {
			Ecs::Eon::APlanNode& sub = ap.tmp_sub.Add(hash);// n.Add();
			sub.SetActionPlanner(n.GetActionPlanner());
			sub.SetGoal(n.GetGoal());
			sub.SetWorldState(ws_to);
			sub.SetCost(action_costs[i]);
			n.AddLink(sub);
		} else {
			n.AddLink(ap.tmp_sub[j]);
		}
	}
	//if (n.GetTotalCount())
	//	return false;
	
	return false;
}

NAMESPACE_TOPSIDE_END


#endif
