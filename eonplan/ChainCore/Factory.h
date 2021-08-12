#ifndef _ChainCore_Factory_h_
#define _ChainCore_Factory_h_

NAMESPACE_PLAN_BEGIN


class ValSpec;
class DevSpec;
class ValDevSpec;


class Factory {
public:
	
	struct Project {
		String name;
		Index<String> deps;
		
		void Set(String s) {name = s; deps.Clear();}
		String ToString() const {return name;}
	};
	
public:
	struct Generic {
		Project* prj = 0;
		const char* name;
		
	};
public:
	struct Val : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Val>& Vals() {static ArrayMap<String,Val> a; return a;}
	
	
public:
	struct Dev : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Dev>& Devs() {static ArrayMap<String,Dev> a; return a;}
	
	
public:
	struct ValDev : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,ValDev>& ValDevs() {static ArrayMap<String,ValDev> a; return a;}
	
	
public:
	struct Base : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Base>& Bases() {static ArrayMap<String,Base> a; return a;}
	
	
public:
	struct Header : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Header>& Headers() {static ArrayMap<String,Header> a; return a;}
	
	
public:
	struct Loop : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Loop>& Loops() {static ArrayMap<String,Loop> a; return a;}
	
	
public:
	struct Link : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Link>& Links() {static ArrayMap<String,Link> a; return a;}
	
public:
	struct Chain : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Chain>& Chains() {static ArrayMap<String,Chain> a; return a;}
	
public:
	struct Scope : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Scope>& Scopes() {static ArrayMap<String,Scope> a; return a;}
	
public:
	struct Machine : Generic {
		
		String ToString() const;
	};
	
	static ArrayMap<String,Machine>& Machines() {static ArrayMap<String,Machine> a; return a;}
	
	
public:
	typedef Factory CLASSNAME;
	Factory() = delete;
	
	
	template <class T> static
	void RegVal(const char* name) {
		Val& v = Vals().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegDev(const char* name) {
		Dev& v = Devs().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegValDev(const char* name) {
		ValDev& v = ValDevs().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegBase(const char* name, const char* sink, const char* side, const char* src) {
		Base& v = Bases().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegHeader(const char* name, const char* base) {
		Header& v = Headers().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegLoop(const char* name, const char* headers) {
		Loop& v = Loops().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class F, class T> static
	void RegLink(const char* name, const char* from, const char* to) {
		Link& v = Links().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegChain(const char* name, const char* loops, const char* links) {
		T::LinkString() = links;
		Chain& v = Chains().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegScope(const char* name, const char* chains, const char* links) {
		T::LinkString() = links;
		Scope& v = Scopes().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	template <class T> static
	void RegMachine(const char* name, const char* scopes, const char* links) {
		T::LinkString() = links;
		Machine& v = Machines().Add(name);
		v.prj = ActiveProject();
		v.name = name;
		
	}
	
	static ArrayMap<String,Project>& Projects() {static ArrayMap<String,Project> a; return a;}
	static Project*& ActiveProject() {static Project* p; return p;}
	static void SetActiveProject(String prj) {auto p = &Projects().Add(prj); p->name = prj; ActiveProject() = p;}
	static void AddDep(String prj) {ActiveProject()->deps.FindAdd(prj);}
	static void Dump();
	static bool ExportAll();
	static bool Export(String dir, String prj);
	static bool ExportComplete(String dir);
	
};


NAMESPACE_PLAN_END

#endif
