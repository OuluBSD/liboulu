#include "EcsLib.h"

NAMESPACE_ECS_BEGIN






bool EonLoader::Initialize() {
	def_ws.SetActionPlanner(def_planner);
	
	es = GetMachine().TryGet<EntityStore>();
	if (!es) {
		LOG("EonLoader requires EntityStore present in machine");
		return false;
	}
	
	if (!DoPostLoad())
		return false;
	
	return true;
}

bool EonLoader::DoPostLoad() {
	for(String path : post_load_file) {
		if (!LoadFile(path))
			return false;
	}
	post_load_file.Clear();
	
	for(String s : post_load_string) {
		if (!Load(s, "input"))
			return false;
	}
	post_load_string.Clear();
	
	return true;
}

void EonLoader::Start() {
	
}

void EonLoader::Update(double dt) {
	
	DoPostLoad();
	
}

void EonLoader::Stop() {
	
}

void EonLoader::Uninitialize() {
	
}

bool EonLoader::LoadFile(String path) {
	if (!FileExists(path)) {
		LOG("Could not find EON file");
		return false;
	}
	String eon = TS::LoadFile(path);
	return Load(eon, path);
}

bool TestParseEonCode(String content) {
	Eon::Parser p;
	if (!p.Parse(content, "<file>")) {
		LOG(GetLineNumStr(content, 1));
		return false;
	}
	p.Dump();
	return true;
}

bool EonLoader::Load(String content, String filepath) {
	RTLOG("EonLoader::Load: Loading \"" << filepath << "\"");
	
	Eon::Parser p;
	if (!p.Parse(content, filepath)) {
		RTLOG(GetLineNumStr(content, 1));
		return false;
	}
	p.Dump();
	MemSwap(p.GetResult(), root);
	
	if (!LoadCompilationUnit(root))
		return false;
	
	return true;
}

bool EonLoader::LoadCompilationUnit(Eon::CompilationUnit& cunit) {
	return LoadSidechainDefinition(cunit.main);
}

bool EonLoader::LoadSidechainDefinition(Eon::SidechainDefinition& def) {
	// Enter scope
	EonScope* parent = scopes.IsFilled() ? &scopes.Top() : 0;
	EonScope& scope = scopes.Add();
	scope.def = &def;
	scope.SetCurrentState(def_ws);
	
	if (parent) {
		scope.current_state = parent->current_state;
	}
	
	
	for (Eon::SidechainDefinition& d : def.chains) {
		if (!LoadSidechainDefinition(d)) {
			scopes.RemoveLast();
			return false;
		}
	}
	
	if (!SolveLoops(def))
		return false;
	
	for (EonLoopLoader& loop : loops) {
		if (!loop.Load()) {
			scopes.RemoveLast();
			return false;
		}
	}
	
	// Link side-connections
	for (EonLoopLoader& loop0 : loops) {
		for (EonLoopLoader& loop1 : loops) {
			if (&loop0 != &loop1) {
				if (!ConnectSides(loop0, loop1)) {
					AddError("Side connecting failed");
					return false;
				}
			}
		}
	}
	
	loops.Clear();
	
	if (scopes.GetCount() >= 2) {
		EonScope& par = scopes.At(scopes.GetCount()-2);
		const Eon::WorldState& src_ws = scope.current_state;
		Eon::WorldState& dst_ws = par.current_state;
		if (!dst_ws.Append(src_ws, par.def->ret_list)) {
			AddError("Invalid type in return value");
			return false;
		}
	}
	
	
	// Add changes to parent state
	if (parent) {
		if (!parent->current_state.Append(scope.current_state, def.ret_list)) {
			AddError("Invalid type in return value");
			return false;
		}
	}
	
	scopes.RemoveLast();
	return true;
}

bool EonLoader::SolveLoops(Eon::SidechainDefinition& def) {
	loops.Clear();
	for (Eon::LoopDefinition& loop_def : def.loops)
		loops.Add(new EonLoopLoader(this, loop_def));
	if (loops.IsEmpty())
		return true;
	
	bool fail = false;
	enum {FORWARDING, CONNECTING_SIDECHANNEL};
	int mode = FORWARDING;
	int mode_count = 0;
	Vector<EonLoopLoader*> waiting_inputs, waiting_outputs;
	while(!fail) {
		if (mode == FORWARDING) {
			bool ready = true;
			bool keep_going = true;
			waiting_inputs.Clear();
			waiting_outputs.Clear();
			while (keep_going) {
				for (EonLoopLoader& loop : loops) {
					keep_going = loop.Forward() && keep_going;
					fail = fail || loop.IsFailed();
					ready = ready && loop.IsReady();
					if (loop.IsWaitingSideInput()) waiting_inputs.Add(&loop);
					if (loop.IsWaitingSideOutput()) waiting_outputs.Add(&loop);
				}
			}
			if (ready)
				break;
		}
		else if (mode == CONNECTING_SIDECHANNEL) {
			if (waiting_inputs.IsEmpty() && waiting_outputs.IsEmpty()) {
				AddError("Internal error. No waitin sidechannel io.");
				fail = true;
				break;
			}
			
			if (waiting_inputs.IsEmpty()) {
				AddError("No input side-ports");
				fail = true;
				break;
			}
			
			if (waiting_outputs.IsEmpty()) {
				AddError("No output side-ports");
				fail = true;
				break;
			}
			
			for (EonLoopLoader* in : waiting_inputs) {
				EonLoopLoader* accepted_out = 0;
				Eon::ActionPlanner::State* accepted_in_node = 0;
				Eon::ActionPlanner::State* accepted_out_node = 0;
				int accepted_out_count = 0;
				for (EonLoopLoader* out : waiting_outputs) {
					if (in->AcceptOutput(*out, accepted_in_node, accepted_out_node)) {
						accepted_out_count++;
						accepted_out = out;
					}
				}
				if (accepted_out_count > 1) {
					AddError("Input can accept multiple outputs");
					fail = true;
					break;
				}
				if (accepted_out_count == 0) {
					AddError("Input cannot accept any output");
					fail = true;
					break;
				}
				
				int conn_id = tmp_side_id_counter++;
				accepted_in_node->last->SetSideInId(conn_id);
				accepted_out_node->last->SetSideOutId(conn_id);
				
				in				->AddSideConnectionSegment(accepted_in_node,	accepted_out);
				accepted_out	->AddSideConnectionSegment(accepted_out_node,	in);
			}
			
		}
		else Panic("Invalid mode");
		
		
		mode = (mode + 1) % 2;
		if (mode_count++ >= 10)
			break;
	}
	
	return !fail;
}

EntityRef EonLoader::ResolveEntity(Eon::Id& id) {
	ASSERT(es);
	EntityRef e;
	PoolRef p = es->GetRoot();
	int i = 0, count = id.parts.GetCount();
	for (const String& part : id.parts) {
		if (i++ == count - 1) {
			e = p->GetAddEmpty(part);
		}
		else {
			p = p->GetAddPool(part);
		}
	}
	return e;
}

void EonLoader::AddError(String msg) {
	LOG("EonLoader: error: " + msg);
}

bool EonLoader::ConnectSides(EonLoopLoader& loop0, EonLoopLoader& loop1) {
	
	for (ComponentBaseRef& in : loop0.comps) {
		int in_conn = in->GetSideIn();
		if (in_conn < 0)
			continue;
		
		bool found = false;
		for (ComponentBaseRef& out : loop1.comps) {
			int out_conn = out->GetSideOut();
			if (out_conn < 0)
				continue;
			
			if (in_conn == out_conn) {
				found = true;
				
				if (!out->LinkSideIn(in)) {
					AddError("Side-output refused linking to side-input");
					return false;
				}
				if (!in->LinkSideOut(out)) {
					AddError("Side-input refused linking to side-output");
					return false;
				}
				LOG(out->ToString() + "<> side-linked to " + in->ToString() + "<>");
				break;
			}
		}
		
		if (!found) {
			AddError("Could not link connection id " + IntStr(in_conn));
			return false;
		}
	}
	
	
	return true;
}


NAMESPACE_ECS_END
