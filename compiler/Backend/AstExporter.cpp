#include "Backend.h"

NAMESPACE_TOPSIDE_BEGIN


AstExporter::AstExporter() :
	ErrorSource("AstExporter")
{
	
}

bool AstExporter::Process(const AstNode& n) {
	output.Clear();
	PushScope(n);
	Visit(n);
	PopScope();
	
	return true;
}

String AstExporter::GetIndentString(int offset) const {
	ASSERT(indent >= 0);
	ASSERT(!inline_mode);
	String s;
	s.Cat('\t', max(0, indent + offset));
	return s;
}

void AstExporter::PushScope(const AstNode& n) {
	Scope& scope = scopes.Add();
	scope.pop_this = !n.IsPartially(SEMT_UNDEFINED);
	scope.n = &n;
	//if (scope.pop_this)
	if (n.src == SEMT_STATEMENT_BLOCK)
		++indent;
}

void AstExporter::PopScope() {
	if (scopes.Top().n->src == SEMT_STATEMENT_BLOCK) {
		ASSERT(indent > 0);
		--indent;
	}
	scopes.SetCount(scopes.GetCount()-1);
}

void AstExporter::PushInlineScope() {
	InlineScope& is = inline_scopes.Add();
	
}

void AstExporter::PopInlineScope() {
	ASSERT(!inline_scopes.IsEmpty());
	inline_scopes.SetCount(inline_scopes.GetCount()-1);
}

void AstExporter::Visit(const AstNode& n) {
	
	switch (n.src) {
	case SEMT_BUILTIN:
	case SEMT_FUNCTION_BUILTIN:
	case SEMT_META_BUILTIN:
		return;
	
	case SEMT_ROOT:
	case SEMT_IDPART:
	case SEMT_STATEMENT_BLOCK:
		for (const AstNode& s : n.sub) {
			PushScope(s);
			Visit(s);
			PopScope();
		}
		return;
	
	case SEMT_FUNCTION_STATIC:
		VisitFunction(n);
		break;
	
	case SEMT_PARAMETER:
		VisitParameter(n);
		break;
	
	case SEMT_STATEMENT:
		VisitStatement(n);
		break;
		
	case SEMT_EXPR:
		VisitExpression(n, 0);
		break;
		
	case SEMT_CONSTANT:
		VisitConstant(n);
		break;
	
	case SEMT_VARIABLE:
		VisitVariable(n);
		break;
	
	case SEMT_ARGUMENT:
		VisitArgument(n);
		break;
		
	case SEMT_NULL:
	case SEMT_NAMESPACE:
	case SEMT_TYPEDEF:
	case SEMT_CLASS_DECL:
	case SEMT_CLASS:
	case SEMT_CLASS_TEMPLATE:
	case SEMT_FUNCTION_METHOD:
		TODO
		break;
		
	default:
		TODO
	}
	
}

void AstExporter::Visit(const AstNode& n, SemanticType t) {
	for(const AstNode& sub : n.sub) {
		if (sub.IsPartially(t)) {
			PushScope(sub);
			Visit(sub);
			PopScope();
		}
	}
}

void AstExporter::VisitStmt(const AstNode& n, StmtType t) {
	for(const AstNode& sub : n.sub) {
		if (sub.src == SEMT_STATEMENT && sub.stmt == t) {
			PushScope(sub);
			Visit(sub);
			PopScope();
		}
	}
}

void AstExporter::VisitFunction(const AstNode& n) {
	ASSERT(n.src == SEMT_FUNCTION_STATIC);
	
	output << GetIndentString();
	
	output << GetCPath();
	
	PushInlineScope();
	output << "(";
	Visit(n, SEMT_PARAMETER_PATH);
	output << ")";
	PopInlineScope();
	
	const AstNode* block = n.Find(SEMT_STATEMENT_BLOCK);
	if (!block) {
		output << ";\n";
	}
	else {
		output << " {\n";
		Visit(n, SEMT_STATEMENT_BLOCK);
		output << GetIndentString() << "}\n";
	}
}

void AstExporter::VisitParameter(const AstNode& n) {
	ASSERT(inline_scopes.GetCount());
	InlineScope& is = inline_scopes.Top();
	
	if (is.count)
		output << ", ";
	
	output << GetCPath();
	
	is.count++;
}

void AstExporter::VisitStatement(const AstNode& n) {
	
	switch (n.stmt) {
	case STMT_NULL:
		break;
		
	case STMT_FOR:
		ASSERT(inline_scopes.IsEmpty());
		PushInlineScope();
		output << GetIndentString() << "for(";
		VisitStmt(n, STMT_CTOR);
		output << "; ";
		VisitStmt(n, STMT_FOR_COND);
		output << "; ";
		VisitStmt(n, STMT_FOR_POST);
		output << ") {\n";
		PopInlineScope();
		Visit(n, SEMT_STATEMENT_BLOCK);
		output << GetIndentString() << "}\n";
		break;
		
	case STMT_CTOR:
	case STMT_FOR_COND:
	case STMT_FOR_POST:
		for (const AstNode& sub : n.sub)
			Visit(sub);
		break;
		
	case STMT_EXPR:
		output << GetIndentString() << "";
		Visit(n, SEMT_EXPR);
		output << ";\n";
		break;
		
	/*case STMT_LOG:
		output << GetIndentString() << "LOG(";
		PushInlineScope();
		for (const AstNode& sub : n.sub)
			Visit(sub);
		PopInlineScope();
		output << ");\n";
		break;*/
		
	case STMT_IF:
	case STMT_ELSE:
	case STMT_DOWHILE:
	case STMT_WHILE:
	case STMT_FOR_RANGE:
	case STMT_BREAK:
	case STMT_CONTINUE:
	case STMT_CASE:
	case STMT_DEFAULT:
	case STMT_RETURN:
	case STMT_SWITCH:
	case STMT_BLOCK:
	default:
		TODO
		break;
	}
}

void AstExporter::VisitExpression(const AstNode& n, int depth) {
	if (n.src == SEMT_VARIABLE || n.src == SEMT_PARAMETER) {
		VisitVariable(n);
		return;
	}
	else if (n.src == SEMT_CONSTANT) {
		VisitConstant(n);
		return;
	}
	else if (n.src == SEMT_RESOLVE) {
		VisitResolve(n);
		return;
	}
	else if (n.src == SEMT_ARGUMENT_LIST) {
		VisitArgumentList(n);
		return;
	}
	else if (n.IsPartially(SEMT_FUNCTION)) {
		VisitFunctionRval(n);
		return;
	}
	
	ASSERT(n.src == SEMT_EXPR && n.op != OP_NULL);
	
	if (depth > 0)
		output << "(";
	
	switch (n.op) {
	case OP_NULL:
		break;
		
	case OP_INC:
	case OP_DEC:
	case OP_NEGATIVE:
	case OP_POSITIVE:
	case OP_NOT:
	case OP_NEGATE:
		ASSERT(n.link[0]);
		output << GetOpCodeString(n.op);
		VisitExpression(*n.link[0], depth+1);
		break;
		
	case OP_POSTINC:
	case OP_POSTDEC:
		ASSERT(n.link[0]);
		VisitExpression(*n.link[0], depth+1);
		output << GetOpCodeString(n.op);
		break;
	
	case OP_ADD:
	case OP_SUB:
	case OP_MUL:
	case OP_DIV:
	case OP_MOD:
	case OP_LSH:
	case OP_RSH:
	case OP_GREQ:
	case OP_LSEQ:
	case OP_GREATER:
	case OP_LESS:
	case OP_EQ:
	case OP_INEQ:
	case OP_BWAND:
	case OP_BWXOR:
	case OP_BWOR:
	case OP_AND:
	case OP_OR:
	case OP_ASSIGN:
	case OP_ADDASS:
	case OP_SUBASS:
	case OP_MULASS:
	case OP_DIVASS:
	case OP_MODASS:
		ASSERT(n.link[0]);
		ASSERT(n.link[1]);
		VisitExpression(*n.link[0], depth+1);
		output << " " << GetOpCodeString(n.op) << " ";
		VisitExpression(*n.link[1], depth+1);
		break;
		
	case OP_COND:
		ASSERT(n.link[0]);
		ASSERT(n.link[1]);
		ASSERT(n.link[2]);
		output << "(";
		VisitExpression(*n.link[0], depth+1);
		output << ") ? (";
		VisitExpression(*n.link[1], depth+1);
		output << ") : (";
		VisitExpression(*n.link[2], depth+1);
		output << ")";
		break;
		
	case OP_CALL:
		ASSERT(n.link[0]);
		ASSERT(n.link[1]);
		VisitExpression(*n.link[0], depth+1);
		//PushInlineScope();
		VisitExpression(*n.link[1], depth+1);
		//PopInlineScope();
	}
	
	if (depth > 0)
		output << ")";
	
}

void AstExporter::VisitVariable(const AstNode& n) {
	ASSERT(n.src == SEMT_VARIABLE || n.src == SEMT_PARAMETER);
	
	output << GetCPath(n);
	
}

void AstExporter::VisitArgument(const AstNode& n) {
	ASSERT(n.src == SEMT_ARGUMENT);
	
	ASSERT(n.link[0]);
	const AstNode& arg = *n.link[0];
	
	InlineScope& is = inline_scopes.Top();
	if (is.count)
		output << ", ";
	
	if (arg.src == SEMT_CONSTANT) {
		VisitConstant(arg);
	}
	else if (arg.IsPartially(SEMT_FIELD)) {
		output << GetCPath(arg);
	}
	else {
		TODO
	}
	
	is.count++;
}

void AstExporter::VisitConstant(const AstNode& n) {
	ASSERT(n.src == SEMT_CONSTANT);
	
	switch (n.con) {
	case CONST_NULL:	output << "void"; break;
	case CONST_INT32:	output << IntStr((int)n.i64); break;
	case CONST_INT64:	output << IntStr64(n.i64); break;
	case CONST_DOUBLE:	output << DblStr(n.dbl); break;
	case CONST_STRING:	output << "\"" << n.str << "\""; break;
	default:
		TODO
		output << "<internal error>";
		break;
	}
	
}

void AstExporter::VisitResolve(const AstNode& n) {
	/*ASSERT(n.path.GetCount());
	if (n.path.GetCount() > 1) {
		TODO
	}
	else {
		output << n.path[0];
	}*/
	ASSERT(n.link[0]);
	output << GetCPath(*n.link[0]);
}

void AstExporter::VisitArgumentList(const AstNode& n) {
	PushInlineScope();
	output << "(";
	Visit(n, SEMT_ARGUMENT);
	output << ")";
	PopInlineScope();
}

void AstExporter::VisitFunctionRval(const AstNode& n) {
	output << GetCPath(n);
}

String AstExporter::GetCPath() const {
	int c = scopes.GetCount();
	int begin = c-1;
	for(int i = c-2; i >= 0; i--) {
		const Scope& scope = scopes[i];
		if (scope.pop_this)
			break;
		begin = i;
	}
	String s;
	for(int i = begin, j = 0; i < c; i++, j++) {
		const Scope& scope = scopes[i];
		if (j) s.Cat('_');
		s.Cat(scope.n->name);
	}
	return s;
}

String AstExporter::GetCPath(const AstNode& n) const {
	int c = scopes.GetCount();
	int common_i = -1;
	const AstNode* parts[PathIdentifier::MAX_PARTS];
	int part_count = 0;
	for(int i = 0; i < c && common_i < 0; i++) {
		int j = c-1-i;
		const Scope& scope = scopes[j];
		const AstNode* iter = &n;
		part_count = 0;
		while (iter) {
			if (iter == scope.n) {
				common_i = j;
				break;
			}
			parts[part_count++] = iter;
			iter = iter->GetSubOwner();
		}
	}
	if (common_i < 0) {
		TODO
	}
	else {
		String s;
		for (int i = 0; i < part_count; i++) {
			const AstNode* part = parts[part_count - 1 -i];
			if (i) s.Cat('_');
			s.Cat(part->name);
		}
		return s;
	}
}


NAMESPACE_TOPSIDE_END
