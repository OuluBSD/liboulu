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
}



bool HalSdl2::AudioSinkDevice_Initialize(NativeAudioSinkDevice& dev, AtomBase& a, const Script::WorldState& ws) {
	auto ev_ctx = a.GetSpace()->template FindNearestAtomCast<Sdl2ContextBase>(1);
	ASSERT(ev_ctx);
	if (!ev_ctx) {RTLOG("error: could not find SDL2 context"); return false;}
	
	if (!ev_ctx->AttachContext(a))
		return false;
	
	// Set init flag
	dword sdl_flag = SDL_INIT_AUDIO;
	ev_ctx->UserData().MapGetAdd("dependencies").MapGetAdd(a).MapSet("sdl_flag", (int64)sdl_flag);
	
	return true;
}

bool HalSdl2::AudioSinkDevice_PostInitialize(NativeAudioSinkDevice& dev, AtomBase& a) {
	AtomBaseRef dep = a.GetDependency();
	if (dep.IsEmpty()) {
		LOG("HalSdl2::AudioSinkDevice_PostInitialize: expected dependency atom but got null");
		return false;
	}
	
	if (!dep->IsRunning()) {
		LOG("HalSdl2::AudioSinkDevice_PostInitialize: context is not running");
	}
	
	RTLOG("HalSdl2::AudioSinkDevice_PostInitialize");
	
	SDL_AudioSpec audio_fmt;
	SDL_AudioSpec audio_desired;
	SDL_AudioDeviceID audio_dev;
	
	SDL_zero(audio_desired);
	audio_desired.freq = 44100;
	audio_desired.format = AUDIO_F32;
	audio_desired.channels = 2;
	audio_desired.samples = 1024;
	audio_desired.callback = StaticAudioOutputSinkCallback;
	audio_desired.userdata = &a;
	
	SDL_zero(audio_fmt);
	
	dev = SDL_OpenAudioDevice(NULL, 0, &audio_desired, &audio_fmt, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
	if (dev == 0) {
	    RTLOG("HalSdl2::AudioSinkDevice_PostInitialize: error: failed to open audio: " << SDL_GetError());
	    return false;
	}
	
    if (audio_fmt.format != audio_desired.format) {
		// we let this one thing change.
        RTLOG("HalSdl2::AudioSinkDevice_PostInitialize: warning: couldn't get desired audio format.");
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
    
    RTLOG("HalSdl2::AudioSinkDevice_PostInitialize: opened format: " << fmt.ToString());
    
    a.UpdateSinkFormat(ValCls::AUDIO, f);
    
	return true;
}

bool HalSdl2::AudioSinkDevice_Start(NativeAudioSinkDevice& dev, AtomBase& a) {
	
	return true;
}

void HalSdl2::AudioSinkDevice_Stop(NativeAudioSinkDevice& dev, AtomBase& a) {
	a.ClearDependency();
}

void HalSdl2::AudioSinkDevice_Uninitialize(NativeAudioSinkDevice& dev, AtomBase& a) {
	if (dev) {
		SDL_PauseAudioDevice(dev, 1);
		SDL_CloseAudioDevice(dev);
		dev = 0;
	}
}

bool HalSdl2::AudioSinkDevice_ProcessPacket(NativeAudioSinkDevice& dev, AtomBase& a, PacketValue& in, PacketValue& out) {
	return true;
}





bool HalSdl2::ContextBase_Initialize(NativeContextBase& ctx, AtomBase& a, const Script::WorldState& ws) {
	RTLOG("HalSdl2::ContextBase_Initialize");
	return true;
}

bool HalSdl2::ContextBase_PostInitialize(NativeContextBase& ctx, AtomBase& a) {
	RTLOG("HalSdl2::ContextBase_PostInitialize");
	
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

bool HalSdl2::ContextBase_Start(NativeContextBase& ctx, AtomBase& a) {
	return true;
}

void HalSdl2::ContextBase_Stop(NativeContextBase& ctx, AtomBase& a) {
	
}

void HalSdl2::ContextBase_Uninitialize(NativeContextBase& ctx, AtomBase& a) {
	RTLOG("HalSdl2::ContextBase_Uninitialize");
	SDL_Quit();
}

bool HalSdl2::ContextBase_ProcessPacket(NativeContextBase& ctx, AtomBase& a, PacketValue& in, PacketValue& out) {
	return true;
}

bool HalSdl2::ContextBase_AttachContext(NativeContextBase& ctx, AtomBase& a, AtomBase& other) {
	if (other.GetDependency()) {
		LOG("HalSdl2::ContextBase_AttachContext: atom already has dependency");
		return false;
	}
	other.SetDependency(a);
	return true;
}

void HalSdl2::ContextBase_DetachContext(NativeContextBase& ctx, AtomBase& a, AtomBase& other) {
	AtomBaseRef aref = a.AsRefT();
	if (other.GetDependency() == aref)
		other.SetDependency(AtomBaseRef());
}






bool HalSdl2::CenterVideoSinkDevice_Initialize(NativeVideoSink& dev, AtomBase& a, const Script::WorldState& ws) {
	auto ev_ctx = a.GetSpace()->template FindNearestAtomCast<Sdl2ContextBase>(1);
	ASSERT(ev_ctx);
	if (!ev_ctx) {RTLOG("error: could not find SDL2 context"); return false;}
	
	if (!ev_ctx->AttachContext(a))
		return false;
	
	String title = ws.GetString(".title", "SDL2 Window");
	Size sz = ws.GetSize(".cx", ".cy", Size(800,600));
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

bool HalSdl2::CenterVideoSinkDevice_PostInitialize(NativeVideoSink& dev, AtomBase& a) {
	AppFlags& app_flags = GetAppFlags();
	dev.win = 0;
	dev.rend = 0;
	
	HiValue& data = a.UserData();
	Size screen_sz(data["cx"], data["cy"]);
	bool is_fullscreen = data["fullscreen"];
	bool is_sizeable = data["sizeable"];
	bool is_maximized = data["maximized"];
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
	
	SDL_Texture* fb = SDL_CreateTexture(dev.rend, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, screen_sz.cx, screen_sz.cy);
	if (!fb) {
		LOG("error: couldn't create framebuffer texture");
		return false;
	}
	
	SDL_SetRenderTarget(dev.rend, fb);
	
	auto& rend_fb = dev.fb;
	rend_fb.Init(fb, screen_sz.cx, screen_sz.cy, fb_stride);
	rend_fb.SetWindowFbo();
	
	if (is_fullscreen)
		SDL_SetWindowFullscreen(dev.win, SDL_WINDOW_FULLSCREEN);
	
	return true;
}

bool HalSdl2::CenterVideoSinkDevice_Start(NativeVideoSink& dev, AtomBase& a) {
	
	return true;
}

void HalSdl2::CenterVideoSinkDevice_Stop(NativeVideoSink& dev, AtomBase& a) {
	a.ClearDependency();
}

void HalSdl2::CenterVideoSinkDevice_Uninitialize(NativeVideoSink& dev, AtomBase& a) {
	if (dev.rend) {
		SDL_DestroyRenderer(dev.rend);
		dev.rend = 0;
	}
	if (dev.win) {
		SDL_DestroyWindow(dev.win);
		dev.win = 0;
	}
}

bool HalSdl2::CenterVideoSinkDevice_ProcessPacket(NativeVideoSink& dev, AtomBase& a, PacketValue& in, PacketValue& out) {
	TODO
}




NAMESPACE_PARALLEL_END
#endif
