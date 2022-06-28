#include "IHal.h"

#if defined flagSDL2

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

NAMESPACE_PARALLEL_BEGIN

void StaticAudioOutputSinkCallback(void* userdata, Uint8* stream, int len) {
	if (!userdata) {
		memset(stream, 0, len);
		return;
	}
	
	AtomBase* atom = (AtomBase*)userdata;
	if (!Serial_Link_ForwardAsyncMem(atom->GetLink(), (byte*)stream, len)) {
		RTLOG("StaticAudioOutputSinkCallback: reading memory failed");
		memset(stream, 0, len);
	}
	else {
		float* flt = (float*)stream;
		RTLOG("StaticAudioOutputSinkCallback: reading success");
	}
}



bool HalSdl::AudioSinkDevice_Initialize(NativeAudioSinkDevice& dev, AtomBase& a, const Script::WorldState& ws) {
	auto ev_ctx = a.GetSpace()->template FindNearestAtomCast<SdlContextBase>(1);
	ASSERT(ev_ctx);
	if (!ev_ctx) {RTLOG("error: could not find SDL2 context"); return false;}
	
	if (!ev_ctx->AttachContext(a))
		return false;
	
	// Set init flag
	dword sdl_flag = SDL_INIT_AUDIO;
	ev_ctx->UserData().MapGetAdd("dependencies").MapGetAdd(a).MapSet("sdl_flag", (int64)sdl_flag);
	
	a.SetQueueSize(DEFAULT_AUDIO_QUEUE_SIZE);
	
	return true;
}

bool HalSdl::AudioSinkDevice_PostInitialize(NativeAudioSinkDevice& dev, AtomBase& a) {
	AtomBaseRef dep = a.GetDependency();
	if (dep.IsEmpty()) {
		LOG("HalSdl::AudioSinkDevice_PostInitialize: expected dependency atom but got null");
		return false;
	}
	
	if (!dep->IsRunning()) {
		LOG("HalSdl::AudioSinkDevice_PostInitialize: context is not running");
	}
	
	RTLOG("HalSdl::AudioSinkDevice_PostInitialize");
	
	SDL_AudioSpec audio_fmt;
	SDL_AudioSpec audio_desired;
	SDL_AudioDeviceID audio_dev;
	
	SDL_zero(audio_desired);
	audio_desired.freq = 44100;
	audio_desired.format = AUDIO_U16;
	audio_desired.channels = 2;
	audio_desired.samples = 1024;
	audio_desired.callback = StaticAudioOutputSinkCallback;
	audio_desired.userdata = &a;
	
	SDL_zero(audio_fmt);
	
	dev = SDL_OpenAudioDevice(NULL, 0, &audio_desired, &audio_fmt, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
	if (dev == 0) {
	    RTLOG("HalSdl::AudioSinkDevice_PostInitialize: error: failed to open audio: " << SDL_GetError());
	    return false;
	}
	
    if (audio_fmt.format != audio_desired.format) {
		// we let this one thing change.
        RTLOG("HalSdl::AudioSinkDevice_PostInitialize: warning: couldn't get desired audio format.");
    }
    
    SoundSample::Type st = SoundSample::FLT_LE;
    #if CPU_LITTLE_ENDIAN
    if (audio_fmt.format != AUDIO_F32) {
        switch (audio_fmt.format) {
            case AUDIO_S8:  st = SoundSample::S8_LE;  break;
            case AUDIO_S16: st = SoundSample::S16_LE; break;
            case AUDIO_S32: st = SoundSample::S32_LE; break;
            case AUDIO_U16: st = SoundSample::U16_LE; break;
            default: break;
            case AUDIO_U8:  st = SoundSample::U8_LE;  break;
        }
    }
    #else
    #error TODO
    #endif
    
    Format f;
    f.SetAudio(DevCls::CENTER, st, audio_fmt.channels, audio_fmt.freq, audio_fmt.samples);
    AudioFormat& fmt = f;
    
    //buf.SetFormat(fmt, 4*MIN_AUDIO_BUFFER_SAMPLES);
	
    SDL_PauseAudioDevice(dev, 0); // start audio playing.
    
    RTLOG("HalSdl::AudioSinkDevice_PostInitialize: opened format: " << fmt.ToString());
    
    a.UpdateSinkFormat(ValCls::AUDIO, f);
    
	return true;
}

bool HalSdl::AudioSinkDevice_Start(NativeAudioSinkDevice& dev, AtomBase& a) {
	
	return true;
}

void HalSdl::AudioSinkDevice_Stop(NativeAudioSinkDevice& dev, AtomBase& a) {
	a.ClearDependency();
}

void HalSdl::AudioSinkDevice_Uninitialize(NativeAudioSinkDevice& dev, AtomBase& a) {
	if (dev) {
		SDL_PauseAudioDevice(dev, 1);
		SDL_CloseAudioDevice(dev);
		dev = 0;
	}
}

bool HalSdl::AudioSinkDevice_Send(NativeAudioSinkDevice& dev, AtomBase& a, RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	return true;
}

bool HalSdl::AudioSinkDevice_Recv(NativeAudioSinkDevice& dev, AtomBase&, int, const Packet&) {
	return true;
}

void HalSdl::AudioSinkDevice_Finalize(NativeAudioSinkDevice& dev, AtomBase&, RealtimeSourceConfig&) {
	
}

void HalSdl::AudioSinkDevice_Update(NativeAudioSinkDevice& dev, AtomBase&, double dt) {
	
}

bool HalSdl::AudioSinkDevice_IsReady(NativeAudioSinkDevice& dev, AtomBase&, PacketIO& io) {
	return true;
}





bool HalSdl::ContextBase_Initialize(NativeContextBase& ctx, AtomBase& a, const Script::WorldState& ws) {
	RTLOG("HalSdl::ContextBase_Initialize");
	return true;
}

bool HalSdl::ContextBase_PostInitialize(NativeContextBase& ctx, AtomBase& a) {
	RTLOG("HalSdl::ContextBase_PostInitialize");
	
	// SDL
	uint32 sdl_flags = 0;
	HiValue deps = a.UserData()("dependencies");
	if (!deps.IsMap())
		deps.SetEmptyMap();
	const auto& map = deps.GetMap();
	for(int i = 0; i < map.GetCount(); i++) {
		HiValue hi_atom = map.GetKey(i);
		ASSERT(hi_atom.IsAtom());
		AtomBase& other = hi_atom.GetAtom();
		HiValue hi_data = map[i];
		HiValue hi_flag = hi_data("sdl_flag");
		ASSERT(hi_flag.IsInt64());
		uint32 flag = (uint32)hi_flag.GetInt64();
		sdl_flags |= flag;
	}
	
	if (SDL_Init(sdl_flags) < 0) {
		String last_error = SDL_GetError();
		LOG("SDL2::Context: error : " << last_error);
		return false;
	}
	
	return true;
}

bool HalSdl::ContextBase_Start(NativeContextBase& ctx, AtomBase& a) {
	return true;
}

void HalSdl::ContextBase_Stop(NativeContextBase& ctx, AtomBase& a) {
	
}

void HalSdl::ContextBase_Uninitialize(NativeContextBase& ctx, AtomBase& a) {
	RTLOG("HalSdl::ContextBase_Uninitialize");
	SDL_Quit();
}

bool HalSdl::ContextBase_Send(NativeContextBase& ctx, AtomBase& a, RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	return true;
}

bool HalSdl::ContextBase_AttachContext(NativeContextBase& ctx, AtomBase& a, AtomBase& other) {
	if (other.GetDependency()) {
		LOG("HalSdl::ContextBase_AttachContext: atom already has dependency");
		return false;
	}
	other.SetDependency(a);
	return true;
}

void HalSdl::ContextBase_DetachContext(NativeContextBase& ctx, AtomBase& a, AtomBase& other) {
	AtomBaseRef aref = a.AsRefT();
	if (other.GetDependency() == aref)
		other.SetDependency(AtomBaseRef());
}

bool HalSdl::ContextBase_Recv(NativeContextBase& ctx, AtomBase&, int, const Packet&) {
	return true;
}

void HalSdl::ContextBase_Finalize(NativeContextBase& ctx, AtomBase&, RealtimeSourceConfig&) {
	
}

void HalSdl::ContextBase_Update(NativeContextBase& ctx, AtomBase&, double dt) {
	
}

bool HalSdl::ContextBase_IsReady(NativeContextBase& ctx, AtomBase&, PacketIO& io) {
	return true;
}


	




/*enum {
	RENDSRC_BUF,
	RENDSRC_IMAGEDRAW,
};*/

bool HalSdl::CenterVideoSinkDevice_Initialize(NativeVideoSink& dev, AtomBase& a, const Script::WorldState& ws) {
	auto ev_ctx = a.GetSpace()->template FindNearestAtomCast<SdlContextBase>(1);
	ASSERT(ev_ctx);
	if (!ev_ctx) {RTLOG("error: could not find SDL2 context"); return false;}

	if (!ev_ctx->AttachContext(a))
		return false;

	String title = ws.GetString(".title", "SDL2 Window");
	dev.sz = ws.GetSize(".cx", ".cy", Size(1280,720));
	bool fullscreen = ws.GetBool(".fullscreen", false);
	bool sizeable = ws.GetBool(".sizeable", false);
	bool maximized = ws.GetBool(".maximized", false);

	HiValue& data = a.UserData();
	data.Set("cx", dev.sz.cx);
	data.Set("cy", dev.sz.cy);
	data.Set("fullscreen", fullscreen);
	data.Set("sizeable", sizeable);
	data.Set("maximized", maximized);
	data.Set("title", title);

	//dev.render_src = RENDSRC_BUF;
	
	// Set init flag
	dword sdl_flag = SDL_INIT_VIDEO;
	ev_ctx->UserData().MapGetAdd("dependencies").MapGetAdd(a).MapSet("sdl_flag", (int64)sdl_flag);

	return true;
}

bool HalSdl::CenterVideoSinkDevice_PostInitialize(NativeVideoSink& dev, AtomBase& a) {
	AppFlags& app_flags = GetAppFlags();
	dev.win = 0;
	dev.rend = 0;

	HiValue& data = a.UserData();
	Size screen_sz(data["cx"], data["cy"]);
	bool is_fullscreen = data("fullscreen").GetInt();
	bool is_sizeable = data("sizeable").GetInt();
	bool is_maximized = data("maximized").GetInt();
	String title = data("title");

	// Window
	uint32 flags = 0;

	if (is_fullscreen)	flags |= SDL_WINDOW_FULLSCREEN;
	if (is_sizeable)	flags |= SDL_WINDOW_RESIZABLE;
	if (is_maximized)	flags |= SDL_WINDOW_MAXIMIZED;

	if (SDL_CreateWindowAndRenderer(screen_sz.cx, screen_sz.cy, flags, &dev.win, &dev.rend) == -1)
        return false;
	SDL_SetWindowTitle(dev.win, title);
    
    
    
    // Renderer
    int fb_stride = 3;

	SDL_Texture* fb = SDL_CreateTexture(dev.rend, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, screen_sz.cx, screen_sz.cy);
	if (!fb) {
		LOG("error: couldn't create framebuffer texture");
		return false;
	}

	SDL_SetRenderTarget(dev.rend, fb);

	auto& rend_fb = dev.fb;
	rend_fb.Init(fb, screen_sz.cx, screen_sz.cy, fb_stride);
	//rend_fb.SetWindowFbo();

	if (is_fullscreen)
		SDL_SetWindowFullscreen(dev.win, SDL_WINDOW_FULLSCREEN);

	return true;
}

bool HalSdl::CenterVideoSinkDevice_Start(NativeVideoSink& dev, AtomBase& a) {

	return true;
}

void HalSdl::CenterVideoSinkDevice_Stop(NativeVideoSink& dev, AtomBase& a) {
	a.ClearDependency();
}

void HalSdl::CenterVideoSinkDevice_Uninitialize(NativeVideoSink& dev, AtomBase& a) {
	if (dev.rend) {
		SDL_DestroyRenderer(dev.rend);
		dev.rend = 0;
	}
	if (dev.win) {
		SDL_DestroyWindow(dev.win);
		dev.win = 0;
	}
}

bool HalSdl::CenterVideoSinkDevice_Send(NativeVideoSink& dev, AtomBase& a, RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	return true;
}

bool HalSdl::CenterVideoSinkDevice_Recv(NativeVideoSink& dev, AtomBase&, int ch_i, const Packet& p) {
	Format fmt = p->GetFormat();
	if (fmt.IsVideo()) {
		const Vector<byte>& data = p->GetData();
		const byte* mem = (const byte*)data.Begin();
		int len = data.GetCount();
		VideoFormat& vfmt = fmt;
		int frame_size = vfmt.GetFrameSize();
		
		if (mem && len > 0 && len == frame_size) {
			dev.fb.DrawFill(mem, len);
		}
		
		return true;
	}
	else if (fmt.IsProg()) {
		if (dev.id.IsEmpty())
			dev.id.Create(dev.sz, 3);
		
		//Size sz = fb.GetSize();
		//int channels = fb.GetChannels();
		InternalPacketData& data = p->GetData<InternalPacketData>();
		DrawCommand* cmd_screen_begin = (DrawCommand*)data.ptr;
		
		//pi.Create(sz, channels);
		dev.pi.Paint(*cmd_screen_begin, dev.id);
		
		//dev.render_src = RENDSRC_IMAGEDRAW;
		{
			RTLOG("HalSdl::CenterVideoSinkDevice_Recv: warning: slow screen buffer copy");
			
			auto fb = dev.fb.GetActiveColorBuffer();
			ASSERT(fb);
			uint32 fmt = 0;
			int access, w = 0, h = 0;
			if (SDL_QueryTexture(fb, &fmt, &access, &w, &h) < 0 || w == 0 || h == 0)
				return false;
			SDL_Surface* surf = 0;
			SDL_Rect r {0, 0, w, h};
			if (SDL_LockTextureToSurface(fb, &r, &surf) < 0 || !surf)
				return false;
			int stride = surf->format->BytesPerPixel;
			int pitch = surf->pitch;
			byte* pixels = (byte*)surf->pixels;
			int len = h * pitch;
			int id_len = dev.id->Data().GetCount();
			ASSERT(len == id_len);
			if (len == id_len) {
				// optional vertical invert
				#if 1
				memcpy(pixels, (byte*)dev.id->Data().Begin(), len);
				#else
				byte* to = pixels;
				byte* from = dev.id->Data().Begin();
				from += (h - 1) * pitch;
				for (int y = 0; y < h; y++) {
					memcpy(to, from, pitch);
					to += pitch;
					from -= pitch;
				}
				#endif
			}
			//memset(pixels, Random(0x100), len);
			SDL_UnlockTexture(fb);
		}
		
		return true;
	}
	else return false;
}

void HalSdl::CenterVideoSinkDevice_Finalize(NativeVideoSink& dev, AtomBase&, RealtimeSourceConfig& cfg) {
	SDL_RenderCopy(dev.rend, dev.fb.GetActiveColorBuffer(), NULL, NULL);
	SDL_RenderPresent(dev.rend);
}

void HalSdl::CenterVideoSinkDevice_Update(NativeVideoSink& dev, AtomBase&, double dt) {
	// pass
}

bool HalSdl::CenterVideoSinkDevice_IsReady(NativeVideoSink& dev, AtomBase&, PacketIO& io) {
	return true;
}












bool HalSdl::CenterFboSinkDevice_Initialize(NativeSw3dVideoSink& dev, AtomBase& a, const Script::WorldState& ws) {
	
	if (!dev.accel.Initialize(a, ws))
		return false;
	
	auto ev_ctx = a.GetSpace()->template FindNearestAtomCast<SdlContextBase>(1);
	ASSERT(ev_ctx);
	if (!ev_ctx) {RTLOG("error: could not find SDL2 context"); return false;}
	
	if (!ev_ctx->AttachContext(a))
		return false;
	
	String title = ws.GetString(".title", "SDL2 Window");
	Size sz = ws.GetSize(".cx", ".cy", Size(1280,720));
	bool fullscreen = ws.GetBool(".fullscreen", false);
	bool sizeable = ws.GetBool(".sizeable", false);
	bool maximized = ws.GetBool(".maximized", false);
	
	HiValue& data = a.UserData();
	data.Set("cx", sz.cx);
	data.Set("cy", sz.cy);
	data.Set("fullscreen", fullscreen);
	data.Set("sizeable", sizeable);
	data.Set("maximized", maximized);
	data.Set("title", title);
	
	
	// Set init flag
	dword sdl_flag = SDL_INIT_VIDEO;
	ev_ctx->UserData().MapGetAdd("dependencies").MapGetAdd(a).MapSet("sdl_flag", (int64)sdl_flag);
	
	return true;
}

bool HalSdl::CenterFboSinkDevice_PostInitialize(NativeSw3dVideoSink& dev, AtomBase& a) {
	AppFlags& app_flags = GetAppFlags();
	dev.win = 0;
	dev.rend = 0;
	
	HiValue& data = a.UserData();
	Size screen_sz(data["cx"], data["cy"]);
	bool is_fullscreen = data("fullscreen").GetInt();
	bool is_sizeable = data("sizeable").GetInt();
	bool is_maximized = data("maximized").GetInt();
	String title = data["title"];
	
	// Window
	uint32 flags = 0;
	
	if (is_fullscreen)	flags |= SDL_WINDOW_FULLSCREEN;
	if (is_sizeable)	flags |= SDL_WINDOW_RESIZABLE;
	if (is_maximized)	flags |= SDL_WINDOW_MAXIMIZED;
	
	if (SDL_CreateWindowAndRenderer(screen_sz.cx, screen_sz.cy, flags, &dev.win, &dev.rend) == -1)
        return false;
	SDL_SetWindowTitle(dev.win, title);
    
    
    
    // Renderer
    int fb_stride = 3;
	
	dev.fb = SDL_CreateTexture(dev.rend, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, screen_sz.cx, screen_sz.cy);
	if (!dev.fb) {
		LOG("error: couldn't create framebuffer texture");
		return false;
	}
	
	SDL_SetRenderTarget(dev.rend, dev.fb);
	
	dev.accel.SetNative(dev.display, dev.win, &dev.rend, dev.fb);
	
	if (!dev.accel.Open(screen_sz, fb_stride)) {
		LOG("HalSdl::CenterFboSinkDevice_PostInitialize: error: could not open opengl atom");
		return false;
	}
	
	if (is_fullscreen)
		SDL_SetWindowFullscreen(dev.win, SDL_WINDOW_FULLSCREEN);
	
	return true;
}

bool HalSdl::CenterFboSinkDevice_Start(NativeSw3dVideoSink& dev, AtomBase& a) {
	
	return true;
}

void HalSdl::CenterFboSinkDevice_Stop(NativeSw3dVideoSink& dev, AtomBase& a) {
	a.ClearDependency();
}

void HalSdl::CenterFboSinkDevice_Uninitialize(NativeSw3dVideoSink& dev, AtomBase& a) {
	dev.accel.Uninitialize();
	
	if (dev.rend) {
		SDL_DestroyRenderer(dev.rend);
		dev.rend = 0;
	}
	if (dev.win) {
		SDL_DestroyWindow(dev.win);
		dev.win = 0;
	}
}

bool HalSdl::CenterFboSinkDevice_Recv(NativeSw3dVideoSink& dev, AtomBase&, int ch_i, const Packet& p) {
	return dev.accel.Recv(ch_i, p);
}

void HalSdl::CenterFboSinkDevice_Finalize(NativeSw3dVideoSink& dev, AtomBase&, RealtimeSourceConfig& cfg) {
	dev.accel.Render(cfg);
}

bool HalSdl::CenterFboSinkDevice_Send(NativeSw3dVideoSink& dev, AtomBase& a, RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	/*Format fmt = in.GetFormat();
	if (fmt.IsVideo()) {
		const Vector<byte>& pixmap = in.Data();
		VideoFormat& vfmt = fmt;
		int frame_sz = vfmt.GetFrameSize();
		ASSERT(pixmap.GetCount() == frame_sz);
		
		int width = vfmt.res[0];
		int height = vfmt.res[1];
		
	}*/
	return true;
}

void HalSdl::CenterFboSinkDevice_Update(NativeSw3dVideoSink& dev, AtomBase&, double dt) {
	
}

bool HalSdl::CenterFboSinkDevice_IsReady(NativeSw3dVideoSink& dev, AtomBase&, PacketIO& io) {
	return true;
}











#ifdef flagOGL
bool HalSdl::OglVideoSinkDevice_Initialize(NativeOglVideoSink& dev, AtomBase& a, const Script::WorldState& ws) {
	
	if (!dev.accel.Initialize(a, ws))
		return false;
	
	auto ev_ctx = a.GetSpace()->template FindNearestAtomCast<SdlContextBase>(1);
	ASSERT(ev_ctx);
	if (!ev_ctx) {RTLOG("error: could not find SDL2 context"); return false;}
	
	if (!ev_ctx->AttachContext(a))
		return false;
	
	String title = ws.GetString(".title", "SDL2 Window");
	Size sz = ws.GetSize(".cx", ".cy", Size(1280,720));
	bool fullscreen = ws.GetBool(".fullscreen", false);
	bool sizeable = ws.GetBool(".sizeable", false);
	bool maximized = ws.GetBool(".maximized", false);
	
	HiValue& data = a.UserData();
	data.Set("cx", sz.cx);
	data.Set("cy", sz.cy);
	data.Set("fullscreen", fullscreen);
	data.Set("sizeable", sizeable);
	data.Set("maximized", maximized);
	data.Set("title", title);
	
	
	// Set init flag
	dword sdl_flag = SDL_INIT_VIDEO | SDL_WINDOW_OPENGL;
	ev_ctx->UserData().MapGetAdd("dependencies").MapGetAdd(a).MapSet("sdl_flag", (int64)sdl_flag);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	
	return true;
}

bool HalSdl::OglVideoSinkDevice_PostInitialize(NativeOglVideoSink& dev, AtomBase& a) {
	AppFlags& app_flags = GetAppFlags();
	dev.win = 0;
	dev.rend = 0;
	
	HiValue& data = a.UserData();
	Size screen_sz(data["cx"], data["cy"]);
	int is_fullscreen = data["fullscreen"];
	int is_sizeable = data["sizeable"];
	int is_maximized = data["maximized"];
	String title = data["title"];
	
	// Window
	uint32 flags = 0;
	
	if (is_fullscreen)	flags |= SDL_WINDOW_FULLSCREEN;
	if (is_sizeable)	flags |= SDL_WINDOW_RESIZABLE;
	if (is_maximized)	flags |= SDL_WINDOW_MAXIMIZED;
	
	if (SDL_CreateWindowAndRenderer(screen_sz.cx, screen_sz.cy, flags, &dev.win, &dev.rend) == -1) {
		LOG("HalSdl::OglVideoSinkDevice_PostInitialize: error: could not create window and renderer");
        return false;
	}
	SDL_SetWindowTitle(dev.win, title);
    
    
    
    // Renderer
    SDL_GetRendererInfo(dev.rend, &dev.rend_info);
	if ((dev.rend_info.flags & SDL_RENDERER_ACCELERATED) == 0 ||
        (dev.rend_info.flags & SDL_RENDERER_TARGETTEXTURE) == 0) {
        LOG("HalSdl::OglVideoSinkDevice_PostInitialize: error: renderer does not have acceleration");
        return false;
    }
	
	// GL context
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 0);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	dev.gl_ctx = SDL_GL_CreateContext(dev.win);
	GetAppFlags().SetOpenGLContextOpen();
	
	// Glew
	GLenum err = glewInit();
	if (err != GLEW_OK) {
		LOG("Glew error: " << (const char*)glewGetErrorString(err));
		return false;
	}
    
	
	
	dev.accel.SetNative(dev.display, dev.win, &dev.rend, 0);
	
    int fb_stride = 3;
	if (!dev.accel.Open(screen_sz, fb_stride)) {
		LOG("HalSdl::OglVideoSinkDevice_PostInitialize: error: could not open opengl atom");
		return false;
	}
	
	if (!dev.accel.PostInitialize())
		return false;
	
	if (is_fullscreen)
		SDL_SetWindowFullscreen(dev.win, SDL_WINDOW_FULLSCREEN);
	
	return true;
}

bool HalSdl::OglVideoSinkDevice_Start(NativeOglVideoSink& dev, AtomBase&) {
	
	return true;
}

void HalSdl::OglVideoSinkDevice_Stop(NativeOglVideoSink& dev, AtomBase& a) {
	a.ClearDependency();
}

void HalSdl::OglVideoSinkDevice_Uninitialize(NativeOglVideoSink& dev, AtomBase&) {
	dev.accel.Uninitialize();
	
	if (dev.rend) {
		SDL_DestroyRenderer(dev.rend);
		dev.rend = 0;
	}
	if (dev.win) {
		SDL_DestroyWindow(dev.win);
		dev.win = 0;
	}
}

bool HalSdl::OglVideoSinkDevice_Send(NativeOglVideoSink& dev, AtomBase&, RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	/*Format fmt = in.GetFormat();
	if (fmt.IsVideo()) {
		const Vector<byte>& pixmap = in.Data();
		VideoFormat& vfmt = fmt;
		int frame_sz = vfmt.GetFrameSize();
		ASSERT(pixmap.GetCount() == frame_sz);
		
		int width = vfmt.res[0];
		int height = vfmt.res[1];
		
	}*/
	dev.accel.Render(cfg);
	return true;
}

bool HalSdl::OglVideoSinkDevice_Recv(NativeOglVideoSink& dev, AtomBase&, int ch_i, const Packet& p) {
	return dev.accel.Recv(ch_i, p);
}

void HalSdl::OglVideoSinkDevice_Finalize(NativeOglVideoSink& dev, AtomBase& a, RealtimeSourceConfig& cfg) {
	
}

void HalSdl::OglVideoSinkDevice_Update(NativeOglVideoSink& dev, AtomBase& a, double dt) {
	dev.accel.Update(dt);
}

bool HalSdl::OglVideoSinkDevice_IsReady(NativeOglVideoSink& dev, AtomBase&, PacketIO& io) {
	return true;
}

#endif









bool HalSdl::EventsBase_Initialize(NativeEventsBase& dev, AtomBase& a, const Script::WorldState&) {
	memset(&dev, 0, sizeof(NativeEventsBase));
	
	
	auto ev_ctx = a.GetSpace()->template FindNearestAtomCast<SdlContextBase>(1);
	ASSERT(ev_ctx);
	if (!ev_ctx) {RTLOG("error: could not find SDL2 context"); return false;}
	
	if (!ev_ctx->AttachContext(a))
		return false;
	
	// Set init flag
	dword sdl_flag = SDL_INIT_EVENTS;
	ev_ctx->UserData().MapGetAdd("dependencies").MapGetAdd(a).MapSet("sdl_flag", (int64)sdl_flag);
	
	
	return true;
}

bool HalSdl::EventsBase_PostInitialize(NativeEventsBase& dev, AtomBase& a) {
	AtomBaseRef dep = a.GetDependency();
	if (dep.IsEmpty()) {
		LOG("HalSdl::EventsBase_PostInitialize: expected dependency atom but got null");
		return false;
	}
	
	if (!dep->IsRunning()) {
		LOG("HalSdl::EventsBase_PostInitialize: context is not running");
	}
	
	RTLOG("HalSdl::EventsBase_PostInitialize");
	
	a.AddAtomToUpdateList();
	
	return true;
}

bool HalSdl::EventsBase_Start(NativeEventsBase& dev, AtomBase& a) {
	// pass
	return true;
}

void HalSdl::EventsBase_Stop(NativeEventsBase& dev, AtomBase& a) {
	// pass
}

void HalSdl::EventsBase_Uninitialize(NativeEventsBase& dev, AtomBase& a) {
	a.RemoveAtomFromUpdateList();
}

bool HalSdl::EventsBase_Send(NativeEventsBase& dev, AtomBase& a, RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) {
	ASSERT(dev.ev_sendable);
	if (!dev.ev_sendable)
		return false;
	

	Format fmt = out.GetFormat();
	RTLOG("HalSdl::EventsBase_Send: " << fmt.ToString());
	
	if (fmt.IsEvent()) {
		out.seq = dev.seq++;
		UPP::CtrlEvent& dst = out.SetData<UPP::CtrlEvent>();
		dst = dev.ev;
		dev.ev_sendable = false;
	}
	
	return true;
}

bool HalSdl::EventsBase_Recv(NativeEventsBase& dev, AtomBase& a, int sink_ch, const Packet& p) {
	return true;
}

void HalSdl::EventsBase_Finalize(NativeEventsBase& dev, AtomBase&, RealtimeSourceConfig&) {
	
}

void HalSdl::EventsBase_Update(NativeEventsBase& dev, AtomBase&, double dt) {
	dev.time += dt;
}

#ifdef flagSCREEN
void Events__PutKeyFlags(HalSdl::NativeEventsBase& dev, dword& key) {
	if (dev.is_lalt   || dev.is_ralt)		key |= K_ALT;
	if (dev.is_lshift || dev.is_rshift)		key |= K_SHIFT;
	if (dev.is_lctrl  || dev.is_rctrl)		key |= K_CTRL;
}
#endif

bool Events__Poll(HalSdl::NativeEventsBase& dev, AtomBase& a) {
	UPP::CtrlEvent& e = dev.ev;
	
	SDL_Event event;
	Size screen_sz;
	Point mouse_pt;
#ifdef flagSCREEN
	auto s = a.GetSpace();
	auto v_sink   = s->template FindNearestAtomCast<SdlCenterVideoSinkDevice>(2);
	auto sw_sink  = s->template FindNearestAtomCast<SdlCenterFboSinkDevice>(2);
	::SDL_Renderer* rend = 0;
	if (v_sink)   rend = v_sink->dev.rend;
	if (sw_sink)  rend = sw_sink->dev.rend;
#ifdef flagOGL
	auto ogl_sink = s->template FindNearestAtomCast<SdlOglVideoSinkDevice>(2);
	if (ogl_sink) rend = ogl_sink->dev.rend;
#endif
#endif
	dword key;
	int mouse_code;
	
	// Process the events
	while (SDL_PollEvent(&event)) {
		e.Clear();
		
		switch (event.type) {
			
#ifdef flagSCREEN
			
		case SDL_WINDOWEVENT:
			
			/*if (event.window.event == SDL_WINDOWEVENT_LEAVE) {
				if (IsCaptured())
					;//Ctrl::captured->LeftUp(prev_mouse_pt, 0);
				else
					DeepMouseLeave();
			}
			else*/
			if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
				e.type = EVENT_SHUTDOWN;
				return true;
			}
			else if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
				screen_sz.cx = event.window.data1;
				screen_sz.cy = event.window.data2;
				dev.sz = screen_sz;
				/*SetFrameRect0(RectC(0, 0, screen_sz.cx, screen_sz.cy));
				SetContentRect(RectC(0, 0, screen_sz.cx, screen_sz.cyh));
				SetPendingLayout();
				SetPendingEffectRedraw();
				SetPendingRedraw();*/
				e.type = EVENT_WINDOW_RESIZE;
				e.sz = screen_sz;
				return true;
			}
			break;
		
			
		case SDL_KEYDOWN:
		
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:	event.type = SDL_QUIT; break;
				case SDLK_LALT:		dev.is_lalt = true; break;
				case SDLK_RALT:		dev.is_ralt = true; break;
				case SDLK_LSHIFT:	dev.is_lshift = true; break;
				case SDLK_RSHIFT:	dev.is_rshift = true; break;
				case SDLK_LCTRL:	dev.is_lctrl = true; break;
				case SDLK_RCTRL:	dev.is_rctrl = true; break;
			}
			
			key = event.key.keysym.sym;
			if (key & SDLK_SCANCODE_MASK) {
				key &= ~SDLK_SCANCODE_MASK;
				
				// TODO handle codes separately
				if (0 /*key == */) {
					
				}
				else key = 0;
			}
			Events__PutKeyFlags(dev, key);
			
			e.type = EVENT_KEYDOWN;
			e.value = key;
			e.n = 1;
			e.pt = Point(0,0);
			
			return true;
			
		case SDL_KEYUP:
		
			switch (event.key.keysym.sym) {
				case SDLK_LALT:		dev.is_lalt = false; break;
				case SDLK_RALT:		dev.is_ralt = false; break;
				case SDLK_LSHIFT:	dev.is_lshift = false; break;
				case SDLK_RSHIFT:	dev.is_rshift = false; break;
				case SDLK_LCTRL:	dev.is_lctrl = false; break;
				case SDLK_RCTRL:	dev.is_rctrl = false; break;
			}
			
			key = event.key.keysym.sym | K_KEYUP;
			if (key & SDLK_SCANCODE_MASK) {
				key &= ~SDLK_SCANCODE_MASK;
				
				// TODO handle codes separately
				if (0 /*key == */) {
					
				}
				else key = 0;
			}
			Events__PutKeyFlags(dev, key);
			
			e.type = EVENT_KEYUP;
			e.value = key;
			e.n = 1;
			e.pt = Point(0,0);
			
			return true;
			
		case SDL_MOUSEMOTION:
			mouse_pt = Point(event.motion.x, event.motion.y);
			key = 0;
			Events__PutKeyFlags(dev, key);
			
			e.type = EVENT_MOUSEMOVE;
			e.value = key;
			e.pt = mouse_pt;
			
			dev.prev_mouse_pt = mouse_pt;
			return true;
		
		case SDL_MOUSEWHEEL:
			key = 0;
			Events__PutKeyFlags(dev, key);
			
			e.type = EVENT_MOUSEWHEEL;
			e.value = key;
			e.pt = mouse_pt;
			
			return true;
			
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			
			mouse_code = 0;
			//mouse_zdelta = 0;
			if (event.button.state == SDL_PRESSED) {
				if (event.button.clicks == 1) {
					if (event.button.button == SDL_BUTTON_LEFT)
						mouse_code = VirtualCtrl::LEFTDOWN;
						//mouse_code = MOUSE_LEFTDOWN;
					else if (event.button.button == SDL_BUTTON_MIDDLE)
						mouse_code = VirtualCtrl::MIDDLEDOWN;
						//mouse_code = MOUSE_MIDDLEDOWN;
					else if (event.button.button == SDL_BUTTON_RIGHT)
						mouse_code = VirtualCtrl::RIGHTDOWN;
						//mouse_code = MOUSE_RIGHTDOWN;
				}
				else if (event.button.clicks == 2) {
					if (event.button.button == SDL_BUTTON_LEFT)
						mouse_code = VirtualCtrl::LEFTDOUBLE;
						//mouse_code = MOUSE_LEFTDOUBLE;
					else if (event.button.button == SDL_BUTTON_MIDDLE)
						mouse_code = VirtualCtrl::MIDDLEDOUBLE;
						//mouse_code = MOUSE_MIDDLEDOUBLE;
					else if (event.button.button == SDL_BUTTON_RIGHT)
						mouse_code = VirtualCtrl::RIGHTDOUBLE;
						//mouse_code = MOUSE_RIGHTDOUBLE;
				}
				else {
					if (event.button.button == SDL_BUTTON_LEFT)
						mouse_code = VirtualCtrl::LEFTTRIPLE;
						//mouse_code = MOUSE_LEFTTRIPLE;
					else if (event.button.button == SDL_BUTTON_MIDDLE)
						mouse_code = VirtualCtrl::MIDDLETRIPLE;
						//mouse_code = MOUSE_MIDDLETRIPLE;
					else if (event.button.button == SDL_BUTTON_RIGHT)
						mouse_code = VirtualCtrl::RIGHTTRIPLE;
						//mouse_code = MOUSE_RIGHTTRIPLE;
				}
				/*else if (event.button.button == SDL_BUTTON_WHEELUP)
					mouse_zdelta = 120;
				else if (event.button.button == SDL_BUTTON_WHEELDOWN)
					mouse_zdelta = -120;*/
			}
			else if (event.button.state == SDL_RELEASED) {
				if (event.button.button == SDL_BUTTON_LEFT)
					mouse_code = VirtualCtrl::LEFTUP;
					//mouse_code = MOUSE_LEFTUP;
				else if (event.button.button == SDL_BUTTON_MIDDLE)
					mouse_code = VirtualCtrl::MIDDLEUP;
					//mouse_code = MOUSE_MIDDLEUP;
				else if (event.button.button == SDL_BUTTON_RIGHT)
					mouse_code = VirtualCtrl::RIGHTUP;
					//mouse_code = MOUSE_RIGHTUP;
			}
			
			if (mouse_code) {
				mouse_pt = Point(event.button.x, event.button.y);
				key = 0;
				Events__PutKeyFlags(dev, key);
				
				e.type = EVENT_MOUSE_EVENT;
				e.value = key;
				e.pt = mouse_pt;
				e.n = mouse_code;
				
				dev.prev_mouse_pt = mouse_pt;
				return true;
			}
			
#endif
			
		default:
			break;
		}
	}
	
	
	return false;
}

bool HalSdl::EventsBase_IsReady(NativeEventsBase& dev, AtomBase& a, PacketIO& io) {
	bool b = io.full_src_mask == 0;
	if (b) {
		if (dev.seq == 0) {
			auto s = a.GetSpace();
			dev.ev.type = EVENT_WINDOW_RESIZE;
			auto v_sink   = s->template FindNearestAtomCast<SdlCenterVideoSinkDevice>(2);
			auto sw_sink  = s->template FindNearestAtomCast<SdlCenterFboSinkDevice>(2);
			#ifdef flagOGL
			auto ogl_sink = s->template FindNearestAtomCast<SdlOglVideoSinkDevice>(2);
			#endif
			
			int x = 0, y = 0;
			if (v_sink) {
				SDL_GetWindowPosition(v_sink->dev.win, &x, &y);
				dev.ev_sendable = true;
			}
			else if (sw_sink) {
				SDL_GetWindowPosition(sw_sink->dev.win, &x, &y);
				dev.ev_sendable = true;
			}
			#ifdef flagOGL
			else if (ogl_sink) {
				SDL_GetWindowPosition(ogl_sink->dev.win, &x, &y);
				dev.ev_sendable = true;
			}
			#endif
			else {
				RTLOG("HalSdl::EventsBase_IsReady: skipping windows resize, because no screen is in context");
				dev.seq++;
				b = false;
			}
			dev.sz = Size(x,y);
		}
		else if (Events__Poll(dev, a)) {
			dev.ev_sendable = true;
		}
		else {
			dev.ev_sendable = false;
			b = false;
		}
	}
	RTLOG("HalSdl::EventsBase_IsReady: " << (b ? "true" : "false"));
	return b;
}


NAMESPACE_PARALLEL_END
#endif

