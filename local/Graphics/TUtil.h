#ifndef _Graphics_TUtil_h_
#define _Graphics_TUtil_h_

NAMESPACE_TOPSIDE_BEGIN


/*template <class Gfx>
struct DrawFramebufferT : GfxStateDraw {
	RTTI_DECL1(DrawFramebufferT, GfxStateDraw)
	using Base = DrawFramebufferT<Gfx>;
	using Renderer = typename Gfx::Renderer;
	using Framebuffer = typename Gfx::Framebuffer;
	using ShaderPipeline = typename Gfx::ShaderPipeline;
	
	GfxRenderer* rend = 0;
	GfxFramebuffer* fb = 0;
	
	//GfxRenderer* GetRenderer() override {return rend;}
	//GfxFramebuffer* GetFramebuffer() override {return fb;}
	
	
	void DrawShaderPipeline(ShaderPipeline&);
	
	
};*/

template <class Gfx>
struct StateDrawT : GfxStateDraw {
	RTTI_DECL1(StateDrawT, GfxStateDraw)
	using Base = StateDrawT<Gfx>;
	using ShaderPipeline = typename Gfx::ShaderPipeline;
	//using Renderer = typename Gfx::Renderer;
	using Framebuffer = typename Gfx::Framebuffer;
	
	//Renderer* rend = 0;
	Framebuffer* fb = 0;
	
	
	void DrawShaderPipeline(ShaderPipeline&) {TODO}
	
	Size GetPageSize() const override {TODO}
	void DrawLineOp(int x1, int y1, int x2, int y2, int width, Color color) override {TODO}
	void DrawRectOp(int x, int y, int cx, int cy, Color color) override {TODO}
	void DrawTextOp(int x, int y, int angle, const wchar *text, Font font,
		            Color ink, int n, const int *dx) override {TODO}
	void DrawPolyPolylineOp(const Point *vertices, int vertex_count,
	                        const int *counts, int count_count,
	                        int width, Color color, Color doxor) override {TODO}
	bool ClipOp(const Rect& r) override {TODO}
	void EndOp() override {TODO}
	Draw& Alpha() {TODO}
};


NAMESPACE_TOPSIDE_END

#endif
