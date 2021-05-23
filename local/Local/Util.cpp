#include "Local.h"

NAMESPACE_TOPSIDE_BEGIN

bool IsClose(double a, double b) {
	if (IsFin(a) && IsFin(b)) {
		double diff = fabs(a - b);
		return diff < 0.0001;
	}
	else {
		return *(uint64*)&a == *(uint64*)&b;
	}
}

double Multiply(double prev_norm, int64 count, double multiplier) {
	if (count <= 0)
		return multiplier;
	if (prev_norm == 0.0 || multiplier == 0.0)
		return 0.0;
	ASSERT(count < 300);
	return FastPow(FastPow(prev_norm, (double)count) * multiplier, 1.0 / (count + 1));
}

void RenameFile(String oldpath, String newpath) {
	rename(oldpath.Begin(), newpath.Begin());
}





String EscapeString(String s) {
	s.Replace("\n", "\\n");
	s.Replace("\t", "\\t");
	s.Replace("\r", "\\r");
	s.Replace("\"", "\\\"");
	
	return s;
}

String EscapeCharacter(String s) {
	s.Replace("\n", "\\n");
	s.Replace("\t", "\\t");
	s.Replace("\r", "\\r");
	s.Replace("\"", "\\\"");
	s.Replace("\'", "\\\'");
	
	return s;
}

String ReadFileName(String s) {
	String out;
	bool force_add = false;
	for(int i = 0; i < s.GetCount(); i++) {
		int chr = s[i];
		if (force_add)
			out.Cat(chr);
		else {
			if (chr == '\\')
				force_add = true;
			else if (IsSpace(chr))
				break;
			else
				out.Cat(chr);
		}
	}
	return out;
}

String GetLineNumStr(String s, bool from_zero) {
	Vector<String> lines = Split(s, "\n", false);
	String out;
	const int tab_size = 4;
	int begin = from_zero ? 0 : 1;
	for(int i = 0; i < lines.GetCount(); i++) {
		String nstr = IntStr(begin + i);
		nstr.Cat('\t', nstr.GetCount() < tab_size ? 2 : 1);
		out << nstr << lines[i] << "\n";
	}
	return out;
}

bool ScanBoolString(const String& s) {
	return ToLower(s) == "true" || s == "1";
}

bool IsConstChar(const WString& n, const char* cmp, int cmp_len) {
	if (n.GetCount() < cmp_len)
		return false;
	for(int i = 0; i < cmp_len; i++) {
		int chr = n[i];
		if (chr != cmp[i])
			return false;
	}
	if (cmp_len == n.GetCount())
		return true;
	
	return n[cmp_len] == ',';
}

bool IsConstCharEnd(const WString& n, const char* cmp, int cmp_begin, int cmp_len) {
	for(int i = cmp_begin; i < cmp_len; i++) {
		int chr = n[i];
		if (chr != cmp[i])
			return false;
	}
	return true;
}

bool IsArg(const WString& n, const char* cmp, int cmp_len) {
	int count = n.GetCount();
	if (count < cmp_len)
		return false;
	
	for(int i = 0; i < cmp_len; i++) {
		int chr = n[count-cmp_len+i];
		if (chr != cmp[i])
			return false;
	}
	if (cmp_len == n.GetCount())
		return true;
	
	return n[count-cmp_len-1] == ',';
}

bool IsAllSpace(const String& a) {
	bool is_space = true;
	for(int i = 0; i < a.GetCount() && is_space; i++)
		if (!IsSpace(a[i]))
			is_space = false;
	return is_space;
}

String CamelToName(String s) {
	String o;
	bool is_cap = true;
	
	for(int i = 0; i < s.GetCount(); i++) {
		int chr = s[i];
		
		if (chr == '_') {
			is_cap = true;
		}
		else {
			if (is_cap || IsUpper(chr))
				o.Cat(ToUpper(chr));
			else
				o.Cat(ToLower(chr));
			is_cap = false;
		}
	}
	
	return o;
}

String ToVarName(String s) {
	String o;
	
	bool all_upper = true;
	for(int i = 0; i < s.GetCount() && all_upper; i++) {
		int chr = s[i];
		if (IsUpper(chr) || chr == '_')
			;
		else
			all_upper = false;
	}
	if (all_upper)
		return ToLower(s);
	
	for(int i = 0; i < s.GetCount(); i++) {
		int chr = s[i];
		
		if (IsUpper(chr)) {
			if (i > 0)
				o.Cat('_');
			o.Cat(ToLower(chr));
		}
		else {
			o.Cat(chr);
		}
	}
	
	return o;
}

String ToCaps(String s) {
	String out;
	
	for(int i = 0; i < s.GetCount(); i++) {
		int chr = s[i];
		
		if (i && IsUpper(chr))
			out << "_";
		out.Cat(ToUpper(chr));
	}
	
	return out;
}



void GetDirectoryFiles(String dir, Index<String>& files) {
	files.Clear();
	FindFile ff;
	if (ff.Search(AppendFileName(dir, "*"))) {
		do {
			String name = ff.GetName();
			if (name == "." || name == "..") continue;
			files.Add(ff.GetPath());
		}
		while (ff.Next());
	}
}


void RunningFlagSingle::Stop() {running = false; while (!stopped) Sleep(100);}

void RunningFlag::Stop() {running = false; while (workers_running > 0) Sleep(sleep_time);}
void RunningFlag::Wait() {while ((int)workers_running != 0) Sleep(100);}













void CommandLineArguments::AddArg(char key, const char* desc, bool has_value, String value_desc) {
	CmdArg& a = args.Add();
	a.key = key;
	a.desc = desc;
	a.has_value = has_value;
	a.value_desc = value_desc;
}

bool CommandLineArguments::Parse() {
	const Vector<String>& args = CommandLine();
	
	for(int i = 0; i < args.GetCount(); i++) {
		String arg = args[i];
		
		if (arg.GetCount() < 2) return false;
		
		bool found = false;
		
		if (arg[0] == '-') {
			char key = arg[1];
			if (key) {
				for(int j = 0; j < this->args.GetCount(); j++) {
					CmdArg& a = this->args[j];
					if (a.key == key) {
						found = true;
						CmdInput& in = inputs.Add();
						in.key = key;
						if (a.has_value) {
							if (i+1 >= args.GetCount()) {
								Cerr() << "No value provided: " << arg << EOL;
								return false;
							}
							in.value = args[i+1];
							i++;
						}
						break;
					}
				}
			}
		}
		
		if (!found) {Cerr() << "Invalid argument: " << arg << EOL; return false;}
	}
	
	return true;
}

void CommandLineArguments::PrintHelp() {
	String exe = GetExeFilePath();
	int i = exe.ReverseFind(DIR_SEPS);
	if (i >= 0)
		exe = exe.Mid(i+1);
	
	Stream& cout = Cout();
	cout << exe << " [-";
	for(int i = 0; i < args.GetCount(); i++)
		if (args[i].has_value)
			cout << args[i].key;
	cout << " value]";
	
	cout << " [-";
	for(int i = 0; i < args.GetCount(); i++)
		if (!args[i].has_value)
			cout << args[i].key;
	cout << "]" << EOL;
	
	for(int i = 0; i < args.GetCount(); i++) {
		CmdArg& a = args[i];
		cout << "\t-" << a.key;
		if (a.has_value)
			cout << " " << (a.value_desc.IsEmpty() ? "value" : a.value_desc);
		cout << ": " << a.desc << EOL;
	}
}







String FindShareDir() {
	String config_share = ConfigFile("share");
	if (DirectoryExists(config_share))
		return config_share;
	
	String home_upphub_share = AppendFileName(GetHomeDirFile("libtopside"), "share");
	if (DirectoryExists(home_upphub_share))
		return home_upphub_share;
	
	#ifdef flagLINUX
	return "/usr/share";
	#elif defined flagFREEBSD
	return "/usr/local/share";
	#else
	return config_share;
	#endif
}

String ShareDirFile(String file) {
	return AppendFileName(FindShareDir(), file);
}

String TrimTrailingDirSep(String file) {
	while (file.GetCount() && file[file.GetCount()-1] == DIR_SEP)
		file = file.Left(file.GetCount()-1);
	
	return file;
}


void SetCoutLog() {StdLogSetup(LOG_COUT|LOG_FILE);}








NAMESPACE_TOPSIDE_END