#include "Internal.h"


NAMESPACE_SERIAL_BEGIN

String GetScriptStatusLine(int indent, ScriptStatus status, String extra_str) {
	String s;
	s.Cat('\t', indent);
	const char* t = GetScriptStatusString(status);
	s << "-> " << t;
	if (extra_str.GetCount())
		s << " (" << extra_str << ")";
	s.Cat('\n');
	return s;
}





int ScriptLoader::loop_counter = 0;



ScriptLoader::~ScriptLoader() {
	//LOG("~ScriptLoader");
}

bool ScriptLoader::Initialize() {
	def_ws.SetActionPlanner(def_planner);
	
	es = GetMachine().Find<LoopStore>();
	if (!es) {
		LOG("ScriptLoader requires LoopStore present in machine");
		return false;
	}
	
	if (!DoPostLoad())
		return false;
	
	RTLOG("ScriptLoader::Initialize success!");
	return true;
}

bool ScriptLoader::DoPostLoad() {
	bool success = true;
	
	while (!post_load_file.IsEmpty()) {
		String path = post_load_file[0];
		post_load_file.Remove(0);
		
		if (!LoadFile(path))
			success = false;
	}
	
	while (!post_load_string.IsEmpty()) {
		String s = post_load_string[0];
		post_load_string.Remove(0);
		
		if (!Load(s, "input"))
			success = false;
	}
	
	return success;
}

void ScriptLoader::Start() {
	
}

void ScriptLoader::Update(double dt) {
	
	if (!DoPostLoad()) {
		GetMachine().SetNotRunning();
	}
	
}

void ScriptLoader::Stop() {
	
}

void ScriptLoader::Uninitialize() {
	
}

bool ScriptLoader::LoadFile(String path) {
	if (!FileExists(path)) {
		LOG("Could not find EON file");
		return false;
	}
	String eon = TS::LoadFile(path);
	return Load(eon, path);
}

bool TestParseScriptCode(String content) {
	Script::Parser p;
	if (!p.Parse(content, "<file>")) {
		LOG(GetLineNumStr(content, 1));
		return false;
	}
	p.Dump();
	return true;
}

bool ScriptLoader::Load(const String& content, const String& filepath) {
	RTLOG("ScriptLoader::Load: Loading \"" << filepath << "\"");
	
	Script::Parser p;
	if (!p.Parse(content, filepath)) {
		RTLOG(GetLineNumStr(content, 1));
		return false;
	}
	p.Dump();
	MemSwap(p.GetResult(), root);
	
	if (!LoadAtomilationUnit(root)) {
		LOG("error dump:"); loader->Dump();
		DumpErrors();
		
		Cleanup();
		return false;
	}
	
	if (!ImplementScript()) {
		DumpErrors();
		
		Cleanup();
		return false;
	}
	
	Cleanup();
	return true;
}

void ScriptLoader::Cleanup() {
	loader.Clear();
}

void ScriptLoader::DumpErrors() {
	Vector<ScriptLoopLoader*> loops;
	loader->GetLoops(loops);
	for (ScriptLoopLoader* ll : loops) {
		if (ll->GetStatus() == ScriptStatus::FAILED) {
			LOG("ScriptLoopLoader: error: " << ll->GetErrorString());
		}
	}
}

bool ScriptLoader::ImplementScript() {
	Vector<ScriptDriverLoader*> drivers;
	loader->GetDrivers(drivers);
	for (ScriptDriverLoader* dl: drivers) {
		if (!dl->Load())
			return false;
	}
	
	Vector<ScriptLoopLoader*> loops;
	loader->GetLoops(loops);
	for (ScriptLoopLoader* ll : loops) {
		if (!ll->Load())
			return false;
	}
	
	for (ScriptLoopLoader* loop0 : loops) {
		for (ScriptLoopLoader* loop1 : loops) {
			if (loop0 != loop1) {
				if (!ConnectSides(*loop0, *loop1)) {
					AddError("Side connecting failed");
					return false;
				}
			}
		}
	}
	
	for (ScriptDriverLoader* dl: drivers) {
		if (!dl->PostInitialize())
			return false;
	}
	
	for (ScriptLoopLoader* ll : loops) {
		if (!ll->PostInitialize())
			return false;
	}
	
	return true;
}

bool ScriptLoader::LoadAtomilationUnit(Script::AtomilationUnit& cunit) {
	return LoadGlobalScope(cunit.list);
}

bool ScriptLoader::LoadGlobalScope(Script::GlobalScope& glob) {
	//EnterScope();
	//scopes.Top().glob = &glob;
	scopes.Add(&glob);
	
	loader = new ScriptSystemLoader(*this, 0, glob);
	
	int dbg_i = 0;
	while (!loader->IsFailed() && !loader->IsReady()) {
		DUMP(dbg_i);
		loader->Dump();
		
		loader->Forward();
		++dbg_i;
		
		ASSERT_(dbg_i < 100, "Something probably broke");
	}
	
	
	scopes.Remove(scopes.GetCount()-1);
	
	return loader->IsReady();
}

LoopRef ScriptLoader::ResolveLoop(Script::Id& id) {
	ASSERT(es);
	LoopRef e;
	LoopRef p = es->GetRoot();
	int i = 0, count = id.parts.GetCount();
	for (const String& part : id.parts) {
		if (i++ == count - 1) {
			e = p->GetAddEmpty(part);
		}
		else {
			p = p->GetAddLoop(part);
		}
	}
	return e;
}

void ScriptLoader::AddError(String msg) {
	if (!collect_errors) {
		LOG("ScriptLoader: error: " + msg);
	}
	else {
		ScriptError& e = errs.Add();
		e.msg = msg;
	}
}

void ScriptLoader::AddError(ScriptLoopLoader* ll, String msg) {
	if (!collect_errors) {
		LOG("ScriptLoader: error: " + msg);
	}
	else {
		ScriptError& e = errs.Add();
		e.ll = ll;
		e.status = ll->GetStatus();
		e.msg = msg;
	}
}

void ScriptLoader::ReleaseErrorBuffer() {
	if (errs.GetCount()) {
		ScriptError& e = errs.Top();
		LOG("ScriptLoader: error: " + e.msg);
		errs.Clear();
	}
}

void ScriptLoader::ClearErrorBuffer() {
	for (ScriptError& e : errs) {
		if (e.ll && e.ll->IsFailed() && e.status >= 0)
			e.ll->SetStatus(e.status);
	}
	errs.Clear();
}

bool ScriptLoader::ConnectSides(ScriptLoopLoader& loop0, ScriptLoopLoader& loop1) {
	
	int dbg_i = 0;
	for (AtomBaseRef& sink : loop0.atoms) {
		for (int sink_conn : sink->GetSideSinks()) {
			RTLOG("Trying to side-link id " << sink_conn);
			bool found = false;
			for (AtomBaseRef& src : loop1.atoms) {
				for (int src_conn : src->GetSideSources()) {
					if (sink_conn == src_conn) {
						found = true;
						
						int src_ch_i = 1 + src->GetSideSinkCount();
						int sink_ch_i = 1 + sink->GetSideSourceCount();
						
						if (!src->LinkSideSink(sink, src_ch_i, sink_ch_i)) {
							AddError("Side-source refused linking to side-src");
							return false;
						}
						if (!sink->LinkSideSource(src, sink_ch_i, src_ch_i)) {
							AddError("Side-src refused linking to side-source");
							return false;
						}
						
						LOG(src->ToString() + "(" << src_ch_i << ") side-linked to " + sink->ToString() + "(" << sink_ch_i << ")");
						
						
						loop0.UpdateLoopLimits();
						loop1.UpdateLoopLimits();
						break;
					}
				}
			}
			
			/*if (!found) {
				AddError("Could not link connection id " + IntStr(in_conn));
				return false;
			}*/
			
			dbg_i++;
		}
	}
	
	
	return true;
}

Script::State* ScriptLoader::FindState(const Script::Id& id) {
	auto iter = scopes.rbegin();
	auto end = scopes.rend();
	for(; iter != end; --iter) {
		Script::GlobalScope& glob = **iter;
		for (Script::State& state : glob.states) {
			if (state.id == id) {
				return &state;
			}
		}
	}
	return NULL;
}

bool ScriptConnectionSolver::Process() {
	Vector<ScriptLoopLoader*>	waiting_sources;
	Vector<ScriptLoopLoader*>	waiting_sinks;
	
	is_waiting_source = false;
	is_waiting_sink = false;
	
	for (ScriptLoopLoader* ll : loops) {
		if (ll->IsStatus(ScriptStatus::SOURCE_IS_WAITING))
			waiting_sources.Add(ll);
		if (ll->IsStatus(ScriptStatus::SINK_IS_WAITING))
			waiting_sinks.Add(ll);
	}
	
	if (waiting_sources.IsEmpty() && waiting_sinks.IsEmpty()) {
		SetError("Internal error. No any waiting sidechannel io exists.");
		return false;
	}
	
	if (waiting_sources.IsEmpty()) {
		SetError("No side-sources");
		is_waiting_sink = true; // because waiting_sinks.count > 0
		return false;
	}
	
	if (waiting_sinks.IsEmpty()) {
		SetError("No side-sinks");
		is_waiting_source = true; // because waiting_sources.count > 0
		return false;
	}
	
	Vector<ScriptLoopLoader*> retry_list;
	
	int accepted_count = 0;
	for (ScriptLoopLoader* src : waiting_sources) {
		ScriptLoopLoader* accepted_sink = 0;
		Script::ActionPlanner::State* accepted_src_node = 0;
		Script::ActionPlanner::State* accepted_sink_node = 0;
		int accepted_sink_count = 0;
		bool accepted_all_multi = true;
		int dbg_i = 0;
		for (ScriptLoopLoader* sink : waiting_sinks) {
			if (!src->IsFailed() &&
				!sink->IsFailed()) {
				RTLOG("ScriptConnectionSolver::Process: #" << dbg_i << " check fail state: src " << HexStr(src) << " against sink " << HexStr(sink) << ": passed");
				SideStatus s = src->AcceptSink(*sink, accepted_src_node, accepted_sink_node);
				if (s == SIDE_ACCEPTED || s == SIDE_ACCEPTED_MULTI) {
					ASSERT(accepted_src_node && accepted_sink_node);
					accepted_sink_count++;
					accepted_sink = sink;
					if (s != SIDE_ACCEPTED_MULTI)
						accepted_all_multi = false;
				}
			}
			else {
				RTLOG("ScriptConnectionSolver::Process: #" << dbg_i << " check fail state: src " << HexStr(src) << " against sink " << HexStr(sink) << ": failed");
			}
			dbg_i++;
		}
		if (!accepted_all_multi && accepted_sink_count > 1) {
			SetError("source loop " + IntStr(src->GetId()) + " can accept multiple sinks");
			return false;
		}
		if (accepted_sink_count == 0) {
			SetError("source loop " + IntStr(src->GetId()) + " cannot accept any sink");
			is_waiting_sink = true;
			continue;
		}
		
		ASSERT(accepted_sink);
		AtomTypeCls src_type = accepted_src_node->last->GetWorldState().GetAtom();
		AtomTypeCls sink_type = accepted_sink_node->last->GetWorldState().GetAtom();
		src->SetSideSourceConnected(src_type, accepted_src_node->ch_i, accepted_sink);
		accepted_sink->SetSideSinkConnected(sink_type, accepted_sink_node->ch_i, src);
		
		int conn_id = tmp_side_id_counter++;
		accepted_src_node->last->SetSideSinkId(conn_id);
		accepted_sink_node->last->SetSideSrcId(conn_id);
		
		LOG("Loop src " << src->GetId() << " ch " << accepted_src_node->ch_i << " accepted loop sink "
			<< accepted_sink->GetId() << " ch " << accepted_sink_node->ch_i << " with id " << conn_id);
		
		
		if (src->IsAllSidesConnected()) {
			LOG("Loop " << src->GetId() << " all sides connected");
			src->AddSideConnectionSegment(accepted_src_node, accepted_sink, accepted_sink_node);
			src->ClearSides();
			retry_list.Add(src);
		}
		
		if (accepted_sink->IsAllSidesConnected()) {
			LOG("Loop " << accepted_sink->GetId() << " all sides connected");
			accepted_sink->AddSideConnectionSegment(accepted_sink_node,	src, accepted_src_node);
			accepted_sink->ClearSides();
			retry_list.Add(accepted_sink);
		}
		
		++accepted_count;
	}
	
	for (ScriptLoopLoader* ll : retry_list)
		ll->SetStatusRetry();
	
	return accepted_count > 0;
}

NAMESPACE_SERIAL_END
