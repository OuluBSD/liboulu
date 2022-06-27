#include "EcsLocal.h"

NAMESPACE_ECS_BEGIN

void PlayerHandComponent::Initialize() {
	
}

void PlayerHandComponent::Uninitialize() {
	
}

bool PlayerHandComponent::IsSource(const ControllerSource& rhs) const {
	TODO
}

bool PlayerHandComponent::Arg(String key, Object value) {
	if (key == "hand") {
		if ((String)value == "left")
			req_hand = PlayerHandedness::Left;
		else if ((String)value == "right")
			req_hand = PlayerHandedness::Right;
		else
			return false;
	}
	else if (key == "body") {
		EntityStoreRef es = GetEngine().TryGet<EntityStore>();
		if (!es)
			return false;
		EntityRef e = es->FindEntity(value);
		if (e) {
			PlayerBodyComponentRef bc = e->Find<PlayerBodyComponent>();
			if (bc && bc->SetHand(req_hand, AsRefT())) {
				body = bc;
			}
		}
		else {
			LOG("PlayerHandComponent::Arg: could not find entity: " + (String)value);
			return false;
		}
	}
	return true;
}










void PlayerHeadComponent::Initialize() {
	
}

void PlayerHeadComponent::Uninitialize() {
	
}

bool PlayerHeadComponent::Arg(String key, Object value) {
	if (key == "body") {
		EntityStoreRef es = GetEngine().TryGet<EntityStore>();
		if (!es)
			return false;
		EntityRef e = es->FindEntity(value);
		if (e) {
			PlayerBodyComponentRef bc = e->Find<PlayerBodyComponent>();
			if (bc && bc->SetHead(AsRefT())) {
				body = bc;
			}
		}
		else {
			LOG("PlayerHeadComponent::Arg: could not find entity: " + (String)value);
			return false;
		}
	}
	return true;
}







void PlayerBodyComponent::Initialize() {
	Ref<PlayerBodySystem> sys = GetEngine().TryGet<PlayerBodySystem>();
	ASSERT(sys);
	if (sys) sys->Attach(AsRefT());
}

void PlayerBodyComponent::Uninitialize() {
	Ref<PlayerBodySystem> sys = GetEngine().TryGet<PlayerBodySystem>();
	ASSERT(sys);
	if (sys) sys->Detach(AsRefT());
}

bool PlayerBodyComponent::Arg(String key, Object value) {
	if (key == "height")
		height = StrDbl(value);
	
	return true;
}

bool PlayerBodyComponent::SetHand(PlayerHandedness hand, PlayerHandComponentRef comp) {
	if (hand == PlayerHandedness::Left) {
		if (hands[0])
			return false;
		hands[0] = comp;
	}
	else if (hand == PlayerHandedness::Right) {
		if (hands[1])
			return false;
		hands[1] = comp;
	}
	else return false;
	
	return true;
}

bool PlayerBodyComponent::SetHead(PlayerHeadComponentRef head) {
	if (this->head)
		return false;
	this->head = head;
	
	return true;
}






bool PlayerBodySystem::Initialize() {
	if (!InteractionListener::Initialize(GetEngine(), AsRefT<InteractionListener>()))
		return false;
	
	return true;
}

void PlayerBodySystem::Uninitialize() {
	InteractionListener::Uninitialize(GetEngine(), AsRefT<InteractionListener>());
	
}

void PlayerBodySystem::Start() {
	
}

void PlayerBodySystem::Update(double dt) {
	for (PlayerBodyComponentRef& b : bodies) {
		EntityRef e = b->GetEntity();
		TransformRef trans = e->Find<Transform>();
		if (!trans)
			continue;
		
		float eyes_from_height = 0.15; // guesstimate, that height of eyes is 15cm from your total height
		float hand_from_height = 0.4; // guesstimate
		
		vec3 body_feet_pos = trans->data.position;
		vec3 head_direction(0,0,1);
		vec3 head_pos(0,0,0);
		vec3 head_up(0,1,0);
		vec3 axes(0,0,0);
		
		if (b->head) {
			vec3 head_rel_pos(0, b->height - eyes_from_height, 0);
			head_pos = body_feet_pos + head_rel_pos;
			ASSERT(head_pos[1] > 0.0f);
			
			TransformRef head_trans = b->head->GetEntity()->Find<Transform>();
			if (head_trans) {
				TransformMatrix& t = head_trans->data;
				t.position = head_pos;
				axes = t.axes;
				head_up = t.up;
				head_direction = head_trans->GetForwardDirection();
				ASSERT(t.up.GetLength() > 0);
			}
		}
		
		for(int i = 0; i < 2; i++) {
			if (b->hands[i]) {
				TransformRef hand_trans = b->hands[i]->GetEntity()->Find<Transform>();
				if (hand_trans) {
					if (b->hands[i]->is_fake) {
						hand_trans->data.mode = TransformMatrix::MODE_AXES;
						hand_trans->data.axes = axes;
						float horz_deg = (i == 1 ? -1 : +1) * 30;
						camera_object(
							head_pos, head_direction, head_up,
							DEG2RAD(-horz_deg), DEG2RAD(-30), 0.3f,
							hand_trans->data.position);
					}
					else {
						float horz_deg = (i == 1 ? -1 : +1) * 30;
						camera_object(
							head_pos, head_direction, head_up,
							DEG2RAD(-horz_deg), DEG2RAD(-30), 0.3f,
							hand_trans->anchor_position);
					}
				}
			}
		}
		
	}
}

void PlayerBodySystem::Stop() {
	
}

void PlayerBodySystem::RefreshComponentsForSource(const HandLocationSource& source) {
	
	TODO
	
}

void PlayerBodySystem::Attach(PlayerBodyComponentRef h) {
	ArrayFindAdd(bodies, h);
}

void PlayerBodySystem::Detach(PlayerBodyComponentRef h) {
	ArrayRemoveKey(bodies, h);
}

void PlayerBodySystem::OnControllerDetected(const CtrlEvent& e) {
	// pass
}

void PlayerBodySystem::OnControllerLost(const CtrlEvent& e) {
	// pass
}

void PlayerBodySystem::OnControllerPressed(const CtrlEvent& e) {
	// pass
}

void PlayerBodySystem::OnControllerReleased(const CtrlEvent& e) {
	// pass
}

void PlayerBodySystem::OnControllerUpdated(const CtrlEvent& e) {
	if (e.type == EVENT_HOLO_LOOK) {
		for (PlayerBodyComponentRef& b : bodies) {
			if (b->head && e.trans) {
				TransformRef trans = b->head->GetEntity()->Find<Transform>();
				if (trans)
					trans->data = *e.trans;
				/*auto cam = b->head->GetEntity()->Find<CameraBase>();
				if (e.cam->mode == TransformMatrix::MODE_LOOKAT) {
					
				}
				else if (e.cam->mode == TransformMatrix::MODE_AXES) {
					trans->
				}
				else if (e.cam->mode == TransformMatrix::MODE_QUATERNION) {
					
				}
				else if (e.cam->mode == TransformMatrix::MODE_VIEW && e.cam->is_stereo) {
					if (cam) {
						cam->cam = e.cam;
					}
				}
				else TODO*/
					
				#if 0
				TransformRef trans = b->head->GetEntity()->Find<Transform>();
				if (trans) {
					if (!e.spatial->use_lookat) {
						trans->use_lookat = false;
						COPY4(trans->orientation, e.spatial->orient);
					}
					else {
						trans->use_lookat = true;
						COPY3(trans->direction, e.spatial->direction);
						trans->up = vec3(0,1,0);
					}
				}
				#endif
			}
		}
	}
	else if (e.type == EVENT_HOLO_MOVE_FAR_RELATIVE) {
		for (PlayerBodyComponentRef& b : bodies) {
			TransformRef trans = b->GetEntity()->Find<Transform>();
			if (trans) {
				TODO
				#if 0
				vec3 rel_pos;
				COPY3(rel_pos, e.spatial->position);
				trans->position += rel_pos;
				#endif
			}
		}
	}
	else if (e.type == EVENT_HOLO_MOVE_CONTROLLER) {
		PlayerBodyComponentRef vr_body;
		if (!bodies.IsEmpty()) vr_body = bodies[0];
		
		if (vr_body && e.ctrl) {
			const ControllerMatrix& cm = *e.ctrl;
			
			for(int i = 0; i < 2; i++) {
				if (vr_body->hands[i] && cm.ctrl[i].is_enabled) {
					PlayerHandComponent& hand = *vr_body->hands[i];
					const ControllerMatrix::Ctrl& ctrl = cm.ctrl[i];
					
					TransformRef trans = hand.GetEntity()->Find<Transform>();
					if (trans) {
						trans->data = ctrl.trans;
						trans->data.position += trans->anchor_position;
						//DUMP(trans->data.position); LOG(trans->data.GetAxesString());
					}
				}
			}
		}
	}
	else if (e.type == EVENT_HOLO_UPDATED) {
		
	}
	else TODO
}




NAMESPACE_ECS_END
