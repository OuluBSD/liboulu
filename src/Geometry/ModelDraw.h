#ifndef _Geometry_ModelDraw_h_
#define _Geometry_ModelDraw_h_

#if 0

NAMESPACE_TOPSIDE_BEGIN


class ModelDraw : public DrawProxy3 {
	One<ModelPainter> d;
	
	Volf GetFrameSize() const;
	
public:
	DrawCommand cmd_screen_begin, cmd_screen_end;
	DrawCommand render_begin, render_end;
	
	
	void LinkRender();
public:
	RTTI_DECL1(ModelDraw, Draw3)
	ModelDraw();
	ModelDraw(Volf sz);
	ModelDraw(float w, float h, float z);
	
	void Create(Volf sz);
	void Create(Volf sz, DrawCommand& sub_begin, DrawCommand& sub_end);
	void Clear();
	void Finish();
	void DetachTo(ModelPainter& pp);
	
	operator Image() const;
	
	Draw& Alpha();
	
	ModelPainter& GetPainter();
	
	String Dump() const;
};


NAMESPACE_TOPSIDE_END

#endif
#endif
