#pragma once

#ifdef flagVR

NAMESPACE_ECS_BEGIN

class ToolSystemBase;

class ToolComponent : public Component<ToolComponent> {
	
public:
	RTTI_COMP0(ToolComponent)
	COPY_PANIC(ToolComponent)
	COMP_DEF_VISIT
	COMP_DEF_MAKE_ACTION
	
	String title;
	String description;
	TypeId tool_type { AsVoidTypeId() };
	
};


// ToolboxSystem
// This system manages the ToolSystems and manages the two Entities that represent the left and right Motion Controllers
class ToolboxSystem :
	public System<ToolboxSystem>,
	public ISpatialInteractionListener {
	LinkedList<EntityRef> entities;
	
public:
	void Visit(RuntimeVisitor& vis) override {TODO}
	SYS_RTTI(ToolboxSystem)
	SYS_CTOR(ToolboxSystem);
	
	using Parent = Machine;
	
	
	void AddToolSystem(ToolSystemBaseRef system);
	void RemoveToolSystem(ToolSystemBaseRef system);
	
protected:
	// System
	void Start() override;
	void Update(double dt) override;
	void Stop() override;
	void Uninitialize() override;
	
	// ISpatialInteractionListener
	void OnSourcePressed(const SpatialInteractionSourceEventArgs& args) override;
	
private:
	TypeMap<ToolSystemBaseRef> selectors;
	TypeMap<EntityRef> selector_objects;
	
	bool show_toolbox{ false };
	
	enum ControllerHand {
		Left, Right, Count
	};
	
	static String ControllerHandToString(ControllerHand hand);
	static SpatialInteractionSourceHandedness ControllerHandToHandedness(ControllerHand hand);
	
	struct ControllerContext {
		EntityRef ctrl;
		EntityRef dbg_txt;
		ControllerHand hand;
	};
	
	void SwitchToolType(EntityRef entity, const TypeId& new_type);
	
	EntityRef FindController(const SpatialInteractionSource& source);
	
	FixedArray<ControllerContext, ControllerHand::Count> ctrls;
	
	EntityRef instruction_text;
	
	
};

NAMESPACE_ECS_END

#endif
