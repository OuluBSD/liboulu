#ifndef _EcsSDL2_System_h_
#define _EcsSDL2_System_h_

NAMESPACE_TOPSIDE_BEGIN



class SDL2System : public System<SDL2System> {
	LinkedList<SDL2ContextComponentRef> comps;
	
	TS::OOSDL2::Context ctx;
	OOSDL2::Image img;
	OOSDL2::Font fnt;
	
	
	void Visit(RuntimeVisitor& vis) override {vis && comps;}
	
public:
	SYS_RTTI(SDL2System)
	SYS_CTOR(SDL2System)
	
	const LinkedList<SDL2ContextComponentRef>& GetContext() const {return comps;}
	
protected:
	friend class Font;
	friend class CoreWindow;
	
    bool Initialize() override;
    void Start() override;
    void Update(double dt) override;
    void Stop() override;
    void Uninitialize() override;
    
protected:
	friend class SDL2ContextComponent;
	void AddContext(SDL2ContextComponentRef comp);
	void RemoveContext(SDL2ContextComponentRef comp);
	
};




NAMESPACE_TOPSIDE_END

#endif
