#include "Internal.h"


NAMESPACE_SERIAL_BEGIN


ScriptLoopLoader::ScriptLoopLoader(ScriptChainLoader& parent, int id, Script::LoopDefinition& def) :
	Base(parent, id, def)
{
	planner.SetLoopLoader(this);
}

void ScriptLoopLoader::LoopStatus() {
	Panic("internal error");
}

void ScriptLoopLoader::ForwardLoops() {
	Panic("internal error");
}

void ScriptLoopLoader::GetLoops(Vector<ScriptLoopLoader*>& v) {
	Panic("internal error");
}

void ScriptLoopLoader::SetRetryDeep() {
	if (status == ScriptStatus::READY)
		return;
	status = ScriptStatus::RETRY;
}

String ScriptLoopLoader::GetTreeString(int indent) {
	String s;
	s.Cat('\t', indent);
	s << "Loop " << id;
	s.Cat('\n');
	
	int id = 0;
	for (ScriptLoopSegment& seg : segments) {
		s << seg.GetTreeString(id++, indent+1);
	}
	
	String extra;
	if (status == ScriptStatus::FAILED)
		extra = err_str;
	
	s << GetScriptStatusLine(indent+1, status, extra);
	
	return s;
}

void ScriptLoopLoader::SetSideSourceConnected(const AtomTypeCls& type, int ch_i, ScriptLoopLoader* sink) {
	ASSERT(type.IsValid());
	ASSERT(ch_i > 0);
	ASSERT(type.iface.src.count > 1 && ch_i < type.iface.src.count);
	int side_ch_i = ch_i - 1;
	if (src_side_conns.IsEmpty()) {
		int side_conn_count = type.iface.src.count - 1;
		src_side_conns.SetCount(side_conn_count, 0);
	}
	src_side_conns[side_ch_i] = sink;
}

void ScriptLoopLoader::SetSideSinkConnected(const AtomTypeCls& type, int ch_i, ScriptLoopLoader* src) {
	ASSERT(type.IsValid());
	ASSERT(ch_i > 0);
	ASSERT(type.iface.sink.count > 1 && ch_i < type.iface.sink.count);
	int side_ch_i = ch_i - 1;
	if (sink_side_conns.IsEmpty()) {
		int side_conn_count = type.iface.sink.count - 1;
		sink_side_conns.SetCount(side_conn_count, 0);
	}
	sink_side_conns[side_ch_i] = src;
}

bool ScriptLoopLoader::IsAllSidesConnected() const {
	ASSERT(src_side_conns.GetCount() || sink_side_conns.GetCount());
	for (ScriptLoopLoader* l : src_side_conns)
		if (!l)
			return false;
	for (ScriptLoopLoader* l : sink_side_conns)
		if (!l)
			return false;
	return true;
}

	
String ScriptLoopSegment::GetTreeString(int id, int indent) {
	String s;
	s.Cat('\t', indent);
	s << "Segment " << id;
	s.Cat('\n');
	if (!ep.plan.IsEmpty()) {
		bool started = false;
		for (Script::ActionNode* n : ep.plan) {
			started = started || n == start_node;
			if (!started) continue;
			String state_str = n->GetWorldState().ToString();
			if (state_str.GetCount()) {
				s.Cat('\t', indent+1);
				s << state_str << "\n";
			}
		}
	}
	else {
		s.Cat('\t', indent+1);
		s << "empty\n";
	}
	return s;
}

void ScriptLoopLoader::SetupSegment(ScriptLoopSegment& s) {
	
	
	// Do the action plan searching
	s.as.SetLimit(10000);
	
}

void ScriptLoopLoader::Forward() {
	ASSERT(!IsReady() && !IsFailed());
	ScriptStatus prev_status = status;
	
	if (status == ScriptStatus::IN_BEGINNING) {
		if (def.stmts.IsEmpty() && def.req.IsEmpty()) {
			String id = def.id.ToString();
			SetError("Loop " + IntStr(GetId()) + " '" + id + "' has no statements");
			return;
		}
		
		InitSegments();
		ForwardTopSegment();
	}
	else if (status == ScriptStatus::RETRY) {
		ASSERT(segments.GetCount() >= 1);
		planner.ClearForward();
		
		ForwardTopSegment();
	}
	else {
		
		TODO
		
	}
	
	ASSERT(prev_status != status);
}

void ScriptLoopLoader::InitSegments() {
	DevCls dev = DevCls::Get(def.id.parts.First());
	if (!dev.IsValid())
		dev = DevCls::CENTER;
	
	AtomTypeCls consumer;
	if (dev == DevCls::CENTER)
		consumer = AsAtomTypeCls<CenterCustomer>();
	else if (dev == DevCls::OGL) {
		#ifdef flagGUI
		consumer = AsAtomTypeCls<OglCustomer>();
		#else
		SetError("OGL device not supported without this program compiled with GUI compilation flag");
		#endif
	}
	else {
		TODO
		return;
	}
	
	// Prepare action planner and world states
	int CONNECTED = planner.GetAddAtom("loop.connected");
	AtomCls customer;
	customer.sink = ValDevCls(dev, ValCls::RECEIPT);
	customer.side = ValDevCls(dev, ValCls::ORDER);
	customer.src  = ValDevCls(dev, ValCls::ORDER);
	
	//start = scope.current_state;
	start.SetActionPlanner(planner);
	
	
	start.SetAs_AddAtom(consumer);
	//int HAS_DEV = planner.GetAddAtom("has." + dev.GetActionName());
	//start.Set(HAS_DEV, true);
	
	goal.SetActionPlanner(planner);
	goal.SetAs_AddAtom(consumer);
	goal.Set(CONNECTED, true);
	
	for (Script::Id& req : def.req) {
		Script::State* s = GetLoader().FindState(req);
		if (!s) {
			SetError("Could not find required state '" + req.ToString() + "'");
			return;
		}
		for (Script::Statement& stmt : s->stmts)
			if (!SetWorldState(goal, stmt))
				return;
	}
	
	for (Script::Statement& stmt : def.stmts)
		if (stmt.IsRouting() && !SetWorldState(goal, stmt))
			return;
	
	goal_node.SetWorldState(goal);
	goal_node.SetGoal(goal_node);
	
	start_node.SetActionPlanner(planner);
	start_node.SetGoal(goal_node);
	start_node.SetWorldState(start);
	
	
	ScriptLoopSegment& seg = segments.Add();
	seg.start_node = &start_node;
}

void ScriptLoopLoader::ForwardTopSegment() {
	ScriptLoopSegment& seg = segments.Top();
	ASSERT(seg.start_node);
	SetupSegment(seg);
	
	LOG("goal: " << goal.ToString());
	LOG("start-node: " << seg.start_node->GetWorldState().GetAtom().ToString());
	seg.start_node->ResetLinked();
	if (segments.GetCount() == 1)
		seg.ep.plan = seg.as.Search(*seg.start_node);
	else
		seg.ep.plan = seg.as.ContinueSearch(*seg.start_node);
	
	if (seg.ep.plan.IsEmpty()) {
		if (accepted_side_node) {
			SetError("Script implementation searching failed after side-connection");
			return;
		}
		
		// Check side-channel connections
		const Vector<Script::ActionPlanner::State>& sinks = planner.GetSideSinks();
		const Vector<Script::ActionPlanner::State>& sources = planner.GetSideSources();
		
		bool is_sink = planner.IsSideSink();
		if (!is_sink && sources.GetCount()) {
			LOG("Loop " << id << " side-sources:");
			for(int i = 0; i < sources.GetCount(); i++) {
				const Script::ActionPlanner::State& state = sources[i];
				const Script::WorldState& ws = state.last->GetWorldState();
				const Script::WorldState* prev_ws = state.second_last ? &state.second_last->GetWorldState() : 0;
				const Script::Statement* stmt = ws.FindStatement(prev_ws, def.stmts);
				ASSERT(stmt);
				if (!stmt) {SetError("internal error: no statement found"); return;}
				AtomTypeCls type = ws.GetAtom();
				ASSERT(type.IsValid());
				int atom_user_count = type.user_sink_count + type.user_src_count;
				int user_defined_count = stmt->side_conds.GetCount();
				if (atom_user_count != user_defined_count) {
					SetError("user conditional count differs to atom requirements: user gives " + IntStr(user_defined_count) + ", atom requires " + IntStr(atom_user_count));
					return;
				}
				
				LOG(i << ": " << state.last->GetEstimate() << ": " << ws.ToString());
			}
			status = SOURCE_IS_WAITING;
			return;
		}
		else if (is_sink && sinks.GetCount()) {
			LOG("Loop " << id << " side-sinks:");
			for(int i = 0; i < sinks.GetCount(); i++) {
				const Script::ActionPlanner::State& state = sinks[i];
				const Script::WorldState& ws = state.last->GetWorldState();
				const Script::WorldState* prev_ws = state.second_last ? &state.second_last->GetWorldState() : 0;
				const Script::Statement* stmt = ws.FindStatement(prev_ws, def.stmts);
				ASSERT(stmt);
				if (!stmt) {SetError("internal error: no statement found"); return;}
				AtomTypeCls type = ws.GetAtom();
				ASSERT(type.IsValid());
				int atom_user_count = type.user_sink_count + type.user_src_count;
				int user_defined_count = stmt->side_conds.GetCount();
				if (atom_user_count != user_defined_count) {
					SetError("user conditional count differs to atom requirements: user gives " + IntStr(user_defined_count) + ", atom requires " + IntStr(atom_user_count));
					return;
				}
				LOG(i << ": " << state.last->GetEstimate() << ": " << ws.ToString());
			}
			status = SINK_IS_WAITING;
			return;
		}
		else {
			SetError("Script implementation searching failed");
			return;
		}
	}
	
	// Set last node
	seg.stop_node = seg.ep.plan.Top();
	
	// Debug print found loop
	if (1) {
		int pos = 0;
		ScriptLoopSegment& seg = segments.Top();
		for (Script::ActionNode* n : seg.ep.plan) {
			const Script::WorldState& ws = n->GetWorldState();
			AtomTypeCls atom = ws.GetAtom();
			const auto& d = Serial::Factory::AtomDataMap().Get(atom);
			if (ws.IsAddAtom()) {
				LOG(pos++ << ": add atom: " << d.name);
			}
			LOG("\t" << ws.ToString());
		}
	}
	
	status = READY;
}

bool ScriptLoopLoader::SetWorldState(Script::WorldState& ws, const Script::Statement& stmt) {
	if (!stmt.value || stmt.value->type == Script::Value::VAL_CUSTOMER)
		return true;;
	
	int atom = planner.GetAddAtom(stmt.id);
	
	String old_value = goal.Get(atom);
	String new_value;
	
	if (stmt.value->type == Script::Value::VAL_BOOLEAN)
		new_value = stmt.value->b ? "true" : "false";
	else if (stmt.value->type == Script::Value::VAL_ID)
		new_value = stmt.value->id.ToString();
	else if (stmt.value->type == Script::Value::VAL_STRING)
		new_value = stmt.value->str;
	else if (stmt.value->type == Script::Value::VAL_INT)
		new_value = IntStr(stmt.value->i);
	else if (stmt.value->type == Script::Value::VAL_DOUBLE)
		new_value = DblStr(stmt.value->f);
	else {
		SetError("internal error");
		return false;
	}
	
	if (old_value != new_value && !old_value.IsEmpty()) {
		SetError("Earlier value mismatch newer value for id '" + stmt.id.ToString() + "' (" +
			old_value + " != " + new_value + ")");
		return false;
	}
	
	ws.Set(atom, new_value);
	return true;
}


bool ScriptLoopLoader::Load() {
	ScriptLoader& loader = GetLoader();
	
	// Target entity for atoms
	LoopRef l = loader.ResolveLoop(def.id);
	if (!l) {
		SetError("Could not resolve entity with id: " + def.id.ToString());
		return false;
	}
	
	
	added_atoms.Clear();
	
	int seg_i = segments.GetCount()-1;
	ScriptLoopSegment& seg = segments.Top();
	int plan_i = 0;
	const Script::WorldState* prev_ws = 0;
	for (Script::ActionNode* n : seg.ep.plan) {
		RTLOG("Loading plan node " << plan_i);
		Script::WorldState& ws = n->GetWorldState();
		if (ws.IsAddAtom()) {
			bool is_last = plan_i == seg.ep.plan.GetCount()-1;
			AtomTypeCls atom = ws.GetAtom();
			AtomBaseRef ab =
				is_last ?
					l->FindTypeCls(atom) :
					l->GetAddTypeCls(atom);
			if (!ab) {
				String atom_name = Serial::Factory::AtomDataMap().Get(atom).name;
				SetError("Could not create atom '" + atom_name + "' at '" + def.id.ToString() + "'");
				DUMP(atom);
				ASSERT(0);
				return false;
			}
			auto& c = added_atoms.Add();
			c.r = ab;
			c.plan_i = plan_i;
			c.seg_i = seg_i;
			c.side_sink = n->GetSideSinkId();
			c.side_src = n->GetSideSrcId();
			
			
			AtomTypeCls type = ws.GetAtom();
			
			
			// Add arguments to ws
			const Script::Statement* stmt = ws.FindStatement(prev_ws, def.stmts);
			if (stmt) {
				for (const Script::Statement& arg : stmt->args) {
					//LOG("\t" << arg.id.ToString());
					String k = arg.id.ToString();
					String v = arg.value ? arg.value->GetValue() : String();
					ws.Set("." + k, v);
					LOG("ScriptLoopLoader::Load: set argument: " << k << " = " << v);
				}
			}
			
			
			if (!ab->InitializeAtom(ws) || !ab->Initialize(ws) || !ab->Initialize(ws)) {
				const auto& a = Serial::Factory::AtomDataMap().Get(type);
				SetError("Could not " + String(!ab ? "create" : "initialize") + " atom '" + a.name + "' at '" + def.id.ToString() + "'");
				return false;
			}
			
		}
		else {
			Panic("Invalid world state type");
		}
				
		prev_ws = &ws;
		++plan_i;
	}
	
	
	for(int i = 0; i < added_atoms.GetCount()-1; i++) {
		AddedAtom& src_info = added_atoms[i];
		AtomBaseRef src = src_info.r;
		
		AddedAtom& sink_info = added_atoms[i+1];
		AtomBaseRef sink = sink_info.r;
		ScriptLoopSegment& sink_seg = segments[sink_info.seg_i];
		Script::ActionNode& sink_an = *sink_seg.ep.plan[sink_info.plan_i];
		const Script::WorldState& sink_ws = sink_an.GetWorldState();
		
		ValDevCls common_vd = sink_ws.GetCommonSink();
		ASSERT(common_vd.IsValid());
		
		if (!l->Link(src, sink, common_vd)) {
			AtomTypeCls atom = sink_ws.GetAtom();
			String atom_name = Serial::Factory::AtomDataMap().Get(atom).name;
			String src_sink_name = Serial::Factory::IfaceLinkDataMap().Get(common_vd).name;
			SetError("Could not link atom '" + atom_name + "' source '" + src_sink_name + "' at '" + def.id.ToString() + "'");
			return false;
		}
		if (src_info.side_sink >= 0)
			src->AddSideSinkId(src_info.side_sink);
		if (src_info.side_src >= 0)
			src->AddSideSrcId(src_info.side_src);
		
		atoms.Add(src);
	}
	
	
	UpdateLoopLimits();
	
	
	AddedAtom& first = added_atoms[0];
	AddedAtom& last  = added_atoms.Top();
	ScriptLoopSegment& first_seg = segments[first.seg_i];
	ScriptLoopSegment& last_seg  = segments[last.seg_i];
	
	
	// Process sub-loops
	for (Script::Statement& stmt : def.stmts) {
		if (!stmt.value || stmt.value->type != Script::Value::VAL_CUSTOMER)
			continue;
		//LoadLoopDefinition(stmt.value->customer);
		SetError("Sub-loops not supported yet");
		return false;
	}
	
	
	// Add changes to parent state
	/*const Script::WorldState& ret_ws = last_seg.ep.plan.Top()->GetWorldState();
	if (!scope.current_state.Append(ret_ws, def.ret_list)) {
		SetError("Invalid type in return value");
		return false;
	}*/
	
	
	return true;
}

void ScriptLoopLoader::UpdateLoopLimits() {
	
	// as in AtomBase::LinkSideSink
	
	bool changes = false;
	int c = added_atoms.GetCount()-1;
	int total_max = 1000000;
	int total_min = 0;
	for(int i = 0; i < c; i++) {
		AddedAtom& info = added_atoms[i];
		InterfaceSourceRef src = info.r->GetSource();
		int src_c = src->GetSourceCount();
		for(int j = 0; j < src_c; j++) {
			int src_min_packets = src->GetSourceValue(j).GetMinPackets();
			int src_max_packets = src->GetSourceValue(j).GetMaxPackets();
			total_min = max(total_min, src_min_packets);
			total_max = min(total_max, src_max_packets);
		}
		
		InterfaceSinkRef sink = info.r->GetSink();
		int sink_c = sink->GetSinkCount();
		for(int j = 0; j < sink_c; j++) {
			int sink_min_packets = sink->GetValue(j).GetMinPackets();
			int sink_max_packets = sink->GetValue(j).GetMaxPackets();
			total_min = max(total_min, sink_min_packets);
			total_max = min(total_max, sink_max_packets);
		}
	}
	if (total_min > total_max) {
		total_max = total_min;
	}
	
	LOG("ScriptLoopLoader::Load: set loop limits: min=" << total_min << ", max=" << total_max);
	
	for(int i = 0; i < c; i++) {
		AddedAtom& info = added_atoms[i];
		InterfaceSourceRef src = info.r->GetSource();
		InterfaceSinkRef sink = info.r->GetSink();
			
		int sink_c = sink->GetSinkCount();
		for(int k = 0; k < sink_c; k++) {
			Value& v = sink->GetValue(k);
			v.SetMinQueueSize(total_min);
			v.SetMaxQueueSize(total_max);
		}
		
		int src_c = src->GetSourceCount();
		for(int k = 0; k < src_c; k++) {
			Value& v = src->GetSourceValue(k);
			v.SetMinQueueSize(total_min);
			v.SetMaxQueueSize(total_max);
		}
			
		/*if (link_changes) {
			DUMP(min_packets);
			DUMP(sink_min_packets);
			DUMP(src_min_packets);
		}*/
	}
}


bool ScriptLoopLoader::PostInitialize() {
	for(int i = added_atoms.GetCount()-1; i >= 0; i--) {
		AddedAtom& a = added_atoms[i];
		if (!a.r->PostInitialize())
			return false;
	}
	return true;
}

SideStatus ScriptLoopLoader::AcceptSink(ScriptLoopLoader& sink_loader, Script::ActionPlanner::State*& accepted_src, Script::ActionPlanner::State*& accepted_sink) {
	ASSERT(status == SOURCE_IS_WAITING);
	ASSERT(sink_loader.status == SINK_IS_WAITING);
	Vector<Script::ActionPlanner::State>& sources = planner.GetSideSources();
	Vector<Script::ActionPlanner::State>& sinks = sink_loader.planner.GetSideSinks();
	ASSERT(!sources.IsEmpty() && !sinks.IsEmpty());
	
	SideStatus ret = SIDE_NOT_ACCEPTED;
	int accepted_count = 0;
	
	// Don't clear, just overwrite:
	//accepted_src = 0;
	//accepted_sink = 0;
	
	//int src_side_id = src_side_conns.GetCount();
	//int sink_side_id = sink_loader.sink_side_conns.GetCount();
	
	/*if (def.id.ToString() == "source" && sink_loader.def.id.ToString() == "sink1") {
		LOG("");
	}*/
	
	for (Script::ActionPlanner::State& src_state : sources) {
		Script::APlanNode* src = src_state.last;
		Script::WorldState& src_ws = src->GetWorldState();
		Script::WorldState* src_prev_ws = src_state.second_last ? &src_state.second_last->GetWorldState() : 0;
		int src_side_id = src_state.ch_i - 1;
		ASSERT(src_ws.IsAddAtom());
		AtomTypeCls src_atom = src_ws.GetAtom();
		auto& src_d = Serial::Factory::AtomDataMap().Get(src_atom);
		
		
		const Script::Statement* src_stmt = src_ws.FindStatement(src_prev_ws, def.stmts);
		ASSERT(src_stmt);
		if (src_stmt && src_stmt->side_conds.GetCount()) {
			if (src_side_id >= src_stmt->side_conds.GetCount()) {
				SetError("side connection id-number is higher than the count of given side-connection conditionals");
				continue;
			}
			RTLOG("ScriptLoopLoader::AcceptSink: testing source conditionals in sink");
			const Script::Statement& cond_stmt = src_stmt->side_conds[src_side_id];
			if (!sink_loader.PassSideConditionals(cond_stmt)) {
				RTLOG("ScriptLoopLoader::AcceptSink: source side conditionals did not pass");
				continue;
			}
		}
		
		
		for (Script::ActionPlanner::State& sink_state : sinks) {
			Script::APlanNode* sink = sink_state.last;
			Script::WorldState& sink_ws = sink->GetWorldState();
			Script::WorldState* sink_prev_ws = sink_state.second_last ? &sink_state.second_last->GetWorldState() : 0;
			int sink_side_id = sink_state.ch_i - 1;
			ASSERT(sink_ws.IsAddAtom());
			AtomTypeCls sink_atom = sink_ws.GetAtom();
			auto& sink_d = Serial::Factory::AtomDataMap().Get(sink_atom);
			
			RTLOG("ScriptLoopLoader::AcceptSink: src loop '" << def.id.ToString() << "' (" << HexStr(&src_state) << ") against sink '" << sink_loader.def.id.ToString() << "'(" << HexStr(&sink_state) << "): " << src_side_id << " --> " << sink_side_id);
			
			
			const Script::Statement* sink_stmt = sink_ws.FindStatement(sink_prev_ws, sink_loader.def.stmts);
			ASSERT(sink_stmt);
			if (sink_stmt && sink_stmt->side_conds.GetCount()) {
				if (sink_side_id >= sink_stmt->side_conds.GetCount()) {
					SetError("side connection id-number is higher than the count of given side-connection conditionals");
					continue;
				}
				else {
					RTLOG("ScriptLoopLoader::AcceptSink: testing sink conditionals in source");
					const Script::Statement& cond_stmt = sink_stmt->side_conds[sink_side_id];
					if (!PassSideConditionals(cond_stmt)) {
						RTLOG("ScriptLoopLoader::AcceptSink: sink side conditionals did not pass");
						continue;
					}
				}
			}
			
			
			SideStatus a, b;
			if ((a = src_d.side_fn(sink_atom, sink_ws, src_atom, src_ws)) != SIDE_NOT_ACCEPTED) {
				if ((b = sink_d.side_fn(sink_atom, sink_ws, src_atom, src_ws)) != SIDE_NOT_ACCEPTED) {
					RTLOG("ScriptLoopLoader::AcceptSink: pass");
					
					accepted_src = &src_state;
					accepted_sink = &sink_state;
					accepted_count++;
					
					if (a == SIDE_ACCEPTED_MULTI || b == SIDE_ACCEPTED_MULTI)
						ret = SIDE_ACCEPTED_MULTI;
					else
						ret = SIDE_ACCEPTED;
				}
				else {
					RTLOG("ScriptLoopLoader::AcceptSink: sink side function did not pass");
				}
			}
			else {
				RTLOG("ScriptLoopLoader::AcceptSink: source side function did not pass");
			}
		}
	}
	
	if (accepted_count == 0) {
		// not error here, but in caller: SetError("No sources accepts any sinks");
		ret = SIDE_NOT_ACCEPTED;
	}
	else if (accepted_count > 1) {
		SetError("Too many accepting source/sink combinations");
		ret = SIDE_NOT_ACCEPTED;
	}
	
	return ret;
}

void ScriptLoopLoader::AddSideConnectionSegment(Script::ActionPlanner::State* state, ScriptLoopLoader* c, Script::ActionPlanner::State* side_state) {
	ScriptLoopSegment& prev = segments.Top();
	prev.stop_node = state->last;
	prev.ep.plan = prev.as.ReconstructPath(*state->last);
	ASSERT(prev.ep.plan.GetCount());
	ScriptLoopSegment& seg = segments.Add();
	seg.start_node = state->last;
	seg.side_conn = c;
	seg.as = state->as;
}

bool ScriptLoopLoader::PassSideConditionals(const Script::Statement& src_side_stmt) {
	if (src_side_stmt.value.IsEmpty()) {
		SetError("statement '" + src_side_stmt.id.ToString() + "' has no value");
		return false;
	}
	
	for (const Script::Statement& stmt : def.stmts) {
		if (stmt.value.IsEmpty()) {
			RTLOG("ScriptLoopLoader::PassSideConditionals: skip loop empty value stmt: " << stmt.id.ToString());
			continue;
		}
		if (stmt.value->IsBoolean()) {
			RTLOG("ScriptLoopLoader::PassSideConditionals: skip loop boolean value stmt: " << stmt.id.ToString());
			continue;
		}
		if (stmt.id == src_side_stmt.id) {
			bool b = *stmt.value == *src_side_stmt.value;
			if (b) {
				RTLOG("ScriptLoopLoader::PassSideConditionals: conditional '" << stmt.id.ToString() << "': matching '" << stmt.value->ToString() << "'");
			}
			else {
				RTLOG("ScriptLoopLoader::PassSideConditionals: conditional '" << stmt.id.ToString() << "': no match: '" << stmt.value->ToString() << "' vs '" << src_side_stmt.value->ToString() << "'");
			}
			return b;
		}
		else {
			RTLOG("ScriptLoopLoader::PassSideConditionals: no id match: " << stmt.id.ToString() << " != " << src_side_stmt.id.ToString());
		}
	}
	return false;
}




NAMESPACE_SERIAL_END
