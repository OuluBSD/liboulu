// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 26.3.26 14:33:33

#ifndef _IMath_Vendors_h_
#define _IMath_Vendors_h_

NAMESPACE_TOPSIDE_BEGIN

#define MATH_CLS_LIST(x) \
	MATH_CLS(System, x) \



#define MATH_VNDR_LIST \



#define MATH_CLS(x, v) struct v##x;
#define MATH_VNDR(x) MATH_CLS_LIST(x)
MATH_VNDR_LIST
#undef MATH_VNDR
#undef MATH_CLS





NAMESPACE_TOPSIDE_END


#endif

