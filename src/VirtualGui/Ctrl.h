//$ class Ctrl {
private:
	static Ptr<Ctrl>      desktop;
	static Vector<Ctrl *> topctrl;
	static bool           invalid;

	static Point fbCursorPos;
	static Image fbCursorImage;
	
	static Rect  fbCaretRect;
	static int   fbCaretTm;
	
	static bool  fbEndSession;
	static int64 fbEventLoop;
	static int64 fbEndSessionLoop;
	
	static void CursorSync();
	
	int FindTopCtrl() const;
	static Rect GetClipBound(const Vector<Rect>& inv, const Rect& r);
	static void DoPaint(bool force=false);
	static void SyncTopWindows();

//	static void AddInvalid(const Rect& rect);

	void DestroyWnd();
	
	void NewTop()                              { SetTop(new Top); GetTop()->owner_window = NULL; }
	void  SetOpen(bool b)                      { isopen = b; }
	
	void PutForeground();
	static void MouseEventFB(Ptr<Ctrl> t, int event, Point p, int zdelta);

	static void DrawLine(const Vector<Rect>& clip, int x, int y, int cx, int cy, bool horz,
	                     const byte *pattern, int animation);
	static void DragRectDraw0(const Vector<Rect>& clip, const Rect& rect, int n,
	                          const byte *pattern, int animation);

	friend class SystemDraw;
	friend struct DnDLoop;

	
	static void DeleteDesktopTop();

	static int    GetCaretBlinkTime()          { return 500; }
	
protected:
	static int PaintLock;

public:
	static void DoMouseFB(int event, Point p, int zdelta = 0);
	static bool DoKeyFB(dword key, int cnt);
	
	static void InitFB();
	static void ExitFB();
	static void EndSession();
	
	static void PaintAll(bool force=false)     { DoPaint(force); }

	static void  SetDesktop(Ctrl& q);
	static Ctrl *GetDesktop()                  { return desktop; }
	static void  SetDesktopSize(Size sz);
	
	static void Invalidate();

	void DragRectDraw(const Rect& rect1, const Rect& rect2, const Rect& clip, int n,
	                  Color color, int type, int animation);

	static Ctrl *FindMouseTopCtrl();

	static void PaintScene(SystemDraw& draw);
	static void PaintCaretCursor(SystemDraw& draw);
	
	enum { DRAWDRAGRECT_SCREEN = 0x8000 };
	
	
	static bool EventLoopIteration(void* p);
	
	#if !IS_TS_CORE
	static bool DispatchKeyPub(dword key, int count) {return DispatchKey(key, count);}
	void DispatchMousePub(int e, const Point& pt, int zd) {DispatchMouse(e, pt, zd);}
	
	
	#if 1
	void PubCtrlPaint(SystemDraw& w, const Rect& clip) {CtrlPaint(w,clip);}
	void PubPaintCaret(SystemDraw& w) {PaintCaret(w);}
	#else
	void PubCtrlPaint(Draw& w, const Rect& clip);
	void PubPaintCaret(Draw& w);
	#endif
	byte GetOverpaint() const {return overpaint;}
	#endif
	
	static void InitWin32(HINSTANCE inst) {}
	static void ExitWin32() {}
	
//$ };
