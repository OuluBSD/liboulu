#if 0
#ifndef _VirtualGui3D_CoreWindow_h_
#define _VirtualGui3D_CoreWindow_h_

#ifdef flagGUI

NAMESPACE_ECS_BEGIN


struct WindowsImg {
	static Image& close();
	static Image& maximize();
	static Image& minimize();
	static Image& nwse();
	static Image& nesw();
	static Image& ns();
	static Image& ew();
};

class Windows;

class WindowDecoration : public GeomInteraction2D {
	CoreWindow* win = NULL;
	String label;
	bool left_down;
	Point left_down_pt;
	
public:
	RTTI_DECL1(WindowDecoration, GeomInteraction2D)
	typedef WindowDecoration CLASSNAME;
	WindowDecoration(CoreWindow*);
	
	virtual void Paint(Draw& draw) override;
	
	void SetLabel(String str) {label = str;}
	
	String GetLabel() const {return label;}
	
	virtual void LeftDown(Point p, dword keyflags) override;
	virtual void LeftDouble(Point p, dword keyflags) override;
	virtual void LeftUp(Point p, dword keyflags) override;
	virtual void MouseMove(Point p, dword keyflags) override;
	virtual void RightDown(Point p, dword keyflags) override;
	
	void LocalMenu(Bar& bar);
	
	
};


struct CoreWindowLink;

class CoreWindow :
	public GeomInteraction2D,
	public AbsoluteWindow,
	public Component<CoreWindow>
{
	RTTI_COMP2(CoreWindow, GeomInteraction2D, AbsoluteWindow)
	
	#if 0
	struct ResizeFrame : public CtrlFrame {
		RTTI_DECL1(ResizeFrame, CtrlFrame)
	
		CoreWindow* win = NULL;
		Size sz;
		int frame_width = 8;
		int corner_width = 24;
		bool is_active = false;
		bool is_resizing = false;
		Point resize_start_pt;
		Rect resize_start_r;
		int resize_area = 0;
		Point resize_diff;
		bool used_momentum = false;
		
		enum {CENTER, TL, TR, BL, BR, TOP, BOTTOM, LEFT, RIGHT};
		int GetArea(Point pt);
		void SetActive(bool b) {frame_width = b ? 8 : 0;}
		virtual void FrameLayout(Rect& r) override;
		virtual void FramePaint(Draw& w, const Rect& r) override;
		virtual void FrameAddSize(Size& sz) override;
		virtual void MouseEnter(Point frame_p, dword keyflags) override;
		virtual void MouseMove(Point frame_p, dword keyflags) override;
		virtual void MouseLeave() override;
		virtual void LeftDown(Point p, dword keyflags) override;
		virtual void LeftUp(Point p, dword keyflags) override;
		virtual void ContinueGlobalMouseMomentum() override;
		void DoResize();
	};
	#endif
	
	//One<AbsoluteWindowInterface> owned_aw;
	//AbsoluteWindowInterface* aw = 0;
	void (CoreWindow::*reset_fn)() = 0;
	Windows* wins = NULL;
	CoreWindowLink* linked = NULL;
	
	//ResizeFrame resize_frame;
	WindowDecoration decor;
	Button minimize, maximize, close;
	Rect stored_rect;
	int id = -1;
	bool pending_partial_redraw = false;
	
protected:
	friend class Windows;
	friend class SDL2;
	
	bool maximized;
	
	void SetContent(Windows* wins, int id);
	void SetMaximized(bool b=true);
	
	
public:
	TransformRef    transform;
	Transform2DRef  transform2d;
	
public:
	typedef CoreWindow CLASSNAME;
	CoreWindow();
	CoreWindow(const CoreWindow& cw) : stored_rect(0,0,0,0), decor(this) {*this = cw;}
	
	void operator=(const CoreWindow& cw);
	
	#if 0
	template <class T>
	void ResetTopWindow() {
		Clear();
		T* t = new T();
		aw = static_cast<AbsoluteWindowInterface*>(t);
	}
	template <class T>
	T& Create() {
		Clear();
		T* t = new T();
		owned_aw = static_cast<AbsoluteWindowInterface*>(t);
		aw = &*owned_aw;
		reset_fn = &CoreWindow::ResetTopWindow<T>;
		return *t;
	}
	#endif
	
	void Clear();
	//void DeepLayout();
	Point GetGlobalMouse();
	//bool IsGlobalMouseOverridden() const {return pending_partial_redraw;}
	//void SetGlobalMouse(Point pt) {is_global_mouse_override = true; global_mouse = pt;}
	void Title(String label);
	void StoreRect();
	void LoadRect();
	void SetStoredRect(Rect r);
	void SetPendingPartialRedraw() override;
	
	//GLuint GetTexture() {return fb.GetTexture();}
	//const Framebuffer& GetFramebuffer() const {return fb;}
	int GetId() const;
	Rect GetStoredRect() const;
	AbsoluteWindowInterface* GetAbsoluteWindow();
	bool IsMaximized() const;
	bool IsActive() const;
	void MoveWindow(Point pt);
	void Maximize();
	void Restore();
	void Minimize();
	void Close();
	void FocusEvent() override;
	void ToggleMaximized();
	bool IsPendingPartialRedraw() const;
	void Wait();
	Windows* GetWindows() const {return wins;}
	TopWindow* GetTopWindow() const;
	
	String GetTitle() const override;
	void Layout() override;
	void Uninitialize() override;
	bool IsGeomDrawBegin() override;
	void SetFrameRect(const Rect& r) override;
	bool Redraw(bool only_pending) override;
	void LeftDown(Point p, dword keyflags) override;
	void ChildGotFocus() override;
	void Paint(Draw& id) override;
	
	COMP_DEF_VISIT
	
	virtual void ChildMouseEvent(Ctrl *child, int event, Point p, int zdelta, dword keyflags);
};

using CoreWindowRef = Ref<CoreWindow>;


struct CoreWindowLink : public Component<CoreWindowLink> {
	RTTI_COMP1(CoreWindowLink, ComponentT)
	COPY_PANIC(CoreWindowLink)
	COMP_DEF_VISIT
	
	
	CoreWindow* linked = 0;
	
	
	void Initialize() override;
	void Uninitialize() override;
	
	void Link(CoreWindow* cw);
	void Unlink(CoreWindow* cw);
	void Unlink();
	CoreWindow& GetWindow() const;
	
};

using CoreWindowLinkRef = Ref<CoreWindowLink>;


struct Window2D :
	EntityPrefab<
		CoreWindow,
		Transform2D,
		DefaultGuiAppComponent
	> {
    static Components Make(Entity& e)
    {
        auto components = EntityPrefab::Make(e);
		
		components.Get<CoreWindowRef>()->transform2d = components.Get<Transform2DRef>();
		
		components.Get<Transform2DRef>()->position = vec2(0, 1);
		components.Get<Transform2DRef>()->size = vec2(320, 240);
		
        return components;
    }
};


// Window3D needs to be linked to Window2D
struct Window3D :
	EntityPrefab<
		CoreWindowLink,
		Transform,
		ModelComponent
	> {
    static Components Make(Entity& e)
    {
        auto components = EntityPrefab::Make(e);
		
		CoreWindowLinkRef win = components.Get<CoreWindowLinkRef>();
		
		#if 0
		ModelComponentRef mdl = components.Get<ModelComponentRef>();
		mdl->Arg("builtin", "box");
		#endif
		
		TransformRef trans = components.Get<TransformRef>();
		trans->data.position = vec3(0, 2, 0);
		
        return components;
    }
};


NAMESPACE_ECS_END

#endif
#endif
#endif
