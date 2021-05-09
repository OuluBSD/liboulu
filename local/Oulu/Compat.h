#ifndef _Oulu_Compat_h_
#define _Oulu_Compat_h_


#ifdef flagFREEBSD
extern char **environ;
#endif


#ifndef flagALTCORE

#define MemoryCompare memcmp
#define MemoryCopy    memcpy
#define MemoryMove    memmove
#define NAMESPACE_UPP_BEGIN NAMESPACE_UPP
#define NAMESPACE_UPP_END   END_UPP_NAMESPACE


#undef TODO
#define MACROSTR(x) #x
#define COUT(x) {::Upp::String ____s; ____s << x; Cout() << ____s << "\n";}
#define COUTLOG(x) {::Upp::String ____s; ____s << x; LOG(____s); Cout() << ____s << "\n";}
#define TODO {Panic("TODO " __FILE__ ":" + Upp::IntStr(__LINE__)); throw Upp::Exc("TODO");}
#define SYNON_UNION_2(type, name0, name1) union {type name0; type name1;};


NAMESPACE_UPP_BEGIN

inline bool IsOctDigit(char c) { return c >= '0' && c <= '7'; }
inline bool IsHexDigit(char c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'); }
inline int GetHexDigit(char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return 10 + c - 'a';
	if (c >= 'A' && c <= 'F')
		return 10 + c - 'A';
	return 0;
}

inline int OctInt(const char *s) {
	if (!s) return 0;
	while (IsSpace(*s)) s++;
	int n=0, neg=0;
	switch (*s) {
		case '-': neg=1;
		case '+': s++;
	}
	while (*s == '0') s++;
	while (IsOctDigit(*s))
		n = 8*n - (*s++ - '0');
	return neg ? n : -n;
}

inline int HexInt(const char *s) {
	if (!s) return 0;
	while (IsSpace(*s)) s++;
	int n=0, neg=0;
	switch (*s) {
		case '-': neg=1;
		case '+': s++;
	}
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		s += 2;
	while (IsHexDigit(*s))
		n = 16*n - GetHexDigit(*s++);
	return neg ? n : -n;
}

template<class InputIterator, class UnaryPredicate>
InputIterator FindIf(InputIterator first, InputIterator last, UnaryPredicate pred) {
	return std::find_if(first, last, pred);
}

void sSeed(uint64 *s);

inline void GetSysSeedValues(int64* a, int64* b, int64* c) {
	if(a) sSeed((uint64*)a);
	if(b) sSeed((uint64*)b);
	if(c) sSeed((uint64*)c);
}

inline WString ToWString(String s) {return s.ToWString();}
inline WString ToWString(const wchar_t* chr) {return std::wstring(chr);}
template <class T> inline String ToString(const T& o) {return AsString(o);}
inline String HexStr(int64 i) {return Format("0x%X", i);}
inline String HexStr(void* i) {return Format("0x%X", (int64)i);}

typedef Image RawSysTexture;

//template <class T, class V> T Get(V& v) {return v.template Get<T>();}
//template <int I, class V> auto Get(V& v) {return v.template Get<I>();}
//inline bool IsMap(const Value& v) { return v.GetType() == VALUEMAP_V; }
//inline ValueMap GetMap(const Value& v) {return v;}

template <class T> inline int64 ToInt(const T& o) {return o.ToInt();}
template<> inline int64 ToInt(const bool& o) {return (int64)o;}
template<> inline int64 ToInt(const int& o) {return (int64)o;}
template<> inline int64 ToInt(const int64& o) {return (int64)o;}
template<> inline int64 ToInt(const byte& o) {return (int64)o;}
template<> inline int64 ToInt(const char& o) {return (int64)o;}
template<> inline int64 ToInt(const float& o) {return (int64)o;}
template<> inline int64 ToInt(const double& o) {return (int64)o;}
template<> inline int64 ToInt(const String& o) {return StrInt(o);}
template<> inline int64 ToInt(const WString& o) {return StrInt(o.ToString());}
template<> inline int64 ToInt(const Value& o) {return (int64)o;}

template <class T> inline double ToDouble(const T& o) {return o.ToDouble();}
template<> inline double ToDouble(const bool& o) {return (double)o;}
template<> inline double ToDouble(const int& o) {return (double)o;}
template<> inline double ToDouble(const int64& o) {return (double)o;}
template<> inline double ToDouble(const byte& o) {return (double)o;}
template<> inline double ToDouble(const char& o) {return (double)o;}
template<> inline double ToDouble(const float& o) {return (double)o;}
template<> inline double ToDouble(const double& o) {return (double)o;}
template<> inline double ToDouble(const String& o) {return StrDbl(o);}
template<> inline double ToDouble(const WString& o) {return StrDbl(ToString(o));}
template<> inline double ToDouble(const Value& o) {return o;}



NAMESPACE_UPP_END

#include <CoreAlt/Shared.h>
#include <CoreAlt/Object.h>
#include <CoreAlt/CtrlEvent.h>

#define CompatFileHandle(x) x



#if !defined(flagGUI)
NAMESPACE_UPP
class Ctrl : public Pte<Ctrl> {
	
public:
	enum {
		UNKNOWN,
		LEFTDOWN,
		LEFTDOUBLE,
		LEFTTRIPLE,
		LEFTDRAG,
		LEFTHOLD,
		LEFTREPEAT,
		LEFTUP,
		RIGHTDOWN,
		RIGHTDOUBLE,
		RIGHTTRIPLE,
		RIGHTDRAG,
		RIGHTHOLD,
		RIGHTREPEAT,
		RIGHTUP,
		MIDDLEDOWN,
		MIDDLEDOUBLE,
		MIDDLETRIPLE,
		MIDDLEDRAG,
		MIDDLEHOLD,
		MIDDLEREPEAT,
		MIDDLEUP,
	};
};

enum {
	K_DELTA        = 0x010000,

	K_ALT          = 0x080000,
	K_SHIFT        = 0x040000,
	K_CTRL         = 0x020000,

	K_KEYUP        = 0x100000,

	K_MOUSEMIDDLE  = 0x200000,
	K_MOUSERIGHT   = 0x400000,
	K_MOUSELEFT    = 0x800000,
	K_MOUSEDOUBLE  = 0x1000000,
	K_MOUSETRIPLE  = 0x2000000,

	K_SHIFT_CTRL = K_SHIFT|K_CTRL,

#ifdef PLATFORM_COCOA
	K_OPTION       = 0x4000000,
#endif

	K_PEN          = 0x8000000,

	IK_DBL_CLICK   = 0x40000001, // this is just to get the info that the entry is equal to dbl-click to the menu
	
	K_MOUSE_FORWARD = 0x80000001,
	K_MOUSE_BACKWARD = 0x80000002,
};

class SystemDraw {
public:
	Size GetPageSize() const {return Size(0,0);}
};

template<> inline hash_t GetHashValue(const float& a)         { return memhash(&a, sizeof(a)); }

END_UPP_NAMESPACE
#endif

#else

#define CompatFileHandle(x) fileno(x)

#endif
#endif
