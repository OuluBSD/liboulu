#ifndef _Graphics_State_h_
#define _Graphics_State_h_

NAMESPACE_TOPSIDE_BEGIN


struct ShaderState : RTTIBase {
	RTTI_DECL0(ShaderState)
	
	using Type = ShaderVar::Type;
	
	virtual ~ShaderState() {}
	
	// meta
	bool enabled;
	
	// shader stage
	Type	type = ShaderVar::PROG_NULL;
	String	code;
	String	library;
	
	// vertex shader
	mat4	view;
	mat4	projection;
	mat4	scale;
	mat4	offset;
	
	
	
	void Clear() {
		enabled = 0;
		type = ShaderVar::PROG_NULL;
		code.Clear();
		library.Clear();
		view.Clear();
		projection.Clear();
		scale.Clear();
		offset.Clear();
	}
	
};

#if 0
class StateDraw : public Draw {
	FramebufferState* state = 0;
	
	
public:
	RTTI_DECL1(StateDraw, Draw)
	
	void SetTarget(FramebufferState& state) {this->state = &state;}
	
	bool HasTarget() const {return state != 0;}
	FramebufferState& GetState() {return *state;}
	
	Size GetPageSize() const override {return state ? state->size : Size(0,0);}
	void DrawLineOp(int x1, int y1, int x2, int y2, int width, Color color) override;
	void DrawRectOp(int x, int y, int cx, int cy, Color color) override;
	void DrawTextOp(int x, int y, int angle, const wchar *text, Font font,
		             Color ink, int n, const int *dx) override;
	void DrawPolyPolylineOp(const Point *vertices, int vertex_count,
	                        const int *counts, int count_count,
	                        int width, Color color, Color doxor) override;
	bool ClipOp(const Rect& r) override;
	void EndOp() override;
	
	void DrawImageMemory(const  byte* mem, int sz, int x, int y, int w, int h, int ch_var_size, int channels);
	
};
#endif


NAMESPACE_TOPSIDE_END


#endif
