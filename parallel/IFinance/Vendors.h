// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 25.3.25 19:11:33

#ifndef _IFinance_Vendors_h_
#define _IFinance_Vendors_h_

NAMESPACE_TOPSIDE_BEGIN

#define FIN_CLS_LIST(x) \
	FIN_CLS(System, x) \



#define FIN_VNDR_LIST \



#define FIN_CLS(x, v) struct v##x;
#define FIN_VNDR(x) FIN_CLS_LIST(x)
FIN_VNDR_LIST
#undef FIN_VNDR
#undef FIN_CLS





NAMESPACE_TOPSIDE_END


#endif

