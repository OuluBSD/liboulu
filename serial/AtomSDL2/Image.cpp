#include "AtomSDL2.h"
#ifdef flagGUI

NAMESPACE_SERIAL_BEGIN



SDL2ImageBase::SDL2ImageBase()
{
	
}

bool SDL2ImageBase::Initialize(const Script::WorldState& ws) {
	LOG(ws.ToString());
	
	String arg_filepath = ws.Get(".filepath");
	if (arg_filepath.IsEmpty()) {
		LOG("SDL2ImageBase: error: no 'filepath' given");
		return false;
	}
	
	String filepath = RealizeShareFile(arg_filepath);
	RTLOG("SDL2ImageBase: filepath=\"" << filepath << "\"");
	
	if (!FileExists(filepath)) {
		bool found = false;
		String title = GetFileTitle(filepath);
		String other_name = ToyShaderHashToName().Get(title, "");
		String ext = GetFileExt(filepath);
		if (!other_name.IsEmpty()) {
			LOG("SDL2ImageBase: found real name from hash: " << other_name);
			String toypath =
				AppendFileName(
					GetFileDirectory(arg_filepath),
					other_name + ext);
			if (!FileExists(toypath)) {
				toypath = RealizeShareFile(toypath);
				LOG("SDL2ImageBase: trying to find sharefile: " << toypath);
			}
			if (FileExists(toypath)) {
				filepath = toypath;
				found = true;
				LOG("SDL2ImageBase: changed hash to file " << filepath);
			}
			else {
				LOG("SDL2ImageBase: internal error: file not found: " << filepath);
			}
		}
		
		if (!found) {
			LOG("SDL2ImageBase: error: file does not exist: " << filepath);
			return false;
		}
	}
	
	if (ws.Get(".vflip") == "true")
		vflip = true;
	
	OBJ_CREATE
	
	Image img = Image(IMG_Load(filepath.Begin()));
	if (img.IsEmpty()) {
		LOG("SDL2ImageBase: error: empty image: " << filepath);
		return false;
	}
	imgs.Add(img);
	
	return true;
}

void SDL2ImageBase::Uninitialize() {
	imgs.Clear();
	obj.Clear();
}

bool SDL2ImageBase::ProcessPackets(PacketIO& io) {
	if (imgs.IsEmpty()) return false;
	
	PacketIO::Sink& sink = io.sink[0];
	Packet& in = sink.p;
	ASSERT(in); if (!in) return false;
	sink.may_remove = true;
	
	RTLOG("SDL2ScreenBase::ProcessPackets: sink #0: " << in->ToString());
	
	PacketIO::Sink& prim_sink = io.sink[0];
	PacketIO::Source& prim_src = io.src[0];
	Packet& prim_out = prim_src.p;
	prim_src.from_sink_ch = 0;
	prim_out = ReplyPacket(0, prim_sink.p);
	
	ASSERT(io.src_count >= 2);
	PacketIO::Source& src = io.src[1];
	Packet& out = src.p;
	src.from_sink_ch = 0;
	
	out = ReplyPacket(1, prim_sink.p);
	
	PacketValue& v = *out;
	Image& img = imgs[0];
	
	Format fmt = v.GetFormat();
	ASSERT(fmt.IsVideo());
	fmt.vid.SetSize(img.GetSize());
	v.SetFormat(fmt);
	
	// shadertoy compatibility
	if (vflip)
		img = MirrorVertical(img);
	
	DataFromImage(img, v.Data());
	ASSERT(v.GetData().GetCount());
	
	imgs.Remove(0);
	
	return true;
}

bool SDL2ImageBase::IsReady(PacketIO& io) {
	bool b = io.full_src_mask == 0 && !imgs.IsEmpty();
	RTLOG("SDL2ImageBase::IsReady: " << (b ? "true" : "false"));
	return b;
}

bool SDL2ImageBase::LoadFileAny(String path) {
	imgs.Clear();
	
	TODO
	#if 0
	sstream.SetSkipDrop(false);
	
	if (path.Left(9) == "<cubemap>") {
		path = path.Mid(9);
		
		String dir = GetFileDirectory(path);
		String title = GetFileTitle(path);
		String ext = GetFileExt(path);
		
		for(int i = 0; i < 6; i++) {
			if (i)
				path = AppendFileName(dir, title + "_" + IntStr(i) + ext);
			
			SDL_Surface* surf = IMG_Load(path);
			if (!surf) {
				last_error = IMG_GetError();
				return false;
			}
			
			#ifdef flagGUI
			img << Image(surf);
			#else
			TODO
			#endif
		}
		sstream.SetSkipDrop();
		return true;
	}
	else {
		SDL_Surface* surf = IMG_Load(path);
		if (!surf) {
			last_error = IMG_GetError();
			return false;
		}
		
		#ifdef flagGUI
		img << Image(surf);
		#else
		TODO
		#endif
		
		sstream.SetSkipDrop();
		return true;
	}
	#endif
}

Size SDL2ImageBase::GetResolution() const {
	if (imgs.GetCount())
		return imgs[0].GetSize();
	return Size(0,0);
}

#if 0
void SDL2ImageBase::EmitStatic() {
	int id = 0;
	for(Image& img : this->img) {
		int w = img.GetWidth();
		int h = img.GetHeight();
		int d = 1;
		int stride = img.GetStride();
		int pitch = img.GetPitch();
		const byte* img_data = img.Begin();
		
		StaticValueData data;
		data.obj_i = id;
		data.w = w;
		data.h = h;
		data.d = d;
		data.stride = stride;
		data.pitch = pitch;
		data.data = img_data;
		
		for(StaticSinkRef sink : StaticSource::GetConnections())
			sink->RecvStatic(data);
		id++;
	}
}
#endif



NAMESPACE_SERIAL_END

#endif
