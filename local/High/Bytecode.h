#ifndef _High_Emitter_h_
#define _High_Emitter_h_

namespace UPP {



struct VmState {
	static const int REG_COUNT = IrValue::REG_COUNT;
	
	
	struct SRVal : Moveable<SRVal> {
		HiValue *lval;
		HiValue  rval;
		HiValue  sbs;

		SRVal()                    { lval = NULL; }
		SRVal(const HiValue& v)    { lval = NULL; rval = v; }
		SRVal(double n)            { lval = NULL; rval = n; }
		SRVal(int64 n)             { lval = NULL; rval = n; }
		SRVal(uint64 n)            { lval = NULL; rval = (int64)n; }
		SRVal(bool n)              { lval = NULL; rval = (int64)n; }
		
		void operator=(const HiValue& v)    { lval = NULL; rval = v; sbs = HiValue();}
		void operator=(double n)            { lval = NULL; rval = n; sbs = HiValue();}
		void operator=(int64 n)             { lval = NULL; rval = n; sbs = HiValue();}
		void operator=(uint64 n)            { lval = NULL; rval = (int64)n; sbs = HiValue();}
		void operator=(bool n)              { lval = NULL; rval = (int64)n; sbs = HiValue();}
		void operator=(const SRVal& v)		{ lval = v.lval; rval = v.rval; sbs = v.sbs; }
	};
	
	Array<SRVal> r_stack;
	Array<SRVal> temp_stack;
	Vector<SRVal> rself_stack;
	Array<HiValue> var_stack;
	Array<HiValue> self_stack;
	Array<Array<SRVal>> argvec_stack;
	HiValue regs[REG_COUNT];
	int pc = 0;
	int max_pc = 0;
	
};

struct HiCompiler : public CParser {
	
protected:
	struct LoopStack : Moveable<LoopStack> {
		IrValue repeat, exit;
		
	};
	
	Vector<IR> ir;
	Vector<LoopStack> loop_stack;
	int lbl_counter = 0;
	
	
	void Emit_(IrCode x, const char* file, int line);
	void Emit1_(IrCode x, IrValue a, const char* file, int line);
	void Emit2_(IrCode x, IrValue a, IrValue b, const char* file, int line);
	void Emit3_(IrCode x, IrValue a, IrValue b, IrValue c, const char* file, int line);
	void EmitLabel_(IrValue l, const char* file, int line);
	//IrValue	EmitMovReg(const IrValue& v, int reg);
	IrValue		EmitPushVar_(const IrValue& v, const char* file, int line);
	IrValue		EmitPopVar_(const IrValue& v, int reg, const char* file, int line);
	IrValue		EmitPopVar_(const IrValue& v, const IrValue& avoid0, const char* file, int line);
	IrValue		EmitSelfLambdaCheck(String id, IrValue& tmp, const char* file, int line);
	IrValue		EmitGlobalLambdaCheck(String id, IrValue& tmp, const char* file, int line);
	IrValue		EmitSelfLvalCheck(const char* file, int line);
	
	IrValue CreateLabel();
	void PushLoop(IrValue exit);
	void PushLoop(IrValue exit, IrValue repeat);
	void CreateSwitchDefault();
	void PopLoop();
	
	void ReadGlobalIr();
	
	void OnError(String msg);
	
public:
	
	/*struct SRVal : Moveable<SRVal> {
		IrValue *lval;
		IrValue  rval;
		IrValue  sbs;

		SRVal()                    { lval = NULL; }
		SRVal(const IrValue& v)    { lval = NULL; rval = v; }
		SRVal(double n)            { lval = NULL; rval = n; }
		SRVal(int64 n)             { lval = NULL; rval = n; }
		SRVal(uint64 n)            { lval = NULL; rval = (int64)n; }
		SRVal(bool n)              { lval = NULL; rval = (int64)n; }
	};*/

	

	//int		skipexp;
	int			r_stack_level;
	int			loop;
	bool		fail = false;
	
	static int stack_level;
	
	void		OutOfMemory();
	
	void		TestLimit();
	void		DoCompare(const IrValue& a, const IrValue& b, const char *op);
	void		DoCompare(const char *op);
	String		ReadName();
	IrValue		IsTrue(const IrValue& v);
	
	IrValue		Get();
	void		Assign(const IrValue& src);

	IrValue		GetExp();
	

	void  Subscript(String id);
	void  Subscript();
	void  Term();
	void  Unary();
	void  Mul();
	void  Add();
	void  Shift();
	void  Compare();
	void  Equal();
	void  BinAnd();
	void  BinXor();
	void  BinOr();
	void  And();
	void  Or();
	void  Cond();
	void  Assign();
	void  Exp();

	void  SkipTerm();
	//void  SkipStatement();
	void  SkipExp();
	IrValue  PCond();
	void  FinishSwitch();
	void  DoStatement();

	void  Run();
	void  WriteLambda(HiLambda& l);
	void  SwapIR(Vector<IR>& ir);

	HiCompiler(const char *s, const String& fn, int line = 1)
	: CParser(s, fn, line)
	{ r_stack_level = stack_level; ReadGlobalIr();}
	~HiCompiler() { stack_level = r_stack_level; }
};



struct IrVM {
	static const int REG_COUNT = 5;
	using SRVal = VmState::SRVal;
	
	
	IrVM*					parent = 0;
	VmState*				s;
	VmState					state;
	TS::RunningFlagSingle	flag;
	int&					op_limit;
	Vector<int>				lbl_pos;
	VectorMap<String, int>	lbl_names;
	bool					fail = 0;
	HiLambda*				fn = 0;
	HiLambda*				call_fn = 0;
	SRVal*					call_self = 0;
	Array<SRVal>*			call_arg = 0;
	String					call_id;
	bool					is_calling = 0;
	bool					is_subcall = 0;
	Array<HiValue>			argvar;
	String					return_argname;
	
	ArrayMap<String, HiValue>&	global;
	ArrayMap<String, HiValue>	var;
	const Vector<IR>&			ir;
	
	IrVM(ArrayMap<String, HiValue>& g, int& op_limit, const Vector<IR>& ir) : global(g), op_limit(op_limit), ir(ir) {s = &state;}
	
	int		InitLambdaExecution(HiLambda& l, IrVM& parent);
	void	ExecuteInstruction(const IR& ir);
	void	ExecuteEscape();
	void	SetReturnArg(IrVM& vm, String arg);
	void	InitSubcall();
	void	FinishSubcall();
	void	FinishArgument();
	bool	Execute();
	bool	RefreshLabels(const Vector<IR>& ir);
	void	Get();
	void    Get(const SRVal& r, HiValue& v);
	void    Get0(SRVal& r, HiValue& v);
	bool	IsRunning() const {return flag.IsRunning();}
	void	SetNotRunning() {flag.SetNotRunning();}
	void	OnError(String msg);
	void	ThrowError(String msg);
	void	TestLimit();
	void	AddAssign1(SRVal& r, const HiValue& a, const HiValue& b);
	void	AddAssign2(SRVal& r, const HiValue& a, const HiValue& b);
	void	OutOfMemory();
	void	WriteRegister(const IrValue& reg, const HiValue& v);
	HiValue	ReadVar(const IrValue& v);
	void	Jump(const IrValue& v);
	void	Assign(const SRVal& val, const HiValue& src);
	void	Assign(HiValue& val, const Vector<HiValue>& sbs, int si, const HiValue& src);
	double	DoCompare(const HiValue& a, const HiValue& b, const char *op);
	HiValue	MulArray(HiValue array, HiValue times);
	//HiValue	ExecuteLambda(const String& id, HiValue& lambda, SRVal& self, Array<SRVal>& arg);
	void	BeginExecutingLambda(const String& id, HiValue& lambda, SRVal& self, Array<SRVal>& arg);
	
	double	Number(const HiValue& a, const char *oper);
	int64	Int(const HiValue& a, const char *oper);
	double	Number(const SRVal& a, const char *oper);
	int64	Int(const SRVal& a, const char *oper);
	String	Lims(const String& s) const;
	
	HiValue&	Self();
	
};

class Hi {
	ArrayMap<String, HiValue>& global;
	int& oplimit;
	
	typedef enum {
		EVALX,
		SUBCALL,
		LAMBDA,
		STRING,
		FN_NAME,
	} CallType;
		
	struct Call {
		CallType type;
		One<IrVM> vm;
		IrVM* parent = 0;
		int parent_arg_i = -1;
		HiLambda* l = 0;
		HiLambda* scope_l = 0;
		HiValue lambda;
		String fn, code;
		int line = 0;
		bool get_exp = false;
		IrValue out_var;
		Vector<IR> tmp_ir;
	};
		
	Array<Call> calls;
	HiValue self;
	bool fail = false;
	
	
public:
	Hi(ArrayMap<String, HiValue>& global, const char *s, int& oplimit,
	    const String& fn, int line = 1)
		: global(global), oplimit(oplimit) {
	    Call& c = calls.Add();
	    c.type = STRING;
	    c.fn = fn;
	    c.code = s;
	    c.line = line;
	}
	
	Hi(ArrayMap<String, HiValue>& global, int& oplimit, HiLambda& l)
		: global(global), oplimit(oplimit) {
	    Call& c = calls.Add();
	    c.type = LAMBDA;
	    c.l = &l;
	}
	
	void		Run();
	double		Number(const HiValue& a, const char *oper);
	int64		Int(const HiValue& a, const char *oper);
	
	HiValue&	VarGetAdd(const HiValue& key);
	HiValue		GetExp();
	void		OnError(String s);
	
	ArrayMap<String, HiValue>& Var();
	HiValue& Self();
	
	
	
	HiValue return_value;
	
};


}

#endif
