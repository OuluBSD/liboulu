#ifndef _Local_Templates_h_
#define _Local_Templates_h_

NAMESPACE_TOPSIDE_BEGIN


class ConnectorBase;


template <class T>
class RealtimePacketBuffer {
	static const int BUFFER_COUNT = 2;
	static const int SAMPLE_LIMIT = 4*1024; // large default
	
	RWMutex lock;
	LinkedList<T> packets[BUFFER_COUNT];
	int data_i = 0;
	int sample_limit = SAMPLE_LIMIT;
	
	
public:
	RealtimePacketBuffer() {}
	
	void Dump() {
		LOG("RealtimePacketBuffer: active buf: " << data_i);
		for(int i = 0; i < BUFFER_COUNT; i++) {
			LinkedList<T>& l = packets[i];
			auto iter = l.begin();
			int j = 0;
			for(; iter; ++iter, ++j) {
				LOG("RealtimePacketBuffer: " << i << ": " << j << ": " << iter()->GetOffset().ToString());
			}
		}
	}
	void Clear() {
		lock.EnterWrite();
		for(int i = 0; i < BUFFER_COUNT; i++)
			packets[i].Clear();
		data_i = 0;
		sample_limit = SAMPLE_LIMIT;
		lock.LeaveWrite();
	}
	void RemoveFirst(int count=1) {
		lock.EnterWrite();
		count = min(count, packets[data_i].GetCount());
		RTLOG("RealtimePacketBuffer::RemoveFirst: " << IntStr(count));
		packets[data_i].RemoveFirst(count);
		lock.LeaveWrite();
	}
	
	void		SetLimit(int samples) {ASSERT(samples > 0); sample_limit = samples;}
	
	int			GetQueueSize() const {return packets[data_i].GetCount();}
	int			GetQueueSamples() const {int bytes = 0; for (auto& p : packets[data_i]) bytes += p->GetSizeSamples(); return bytes;}
	bool		IsQueueFull() const {
		int sz = GetQueueSamples();
		return sz >= sample_limit;
	}
	bool		IsEmpty() const {return packets[data_i].IsEmpty();}
	
	int GetQueueSizeBytes() const {
		int sz = 0;
		for (auto iter = packets[data_i].begin(); iter; ++iter)
			sz += iter()->GetSizeBytes();
		return sz;
	}
	
	off32 GetOffset() const {
		LinkedList<T>& l = const_cast<LinkedList<T>&>(packets[data_i]);
		return l.IsEmpty() ? off32() : (*l.begin())->GetOffset();
	}
	
	T Get(off32 offset) {
		lock.EnterRead();
		ASSERT(data_i >= 0 && data_i < BUFFER_COUNT);
		LinkedList<T>& l = packets[data_i];
		if (l.IsEmpty()) {
			lock.LeaveRead();
			return T();
		}
		
		// Find given offset frame
		auto iter = l.begin();
		bool found = false;
		while (iter) {
			off32 iter_offset = iter()->GetOffset();
			if (iter_offset == offset) {
				found = true;
				break;
			}
			++iter;
		}
		if (!found) {
			lock.LeaveRead();
			return T();
		}
		
		T p = iter();
		lock.LeaveRead();
		
		return p;
	}
	
	void Put(const T& p, bool realtime) {
		lock.EnterWrite();
		if (realtime) {
			packets[data_i].Clear();
			data_i = (data_i + 1) % BUFFER_COUNT;
			LinkedList<T>& l = packets[data_i];
			ASSERT(l.IsEmpty());
			l.Add(p);
			ASSERT(sample_limit > 0);
		}
		else {
			LinkedList<T>& l = packets[data_i];
			l.Add(p);
		}
		lock.LeaveWrite();
	}
	
};


template <class Ctx>
struct ContextT {
	using C = Ctx;
	using Format = typename Ctx::Format;
	using ValueBase = typename Ctx::ValueBase;
	using StreamBase = typename Ctx::StreamBase;
	
	static const char* TypeStringT(const char* t) {
		thread_local static String s;
		s.Clear();
		s << "ContextT<" << AsTypeName<Ctx>() << ">::" << t;
		return s;
	}
	
	class Ex;
	
	class Value :
		public ValueBase,
		virtual public RealtimeStream
	{
		
	public:
		RTTI_DECL_T2(Value, ValueBase, RealtimeStream)
		Value() = default;
		virtual ~Value() = default;
		
		virtual void Exchange(Ex& e) = 0;
		virtual int GetQueueSize() const = 0;
		virtual Format GetFormat() const = 0;
		virtual bool IsQueueFull() const = 0;
		
	};
	
	
	class ExchangePoint :
		public Topside::ExchangePoint
	{
		ConnectorBase* conn = 0;
		off32 offset;
		bool use_consumer = false;
		bool dbg_offset_is_set = false;
		
	public:
		RTTI_DECL_T1(ExchangePoint, Topside::ExchangePoint)
		typedef ExchangePoint CLASSNAME;
		ExchangePoint() {}
		~ExchangePoint() {Deinit();}
		
		void Init(ConnectorBase* conn);
		void Deinit();
		void Update(double dt) override;
		
		void SetOffset(off32 o) {offset = o; dbg_offset_is_set = true;}
		void UseConsumer(bool b=true) {use_consumer = b;}
		void Destroy() {conn = 0;}
		
		off32 GetOffset() const {return offset;}
		
	};
	
	
	class Ex :
		public ExchangeBase
	{
		bool storing = false;
		ExchangePoint* expt = 0;
		Value* src = 0;
		Value* sink = 0;
		const RealtimeSourceConfig* src_conf = 0;
		off32 offset;
		
	public:
		RTTI_DECL_T1(Ex, ExchangeBase)
		Ex(ExchangePoint* expt) : expt(expt) {}
		
		Value&						Sink() const {return *sink;}
		Value&						Source() const {return *src;}
		const RealtimeSourceConfig&	SourceConfig() const {return *src_conf;}
		ExchangePoint&				GetExchangePoint() {return *expt;}
		off32						GetOffset() const {return offset;}
		virtual bool				IsLoading() override {return !storing;}
		virtual bool				IsStoring() override {return storing;}
		
		void	SetLoading(Value& src, const RealtimeSourceConfig& conf) {storing = false; this->src = &src; this->sink = 0; src_conf = &conf;}
		void	SetStoring(Value& sink, const RealtimeSourceConfig& conf) {storing = true; this->src = 0; this->sink = &sink; src_conf = &conf;}
		void	SetOffset(off32 packet_count);
		
	};
	
	
	class PacketValue :
		RTTIBase,
		Moveable<PacketValue>
	{
		Vector<byte>		data;
		Format				fmt;
		off32				offset;
		double				time;
		
		
	public:
		using Pool = RecyclerPool<PacketValue>;
		
		RTTI_DECL0(PacketValue);
		PacketValue() {}
		
		Vector<byte>&			Data() {return data;}
		void					Set(Format fmt, off32 offset, double time) {this->fmt = fmt; this->offset = offset; this->time = time;}
		void					SetFormat(Format fmt) {this->fmt = fmt;}
		void					SetOffset(off32 offset) {this->offset = offset;}
		void					SetTime(double seconds) {time = seconds;}
		
		const Vector<byte>&		GetData() const {return data;}
		Format					GetFormat() const {return fmt;}
		off32					GetOffset() const {return offset;}
		double					GetTime() const {return time;}
		bool					IsOffset(const off32& o) const {return offset.value == o.value;}
		int						GetSizeBytes() const {return data.GetCount();}
		int						GetSizeSamples() const {return data.GetCount() / fmt.GetSampleSize();}
		
	#if HAVE_OPENGL
		virtual bool PaintOpenGLTexture(int texture);
	#endif
		
	};
	
	
	using Packet			= SharedRecycler<PacketValue>;
	using PacketBuffer		= LinkedList<Packet>;
	using RecRefBase		= RecyclerRefBase<PacketValue>;
	
	static Packet CreatePacket() {
		PacketValue* obj = PacketValue::Pool::StaticPool().New();
		RecRefBase* base = RecRefBase::Pool::StaticPool().New();
		base->SetObj(obj);
		return Packet(obj, base);
	}
	
	
	class Proxy :
		public Value
	{
		Value* o = 0;
		
	public:
		RTTI_DECL_T1(Proxy, Value)
		Proxy() = default;
		Proxy(Value* o) : o(o) {}
		
		void Set(Value* o) {this->o = o;}
		
		operator bool() const {return o != 0;}
		void Exchange(Ex& e) override {if (o) o->Exchange(e);}
		int GetQueueSize() const override {if (o) return o->GetQueueSize(); return 0;}
		Format GetFormat() const override {if (o) return o->GetFormat(); return Format();}
		bool IsQueueFull() const override {if (o) return o->IsQueueFull(); return 0;}
		
	};
	
	
	class VolatileBuffer;
	
	
	class PacketProducer :
		RTTIBase
	{
		PacketBuffer*		src = 0;
		VolatileBuffer*		dst = 0;
		off32				offset;
		bool				dst_realtime = false;
		int					internal_written_bytes;
		
	public:
		RTTI_DECL_T0(PacketProducer)
		PacketProducer() {}
		
		void		SetOffset(off32 offset) {this->offset = offset;}
		void		SetSource(PacketBuffer& src) {this->src = &src;}
		void		SetDestination(VolatileBuffer& dst) {this->dst = &dst;}
		void		SetDestinationRealtime(bool b) {dst_realtime = b;}
		void		ClearDestination() {dst = 0;}
		
		
		void		ProduceAll(bool blocking=false);
		bool		ProducePacket();
		bool		IsFinished() const;
		bool		IsEmptySource() const {return src == 0;}
		off32		GetOffset() const {return offset;}
		int			GetLastMemoryBytes() const {return internal_written_bytes;}
		
		operator bool() const {return IsFinished();}
		
	};
	
	
	class PacketConsumer :
		RTTIBase
	{
		
		VolatileBuffer*	src = 0;
		off32			offset;
		int				leftover_size = 0;
		Packet			leftover;
		
		Format			dst_fmt;
		VolatileBuffer*	dst_buf = 0;
		void*			dst_mem = 0;
		byte*			dst_iter = 0;
		byte*			dst_iter_end = 0;
		int				dst_size = 0;
		bool			dst_realtime = 0;
		
		int				internal_count;
		int				internal_written_bytes;
		
		void Consume(Packet& p, int data_shift);
		
	public:
		RTTI_DECL_T0(PacketConsumer)
		PacketConsumer() {}
		
		void		SetOffset(off32 offset) {ASSERT(!HasLeftover()); this->offset = offset;}
		void		SetSource(VolatileBuffer& src);
		void		SetDestination(const Format& fmt, void* dst, int src_dst_size);
		void		SetDestination(VolatileBuffer& dst);
		void		SetDestinationRealtime(bool b) {dst_realtime = b;}
		void		ClearDestination();
		void		ClearLeftover() {leftover_size = 0; leftover.Clear();}
		void		TestSetOffset(off32 offset);
		
		void		ConsumeAll(bool blocking=false);
		bool		ConsumePacket();
		bool		IsFinished() const;
		bool		IsEmptySource() const {return src == 0;}
		off32		GetOffset() const {return offset;}
		bool		HasLeftover() const {return leftover_size != 0;}
		int			GetLastMemoryBytes() const {return internal_written_bytes;}
		
		operator bool() const {return IsFinished();}
		
	};
	
	
	class VolatileBuffer :
		public Value,
		public RealtimePacketBuffer<Packet>
	{
		Format preferred_fmt;
		One<PacketConsumer> consumer;
		
		#if DEBUG_REALTIME
		off32 dbg_offset;
		#endif
		
	public:
		RTTI_DECL_T1(VolatileBuffer, Value)
		using Buffer = RealtimePacketBuffer<Packet>;
		
		VolatileBuffer() = default;
		
		#if DEBUG_REALTIME
		Packet Get(off32 offset) {
			Packet p = Buffer::Get(offset);
			if (p.IsEmpty()) {
				RTLOG("error: got empty packet in VolatileBuffer<" << Ctx::Name << ">");
			}
			return p;
		}
		void Put(const Packet& p, bool realtime) {
			off32 off = p->GetOffset();
			ASSERT(off == dbg_offset);
			dbg_offset.value = off.value + 1;
			Buffer::Put(p, realtime);
		}
		#endif
		
		void		SetSampleSize(Format fmt, int samples) {preferred_fmt = fmt; Buffer::SetLimit(samples);}
		
		void		Exchange(Ex& e)			override;
		int			GetQueueSize() const	override {return Buffer::GetQueueSize();}
		Format		GetFormat() const		override {return preferred_fmt;}
		bool		IsQueueFull() const		override {return Buffer::IsQueueFull();}
		
		
		
	};
	
	
	class Stream :
		public virtual RealtimeStream,
		public StreamBase
	{
		
	public:
		RTTI_DECL_T2(Stream, RealtimeStream, StreamBase)
		
		virtual ~Stream() {}
		
		virtual bool			IsOpen() const = 0;
		virtual bool			Open(int fmt_idx) = 0;
		virtual void			Close() = 0;
		virtual Value&			Get() = 0;
		virtual void			FillBuffer() = 0;
		virtual void			DropBuffer() = 0;
		virtual int				GetActiveFormatIdx() const = 0;
		virtual int				GetFormatCount() const = 0;
		virtual Format			GetFormat(int i) const = 0;
		virtual bool			FindClosestFormat(const Format& fmt, int& idx) = 0;
		
		
		Format GetActiveFormat() const {return GetFormat(GetActiveFormatIdx());}
		
	};
	
	
	class SimpleValue :
		public Value
	{
		Format fmt;
		off32 offset;
		double time = 0;
	public:
		RTTI_DECL_T1(SimpleValue, Value)
		void Exchange(Ex& e) override;
		int GetQueueSize() const override;
		Format GetFormat() const override;
		bool IsQueueFull() const override;
		virtual void StorePacket(Packet& p) = 0;
	};
	
	
	class SimpleBufferedValue :
		public Value
	{
		
	protected:
		PacketProducer	producer;
		PacketBuffer	buf;
		dword			frame_counter = 0;
		int				min_buf_samples = std::max<int>(1, 3 * Ctx::Format::def_sample_rate);
		off32			begin;
		off32			begin_offset_min;
		off32			begin_offset_max;
		off32			end_offset_min;
		off32			end_offset_max;
		dword			exchange_count = 0;
		Format			fmt;
		
	public:
		RTTI_DECL_T1(SimpleBufferedValue, Value)
		void		Exchange(Ex& e) override;
		int			GetQueueSize() const override;
		Format		GetFormat() const override;
		bool		IsQueueFull() const override;
		int			GetQueueSamples() const;
		void		Clear() {buf.Clear();}
		void		FillBuffersNull();
		void		Visit(RuntimeVisitor& vis) {}
		void		DropBuffer();
		
	};
	
	
	class SimpleStream :
		public Stream
	{
		Value* ptr = 0;
	public:
		RTTI_DECL_T1(SimpleStream, Stream)
		SimpleStream() {}
		SimpleStream(Value& v) : ptr(&v) {}
		void			Set(Value& v) {ptr = &v;}
		bool			IsOpen() const override {return true;}
		bool			Open(int fmt_idx) override {ASSERT(fmt_idx == 0); return true;}
		void			Close() override {}
		Value&			Get() override {ASSERT(ptr); return *ptr;}
		void			FillBuffer() override {}
		void			DropBuffer() override {}
		int				GetActiveFormatIdx() const override {return 0;}
		int				GetFormatCount() const override {return 1;}
		Format			GetFormat(int i) const override {return ptr->GetFormat();}
		bool			FindClosestFormat(const Format& fmt, int& idx) override {idx = 0; return true;}
	};
	
	
	class SimpleBufferedStream :
		public Stream
	{
		SimpleBufferedValue* ptr = 0;
		bool skip_drop = false;
	public:
		RTTI_DECL_T1(SimpleBufferedStream, Stream)
		SimpleBufferedStream() {}
		SimpleBufferedStream(SimpleBufferedValue& v) : ptr(&v) {}
		void			SetSkipDrop(bool b=true) {skip_drop = b;}
		void			Set(SimpleBufferedValue& v) {ptr = &v;}
		Value&			Get() override {ASSERT(ptr); return *ptr;}
		void			FillBuffer() override;
		void			DropBuffer() override {if (!skip_drop) ptr->DropBuffer();}
		int				GetActiveFormatIdx() const override {return 0;}
		int				GetFormatCount() const override {return 1;}
		Format			GetFormat(int i) const override {return ptr->GetFormat();}
		bool			FindClosestFormat(const Format& fmt, int& idx) override {idx = 0; return true;}
		virtual bool			IsEof() = 0;
		virtual bool			ReadFrame() = 0;
		virtual bool			ProcessFrame() = 0;
		virtual bool			ProcessOtherFrame() = 0;
		virtual void			ClearPacketData() = 0;
	};
	
	
	static bool Convert(const Format& src_fmt, const byte* src, const Format& dst_fmt, byte* dst);
	static bool Convert(const Packet& src, Packet& dst);
	
};


#include "Templates.inl"


#define LOCAL_CTX(x, value_base, stream_base, sys_base, sink_base) \
	struct x##Context: RTTIBase { \
		RTTI_DECL0(x##Context) \
		static constexpr const char* Name = #x; \
		using Format			= x##Format; \
		using Ctx				= x##Context; \
		using ValueBase			= value_base; \
		using StreamBase		= stream_base; \
		using CustomSystemBase	= sys_base; \
		using CustomSinkBase	= sink_base; \
	}; \
	using x##T = ContextT<x##Context>; \
	using x = x##T::Value; \
	using x##Proxy = x##T::Proxy; \
	using x##Proxy = x##T::Proxy; \
	using x##Packet = x##T::Packet; \
	using x##VolatileBuffer = x##T::VolatileBuffer; \
	using x##Stream = x##T::Stream; \
	using x##PacketConsumer = x##T::PacketConsumer; \
	using x##PacketProducer = x##T::PacketProducer; \
	using x##Ex = x##T::Ex; \
	using x##Proxy = x##T::Proxy; \
	using x##PacketBuffer = x##T::PacketBuffer; \
	using Simple##x = x##T::SimpleValue; \
	using SimpleBuffered##x = x##T::SimpleBufferedValue; \
	using Simple##x##Stream = x##T::SimpleStream; \
	using SimpleBuffered##x##Stream = x##T::SimpleBufferedStream; \
	using x##StreamRef = Ref<x##Stream,RefParent1<ComponentBase>>; \
	inline x##Packet Create##x##Packet() {return x##T::CreatePacket();}


struct DummyValueBase			: RTTIBase {RTTI_DECL0(DummyValueBase)};
struct DummyStreamBase			: RefScopeEnabler<DummyStreamBase,ComponentBase> {RTTI_DECL_R0(DummyStreamBase)};
struct DummyCustomSystemBase	: RTTIBase {RTTI_DECL0(DummyCustomSystemBase)};
struct DummyCustomSinkBase		: RTTIBase {RTTI_DECL0(DummyCustomSinkBase)};

NAMESPACE_TOPSIDE_END

#endif