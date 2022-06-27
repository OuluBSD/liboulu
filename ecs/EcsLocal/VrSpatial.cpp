#include "EcsLocal.h"

NAMESPACE_ECS_BEGIN


/*bool VrControllerSource::GetLocation(float* matrix4x4) const {
	
}*/

void VrControllerSource::GetVelocity(float* v3) const {
	COPY3(v3, mgr->hand_velocity);
}

void VrControllerSource::GetAngularVelocity(float* v3) const {
	COPY3(v3, mgr->hand_angular_velocity);
}











VrSpatialInteractionManager::VrSpatialInteractionManager() {
	ctrl.mgr = this;
	ctrl_state.source = &ctrl;
	
	for(int i = 0; i < 3; i++) av[i].Resize(30);
	
}

bool VrSpatialInteractionManager::Initialize(InteractionSystem& sys) {
	this->sys = &sys;
	
	hand_velocity = vec3(0, 0.1, 0.1);
	hand_angular_velocity = vec3(0.1, 0.1, 0);
	
	prev.SetAll(false);
	
	return true;
}

void VrSpatialInteractionManager::Update(double dt) {
	time += dt;
	last_dt = dt;
	
	String env_name = sys->env_name;
	
	if (!env_name.IsEmpty()) {
		Serial::Machine& m = Serial::GetActiveMachine();
		Ref<LoopStore> ls = m.Find<LoopStore>();
		LoopRef l = ls->GetRoot();
		state = l->GetSpace()->FindStateDeep(env_name);
		if (!state) {
			LOG("InteractionSystem::Update: error: environment state with name '" << env_name << "' not found");
		}
		env_name.Clear();
		
		DetectController();
		//Look(Point(0,0)); // camera might be messed up, so update it immediately
	}
	
	if (state)
		UpdateState();

}

void VrSpatialInteractionManager::DetectController() {
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_CONTROLLER_DETECTED;
	
	WhenSourceDetected(*this, ev);
}

void VrSpatialInteractionManager::UpdateState() {
	ASSERT(state);
	
	if (sys->use_state_hmd) {
		UpdateStateHmd();
	}
	
}

void VrSpatialInteractionManager::UpdateStateHmd() {
	TransformMatrix& tm = state->Set<TransformMatrix>(HMD_CAMERA);
	Look(tm);
	
	ControllerMatrix& ctrl = state->Set<ControllerMatrix>(HMD_CONTROLLER);
	Control(ctrl);
	
}

void VrSpatialInteractionManager::Pressed(ControllerMatrix::Value b, float f) {
	ctrl_state.props.pressed[(int)b] = true;
	
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_PRESSED;
	ev.value = (int)b;
	
	WhenSourcePressed(*this, ev);
}

void VrSpatialInteractionManager::Released(ControllerMatrix::Value b, float f) {
	ctrl_state.props.pressed[(int)b] = false;
	
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_RELEASED;
	ev.value = (int)b;
	
	WhenSourceReleased(*this, ev);
}

void VrSpatialInteractionManager::Updated(ControllerMatrix::Value b, float f) {
	ctrl_state.props.pressed[(int)b] = false;
	
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_UPDATED;
	ev.value = (int)b;
	
	WhenSourceUpdated(*this, ev);
}








void VrSpatialInteractionManager::Look(const TransformMatrix& tm) {
	this->trans = tm;
	
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_LOOK;
	ev.pt = Point(0,0);
	ev.trans = &trans;
	
	if (sys->debug_log) {
		mat4 m = ToMat4(trans.orientation);
		vec4 dir = vec4(0,0,1,1) * m;
		direction_to_yaw_pitch(dir.Splice(), yaw, pitch);
		
		LOG("VrSpatialInteractionManager::Look: orientation: " << trans.orientation.ToString() <<
			", angle: " << yaw << ", angle1: " << pitch);
	}
	
	WhenSourceUpdated(*this, ev);
}

void VrSpatialInteractionManager::Control(const ControllerMatrix& ctrl) {
	
	if (0) {
		CtrlEvent ev;
		ev.state = &ctrl_state;
		ev.type = EVENT_HOLO_LOOK;
		ev.pt = Point(0,0);
		ev.ctrl = &this->cm;
		
		if (sys->debug_log) {
			mat4 m = ToMat4(trans.orientation);
			vec4 dir = vec4(0,0,1,1) * m;
			direction_to_yaw_pitch(dir.Splice(), yaw, pitch);
			
			LOG("VrSpatialInteractionManager::Look: orientation: " << trans.orientation.ToString() <<
				", angle: " << yaw << ", angle1: " << pitch);
		}
		
		WhenSourceUpdated(*this, ev);
	}
	
	if (1) {
		for(int i = 0; i < 2; i++) {
			const ControllerMatrix::Ctrl& prev = this->cm.ctrl[i];
			const ControllerMatrix::Ctrl& curr = ctrl.ctrl[i];
			
			if (!curr.is_enabled || !prev.is_enabled)
				continue;
			
			for(int j = 0; j < ControllerMatrix::VALUE_COUNT; j++) {
				bool changed = prev.value[j] != curr.value[j];
				if (!changed)
					continue;
				
				bool pushed   = curr.value[j] != 0 && prev.value[j] == 0;
				bool released = curr.value[j] == 0 && prev.value[j] != 0;
				
				if (pushed)
					Pressed((ControllerMatrix::Value)j, curr.value[j]);
				
				else if (released)
					Released((ControllerMatrix::Value)j, curr.value[j]);
				
				else
					Updated((ControllerMatrix::Value)j, curr.value[j]);
			}
			
		}
	}
	
	this->cm = ctrl;
	
	
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_MOVE_CONTROLLER;
	ev.ctrl = &this->cm;
	WhenSourceUpdated(*this, ev);
}

/*void VrSpatialInteractionManager::Look(quat orient) {
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_LOOK;
	ev.pt = Point(0,0);
	ev.spatial = &ev3d;
	
	ev3d.use_lookat = false;
	COPY4(ev3d.orient, orient.data);
	
	mat4 m = ToMat4(orient);
	vec4 dir = vec4(0,0,1,1) * m;
	direction_to_yaw_pitch(dir.Splice(), yaw, pitch);
	
	if (sys->debug_log) {
		LOG("VrSpatialInteractionManager::Look: orientation: " << orient.ToString() <<
			", angle: " << yaw << ", angle1: " << pitch);
	}
	
	WhenSourceUpdated(*this, ev);
}

void VrSpatialInteractionManager::Look(const StereoMatrix& st) {
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_LOOK;
	ev.pt = Point(0,0);
	ev.spatial = &ev3d;
	
	ev3d.use_view = true;
	COPY4x4(ev3d.l_proj, st.proj[0]);
	COPY4x4(ev3d.r_proj, st.proj[1]);
	COPY4x4(ev3d.l_view, st.view[0]);
	COPY4x4(ev3d.r_view, st.view[1]);
}*/

void VrSpatialInteractionManager::Move(vec3 rel_dir, float step) {
	CtrlEvent ev;
	ev.state = &ctrl_state;
	ev.type = EVENT_HOLO_MOVE_FAR_RELATIVE;
	TODO
	#if 0
	ev.spatial = &ev3d;
	vec3 dir = head_direction;
	
	// remove y component
	dir[1] = 0;
	
	float straight = rel_dir[2];
	float sideways = rel_dir[0];
	
	if (straight) {
		vec3 pos_diff = dir * step * straight;
		COPY3(ev3d.position, pos_diff);
	}
	if (sideways) {
		vec3 s = dir * step * sideways;
		vec3 pos_diff(-s[2], 0, +s[0]);
		COPY3(ev3d.position, pos_diff);
	}
	
	WhenSourceUpdated(*this, ev);
	#endif
}


NAMESPACE_ECS_END
