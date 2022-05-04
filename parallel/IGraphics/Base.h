#ifndef _IGraphics_Base_h_
#define _IGraphics_Base_h_

NAMESPACE_PARALLEL_BEGIN


template <class Gfx>
class BufferBaseT :
	public Atom
{
	
protected:
	using Buffer = BufferT<Gfx>;
	
	RealtimeSourceConfig* last_cfg = 0;
	
public:
	using BufferBase = BufferBaseT<Gfx>;
	RTTI_DECL1(BufferBaseT, Atom);
	
	void Visit(RuntimeVisitor& vis) override {vis % bf; vis.VisitThis<Atom>(this);}
	void Update(double dt) override {bf.Update(dt);}
	RealtimeSourceConfig* GetConfig() override {return last_cfg;}
	
	Buffer& GetBuffer() {return bf.GetBuffer();}
	
	
	GfxBufferFieldT<Gfx> bf;
};


template <class Gfx>
class ShaderBaseT :
	public BufferBaseT<Gfx>
{
	
public:
	using ShaderBase = ShaderBaseT<Gfx>;
	using BufferBase = BufferBaseT<Gfx>;
	RTTI_DECL1(ShaderBase, BufferBase);
	
	ShaderBaseT() {}
	
	bool Initialize(const Script::WorldState& ws) override;
	bool PostInitialize() override;
	bool Start() override;
	void Uninitialize() override;
	bool IsReady(PacketIO& io) override;
	bool Send(PacketValue& out, int src_ch) override;
	bool Recv(int sink_ch, const Packet& in) override;
	void Finalize(RealtimeSourceConfig& cfg) override;
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<BufferBase>(this);}
	
	
};


template <class Gfx>
class TextureBaseT :
	public BufferBaseT<Gfx>
{
	using Filter = GVar::Filter;
	using Wrap = GVar::Wrap;
	
	bool			loading_cubemap = false;
	Filter			filter = GVar::FILTER_LINEAR;
	Wrap			wrap = GVar::WRAP_REPEAT;
	Array<Packet>	cubemap;
	
public:
	using BufferBase = BufferBaseT<Gfx>;
	RTTI_DECL1(TextureBaseT, BufferBase);
	
	TextureBaseT() {}
	
	bool Initialize(const Script::WorldState& ws) override;
	bool PostInitialize() override;
	void Uninitialize() override;
	bool IsReady(PacketIO& io) override;
	bool Recv(int sink_ch, const Packet& in) override;
	bool Send(PacketValue& out, int src_ch) override;
	void Visit(RuntimeVisitor& vis) override;
	bool NegotiateSinkFormat(Serial::Link& link, int sink_ch, const Format& new_fmt) override;
	
	
};


template <class Gfx>
class FboReaderBaseT :
	public BufferBaseT<Gfx>
{
public:
	using BufferBase = BufferBaseT<Gfx>;
	using Buffer = BufferT<Gfx>;
	RTTI_DECL1(FboReaderBaseT, BufferBase);
	
	FboReaderBaseT() {}
	
	bool Initialize(const Script::WorldState& ws) override {
		ISourceRef src = this->GetSource();
		Format out_fmt = src->GetSourceValue(src->GetSourceCount()-1).GetFormat();
		if (out_fmt.IsAudio())
			this->SetPrimarySinkQueueSize(DEFAULT_AUDIO_QUEUE_SIZE);
		return true;
	}
	
	bool PostInitialize() override {
		return true;
	}
	
	void Uninitialize() override {
		
	}
	
	bool IsReady(PacketIO& io) override {
		dword iface_sink_mask = this->iface.GetSinkMask();
		bool b = io.active_sink_mask == iface_sink_mask && io.full_src_mask == 0;
		RTLOG("OglFboReaderBase::IsReady: " << (b ? "true" : "false") << " (" << io.nonempty_sinks << ", " << io.sink_count << ", " << HexStr(iface_sink_mask) << ", " << HexStr(io.active_sink_mask) << ")");
		return b;
	}
	
	bool Send(PacketValue& out, int src_ch) override {
		TODO
	}
	
	/*bool ProcessPackets(PacketIO& io) override {
		ASSERT(io.nonempty_sinks == 2);
		
		{
			PacketIO::Sink& sink = io.sink[0];
			PacketIO::Source& src = io.src[0];
			sink.may_remove = true;
			src.from_sink_ch = 0;
			src.p = this->ReplyPacket(0, sink.p);
			src.p->AddRouteData(src.from_sink_ch);
		}
		
		{
			PacketIO::Sink& sink = io.sink[1];
			PacketIO::Source& src = io.src[1];
			ASSERT(sink.p && src.val && !src.is_full);
			Packet& in = sink.p;
			sink.may_remove = true;
			src.from_sink_ch = 1;
			src.p = this->ReplyPacket(1, sink.p);
			src.p->AddRouteData(src.from_sink_ch);
			
			Format fmt = src.p->GetFormat();
			
			if (fmt.IsAudio()) {
				int src_queue = src.val->GetMinPackets();
				int sink_queue = sink.val->GetMinPackets();
				ASSERT(src_queue > 1);
				ASSERT(sink_queue > 1);
				
				//DUMP(fmt);
				AudioFormat& afmt = fmt;
				InternalPacketData& v = in->GetData<InternalPacketData>();
				Buffer* src_buf = (Buffer*)v.ptr;
				ASSERT(src_buf);
				
				auto& fb = src_buf->fb;
				int afmt_size = afmt.GetSize();
				ASSERT(fb.size.cx == afmt.sample_rate && fb.size.cy == 1 && fb.channels == afmt_size);
				int len = afmt.sample_rate * fb.channels * sizeof(float);
				ASSERT(len > 0);
				Vector<byte>& out_data = src.p->Data();
				out_data.SetCount(len);
				
				GLuint frame_buf = fb.GetReadFramebuffer();
				ASSERT(frame_buf > 0);
				glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frame_buf);
				glReadBuffer(GL_COLOR_ATTACHMENT0_EXT);
				glReadPixels(0, 0, afmt.sample_rate, 1, GetOglChCode(fb.channels), GL_FLOAT, out_data.Begin());
				glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
				
			}
			else TODO
		}
		
		return true;
	}*/
	
	bool NegotiateSinkFormat(int sink_ch, const Format& new_fmt) override {
		
		TODO
		
	}
	
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<BufferBase>(this);}
	
};




template <class Gfx>
class KeyboardBaseT :
	public BufferBaseT<Gfx>
{
	String			target;
	EnvStateRef		state;
	
	
public:
	using BufferBase = BufferBaseT<Gfx>;
	RTTI_DECL1(KeyboardBaseT, BufferBase);
	KeyboardBaseT() {}
	
	bool Initialize(const Script::WorldState& ws) override {
		
		target = ws.Get(".target");
		if (target.IsEmpty()) {
			LOG("EventStateBase::Initialize: error: target state argument is required");
			return false;
		}
		
		Space& space = this->GetParent();
		state = space.FindNearestState(target);
		if (!state) {
			LOG("EventStateBase::Initialize: error: state '" << target << "' not found in parent space: " << space.GetDeepName());
			return false;
		}
		
		FboKbd::KeyVec& data = state->Set<FboKbd::KeyVec>(KEYBOARD_PRESSED);
		data.SetAll(false);
		
		return true;
	}
	
	bool PostInitialize() override {
		
		return true;
	}
	
	void Uninitialize() override {
		
	}
	
	bool IsReady(PacketIO& io) override {
		if (!state) return false;
		ASSERT(io.src_count == 2);
		if (io.src_count != 2) return false;
		
		dword iface_sink_mask = this->iface.GetSinkMask();
		bool b = io.active_sink_mask == iface_sink_mask && io.full_src_mask == 0;
		RTLOG("OglKeyboardBase::IsReady: " << (b ? "true" : "false") << " (" << io.nonempty_sinks << ", " << io.sink_count << ", " << HexStr(iface_sink_mask) << ", " << HexStr(io.active_sink_mask) << ")");
		return b;
	}
	
	bool Send(PacketValue& out, int src_ch) override {
		TODO
	}
	
	/*bool ProcessPackets(PacketIO& io) override {
		RTLOG("OglKeyboardBase::ProcessPackets");
		auto& buf = this->buf;
		
		PacketIO::Sink& prim_sink = io.sink[0];
		PacketIO::Source& src = io.src[0];
		
		ASSERT(prim_sink.p);
		prim_sink.may_remove = true;
		src.from_sink_ch = 0;
		src.p = this->ReplyPacket(0, prim_sink.p);
		
		Packet& from = src.p;
		Size sz(FboKbd::key_tex_w, FboKbd::key_tex_h);
		int channels = 1;
		FboKbd::KeyVec& data = state->Set<FboKbd::KeyVec>(KEYBOARD_PRESSED);
		
		if (!buf.IsInitialized()) {
			ASSERT(sz.cx > 0 && sz.cy > 0);
			auto& fb = buf.fb;
			fb.is_win_fbo = false;
			fb.size = sz;
			fb.channels = channels;
			fb.sample = GVar::SAMPLE_FLOAT;
			fb.fps = 0;
			
			if (!buf.InitializeTexture(
				Size(sz.cx, sz.cy),
				channels,
				GVar::SAMPLE_U8,
				data.Get(),
				data.GetCount() * sizeof(byte)))
				return false;
		}
		else {
			buf.ReadTexture(
				sz,
				channels,
				GVar::SAMPLE_U8,
				data.Get(),
				data.GetCount() * sizeof(byte));
		}
		
		
		InterfaceSourceRef src_iface = this->GetSource();
		int src_count = src_iface->GetSourceCount();
		for (int src_ch = 1; src_ch < src_count; src_ch++) {
			PacketIO::Source& src = io.src[src_ch];
			if (!src.val)
				continue;
			Format src_fmt = src_iface->GetSourceValue(src_ch).GetFormat();
			if (src_fmt.vd == VD(OGL,FBO)) {
				Packet& out = src.p;
				if (!out) {
					src.from_sink_ch = 1;
					out = this->ReplyPacket(src_ch, prim_sink.p);
				}
				PacketValue& val = *out;
				InternalPacketData& data = val.GetData<InternalPacketData>();
				this->GetBuffer().StoreOutputLink(data);
				RTLOG("OglKeyboardBase::ProcessPackets: 0, " << src_ch << ": " << out->ToString());
			}
		}
		
		return true;
	}*/
	
	void Visit(RuntimeVisitor& vis) override {}
	
};


template <class Gfx>
class AudioBaseT :
	public BufferBaseT<Gfx>
{
	
public:
	using BufferBase = BufferBaseT<Gfx>;
	RTTI_DECL1(AudioBaseT, BufferBase);
	AudioBaseT() {}
	
	bool Initialize(const Script::WorldState& ws) override {
		return true;
	}
	
	bool PostInitialize() override {
		return true;
	}
	
	void Uninitialize() override {
		
	}
	
	bool IsReady(PacketIO& io) override {
		dword iface_sink_mask = this->iface.GetSinkMask();
		bool b = io.active_sink_mask == iface_sink_mask && io.full_src_mask == 0;
		RTLOG("OglAudioBase::IsReady: " << (b ? "true" : "false") << " (" << io.nonempty_sinks << ", " << io.sink_count << ", " << HexStr(iface_sink_mask) << ", " << HexStr(io.active_sink_mask) << ")");
		return b;
	}
	
	bool Send(PacketValue& out, int src_ch) override {
		TODO
	}
	
	/*bool ProcessPackets(PacketIO& io) override {
		RTLOG("OglAudioBase::ProcessPackets");
		ASSERT(io.src_count == 2 && io.sink_count == 2);
		auto& buf = this->buf;
		
		PacketIO::Sink&		prim_sink	= io.sink[0];
		PacketIO::Source&	prim_src	= io.src[0];
		PacketIO::Sink&		sink		= io.sink[1];
		PacketIO::Source&	src			= io.src[1];
		
		ASSERT(prim_sink.p);
		prim_sink.may_remove = true;
		prim_src.from_sink_ch = 0;
		prim_src.p = this->ReplyPacket(0, prim_sink.p);
		
		ASSERT(sink.p);
		sink.may_remove = true;
		src.from_sink_ch = 0;
		src.p = this->ReplyPacket(1, sink.p);
		
		Packet& from = sink.p;
		Format from_fmt = from->GetFormat();
		ASSERT(from_fmt.IsAudio());
		AudioFormat& afmt = from_fmt;
		Size sz(afmt.sample_rate, 1);
		int channels = afmt.GetSize();
		const Vector<byte>& data = from->GetData();
		
		if (!buf.IsInitialized()) {
			ASSERT(sz.cx > 0 && sz.cy > 0);
			auto& fb = buf.fb;
			fb.is_win_fbo = false;
			fb.size = sz;
			fb.channels = channels;
			ASSERT(afmt.IsSampleFloat());
			fb.sample = GVar::SAMPLE_FLOAT;
			fb.fps = 0;
			
			if (!buf.InitializeTexture(
				Size(sz.cx, sz.cy),
				channels,
				GVar::SAMPLE_U8,
				&*data.Begin(),
				data.GetCount() * sizeof(byte)))
				return false;
		}
		else {
			buf.ReadTexture(
				sz,
				channels,
				GVar::SAMPLE_U8,
				&*data.Begin(),
				data.GetCount() * sizeof(byte));
		}
		
		
		InterfaceSourceRef src_iface = this->GetSource();
		int src_count = src_iface->GetSourceCount();
		for (int src_ch = 1; src_ch < src_count; src_ch++) {
			PacketIO::Source& src = io.src[src_ch];
			if (!src.val)
				continue;
			Format src_fmt = src_iface->GetSourceValue(src_ch).GetFormat();
			if (src_fmt.vd == VD(OGL,FBO)) {
				Packet& out = src.p;
				if (!out) {
					src.from_sink_ch = 1;
					out = this->ReplyPacket(src_ch, prim_sink.p);
				}
				PacketValue& val = *out;
				InternalPacketData& data = val.GetData<InternalPacketData>();
				this->GetBuffer().StoreOutputLink(data);
				RTLOG("OglKeyboardBase::ProcessPackets: 0, " << src_ch << ": " << out->ToString());
			}
		}
		
		return true;
	}*/
	
	bool NegotiateSinkFormat(int sink_ch, const Format& new_fmt) override {
		// accept all valid video formats for now
		if (new_fmt.IsValid() && new_fmt.IsAudio()) {
			ISinkRef sink = this->GetSink();
			Value& val = sink->GetValue(sink_ch);
			val.SetFormat(new_fmt);
			return true;
		}
		return false;
	}
	
	void Visit(RuntimeVisitor& vis) override {}
	
};

#define GFXTYPE(x) \
	using x##ShaderBase = ShaderBaseT<x##Gfx>; \
	using x##TextureBase = TextureBaseT<x##Gfx>; \
	using x##FboReaderBase = FboReaderBaseT<x##Gfx>; \
	using x##KeyboardBase = KeyboardBaseT<x##Gfx>; \
	using x##AudioBase = AudioBaseT<x##Gfx>;
GFXTYPE_LIST
#undef GFXTYPE


NAMESPACE_PARALLEL_END

#endif
