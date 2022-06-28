#include "Geometry.h"

NAMESPACE_TOPSIDE_BEGIN


vec3 lerp(const vec3& pos, const vec3& tgt_pos, float easing_factor) {
	ASSERT(easing_factor >= 0.f && easing_factor <= 1.f);
	return pos * (1.0f - easing_factor) + (tgt_pos * easing_factor);
}

quat slerp(const quat& orient, const quat& tgt_orient, float easing_factor) {
	quat z = tgt_orient;
	float cos_theta = dot(orient, tgt_orient);
	
	if (cos_theta < 0.0f) {
		z = -tgt_orient;
		cos_theta = -cos_theta;
	}

	if (cos_theta > 1.0f - std::numeric_limits<float>::epsilon()) {
		return mix(orient, z, easing_factor);
	}
	else {
		float angle = acos(cos_theta);
		return (
			orient * sin((1.0f - easing_factor) * angle) +
			z * sin(easing_factor * angle)) / sin(angle);
	}
}



mat4 LookAt(const vec3& eye, const vec3& center, const vec3& up) {
    #if 0
	vec3 f = (center - eye);
	vec3 u = up;
	f.Normalize();
	u.Normalize();
	vec3 s = cross(f, u);
	s.Normalize();
	u = cross(s, f);
	
	mat4 minv;
	minv[0][0] = s[0];
	minv[1][0] = s[1];
	minv[2][0] = s[2];
	minv[3][0] = 0;
	minv[0][1] = u[0];
	minv[1][1] = u[1];
	minv[2][1] = u[2];
	minv[3][1] = 0;
	minv[0][2] = -f[0];
	minv[1][2] = -f[1];
	minv[2][2] = -f[2];
	minv[3][2] = 0;
	minv[0][3] = 0;
	minv[1][3] = 0;
	minv[2][3] = 0;
	minv[3][3] = 1;
	
	mat4 t;
	t.SetTranslate(-eye[0], -eye[1], -eye[2]);
	mat4 res = minv * t;
	return res;
	#else
    mat4 minv = zero<mat4>();
	vec3 z = normalize(eye - center);
    vec3 x = normalize(cross(up, z));
    vec3 y = cross(z,x);
    for (int i=0; i<3; i++) {
        minv[i][0] = x[i];
        minv[i][1] = y[i];
        minv[i][2] = z[i];
    }
    minv[3][0] = -dot(x, eye);
    minv[3][1] = -dot(y, eye);
    minv[3][2] = -dot(z, eye);
    minv[3][3] = 1.0f;
    return minv;
    #endif
}

mat4 GetViewport(const ViewportParams& vp) {
	return GetViewport(vp.x, vp.y, vp.w, vp.h, vp.max_depth);
}

mat4 GetViewport(float x, float y, float w, float h, float depth) {
	#if 1
	mat4 m = zero<mat4>();
	m[0][3] = x + w / 2.f;
	m[1][3] = y + h / 2.f;
	m[2][3] = depth / 2.f;

	m[0][0] = w / 2.f;
	m[1][1] = h / 2.f;
	m[2][2] = depth / 2.f;
	m[3][3] = 1.0f;
	
	return m;
	#else
	mat4 m = zero<mat4>();
	
	m.SetComponentTranslate(
		x + w / 2.f,
		y + h / 2.f,
		depth / 2.f);
	
	m.SetComponentScale(
		w / 2.f;
		h / 2.f;
		depth / 2.f);
	
	m.Transpose();
	#endif
	return m;
}

void ColorCopy(const RGBA& src, vec3& dst) {
	dst[0] = src.r / 255.0f;
	dst[1] = src.g / 255.0f;
	dst[2] = src.b / 255.0f;
}

void ColorCopy(const RGBA& src, vec4& dst) {
	dst[0] = src.r / 255.0f;
	dst[1] = src.g / 255.0f;
	dst[2] = src.b / 255.0f;
	dst[3] = src.a / 255.0f;
}


Size ToSize(const vec2& v) {return Size((int)v[0], (int)v[1]);}
Point ToPoint(const vec2& v) {return Point((int)v[0], (int)v[1]);}
vec3 MakeVec3(float v[4]) {vec3 o; for(int i = 0; i < 3; i++) o[i] = v[i]; return o;}
vec3 MakeVec3(double v[4]) {vec3 o; for(int i = 0; i < 3; i++) o[i] = (float)v[i]; return o;}
vec4 MakeVec4(const vec3& v, float v4) {vec4 o; for(int i = 0; i < 3; i++) o[i] = v[i]; o[3] = v4; return o;}

double GetRadians(double degrees) {return degrees / 360.0 * M_2PI;}
double GetDegrees(double radians) {return radians / M_2PI * 360.0;}


mat4 perspective(float half_fov_rad, float aspect, float near, float far) {
	mat4 m;
	m.SetPerspective(half_fov_rad, aspect, near, far);
	return m;
}

mat4 ortho(float left, float right, float bottom, float top, float near, float far) {
	mat4 m;
	m.SetOrtographic(left, right, bottom, top, near, far);
	return m;
}

mat4 ToMat4(const quat& q) {
	mat4 result;
	result.SetIdentity();
	
	double qxx = q[0] * q[0];
	double qyy = q[1] * q[1];
	double qzz = q[2] * q[2];
	double qxz = q[0] * q[2];
	double qxy = q[0] * q[1];
	double qyz = q[1] * q[2];
	double qwx = q[3] * q[0];
	double qwy = q[3] * q[1];
	double qwz = q[3] * q[2];

	result[0][0] = 1.0 - 2.0 * (qyy +  qzz);
	result[0][1] = 2.0       * (qxy + qwz);
	result[0][2] = 2.0       * (qxz - qwy);

	result[1][0] = 2.0       * (qxy - qwz);
	result[1][1] = 1.0 - 2.0 * (qxx +  qzz);
	result[1][2] = 2.0       * (qyz + qwx);

	result[2][0] = 2.0       * (qxz + qwy);
	result[2][1] = 2.0       * (qyz - qwx);
	result[2][2] = 1.0 - 2.0 * (qxx +  qyy);
	
	for(int i = 0; i < 3; i++) {
		result[3][i] = 0;
		result[i][3] = 0;
	}
	result[3][3] = 1;
	
	return result;
}



bool Decompose(const mat4& model_mat, vec3& scale_, quat& orientation, vec3& translation, vec3& skew, vec4& perspective) {
	mat4 local_mat(model_mat);

	if(IsEpsilonEqual(local_mat[3][3], 0.0f, EPSILONf))
		return false;

	for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            local_mat[i][j] /= local_mat[3][3];

	mat4 persp_mat(local_mat);

	for(int i = 0; i < 3; i++)
		persp_mat[i][3] = 0.0f;
	persp_mat[3][3] = 1.0f;

	if(IsEpsilonEqual(persp_mat.GetDeterminant(), 0.0f, EPSILONf))
		return false;

	if( IsEpsilonNotEqual(local_mat[0][3], 0.0f, EPSILONf) ||
		IsEpsilonNotEqual(local_mat[1][3], 0.0f, EPSILONf) ||
		IsEpsilonNotEqual(local_mat[2][3], 0.0f, EPSILONf)) {
		vec4 right_hand_side;
		right_hand_side[0] = local_mat[0][3];
		right_hand_side[1] = local_mat[1][3];
		right_hand_side[2] = local_mat[2][3];
		right_hand_side[3] = local_mat[3][3];

		mat4 inv_persp_mat = persp_mat.GetInverse();
		mat4 trans_inv_persp_mat = inv_persp_mat.GetTransposed();

		perspective = trans_inv_persp_mat * right_hand_side;

		local_mat[0][3] = local_mat[1][3] = local_mat[2][3] = 0.0f;
		local_mat[3][3] = 1.0f;
	}
	else {
		perspective = vec4(0, 0, 0, 1);
	}

	translation = local_mat[3].Splice();
	local_mat[3] = vec4(0, 0, 0, local_mat[3][3]);

	vec3 row[3], p_dum3;

	for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            row[i][j] = local_mat[i][j];

	scale_[0] = row[0].GetLength();

	row[0] = scale(row[0], 1.0f);

	skew[2] = dot(row[0], row[1]);
	row[1] = combine(row[1], row[0], 1.0f, -skew[2]);

	scale_[1] = row[1].GetLength();
	row[1] = scale(row[1], 1.0f);
	skew[2] /= scale_[1];

	skew[1] = dot(row[0], row[2]);
	row[2] = combine(row[2], row[0], 1.0f, -skew[1]);
	skew[0] = dot(row[1], row[2]);
	row[2] = combine(row[2], row[1], 1.0f, -skew[0]);

	scale_[2] = row[2].GetLength();
	row[2] = scale(row[2], 1.0f);
	skew[1] /= scale_[2];
	skew[0] /= scale_[2];

	p_dum3 = cross(row[1], row[2]);
	if (dot(row[0], p_dum3) < 0) {
		for(int i = 0; i < 3; i++)
		{
			scale_[i] *= -1.0f;
			row[i] *= -1.0f;
		}
	}

	int i, j, k = 0;
	float root, trace = row[0][0] + row[1][1] + row[2][2];
	if(trace > 0.0f)
	{
		root = sqrt(trace + 1.0f);
		orientation[3] = 0.5f * root;
		root = 0.5f / root;
		orientation[0] = root * (row[1][2] - row[2][1]);
		orientation[1] = root * (row[2][0] - row[0][2]);
		orientation[2] = root * (row[0][1] - row[1][0]);
	}
	else {
		static int Next[3] = {1, 2, 0};
		i = 0;
		if(row[1][1] > row[0][0]) i = 1;
		if(row[2][2] > row[i][i]) i = 2;
		j = Next[i];
		k = Next[j];

		root = sqrt(row[i][i] - row[j][j] - row[k][k] + 1.0f);

		orientation[i] = 0.5f * root;
		root = 0.5f / root;
		orientation[j] = root * (row[i][j] + row[j][i]);
		orientation[k] = root * (row[i][k] + row[k][i]);
		orientation[3] = root * (row[j][k] - row[k][j]);
	}

	return true;
}

vec3 combine(const vec3& a, const vec3& b, float ascl, float bscl) {
	return (a * ascl) + (b * bscl);
}

mat4 GetEulerAngleYXZ(const vec3& in) {
	float yaw = in[2];
	float pitch = in[1];
	float roll = in[0];
	float ch = cos(yaw);
	float sh = sin(yaw);
	float cp = cos(pitch);
	float sp = sin(pitch);
	float cb = cos(roll);
	float sb = sin(roll);

	mat4 r;
	r[0][0] = ch * cb + sh * sp * sb;
	r[0][1] = sb * cp;
	r[0][2] = -sh * cb + ch * sp * sb;
	r[0][3] = 0;
	r[1][0] = -ch * sb + sh * sp * cb;
	r[1][1] = cb * cp;
	r[1][2] = sb * sh + ch * sp * cb;
	r[1][3] = 0;
	r[2][0] = sh * cp;
	r[2][1] = -sp;
	r[2][2] = ch * cp;
	r[2][3] = 0;
	r[3][0] = 0;
	r[3][1] = 0;
	r[3][2] = 0;
	r[3][3] = 1;
	return r;
}

mat4 GetEulerAngleYX(const vec3& in) {
	float angle_y = in[2];
	float angle_x = in[1];
	
	float cos_x = cos(angle_x);
	float sin_x = sin(angle_x);
	float cos_y = cos(angle_y);
	float sin_y = sin(angle_y);

	return mat4 {
		{cos_y,          0,            -sin_y,    0},
		{sin_y * sin_x,  cos_x, cos_y * sin_x,    0},
		{sin_y * cos_x, -sin_x, cos_y * cos_x,    0},
		{0,              0,             0,        1}};
	
}

mat4 rotate(mat4 const& m, float angle, vec3 const& v) {
	const float a = angle;
	const float c = cos(a);
	const float s = sin(a);
	
	vec3 axis(normalize(v));
	vec3 temp(axis * (1.0f - c));
	
	mat4 rot;
	rot[0][0] = c + temp[0] * axis[0];
	rot[0][1] = temp[0] * axis[1] + s * axis[2];
	rot[0][2] = temp[0] * axis[2] - s * axis[1];
	
	rot[1][0] = temp[1] * axis[0] - s * axis[2];
	rot[1][1] = c + temp[1] * axis[1];
	rot[1][2] = temp[1] * axis[2] + s * axis[0];
	
	rot[2][0] = temp[2] * axis[0] + s * axis[1];
	rot[2][1] = temp[2] * axis[1] - s * axis[0];
	rot[2][2] = c + temp[2] * axis[2];
	
	mat4 res;
	res[0] = m[0] * rot[0][0] + m[1] * rot[0][1] + m[2] * rot[0][2];
	res[1] = m[0] * rot[1][0] + m[1] * rot[1][1] + m[2] * rot[1][2];
	res[2] = m[0] * rot[2][0] + m[1] * rot[2][1] + m[2] * rot[2][2];
	res[3] = m[3];
	return res;
}

quat make_quat_from_axis_angle(const vec3& v, float angle) {
	double s = sinf(angle * 0.5);
	quat r;
	r[0] = v[0] * s;
	r[1] = v[1] * s;
	r[2] = v[2] * s;
	r[3] = cosf(angle * 0.5);
	return r;
}

vec3 transform(const vec3& v, const quat& q) {
	// https://gamedev.stackexchange.com/questions/28395/rotating-vector3-by-a-quaternion
	
	// Extract the vector part of the quaternion
    vec3 u = q.data.Splice();

    // Extract the scalar part of the quaternion
    float s = q.data[3];

    // Do the math
    vec3 vprime = u * (2.0f * dot(u, v))
          + v * ((s*s - dot(u, u)))
          + cross(u, v) * (2.0f * s);
    return vprime;
}

mat4 make_mat4_from_quat(const quat& q) {
	mat4 m1{
		{q[3], q[2], -q[1], q[0]},
		{-q[2], q[3], q[0], q[1]},
		{q[1], -q[0], q[3], q[2]},
		{-q[0], -q[1], -q[2], q[3]}
	};
	
	mat4 m2{
		{q[3], q[2], -q[1], -q[0]},
		{-q[2], q[3], q[0], -q[1]},
		{q[1], -q[0], q[3], -q[2]},
		{q[0], q[1], q[2], q[3]}
	};
	
	return m2 * m1;
}

quat make_quat_from_yaw_pitch_roll(float yaw, float pitch, float roll)
{
	//return MatrixUtils::orientation(YawPitchRoll(yaw, pitch, roll));
    float sr, cr, sp, cp, sy, cy;

    float half_roll = roll * 0.5f;
    sr = sinf(half_roll);
    cr = cosf(half_roll);

    float half_pitch = pitch * 0.5f;
    sp = sinf(half_pitch);
    cp = cosf(half_pitch);

    float half_yaw = -yaw * 0.5f;
    sy = sinf(half_yaw);
    cy = cosf(half_yaw);

    return quat(
		cy * sp * cr + sy * cp * sr,
		sy * cp * cr - cy * sp * sr,
		cy * cp * sr - sy * sp * cr,
		cy * cp * cr + sy * sp * sr
	);
}

mat4 make_mat4_rotation_x(float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	
	return mat4{
		{1,  0, 0, 0},
		{0,  c, s, 0},
		{0, -s, c, 0},
		{0,  0, 0, 1}
	};
}

mat4 make_mat4_rotation_y(float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	return mat4{
		{c, 0, -s, 0},
		{0, 1,  0, 0},
		{s, 0,  c, 0},
		{0, 0,  0, 1}
	};
}

mat4 make_mat4_rotation_z(float angle) {
	float c = cosf(angle);
	float s = sinf(angle);
	return mat4{
		{c, s, 0, 0},
		{-s, c, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
}

mat4 make_mat4_translation(const vec3& position) {
    return mat4{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{position[0], position[1], position[2], 1}
	};
}

quat make_quat_from_rotation_matrix(const mat4& m) {
    if (m[1][1] + m[2][2] + m[3][3] > 0.0f)
    {
        float s = sqrtf(1.0f + m[1][1] + m[2][2] + m[3][3]);
        float inv_s = 0.5f / s;

        return quat((m[2][3] - m[3][2]) * inv_s,
                   (m[3][1] - m[1][3]) * inv_s,
                   (m[1][2] - m[2][1]) * inv_s,
                   s * 0.5f);
    }
    else if (m[1][1] >= m[2][2] && m[1][1] >= m[3][3])
    {
        float s = sqrtf(1.0f + m[1][1] - m[2][2] - m[3][3]);
        float inv_s = 0.5f / s;

        return quat(0.5f * s,
                    (m[1][2] + m[2][1]) * inv_s,
                    (m[1][3] + m[3][1]) * inv_s,
                    (m[2][3] - m[3][2]) * inv_s);
    }
    else if (m[2][2] > m[3][3])
    {
        float s = sqrtf(1.0f + m[2][2] - m[1][1] - m[3][3]);
        float inv_s = 0.5f / s;

        return quat((m[2][1] + m[1][2]) * inv_s,
                    0.5f * s,
                    (m[3][2] + m[2][3]) * inv_s,
                    (m[3][1] - m[1][3]) * inv_s);
    }
    else
    {
        float s = sqrtf(1.0f + m[3][3] - m[1][1] - m[2][2]);
        float inv_s = 0.5f / s;

        return quat((m[3][1] + m[1][3]) * inv_s,
                    (m[3][2] + m[2][3]) * inv_s,
                    0.5f * s,
                    (m[1][2] - m[2][1]) * inv_s);
    }
}

mat4 rotate(const quat& q) {
	return make_mat4_from_quat(q);
}

mat4 make_mat4_from_yaw_pitch_roll(float yaw, float pitch, float roll) {
	return make_mat4_from_quat(make_quat_from_yaw_pitch_roll(yaw, pitch, roll));
}

vec3 yaw_pitch_to_direction(float yaw, float pitch) {
	#if 0
	yaw += M_PI_2;
	float len = cos(pitch);
	return vec3(
		len * cos(-yaw),
		sin(pitch),
		len * sin(yaw));
	#else
	float len = cos(pitch);
	return vec3(
		len * sin(yaw),
		sin(-pitch),
		len * cos(-yaw));
	#endif
}

void direction_to_yaw_pitch(vec3 dir, float& yaw, float& pitch) {
	#if 0
	dir.Normalize();
	pitch = asin(dir[1]);
	yaw = atan2(dir[2], dir[0]);
	yaw -= M_PI_2;
	yaw = yaw < -M_PI ? yaw + M_2PI : yaw;
	#else
	dir.Normalize();
	pitch = asin(-dir[1]);
	yaw = atan2(dir[0], dir[2]);
	#endif
}

void camera_object(
	const vec3& eye, const vec3& eye_dir, const vec3& eye_up,
	float obj_yaw_diff, float obj_pitch_diff, float obj_dist,
	vec3& position) {
	
	// get z-vector from eye direction
	vec3 zv = eye_dir;
	zv.Normalize();
	
	// get x-vector with cross product of z-vector and up-vector
	vec3 xv = cross(zv, eye_up);
	xv.Normalize();
	
	// get y-vector with x-vector and z-vector
	vec3 yv = cross(zv, xv);
	yv.Normalize(); // unnecessary
	
	// calculate relative direction vector for object in local space
	vec3 local_obj_dir = yaw_pitch_to_direction(obj_yaw_diff, obj_pitch_diff);
	vec3 local_eye_dir = yaw_pitch_to_direction(0, 0);
	local_obj_dir.Normalize();
	local_eye_dir.Normalize();
	float local_obj_dir_mag = local_obj_dir.GetMagnitude();
	float local_eye_dir_mag = local_eye_dir.GetMagnitude();
	ASSERT(local_obj_dir_mag == 1.0f);
	ASSERT(local_eye_dir_mag == 1.0f);
	
	// get angle between relative direction vector and eye direction
	float local_obj_eye_dot = dot(local_obj_dir, local_eye_dir);
	float local_obj_eye_angle = acos(local_obj_eye_dot / (local_obj_dir_mag * local_eye_dir_mag));
	float local_obj_eye_angle_deg = RAD2DEG(local_obj_eye_angle);
	
	// calculate plane's z-distance from angle
	float local_plane_z = cos(local_obj_eye_angle) * obj_dist;
	
	// calculate xy point in plane using plane's distance and angles
	float local_plane_x = local_obj_dir[0] * obj_dist;
	float local_plane_y = local_obj_dir[1] * obj_dist;
	
	// calculate relative point in global space using local plane-xyz and global forward-unit-vector
	vec3 obj_xv = xv * local_plane_x;
	vec3 obj_yv = yv * local_plane_y;
	vec3 obj_zv = zv * local_plane_z;
	vec3 obj_rel_pos = obj_xv + obj_yv + obj_zv;
	
	// calculate global position
	position = eye + obj_rel_pos;
	
}

mat4 Rotation(float pitch, float yaw, float roll) {
	return YRotation(yaw) * XRotation(pitch) * ZRotation(roll);
}

mat3 Rotation3x3(float pitch, float yaw, float roll) {
	return YRotation3x3(yaw) * XRotation3x3(pitch) *  ZRotation3x3(roll);
}

mat2 Rotation2x2(float angle) {
	return mat2{
		cosf(angle), sinf(angle),
		-sinf(angle), cosf(angle)
		};
}

/*
// INCORRECT
Compare
quat orient1 = MatrixUtils::orientation(YawPitchRoll(yaw, pitch, roll));
quat orient2 = make_quat_from_yaw_pitch_roll(yaw, pitch, roll);
DUMP(orient1);
DUMP(orient2);

mat4 YawPitchRoll(float yaw, float pitch, float roll) {
	mat4 out;
	out.Clear();
	vec4& r0 = out.data[0];
	vec4& r1 = out.data[1];
	vec4& r2 = out.data[2];
	vec4& r3 = out.data[3];
	r0[0] = (cosf(roll) * cosf(yaw)) + (sinf(roll) * sinf(pitch) * sinf(yaw));
	r1[0] = (sinf(roll) * cosf(pitch));
	r2[0] = (cosf(roll) * -sinf(yaw)) + (sinf(roll) * sinf(pitch) * cosf(yaw));
	r0[1] = (-sinf(roll) * cosf(yaw)) + (cosf(roll) * sinf(pitch) * sinf(yaw));
	r1[1] = (cosf(roll) * cosf(pitch));
	r2[1] = (sinf(roll) * sinf(yaw)) + (cosf(roll) * sinf(pitch) * cosf(yaw));
	r0[2] = (cosf(pitch) * sinf(yaw));
	r1[2] = -sinf(pitch);
	r2[2] = (cosf(pitch) * cosf(yaw));
	r3[3] = 1;
	return out;
}
*/
/*float GetXRotation(const mat4& m) {
	float angle = atan2(m.data[1][1], m.data[1][2]);
	return angle;
}
*/
float GetXRotation(const mat4& m) {
	float angle = atan2(m.data[2][0], m.data[0][0]);
	return angle;
}

mat4 XRotation(float angle) {
	//angle = DegRad(angle);
	return mat4 {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosf(angle), sinf(angle), 0.0f,
		0.0f, -sinf(angle), cosf(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

mat3 XRotation3x3(float angle) {
	//angle = DegRad(angle);
	return mat3 {
		1.0f, 0.0f, 0.0f,
		0.0f, cosf(angle), sinf(angle),
		0.0f, -sinf(angle), cosf(angle)
	};
}

mat4 YRotation(float angle) {
	//angle = DegRad(angle);
	return mat4{
		cosf(angle), 0.0f, -sinf(angle), 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		sinf(angle), 0.0f, cosf(angle), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

mat3 YRotation3x3(float angle) {
	//angle = DegRad(angle);
	return mat3{
		cosf(angle), 0.0f, -sinf(angle),
		0.0f, 1.0f, 0.0f,
		sinf(angle), 0.0f, cosf(angle)
	};
}

mat4 ZRotation(float angle) {
	//angle = DegRad(angle);
	return mat4{
		cosf(angle), sinf(angle), 0.0f, 0.0f,
		-sinf(angle), cosf(angle), 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
}

mat3 ZRotation3x3(float angle) {
	//angle = DegRad(angle);
	return mat3{
		cosf(angle), sinf(angle), 0.0f,
		-sinf(angle), cosf(angle), 0.0f,
		0.0f, 0.0f, 1.0f
	};
}

mat4 FastInverse(const mat4& mat) {

	mat4 inverse = mat.GetTransposed();
	inverse[3][0] = 0.0f;
	inverse[0][3] = 0.0f;
	inverse[3][1] = 0.0f;
	inverse[1][3] = 0.0f;
	inverse[3][2] = 0.0f;
	inverse[2][3] = 0.0f;

	vec3 right =	mat[0].Splice();
	vec3 up =		mat[1].Splice();
	vec3 forward =	mat[2].Splice();
	vec3 position = mat[3].Splice();

	inverse[3][0] = -dot(right, position);
	inverse[3][1] = -dot(up, position);
	inverse[3][2] = -dot(forward, position);

	return inverse;
}

vec2 Project(const vec2& length, const vec2& direction) {
	float dot = Dot(length, direction);
	float magSq = MagnitudeSq(direction);
	return direction * (dot / magSq);
}

vec3 Project(const vec3& length, const vec3& direction) {
	float dot = Dot(length, direction);
	float magSq = MagnitudeSq(direction);
	return direction * (dot / magSq);
}

vec2 Normalized(const vec2& v) {
	return v * (1.0f / Magnitude(v));
}
vec3 Normalized(const vec3& v) {
	return v * (1.0f / Magnitude(v));
}

mat4 Translation(const vec3& pos) {
	return mat4 {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		pos[0],pos[1],pos[2],1.0f
	};
}

mat2 Cut(const mat3& mat, int row, int col) {
	return mat.Cut(row, col);
}

mat3 Cut(const mat4& mat, int row, int col) {
	return mat.Cut(row, col);
}

mat2 Minor(const mat2& mat) {
	return mat2 {
		mat[1][1], mat[1][0],
		mat[0][1], mat[0][0]
	};
}

mat3 Minor(const mat3& mat) {
	mat3 result;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			result[i][j] = Determinant(Cut(mat, i, j));
		}
	}
	
	return result;
}

mat4 Minor(const mat4& mat) {
	mat4 result;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result[i][j] = Determinant(Cut(mat, i, j));
		}
	}

	return result;
}

void Cofactor(mat2& out, const mat2& minor) {
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			out[j][i] = minor[j][i] * powf(-1.0f, i + j);
}

void Cofactor(mat3& out, const mat3& minor) {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			out[j][i] = minor[j][i] * powf(-1.0f, i + j);
}

void Cofactor(mat4& out, const mat4& minor) {
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			out[j][i] = minor[j][i] * powf(-1.0f, i + j);
}

mat2 Cofactor(const mat2& mat) {
	mat2 result;
	Cofactor(result, Minor(mat));
	return result;
}

mat3 Cofactor(const mat3& mat) {
	mat3 result;
	Cofactor(result, Minor(mat));
	return result;
}

mat4 Cofactor(const mat4& mat) {
	mat4 result;
	Cofactor(result, Minor(mat));
	return result;
}

float Determinant(const mat2& mat) {
	float result = 0.0f;

	mat2 cofactor = Cofactor(mat);
	for (int j = 0; j < 2; ++j) {
		result += mat[0][j] * cofactor[0][j];
	}

	return result;
}

float Determinant(const mat3& mat) {
	float result = 0.0f;

	mat3 cofactor = Cofactor(mat);
	for (int j = 0; j < 3; ++j) {
		result += mat[0][j] * cofactor[0][j];
	}

	return result;
}

float Determinant(const mat4& mat) {
	float result = 0.0f;

	mat4 cofactor = Cofactor(mat);
	for (int j = 0; j < 4; ++j) {
		result += mat[0][j] * cofactor[0][j];
	}

	return result;
}

mat2 Transpose(const mat2& matrix) {return matrix.GetTransposed();}
mat3 Transpose(const mat3& matrix) {return matrix.GetTransposed();}
mat4 Transpose(const mat4& matrix) {return matrix.GetTransposed();}

mat2 Adjugate(const mat2& mat) {return Transpose(Cofactor(mat));}
mat3 Adjugate(const mat3& mat) {return Transpose(Cofactor(mat));}
mat4 Adjugate(const mat4& mat) {return Transpose(Cofactor(mat));}

mat2 Inverse(const mat2& mat) {
	float det = Determinant(mat);
	if (CMP(det, 0.0f)) { return mat2(); }
	mat2 a = Adjugate(mat);
	return a * (1.0f / det);
}

mat3 Inverse(const mat3& mat) {
	float det = Determinant(mat);
	if (CMP(det, 0.0f)) { return mat3(); }
	mat3 a = Adjugate(mat);
	return a * (1.0f / det);
}

mat4 Inverse(const mat4& m) {

	float det
		= m.data[0].data[0] * m.data[1].data[1] * m.data[2].data[2] * m.data[3].data[3] + m.data[0].data[0] * m.data[1].data[2] * m.data[2].data[3] * m.data[3].data[1] + m.data[0].data[0] * m.data[1].data[3] * m.data[2].data[1] * m.data[3].data[2]
		+ m.data[0].data[1] * m.data[1].data[0] * m.data[2].data[3] * m.data[3].data[2] + m.data[0].data[1] * m.data[1].data[2] * m.data[2].data[0] * m.data[3].data[3] + m.data[0].data[1] * m.data[1].data[3] * m.data[2].data[2] * m.data[3].data[0]
		+ m.data[0].data[2] * m.data[1].data[0] * m.data[2].data[1] * m.data[3].data[3] + m.data[0].data[2] * m.data[1].data[1] * m.data[2].data[3] * m.data[3].data[0] + m.data[0].data[2] * m.data[1].data[3] * m.data[2].data[0] * m.data[3].data[1]
		+ m.data[0].data[3] * m.data[1].data[0] * m.data[2].data[2] * m.data[3].data[1] + m.data[0].data[3] * m.data[1].data[1] * m.data[2].data[0] * m.data[3].data[2] + m.data[0].data[3] * m.data[1].data[2] * m.data[2].data[1] * m.data[3].data[0]
		- m.data[0].data[0] * m.data[1].data[1] * m.data[2].data[3] * m.data[3].data[2] - m.data[0].data[0] * m.data[1].data[2] * m.data[2].data[1] * m.data[3].data[3] - m.data[0].data[0] * m.data[1].data[3] * m.data[2].data[2] * m.data[3].data[1]
		- m.data[0].data[1] * m.data[1].data[0] * m.data[2].data[2] * m.data[3].data[3] - m.data[0].data[1] * m.data[1].data[2] * m.data[2].data[3] * m.data[3].data[0] - m.data[0].data[1] * m.data[1].data[3] * m.data[2].data[0] * m.data[3].data[2]
		- m.data[0].data[2] * m.data[1].data[0] * m.data[2].data[3] * m.data[3].data[1] - m.data[0].data[2] * m.data[1].data[1] * m.data[2].data[0] * m.data[3].data[3] - m.data[0].data[2] * m.data[1].data[3] * m.data[2].data[1] * m.data[3].data[0]
		- m.data[0].data[3] * m.data[1].data[0] * m.data[2].data[1] * m.data[3].data[2] - m.data[0].data[3] * m.data[1].data[1] * m.data[2].data[2] * m.data[3].data[0] - m.data[0].data[3] * m.data[1].data[2] * m.data[2].data[0] * m.data[3].data[1];

	if (CMP(det, 0.0f)) {
		return mat4();
	}
	float i_det = 1.0f / det;

	mat4 result;
	result[0].data[0] = (m.data[1].data[1] * m.data[2].data[2] * m.data[3].data[3] + m.data[1].data[2] * m.data[2].data[3] * m.data[3].data[1] + m.data[1].data[3] * m.data[2].data[1] * m.data[3].data[2] - m.data[1].data[1] * m.data[2].data[3] * m.data[3].data[2] - m.data[1].data[2] * m.data[2].data[1] * m.data[3].data[3] - m.data[1].data[3] * m.data[2].data[2] * m.data[3].data[1]) * i_det;
	result[0].data[1] = (m.data[0].data[1] * m.data[2].data[3] * m.data[3].data[2] + m.data[0].data[2] * m.data[2].data[1] * m.data[3].data[3] + m.data[0].data[3] * m.data[2].data[2] * m.data[3].data[1] - m.data[0].data[1] * m.data[2].data[2] * m.data[3].data[3] - m.data[0].data[2] * m.data[2].data[3] * m.data[3].data[1] - m.data[0].data[3] * m.data[2].data[1] * m.data[3].data[2]) * i_det;
	result[0].data[2] = (m.data[0].data[1] * m.data[1].data[2] * m.data[3].data[3] + m.data[0].data[2] * m.data[1].data[3] * m.data[3].data[1] + m.data[0].data[3] * m.data[1].data[1] * m.data[3].data[2] - m.data[0].data[1] * m.data[1].data[3] * m.data[3].data[2] - m.data[0].data[2] * m.data[1].data[1] * m.data[3].data[3] - m.data[0].data[3] * m.data[1].data[2] * m.data[3].data[1]) * i_det;
	result[0].data[3] = (m.data[0].data[1] * m.data[1].data[3] * m.data[2].data[2] + m.data[0].data[2] * m.data[1].data[1] * m.data[2].data[3] + m.data[0].data[3] * m.data[1].data[2] * m.data[2].data[1] - m.data[0].data[1] * m.data[1].data[2] * m.data[2].data[3] - m.data[0].data[2] * m.data[1].data[3] * m.data[2].data[1] - m.data[0].data[3] * m.data[1].data[1] * m.data[2].data[2]) * i_det;
	result[1].data[0] = (m.data[1].data[0] * m.data[2].data[3] * m.data[3].data[2] + m.data[1].data[2] * m.data[2].data[0] * m.data[3].data[3] + m.data[1].data[3] * m.data[2].data[2] * m.data[3].data[0] - m.data[1].data[0] * m.data[2].data[2] * m.data[3].data[3] - m.data[1].data[2] * m.data[2].data[3] * m.data[3].data[0] - m.data[1].data[3] * m.data[2].data[0] * m.data[3].data[2]) * i_det;
	result[1].data[1] = (m.data[0].data[0] * m.data[2].data[2] * m.data[3].data[3] + m.data[0].data[2] * m.data[2].data[3] * m.data[3].data[0] + m.data[0].data[3] * m.data[2].data[0] * m.data[3].data[2] - m.data[0].data[0] * m.data[2].data[3] * m.data[3].data[2] - m.data[0].data[2] * m.data[2].data[0] * m.data[3].data[3] - m.data[0].data[3] * m.data[2].data[2] * m.data[3].data[0]) * i_det;
	result[1].data[2] = (m.data[0].data[0] * m.data[1].data[3] * m.data[3].data[2] + m.data[0].data[2] * m.data[1].data[0] * m.data[3].data[3] + m.data[0].data[3] * m.data[1].data[2] * m.data[3].data[0] - m.data[0].data[0] * m.data[1].data[2] * m.data[3].data[3] - m.data[0].data[2] * m.data[1].data[3] * m.data[3].data[0] - m.data[0].data[3] * m.data[1].data[0] * m.data[3].data[2]) * i_det;
	result[1].data[3] = (m.data[0].data[0] * m.data[1].data[2] * m.data[2].data[3] + m.data[0].data[2] * m.data[1].data[3] * m.data[2].data[0] + m.data[0].data[3] * m.data[1].data[0] * m.data[2].data[2] - m.data[0].data[0] * m.data[1].data[3] * m.data[2].data[2] - m.data[0].data[2] * m.data[1].data[0] * m.data[2].data[3] - m.data[0].data[3] * m.data[1].data[2] * m.data[2].data[0]) * i_det;
	result[2].data[0] = (m.data[1].data[0] * m.data[2].data[1] * m.data[3].data[3] + m.data[1].data[1] * m.data[2].data[3] * m.data[3].data[0] + m.data[1].data[3] * m.data[2].data[0] * m.data[3].data[1] - m.data[1].data[0] * m.data[2].data[3] * m.data[3].data[1] - m.data[1].data[1] * m.data[2].data[0] * m.data[3].data[3] - m.data[1].data[3] * m.data[2].data[1] * m.data[3].data[0]) * i_det;
	result[2].data[1] = (m.data[0].data[0] * m.data[2].data[3] * m.data[3].data[1] + m.data[0].data[1] * m.data[2].data[0] * m.data[3].data[3] + m.data[0].data[3] * m.data[2].data[1] * m.data[3].data[0] - m.data[0].data[0] * m.data[2].data[1] * m.data[3].data[3] - m.data[0].data[1] * m.data[2].data[3] * m.data[3].data[0] - m.data[0].data[3] * m.data[2].data[0] * m.data[3].data[1]) * i_det;
	result[2].data[2] = (m.data[0].data[0] * m.data[1].data[1] * m.data[3].data[3] + m.data[0].data[1] * m.data[1].data[3] * m.data[3].data[0] + m.data[0].data[3] * m.data[1].data[0] * m.data[3].data[1] - m.data[0].data[0] * m.data[1].data[3] * m.data[3].data[1] - m.data[0].data[1] * m.data[1].data[0] * m.data[3].data[3] - m.data[0].data[3] * m.data[1].data[1] * m.data[3].data[0]) * i_det;
	result[2].data[3] = (m.data[0].data[0] * m.data[1].data[3] * m.data[2].data[1] + m.data[0].data[1] * m.data[1].data[0] * m.data[2].data[3] + m.data[0].data[3] * m.data[1].data[1] * m.data[2].data[0] - m.data[0].data[0] * m.data[1].data[1] * m.data[2].data[3] - m.data[0].data[1] * m.data[1].data[3] * m.data[2].data[0] - m.data[0].data[3] * m.data[1].data[0] * m.data[2].data[1]) * i_det;
	result[3].data[0] = (m.data[1].data[0] * m.data[2].data[2] * m.data[3].data[1] + m.data[1].data[1] * m.data[2].data[0] * m.data[3].data[2] + m.data[1].data[2] * m.data[2].data[1] * m.data[3].data[0] - m.data[1].data[0] * m.data[2].data[1] * m.data[3].data[2] - m.data[1].data[1] * m.data[2].data[2] * m.data[3].data[0] - m.data[1].data[2] * m.data[2].data[0] * m.data[3].data[1]) * i_det;
	result[3].data[1] = (m.data[0].data[0] * m.data[2].data[1] * m.data[3].data[2] + m.data[0].data[1] * m.data[2].data[2] * m.data[3].data[0] + m.data[0].data[2] * m.data[2].data[0] * m.data[3].data[1] - m.data[0].data[0] * m.data[2].data[2] * m.data[3].data[1] - m.data[0].data[1] * m.data[2].data[0] * m.data[3].data[2] - m.data[0].data[2] * m.data[2].data[1] * m.data[3].data[0]) * i_det;
	result[3].data[2] = (m.data[0].data[0] * m.data[1].data[2] * m.data[3].data[1] + m.data[0].data[1] * m.data[1].data[0] * m.data[3].data[2] + m.data[0].data[2] * m.data[1].data[1] * m.data[3].data[0] - m.data[0].data[0] * m.data[1].data[1] * m.data[3].data[2] - m.data[0].data[1] * m.data[1].data[2] * m.data[3].data[0] - m.data[0].data[2] * m.data[1].data[0] * m.data[3].data[1]) * i_det;
	result[3].data[3] = (m.data[0].data[0] * m.data[1].data[1] * m.data[2].data[2] + m.data[0].data[1] * m.data[1].data[2] * m.data[2].data[0] + m.data[0].data[2] * m.data[1].data[0] * m.data[2].data[1] - m.data[0].data[0] * m.data[1].data[2] * m.data[2].data[1] - m.data[0].data[1] * m.data[1].data[0] * m.data[2].data[2] - m.data[0].data[2] * m.data[1].data[1] * m.data[2].data[0]) * i_det;
	
	return result;
}

bool Multiply(vec2& out, const vec2& v, const mat2& m) {
	out = v * m;
	return true;
}

bool Multiply(vec3& out, const vec3& v, const mat3& m) {
	out = v * m;
	return true;
}

bool Multiply(vec4& out, const vec4& v, const mat4& m) {
	out = v * m;
	return true;
}

float Dot(const vec2& a, const vec2& b) {
	return a.Dot(b);
}

float Dot(const vec3& a, const vec3& b) {
	return a.Dot(b);
}

vec3 Cross(const vec3& l, const vec3& r) {return cross(l,r);}
float Magnitude(const vec2& v) {return v.GetMagnitude();}
float Magnitude(const vec3& v) {return v.GetMagnitude();}
float MagnitudeSq(const vec2& v) {return v.GetMagnitudeSq();}
float MagnitudeSq(const vec3& v) {return v.GetMagnitudeSq();}

float CorrectDegrees(float degrees) {
	while (degrees > 360.0f) {
		degrees -= 360.0f;
	}
	while (degrees < -360.0f) {
		degrees += 360.0f;
	}
	return degrees;
}

float RadDeg(float radians) {
	float degrees = radians * 57.295754f;
	degrees = CorrectDegrees(degrees);
	return degrees;
}

float DegRad(float degrees) {
	degrees = CorrectDegrees(degrees);
	float radians = degrees * 0.0174533f;
	return radians;
}

void SetCrossMatrixPlus(mat3& res, const vec3& a)
{
	const float a_0 = a[0];
	const float a_1 = a[1];
	const float a_2 = a[2];
	res[0][1] = -a_2;
	res[0][2] = +a_1;
	res[1][0] = +a_2;
	res[1][2] = -a_0;
	res[2][0] = -a_1;
	res[2][1] = +a_0;
}



float CalcVectorDot(const mat3& a, int a_col, const vec3& b) {
	return	a[0][a_col] * b[0] +
			a[1][a_col] * b[1] +
			a[2][a_col] * b[2];
}

void Multiply0_333_Helper(vec3& res, const mat3& a, const vec3& b) {
  float res_0 = CalcVectorDot(a, 0, b);
  float res_1 = CalcVectorDot(a, 1, b);
  float res_2 = CalcVectorDot(a, 2, b);
  res[0] = res_0;
  res[1] = res_1;
  res[2] = res_2;
}

void Multiply(mat3& res, const mat3& a, const mat3& b) {
	Multiply0_333_Helper(res[0], b, a[0]);
	Multiply0_333_Helper(res[1], b, a[1]);
	Multiply0_333_Helper(res[2], b, a[2]);
}


bool FactorCholesky(mat3& A, vec3& out) {
    bool failure = false;
    const unsigned n = 3;
    
    for (unsigned i = 0; i < n; ++i) {
        vec3& cc = A[i];
        {
            for (unsigned j = 0; j < i; ++j) {
                vec3& bb = A[j];
                
                float sum = cc[j];
				for(int k = 0; k < j; k++) {
					sum -= cc[k] * bb[k];
				}
				cc[j] = sum * out[j];
            }
        }
        {
            float sum = cc[i];
            for (unsigned j = 0; j < i; ++j) {
                float f = cc[j];
                sum -= f * f;
            }
            if (sum <= 0.0f) {
                failure = true;
                break;
            }
            float sumsqrt = FastSqrt(sum);
            cc[i] = sumsqrt;
            out[i] = 1.0f / sumsqrt;
        }
    }
    
    return failure ? 0 : 1;
}

bool IsPositiveDefinite(const mat3& m) {
	vec3 tmp{0,0,0};
	mat3 tmp_m = m;
	return FactorCholesky(tmp_m, tmp);
}

void ToMat3_(mat3& m, const quat& q) {
    float qq1 = 2 * q[1] * q[1];
    float qq2 = 2 * q[2] * q[2];
    float qq3 = 2 * q[3] * q[3];
    m[0][0] = 1 - qq2 - qq3;
    m[0][1] = 2*(q[1]*q[2] - q[0]*q[3]);
    m[0][2] = 2*(q[1]*q[3] + q[0]*q[2]);
    
    m[1][0] = 2*(q[1]*q[2] + q[0]*q[3]);
    m[1][1] = 1 - qq1 - qq3;
    m[1][2] = 2*(q[2]*q[3] - q[0]*q[1]);
    
    m[2][0] = 2*(q[1]*q[3] - q[0]*q[2]);
    m[2][1] = 2*(q[2]*q[3] + q[0]*q[1]);
    m[2][2] = 1 - qq1 - qq2;
}

void StoreMatrix(mat4* dst, const mat4& src) {
	*dst = src;
}

void StoreVec2(vec2* dst, const vec4& src) {
	*dst = src.Splice<0,2>();
}

void StoreVec3(vec3* dst, const vec4& src) {
	*dst = src.Splice<0,3>();
}

void StoreVec4(vec4* dst, const vec4& src) {
	*dst = src;
}

void ScalarSinCos(float* f_sin, float* f_cos, float rad) {
	ASSERT(f_sin && f_cos);
	if (f_sin) *f_sin = FastSin(rad);
	if (f_cos) *f_cos = FastCos(rad);
}

vec4 VectorScale(const vec4& v, float f) {
	return v * f;
}

RGBA CreateRGBA(const vec4& color) {
    vec4 colorf = color * 255.f;
    return RGBA { (byte)colorf[0], (byte)colorf[1], (byte)colorf[2], (byte)colorf[3] };
}

vec3 MultiplyPoint(const vec3& vec, const mat4& mat) {
	return (vec.Embed() * mat).Splice(); // notice Embed = Extend(1)
}

vec3 MultiplyVector(const vec3& vec, const mat3& mat) {
	return vec * mat;
}

vec3 MultiplyVector(const vec3& vec, const mat4& mat) {
	return (vec.Extend() * mat).Splice();
}

mat4 MultiplyMatrix(const mat4& m0, const mat4& m1) {
	mat4 r;
    
    float x = m0.data[0].data[0];
    float y = m0.data[0].data[1];
    float z = m0.data[0].data[2];
    float w = m0.data[0].data[3];
    
    r.data[0].data[0] = (m1.data[0].data[0] * x) + (m1.data[1].data[0] * y) + (m1.data[2].data[0] * z) + (m1.data[3].data[0] * w);
    r.data[0].data[1] = (m1.data[0].data[1] * x) + (m1.data[1].data[1] * y) + (m1.data[2].data[1] * z) + (m1.data[3].data[1] * w);
    r.data[0].data[2] = (m1.data[0].data[2] * x) + (m1.data[1].data[2] * y) + (m1.data[2].data[2] * z) + (m1.data[3].data[2] * w);
    r.data[0].data[3] = (m1.data[0].data[3] * x) + (m1.data[1].data[3] * y) + (m1.data[2].data[3] * z) + (m1.data[3].data[3] * w);
    
    x = m0.data[1].data[0];
    y = m0.data[1].data[1];
    z = m0.data[1].data[2];
    w = m0.data[1].data[3];
    r.data[1].data[0] = (m1.data[0].data[0] * x) + (m1.data[1].data[0] * y) + (m1.data[2].data[0] * z) + (m1.data[3].data[0] * w);
    r.data[1].data[1] = (m1.data[0].data[1] * x) + (m1.data[1].data[1] * y) + (m1.data[2].data[1] * z) + (m1.data[3].data[1] * w);
    r.data[1].data[2] = (m1.data[0].data[2] * x) + (m1.data[1].data[2] * y) + (m1.data[2].data[2] * z) + (m1.data[3].data[2] * w);
    r.data[1].data[3] = (m1.data[0].data[3] * x) + (m1.data[1].data[3] * y) + (m1.data[2].data[3] * z) + (m1.data[3].data[3] * w);
    
    x = m0.data[2].data[0];
    y = m0.data[2].data[1];
    z = m0.data[2].data[2];
    w = m0.data[2].data[3];
    r.data[2].data[0] = (m1.data[0].data[0] * x) + (m1.data[1].data[0] * y) + (m1.data[2].data[0] * z) + (m1.data[3].data[0] * w);
    r.data[2].data[1] = (m1.data[0].data[1] * x) + (m1.data[1].data[1] * y) + (m1.data[2].data[1] * z) + (m1.data[3].data[1] * w);
    r.data[2].data[2] = (m1.data[0].data[2] * x) + (m1.data[1].data[2] * y) + (m1.data[2].data[2] * z) + (m1.data[3].data[2] * w);
    r.data[2].data[3] = (m1.data[0].data[3] * x) + (m1.data[1].data[3] * y) + (m1.data[2].data[3] * z) + (m1.data[3].data[3] * w);
    
    x = m0.data[3].data[0];
    y = m0.data[3].data[1];
    z = m0.data[3].data[2];
    w = m0.data[3].data[3];
    r.data[3].data[0] = (m1.data[0].data[0] * x) + (m1.data[1].data[0] * y) + (m1.data[2].data[0] * z) + (m1.data[3].data[0] * w);
    r.data[3].data[1] = (m1.data[0].data[1] * x) + (m1.data[1].data[1] * y) + (m1.data[2].data[1] * z) + (m1.data[3].data[1] * w);
    r.data[3].data[2] = (m1.data[0].data[2] * x) + (m1.data[1].data[2] * y) + (m1.data[2].data[2] * z) + (m1.data[3].data[2] * w);
    r.data[3].data[3] = (m1.data[0].data[3] * x) + (m1.data[1].data[3] * y) + (m1.data[2].data[3] * z) + (m1.data[3].data[3] * w);
    
    return r;
}

mat4 MatrixInverse(const mat4* l, const mat4& r) {
	TODO
}

vec4 VectorSet(float x, float y, float z, float d) {
	return vec4 {x, y, z, d};
}

vec4 VectorCross(const vec4& a, const vec4& b) {
	return cross(a, b);
}

mat4 MatrixTranspose(const mat4& m) {
	return m.GetTransposed();
}

mat4 DoubleToMatrix4(const std::vector<double>& v) {
	ASSERT(v.size() == 16);
	mat4 m;
	int k = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			m[i][j] = k < v.size() ? v[k] : 0;
			k++;
		}
	}
	return m;
}

vec3 DoubleToVector3(const std::vector<double>& v) {
	ASSERT(v.size() == 3);
	vec3 r;
	for(int i = 0; i < 3; i++)
		r[i] = v[i];
	return r;
}

vec3 DoubleToVector4(const std::vector<double>& v) {
	ASSERT(v.size() == 4);
	vec3 r;
	for(int i = 0; i < 4; i++)
		r[i] = v[i];
	return r;
}

quat DoubleToQuat(const std::vector<double>& v) {
	ASSERT(v.size() == 4);
	quat r;
	for(int i = 0; i < 4; i++)
		r[i] = v[i];
	return r;
}

mat4 MatrixTransformation(
    const vec3& scaling_origin,
    const quat& scaling_orientation_quaternion,
    const vec3& scaling,
    const vec3& rotation_origin,
    const quat& rotation_quaternion,
    const vec3& translation
)
{
    vec4 v_scaling_origin			= scaling_origin.Extend();
    vec3 neg_scaling_origin			= -scaling_origin;

    mat4 m_scaling_origin_i			= MatrixTranslationFromVector(neg_scaling_origin);
    mat4 m_scaling_orientation		= MatrixRotationQuaternion(scaling_orientation_quaternion);
    mat4 m_scaling_orientation_t	= MatrixTranspose(m_scaling_orientation);
    mat4 m_scaling					= MatrixScalingFromVector(scaling);
    vec4 v_rotation_origin			= rotation_origin.Extend();
    mat4 m_rotation					= MatrixRotationQuaternion(rotation_quaternion);
    vec4 v_translation				= translation.Extend();

    mat4 m;
    m		= MatrixMultiply(m_scaling_origin_i, m_scaling_orientation_t);
    m		= MatrixMultiply(m, m_scaling);
    m		= MatrixMultiply(m, m_scaling_orientation);
    m[3]	= m[3] + v_scaling_origin;
    m[3]	= m[3] - v_rotation_origin;
    m		= MatrixMultiply(m, m_rotation);
    m[3]	= m[3] + v_rotation_origin + v_translation;
    return m;
}

mat4 MatrixTranslationFromVector(const vec3& v) {
	mat4 m;
	m.SetIdentity();
	m.SetComponentTranslate(v[0], v[1], v[2]);
	return m;
}

mat4 MatrixRotationQuaternion(quat q) {
    float qx = q[0];
    float qxx = qx * qx;

    float qy = q[1];
    float qyy = qy * qy;

    float qz = q[2];
    float qzz = qz * qz;

    float qw = q[3];

    mat4 m;
    m[0][0] = 1.f - 2.f * qyy - 2.f * qzz;
    m[0][1] = 2.f * qx * qy + 2.f * qz * qw;
    m[0][2] = 2.f * qx * qz - 2.f * qy * qw;
    m[0][3] = 0.f;

    m[1][0] = 2.f * qx * qy - 2.f * qz * qw;
    m[1][1] = 1.f - 2.f * qxx - 2.f * qzz;
    m[1][2] = 2.f * qy * qz + 2.f * qx * qw;
    m[1][3] = 0.f;

    m[2][0] = 2.f * qx * qz + 2.f * qy * qw;
    m[2][1] = 2.f * qy * qz - 2.f * qx * qw;
    m[2][2] = 1.f - 2.f * qxx - 2.f * qyy;
    m[2][3] = 0.f;

    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = 0.f;
    m[3][3] = 1.0f;
    
    return m;
}

mat4 MatrixScalingFromVector(const vec3& scale)
{
    mat4 m;
    
    m[0][0] = scale[0];
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[0][3] = 0.0f;

    m[1][0] = 0.0f;
    m[1][1] = scale[1];
    m[1][2] = 0.0f;
    m[1][3] = 0.0f;

    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = scale[2];
    m[2][3] = 0.0f;

    m[3][0] = 0.0f;
    m[3][1] = 0.0f;
    m[3][2] = 0.0f;
    m[3][3] = 1.0f;
    return m;
}

mat4 MatrixMultiply(const mat4& m1, const mat4& m2) {
    mat4 r;
    
    // Cache the invariants in registers
    float x = m1[0][0];
    float y = m1[0][1];
    float z = m1[0][2];
    float w = m1[0][3];
    
    // Perform the operation on the first row
    r[0][0] = (m2[0][0] * x) + (m2[1][0] * y) + (m2[2][0] * z) + (m2[3][0] * w);
    r[0][1] = (m2[0][1] * x) + (m2[1][1] * y) + (m2[2][1] * z) + (m2[3][1] * w);
    r[0][2] = (m2[0][2] * x) + (m2[1][2] * y) + (m2[2][2] * z) + (m2[3][2] * w);
    r[0][3] = (m2[0][3] * x) + (m2[1][3] * y) + (m2[2][3] * z) + (m2[3][3] * w);
    
    // Repeat for all the other rows
    x = m1[1][0];
    y = m1[1][1];
    z = m1[1][2];
    w = m1[1][3];
    r[1][0] = (m2[0][0] * x) + (m2[1][0] * y) + (m2[2][0] * z) + (m2[3][0] * w);
    r[1][1] = (m2[0][1] * x) + (m2[1][1] * y) + (m2[2][1] * z) + (m2[3][1] * w);
    r[1][2] = (m2[0][2] * x) + (m2[1][2] * y) + (m2[2][2] * z) + (m2[3][2] * w);
    r[1][3] = (m2[0][3] * x) + (m2[1][3] * y) + (m2[2][3] * z) + (m2[3][3] * w);
    
    x = m1[2][0];
    y = m1[2][1];
    z = m1[2][2];
    w = m1[2][3];
    r[2][0] = (m2[0][0] * x) + (m2[1][0] * y) + (m2[2][0] * z) + (m2[3][0] * w);
    r[2][1] = (m2[0][1] * x) + (m2[1][1] * y) + (m2[2][1] * z) + (m2[3][1] * w);
    r[2][2] = (m2[0][2] * x) + (m2[1][2] * y) + (m2[2][2] * z) + (m2[3][2] * w);
    r[2][3] = (m2[0][3] * x) + (m2[1][3] * y) + (m2[2][3] * z) + (m2[3][3] * w);
    
    x = m1[3][0];
    y = m1[3][1];
    z = m1[3][2];
    w = m1[3][3];
    r[3][0] = (m2[0][0] * x) + (m2[1][0] * y) + (m2[2][0] * z) + (m2[3][0] * w);
    r[3][1] = (m2[0][1] * x) + (m2[1][1] * y) + (m2[2][1] * z) + (m2[3][1] * w);
    r[3][2] = (m2[0][2] * x) + (m2[1][2] * y) + (m2[2][2] * z) + (m2[3][2] * w);
    r[3][3] = (m2[0][3] * x) + (m2[1][3] * y) + (m2[2][3] * z) + (m2[3][3] * w);
    
    return r;
}

const vec4 IdentityR0            = vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
const vec4 IdentityR1            = vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
const vec4 IdentityR2            = vec4{ 0.0f, 0.0f, 1.0f, 0.0f };
const vec4 IdentityR3            = vec4{ 0.0f, 0.0f, 0.0f, 1.0f };
const vec4 NegIdentityR0         = vec4{ -1.0f, 0.0f, 0.0f, 0.0f };
const vec4 NegIdentityR1         = vec4{ 0.0f, -1.0f, 0.0f, 0.0f };
const vec4 NegIdentityR2         = vec4{ 0.0f, 0.0f, -1.0f, 0.0f };
const vec4 NegIdentityR3         = vec4{ 0.0f, 0.0f, 0.0f, -1.0f };



// https://stackoverflow.com/questions/18558910/direction-vector-to-rotation-matrix
quat make_rotation_direction(const vec3& dir, const vec3& up) {
	vec3 xaxis = cross(up, dir);
	xaxis.Normalize();
	
	vec3 yaxis = cross(dir, xaxis);
	yaxis.Normalize();
	
	mat4 rot;
	rot[0][0] = xaxis[0];
	rot[0][1] = yaxis[0];
	rot[0][2] = dir[0];
	rot[0][3] = 0;
	
	rot[1][0] = xaxis[1];
	rot[1][1] = yaxis[1];
	rot[1][2] = dir[1];
	rot[1][3] = 0;
	
	rot[2][0] = xaxis[2];
	rot[2][1] = yaxis[2];
	rot[2][2] = dir[2];
	rot[2][3] = 0;
	
	rot[3][0] = 0;
	rot[3][1] = 0;
	rot[3][2] = 0;
	rot[3][3] = 1;
	
	// note: not verified to be correct
	return make_quat_from_rotation_matrix(rot);
}

void decompose_quat(const quat& q, float& yaw, float& pitch, float& roll) {
	float x = q[0];
	float y = q[1];
	float z = q[2];
	float w = q[3];
	yaw   = atan2(2*y*w - 2*x*z, 1 - 2*y*y - 2*z*z);
	pitch = -atan2(2*x*w - 2*y*z, 1 - 2*x*x - 2*z*z);
	roll  = asin(2*x*y + 2*z*w);
}

namespace MatrixUtils {
vec3 right(const mat4& transform)
{
    return { +transform[0][0], +transform[0][1], +transform[0][2] };
}

vec3 left(const mat4& transform)
{
    return { -transform[0][0], -transform[0][1], -transform[0][2] };
}

vec3 up(const mat4& transform)
{
    return { +transform[1][0], +transform[1][1], +transform[1][2] };
}

vec3 down(const mat4& transform)
{
    return { -transform[1][0], -transform[1][1], -transform[1][2] };
}

vec3 forward(const mat4& transform)
{
    return { +transform[2][0], +transform[2][1], +transform[2][2] };
}

vec3 backward(const mat4& transform)
{
    return { -transform[2][0], -transform[2][1], -transform[2][2] };
}

vec3 position(const mat4& transform)
{
    return { +transform[3][0], +transform[3][1], +transform[3][2] };
}


quat orientation(const mat4& transform)
{
    vec3 baller_position, size, skew;
	quat orientation;
	vec4 persp;
	Decompose(transform, size, orientation, baller_position, skew, persp);
	return orientation;
}



mat4 RemoveScale(const mat4& transform)
{
    quat rotation;
    vec3 scale, translation, skew;
    vec4 pers;
    Decompose(transform, scale, rotation, translation, skew, pers);
    rotation.Normalize();
    return translate(translation) * ToMat4(rotation);
}
}






vec3 GetVelocityNearSourceLocation(
	    const vec3& grasp_position,
	    const vec3& grasp_velocity,
	    const vec3& angular_velocity,
	    const vec3& position_near_source_location)
{
    // Compute the tangential velocity at position_near_source_location due to angular velocity.
    vec3 position_near_source_location_offset = position_near_source_location - grasp_position;
    vec3 angular_tangential_velocity = cross(angular_velocity, position_near_source_location_offset);

    // Combine the tangential velocity with the velocity to get the combined velocity.
    vec3 ret = grasp_velocity + angular_tangential_velocity;
    return ret;
}

NAMESPACE_TOPSIDE_END
