// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!

#ifndef _ICrypt_Vendors_h_
#define _ICrypt_Vendors_h

NAMESPACE_TOPSIDE_BEGIN

#define CRY_CLS_LIST(x) \
	CRY_CLS(Crypt, x) \



#define CRY_VNDR_LIST \



#define CRY_CLS(x, v) struct v##x;
#define CRY_VNDR(x) CRY_CLS_LIST(x)
CRY_VNDR_LIST
#undef CRY_VNDR
#undef CRY_CLS



VENDORSSZZ


NAMESPACE_TOPSIDE_END


#endif
