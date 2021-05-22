#ifndef _CoreAlt_Macros_h_
#define _CoreAlt_Macros_h_

NAMESPACE_UPP_BEGIN


#ifndef NULL
	#define NULL 0
#endif

// TODO translate
#define t_(x) x

#if !defined SCHAR_MIN
#  define SCHAR_MIN		(-128)
#  define SCHAR_MAX		127
#  define UCHAR_MAX		255
#  define SHRT_MIN		(-32768)
#  define SHRT_MAX		32767
#  define USHRT_MAX		65535
#  define INT_MIN		(-INT_MAX - 1)
#  define INT_MAX		2147483647
#  define UINT_MAX		4294967295U
# ifndef INT64_MAX
#  define INT64_MAX		9223372036854775807LL
# endif
# ifndef INT64_MIN
#  define INT64_MIN		(-LLONG_MAX - 1LL)
# endif
# ifndef UINT64_MAX
#  define UINT64_MAX	18446744073709551615ULL
# endif
#endif


#ifndef M_E
	#define M_E        2.71828182845904523536   // e
	#define M_LOG2E    1.44269504088896340736   // log2(e)
	#define M_LOG10E   0.434294481903251827651  // log10(e)
	#define M_LN2      0.693147180559945309417  // ln(2)
	#define M_LN10     2.30258509299404568402   // ln(10)
	#define M_PI       3.14159265358979323846   // pi
	#define M_PI_2     1.57079632679489661923   // pi/2
	#define M_PI_4     0.785398163397448309616  // pi/4
	#define M_1_PI     0.318309886183790671538  // 1/pi
	#define M_2_PI     0.636619772367581343076  // 2/pi
	#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
	#define M_SQRT2    1.41421356237309504880   // sqrt(2)
	#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)
#endif


#undef TODO
#define MK_str_(x)		#x

#define MACROSTR(x) #x
#define COUT(x) {::Upp::String ____s; ____s << x; Cout() << ____s << "\n";}
#define COUTLOG(x) {::Upp::String ____s; ____s << x; LOG(____s); Cout() << ____s << "\n";}
#define TODO {Panic("TODO " __FILE__ ":" + Upp::IntStr(__LINE__)); THROW(Upp::Exc("TODO"));}
#define TODO_ {Panic(); UNREACHABLE;}
#define SYNON_UNION_2(type, name0, name1) union {type name0; type name1;};


#define LOG(x) {Upp::VppLog() << x << EOL; Upp::VppLog().Flush();}
#define LLOG(x)


#define DUMP(x) {LOG( #x  " = " << ::Upp::AsString(x));}

#define DUMPC(c) {\
LOG(#c << " {"); \
for (int i = 0; i < c.GetCount(); i++) \
	LOG("\t[" << i << "]: " << ::Upp::AsString(c[i])); \
LOG("}"); \
}

#define DUMPCC(c) {\
LOG(#c << " {"); \
for (int i = 0; i < c.GetCount(); i++) {\
	for (int j = 0; j < c[i].GetCount(); j++) {\
		LOG("\t[" << i << "][" << j << "]: " << ::Upp::AsString(c[i][j])); }}\
LOG("}"); \
}

#define DUMPM(m) {\
LOG(#m << " {"); \
for (int i = 0; i < m.GetCount(); i++) \
	LOG("\t[" << i << "]: " << ::Upp::AsString(m.GetKey(i)) << ": " << ::Upp::AsString(m[i])); \
LOG("}"); \
}


#ifdef flagGUI
	#if 0
		#if defined(flagWIN32)
			#define GUI_APP_MAIN \
				void AppMain(); \
				\
				int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hprev, LPSTR cmdline, int show) {\
					::SetWin32Instances(hinst, hprev, show); \
					char chr[512]; GetModuleFileNameA(NULL, chr, 512); \
					UPP::AppInit__(0, (const char **)cmdline); \
					AppMain(); \
					return ::Upp::AppExit__(); \
				} \
				\
				void AppMain()
		#else
			#define GUI_APP_MAIN \
				void AppMain(); \
				\
				int main(int argc, const char** argv) {\
					UPP::AppInit__(argc, (const char **)argv); \
					AppMain(); \
					return ::Upp::AppExit__(); \
				} \
				\
				void AppMain()
			#define MAIN_FN
		#endif
	#endif
#else
	#define CONSOLE_APP_MAIN \
	void AppMain(); \
	\
	extern "C" int main(int argc, const char** argv) {\
		UPP::AppInit__(argc, (const char **)argv); \
		AppMain(); \
		::Upp::AppExit__(); \
		return ::Upp::GetExitCode(); \
	} \
	\
	void AppMain()
#endif



#if defined flagGCC || flagCLANG
	#define MemoryCompare __builtin_memcmp
	#define MemoryCopy    __builtin_memcpy
	#define MemoryMove    __builtin_memmove
#elif defined flagMSC
	#define MemoryCompare memcmp
	#define MemoryCopy    memcpy
	#define MemoryMove    memmove
#endif



#define COMBINE2(a, b) a##b
#define COMBINE3(a, b, c) a##b##c
#define COMBINE(a, b) COMBINE2(a, b)

#define MK_str(x)		#x
#define __LINESTR__		MK_str(__LINE__)
#define MK__s__(x)       s__s##x
#define MK__s_(x)        MK__s__(x)

#ifdef  BLITZ_INDEX__
#define MK__s            MK__s_(COMBINE3(BLITZ_INDEX__, _, __LINE__))
#else
#define MK__s            MK__s_(__LINE__)
#endif

#define LINEID(pre, x) COMBINE(COMBINE(pre, x), __LINE__)
#define INITBLOCK void LINEID(Init,MK__s) (); static Topside::Callinit LINEID(initcb,MK__s) (LINEID(Init,MK__s)); void LINEID(Init,MK__s) ()
#define EXITBLOCK void LINEID(Exit,MK__s) (); static Topside::Callexit LINEID(exitcb,MK__s) (LINEID(Exit,MK__s)); void LINEID(Exit,MK__s) ()
#define INITBLOCK_(x) void LINEID(Init,x) (); static Topside::Callinit LINEID(initcb,x) (LINEID(Init,x)); void LINEID(Init,x) ()
#define EXITBLOCK_(x) void LINEID(Exit,x) (); static Topside::Callexit LINEID(exitcb,x) (LINEID(Exit,x)); void LINEID(Exit,x) ()
#define ONCELOCK static std::atomic_flag __once; if (!__once.test_and_set())
#define ONCELOCK_(once) if (!once.test_and_set())




#define GLOBAL_VP(type, name, param) \
	name() { \
		static type x param; \
		return x; \
	}
#define GLOBAL_VARP(type, name, param)	type& GLOBAL_VP(type, name, param)
#define GLOBAL_V(type, name)			GLOBAL_VP(type, name, )
#define GLOBAL_VAR(type, name)			type& GLOBAL_V(type, name)
#define GLOBAL_VP_INIT(type, name, param) \
	name() \
	{ \
		static type x param; \
		return x; \
} \
INITBLOCK { name(); }

NAMESPACE_UPP_END

#endif
