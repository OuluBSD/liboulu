#ifndef _SoftRend_Compiler_h_
#define _SoftRend_Compiler_h_

NAMESPACE_TOPSIDE_BEGIN


class SoftCompiler {
	
	
public:
	typedef SoftCompiler CLASSNAME;
	SoftCompiler();
	
	
	bool Compile(SoftShader& s);
	
};


NAMESPACE_TOPSIDE_END

#endif
