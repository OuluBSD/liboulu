// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!

#ifndef _IOperatingSystem_Vendors_h_
#define _IOperatingSystem_Vendors_h

NAMESPACE_TOPSIDE_BEGIN

#define OS_CLS_LIST(x) \
	OS_CLS(MessageBus, x) \
	OS_CLS(ProcessManager, x) \
	OS_CLS(DesktopManager, x) \



#define OS_VNDR_LIST \



#define OS_CLS(x, v) struct v##x;
#define OS_VNDR(x) OS_CLS_LIST(x)
OS_VNDR_LIST
#undef OS_VNDR
#undef OS_CLS





NAMESPACE_TOPSIDE_END


#endif

