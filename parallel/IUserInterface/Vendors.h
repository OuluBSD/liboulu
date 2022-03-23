// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 23.3.23 18:44:22

#ifndef _IUserInterface_Vendors_h_
#define _IUserInterface_Vendors_h_

NAMESPACE_TOPSIDE_BEGIN

#define UI_CLS_LIST(x) \
	UI_CLS(Window, x) \
	UI_CLS(Splitter, x) \
	UI_CLS(SeparatorCtrl, x) \
	UI_CLS(ArrayCtrl, x) \
	UI_CLS(ColumnCtrl, x) \
	UI_CLS(TreeCtrl, x) \
	UI_CLS(IconCtrl, x) \
	UI_CLS(ImageCtrl, x) \
	UI_CLS(Button, x) \
	UI_CLS(Label, x) \
	UI_CLS(StringEdit, x) \
	UI_CLS(IntEdit, x) \
	UI_CLS(FloatEdit, x) \
	UI_CLS(TimeEdit, x) \
	UI_CLS(DateEdit, x) \
	UI_CLS(DocEdit, x) \
	UI_CLS(Bar, x) \
	UI_CLS(MenuBar, x) \



#define UI_VNDR_LIST \
	UI_VNDR(UiImgui) \



#define UI_CLS(x, v) struct v##x;
#define UI_VNDR(x) UI_CLS_LIST(x)
UI_VNDR_LIST
#undef UI_VNDR
#undef UI_CLS



struct UiImgui {
	using NativeCtrl = uint32;
	typedef void (*DataCallbackFn)(void*, char* data, int size);
	
	struct Thread {
		
	};
	static Thread& Local() {thread_local static Thread t; return t;}
	
	#include "IfaceFuncs.inl"
	
};



NAMESPACE_TOPSIDE_END


#endif

