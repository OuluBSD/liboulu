#include "SoftRend.h"

NAMESPACE_PARALLEL_BEGIN


template <class B>
SoftFramebufferT<B>::SoftFramebufferT() {
	
}

template <class B>
void SoftFramebufferT<B>::Clear() {
	inited = false;
	
}

template <class B>
bool SoftFramebufferT<B>::Create() {
	
	
	inited = true;
	return true;
}

template <class B>
void SoftFramebufferT<B>::operator=(NativeTexture& tex) {
	ASSERT(!this->tex);
	this->tex = tex;
}

template <class B>
void SoftFramebufferT<B>::ClearData(GVar::BufferType type) {
	
}

template <class B>
void SoftFramebufferT<B>::ClearDataAll() {
	
}

template <class B>
void SoftFramebufferT<B>::SetParam(GVar::TextureType type, GVar::Filter filter, GVar::Wrap wrap) {
	ASSERT(type >= 0 && type < GVar::TEXTYPE_COUNT);
	this->filter[type] = filter;
	this->wrap[type] = wrap;
}


SOFTREND_EXCPLICIT_INITIALIZE_CLASS(SoftFramebufferT)


NAMESPACE_PARALLEL_END
