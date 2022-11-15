#ifndef _SharedCore_Draw_h_
#define _SharedCore_Draw_h_


NAMESPACE_UPP

#define DRAWCMD_LIST \
	DRAWCMD(NULL) \
	DRAWCMD(META_SIZE) \
	\
	DRAWCMD(BEGIN) /* dummy */ \
	DRAWCMD(BIND_WINDOW) \
	DRAWCMD(UNBIND_WINDOW) \
	DRAWCMD(LINE) \
	DRAWCMD(IMAGE) \
	DRAWCMD(RECT) \
	DRAWCMD(TRIANGLES) \
	DRAWCMD(POLYLINE) \
	DRAWCMD(OFFSET) \
	DRAWCMD(END) \
	DRAWCMD(WINDOW_OFFSET) \
	DRAWCMD(WINDOW_END) \


enum {
	#define DRAWCMD(x) DRAW_##x,
	DRAWCMD_LIST
	#undef DRAWCMD
	
	DRAW_CMD_COUNT,
};

struct DrawCommand {
	DrawCommand *prev = NULL, *next = NULL;
	Byte type = 0;
	int i[5];
	hash_t hash;
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
	DrawCommand& CreateCommand();
	void Return(DrawCommand* cmd);
	void Clear() {unused.Clear(); owned.Clear();}
	
	static DrawCommandCache& Local() {thread_local static DrawCommandCache c; return c;}
	
};


END_UPP_NAMESPACE


#endif
