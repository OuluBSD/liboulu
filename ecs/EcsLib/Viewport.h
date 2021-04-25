#ifndef _System_Camera_h_
#define _System_Camera_h_

NAMESPACE_OULU_BEGIN


struct Viewport : public Component<Viewport> {
	vec3 target = zero<vec3>();
	
	void operator=(const Viewport& vp) {
		target = vp.target;
	}
	
};


NAMESPACE_OULU_END

#endif
