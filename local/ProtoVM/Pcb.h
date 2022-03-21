#ifndef _ProtoVM_Pcb_h_
#define _ProtoVM_Pcb_h_


class Machine;


class Pcb {
	
protected:
	friend class Machine;
	Machine* mach = 0;
	Array<ElectricNodeBase> nodes;
	
	
public:
	
	
	template <class T>
	T& Add(String name="") {
		T* o = new T();
		o->pcb = this;
		o->name = name;
		nodes.Add(o);
		return *o;
	}
	
	ENode& AddNode(String name);
	ElcBase& AddReferenceSingle(ElcBase& n, int pin_i);
	
	void Attach(ElectricNodeBase& from, ElectricNodeBase& to);
	
};


template <int Width>
class Bus : public ElcBase {
	RTTI_DECL1(Bus, ElcBase);
	
	
	
};


using Bus8 = Bus<8>;
using Bus16 = Bus<16>;


#endif
