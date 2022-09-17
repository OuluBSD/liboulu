#include "Backend.h"

NAMESPACE_TOPSIDE_BEGIN


AstNode::AstNode() {
	
}

void AstNode::CopyFrom(const AstNode& n) {
	sub.Clear();
	
	name = n.name;
	src = n.src;
	stmt = n.stmt;
	op = n.op;
	con = n.con;
	filter = n.filter;
	i64 = n.i64;
	str = n.str;
	loc = n.loc;
	
	type = n.type ? n.type->next : 0;
	for(int i = 0; i < AstNode::LINK_COUNT; i++)
		link[i] = n.link[i] ? n.link[i]->next : 0;
	
}

AstNode& AstNode::Add(const FileLocation& loc, String name, int idx) {
	ASSERT(!locked);
	AstNode& s =
		idx >= 0 ? sub.Insert(idx) : sub.Add();
	s.SetOwner(this);
	s.name = name;
	s.loc = loc;
	return s;
}

AstNode& AstNode::GetAdd(const FileLocation& loc, String name) {
	ASSERT(name.GetCount());
	AstNode* p = Find(name);
	if (p)
		return *p;
	else
		return Add(loc, name);
}

AstNode& AstNode::GetAdd(const FileLocation& loc, SemanticType accepts) {
	ASSERT(name.GetCount());
	for (AstNode& s : sub) {
		if (s.IsPartially(accepts))
			return s;
	}
	AstNode& s = Add(loc);
	s.src = accepts;
	if (accepts == SEMT_TYPE_POINTER)
		s.name = "#";
	else if (accepts == SEMT_TYPE_LREF)
		s.name = "&";
	
	return s;
}

AstNode* AstNode::Find(String name, SemanticType accepts) {
	ASSERT(name.GetCount());
	for (auto& s : sub)
		if (s.name == name && (accepts == SEMT_NULL || s.IsPartially(accepts)))
			return &s;
	return 0;
}

const AstNode* AstNode::Find(String name, SemanticType accepts) const {
	ASSERT(name.GetCount());
	for (auto& s : sub)
		if (s.name == name && (accepts == SEMT_NULL || s.IsPartially(accepts)))
			return &s;
	return 0;
}

AstNode* AstNode::Find(SemanticType t) {
	for (auto& s : sub)
		if (s.src == t)
			return &s;
	return 0;
}

const AstNode* AstNode::Find(SemanticType t) const {
	for (auto& s : sub)
		if (s.src == t)
			return &s;
	return 0;
}

String AstNode::GetConstantString() const {
	String s = GetConstString(con) + ": ";
	switch (con) {
		case CONST_NULL:	s += "null"; break;
		case CONST_INT32:	s += IntStr(i64); break;
		case CONST_INT64:	s += IntStr64(i64); break;
		case CONST_DOUBLE:	s += DblStr(dbl); break;
		case CONST_STRING:	s += "\"" + str + "\""; break;
		default: break;
	}
	return s;
}

String AstNode::GetTreeString(int indent) const {
	String s;
	s.Cat('\t', indent);
	
	s << GetSemanticTypeString(src) << ": ";
	
	if (name.GetCount())
		s << name << "\n";
	else if (src == SEMT_CONSTANT)
		s << "const(" << GetConstantString() << ")\n";
	else if (src == SEMT_STATEMENT)
		s << "stmt(" << GetStmtTypeString(stmt) << ")\n";
	else if (op != OP_NULL)
		s << "op(" << GetOpString(op) << ")\n";
	else if (filter != SEMT_NULL)
		s << "filter(" << GetSemanticTypeString(filter) << ")\n";
	else if (src == SEMT_RVAL && link[0])
		s << link[0]->GetName() << "\n";
	else
		s << "\n";
	
	//else if (src != SEMT_NULL)
	//	s << "src(" << GetSemanticTypeString(src) << ")\n";
	
	for (const AstNode& n : sub) {
		s << n.GetTreeString(indent+1);
	}
	return s;
}

String AstNode::GetCodeString(const CodeArgs& args) const {
	TODO
}

String AstNode::ToString() const {
	return name;
}

String AstNode::GetPath() const {
	static const int MAX_PATH_LEN = 32;
	const AstNode* path[MAX_PATH_LEN];
	const AstNode* cur = this;
	int count = 0;
	while (cur) {
		path[count] = cur;
		cur = cur->GetSubOwner();
		count++;
	}
	
	String s;
	for(int i = count-1, j = 0; i >= 0; i--, j++) {
		if (j) s += ".";
		s += path[i]->GetName();
	}
	return s;
}

String AstNode::GetPartStringArray() const {
	static const int MAX_PATH_LEN = 32;
	const AstNode* path[MAX_PATH_LEN];
	const AstNode* cur = this;
	int count = 0;
	while (cur) {
		if (cur->IsPartially((SemanticType)(
				SEMT_PATH | SEMT_TYPE | SEMT_FIELD | SEMT_META_TYPE | SEMT_META_FIELD)))
			path[count++] = cur;
		cur = cur->GetSubOwner();
	}
	
	String s;
	s.Cat('[');
	for(int i = count-1, j = 0; i >= 0; i--, j++) {
		if (j) s += ", \"";
		else s.Cat('\"');
		s.Cat(path[i]->GetName());
		s.Cat('\"');
	}
	s.Cat(']');
	return s;
}


NAMESPACE_TOPSIDE_END
