#include "Geometry.h"

NAMESPACE_TOPSIDE_BEGIN

quat quat::GetConjugate() const {
	// https://mathworld.wolfram.com/QuaternionConjugate.html
	quat q;
	q.data[0] = q.data[0];
	q.data[1] = -q.data[1];
	q.data[2] = -q.data[2];
	q.data[3] = -q.data[3];
	return q;
}

quat quat::operator-() const {
	quat q = *this;
	for (int i = 0; i < 4; i++)
		q.data.data[i] *= -1;
	return q;
}

quat quat::operator+(const quat& q) const {
	quat r = *this;
	for (int i = 0; i < 4; i++)
		r.data.data[i] += q.data.data[i];
	return r;
}

quat quat::operator*(const quat& b) const {
	// https://stackoverflow.com/questions/19956555/how-to-multiply-two-quaternions
	const quat& a = *this;
	return quat (
		a[3] * b[3] - a[0] * b[0] - a[1] * b[1] - a[2] * b[2],
	    a[3] * b[0] + a[0] * b[3] + a[1] * b[2] - a[2] * b[1],
	    a[3] * b[1] - a[0] * b[2] + a[1] * b[3] + a[2] * b[0],
	    a[3] * b[2] + a[0] * b[1] - a[1] * b[0] + a[2] * b[3]
	);
}

quat quat::operator*(float f) const {
	quat q = *this;
	for (int i = 0; i < 4; i++)
		q.data.data[i] *= f;
	return q;
}

quat quat::operator/(float f) const {
	quat q = *this;
	for (int i = 0; i < 4; i++)
		q.data.data[i] /= f;
	return q;
}

float quat::GetDotProduct(const quat& q) const {
	return data.GetDotProduct(q.data);
}

quat quat::Mix(const quat& q, float f) const {
	quat r;
	r.data = data.Mix(q.data, f);
	return r;
}







void TransformMatrix::Clear() {
	mode = MODE_POSITION;
	is_stereo = false;
	position = vec3(0,0,0);
	direction = vec3(0,0,0);
	up = vec3(0,1,0);
	axes = vec3(0,0,0);
	orientation = quat(0,0,0,0);
	float eye_dist = 0;
}

void TransformMatrix::operator=(const TransformMatrix& m) {
	mode = m.mode;
	is_stereo = m.is_stereo;
	position = m.position;
	direction = m.direction;
	up = m.up;
	axes = m.axes;
	orientation = m.orientation;
	eye_dist = m.eye_dist;
	/*proj[0] = m.proj[0];
	proj[1] = m.proj[1];
	view[0] = m.view[0];
	view[1] = m.view[1];*/
}

vec3 TransformMatrix::GetForwardDirection() const {
	if (mode == MODE_POSITION)
		return vec3(0,0,1);
	
	if (mode == MODE_LOOKAT) {
		return direction;
	}
	if (mode == MODE_AXES) {
		//mat4 yaw = YRotation(axes[0]);
		//mat4 rotate = make_mat4_from_yaw_pitch_roll(M_PI, axes[1], axes[2]);
		mat4 rotate = make_mat4_from_yaw_pitch_roll(axes[0], axes[1], axes[2]);
		vec4 fwd(0,0,1,1);
		//vec4 dir = rotate * yaw * fwd;
		vec4 dir = rotate * fwd;
		return dir.Splice();
	}
	if (mode == MODE_QUATERNION) {
		mat4 m = QuatMat(orientation);
		vec4 fwd(0,0,1,1);
		vec4 dir = m * fwd;
		return dir.Splice();
	}
	TODO
	return vec3(0,0,1);
}

void TransformMatrix::FillFromOrientation() {
	decompose_quat(orientation, axes[0], axes[1], axes[2]);
	direction = yaw_pitch_to_direction(axes[0], axes[1]);
	up = vec3(0,1,0);
}

String TransformMatrix::GetAxesString() const {
	String s;
	s << "yaw: " << axes[0] << ", "
		 "pitch: " << axes[1] << ", "
		 "roll: " << axes[2];
	return s;
}










String CalibrationData::ToString() const {
	String s;
	s << " axes(" << axes[0] << ", " << axes[1] << ", " << axes[2] << "), "
		 " position(" << position[0] << ", " << position[1] << ", " << position[2] << "), "
		 " fov(" << fov << "), scale(" << scale << "), eye_dist(" << eye_dist << ")";
	return s;
}

void CalibrationData::Dump() {
	DUMP(*this);
}





NAMESPACE_TOPSIDE_END
