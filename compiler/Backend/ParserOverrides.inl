void PushFunction(const FileLocation& loc, AstNode& ret_type, const PathIdentifier& name) override;
void PushMetaFunction(const FileLocation& loc, AstNode& ret_type, const PathIdentifier& name) override;
void Parameter(const FileLocation& loc, const PathIdentifier& type, const PathIdentifier& name) override;
void MetaParameter(const FileLocation& loc, const PathIdentifier& type, const PathIdentifier& name) override;
void PopFunctionDefinition(const FileLocation& loc) override;
void PopFunction(const FileLocation& loc) override;
void PopMetaFunction(const FileLocation& loc) override;
void PushStatementList(const FileLocation& loc) override;
void PopStatementList(const FileLocation& loc) override;
void PushStatement(const FileLocation& loc, StmtType type) override;
void PopStatement(const FileLocation& loc) override;
void PushStatementParameter(const FileLocation& loc, StmtParamType t) override;
void PopStatementParameter(const FileLocation& loc) override;
void DeclareVariable(const FileLocation& loc, AstNode& type, const PathIdentifier& name) override;
void DeclareMetaVariable(const FileLocation& loc, AstNode& type, const PathIdentifier& name) override;
void Variable(const FileLocation& loc, const AstNode& n, const PathIdentifier& id) override;
void PushRvalResolve(const FileLocation& loc, const PathIdentifier& id, SemanticType t) override;
void PushRvalUnresolved(const FileLocation& loc, const PathIdentifier& id, SemanticType t) override;
void PushRvalArgumentList(const FileLocation& loc) override;
void Argument(const FileLocation& loc) override;
void PopExpr(const FileLocation& loc) override;
void PushRval(const FileLocation& loc, AstNode& n) override;
void PushRvalConstruct(const FileLocation& loc, AstNode& n) override;
void PushRvalConstant(const FileLocation& loc, const Token& t) override;
void Expr1(const FileLocation& loc, OpType op) override;
void Expr2(const FileLocation& loc, OpType op) override;
void Expr3(const FileLocation& loc, OpType op) override;

void PushSystem(const FileLocation& loc, const PathIdentifier& id) override;
void PopSystem(const FileLocation& loc) override;
void PushPool(const FileLocation& loc, const PathIdentifier& id) override;
void PopPool(const FileLocation& loc) override;
void PushEntity(const FileLocation& loc, const PathIdentifier& id) override;
void PopEntity(const FileLocation& loc) override;
void PushComponent(const FileLocation& loc, const PathIdentifier& id) override;
void PopComponent(const FileLocation& loc) override;
void PushMachine(const FileLocation& loc, const PathIdentifier& id) override;
void PopMachine(const FileLocation& loc) override;
void PushChain(const FileLocation& loc, const PathIdentifier& id) override;
void PopChain(const FileLocation& loc) override;
void PushLoop(const FileLocation& loc, const PathIdentifier& id) override;
void PopLoop(const FileLocation& loc) override;
void PushAtom(const FileLocation& loc, const PathIdentifier& id) override;
void PopAtom(const FileLocation& loc) override;
void PushAtomConnector(const FileLocation& loc, int part) override;
void PopAtomConnector(const FileLocation& loc) override;
void PushState(const FileLocation& loc, const PathIdentifier& id) override;
void PopState(const FileLocation& loc) override;

void PushCall(const FileLocation& loc) override;
void PopCall(const FileLocation& loc) override;
void PopExprCallArgument(const FileLocation& loc, int arg_i) override;
