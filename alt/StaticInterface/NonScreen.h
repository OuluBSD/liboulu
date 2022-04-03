#ifndef _StaticInterface_StaticInterface_h_
#define _StaticInterface_StaticInterface_h_

#include <Draw/Draw.h>




NAMESPACE_UPP


class SystemDraw : public DrawProxy {
public:
	RTTI_DECL1(SystemDraw, DrawProxy)
	
	bool    CanSetSurface()                         { return false; }
	static void Flush()                             {}
};

class ImageDraw : public SImageDraw {
public:
	ImageDraw(Size sz) : SImageDraw(sz) {}
	ImageDraw(int cx, int cy) : SImageDraw(cx, cy) {}
};



enum {
	K_DELTA        = 0x010000,

	K_ALT          = 0x080000,
	K_SHIFT        = 0x040000,
	K_CTRL         = 0x020000,

	K_KEYUP        = 0x100000,

	K_MOUSEMIDDLE  = 0x200000,
	K_MOUSERIGHT   = 0x400000,
	K_MOUSELEFT    = 0x800000,
	K_MOUSEDOUBLE  = 0x1000000,
	K_MOUSETRIPLE  = 0x2000000,

	K_SHIFT_CTRL = K_SHIFT|K_CTRL,

#ifdef PLATFORM_COCOA
	K_OPTION       = 0x4000000,
#endif

	IK_DBL_CLICK   = 0x40000001, // this is just to get the info that the entry is equal to dbl-click to the menu
	
	K_MOUSE_FORWARD = 0x80000001,
	K_MOUSE_BACKWARD = 0x80000002,
};

class Ctrl : public Pte<Ctrl> {
	
public:
	enum {
		UNKNOWN,
		LEFTDOWN,
		LEFTDOUBLE,
		LEFTTRIPLE,
		LEFTDRAG,
		LEFTHOLD,
		LEFTREPEAT,
		LEFTUP,
		RIGHTDOWN,
		RIGHTDOUBLE,
		RIGHTTRIPLE,
		RIGHTDRAG,
		RIGHTHOLD,
		RIGHTREPEAT,
		RIGHTUP,
		MIDDLEDOWN,
		MIDDLEDOUBLE,
		MIDDLETRIPLE,
		MIDDLEDRAG,
		MIDDLEHOLD,
		MIDDLEREPEAT,
		MIDDLEUP,
	};
};



END_UPP_NAMESPACE




#endif
