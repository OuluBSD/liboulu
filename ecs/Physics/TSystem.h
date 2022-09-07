#ifndef _Physics_TSystem_h_
#define _Physics_TSystem_h_

NAMESPACE_ECS_BEGIN


template <class Fys>
struct SystemT :
	SpaceT<Fys>,
	System<SystemT<Fys>>
{
	using Node = NodeT<Fys>;
	using Space = SpaceT<Fys>;
	using EcsSystem = System<SystemT<Fys>>;
	using NativeWorld = typename Fys::NativeWorld;
	using NativeSpace = typename Fys::NativeSpace;
	
protected:
	NativeWorld world = NULL;
	NativeJointGroup contactgroup = NULL;
	NativeThreading threading = NULL;
	NativeThreadPool pool = NULL;
	
	
public:
	RTTI_DECL2(SystemT, Space, EcsSystem)
	using Parent = Engine;
	
	static vec3 EarthGravity;
	
	ECS_SYS_CTOR_(OdeSystem) {
		Fys::InitializeLibrary();
		Fys::CreateWorld(world);
		
		SetRoot();
		OnAttach();
		
		Fys::CreateJointGroup(contactgroup);
		
		SetGravity(EarthGravity[1]);
		SetIterationCount(64);
		
		Fys::CreateThreading(threading);
		Fys::CreateThreadPool(pool);
		Fys::AttachThreadPool(threading, pool);
		Fys::AttachThreading(world, threading);
	}
	SYS_DEF_VISIT
	
	~OdeSystem() {
		Sys::DetachThreading(threading);
		Fys::ClearThreadPool(pool);
		Fys::DetachThreading(world);
		Fys::ClearThreading(threading);
		
		Fys::DetachJointGroup(contactgroup);
		Fys::ClearJointGroup(contactgroup);
		Fys::ClearSpace(space);
		Fys::ClearWorld(world);
		Fys::UninitializeLibrary();
	}
	
    bool Initialize() override {
		SetGravity(-0.5);
		return true;
	}
    void Start() override {}
    void Update(double dt) override {
		Collide();
		StepWorld(dt);
		RemoveContactJoints();
	}
    void Stop() override {}
    void Uninitialize() override {}
    
	void SetGravity(float f) {Fys::SetGravity(world, f);}
	void SetCFM(float f) {Fys::SetWorldCFM(world, f);}
	void SetConstraintForceMixing(float f) {Fys::SetWorldCFM(world, f);}
	void SetContactMaxCorrectingVel(float f) {Fys::SetMaxCorrectingVelocity(world, f);}
	void SetContactSurfaceLayer(float f) {Fys::SetContactSurfaceLayer(world, f);}
	void SetAutoDisableFlag(bool b) {Fys::SetAutoDisable(world, b);}
	void SetIterationCount(int i) {Fys::SetStepIterations(world, i);}
	void SetAutoDisableAverageSamplesCount(int i) {Fys::SetAutoDisableSamples(world, i);}
	
	dWorldID GetWorldId() const {ASSERT(world); return world;}
	dJointGroupID GetJointGroupId() const {ASSERT(contactgroup); return contactgroup;}
	
	void Collide() {ASSERT(space); Sys::Collide(space, this, &OdeSystem::StaticNearCallback);}
	void StepWorld(double seconds) {Fys::Step(world, seconds);}
	void RemoveContactJoints() {Fys::DetachJointGroup(contactgroup);}
	
	virtual void NearCallback(void *, NativeGeom& o1, NativeGeom& o2);
	static void StaticNearCallback(void *data, NativeGeom& o1, NativeGeom& o2) {((SystemT*)data)->NearCallback(NULL, o1, o2);}
	
};


NAMESPACE_ECS_END

#endif
