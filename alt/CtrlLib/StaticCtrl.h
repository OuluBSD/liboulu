#ifndef _CtrlLibAlt_StaticCtrl_h_
#define _CtrlLibAlt_StaticCtrl_h_


NAMESPACE_UPP


class SeparatorCtrl : public Ctrl {
	
public:
	RTTI_DECL1(SeparatorCtrl, Ctrl)
	SeparatorCtrl();
	
	virtual Size GetMinSize() const;
	virtual void Paint(Draw& w);

	struct Style : ChStyle<Style> {
		Value l1, l2;
	};
};


class StaticRect : public Ctrl {
	Color clr;
	
public:
	RTTI_DECL1(StaticRect, Ctrl)
	StaticRect();
	
	virtual Size GetMinSize() const;
	virtual void Paint(Draw& w);
	
	StaticRect& Background(const Value& chvalue);
	StaticRect& SetColor(typename UPP::Color c)                { Background(c); return *this; }

	
	struct Style : ChStyle<Style> {
		Value def_clr;
	};
};


END_UPP_NAMESPACE


#endif
