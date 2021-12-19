#ifndef _SoftRend_Framebuffer_h_
#define _SoftRend_Framebuffer_h_

NAMESPACE_TOPSIDE_BEGIN


/*class SoftBuffer : Moveable<SoftBuffer> {
	bool inited = false;
	
public:
	Texture tex;
	
public:
	typedef SoftBuffer CLASSNAME;
	
	
	
	void Clear() {inited = false;}
	bool Create() {ASSERT(!inited); inited = true; return true;}
	void operator=(const Nuller&) {Clear();}
	operator bool() const {return inited;}
};*/

class SoftFramebuffer {
	bool inited = false;
	
protected:
	friend class SoftRend;
	SDL_Texture* tex = 0;
	Texture* gtex = 0;
	
	GVar::Wrap wrap[GVar::TEXTYPE_COUNT] {GVar::WRAP_REPEAT, GVar::WRAP_REPEAT};
	GVar::Filter filter[GVar::TEXTYPE_COUNT] {GVar::FILTER_NEAREST, GVar::FILTER_NEAREST, GVar::FILTER_NEAREST};
public:
	typedef SoftFramebuffer CLASSNAME;
	SoftFramebuffer();
	
	void Clear();
	bool Create();
	void ClearData(GVar::BufferType type);
	void ClearDataAll();
	
	void SetParam(GVar::TextureType type, GVar::Filter filter, GVar::Wrap repeat);
	
	SDL_Texture* GetTex() const {ASSERT(tex); return tex;}
	Texture& GetGeomTex() const {ASSERT(gtex); return *gtex;}
	
	void operator=(SDL_Texture* tex);
	void operator=(Texture* t) {ASSERT(tex == 0); gtex = t;}
	void operator=(const Nuller&) {Clear();}
	operator bool() const {return inited;}
	
};


NAMESPACE_TOPSIDE_END

#endif
