#include "PlayEditor.h"

NAMESPACE_TOPSIDE_BEGIN


PlayTokenizer::PlayTokenizer() : ErrorSource("PlayTokenizer") {
	
}

Token& PlayTokenizer::Add(int token_id) {
	struct Token& t = tokens.Add();
	t.loc = loc;
	t.end = loc;
	t.end.col++;
	t.type = token_id;
	return t;
}

bool PlayTokenizer::Process(String str, String path) {
	input = str.ToWString();
	
	loc.file = path;
	loc.line = 1;
	loc.col = 0;
	loc.cursor = 0;
	
	int& cursor = loc.cursor;
	WString s;
	
	while (cursor < input.GetCount()) {
		loc.cursor = cursor;
		loc.col++;
		
		int chr = input[cursor++];
		int chr1 = cursor < input.GetCount() ? input[cursor] : 0;
		
		if (state == ANY) {
			if (chr == '\n') {
				Add(TK_NEWLINE);
				loc.col = 0;
				loc.line++;
			}
			else if (chr == '\r' || chr == '\t' || chr == ' ') {
				continue;
			}
			else if (chr == '\"') {
				state = STRING;
				s.Clear();
			}
			else if (chr == ':') {
				Add(TK_COLON);
			}
			else if (chr == '/' && chr1 == '/') {
				cursor++;
				Add(TK_COMMENT);
			}
			else if (chr == '*' && chr1 == '*') {
				cursor++;
				Add(TK_BLOCK_COMMENT);
			}
			else if (chr == '#') {
				Add(TK_NUMBERSIGN);
			}
			else {
				state = WORD;
				s.Clear();
				s.Cat(chr);
			}
		}
		else if (state == WORD) {
			if (chr == '\n') {
				Add(TK_ID).str_value = s.ToString();
				Add(TK_NEWLINE);
				loc.col = 0;
				loc.line++;
				state = ANY;
			}
			else if (chr == '\r' || chr == '\t' || chr == ' ' || chr == '*') {
				Add(TK_ID).str_value = s.ToString();
				state = ANY;
				cursor--;
				continue;
			}
			else if (chr == ':') {
				Add(TK_ID).str_value = s.ToString();
				Add(TK_COLON);
				state = ANY;
			}
			else {
				s.Cat(chr);
			}
		}
		else if (state == STRING) {
			if (chr == '\"') {
				Token& t = Add(TK_STRING);
				t.str_value = s.ToString();
				state = ANY;
			}
			else {
				s.Cat(chr);
			}
		}
		else Panic("Invalid state");
		
	}
	
	Add(TK_EOF);
	
	return true;
}

void PlayTokenizer::Dump() const {
	LOG("Dumping tokenizer:");
	String prev_file;
	for(int i = 0; i < tokens.GetCount(); i++) {
		const Token& tk = tokens[i];
		if (tk.loc.file != prev_file) {
			prev_file = tk.loc.file;
			LOG("\tfile: " << prev_file);
		}
		
		LOG("\t[" << i << "] (" << tk.loc.line << ":" << tk.loc.col << ") = " <<
			tk.GetTypeString() << ": " << tk.GetTextValue());
	}
}












PlayParser::PlayParser(PlayScript& script) : ErrorSource("PlayParser"), script(script) {
	
}

bool PlayParser::Process(const Vector<Token>& tokens) {
	this->tokens = &tokens;
	cursor = 0;
	
	
	if (!ParseScript(script))
		return false;
	
	
	return true;
}

bool PlayParser::ParseScript(PlayScript& s) {
	
	if (!ParseMetaText(s.title)) return false;
	if (!ParseMetaText(s.description)) return false;
	if (!ParseMetaText(s.disclaimer)) return false;
	if (!ParseMetaText(s.author)) return false;
	if (!ParsePlayDialogue(s.actors)) return false;
	if (!ParseParts(s)) return false;
	
	return true;
}

bool PlayParser::IsPartToken(const Token& t) {
	if (t.IsType(TK_ID)) {
		String s = t.GetTextValue();
		return s == "Part" || s == "Osa";
	}
	return false;
}

bool PlayParser::IsSectionToken(const Token& t) {
	if (t.IsType(TK_ID)) {
		String s = t.GetTextValue();
		return s == "Section" || s == "Luku";
	}
	return false;
}

bool PlayParser::ParseParts(PlayScript& s) {
	PassEmpty();
	
	while (!IsEof()) {
		PassEmpty();
		
		{
			const Token& t = Current();
			if (!IsPartToken(t))
				break;
		}
		
		PlayPart& part = s.parts.Add();
		part.idx = s.parts.GetCount()-1;
		if (!ParsePart(part))
			return false;
		
		{
			const Token& t = Current();
			if (t.IsType(TK_NEWLINE)) {
				Next();
				if (!IsEof() && Current().IsType(TK_NEWLINE)) {
					Next();
					break;
				}
			}
		}
	}
	
	if (s.parts.IsEmpty()) {
		AddError(Current().loc, "Expected at least one part");
		return false;
	}
	
	return true;
}

bool PlayParser::ParsePart(PlayPart& p) {
	PassEmpty();
	
	if (!IsPartToken(Current())) {
		AddError(Current().loc, "Expected part-token");
		return false;
	}
	Next();
	if (!CheckEof()) return false;
	int i = ScanInt(Current().GetTextValue());
	if (i-1 != p.idx) {
		AddError(Current().loc, "Unexpected part id: " + IntStr(i) + " != " + IntStr(p.idx+1));
		return false;
	}
	Next();
	if (!CheckEof()) return false;
	if (!CheckColon()) return false;
	Next();
	if (!CheckEof()) return false;
	if (!ParseSentenceEol(p.title, false)) return false;
	
	
	while (!IsEof()) {
		PassEmpty();
		
		{
			const Token& t = Current();
			if (!IsSectionToken(t))
				break;
		}
		
		PlaySection& sect = p.sections.Add();
		sect.idx = p.sections.GetCount()-1;
		if (!ParseSection(sect))
			return false;
		
		{
			const Token& t = Current();
			if (t.IsType(TK_NEWLINE)) {
				Next();
				if (!IsEof() && Current().IsType(TK_NEWLINE)) {
					Next();
					break;
				}
			}
		}
	}
	
	if (p.sections.IsEmpty()) {
		AddError(Current().loc, "Expected at least one part");
		return false;
	}
	
	
	return true;
}

bool PlayParser::ParseSection(PlaySection& s) {
	PassEmpty();
	
	if (!IsSectionToken(Current())) {
		AddError(Current().loc, "Expected section-token");
		return false;
	}
	Next();
	if (!CheckEof()) return false;
	int i = ScanInt(Current().GetTextValue());
	if (i-1 != s.idx) {
		AddError(Current().loc, "Unexpected section id: " + IntStr(i) + " != " + IntStr(s.idx+1));
		return false;
	}
	Next();
	if (!CheckEof()) return false;
	if (!CheckColon()) return false;
	Next();
	if (!CheckEof()) return false;
	if (!ParseSentenceEol(s.title, false)) return false;
	if (!ParsePlayDialogue(s.dialog)) return false;
	
	return true;
}

bool PlayParser::CheckEof() {
	if (IsEof()) {
		AddError(Current().loc, "Unexpected end-of-file");
		return false;
	}
	return true;
}

bool PlayParser::CheckColon() {
	const Token& t = Current();
	if (!t.IsType(TK_COLON)) {
		AddError(t.loc, "Expected ':'");
		return false;
	}
	return true;
}

bool PlayParser::ParseMetaText(MetaText& txt) {
	PassEmpty();
	
	while (!IsEof()) {
		PlaySentence& sent = txt.sents.Add();
		
		if (!ParseSentence(sent, false))
			return false;
		
		const Token& t = Current();
		if (t.IsType(TK_NEWLINE)) {
			Next();
			if (!IsEof() && Current().IsType(TK_NEWLINE)) {
				Next();
				break;
			}
		}
	}
	
	if (txt.sents.IsEmpty()) {
		AddError(Current().loc, "Expected meta-text");
		return false;
	}
	
	return true;
}

bool PlayParser::CheckEol() {
	const Token& t = Current();
	if (!t.IsType(TK_NEWLINE)) {
		AddError(t.loc, "Expected newline");
		return false;
	}
	Next();
	return true;
}

bool PlayParser::ParseSentenceEol(PlaySentence& sent, bool opt_voice_id) {
	
	if (!ParseSentence(sent, opt_voice_id))
		return false;
	
	return CheckEol();
}

bool PlayParser::ParseTiming(PlayLine& l) {
	if (Current().IsType(TK_ID)) {
		String a = Current().GetTextValue();
		if (a.Left(1) == "[") {
			Next();
			if (Current().IsType(TK_COLON)) {
				Next();
				if (Current().IsType(TK_ID)) {
					String b = Current().GetTextValue();
					if (b.Right(1) == "]") {
						Next();
						a = a.Mid(1);
						b = b.Left(b.GetCount()-1);
						int min = ScanInt(a);
						int sec = ScanInt(b);
						if (min >= 0 && min < 10000 && sec >= 0 && sec < 60) {
							l.is_meta = true;
							l.timing = min * 60 + sec;
							return CheckEol();
						}
					}
				}
			}
		}
	}
	
	AddError(Current().loc, "Invalid timing declaration");
	return false;
}

bool PlayParser::ParseSentence(PlaySentence& p, bool opt_voice_id) {
	
	if (opt_voice_id && Current().IsType(TK_ID)) {
		WString txt = Current().GetTextValue().ToWString();
		if (txt.GetCount() && txt[0] == '(') {
			Next();
			if (txt.GetCount() == 1) {
				while (!IsEof()) {
					txt += Current().GetTextValue().ToWString();
					Next();
					if (txt[txt.GetCount()-1] == ')')
						break;
				}
			}
			if (txt[0] == '(' && txt[txt.GetCount()-1] == ')') {
				p.voice_id = txt.Mid(1, txt.GetCount()-2);
			}
			else {
				AddError(Current().loc, "invalid voice id");
				return false;
			}
		}
	}
	
	while (!IsEof()) {
		const Token& t = Current();
		if (t.IsType(TK_ID) || t.IsType(TK_STRING)) {
			p.tokens.Add(t);
			Next();
		}
		else
			break;
	}
	
	if (p.tokens.IsEmpty()) {
		const Token& t = Current();
		DUMP(t);
		AddError(Current().loc, "Expected text");
		return false;
	}
	
	return true;
}

void PlayParser::PassEmpty() {
	while (!IsEof()) {
		const Token& t = Current();
		if (t.IsType(TK_NEWLINE))
			Next();
		else
			break;
	}
}

bool PlayParser::ParsePlayDialogue(PlayDialogue& p) {
	PassEmpty();
	
	while (!IsEof()) {
		if (IsSectionToken(Current()) || IsPartToken(Current()))
			break;
		
		PlayLine& l = p.lines.Add();
		
		if (!ParsePlayLine(l))
			return false;
		
		if (p.lines.GetCount() >= 2) {
			PlayLine& prev = p.lines[p.lines.GetCount()-2];
			if ((prev.is_narration && l.is_narration) ||
				(prev.is_comment && l.is_comment) ||
				(prev.is_meta && l.is_meta)) {
				prev.sents.Append(l.sents);
				p.lines.Remove(p.lines.GetCount()-1);
			}
		}
		
		PassEmpty();
	}
	
	if (p.lines.IsEmpty()) {
		AddError(Current().loc, "Expected lines");
		return false;
	}
	
	return true;
}

bool PlayParser::ParsePlayLine(PlayLine& l) {
	if (Current().IsType(TK_BLOCK_COMMENT)) {
		Next();
		l.is_narration = true;
		
		PlaySentence& sent = l.sents.Add();
		if (!ParseSentence(sent, false))
			return false;
		
		if (!Current().IsType(TK_BLOCK_COMMENT)) {
			AddError(Current().loc, "Expected end of narration '**'");
			return false;
		}
		Next();
	}
	else if (Current().IsType(TK_NUMBERSIGN)) {
		Next();
		l.is_meta = true;
		
		if (Current().IsType(TK_ID) && Current().GetTextValue().Left(1) == "[") {
			ParseTiming(l);
		}
		else {
			PlaySentence& sent = l.sents.Add();
			if (!ParseSentenceEol(sent, false))
				return false;
		}
	}
	else {
		if (Current().IsType(TK_COMMENT)) {
			Next();
			l.is_comment = true;
		}
		else {
			{
				const Token& t = Current();
				if (!t.IsType(TK_ID)) {
					AddError(t.loc, "Expected identifier");
					return false;
				}
				l.id.name = t.GetTextValue().ToWString();
				Next();
			}
			
			{
				const Token& t = Current();
				if (!CheckColon())
					return false;
				Next();
			}
		}
		
		while (!IsEof()) {
			{
				const Token& t = Current();
				const Token* n = GetNext();
				if (t.IsType(TK_ID) && n && n->IsType(TK_COLON))
					break;
				if (t.IsType(TK_NEWLINE))
					break;
				if (t.IsType(TK_COMMENT) || t.IsType(TK_BLOCK_COMMENT))
					break;
			}
			
			PlaySentence& sent = l.sents.Add();
			if (!ParseSentenceEol(sent, true))
				return false;
		}
		
		if (l.sents.IsEmpty()) {
			AddError(Current().loc, "Expected sentences");
			return false;
		}
	}
	return true;
}




String PlayPart::ToString(int indent) const {
	String s;
	s.Cat('\t', indent);
	s << "Part " << idx+1 << " (" << title.ToString(-1) << "):\n";
	for (const PlaySection& sect : sections)
		s << sect.ToString(indent+1);
	return s;
}

String PlaySection::ToString(int indent) const {
	String s;
	s.Cat('\t', indent);
	s << "Section " << idx+1 << " (" << title.ToString(-1) << "):\n";
	s << dialog.ToString("Dialog", indent+1);
	return s;
}

String PlayIdentifier::ToString() const {
	if (name.IsEmpty())
		return "<PlayIdentifier>";
	return name.ToString();
}

String PlaySentence::ToString(int indent) const {
	String s;
	if (indent >= 0)
		s.Cat('\t', indent);
	int i = 0;
	//if (voice_id.GetCount())
	//	s << "[voice " << voice_id.ToString() << "] ";
	for (const Token& t : tokens) {
		if (i++ > 0)
			s.Cat(' ');
		s << t.GetTextValue();
	}
	if (indent >= 0)
		s.Cat('\n');
	return s;
}

Value PlaySentence::GetData() const {
	String s = ToString();
	
	return s;
}

String PlayLine::ToString(int indent) const {
	String s;
	s.Cat('\t', indent);
	if (is_comment) {
		s << "Comment:\n";
		for (const PlaySentence& sent : sents)
			s << sent.ToString(indent+1);
	}
	else if (is_narration) {
		s << "Narration:\n";
		for (const PlaySentence& sent : sents)
			s << sent.ToString(indent+1);
	}
	else {
		s << id.ToString() << ":\n";
		for (const PlaySentence& sent : sents)
			s << sent.ToString(indent+1);
	}
	return s;
}

String MetaText::ToString(String title, int indent) const {
	String s;
	if (title.IsEmpty())
		title = "<MetaText>";
	s.Cat('\t', indent);
	s << title << ":\n";
	for (const PlaySentence& sent : sents)
		s << sent.ToString(indent+1);
	return s;
}

String PlayDialogue::ToString(String title, int indent) const {
	String s;
	if (title.IsEmpty())
		title = "<PlayDialogue>";
	s.Cat('\t', indent);
	s << title << ":\n";
	for (const PlayLine& line : lines)
		s << line.ToString(indent+1);
	return s;
}

String PlayScript::ToString(int indent) const {
	String s;
	s << title.ToString("Title");
	s << description.ToString("Description");
	s << disclaimer.ToString("Disclaimer");
	s << author.ToString("Author");
	s << actors.ToString("Actors");
	
	s.Cat('\t', indent);
	s << "Parts:\n";
	for (const PlayPart& p : parts) {
		s << p.ToString(indent+1);
	}
	
	return s;
}


#define LW 96

String GetPartString() {
	return "Osa";
}

String GetSectionString() {
	return "Luku";
}


String PlayScript::ToScript() const {
	String s;
	
	s << title.ToScript() << "\n\n";
	s << description.ToScript() << "\n\n";
	s << disclaimer.ToScript() << "\n\n";
	s << author.ToScript() << "\n\n";
	
	for (const PlayPart& p : parts)
		s << p.ToScript() << "\n\n";
	
	return s;
}

String MetaText::ToScript() const {
	String s;
	
	for (const PlaySentence& ps : sents)
		s << CenteredString(ps.ToString(), LW) << "\n";
	
	return s;
}

Value MetaText::GetData() const {
	String s;
	
	for (const PlaySentence& ps : sents) {
		if (!s.IsEmpty()) s.Cat('\n');
		s << ps.ToString();
	}
	
	return s;
}

String PlayPart::ToScript() const {
	String s;
	
	s << CenteredString(GetPartString() + " " + IntStr(idx+1) + ": " + title.ToString(), LW) << "\n\n";
	
	for (const PlaySection& ps : sections) {
		s << ps.ToScript() << "\n\n";
	}
	
	return s;
}

String PlaySection::ToScript() const {
	String s;
	
	s << CenteredString(GetSectionString() + " " + IntStr(idx+1) + ": " + title.ToString(), LW) << "\n\n";
	
	s << dialog.ToScript();
	
	return s;
}

String PlayDialogue::ToScript() const {
	String s;
	
	for (const PlayLine& l : lines) {
		s << l.ToScript();
	}
	s << "\n";
	
	return s;
}

String PlayLine::ToScript() const {
	String s;
	
	if (is_comment) {
		s << "\n";
		for (const PlaySentence& ps : sents)
			s << "// " << ps.ToScript() << "\n";
		s << "\n";
	}
	else if (is_narration) {
		s << "\n";
		for (const PlaySentence& ps : sents)
			s << "    ** " + ps.ToScript() + " **" << "\n";
			//s << CenteredString("** " + ps.ToScript() + " **", LW) << "\n";
		s << "\n";
	}
	else if (is_meta) {
		for (const PlaySentence& ps : sents)
			s << "#" + ps.ToScript() << "\n";
	}
	else {
		s << id.ToScript() << ": ";
		int c = s.ToWString().GetCount();
		static const int indent = 13;
		if (c < indent)
			s.Cat(' ', indent - c);
		for(int i = 0; i < sents.GetCount(); i++) {
			const PlaySentence& ps = sents[i];
			if (i) s.Cat(' ', indent);
			s << ps.ToScript() << "\n";
		}
	}
	
	return s;
}

String PlaySentence::ToScript() const {
	String s;
	int i = 0;
	//if (voice_id.GetCount())
	//	s << "(" << voice_id.ToString() << ") ";
	for (const Token& t : tokens) {
		if (i++ > 0)
			s.Cat(' ');
		s << t.GetTextValue();
	}
	return TrimBoth(s);
}

String PlayIdentifier::ToScript() const {
	return name.ToString();
}





void PlayScript::MakeSubtitles() {
	subtitles.Clear();
	
	for (PlayPart& part : parts) {
		for (PlaySection& sect : part.sections) {
			for (PlayLine& line : sect.dialog.lines) {
				for (PlaySentence& sent : line.sents) {
					String s = sent.ToScript();
					
					int part_i = 0;
					int a = 0;
					int f = 0;
					while (1) {
						int f0 = s.Find(". ", f+1);
						int f1 = s.Find(", ", f+1);
						f = f0 == -1 ? f1 : f0;
						if (f < 0) break;
						
						int b = f+1;
						
						String part = s.Mid(a, b-a);
						
						Subtitle& st = subtitles.Add();
						st.line = &line;
						st.sent = &sent;
						st.part_i = part_i++;
						st.str = part.ToWString();
						
						a = b+1;
					}
					
					int b = s.GetCount();
					String part = s.Mid(a, b-a);
					Subtitle& st = subtitles.Add();
					st.line = &line;
					st.sent = &sent;
					st.part_i = part_i++;
					st.str = part.ToWString();
					
				}
			}
		}
	}
	
	//DUMPC(subtitles);
}


NAMESPACE_TOPSIDE_END