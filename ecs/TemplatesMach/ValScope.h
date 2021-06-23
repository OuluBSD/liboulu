#ifndef _TemplatesMach_ValScope_h_
#define _TemplatesMach_ValScope_h_

NAMESPACE_ECS_BEGIN



/*static String TypeStringT(const char* t) {
	String s;
	s << ValSpec::GetName() << t;
	return s;
}*/

class Format : RTTIBase {
	RTTI_DECL0(Format)
	
public:
	String ToString() const; // {return FormatBase::ToString();}
	TypeCls GetDevSpec() const; // {return FormatBase::GetDevSpec();}
	int GetSampleSize() const;
	int GetArea() const;
	int GetFrameSize() const;
	double GetFrameSeconds() const;
	int GetMinBufSamples() const;
	
	bool IsValid() const;
	bool IsSame(const Format& f) const; // {return FormatBase::IsSame(f);}
	bool IsCopyCompatible(const Format& f) const; // {return FormatBase::IsCopyCompatible(f);}
	bool operator ==(const Format& f); // {return IsSame(f);}
	bool operator !=(const Format& f); // {return !IsSame(f);}
	
	void SetDefault(ValDevCls t); // {FormatBase::template SetDefault<DevSpec>();}
	void Clear();
	
};


typedef dword PacketId;


class PacketValue :
	RTTIBase,
	Moveable<PacketValue>
{
	Vector<byte>		data;
	Format				fmt;
	off32				offset;
	double				time;
	PacketId			id = 0;
	TypeCls				custom_data = 0;
	
public:
	using Pool = RecyclerPool<PacketValue>;
	
	//static const int def_sample_rate = Format::def_sample_rate;
	
	
	RTTI_DECL0(PacketValue);
	PacketValue(off32 offset) : offset(offset) {}
	~PacketValue() {data.Clear(); StopTracking(this);}
	
	Vector<byte>&			Data() {return data;}
	void					Set(Format fmt, double time) {this->fmt = fmt; this->time = time;}
	void					SetFormat(Format fmt) {this->fmt = fmt;}
	void					SetTime(double seconds) {time = seconds;}
	void					SetTrackingId(PacketId i) {id = i;}
	void					Clear() {data.SetCount(0); fmt.Clear(); offset.Clear(); time = 0; id = 0; custom_data = 0;}
	
	const Vector<byte>&		GetData() const {return data;}
	Format					GetFormat() const {return fmt;}
	off32					GetOffset() const {return offset;}
	double					GetTime() const {return time;}
	bool					IsOffset(const off32& o) const {return offset.value == o.value;}
	int						GetSizeBytes() const {return data.GetCount();}
	int						GetSizeTotalSamples() const {return data.GetCount() / fmt.GetSampleSize();}
	int						GetSizeChannelSamples() const {return data.GetCount() / (fmt.GetArea() * fmt.GetSampleSize());}
	void					CheckTracking(TrackerInfo info);
	void					StopTracking(TrackerInfo info);
	PacketId				GetTrackingId() const {return id;}
	bool					HasTrackingId() const {return id != 0;}
	
	String					ToString() const;
	
	template <class T> T& SetData() {
		custom_data = AsTypeCls<T>();
		data.SetCount(sizeof(T));
		byte* b = &data[0];
		memset(b,0, sizeof(T));
		return *(T*)b;
	}
	
	template <class T> bool IsData() {return custom_data == AsTypeCls<T>();}
	bool IsCustomData() const {return custom_data != 0;}
	
	template <class T> T& GetData() {
		ASSERT(custom_data == AsTypeCls<T>());
		ASSERT(data.GetCount() == sizeof(T));
		byte* b = &data[0];
		return *(T*)b;
	}
	
#if HAVE_OPENGL
	virtual bool PaintOpenGLTexture(int texture);
#endif
	
};


using Packet			= SharedRecycler<PacketValue>;
using PacketBuffer		= LinkedList<Packet>;
using RecRefBase		= RecyclerRefBase<PacketValue>;

static Packet CreatePacket(off32 off) {
	PacketValue* obj = PacketValue::Pool::StaticPool().New(off);
	RecRefBase* base = RecRefBase::Pool::StaticPool().New();
	base->SetObj(obj);
	return Packet(obj, base);
}



struct ValStreamState : RTTIBase {
	RTTI_DECL0(ValStreamState)
	Format fmt;
	TimeStop frame_time;
	double total_seconds = 0;
	double frame_seconds = 0;
	double last_sync_sec = 0;
	int frames = 0;
	int frames_after_sync = 0;
	int sink_frame = 0;
	bool is_sync = 0;
	
	void Clear();
	void Reset();
	void Step();
};




NAMESPACE_ECS_END

#endif
