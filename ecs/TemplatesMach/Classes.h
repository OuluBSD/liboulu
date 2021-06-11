#ifndef _TemplatesMach_Classes_h_
#define _TemplatesMach_Classes_h_

NAMESPACE_TOPSIDE_BEGIN

class Entity;
class Viewable;
class Transform;
using ViewableRef			= Ref<Viewable,				RefParent1<Entity>>;
using TransformRef			= Ref<Transform,			RefParent1<Entity>>;




//#define TYPE(type_code, type_sz, type_signed, type_flt, type_aligned, endianess, pack_code, pack_sz)

#define TYPE_LIST(endianess, pack_code, pack_sz) \
	TYPE(U8,	1,	0,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(S8,	1,	1,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(U16,	2,	0,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(S16,	2,	1,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(U24,	3,	0,	0,	0,	endianess, pack_code, pack_sz) \
	TYPE(S24,	3,	1,	0,	0,	endianess, pack_code, pack_sz) \
	TYPE(U32,	4,	0,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(S32,	4,	1,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(U64,	8,	0,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(S64,	8,	1,	0,	1,	endianess, pack_code, pack_sz) \
	TYPE(FLT,	4,	1,	1,	1,	endianess, pack_code, pack_sz) \
	TYPE(DBL,	8,	1,	1,	1,	endianess, pack_code, pack_sz)

#define SAMPLE_LIST \
	TYPE_LIST(LE,,) \
	TYPE_LIST(BE,,)

#define ENDIAN_TYPE_LIST(pack_code, pack_sz) \
	TYPE_LIST(LE, pack_code, pack_sz) \
	TYPE_LIST(BE, pack_code, pack_sz)

#define PACKED_SAMPLE_LIST \
	ENDIAN_TYPE_LIST(A, 1) \
	ENDIAN_TYPE_LIST(AB, 2) \
	ENDIAN_TYPE_LIST(ABC, 3) \
	ENDIAN_TYPE_LIST(ABCD, 4) \
	ENDIAN_TYPE_LIST(BA, 2) \
	ENDIAN_TYPE_LIST(CBA, 3) \
	ENDIAN_TYPE_LIST(DCBA, 4)


class BinarySample : RTTIBase {
	RTTI_DECL0(BinarySample)
	
public:
	static const int def_sample_rate = 1;
	

		
	typedef enum {
		INVALID,
		DEV_INTERNAL,
		#define TYPE(type_code, type_sz, type_signed, type_flt, type_aligned, endianess, pack_code, pack_sz) \
			type_code##_##endianess ,
		SAMPLE_LIST
		#undef TYPE
		#define TYPE(type_code, type_sz, type_signed, type_flt, type_aligned, endianess, pack_code, pack_sz) \
			type_code##_##endianess##_##pack_code ,
		PACKED_SAMPLE_LIST
		#undef TYPE
		TYPE_COUNT,
		
		DEFAULT = U8_LE,
	} Type;
	
	template <class T> static Type GetSampleType();
	template <class T> static bool IsSampleType(Type t) {return t == GetSampleType<T>();}
	
	
	static void Clear(Type& t) {t = INVALID;}
	static String ToString(Type t);
	static bool IsCopyCompatible(Type a, Type b) {return a == b;}
	static int GetSize(Type t);
	static int GetPackedSingleSize(Type t);
	static int GetPackedCount(Type t);
	static bool IsUnsigned(Type t);
	static bool IsSigned(Type t);
	static bool IsFloating(Type t);
	static bool IsDecimal(Type t);
	static bool IsLittleEndian(Type t);
	static bool IsBigEndian(Type t);
	static bool IsValid(Type t) {return (int)t > (int)INVALID && (int)t < (int)TYPE_COUNT;}
};

class SoundSample : public BinarySample {
	RTTI_DECL1(SoundSample, BinarySample)
	
public:
	static const int def_sample_rate = 1024;
	
};


class LightSampleFD : public BinarySample {
	RTTI_DECL1(LightSampleFD, BinarySample)
	
public:
	
	#define LTFD_SMPL_LIST \
		LTFD_SMPL(R_U8_LE,		U8_LE_A) \
		LTFD_SMPL(RG_U8_LE,		U8_LE_AB) \
		LTFD_SMPL(RGB_U8_LE,	U8_LE_ABC) \
		LTFD_SMPL(RGBA_U8_LE,	U8_LE_ABCD) \
		LTFD_SMPL(BGR_U8_LE,	U8_LE_CBA) \
		LTFD_SMPL(R_FLT_LE,		FLT_LE_A) \
		LTFD_SMPL(RG_FLT_LE,	FLT_LE_AB) \
		LTFD_SMPL(RGB_FLT_LE,	FLT_LE_ABC) \
		LTFD_SMPL(RGBA_FLT_LE,	FLT_LE_ABCD) \
		LTFD_SMPL(BGR_FLT_LE,	FLT_LE_CBA)
	
	#define LTFD_SMPL(a,b) static const Type a = b;
	LTFD_SMPL_LIST
	#undef LTFD_SMPL
	
};


/*class EventSample : public BinarySample
{
public:
	
	static const DefaultType = U32_LE_ABCD;
	
};*/


class EventSample : RTTIBase {
	RTTI_DECL0(EventSample)

public:
	static const int def_sample_rate = 1;

	#define DEV_SMPL_LIST \
		DEV_SMPL(CTRL_EVENT)

	typedef enum {
		INVALID,
		DEV_INTERNAL,
		#define DEV_SMPL(x) x ,
		DEV_SMPL_LIST
		#undef DEV_SMPL
		TYPE_COUNT,
		
		DEFAULT = CTRL_EVENT
	} Type;


	static void Clear(Type& t) {t = INVALID;}
	static bool IsCopyCompatible(Type a, Type b) {return a == b;}
	static String ToString(Type t);
	static int GetSize(Type t);
	static bool IsValid(Type t) {return (int)t > (int)INVALID && (int)t < (int)TYPE_COUNT;}
};


class OrderSample : RTTIBase {
	RTTI_DECL0(OrderSample)

public:
	static const int def_sample_rate = 1;

	#define ORDER_SMPL_LIST \
		ORDER_SMPL(AUDIO_ORDER)

	typedef enum {
		INVALID,
		DEV_INTERNAL,
		#define ORDER_SMPL(x) x ,
		ORDER_SMPL_LIST
		#undef ORDER_SMPL
		TYPE_COUNT,
		
		DEFAULT = INVALID
	} Type;


	static void Clear(Type& t) {t = INVALID;}
	static bool IsCopyCompatible(Type a, Type b) {return a == b;}
	static String ToString(Type t);
	static int GetSize(Type t);
	static bool IsValid(Type t) {return (int)t > (int)INVALID && (int)t < (int)TYPE_COUNT;}
};


class ReceiptSample : RTTIBase {
	RTTI_DECL0(ReceiptSample)

public:
	static const int def_sample_rate = 1;

	#define RECEIPT_SMPL_LIST \
		RECEIPT_SMPL(AUDIO_RECEIPT)

	typedef enum {
		INVALID,
		DEV_INTERNAL,
		#define RECEIPT_SMPL(x) x ,
		RECEIPT_SMPL_LIST
		#undef RECEIPT_SMPL
		TYPE_COUNT,
		
		DEFAULT = INVALID
	} Type;


	static void Clear(Type& t) {t = INVALID;}
	static bool IsCopyCompatible(Type a, Type b) {return a == b;}
	static String ToString(Type t);
	static int GetSize(Type t);
	static bool IsValid(Type t) {return (int)t > (int)INVALID && (int)t < (int)TYPE_COUNT;}
};







#define DUMMY_SAMPLE(x) \
	class x : public BinarySample { \
		RTTI_DECL1(x, BinarySample) \
	};
		
DUMMY_SAMPLE(HumanSample)
DUMMY_SAMPLE(SpaceSample)
DUMMY_SAMPLE(VertexSample)
DUMMY_SAMPLE(TexLocSample)
DUMMY_SAMPLE(BoneSample)
DUMMY_SAMPLE(MidiSample)
DUMMY_SAMPLE(PhysicsSample)
DUMMY_SAMPLE(MaterialSample)
DUMMY_SAMPLE(MaterialSampleFD)



template <int> struct DimBase;
template<> struct DimBase<1> : RTTIBase {
	RTTI_DECL0(DimBase<1>)
	static const int n = 1;
	union {
		int res[1];
		int channels;
		int width;
		int length;
	};
	
	using DimArg = int;
	
	DimBase() {Clear();}
	DimBase(const DimBase& b) {*this = b;}
	void SetDim(DimArg a) {res[0] = a;}
	void SetDefault() {for(int i = 0; i < n; i++) res[i] = 1;}
	void Clear() {for(int i = 0; i < n; i++) res[i] = 0;}
	String ToString() const {return "len(" + IntStr(channels) + ")";}
	bool IsSame(const DimBase& b) const {return res[0] == b.res[0];}
	int GetArea() const {return res[0];}
	bool IsValid() const {for(int i = 0; i < n; i++) if (res[i] <= 0) return false; return true;}
	DimBase& operator=(const DimBase& b) {for(int i = 0; i < n; i++) res[i] = b.res[i]; return *this;}
};

template<> struct DimBase<2> : RTTIBase {
	RTTI_DECL0(DimBase<2>)
	static const int n = 2;
	union {
		int res[2];
		Size size;
		union {
			int channels;
			int sources;
		};
		union {
			int width;
			int height;
		};
	};
	int width_pad;
	
	using DimArg = Size;
	
	DimBase() {Clear();}
	DimBase(const DimBase& b) {*this = b;}
	
	void SetDim(DimArg a) {size = a;}
	void SetDefault() {for(int i = 0; i < n; i++) res[i] = 1;}
	void Clear() {
		for(int i = 0; i < n; i++) res[i] = 0;
		width_pad = 0;
	}
	String ToString() const {return size.ToString();}
	bool IsSame(const DimBase& b) const {return res[0] == b.res[0] && res[1] == b.res[1];}
	int GetArea() const {return res[0] * res[1];}
	bool IsValid() const {for(int i = 0; i < n; i++) if (res[i] <= 0) return false; return true;}
	DimBase& operator=(const DimBase& b) {
		for(int i = 0; i < n; i++) res[i] = b.res[i];
		width_pad = b.width_pad;
		return *this;
	}
	
	void SetLinePadding(int bytes) {ASSERT(bytes >= 0); width_pad = bytes;}
	
};

template<> struct DimBase<3> : RTTIBase {
	RTTI_DECL0(DimBase<3>)
	static const int n = 3;
	union {
		int res[3];
		Size3 size;
		union {
			int channels;
			int sources;
			int variants;
		};
		union {
			int width;
			int height;
			int depth;
		};
	};
	
	using DimArg = Size3;
	
	DimBase() {Clear();}
	DimBase(const DimBase& b) {*this = b;}
	
	void SetDim(DimArg a) {size = a;}
	void SetDefault() {for(int i = 0; i < n; i++) res[i] = 1;}
	String ToString() const {return size.ToString();}
	void Clear() {for(int i = 0; i < n; i++) res[i] = 0;}
	bool IsSame(const DimBase& b) const {return res[0] == b.res[0] && res[1] == b.res[1] && res[2] == b.res[2];}
	int GetArea() const {return res[0] * res[1] * res[2];}
	bool IsValid() const {for(int i = 0; i < n; i++) if (res[i] <= 0) return false; return true;}
	DimBase& operator=(const DimBase& b) {for(int i = 0; i < n; i++) res[i] = b.res[i]; return *this;}
};


class OnceBase : RTTIBase {
	RTTI_DECL0(OnceBase)
public:
	
	static const int def_sample_rate = 1;
	
	void Clear() {}
	void SetTimeSeries(int,int) {Panic("never");}
	//void SetDeviceInternal() {}
	
	int GetSampleRate() const {return 1;}
	bool IsSame(const OnceBase& b) const {return true;}
	String ToString() const {return "OnceBase";}
	bool IsValid() const {return true;}
	
};

class SparseTimeSeriesBase : RTTIBase {
	RTTI_DECL0(SparseTimeSeriesBase)
public:
	static const int def_sample_rate = 1;
	
	void Clear() {}
	void SetTimeSeries(int,int) {Panic("never");}
	//void SetDeviceInternal() {}
	
	int GetSampleRate() const {return 1;}
	bool IsSame(const SparseTimeSeriesBase& b) const {return true;}
	String ToString() const {return "SparseTimeSeriesBase";}
	bool IsValid() const {return true;}
	
};

class TimeSeriesBase : RTTIBase {
	RTTI_DECL0(TimeSeriesBase)
public:
	int freq = 0;
	int sample_rate = 0;
	
	
	void Clear() {freq = 0; sample_rate = 0;}
	void SetTimeSeries(int freq, int sample_rate) {this->freq = freq; this->sample_rate = sample_rate;}
	void SetFPS(int fps, int sample_rate=1) {freq = fps * sample_rate; this->sample_rate = sample_rate;}
	//void SetDeviceInternal() {freq = 1; sample_rate = 1;}
	
	String ToString() const {return "freq: " + IntStr(freq) + ", sample-rate: " + IntStr(sample_rate);}
	bool IsPlaybackCompatible(const TimeSeriesBase& b) const {return b.freq == freq;}
	bool IsSame(const TimeSeriesBase& b) const {
		return	b.freq == freq &&
				b.sample_rate == sample_rate;
	}
	bool IsValid() const {return freq > 0 && sample_rate > 0;}
	double GetFrameSeconds() const {return (double)sample_rate / (double)freq;}
	int GetSampleRate() const {return sample_rate;}
	int GetFrequency() const {return freq;}
	double GetFPS() const {return freq / sample_rate;}
	
	void operator=(const TimeSeriesBase& c) {
		freq = c.freq;
		sample_rate = c.sample_rate;
	}
	
};

template <class T>
class SampleBase : RTTIBase {
	RTTI_DECL0(SampleBase)
public:
	using Sample = T;
	using SampleType = typename T::Type;
	
	SampleType type;
	
	
	void Clear() {Sample::Clear(type);}
	void SetType(SampleType t) {type = t;}
	void SetDefault() {type = Sample::DEFAULT;}
	
	String ToString() const {return Sample::ToString(type);}
	int GetSampleSize() const {return Sample::GetSize(type);}
	bool IsSampleFloat() const {return Sample::IsFloating(type);}
	bool IsSampleSigned() const {return Sample::IsSigned(type);}
	bool IsSampleBigEndian() const {return Sample::IsBigEndian(type);}
	bool IsCopyCompatible(const SampleBase& b) const {return Sample::IsCopyCompatible(type, b.type);}
	bool IsValid() const {return Sample::IsValid(type);}
	bool IsDeviceInternal() const {return type == SampleType::DEV_INTERNAL;}
	template <class K> bool IsSampleType() const {return Sample::template IsSampleType<K>(type);}
	int GetPackedSingleSize() const {return Sample::GetPackedSingleSize(type);}
	int GetPackedCount() const {return Sample::GetPackedCount(type);}
	SampleType GetType() const {return type;}
	
	void operator=(const SampleBase& c) {
		type = c.type;
	}
	
};

struct DevBase : RTTIBase {
	TypeCls dev_spec = 0;
	
public:
	RTTI_DECL0(DevBase)
	
	void Clear() {dev_spec = 0;}
	void SetDevSpec(TypeCls t) {dev_spec = t;}
	void operator=(const DevBase& b) {dev_spec = b.dev_spec;}
	
	template <class DevSpec>
	void SetDevSpec() {
		dev_spec = AsTypeCls<DevSpec>();
	}
	
	TypeCls GetDevSpec() const {return dev_spec;}
	bool IsDeviceSpecific() const {return dev_spec != 0;}
	bool IsSame(const DevBase& f) const {return dev_spec == f.dev_spec;}
	bool IsValid() const {return dev_spec != 0;}
	
	String ToString() const;
};






#define COMBINE_CLASS(dim, post, d) \
	template <class T> \
	class d##dim##post : \
		public post##Base, \
		public SampleBase<T>, \
		public DimBase<dim>, \
		public DevBase \
	{ \
	 \
	public: \
		RTTI_DECL3(d##dim##post, post##Base, SampleBase<T>, DimBase<dim>) \
		using Class = d##dim##post<T>; \
		using SampleType = typename SampleBase<T>::Sample::Type; \
		using DimArg = typename DimBase<dim>::DimArg; \
		d##dim##post() {Clear();} \
		d##dim##post(const d##dim##post& s) {*this = s;} \
		d##dim##post(TypeCls dev_spec, SampleType type, DimArg dim_, int freq=0, int sample_rate=0) {Set(dev_spec, type, dim_, freq, sample_rate);} \
		static const int def_sample_rate = T::def_sample_rate; \
		bool IsSame(const Class& b) const {\
			return		post##Base::IsSame(b) && \
						SampleBase<T>::IsCopyCompatible(b) && \
						DimBase<dim>::IsSame(b) && \
						DevBase::IsSame(b); \
		} \
		bool IsCopyCompatible(const d##dim##post& b) const {\
			return		SampleBase<T>::IsCopyCompatible(b) && \
						DimBase<dim>::IsSame(b) && \
						DevBase::IsSame(b); \
		} \
		bool operator==(const Class& b) const {return IsSame(b);} \
		bool operator!=(const Class& b) const {return !IsSame(b);} \
		template <class DevSpec>\
		void Set(SampleType type, DimArg dim_, int freq=0, int sample_rate=0) { \
			Set(AsTypeCls<DevSpec>(), type, dim_, freq, sample_rate); \
		} \
		void Set(TypeCls dev_spec, SampleType type, DimArg dim_, int freq=0, int sample_rate=0) { \
			DevBase::SetDevSpec(dev_spec); \
			SampleBase<T>::SetType(type); \
			DimBase<dim>::SetDim(dim_); \
			if (freq || sample_rate) \
				post##Base::SetTimeSeries(freq, sample_rate); \
		} \
		template <class DevSpec> void SetDefault() {\
			DevBase::SetDevSpec<DevSpec>(); \
			SampleBase<T>::SetDefault(); \
			DimBase<dim>::SetDefault(); \
		} \
		void SetDefaultTimeSeriesAudio() {post##Base::SetTimeSeries(44100, 1024);} \
		void SetDefaultTimeSeriesVideo() {post##Base::SetTimeSeries(60, 1);} \
		/*void SetDeviceInternal() { \
			SampleBase<T>::SetDeviceInternal(); \
			DimBase<dim>::SetDeviceInternal(); \
			post##Base::SetDeviceInternal(); \
		}*/ \
		void Clear() {post##Base::Clear(); SampleBase<T>::Clear(); DimBase<dim>::Clear(); DevBase::Clear();} \
		int GetFrameSize() const {return DimBase<dim>::GetArea() * post##Base::GetSampleRate() * SampleBase<T>::GetSampleSize();} \
		bool IsValid() const { \
			return		post##Base::IsValid() && \
						SampleBase<T>::IsValid() && \
						DimBase<dim>::IsValid() && \
						DevBase::IsValid(); \
		} \
		Class& operator=(const Class& c) { \
						post##Base::operator=(c); \
						SampleBase<T>::operator=(c); \
						DimBase<dim>::operator=(c); \
						DevBase::operator=(c); \
			return *this; \
		} \
		String ToString() const {return DevBase::ToString() + ", " + DimBase<dim>::ToString() + ", " + post##Base::ToString() + ", " + SampleBase<T>::ToString();} \
	\
	\
	};

#define COMBINE_CLASS_3(post, d) \
	COMBINE_CLASS(1, post, d) \
	COMBINE_CLASS(2, post, d) \
	COMBINE_CLASS(3, post, d)

#define COMBINE_CLASS_TDFD(x) \
	COMBINE_CLASS_3(x, TD) \
	COMBINE_CLASS_3(x, FD)


COMBINE_CLASS_TDFD(Once)
COMBINE_CLASS_TDFD(TimeSeries)
COMBINE_CLASS_TDFD(SparseTimeSeries)


#undef COMBINE_CLASS
#undef COMBINE_CLASS_3
#undef COMBINE_CLASS_TDFD







template <class S0, class S1>
class MultiSample2 {
public:
	using T0 = S0;
	using T1 = S1;
	
	struct Type {
		typename S0::Type t0;
		typename S1::Type t1;
	};
	
	static bool IsCopyCompatible(Type a, Type b) {
		return	T0::IsCopyCompatible(a.t0, b.t0) &&
				T1::IsCopyCompatible(a.t1, b.t1);
	}
};

template <class S0, class S1, class S2, class S3>
class MultiSample4 {
public:
	using T0 = S0;
	using T1 = S1;
	using T2 = S2;
	using T3 = S3;
	
	struct Type {
		typename S0::Type t0;
		typename S1::Type t1;
		typename S2::Type t2;
		typename S3::Type t3;
	};
	
	static bool IsCopyCompatible(Type a, Type b) {
		return	T0::IsCopyCompatible(a.t0, b.t0) &&
				T1::IsCopyCompatible(a.t1, b.t1) &&
				T2::IsCopyCompatible(a.t2, b.t2) &&
				T3::IsCopyCompatible(a.t3, b.t3);
	}
};





template <class T>
class TD1OnceMulti4 : RTTIBase {
	RTTI_DECL0(TD1OnceMulti4);
	
	using T0 = typename T::T0;
	using T1 = typename T::T1;
	using T2 = typename T::T2;
	using T3 = typename T::T3;
	
	TD1Once<T0>		o0;
	TD1Once<T1>		o1;
	TD1Once<T2>		o2;
	TD1Once<T3>		o3;
	TypeCls dev_spec = 0;
	
public:
	static const int def_sample_rate = 1;
	
	int GetSampleSize() const {TODO}
	int GetFrameSize() const {TODO}
	int GetArea() const {return 1;}
	TypeCls GetDevSpec() const {return dev_spec;}
	void Clear() {o0.Clear(); o1.Clear(); o2.Clear(); o3.Clear(); dev_spec = 0;}
	bool IsValid() const {return o0.IsValid() && o1.IsValid() && o2.IsValid() && o3.IsValid() && dev_spec != 0;}
	bool IsSame(const TD1OnceMulti4<T>& o) const {TODO}
	bool IsCopyCompatible(const TD1OnceMulti4<T>& o) const {TODO}
	bool operator==(const TD1OnceMulti4<T>& o) const {return IsSame(o);}
	template <class DevSpec> void SetDefault() {dev_spec = AsTypeCls<DevSpec>(); o0.template SetDefault<DevSpec>(); o1.template SetDefault<DevSpec>(); o2.template SetDefault<DevSpec>(); o3.template SetDefault<DevSpec>();}
	
	String ToString() const {return "[" + o0.ToString() + ", " + o1.ToString() + ", " + o2.ToString() + ", " + o3.ToString() + "]";}
	
};

template <class T>
class AVTimeSeries : RTTIBase {
	RTTI_DECL0(AVTimeSeries);
	
	using T0 = TD1TimeSeries<typename T::T0>;
	using T1 = TD2TimeSeries<typename T::T1>;
	
	T0		o0;
	T1		o1;
	
public:
	static const int def_sample_rate = 1;
	
};



using ModelSample = MultiSample4<SpaceSample,VertexSample,TexLocSample,BoneSample>;
using AVSample = MultiSample2<SoundSample,LightSampleFD>;





class ConnectorBase;


class ValExchangePointBase :
	public ExchangePoint
{
	
public:
	RTTI_DECL1(ValExchangePointBase, ExchangePoint);
	virtual void Init(ConnectorBase* conn) = 0;
	
	
	static ValExchangePointBase* Create(TypeCls t);
	
};

using ValExchangePointBaseRef = Ref<ValExchangePointBase>;


NAMESPACE_TOPSIDE_END


#endif
