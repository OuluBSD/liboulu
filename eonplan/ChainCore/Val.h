#ifndef _ChainCore_Val_h_
#define _ChainCore_Val_h_

NAMESPACE_PLAN_BEGIN


class ValSpec {
	
public:
	
	
};



#define VAL_LIST \
	VAL(Order) \
	VAL(Receipt) \
	VAL(Audio) \
	VAL(Video) \
	VAL(Midi) \
	VAL(Event)

#define VAL2_LIST(x) \
	VAL2(x, Order) \
	VAL2(x, Receipt) \
	VAL2(x, Audio) \
	VAL2(x, Video) \
	VAL2(x, Midi) \
	VAL2(x, Event)


#define VAL(x) \
	class x : public ValSpec { \
		 \
	public: \
		 \
	};
VAL_LIST
#undef VAL


NAMESPACE_PLAN_END

#endif