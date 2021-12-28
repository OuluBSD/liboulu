#ifndef _Math_Matrix_h_
#define _Math_Matrix_h_

NAMESPACE_TOPSIDE_BEGIN

#define STRICT_MTX_CHECK(x) ASSERT(x)

template <class T, int I> struct PartVec {};
template <class T, int R, int C> struct Matrix;

template <class T> struct PartVec<T, 2> {
	static inline T GetCrossProduct(const T& a, const T& b);
};

template <class T> struct PartVec<T, 3> {
	static inline T GetCrossProduct(const T& a, const T& b);
};

template <class T, int I>
struct Vec : Moveable<Vec<T, I> > {
	static const int size = I;
	
	typedef T Unit;
	
	
	T data[I];
	
	
	Vec() {}
	Vec(Vec&& v) {memcpy(this, &v, sizeof(Vec));}
	Vec(const Vec& v) {memcpy(this, &v, sizeof(Vec));}
	Vec(T value) {SetConst(value);}
	Vec(T x, T y) {Set(x,y); ClearFrom(2);}
	Vec(T x, T y, T z) {Set(x,y,z); ClearFrom(3);}
	Vec(T x, T y, T z, T w) {Set(x,y,z,w); ClearFrom(4);}
	Vec(std::initializer_list<T> list) {
		ASSERT(list.size() == I);
		int i = 0; for(auto& v : list) data[i++] = v;
	}
	Vec(Nuller) {SetNull();}
	//Vec(const byte* b, T mul, T offset) {Set(b, mul, offset);}
	
	void SetNull() {for(int i = 0; i < I; i++) data[i] = std::numeric_limits<T>::max();}
	bool IsNull() const {for(int i = 0; i < I; i++) if (data[i] != std::numeric_limits<T>::max()) return false; return true;}
	//operator bool() const {return !IsNull();}
	
	void Clear() {memset(this, 0, sizeof(Vec));}
	void ClearFrom(int i) {for(; i < I; i++) data[i] = 0;}
	
	hash_t GetHashValue() const {
		CombineHash c;
		for(int i = 0; i < I; i++) c.Put(UPP::GetHashValue(data[i]));
		return c;
	}
	T& operator[](int i) {STRICT_MTX_CHECK(i >= 0 && i < I); return data[i];}
	const T& operator[](int i) const {STRICT_MTX_CHECK(i >= 0 && i < I); return data[i];}
	
	Vec& operator=(const Vec& v) {memcpy(this, &v, sizeof(Vec)); return *this;}
	Vec& operator*=(T v) {for(int i = 0; i < I; i++) data[i] *= v; return *this;}
	Vec& operator/=(T v) {for(int i = 0; i < I; i++) data[i] /= v; return *this;}
	template<int J> Vec& operator+=(const Vec<T,J>& v) {for(int i = 0; i < std::min(I,J); i++) data[i] += v.data[i]; return *this;}
	
	Vec operator-()             const {Vec r; for(int i = 0; i < I; i++) r.data[i] = -data[i]; return r;}
	Vec operator-(const Vec& v) const {Vec r; for(int i = 0; i < I; i++) r.data[i] = data[i] - v.data[i]; return r;}
	Vec operator+(const Vec& v) const {Vec r; for(int i = 0; i < I; i++) r.data[i] = data[i] + v.data[i]; return r;}
	Vec operator*(T v)          const {Vec r; for(int i = 0; i < I; i++) r.data[i] = data[i] * v; return r;}
	Vec operator/(T v)          const {Vec r; for(int i = 0; i < I; i++) r.data[i] = data[i] / v; return r;}
	Vec operator^(const Vec& v) const {return GetCrossProduct(v);}
	//T   operator*(const Vec& v) const {return GetDotProduct(v);}
	Vec operator*(const Vec& v) const {Vec r; for(int i = 0; i < I; i++) r.data[i] = data[i] * v.data[i]; return r;}
	
	Vec Multiply(const Vec& v)   const {Vec r; for(int i = 0; i < I; i++) r.data[i] = data[i] * v.data[i]; return r;}
	Vec Multiply(T v)           const {Vec r; for(int i = 0; i < I; i++) r.data[i] = data[i] * v; return r;}
	
	Vec operator*(const Matrix<T,I,I>& m) const;
	
	bool operator==(const Vec& v) const {for(int i = 0; i < I; i++) if (data[i] != v.data[i]) return false; return true;}
	bool operator!=(const Vec& v) const {return !(*this == v);}
	
	Vec& Normalize() {
		T mag = 0;
		for(int i = 0; i < I; i++) mag += data[i] * data[i];
		ASSERT_(mag != 0, "zero magnitude vector");
		mag = 1 / std::sqrt(mag);
		for(int i = 0; i < I; i++) data[i] *= mag;
		return *this;
	}
	Vec& Set(T x) {static_assert(I >= 1, "Invalid ctor"); data[0] = x; return *this;}
	Vec& Set(T x, T y) {static_assert(I >= 2, "Invalid ctor"); data[1] = y; return Set(x);}
	Vec& Set(T x, T y, T z) {static_assert(I >= 3, "Invalid ctor"); data[2] = z; return Set(x,y);}
	Vec& Set(T x, T y, T z, T w) {static_assert(I >= 4, "Invalid ctor"); data[3] = w; return Set(x,y,z);}
	Vec& SetData(const byte* b, T mul, T offset) {for(int i = 0; i < I; i++) data[i] = ((T)b[i] / (T)255) * mul + offset; return *this;}
	
	Vec& SetConst(const T& value) {for(int i = 0; i < I; i++) data[i] = value; return *this;}
	Vec& SetIdentity() {for(int i = 0; i < I; i++) data[i] = (T)(i == 0 ? 1 : 0); return *this;}
	template <int begin=0, int end=I-1> Vec& SetFromSplice(const Vec<T, end - begin>& src) {
		static_assert(begin < end, "Splicing area must be positive");
		static_assert(end - begin <= I, "Splicing area must be less or equal to source area");
		for(int i = begin, j = 0; i < end; i++, j++) data[i] = src.data[j];
		return *this;
	}
	template <int from_i=I-1> Vec& Project() {ASSERT(data[from_i] != 0.0); static_assert(from_i >= 0 && from_i < I, "Invalid project pos");for(int i = 0; i < I; i++) if (i != from_i) data[i] /= data[from_i]; data[from_i] = 1.0; return *this;}
	
	template <int begin=0, int end=I-1> Vec<T, end - begin> Splice() const {
		static_assert(begin < end, "Splicing area must be positive");
		static_assert(end - begin <= I, "Splicing area must be less or equal to source area");
		Vec<T, end - begin> ret;
		for(int i = begin, j = 0; i < end; i++, j++) ret.data[j] = data[i];
		return ret;
	}
	template <int J=I+1> Vec<T,J> Embed() const {return Extend<J>(1.0f);}
	template <int J=I+1> Vec<T,J> Extend(float value=0.0) const {
		Vec<T,J> ret;
		for(int i = 0; i < I; i++) ret[i] = data[i];
		for(int j = I; j < J; j++) ret[j] = value;
		return ret;
	}
	
	T GetLengthSquared() const {T r = 0; for(int i = 0; i < I; i++) r += data[i] * data[i]; return r;}
	T GetLength() const {return std::sqrt(GetLengthSquared());}
	T GetAngle(const Vec& v) const {
		T m = std::sqrt(GetLengthSquared() + v.GetLengthSquared());
		return FastACos((*this * v) / m);
		//T m = pow(GetLengthSquared() + v.GetLengthSquared(), 0.5); return acos((*this * v) / m);
	}
	
	Vec GetNormalized() const {Vec v(*this); v.Normalize(); return v;}
	T   GetDotProduct(const Vec& v) const {T r = 0; for(int i = 0; i < I; i++) r += data[i] * v.data[i]; return r;}
	Vec GetCrossProduct(const Vec& b) const {return PartVec<Vec,I>::GetCrossProduct(*this, b);}
	Vec GetProjection(const Vec& v) const {return *this * (v.Dot(*this) / GetLengthSquared());}
	Vec GetReflection(const Vec& surf_normal) const {return *this - surf_normal * ((*this * surf_normal) * (T)2);}
	Vec	GetAbsolute() const {Vec v(*this); for(int i = 0; i < I; i++) if (v.data[i] < 0) v.data[i] *= -1; return v;}
	T   Dot(const Vec& v) const {return GetDotProduct(v);}
	Vec Scale(T target_len) const {
		Vec v;
		T mul = target_len / GetLength();
		for(int i = 0; i < I; i++)
			v.data[i] = data[i] * mul;
		return v;
	}
	
	static Vec GetMin(const Vec& a, const Vec& b) {Vec r; for(int i = 0; i < I; i++) r.data[i] = std::min(a.data[i], b.data[i]); return r;}
	static Vec GetMax(const Vec& a, const Vec& b) {Vec r; for(int i = 0; i < I; i++) r.data[i] = std::max(a.data[i], b.data[i]); return r;}
	
	String ToString() const {
		String s = "[";
		for(int i = 0; i < I; i++) {
			if (i) s << ", ";
			s << ::UPP::AsString(data[i]);
		}
		s << "]";
		return s;
	}
	
	
	operator Point_<T>() const {
		static_assert(I == 2, "Losing information when converting to Point_<T>");
		return Point_<T>(data[0], data[1]);
	}
};


typedef Vec<float, 1> vec1;
typedef Vec<float, 2> vec2;
typedef Vec<float, 3> vec3;
typedef Vec<float, 4> vec4;

typedef Vec<int, 2> ivec2;
typedef Vec<int, 3> ivec3;
typedef Vec<int, 4> ivec4;


struct quat {
	vec4 data;
	
	quat() {}
	quat(const quat& q) {*this = q;}
	quat(float x, float y, float z, float w) : data(x,y,z,w) {}
	
	void operator=(const quat& q) {data = q.data;}
	
	void SetNull() {data.SetNull();}
	bool IsNull() const {return data.IsNull();}
	
	quat& SetIdentity() {data.SetIdentity(); return *this;}
	const float& operator[](int i) const {return data[i];}
	float& operator[](int i) {return data[i];}
	quat GetConjugate() const;
	quat GetInverse() const {return GetConjugate();}
	
	quat operator*(const quat& q) const;
	void operator*=(const quat& q) {quat n = *this * q; data = n.data;}
	
	String ToString() const {return data.ToString();}
};

template <class Unit, class M> inline void DeterminantNonSingle(Unit& det, const M& m) {
	det = 0;
	for(int c = 0; c < m.cols; c++)
		det += m[0][c] * m.GetCofactor(0, c);
}

template <class T, int R, int C> struct PartMatrix {
	typedef typename T::Unit Unit;
	
	static inline void Determinant(Unit& det, const T& m) {DeterminantNonSingle(det, m);}
	
};

template <class T> struct PartMatrix<T, 1, 1> {
	typedef typename T::Unit Unit;
	
	static inline void Determinant(Unit& det, const T& m) {det = m[0][0];}
	
};

template <class T> struct PartMatrix<T, 3, 3> {
	enum {X, Y, Z};
	
	typedef typename T::Unit Unit;
	
	static inline void Determinant(Unit& det, const T& m) {DeterminantNonSingle(det, m);}
	static inline void Adjoint(T& a, const T& m);
};

template <class T> struct PartMatrix<T, 4, 4> {
	enum {X, Y, Z, W};
	
	typedef typename T::Unit Unit;
	
	static inline void Determinant(Unit& det, const T& m);
	static inline void Adjoint(T& a, const T& m);
};



template <class T, int R, int C>
struct Matrix : Moveable<Matrix<T,R,C> > {
	Vec<T, C> data[R];
	
	typedef T Unit;
	typedef Vec<T, C> vec;
	typedef Vec<T, R> vecR;
	typedef Matrix<T, R, C> mat;
	typedef Matrix<T, R-1, C-1> MinorMatrix;
	typedef Vec<T, C-1> MinorVec;
	
	static const int rows = R;
	static const int cols = C;
	
	
	Matrix() {}
	Matrix(const Matrix& m) {*this = m;}
	Matrix(std::initializer_list<vec> list) {
		ASSERT(list.size() == R);
		int i = 0; for(auto& v : list) data[i++] = v;
	}
	
	void SetNull() {for(int i = 0; i < R; i++) data[i].SetNull();}
	bool IsNull() const {for(int i = 0; i < R; i++) if (!data[i].IsNull()) return false; return true;}
	
	void operator=(const Matrix& m) {memcpy(this, &m, sizeof(Matrix));}
	vec& operator[](int i) {STRICT_MTX_CHECK(i >= 0 && i < R); return data[i];}
	const vec& operator[](int i) const {STRICT_MTX_CHECK(i >= 0 && i < R); return data[i];}
	
	Matrix<T,C,R> GetTransposed() const {
		Matrix<T,C,R> ret;
		for(int c = 0; c < C; c++)
			for(int r = 0; r < R; r++)
				ret.data[c][r] = data[r][c];
		return ret;
	}
	MinorMatrix GetMinor(int row, int col) const {
		MinorMatrix ret;
		for(int r = 0; r < R-1; r++)
			for(int c = 0; c < C-1; c++)
				ret[r][c] = data[r < row ? r : r+1][c < col ? c : c+1];
		return ret;
	}
	T GetCofactor(int row, int col) const {
		return GetMinor(row, col).GetDeterminant() *
			((row + col) % 2 ? -1. : +1.);
	}
	Matrix GetAdjugated() const {
		Matrix ret;
		for(int r = 0; r < R; r++)
			for(int c = 0; c < C; c++)
				ret[r][c] = GetCofactor(r, c);
		return ret;
	}
	Matrix GetInverseTransposed() const {
		Matrix ret = GetAdjugated();
		T d = dot(ret[0], data[0]);
		ret /= d;
		return ret;
	}
	Matrix GetInverse() const {return GetInverseTransposed().GetTransposed();}
	Matrix GetAdjoint() const {Matrix dst; PartMatrix<Matrix,R,C>::Adjoint(dst, *this); return dst;}
	T GetDeterminant() const {T ret; PartMatrix<Matrix,R,C>::Determinant(ret, *this); return ret;}
	String ToString() const {
		String s;
		for(int r = 0; r < R; r++) {
			s << (r == 0 ? "[[\t" : " [\t");
			for(int c = 0; c < C; c++) {
				if (c) s << ",\t";
				s << ToString(data[r][c]);
			}
			s << (r == R-1 ? "\t]]" : "\t],\n");
		}
		return s;
	}
	
	void Clear() {for(int i = 0; i < R; i++) data[i] = 0;}
	
	Matrix& Transpose() {
		for(int c = 0; c < C; c++)
			for(int r = 0; r < R; r++)
				if (c != r)
					data[c][r] = data[r][c];
		return *this;
	}
	Matrix& SetColumn(int col, const vecR& v) {
		ASSERT(col >= 0 && col < C);
		for(int r = 0; r < R; r++)
			data[r][col] = v[r];
		return *this;
	}
	Matrix& SetConst(const T& value) {
		for(int r = 0; r < R; r++)
			data[r].SetConst(value);
		return *this;
	}
	Matrix& SetIdentity() {
		for(int r = 0; r < R; r++)
			for(int c = 0; c < C; c++)
				data[r].data[c] = (T)(r == c ? 1 : 0);
		return *this;
	}
	Matrix& SetTranspose(T x, T y, T z) {
		SetIdentity();
		data[3][0] = x;
		data[3][1] = y;
		data[3][2] = z;
		return *this;
	}
	Matrix& SetScale(float scale) {
		SetIdentity();
		data[0][0] = scale;
		data[1][1] = scale;
		data[2][2] = scale;
		return *this;
	}
	Matrix& SetRotation(int axis, float angle_rad) {
		static_assert(R == C && R >= 3, "Expecting square matrix of at least size 3");
		SetIdentity();
		T s = FastSin(angle_rad);
		T c = FastCos(angle_rad);
		if (axis == 0) {
			data[1][1] = c;
			data[1][2] = s;
			data[2][1] = -s;
			data[2][2] = c;
		}
		else if (axis == 1) {
			data[0][0] = c;
			data[0][2] = -s;
			data[2][0] = s;
			data[2][2] = c;
		}
		else if (axis == 2) {
			data[0][0] = c;
			data[0][1] = s;
			data[1][0] = -s;
			data[1][1] = c;
		}
		return *this;
	}
	Matrix& SetRotation(const vec3& axis, float angle_rad) {*this = GetRotation(axis, angle_rad); return *this;}
	Matrix& SetProjection(T fov_rad, T aspect, T near, T far) {
		T tan_half_fov = FastTan(fov_rad * 0.5);
		T fov_y = (T)1 / tan_half_fov;
		T fov_x = fov_y / aspect;
		Clear();
		data[0][0] = fov_x;
		data[1][1] = fov_y;
		data[2][2] = far / (far - near);
		data[2][3] = 1.0f;
		data[3][2] = -near * data[2][2];
		return *this;
	}
	Matrix& SetOrtographic(T left, T right, T bottom, T top, T near, T far) {
		Clear();
		data[0][0] = 2.0f / (right - left);
		data[1][1] = 2.0f / (top - bottom);
		data[2][2] = 1.0f / (far - near);
		data[3][0] = (left + right) / (left - right);
		data[3][1] = (top + bottom) / (bottom - top);
		data[3][2] = (near) / (near - far);
		data[3][3] = 1;
		return *this;
	}
	
	static Matrix GetRotation(const vec3& axis, float angle_rad) {
		T s = FastSin(angle_rad);
		T c = FastCos(angle_rad);
		T t = (T)1.0 - c;
		T x = axis[0], y = axis[1], z = axis[2];
		if (axis.GetLengthSquared() != (T)1.0) {
			T mul = (T)1 / axis.GetLength();
			x *= mul;
			y *= mul;
			z *= mul;
		}
		return Matrix {	vec{t*(x*x) + c, t*x*y + s*z, t*x*z - s*y, 0.0f},
						vec{t*x*y - s*z, t*(y*y) + c, t*y*z + s*x, 0.0f},
						vec{t*x*z + s*y, t*y*z - s*x, t*(z*z) + c, 0.0f},
						vec{0.0f,        0.0f,        0.0f,        1.0f}};
	}
	
	vecR operator*(const vec& src) const {
		vecR ret;
		for(int r = 0; r < R; r++) {
			const vec& row = data[r];
			T& v = ret[r];
			v = 0;
			for(int c = 0; c < C; c++)
				v += row[c] * src[c];
		}
		return ret;
	}
	
	bool operator==(const Matrix& m) const {
		for(int r = 0; r < R; r++)
			if (!(data[r] == m.data[r]))
				return false;
		return true;
	}
	bool operator!=(const Matrix& m) const {return !(*this == m);}
	bool IsClose(const Matrix& m) const {
		for(int r = 0; r < R; r++)
			for(int c = 0; c < C; c++)
				if (!TS::IsClose(data[r][c], m.data[r][c]))
					return false;
		return true;
	}
		
	
	Matrix& operator*=(const Matrix<T,R,C>& src) {*this = Multiply(src); return *this;}
	Matrix& operator*=(T v) {for(int i = 0; i < R; i++) data[i] *= v; return *this;}
	Matrix& operator/=(T v) {for(int i = 0; i < R; i++) data[i] /= v; return *this;}
	
	template<int C2> Matrix<T,R,C2> operator*(const Matrix<T,C,C2>& src) const {return Multiply(src);}
	
	template<int C2> Matrix<T,R,C2> Multiply(const Matrix<T,C,C2>& src) const {
		Matrix<T,R,C2> m;
		for(int r = 0; r < R; r++) {
			for(int c2 = 0; c2 < C2; c2++) {
				T& o = m[r][c2];
				o = 0;
				for(int c = 0; c < C; c++)
					o += data[r][c] * src.data[c][c2];
			}
		}
		return m;
	}
	Matrix Translate(const MinorVec& v) const {
		static_assert(R == C, "must be square matrix");
		Matrix m;
		m.SetIdentity();
		for(int i = 0; i < R-1; i++)
			m.data[i][R-1] = v.data[i];
		return m.Multiply(*this);
	}
	Matrix Scale(const MinorVec& v) const {
		static_assert(R == C, "must be square matrix");
		Matrix m;
		m.Clear();
		for(int i = 0; i < R-1; i++)
			m.data[i][i] = v[i];
		m.data[R-1][R-1] = 1;
		return m.Multiply(*this);
	}
	
	
	operator const vec2& () {static_assert(R == 1 && C == 2, "Expecting Matrix<1,2>"); return data[0];}
	operator const vec3& () {static_assert(R == 1 && C == 3, "Expecting Matrix<1,3>"); return data[0];}
	operator const vec4& () {static_assert(R == 1 && C == 4, "Expecting Matrix<1,4>"); return data[0];}
	
};


typedef Matrix<float, 1, 1> mat1;
typedef Matrix<float, 1, 2> mat12;
typedef Matrix<float, 1, 3> mat13;
typedef Matrix<float, 2, 1> mat21;
typedef Matrix<float, 2, 2> mat2;
typedef Matrix<float, 2, 3> mat23;
typedef Matrix<float, 3, 1> mat31;
typedef Matrix<float, 3, 2> mat32;
typedef Matrix<float, 3, 3> mat3;
typedef Matrix<float, 4, 4> mat4;
typedef Matrix<float, 4, 3> mat43;


inline mat12 AsMatrix(const vec2& v) {return mat12 {v};}
inline mat13 AsMatrix(const vec3& v) {return mat13 {v};}
inline mat21 AsMatrixTrans(const vec2& v) {return mat21 { vec1{v[0]}, vec1{v[1]} };}
inline mat31 AsMatrixTrans(const vec3& v) {return mat31 { vec1{v[0]}, vec1{v[1]}, vec1{v[2]} };}


template <class T> inline T PartVec<T,2>::GetCrossProduct(const T& a, const T& b) {
	if (a == b)
		return a * -1;
	typename T::Unit z = 1;
	T r;
    r[0] =  ( a[1] * z    ) - ( z    * b[1] );
    r[1] =  ( z    * b[0] ) - ( a[0] * z    );
    return r;
}

template <class T> inline T PartVec<T,3>::GetCrossProduct(const T& a, const T& b) {
	T r;
    r[0] =  ( a[1] * b[2] ) - ( a[2] * b[1] );
    r[1] =  ( a[2] * b[0] ) - ( a[0] * b[2] );
    r[2] =  ( a[0] * b[1] ) - ( a[1] * b[0] );
    return r;
}

template<class T> inline void PartMatrix<T,4,4>::Determinant(Unit& det, const T& m) {
	det =	+ m[X][X] * Determinant3 ( m[Y][Y], m[Z][Y], m[W][Y], m[Y][Z], m[Z][Z], m[W][Z], m[Y][W], m[Z][W], m[W][W] )
			- m[X][Y] * Determinant3 ( m[Y][X], m[Z][X], m[W][X], m[Y][Z], m[Z][Z], m[W][Z], m[Y][W], m[Z][W], m[W][W] )
			+ m[X][Z] * Determinant3 ( m[Y][X], m[Z][X], m[W][X], m[Y][Y], m[Z][Y], m[W][Y], m[Y][W], m[Z][W], m[W][W] )
			- m[X][W] * Determinant3 ( m[Y][X], m[Z][X], m[W][X], m[Y][Y], m[Z][Y], m[W][Y], m[Y][Z], m[Z][Z], m[W][Z] );
}

template<class T> inline void PartMatrix<T,4,4>::Adjoint(T& a, const T& m) {
	a[X][X]  =  Determinant3 ( m[Y][Y], m[Z][Y], m[W][Y], m[Y][Z], m[Z][Z], m[W][Z], m[Y][W], m[Z][W], m[W][W] );
    a[Y][X]  = -Determinant3 ( m[Y][X], m[Z][X], m[W][X], m[Y][Z], m[Z][Z], m[W][Z], m[Y][W], m[Z][W], m[W][W] );
    a[Z][X]  =  Determinant3 ( m[Y][X], m[Z][X], m[W][X], m[Y][Y], m[Z][Y], m[W][Y], m[Y][W], m[Z][W], m[W][W] );
    a[W][X]  = -Determinant3 ( m[Y][X], m[Z][X], m[W][X], m[Y][Y], m[Z][Y], m[W][Y], m[Y][Z], m[Z][Z], m[W][Z] );

    a[X][Y]  = -Determinant3 ( m[X][Y], m[Z][Y], m[W][Y], m[X][Z], m[Z][Z], m[W][Z], m[X][W], m[Z][W], m[W][W] );
    a[Y][Y]  =  Determinant3 ( m[X][X], m[Z][X], m[W][X], m[X][Z], m[Z][Z], m[W][Z], m[X][W], m[Z][W], m[W][W] );
    a[Z][Y]  = -Determinant3 ( m[X][X], m[Z][X], m[W][X], m[X][Y], m[Z][Y], m[W][Y], m[X][W], m[Z][W], m[W][W] );
    a[W][Y]  =  Determinant3 ( m[X][X], m[Z][X], m[W][X], m[X][Y], m[Z][Y], m[W][Y], m[X][Z], m[Z][Z], m[W][Z] );

    a[X][Z]  =  Determinant3 ( m[X][Y], m[Y][Y], m[W][Y], m[X][Z], m[Y][Z], m[W][Z], m[X][W], m[Y][W], m[W][W] );
    a[Y][Z]  = -Determinant3 ( m[X][X], m[Y][X], m[W][X], m[X][Z], m[Y][Z], m[W][Z], m[X][W], m[Y][W], m[W][W] );
    a[Z][Z]  =  Determinant3 ( m[X][X], m[Y][X], m[W][X], m[X][Y], m[Y][Y], m[W][Y], m[X][W], m[Y][W], m[W][W] );
    a[W][Z]  = -Determinant3 ( m[X][X], m[Y][X], m[W][X], m[X][Y], m[Y][Y], m[W][Y], m[X][Z], m[Y][Z], m[W][Z] );

    a[X][W]  = -Determinant3 ( m[X][Y], m[Y][Y], m[Z][Y], m[X][Z], m[Y][Z], m[Z][Z], m[X][W], m[Y][W], m[Z][W] );
    a[Y][W]  =  Determinant3 ( m[X][X], m[Y][X], m[Z][X], m[X][Z], m[Y][Z], m[Z][Z], m[X][W], m[Y][W], m[Z][W] );
    a[Z][W]  = -Determinant3 ( m[X][X], m[Y][X], m[Z][X], m[X][Y], m[Y][Y], m[Z][Y], m[X][W], m[Y][W], m[Z][W] );
    a[W][W]  =  Determinant3 ( m[X][X], m[Y][X], m[Z][X], m[X][Y], m[Y][Y], m[Z][Y], m[X][Z], m[Y][Z], m[Z][Z] );
}






template <class T>
class DMatrix : Moveable<DMatrix<T>> {
	
public:
	using type = T;
	Vector<T> data;
	int cols;
	int rows;
	int channels;
	
    DMatrix() : cols(0), rows(0), channels(0) {}
    
    DMatrix(int c, int r, int ch) {
        ASSERT(c > 0 && r > 0 && ch > 0);
        this->cols = c;
        this->rows = r;
        this->channels = ch;
        allocate();
    }
    DMatrix(int c, int r, int ch, const Vector<T>& data) {
        ASSERT(c > 0 && r > 0 && ch > 0);
        this->cols = c;
        this->rows = r;
        this->channels = ch;
        this->data <<= data;
    }
    
    DMatrix(const DMatrix& s) {*this = s;}
    
    void operator=(const DMatrix& s) {
        cols = s.cols;
        rows = s.rows;
        channels = s.channels;
		data <<= s.data;
    }
    void allocate() {
        data.SetCount(cols * rows * channels, 0);
    }
    
    void copy_to(DMatrix& other) const {
        ASSERT(other.cols == cols);
        ASSERT(other.rows == rows);
        ASSERT(other.channels == channels);
        other.data <<= data;
    }
    
    void SetSize(int c, int r, int ch) {
        this->cols = c;
        this->rows = r;
        this->channels = ch;
        allocate();
    }
	
	bool IsEmpty() const {
		return cols == 0 || rows == 0 || channels == 0;
	}
	
};

using ByteMat = DMatrix<byte>;
using FloatMat = DMatrix<float>;



template <class T>
struct Pyramid : Moveable<Pyramid<T>> {
	using Mat = DMatrix<T>;
	
	Vector<Mat> data;
	
	Pyramid() {}
	Pyramid(int w, int h, int levels) {SetSize(w, h, levels);}
	Pyramid(const Pyramid& p) {*this = p;}
	
	
	int GetLevels() const {return data.GetCount();}
	bool IsEmpty() const {return data.IsEmpty();}
	
	Mat& operator[](int i) {return data[i];}
	
	void SetLevels(int i) {data.SetCount(i);}
	
	void SetSize(int w, int h, int channels, int levels) {
		data.SetCount(levels);
		int i = levels;
        while(--i >= 0) {
            data[i].SetSize(w >> i, h >> i, channels);
        }
	}
	
	void Build(const Mat& input, bool skip_first_level=false) {
		ASSERT(data.GetCount());
		if (data.IsEmpty())
			return;
		int i = 2;
		const Mat* a = &input;
		Mat* b = &data[0];
        if (!skip_first_level) {
            *b = *a;
        }
        b = &data[1];
        DownsamplePyramid(*a, *b);
        for(; i < data.GetCount(); ++i) {
            a = b;
            b = &data[i];
            DownsamplePyramid(*a, *b);
        }
	}
	
	
};

typedef Pyramid<uint8> pyra8;
typedef Pyramid<float> pyraf;


template <class T>
void DownsamplePyramid(const DMatrix<T>& src, DMatrix<T>& dst, int sx=0, int sy=0) {
	int w = src.cols;
	int h = src.rows;
	int w2 = w >> 1;
	int h2 = h >> 1;
	int _w2 = w2 - (sx << 1);
	int _h2 = h2 - (sy << 1);
	int sptr = sx + sy * w;
	int dptr = 0;
	
	dst.SetSize(w2, h2, src.channels);
	
	const auto& src_d = src.data;
	auto& dst_d = dst.data;
	
	for (int y = 0; y < _h2; ++y) {
		int sline = sptr;
		int dline = dptr;
		int x;
		for (x = 0; x <= _w2 - 2; x += 2, dline += 2, sline += 4) {
			dst_d[dline] = (src_d[sline] + src_d[sline+1] +
							src_d[sline+w] + src_d[sline+w+1] + 2) >> 2;
			dst_d[dline+1] = (src_d[sline+2] + src_d[sline+3] +
							  src_d[sline+w+2] + src_d[sline+w+3] + 2) >> 2;
		}
		for (; x < _w2; ++x, ++dline, sline += 2) {
			dst_d[dline] = (src_d[sline] + src_d[sline+1] +
							src_d[sline+w] + src_d[sline+w+1] + 2) >> 2;
		}
		sptr += w << 1;
		dptr += w2;
	}
}








struct Square : Moveable<Square> {
	vec3 tl, tr, br, bl;
	
};


NAMESPACE_TOPSIDE_END


#include "Matrix.inl"


#endif
