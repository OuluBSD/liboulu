#ifndef _EcsLib_RenderingSystem_h_
#define _EcsLib_RenderingSystem_h_

NAMESPACE_TOPSIDE_BEGIN


class RenderingSystem : public System<RenderingSystem> {
	Ref<EntityStore> ents;
	LinkedList<DisplaySourceRef> screens;
	
	bool invalid;
	Size vscreen_sz;
	
	
	void Visit(RuntimeVisitor& vis) override {
		vis & ents
			&& screens;
	}
public:
	RenderingSystem(Machine& m);
	
	void Add(DisplaySourceRef src);
	void Remove(DisplaySourceRef src);
	
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



#if 0
#ifdef flagGUI

class DefaultRenderApp :
	public Component<DefaultRenderApp>,
	public DisplaySource,
	public CameraSource
{
	One<Shader> simple_shader;
	EntityStoreRef ents;
	
	VectorRendModel rends;
	
public:
	VIS_COMP_2_0(Display, Camera)
	COPY_PANIC(DefaultRenderApp);
	IFACE_CB(DisplaySource);
	IFACE_CB(CameraSource);
	IFACE_GENERIC;
	
	DefaultRenderApp();
	
	void Initialize() override;
	bool Render(const DisplaySinkConfig& config, SystemDraw& draw) override;
	void Visit(RuntimeVisitor& vis) override {TODO vis & ents;}
	
};

#endif
#endif

NAMESPACE_TOPSIDE_END

#endif
