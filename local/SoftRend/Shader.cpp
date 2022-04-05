#include "SoftRend.h"

NAMESPACE_TOPSIDE_BEGIN


//VectorMap<String, SoftShaderLibrary::FragmentShader> SoftShaderLibrary::frag_shaders;
VectorMap<String, SoftShaderLibrary::ShaderFactory> SoftShaderLibrary::shader_classes[GVar::SHADERTYPE_COUNT];



template <class B>
SoftShaderT<B>::SoftShaderT() {
	
}

template <class B>
void SoftShaderT<B>::Clear() {
	inited = false;
}

template <class B>
bool SoftShaderT<B>::Create(GVar::ShaderType t) {
	Clear();
	
	type = t;
	
	
	inited = true;
	return true;
}

template <class B>
void SoftShaderT<B>::SetSource(String s) {
	src = s;
}

/*template <class B>
void SoftShaderT<B>::SetTestShader(SoftShaderLibrary::FragmentShader fs) {
	this->fs = fs;
}*/


NAMESPACE_TOPSIDE_END
