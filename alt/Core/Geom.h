#ifndef _CoreAlt_Geom_h_
#define _CoreAlt_Geom_h_

NAMESPACE_UPP_BEGIN



template <class T>
struct Point_ : Moveable<Point_<T>> {
	T x = 0, y = 0;

	Point_() {}

	Point_(T x, T y) : x(x), y(y) {}

	Point_(const Point_& pt) {
		*this = pt;
	}




	double Length() { return sqrt(x * x + y * y); }
	double Slope() { return y / x; }

	Point_ operator-() const { return Point_(-x, -y); }
	Point_ operator*(double k) const { return Point_(x * k, y * k); }
	Point_ operator/(double k) const { return Point_(x / k, y / k); }

	Point_ operator+(const Point_& b) const { return Point_(x + b.x, y + b.y); }
	Point_ operator-(const Point_& b) const { return Point_(x - b.x, y - b.y); }
	Point_ operator*(const Point_& b) const { return Point_(x * b.x, y * b.y); }
	Point_ operator/(const Point_& b) const { return Point_(x / b.x, y / b.y); }


	template <class V>
	Point_& operator=(const V& b) {
		x = (T)b.x;
		y = (T)b.y;
		return *this;
	}

	Point_& operator+=(const Point_& b) {
		x = (T)(x + b.x);
		y = (T)(y + b.y);
		return *this;
	}

	Point_& operator-=(const Point_& b) {
		x = (T)(x - b.x);
		y = (T)(y - b.y);
		return *this;
	}

	Point_& operator*=(const double k) {
		x = (T)(x * k);
		y = (T)(y * k);
		return *this;
	}

	Point_& operator/=(const double k) {
		x = (T)(x / k);
		y = (T)(y / k);
		return *this;
	}

	static void Dot(const Point_& a, const Point_& b, Point_& o) {
		//dot product: o = a dot b
		o.x = a.x * b.x;
		o.y = a.y * b.y;
	}

	Point_ DotProd(const Point_& b) const {
		//return dot product
		return Point(x * b.x, y * b.y);
	}
	
	String ToString() const {return "Point(" + IntStr(x) + ", " + IntStr(y) + ")";}
	
	operator Point_<int>() const {return Point_<int>(x,y);}
	operator Point_<double>() const {return Point_<double>(x,y);}
	
	bool	IsNull() const {return IsNull(x) || IsNull(y);}
	void	SetNull() const {SetNull(x); SetNull(y);}
	
};


typedef Point_<int> Point;
typedef Point_<float> PointF32;
typedef Point_<double> Pointf;



template <class T>
double GetSignedArea(const T& a, const T& b, const T& c) {
	double area = 0;
	area += (a.x * b.y - b.x * a.y);
	area += (b.x * c.y - c.x * b.y);
	area += (c.x * a.y - a.x * c.y);
	return area * 0.5;
}


template <class T>
struct Size_ : Moveable<Size_<T>> {
	T cx = 0, cy = 0;

	Size_() {}
	Size_(const Size_& sz) { *this = sz; }
	Size_(T cx, T cy) : cx(cx), cy(cy) {}
	
	void Clear() {cx = 0; cy = 0;}
	bool IsEmpty() const {return cx == 0 && cy == 0;}
	bool IsPositive() const {return cx > 0 && cy > 0;}
	bool IsEqual(const Size_& sz) const {return cx == sz.cx && cy == sz.cy;}
	
	bool operator==(const Size_& sz) {return IsEqual(sz);}
	bool operator!=(const Size_& sz) {return !IsEqual(sz);}
	void operator=(const Size_& sz) {
		cx = sz.cx;
		cy = sz.cy;
	}

	Size_& operator+=(Size_ p) { cx += p.cx; cy += p.cy; return *this; }
	Size_& operator+=(double t) { cx += t;    cy += t;    return *this; }
	Size_& operator-=(Size_ p) { cx -= p.cx; cy -= p.cy; return *this; }
	Size_& operator-=(double t) { cx -= t;    cy -= t;    return *this; }
	Size_& operator*=(Size_ p) { cx *= p.cx; cy *= p.cy; return *this; }
	Size_& operator*=(double t) { cx *= t;    cy *= t;    return *this; }
	Size_& operator/=(Size_ p) { cx /= p.cx; cy /= p.cy; return *this; }
	Size_& operator/=(double t) { cx /= t;    cy /= t;    return *this; }
	Size_& operator<<=(int sh) { cx <<= sh;   cy <<= sh;   return *this; }
	Size_& operator>>=(int sh) { cx >>= sh;   cy >>= sh;   return *this; }
	
	Size_ operator*(double v) {return Size_(cx * v, cy * v);}
	Size_ operator/(double v) {return Size_(cx * v, cy * v);}
	String ToString() const {return "Size(" + IntStr(cx) + ", " + IntStr(cy) + ")";}
	
	operator Size_<int>() const {return Size_<int>(cx,cy);}
	operator Size_<double>() const {return Size_<double>(cx,cy);}
	
	bool	IsNull() const {return IsNull(cx) || IsNull(cy);}
	void	SetNull() const {SetNull(cx); SetNull(cy);}
	
};

template <class T>
bool operator==(const Size_<T>& a, const Size_<T>& b) {
	return a.cx == b.cx && a.cy == b.cy;
}

typedef Size_<int> Size;
typedef Size_<float> SizeF32;
typedef Size_<double> Sizef;



template <class T>
struct Rect_ : Moveable<Rect_<T>> {
	T left = 0, top = 0, right = 0, bottom = 0;

	typedef Point_<T>  Pt;
	typedef Size_<T>   Sz;

	Rect_() {}
	Rect_(const Rect_& r) { *this = r; }
	Rect_(const Size_<T>& sz) { right = sz.cx; bottom = sz.cy; }
	Rect_(T l, T t, T r, T b) : top(t), left(l), bottom(b), right(r) {}

	bool IsEqual(const Rect_& r) const {return top == r.top && left == r.left && bottom == r.bottom && right == r.right;}
	
	bool operator==(const Rect_& r) {return IsEqual(r);}
	bool operator!=(const Rect_& r) {return !IsEqual(r);}
	void operator=(const Rect_& src) {
		top = src.top;
		left = src.left;
		bottom = src.bottom;
		right = src.right;
	}
	//bool operator!=(const Rect_& src) { return !(*this == src); }

	Point TopLeft() const { return Point(left, top); }
	Point TopRight() const { return Point(right, top); }
	Point BottomRight() const { return Point(right, bottom); }
	Point BottomLeft() const { return Point(left, bottom); }

	T GetWidth() const { return right - left; }
	T GetHeight() const { return bottom - top; }
	T Width() const { return right - left; }
	T Height() const { return bottom - top; }
	Sz GetSize() const { return Sz(Width(), Height()); }
	bool Contains(const Point_<T>& pt) const {return pt.x >= left && pt.x <= right && pt.y >= top && pt.y <= bottom;}
	bool Contains(const Rect_<T>& r) const {return Contains(TopLeft()) && Contains(TopRight()) && Contains(BottomRight()) && Contains(BottomLeft());}
	bool Intersects(const Rect_<T>& r) const {
		if(IsNull() || r.IsNull()) return false;
		return r.right >= left && r.bottom >= top && r.left <= right && r.top <= bottom;
	}
	Point_<T> CenterPoint() const {return Point_<T>((right+left)/(T)2, (top+bottom)/(T)2);}
	
	void   InflateHorz(T dx) { left -= dx; right += dx; }
	void   InflateVert(T dy) { top -= dy; bottom += dy; }
	void   Inflate(T dx, T dy) { InflateHorz(dx); InflateVert(dy); }
	void   Inflate(Sz sz) { Inflate(sz.cx, sz.cy); }
	void   Inflate(T dxy) { Inflate(dxy, dxy); }
	void   Inflate(T l, T t, T r, T b) { left -= l; top -= t; right += r; bottom += b; }
	void   Inflate(const Rect_& r) { Inflate(r.left, r.top, r.right, r.bottom); }

	void   DeflateHorz(T dx) { InflateHorz(-dx); }
	void   DeflateVert(T dy) { InflateVert(-dy); }
	void   Deflate(T dx, T dy) { Inflate(-dx, -dy); }
	void   Deflate(Sz sz) { Inflate(-sz); }
	void   Deflate(T dxy) { Inflate(-dxy); }
	void   Deflate(T l, T t, T r, T b) { Inflate(-l, -t, -r, -b); }
	void   Deflate(const Rect_& r) { Deflate(r.left, r.top, r.right, r.bottom); }

	operator Rect_<int>() const {return Rect_<int>(left,top,right,bottom);}
	operator Rect_<double>() const {return Rect_<double>(left,top,right,bottom);}
	
	bool	IsNull() const {return Upp::IsNull(left) || Upp::IsNull(top) || Upp::IsNull(right) || Upp::IsNull(bottom);}
	void	SetNull() const {Upp::SetNull(left); Upp::SetNull(top); Upp::SetNull(right); Upp::SetNull(bottom);}
	
};

template <class T>
bool operator==(const Rect_<T>& a, const Rect_<T>& b) {
	return
		a.top    == b.top &&
		a.left   == b.left &&
		a.bottom == b.bottom &&
		a.right  == b.right;
}

typedef Rect_<int> Rect;
typedef Rect_<double> Rectf;


inline Rect RectC(int x, int y, int w, int h) { return Rect(x, y, x + w, y + h); }




template <class T>
struct Triangle_ : Moveable<Triangle_<T>> {
	typedef Point_<T> Pt;

	Pt a, b, c;

	Triangle_() {}
	Triangle_(const Triangle_& t) { *this = t; }
	void operator=(const Triangle_& t) {
		a = t.a;
		b = t.b;
		c = t.c;
	}
	void Set(const Pt& a, const Pt& b, const Pt& c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

typedef Triangle_<int> Triangle;
typedef Triangle_<float> TriangleF32;
typedef Triangle_<double> Trianglef;



template <class T>
T GetOffsets(const T& a, const T& b, double width) {
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	double len = sqrt(dx * dx + dy * dy);
	double scale = width / (2 * len);
	return T(-scale * dy, scale * dx);
}



Pointf Intersect(const Pointf& a, const Pointf& b, const Pointf& c, const Pointf& d);


NAMESPACE_UPP_END

#endif
