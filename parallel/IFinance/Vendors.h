// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.31 14:22:11

#ifndef _IFinance_Vendors_h_
#define _IFinance_Vendors_h_

NAMESPACE_PARALLEL_BEGIN

#define FIN_CLS_LIST(x) \
	FIN_CLS(System, x) \



#define FIN_VNDR_LIST \



#define FIN_CLS(x, v) struct v##x;
#define FIN_VNDR(x) FIN_CLS_LIST(x)
FIN_VNDR_LIST
#undef FIN_VNDR
#undef FIN_CLS





NAMESPACE_PARALLEL_END


#endif

