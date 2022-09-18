#ifndef _Backend_AstRunner_h_
#define _Backend_AstRunner_h_

NAMESPACE_TOPSIDE_BEGIN


class AstRunner :
	public CompilerNode<AstRunner,NodeBase>,
	public EonStd,
	public ErrorSource
{
	AstNode root;
	
public:
	Object runtime;
	Vector<Object*> rpath;
	
public:
	typedef AstRunner CLASSNAME;
	AstRunner();
	
	
	bool		Execute(AstNode& n);
	bool		Visit(AstNode& n);
	AstNode*	AddDuplicate(AstNode& n);
	bool		VisitMetaRVal(AstNode& n);
	bool		VisitMetaCtor(AstNode& n);
	AstNode*	Merge(AstNode& n);
	AstNode*	MergeStatement(AstNode& n);
	void		PushRuntimeScope(Object& o);
	void		AddRuntimeScope(const FileLocation& loc, String name);
	void		PopRuntimeScope();
	bool		DeclareMetaVariable(AstNode& n);
	bool		IsMergeable(AstNode& prev, AstNode& to_merge) const;
	
	String		GetTreeString(int indent=0) const override;
	String		GetCodeString(const CodeArgs& args) const override;
	String		ToString() const override;
	AstNode&	GetRoot() override;
	
};


NAMESPACE_TOPSIDE_END

#endif
