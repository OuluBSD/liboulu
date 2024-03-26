#include "EmuCtrl.h"


EmuApp::EmuApp() : scr(*this) {
	Title("LittleKernel emulator");
	Add(scr.SizePos());
	
	SetRect(scr.GetPreferredSize());
	
	WhenClose << THISBACK(OnClose);
}

EmuApp::~EmuApp() {
	Stop();
}

void EmuApp::OnClose() {
	Thread::ShutdownThreads();
}

void EmuApp::Init() {
	ASSERT(global);
	Monitor& mon = global->monitor;
	
	#define LINK(x) mon.On##x << THISBACK(x);
	LINK(MoveCursor)
	LINK(Scroll)
	LINK(Put)
	LINK(Clear)
	LINK(Write)
	LINK(WriteN)
	LINK(WriteDec)
	LINK(WriteHexPtr)
	LINK(WriteHexInt)
	LINK(NewLine)
	#undef LINK
	
}

void EmuApp::Data() {
	Monitor& mon = global->monitor;
	
	
	
}

void EmuApp::Start() {
	running = 1;
	stopped = 0;
	
	Thread::Start(THISBACK(EmuProcess));
	Sleep(100); // give some time for booting
	
	TopWindow::Run();
	
	running = 0;
	while (!stopped) Sleep(1);
}

void EmuApp::EmuProcess() {
	multiboot mboot;
	
	mboot.OnMonitorCreate << THISBACK(Init);
	
	int ret = multiboot_main(&mboot);
	
	stopped = 1;
	running = 0;
}

void EmuApp::RefreshOutput() {
	Refresh();
}

void EmuApp::MoveCursor() {
	
}

void EmuApp::Scroll() {
	
}

void EmuApp::Put(char c) {
	scr.Put(c);
}

void EmuApp::Clear() {
	scr.ClearScreen();
}

void EmuApp::WriteString(const String& s) {
	WString ws = s.ToWString();
	for(int i = 0; i < ws.GetCount(); i++) {
		wchar chr = ws[i];
		scr.Put(chr);
	}
}

void EmuApp::Write(const char *c) {
	WriteString(c);
}

void EmuApp::WriteN(const char *c, int len) {
	String s;
	s.Set(c, len);
	WriteString(s);
}

void EmuApp::WriteDec(int i) {
	WriteString(UPP::IntStr(i));
}

void EmuApp::WriteHexPtr(void* p) {
	WriteString(Format("%X", (int64)p));
}

void EmuApp::WriteHexInt(size_t i) {
	WriteString(Format("%X", (int64)i));
}

void EmuApp::NewLine() {
	scr.NewLine();
}



EmuScreen::EmuScreen(EmuApp& a) : app(a) {
	int grid_w = 14;
	grid = Size(grid_w, grid_w*4/3);
	
	int cols = 80;
	int expected_w = cols * grid_w;
	int expected_h = expected_w * 3 / 4;
	int rows = expected_h / grid.cy;
	
	ResizeTxt(Size(cols, rows));
	cur = Point(0,0);
	bg = Black();
	fg = White();
	
	// https://int10h.org/oldschool-pc-fonts/download/
	String preferred_fnt = "AcPlus IBM BIOS-2y";
	
	fnt = Monospace(grid.cy);
	for(int i = 0; i < Font::GetFaceCount(); i++) {
		String face_name = Font::GetFaceName(i);
		if (face_name == preferred_fnt) {
			fnt.SetFace(i, face_name);
			break;
		}
	}
	
	tc.Set(-1000/60, THISBACK(PostRefresh));
}

void EmuScreen::ClearScreen() {
	memset(scr_txt.Begin(), 0, scr_txt.GetCount() * sizeof(wchar));
}

void EmuScreen::NewLine() {
	cur.y++;
	cur.x = 0;
}

void EmuScreen::Put(wchar w) {
	if (w == '\n') {
		cur.y++;
		cur.x = 0;
	}
	else if (w == '\r')
		cur.x = 0;
	else if (cur.x >= 0 && cur.y < scr_txt_sz.cx &&
			 cur.y >= 0 && cur.y < scr_txt_sz.cy) {
		int pos = cur.y * scr_txt_sz.cx + cur.x;
		scr_txt[pos] = w;
		cur.x++;
	}
}
	
void EmuScreen::Paint(Draw& d) {
	Size sz(GetSize());
	d.DrawRect(sz, bg);
	
	int len = scr_txt_sz.cx * scr_txt_sz.cy;
	ASSERT(scr_txt.GetCount() == len);
	wchar* it = scr_txt.Begin();
	int gy = 0;
	for (int y = 0; y < scr_txt_sz.cy; y++) {
		int gx = 0;
		for (int x = 0; x < scr_txt_sz.cx; x++) {
			wchar w = *it++;
			if (w > 0) {
				wchar txt[2];
				txt[0] = w;
				txt[1] = 0;
				d.DrawText(gx, gy, txt, fnt, fg);
			}
			gx += grid.cx;
		}
		gy += grid.cy;
	}
}

Size EmuScreen::GetPreferredSize() const {
	return Size(
		scr_txt_sz.cx * grid.cx,
		scr_txt_sz.cy * grid.cy);
}

int __emu_kb_char_queue[KB_QUEUE_LENGTH];

bool EmuScreen::Key(dword key, int count) {
	if (key & K_KEYUP || key & K_DELTA) {
		
	}
	else {
		String desc = GetKeyDesc(key);
		int chr = desc.GetCount() == 1 ? desc[0] : 0;
		if (chr && chr >= 0x20 && chr < 0x80) {
			//Put(chr);
			for(int i = 0; i < KB_QUEUE_LENGTH; i++) {
				int& e = __emu_kb_char_queue[i];
				if (e == 0) {
					e = chr;
					break;
				}
			}
			Registers r;
			memset(&r, 0, sizeof(r));
			r.int_no = IRQ1;
			r.eax = chr;
			isr_handler(r);
			return true;
		}
	}
	
	return false;
}
