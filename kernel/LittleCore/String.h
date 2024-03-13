#ifndef _LittleCore_String_h_
#define _LittleCore_String_h_



inline bool IsOctDigit(int c) { return c >= '0' && c <= '7'; }
inline bool IsHexDigit(int c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'); }
inline bool IsBinDigit(int c) { return c == '0' || c == '1'; }
inline bool IsDigit(int c) { return c >= '0' && c <= '9'; }
inline bool IsSpace(int c) { return c == ' ' || c == '\t' || c == '\n' || c == '\r'; }
inline bool IsAlpha(int c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
inline int GetHexDigit(int c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return 10 + c - 'a';
	if (c >= 'A' && c <= 'F')
		return 10 + c - 'A';
	return 0;
}
inline int GetBinDigit(int c) {
	if (c == '0' || c == '1')
		return c - '0';
	return 0;
}


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
	while (::IsSpace(*s)) s++;
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
	while (::IsSpace(*s)) s++;
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


struct KString {
	const char* str = 0;
	int len = 0;
	bool owned = false;
	int refs = 0;
	
	
	KString() {}
	KString(KString&& s);
	KString(const KString& s) {Ref(s);}
	KString(const char* s) {Link(s);}
	void Clear();
	void Link(const char* s, int len=-1);
	void Attach(const char* s, int len=-1);
	void Ref(const KString& s);
	const char* Detach();
	
	KString& Cat(char c);
	
	bool IsEmpty() const {return len <= 0;}
	int GetLength() const {return len;}
	int GetCount() const {return len;}
	char operator[](int i) const {ASSERT(i >= 0 && i <= len); return str[i];}
	const char* CStr() const {return str;}
	
	void operator=(const KString& s) {Ref(s);}
	void operator=(const char* s) {Link(s);}
	
	KString Mid(int begin) const;
	KString Mid(int begin, int len) const;
	
	
	
	static int CharOctInt(const char* s);
	static int CharBinInt(const char* s);
	static int64 CharBinInt64(const char* s);
	static int CharHexInt(const char* s);
	static int64 CharHexInt64(const char* s);
	static int CharInt(const char* s);
	static int64 CharInt64(const char* s);
	static uint64 CharIntU64(const char* s);
	static double CharDbl(const char* s);
	static const char* IntChar(char* p, int bufsize, int x);
	static const char* IntChar64(char* p, int bufsize, int64 x);
	static const char* IntCharU64(char* p, int bufsize, uint64 x);
	static int Length(const char* c, int max_len=-1);
	static int Compare(const char* a, const char* b);
	static int Compare(const char* a, const char* b, int len);
	static void Copy(char* dst, const char* src);
	
	static KString IntStr(int i);
	static KString IntStr64(int64 i);
	static KString DblStr(double d);
	
};

inline int OctInt(const KString& s) {return OctInt(s.str);}
inline int HexInt(const KString& s) {return HexInt(s.str);}
inline int64 HexInt64(const KString& s) { return KString::CharHexInt64(s.str); }
inline int BinInt(const KString& s) { return KString::CharBinInt(s.str); }
inline int64 BinInt64(const KString& s) { return KString::CharBinInt64(s.str); }
inline int64 StrInt64(const KString& s) { return KString::CharInt64(s.str); }
inline KString IntStr(int i) { return KString::IntStr(i); }
inline KString IntStr64(int64 i) { return KString::IntStr64(i); }

#ifdef flagEMU
inline double StrDbl(const KString& s) {return StrDbl((UPP::String)s.str);}
#endif


#endif
