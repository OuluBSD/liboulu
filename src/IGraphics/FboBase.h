#ifndef _IGraphics_FboBase_h_
#define _IGraphics_FboBase_h_

NAMESPACE_PARALLEL_BEGIN


template <class Gfx>
struct FboAtomT :
	Atom
{
	using StateDraw = StateDrawT<Gfx>;
	using Framebuffer = FramebufferT<Gfx>;
	using DataState = DataStateT<Gfx>;
	using PipelineState = PipelineStateT<Gfx>;
	using ProgramState = ProgramStateT<Gfx>;
	
	Vector<BinderIfaceVideo*> binders;
	One<BinderIfaceVideo>	own_binder;
	String					target;
	EnvStateRef				state;
	int						prev_iter = -1;
	ValDevCls				src_type;
	One<ImageDraw>			id;
	StateDraw				accel_sd;
	Framebuffer				cpu_fb;
	bool					draw_mem = false;
	RealtimeSourceConfig*	last_cfg = 0;
	String					program;
	DataState				data;
	One<BinderIfaceVideo>	prog;
	
	static FboAtomT*	latest;
	
public:
	RTTI_DECL1(FboAtomT, Atom);
	FboAtomT();
	
	bool			Initialize(const Script::WorldState& ws) override;
	bool			PostInitialize() override;
	void			Uninitialize() override;
	bool			IsReady(PacketIO& io) override;
	bool			Send(RealtimeSourceConfig& cfg, PacketValue& out, int src_ch) override;
	void			Visit(RuntimeVisitor& vis) override {vis & state; vis % data; vis.VisitThis<Atom>(this);}
	void			Finalize(RealtimeSourceConfig& cfg) override;
	RealtimeSourceConfig* GetConfig() override {return last_cfg;}
	
	void AddBinder(BinderIfaceVideo* iface);
	void RemoveBinder(BinderIfaceVideo* iface);
	
	static Callback1<FboAtomT*>	WhenInitialize;
	static FboAtomT& Latest();
	
};


#if defined flagPOSIX
using X11SwFboBase = FboAtomT<X11SwGfx>;

#ifdef flagOGL
using X11OglFboBase = FboAtomT<X11OglGfx>;
#endif

#endif

#if defined flagOGL && defined flagSDL2
using SdlOglFboBase = FboAtomT<SdlOglGfx>;
#endif


NAMESPACE_PARALLEL_END

#endif
