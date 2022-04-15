#include "SoftRend.h"

NAMESPACE_PARALLEL_BEGIN


template <class B>
SoftPipelineT<B>::SoftPipelineT() {
	
}

template <class B>
bool SoftPipelineT<B>::Create() {
	
	inited = true;
	return true;
}

template <class B>
void SoftPipelineT<B>::Clear() {
	
	inited = false;
}

template <class B>
void SoftPipelineT<B>::Use(SoftProgram& prog, uint32 bmask) {
	Stage& s = stages.IsEmpty() ? stages.Add() : stages.Top();
	s.prog = &prog;
	s.bmask = bmask;
}


SOFTREND_EXCPLICIT_INITIALIZE_CLASS(SoftPipelineT)


NAMESPACE_PARALLEL_END
