#ifndef _AccelCore_Context_h_
#define _AccelCore_Context_h_


NAMESPACE_TOPSIDE_BEGIN


class ConnectorBase;

template <class Ctx>
struct ContextAccelT {
	using C = Ctx;
	using Format = typename Ctx::Format;
	using ValueBase = typename Ctx::ValueBase;
	using StreamBase = typename Ctx::StreamBase;
	using CustomSystemBase = typename Ctx::CustomSystemBase;
	using Value = typename ContextT<Ctx>::Value;
	using CtxStream = typename ContextT<Ctx>::Stream;
	using ExchangePoint = typename ContextT<Ctx>::ExchangePoint;
	using SimpleBufferedValue = typename ContextT<Ctx>::SimpleBufferedValue;
	using SimpleBufferedStream = typename ContextT<Ctx>::SimpleBufferedStream;
	using BaseSource = typename ContextEcsT<Ctx>::BaseSource;
	using BaseSink = typename ContextEcsT<Ctx>::BaseSink;
	
	class AccelSink :
		public InterfaceSink<AccelSink>,
		RTTIBase
	{
	public:
		RTTI_DECL1(AccelSink, InterfaceSink<AccelSink>)
		TypeId GetProviderType() override {return TypeId(AsTypeCls<AccelSink>());}
		
		virtual Format			GetFormat(C*) = 0;
		virtual Value&			GetValue(C*) = 0;
		
	};
	
	class AccelSource :
		public InterfaceSource<AccelSource, AccelSink>,
		RTTIBase
	{
		using InterfaceSourceT = InterfaceSource<AccelSource, AccelSink>;
		
	public:
		RTTI_DECL1(AccelSource, InterfaceSourceT)
		TypeId GetProviderType() override {return TypeId(AsTypeCls<AccelSource>());}
		
		using ExPt = ExchangePoint;
		using SinkClass = ContextAccelT::AccelSink;
		
		void						Update(double dt, bool buffer_full) {cfg.Update(dt, buffer_full);}
		const RealtimeSourceConfig&	Cfg() const {return cfg;}
		void						SetOffset(off32 begin, off32 end) {cfg.SetOffset(begin, end);}
		
		virtual CtxStream&			GetStream(C*) = 0;
		virtual void				BeginStream(C*) = 0;
		virtual void				EndStream(C*) = 0;
		
	private:
		RealtimeSourceConfig		cfg;
		
	};
	
	
	class PipeComponent :
		public Component<PipeComponent>,
		public AccelSource,
		public AccelSink,
		public AccelComponent
	{
		RTTI_COMP3(PipeComponent, AccelSource, AccelSink, AccelComponent)
		VIS_COMP_1_1(Accel, Accel)
		COPY_PANIC(PipeComponent)
		IFACE_GENERIC
		void Visit(RuntimeVisitor& vis) override {}
	public:
		
		void				Initialize() override {AccelComponent::Initialize();}
		void				Uninitialize() override {AccelComponent::Uninitialize();}
		TypeCls				GetContextType() const override {return AsTypeCls<C>();}
		
		// AccelSink
		Format				GetFormat(C*) override;
		Value&				GetValue(C*) override;
		
		// AccelSource
		CtxStream&			GetStream(C*) override;
		void				BeginStream(C*) override;
		void				EndStream(C*) override;
		
		bool IsContext(TypeCls t) const override {return AsTypeCls<C>() == t;}
		bool LoadAsInput(const AcceleratorHeader& in) override;
		void UpdateTexBuffers() override;
		
	};
	
	
	class ConvertInputComponent :
		public Component<ConvertInputComponent>,
		public AccelSource,
		public BaseSink,
		public AccelComponent
	{
		RTTI_COMP3(ConvertInputComponent, AccelSource, BaseSink, AccelComponent)
		VIS_COMP_1_1(Base, Accel)
		COPY_PANIC(ConvertInputComponent)
		IFACE_GENERIC
		void Visit(RuntimeVisitor& vis) override {}
	public:
		
		void				Initialize() override {AccelComponent::Initialize();}
		void				Uninitialize() override {AccelComponent::Uninitialize();}
		TypeCls				GetContextType() const override {return AsTypeCls<C>();}
		
		// BaseSink
		Format				GetFormat(C*) override;
		Value&				GetValue(C*) override;
		
		// AccelSource
		CtxStream&			GetStream(C*) override;
		void				BeginStream(C*) override;
		void				EndStream(C*) override;
		
		bool IsContext(TypeCls t) const override {return AsTypeCls<C>() == t;}
		bool LoadAsInput(const AcceleratorHeader& in) override;
		void PreProcess() override;
		void UpdateTexBuffers() override;
		
	};
	
	
	class ConvertOutputComponent :
		public Component<ConvertOutputComponent>,
		public BaseSource,
		public AccelSink,
		public AccelComponent
	{
		RTTI_COMP3(ConvertOutputComponent, BaseSource, AccelSink, AccelComponent)
		VIS_COMP_1_1(Accel, Base)
		COPY_PANIC(ConvertOutputComponent)
		IFACE_GENERIC
		void Visit(RuntimeVisitor& vis) override {}
		
		struct LocalValue : public SimpleBufferedValue {
			RTTI_DECL1(LocalValue, SimpleBufferedValue)
			ConvertOutputComponent& par;
			LocalValue(ConvertOutputComponent* par) : par(*par) {}
			
		};
		struct LocalStream : public SimpleBufferedStream {
			RTTI_DECL1(LocalStream, SimpleBufferedStream)
			ConvertOutputComponent& par;
			LocalStream(ConvertOutputComponent* par) : par(*par), SimpleBufferedStream(par->value) {}
			bool			IsOpen() const override {return par.IsOpen();}
			bool			Open(int fmt_idx) override {ASSERT(fmt_idx == 0); return par.Open();}
			void			Close() override {par.Close();}
			bool			IsEof() override {return !par.IsOpen();}
			bool			ReadFrame() override {return par.ReadFrame();}
			bool			ProcessFrame() override {return par.ProcessFrame();}
			bool			ProcessOtherFrame() override {return false;}
			void			ClearPacketData() override {par.ClearPacketData();}
		};
		
		LocalValue		value;
		LocalStream		stream;
	public:
		
		ConvertOutputComponent() : stream(this), value(this) {}
		
		void				Initialize() override {AccelComponent::Initialize();}
		void				Uninitialize() override {AccelComponent::Uninitialize();}
		TypeCls				GetContextType() const override {return AsTypeCls<C>();}
		
		// AccelSink
		Format				GetFormat(C*) override;
		Value&				GetValue(C*) override;
		
		// BaseSource
		CtxStream&			GetStream(C*) override;
		void				BeginStream(C*) override;
		void				EndStream(C*) override;
		
		bool IsContext(TypeCls t) const override {return AsTypeCls<C>() == t;}
		bool LoadAsInput(const AcceleratorHeader& in) override {return false;}
		void UpdateTexBuffers() override;
		bool ReadFrame();
		bool ProcessFrame();
		void ClearPacketData();
	};
	
	
	#if 0
	class SourceComponent :
		public Component<Source>,
		public AccelComponent,
		public DisplaySource,
		public AcceleratorSink
	{
		RTTI_COMP3(Source, AccelComponent, DisplaySource, AcceleratorSink)
		VIS_COMP_1_1(Display, Accelerator)
	private:
		void			Reset() override;
		void			PreProcess() override;
		void			PostProcess() override;
		void			UpdateTexBuffers() override;
		void			Event(const CtrlEvent& e) override;
		bool			LoadResources() override;
		bool			Accept(ExchangeSinkProviderRef sink, CookieRef& src_c, CookieRef& sink_c) override;
		ComponentBase&	GetECS() override {return *this;}
		bool			RequiresShaderCode() const override {return true;}
		//AccelVideoInput*	FindVideoInput(String path);
		void			Visit(RuntimeVisitor& vis) override {}
		
	private:
		struct LocalDisplay : public SimpleBufferedDisplay {
			RTTI_DECL1(LocalDisplay, SimpleBufferedDisplay)
			Source& par;
			LocalDisplay(Source* par) : par(*par) {}
			
		};
		struct LocalDisplayStream : public SimpleBufferedDisplayStream {
			RTTI_DECL1(LocalDisplayStream, DisplayStream)
			Source& par;
			LocalDisplayStream(Source* par) : par(*par), SimpleBufferedDisplayStream(par->dvalue) {}
			bool			IsOpen() const override {return par.IsOpen();}
			bool			Open(int fmt_idx) override {ASSERT(fmt_idx == 0); return par.Open();}
			void			Close() override {par.Close();}
			bool			IsEof() override {return !par.IsOpen();}
			bool			ReadFrame() override {return par.ReadFrame();}
			bool			ProcessFrame() override {return par.ProcessFrame();}
			bool			ProcessOtherFrame() override {return false;}
			void			ClearPacketData() override {par.ClearPacketData();}
		};
		
		LocalDisplay		dvalue;
		LocalDisplayStream	dstream;
		
		
	public:
		COPY_PANIC(Source);
		IFACE_CB(DisplaySource);
		IFACE_CB(AcceleratorSink);
		IFACE_GENERIC;
		
		Source() : AccelComponent(FUSION_DISPLAY_SOURCE), dvalue(this), dstream(this) {}
		
		bool				ReadFrame();
		bool				ProcessFrame();
		void				ClearPacketData();
		
		void				Initialize() override;
		void				Uninitialize() override;
		
		// DisplaySource
		DisplayStream&		GetStream(DisCtx) override;
		void				BeginStream(DisCtx) override;
		void				EndStream(DisCtx) override;
		
		// AcceleratorSink
		AcceleratorFormat	GetFormat(AccCtx) override {TODO}
		Accelerator&		GetValue(AccCtx) override {TODO}
		
		void				SetVideoSize(Size sz);
		void				SetFPS(int fps);
		
	};
	
	#endif
	
};


NAMESPACE_TOPSIDE_END


#endif