#include "IGraphics.h"

NAMESPACE_PARALLEL_BEGIN


template <class Gfx>
void RendererT<Gfx>::DefaultPreFrame() {
	//ASSERT(rend);
	Gfx::BindFramebufferDefault();
	Gfx::SetClearValue(RGBA(0,0,0,255), 255);
	//TODO: useless? Gfx::ClearBuffers();
	Gfx::SetSmoothShading();
	Gfx::SetDepthTest();
	Gfx::SetDepthOrderLess(true);
	Gfx::SetFastPerspectiveCorrection();
	Gfx::SetTriangleBacksideCulling();
	Gfx::SetTriangleFrontsideCCW();
	Gfx::SetViewport(output_sz);
}


GFX_EXCPLICIT_INITIALIZE_CLASS(ContextStateT)
GFX_EXCPLICIT_INITIALIZE_CLASS(RendererT)


NAMESPACE_PARALLEL_END