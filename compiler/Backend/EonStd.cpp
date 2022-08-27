#include "Backend.h"

NAMESPACE_TOPSIDE_BEGIN


String EonStd::GetPathString() const {
	String s;
	for (const Scope& scope : spath) {
		if (!s.IsEmpty())
			s.Cat('.');
		s << scope.n->GetName();
	}
	return s;
}

void EonStd::AddBuiltinType(String name) {
	AstNode& root = GetRoot();
	AstNode& sn = root.Add(name);
	sn.src = SEMT_BUILTIN;
}

String EonStd::GetRelativePartStringArray(const AstNode& n) const {
	ASSERT(!spath.IsEmpty());
	AstNode* top = spath.Top().n;
	AstNode* root = spath[0].n;
	ASSERT(top != &n);
	
	const AstNode* nodes[PathIdentifier::MAX_PARTS];
	int node_count = 0;
	const AstNode* iter = &n;
	while (iter && iter != top && iter != root) {
		nodes[node_count++] = iter;
		iter = iter->GetSubOwner();
	}
	
	String s = "[";
	for(int i = 0; i < node_count; i++) {
		if (i) s.Cat(',');
		s.Cat('\"');
		s.Cat(nodes[node_count-1-i]->name);
		s.Cat('\"');
	}
	s.Cat(']');
	//DUMP(s)
	return s;
}

void EonStd::InitDefault() {
	AddBuiltinType("void");
	AddBuiltinType("int");
	AddBuiltinType("long");
	AddBuiltinType("uint");
	AddBuiltinType("ulong");
	AddBuiltinType("float");
	AddBuiltinType("double");
	AddBuiltinType("byte");
	AddBuiltinType("char");
	AddBuiltinType("short");
	AddBuiltinType("ushort");
	AddBuiltinType("cstring");
	
	GetRoot().src = SEMT_ROOT;
	
	spath.Add().Set(&GetRoot(),true);
}

bool EonStd::ForwardUserspace(AstNode*& n) {
	if (!n) return false;
	
	if (n->IsPartially(SEMT_FUNCTION)) {
		n = n->Find(FN_BLOCK_NAME);
		return n != NULL;
	}
	if (n->IsPartially(SEMT_STATEMENT)) {
		switch (n->stmt) {
			case STMT_FOR:
				n = n->Find(FN_BLOCK_NAME);
				break;
			
			case STMT_FOR_COND:
			case STMT_FOR_POST:
			case STMT_FOR_RANGE:
			case STMT_LOG:
			case STMT_BLOCK:
				return false;
				
			case STMT_IF:
			case STMT_ELSE:
			case STMT_DOWHILE:
			case STMT_WHILE:
			case STMT_BREAK:
			case STMT_CONTINUE:
			case STMT_CASE:
			case STMT_DEFAULT:
			case STMT_RETURN:
			case STMT_SWITCH:
				TODO
				
			default:
			case STMT_NULL:
				break;
		}
	}
	return false;
}

AstNode* EonStd::FindDeclaration(const PathIdentifier& id, SemanticType accepts) {
	if (id.part_count == 0)
		return 0;
	
	for (int i = spath.GetCount()-1; i >= 0; i--) {
		Scope& s = spath[i];
			
		AstNode* n = GetDeclaration(s.n, id, accepts);
		if (n)
			return n;
	}
	return 0;
}

AstNode* EonStd::FindTypeDeclaration(const PathIdentifier& id) {
	return FindDeclaration(id, SEMT_TYPE);
}

AstNode* EonStd::GetDeclaration(const PathIdentifier& id, SemanticType accepts) {
	if (id.part_count == 0 || spath.IsEmpty())
		return 0;
	
	Scope& s = spath[0];
	return GetDeclaration(s.n, id, accepts);
}

AstNode* EonStd::GetDeclaration(AstNode* owner, const PathIdentifier& id, SemanticType accepts) {
	AstNode* cur = owner;
	AstNode* next = 0;
	AstNode* prev = 0;
	for(int i = 0; i < id.part_count; i++) {
		next = 0;
		for (int tries = 0; tries < 100; tries++) {
			const Token* t = id.parts[i];
			if (t->IsType(TK_ID) || t->IsType(TK_INTEGER)) {
				next = cur->Find(t->str_value);
			}
			else {
				TODO
			}
			
			if (!next) {
				if (ForwardUserspace(cur)) {
					ASSERT(cur);
					continue;
				}
				else
					return 0;
			}
			else break;
		}
		
		ASSERT(next);
		prev = cur;
		cur = next;
	}
	
	if (cur) {
		if (accepts == SEMT_NULL)
			return cur;
		if (cur->IsPartially(accepts))
			return cur;
	}
	
	return 0;
}

AstNode& EonStd::DeclareRelative(const PathIdentifier& id) {
	ASSERT(id.part_count > 0);
	AstNode* cur = spath.Top().n;
	for(int i = 0; i < id.part_count; i++) {
		const Token* t = id.parts[i];
		if (t->IsType(TK_ID) || t->IsType(TK_INTEGER)) {
			String id = t->str_value;
			ASSERT(id.GetCount());
			cur = &cur->GetAdd(id);
			if (cur->src == SEMT_NULL)
				cur->src = SEMT_IDPART;
		}
		else {
			TODO
		}
	}
	
	//LOG("Declared " << GetPath(*cur));
	
	return *cur;
}

void EonStd::PushScope(AstNode& n) {
	ASSERT(!spath.IsEmpty());
	thread_local static Vector<AstNode*> tmp;
	AstNode* cur = spath.Top().n;
	
	tmp.SetCount(0);
	AstNode* iter = &n;
	while (iter && iter != cur) {
		tmp.Add(iter);
		iter = iter->GetSubOwner();
	}
	ASSERT(iter == cur);
	
	for (int i = tmp.GetCount()-1, j = 0; i >= 0; i--, j++) {
		Scope& s = spath.Add();
		s.n = tmp[i];
		s.pop_this = j == 0;
	}
}

// Returns links to variables in expression statements etc.
// The scope path is not continous, unlike with LVal.
// ~ The scope stack grows from left, and sometimes meet's it's end from the right side. ~
void EonStd::PushScopeRVal(AstNode& n) {
	Scope& s = spath.Add();
	s.n = &n;
	s.pop_this = true;
}

void EonStd::PopScope() {
	int rm_i = 0;
	for (int i = spath.GetCount()-1; i >= 0; i--) {
		Scope& s = spath[i];
		if (s.pop_this) {
			rm_i = i;
			break;
		}
	}
	int c = spath.GetCount() - rm_i;
	spath.Remove(rm_i, c);
}


NAMESPACE_TOPSIDE_END
