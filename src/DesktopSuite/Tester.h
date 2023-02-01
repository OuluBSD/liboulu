#ifndef _DesktopSuite_Tester_h_
#define _DesktopSuite_Tester_h_


NAMESPACE_TOPSIDE_BEGIN


class GuiTesterApp : public TopWindow {
	EditString edit;
	TimeCallback tc;
	
	Vector<Point> v;
	Color c;
	Point test_rect_tl;
	
public:
	typedef GuiTesterApp CLASSNAME;
	GuiTesterApp();
	void TimedToggle();
	
	bool Key(dword key, int count) override;
	void Paint(Draw& d) override;
	void MouseMove(Point p, dword keyflags) override;
	void MouseWheel(Point p, int zdelta, dword keyflags) override;
	void MouseLeave() override {Refresh();}
	void LeftDown(Point p, dword keyflags) override;
	void RightDown(Point p, dword keyflags) override;

};


NAMESPACE_TOPSIDE_END


#endif
