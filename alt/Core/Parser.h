#ifndef _CoreAlt_Parser_h_
#define _CoreAlt_Parser_h_

NAMESPACE_UPP_BEGIN
	

struct IdParser {
	bool is_valid = false;
	const String& input;
	int pos;
	String id;
	
	IdParser(const String& input, int pos) : input(input), pos(pos) {Parse();}
	
	void Parse();
	
};

struct StringParser {
	bool is_valid = false;
	const String& input;
	int pos;
	String str;
	int delim = '\"';
	bool checkend = true;
	
	StringParser(const String& input, int pos, int delim='\"', bool checkend=true) :
		input(input), pos(pos), delim(delim), checkend(checkend) {Parse();}
	
	void Parse();
	
};

struct NumberParser {
	enum {
		INVALID,
		OCT,
		HEX,
		INT,
		BIN,
		FLOAT,
		DOUBLE
	};
	
	int type = 0;
	const String& input;
	int cursor;
	String str;
	uint32 u32;
	int32 i32;
	int64 i64;
	float f;
	double d;
	
	NumberParser(const String& input, int cursor) : input(input), cursor(cursor) {Parse();}
	
	void Parse();
	
};

class CParser : public RtErr {
	String input;
	
	bool pass_whitespace = true;
	void SkipSpaces();
	void ChkNewline(int chr) {if (chr == '\n') {pos.line++; pos.col = 0;}}
	
public:
	struct Pos {
		const char *ptr;
		const char *wspc;
		const char *lineptr;
		int cursor = 0, line = 0, col = 0;
		String      fn;
		
		int GetColumn(int tabsize = 4) const;

		Pos(const char *ptr = NULL, int line = 1, String fn = Null) : ptr(ptr), line(line), fn(fn) {}
	};
	Pos pos;
	
public:
	typedef CParser CLASSNAME;
	CParser() {}
	CParser(String input, String fn, int line=0) {this->input = input; pos.fn = fn; pos.line = line;}
	CParser(String s) {input = s;}
	
	using Error = Exc;
	
	//void Next() {pos++; col++;}
	bool IsEnd() const;
	//FileLocation GetLocation() const;
	int GetCharPos() const {return pos.cursor;}
	int GetLine() const {return pos.line;}
	int GetColumn() const {return pos.col;}
	String GetFileName() const {return pos.fn;}
	Pos GetPos() const {return pos;}
	void SetPos(const Pos& p) {pos = p;}
	
	String ReadId();
	String ReadString(char delim='\"', bool checkend=true);
	int ReadInt();
	double ReadNumber();
	double ReadDouble();
	uint64 ReadNumber64(int base=10);
	void PassId(String id);
	void PassNewline();
	void PassChar(char chr);
	void SkipTerm();
	void DoSpaces() {if (pass_whitespace) SkipSpaces();}
	void Spaces() {DoSpaces();}
	
	int PeekChar() const;
	bool Char(char chr);
	bool Char2(char a, char b);
	bool Char3(char a, char b, char c);
	bool Id(String id);
	bool Newline();
	bool GetId(String& str);
	bool GetInt(int64& i64);
	bool GetFloating(double& dbl);
	const char* GetPtr() const {return input.Begin() + pos.cursor;}
	
	bool IsEof() const {return pos.cursor >= input.GetCount();}
	bool IsId() const;
	bool IsId(String id) const;
	bool IsInt() const;
	bool IsChar(char i) const;
	bool IsChar2(char a, char b) const;
	bool IsChar3(char a, char b, char c) const;
	bool IsCharDigit() const;
	bool IsNumber() const;
	bool IsString() const;
	
	void ThrowError(const char *s);
	
	
	
};

NAMESPACE_UPP_END

#endif
