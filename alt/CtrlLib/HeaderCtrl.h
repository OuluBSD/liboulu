#ifndef _CtrlLib_HeaderCtrl_h_
#define _CtrlLib_HeaderCtrl_h_

NAMESPACE_UPP_BEGIN


class HeaderCtrl : public Ctrl, public CtrlFrame {
	bool invisible = false;
	
public:
	RTTI_DECL2(HeaderCtrl, Ctrl, CtrlFrame)
	HeaderCtrl();
	
	HeaderCtrl&   Invisible(bool inv);
	
	void FrameLayout(Rect& r) override;
	void FrameAddSize(Size& sz) override;
	
};


NAMESPACE_UPP_END

#endif
