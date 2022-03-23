#ifndef _ProtoVM_Component_h_
#define _ProtoVM_Component_h_



struct Pin : public ElcBase {
	RTTI_DECL1(Pin, ElcBase);
	
	bool is_ref_volt = false;
	double voltage;
	
	Pin();
	Pin& SetReference(double voltage);
	
};

struct Port : public ElcBase {
	RTTI_DECL1(Port, ElcBase);
	
	Array<Pin> pins;
	
	
	void SetCount(int i) {pins.SetCount(i);}
	
	Pin& GetPin(int i) {return pins[i];}
	
};


//template <int Ohm>
class Resistor : public ElcBase {
	RTTI_DECL1(Resistor, ElcBase);
	
	
public:
	Resistor() {
		AddSink("A");
		AddSource("B");
		
	}
	
	
	
};

using Resistor4k7 = Resistor;//<4700>;



class Crystal : public ElcBase {
	RTTI_DECL1(Crystal, ElcBase);
	int hz = 0;
	
public:
	Crystal();
	
};




class ElcNor : public ElcBase {
	RTTI_DECL1(ElcNor, ElcBase);
	
	
public:
	ElcNor();
	
};


class ElcNand : public ElcBase {
	RTTI_DECL1(ElcNand, ElcBase);
	
	
public:
	ElcNand();
	
};


class ElcNot : public ElcBase {
	RTTI_DECL1(ElcNot, ElcBase);
	
	
public:
	ElcNot();
	
};


class ElcCapacitor : public ElcBase {
	RTTI_DECL1(ElcCapacitor, ElcBase);
	
	
public:
	ElcCapacitor();
	
};


class FlipFlopJK : public ElcBase {
	RTTI_DECL1(FlipFlopJK, ElcBase);
	
public:
	FlipFlopJK();
	
	
};


#endif
