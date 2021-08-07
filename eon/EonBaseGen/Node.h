#ifndef _EonBaseGen_Node_h_
#define _EonBaseGen_Node_h_

NAMESPACE_EONGEN_BEGIN



class Node {
	
public:
	typedef enum {
		INVALID,
		LOOP,
		CHAIN,
		TOPCHAIN,
		MACHINE,
		VALID_NODE_LINK,
	} Type;
	
protected:
	friend class World;
	
	Vector<Link*>		links;
	Type				type = INVALID;
	String				key;
	
};



NAMESPACE_EONGEN_END

#endif