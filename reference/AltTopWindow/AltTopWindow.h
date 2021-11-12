#ifndef _AltTopWindow_AltTopWindow_h_
#define _AltTopWindow_AltTopWindow_h_

#include <EcsLib/EcsLib.h>


NAMESPACE_OULU_BEGIN

class ExampleApp : public TopWindow {
	EditString edit;
	
	
	Vector<Point> v;
	Color c;
	
public:
	ExampleApp();
	virtual bool Key(dword key, int count);
	virtual void Paint(Draw& d);
	virtual void MouseMove(Point p, dword keyflags);
	virtual void MouseWheel(Point p, int zdelta, dword keyflags);
	virtual void MouseLeave() {Refresh();}
	virtual void LeftDown(Point p, dword keyflags);

};

NAMESPACE_OULU_END

#endif
