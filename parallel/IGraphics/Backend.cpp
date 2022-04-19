#include "IGraphics.h"

NAMESPACE_PARALLEL_BEGIN


bool X11SwGfx::LockTextureToSurface(NativeTexture& tex, Rect r, NativeSurface& surf) {
	surf = tex;
	return true;
}

void X11SwGfx::QueryTexture(NativeTexture& tex, uint32& fmt, int& access, int& w, int& h) {
	fmt = 0;
	access = 0;
	w = tex->GetWidth();
	h = tex->GetHeight();
}


#ifdef flagSDL2
bool SdlCpuGfx::LockTextureToSurface(NativeTexture& tex, Rect r, NativeSurface& surf) {
	SDL_Rect re {
		r.left,
		r.top,
		r.GetWidth(),
		r.GetHeight()
	};
	return SDL_LockTextureToSurface(tex, &re, &surf) >= 0;
}

void SdlCpuGfx::QueryTexture(NativeTexture& tex, uint32& fmt, int& access, int& w, int& h) {
	SDL_QueryTexture(tex, &fmt, &access, &w, &h);
}

void SdlCpuGfx::UnlockTextureToSurface(NativeTexture& tex) {
	SDL_UnlockTexture(tex);
}
#endif


NAMESPACE_PARALLEL_END
