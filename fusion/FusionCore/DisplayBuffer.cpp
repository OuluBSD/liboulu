#include "FusionCore.h"

NAMESPACE_OULU_BEGIN


void FusionDisplayBuffer::Initialize() {
	FusionComponent::Initialize();
	
}

void FusionDisplayBuffer::Uninitialize() {
	
	FusionComponent::Uninitialize();
}

void FusionDisplayBuffer::Reset() {
	// pass
}

void FusionDisplayBuffer::PreProcess() {
	// pass
}

void FusionDisplayBuffer::PostProcess() {
	// pass
}

void FusionDisplayBuffer::UpdateTexBuffers() {
	auto* stream = Stream();
	if (stream) {
		ASSERT(stream->video_size.cx > 0 && stream->video_size.cy > 0);
		ClearTex();
#ifdef flagOPENGL
		Ogl_CreateTex(
			stream->video_size, 4,
			1, 1,
			FusionComponentInput::FILTER_LINEAR,
			FusionComponentInput::WRAP_CLAMP);
#endif
	}
}

void FusionDisplayBuffer::Event(const CtrlEvent& e) {
	// pass
}

bool FusionDisplayBuffer::LoadResources() {
	return true;
}



NAMESPACE_OULU_END
