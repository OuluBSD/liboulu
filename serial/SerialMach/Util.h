#ifndef _SerialMach_Util_h_
#define _SerialMach_Util_h_

NAMESPACE_SERIAL_BEGIN

String RealizeEonFile(String path);


#define HAVE_SCRIPTLOADER_MACHVER	1


#if HAVE_SCRIPTLOADER_MACHVER

#define MACHVER_FWDFN_LIST \
	MACHVER_FWD_FN(TerminalTest) \
	MACHVER_FWD_FN(ForwardTopSegment) \
	MACHVER_FWD_FN(ScriptLoopLoaderForwardBeginning) \
	MACHVER_FWD_FN(ScriptLoopLoaderForwardRetry) \


#define MACHVER_FWD_FN(x) \
	void MachineVerifier_OnEnter##x(size_t call_id); \
	void MachineVerifier_OnLeave##x(size_t call_id);
MACHVER_FWDFN_LIST
#undef MACHVER_FWD_FN

#define MACHVER_ENTER(fn)		{static byte __; Serial::MachineVerifier_OnEnter##fn((size_t)&__);}
#define MACHVER_LEAVE(fn)		{static byte __; Serial::MachineVerifier_OnLeave##fn((size_t)&__);}
#define MACHVER_STATUS(fn, ptr)	{static byte __; Serial::MachineVerifier_On##fn(ptr);}

class ScriptLoopLoader;

void MachineVerifier_OnLoopLoader_Status(ScriptLoopLoader* ll);

#else

#define MACHVER_FWDFN_LIST
#define MACHVER_ENTER(fn)
#define MACHVER_LEAVE(fn)
#define MACHVER_STATUS(fn, ptr)

#endif

NAMESPACE_SERIAL_END

#endif