#ifndef _EcsLib_RenderingSystem_h_
#define _EcsLib_RenderingSystem_h_

NAMESPACE_OULU_BEGIN


class RenderingSystem : public System<RenderingSystem> {
	bool invalid;
	Size vscreen_sz;
	
	Ref<EntityStore> ents;
	Vector<DisplaySource*> screens;
	
	
public:
	RenderingSystem(Machine& m);
	
	void AddDisplaySource(DisplaySource& src);
	void RemoveRenderable(DisplaySource& src);
	
	void RunTest();
	
	Size GetVirtualScreenSize() const {ASSERT(vscreen_sz.cx > 0 && vscreen_sz.cy > 0); return vscreen_sz;}
	
protected:
	friend class Font;
	friend class CoreWindow;
	
    bool Initialize() override;
    void Start() override;
    void Update(double dt) override;
    void Stop() override;
    void Uninitialize() override;
    
    
};

template <class T> void AddDisplaySource(T& o) {
	Ref<RenderingSystem> sys = o.GetEntity().GetMachine().template Get<RenderingSystem>();
	if (sys)
		sys	-> AddDisplaySource(o);
}

template <class T> void RemoveRenderable(T& o) {
	Ref<RenderingSystem> sys = o.GetEntity().GetMachine().template Get<RenderingSystem>();
	if (sys)
		sys	-> RemoveRenderable(o);
}



#ifdef flagGUI

class DefaultRenderApp :
	public Component<DefaultRenderApp>,
	public DisplaySource,
	public CameraSource
{
	One<Shader> simple_shader;
	Ref<EntityStore> ents;
	
	VectorRendModel rends;
	
public:
	COPY_PANIC(DefaultRenderApp);
	IFACE_CB(DisplaySource);
	IFACE_CB(CameraSource);
	IFACE_GENERIC;
	
	DefaultRenderApp();
	
	void Initialize() override;
	bool Render(const DisplaySinkConfig& config, SystemDraw& draw) override;
	
};

#endif

NAMESPACE_OULU_END

#endif
