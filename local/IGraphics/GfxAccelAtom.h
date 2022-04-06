#ifndef _IGraphics_GfxAccelAtom_h_
#define _IGraphics_GfxAccelAtom_h_

NAMESPACE_PARALLEL_BEGIN


template <class Gfx>
class GfxAccelAtom {
	
protected:
	friend class Events;
	
	using Buffer			= typename Gfx::Buffer;
	using Renderer			= RendererT<Gfx>;
	using StateDraw			= StateDrawT<Gfx>;
	using ShaderPipeline	= typename Gfx::ShaderPipeline;
	using DataState			= DataStateT<Gfx>;
	using NatWin			= typename Gfx::NativeWindow;
	using NatRend			= typename Gfx::NativeRenderer;
	using NatFrameBuf		= typename Gfx::NativeFrameBuffer;
	using ValFormat			= typename Gfx::ValFormat;
	using RendererInfo		= typename Gfx::NativeRendererInfo;
	using GLContext			= typename Gfx::NativeGLContext;
	using Framebuffer = FramebufferT<Gfx>;
	
	Buffer*					buf = NULL;
    NatWin*					win = NULL;
    NatRend*				nat_rend = NULL;
	AtomBase*				ab = NULL;
	int						fb_stride;
    RendererInfo			rend_info;
    Rect					desired_rect;
	Size					screen_sz;
	String					title;
	GLContext				glcontext = NULL;
	Renderer				rend;
	StateDraw				draw;
	SystemDraw				sysdraw;
	bool is_opengl = false;
	bool is_sw = false;
	bool is_dx11 = false;
	bool full_screen = false;
	bool is_maximized = false;
	bool is_sizeable = false;
	bool mouse_captured = false;
	bool is_user_shader = false;
	String frag_shdr;
	String vtx_shdr;
	String frag_path;
	String vtx_path;
	String library_paths;
	
	Packet fb_packet;
	
	// requires template specialization
	void GfxFlags(uint32& flags);
	bool GfxRenderer();
	
	
	void SetWindowRect(Rect r);
	
public:
	GfxAccelAtom() : ab(0) {desired_rect = RectC(0,0,1280,720);}
	
	void SetAtom(AtomBase* ab) {this->ab = ab;}
	
	bool Open();
	bool AcceptsOrder() const {return is_user_shader || frag_shdr.GetCount();}
	bool ImageInitialize();
	void Close();
	bool IsOpen() const;
	
	void Maximize(bool b=true);
	void Fullscreen(bool b=true);
	GfxAccelAtom& Sizeable(bool b=true) {is_sizeable = b; return *this;}
	void SetTitle(String title);
	void SetRect(Rect r);
	void Render(const RealtimeSourceConfig& cfg);
	bool Recv(int ch_i, const Packet& p);
	SystemDraw& BeginDraw();
	void CommitDraw();
	void FrameCopy(const ValFormat& vfmt, const byte* data, int len) {}
	
	void SetBuffer(Buffer& buf) {this->buf = &buf;}
	
	Size GetSize() {return Gfx::GetWindowSize(*win);}
	bool IsCaptured() const {return mouse_captured;}
	
	void SetShaderFile(String frag_path, String vtx_path, String library_paths) {this->frag_path = frag_path; this->vtx_path = vtx_path; this->library_paths = library_paths;}
	void SetFragmentShader(String s) {frag_shdr = s;}
	void SetVertexShader(String s) {vtx_shdr = s;}
	
};


NAMESPACE_PARALLEL_END

#endif