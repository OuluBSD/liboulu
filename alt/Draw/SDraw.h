#ifndef _DrawAlt_SDraw_h_
#define _DrawAlt_SDraw_h_


NAMESPACE_UPP



enum {
	DRAW_NULL,
	DRAW_LINE,
	DRAW_IMAGE,
	DRAW_RECT,
	DRAW_TRIANGLES,
	DRAW_POLYLINE,
	DRAW_OFFSET,
	DRAW_END,
	
	DRAW_CMD_COUNT,
};

struct DrawCommand {
	DrawCommand *prev = NULL, *next = NULL;
	Byte type = 0;
	int i[5];
	RGBA clr;
	Image img;
	Vector<float> triangles;
	Vector<Point> pts;
	bool is_cached = false;
	
	String GetTypeString() const;
	String ToString() const;
	String GetQueueString() const;
	void Check() const;
	
	~DrawCommand() {img.Clear(); triangles.Clear(); pts.Clear();}
};

class DrawCommandCache {
	Array<DrawCommand> owned;
	Vector<DrawCommand*> unused;
	
public:
	DrawCommand& Get();
	void Return(DrawCommand* cmd);
	void Clear() {unused.Clear(); owned.Clear();}
	
	static DrawCommandCache& Local() {thread_local static DrawCommandCache c; return c;}
	
};






class SDraw {
	
public:
	virtual ~SDraw() {}
	
};

struct SImageDraw : Draw {
	Size sz;
	int pitch = 0;
	int stride = 0;
	Vector<byte> pixels;
	
	struct Op : Moveable<Op> {
		Rect cur_area;
	};
	Vector<Op> ops;
		
	Rect cur_area;
	
	byte AtRGBA(RGBA rgba, int i);
	void DrawPixel0(byte* data, int stride, int pitch, int x, int y, Color color);
	
public:
	SImageDraw() {}
	SImageDraw(Size sz) : sz(0,0) {Create(sz);}
	SImageDraw(Size sz, int stride) : sz(0,0) {Create(sz, stride);}
	SImageDraw(int cx, int cy) : sz(0,0) {Create(Size(cx,cy));}
	
	void Create(Size sz);
	void Create(Size sz, int stride);
	void Finish();
	int GetWidth() const {return sz.cx;}
	int GetHeight() const {return sz.cy;}
	int GetPitch() const {return pitch;}
	int GetStride() const {return stride;}
	
	Size GetPageSize() const override;
	void DrawLineOp(int x1, int y1, int x2, int y2, int width, Color color) override;
	void DrawRectOp(int x, int y, int cx, int cy, Color color) override;
	void DrawTextOp(int x, int y, int angle, const wchar *text, Font font,
		            Color ink, int n, const int *dx) override;
	void DrawPolyPolylineOp(const Point *vertices, int vertex_count,
	                        const int *counts, int count_count,
	                        int width, Color color, Color doxor) override;
	bool ClipOp(const Rect& r) override;
	void EndOp() override;
	void DrawImage(int x, int y, Image img, byte alpha) override;
	void DrawTriangle(Point a, Point b, Point c, RGBA clr) override;
	
	Vector<byte>& Data() {return pixels;}
	
	byte* GetIterator(int x, int y);
	void Zero();
	
	void DrawPixel(int x, int y, RGBA color);
	void DrawPixel(int x, int y, Color color);
	void DrawHLine(int x0, int x1, int y, Color color);
	void DrawLine(int x0, int y0, int x1, int y1, Color color);
	
};

END_UPP_NAMESPACE


#endif
