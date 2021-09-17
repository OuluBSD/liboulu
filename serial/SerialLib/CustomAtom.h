#ifndef _SerialLib_CustomAtom_h_
#define _SerialLib_CustomAtom_h_

NAMESPACE_SERIAL_BEGIN

template <class T>
class CustomerBaseT : public Atom<T> {
	using AtomT = Atom<T>;
	
protected:
	friend class Loop;
	using CustomerData = AtomBase::CustomerData;
	
	One<CustomerData>		customer;
	
	
	CustomerData* GetCustomerData() override {return customer.IsEmpty() ? 0 : &*customer;}
	
	
public:
	COPY_PANIC(CustomerBaseT)
	
	using BaseT = CustomerBaseT<T>;
	RealtimeSourceConfig& GetConfig() override {ASSERT(customer); return customer->cfg;}
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!this->AltInitialize(ws)) return false;
		AtomBase::packets_forwarded = 0;
		customer.Create();
		AtomBaseRef r = AtomBase::AsRefT();
		ASSERT(r);
		AtomBase::GetMachine().template Get<AtomSystem>()->Add(r);
		return true;
	}
	
	void Uninitialize() override {
		this->AltUninitialize();
		AtomBaseRef r = AtomBase::AsRefT();
		ASSERT(r);
		AtomBase::GetMachine().template Get<AtomSystem>()->Remove(r);
	}
	
	void AddPlan(Script::Plan& sp) override {
		ASSERT(!customer.IsEmpty());
		customer->plans.Add(sp);
	}
	
	void UpdateConfig(double dt) override {
		ASSERT(customer);
		/*{
			InterfaceSourceRef ss = AtomT::GetSource();
			InterfaceSource* o = ss.Get();
			TypeCls cls = AsTypeCls<DefaultInterfaceSource>();
			void* p = o->GetBasePtr(cls);
			DefaultInterfaceSource* pp = (DefaultInterfaceSource*)p;
		}*/
		DefaultInterfaceSourceRef src = AtomT::GetSource();
		ASSERT(src);
		if (src) {
			Stream& str = src->GetStream();
			Value& val = str.Get();
			customer->cfg.Update(dt, val.IsQueueFull());
		}
	}
	
	void VisitSource(RuntimeVisitor& vis) override {TODO}
	void VisitSink(RuntimeVisitor& vis) override {TODO}
	void Forward(FwdScope& fwd) override {}
	
	
	
};


template <class T>
class CenterSourceAsync : public Atom<T> {
	
protected:
	Serial::Format		internal_fmt;
	double				time = 0;
	byte				rolling_value = 0;
	
	using AtomT = Atom<T>;
	
public:
	using BaseT = CenterSourceAsync<T>;
	RTTI_DECL1(CenterSourceAsync, AtomT)
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!this->AltInitialize(ws)) return false;
		
		AtomTypeCls type = ((AtomBase*)this)->GetType();
		if (type.iface.src.val == ValCls::AUDIO)
			internal_fmt.SetAudio(DevCls::CENTER, SoundSample::U8_LE, 2, 44100, 777);
		else
			TODO;
		
		time = 0;
		return true;
	}
	
	void Uninitialize() override {
		this->AltUninitialize();
		
	}
	
	void Forward(FwdScope& fwd) override {
		RTLOG("CenterSourceAsync<T>::Forward");
	}

	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<AtomT>(this);}
	
	void VisitSource(RuntimeVisitor& vis) override {TODO}
	void VisitSink(RuntimeVisitor& vis) override {TODO}
	
};

template <class T>
class CenterSinkSync : public Atom<T> {
	
protected:
	RunningFlag		flag;
	byte			rolling_value = 0;
	
	
	using AtomT = Atom<T>;
	
	void IntervalSinkProcess0() {IntervalSinkProcess();}
	
public:
	typedef CenterSinkSync CLASSNAME;
	using BaseT = CenterSinkSync<T>;
	RTTI_DECL1(CenterSinkSync, AtomT)
	
	~CenterSinkSync() {ASSERT(!flag.IsRunning());}
	void CopyTo(AtomBase* atom) const override {TODO}
	void VisitSource(RuntimeVisitor& vis) override {TODO}
	void VisitSink(RuntimeVisitor& vis) override {TODO}
	virtual void IntervalSinkProcess() = 0;
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!this->AltInitialize(ws)) return false;
		flag.Start(1);
		Thread::Start(THISBACK(IntervalSinkProcess0));
		return true;
	}
	
	void Uninitialize() override {
		this->AltUninitialize();
		flag.Stop();
	}

	void Forward(FwdScope& fwd) override {
		RTLOG("CenterSinkSync<T>::Forward");
		AtomBase::ForwardVoidSink(fwd);
	}
	
	void StorePacket(Packet& p) override {
		RTLOG("CenterSinkSync<T>::StorePacket");
		//TODO
		//p->SetFormat(GetParent()->GetSourceValue().GetFormat());
	}
	
	
};

template <class T>
class CenterSinkPolling : public Atom<T> {
	
protected:
	
	using AtomT = Atom<T>;
	
public:
	typedef CenterSinkPolling CLASSNAME;
	using BaseT = CenterSinkPolling<T>;
	RTTI_DECL1(CenterSinkPolling, AtomT)
	
	
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!this->AltInitialize(ws)) return false;
		return true;
	}
	
	void Uninitialize() override {
		this->AltUninitialize();
	}
	
	void Forward(FwdScope& fwd) override {this->AltForward(fwd);}
	void VisitSource(RuntimeVisitor& vis) override {TODO}
	void VisitSink(RuntimeVisitor& vis) override {TODO}
	
};


template <class T>
class CenterSideSinkAsync :
	public Atom<
		T,
		DefaultInterfaceSink,
		DefaultInterfaceSource,
		DefaultInterfaceSideSink
	>
{
	
protected:
	
	using AtomT = Atom<T, DefaultInterfaceSink, DefaultInterfaceSource, DefaultInterfaceSideSink>;
	
public:
	using BaseT = CenterSideSinkAsync<T>;
	RTTI_DECL1(CenterSideSinkAsync, AtomT)
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!this->AltInitialize(ws)) return false;
		
		return true;
	}
	
	void Uninitialize() override {
		this->AltUninitialize();
		
	}
	
	void Forward(FwdScope& fwd) override {
		RTLOG("CenterSideSinkAsync<T>::Forward");
	}

	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<AtomT>(this);}
	
	void VisitSource(RuntimeVisitor& vis) override {TODO}
	void VisitSink(RuntimeVisitor& vis) override {TODO}
	
};


template <class T>
class CenterSideSourceAsync :
	public Atom<
		T,
		DefaultInterfaceSink,
		DefaultInterfaceSource,
		DefaultInterfaceSideSource
	>
{
	
protected:
	
	using AtomT = Atom<T, DefaultInterfaceSink, DefaultInterfaceSource, DefaultInterfaceSideSource>;
	
public:
	using BaseT = CenterSideSourceAsync<T>;
	RTTI_DECL1(CenterSideSourceAsync, AtomT)
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!this->AltInitialize(ws)) return false;
		
		return true;
	}
	
	void Uninitialize() override {
		this->AltUninitialize();
		
	}
	
	void Forward(FwdScope& fwd) override {
		RTLOG("CenterSideSourceAsync<T>::Forward");
	}

	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<AtomT>(this);}
	
	void VisitSource(RuntimeVisitor& vis) override {TODO}
	void VisitSink(RuntimeVisitor& vis) override {TODO}
	
};


template <class T>
class CenterDriver : public Atom<T> {
	
protected:
	using CustomerData = AtomBase::CustomerData;
	
	One<CustomerData>		customer;
	
	
protected:
	
	using AtomT = Atom<T>;
	
	
public:
	using BaseT = CenterDriver<T>;
	RTTI_DECL1(CenterDriver, AtomT)
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!this->AltInitialize(ws)) return false;
		customer.Create();
		AtomBaseRef r = AtomBase::AsRefT();
		ASSERT(r);
		AtomBase::GetMachine().template Get<AtomSystem>()->Add(r);
		return true;
	}
	
	void Uninitialize() override {
		this->AltUninitialize();
		AtomBaseRef r = AtomBase::AsRefT();
		ASSERT(r);
		AtomBase::GetMachine().template Get<AtomSystem>()->Remove(r);
	}
	
	void Forward(FwdScope& fwd) override {
		RTLOG("CenterDriver<T>::Forward");
		Panic("not implemented");
	}

	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<AtomT>(this);}
	
	void VisitSource(RuntimeVisitor& vis) override {TODO}
	void VisitSink(RuntimeVisitor& vis) override {TODO}
	
	void UpdateConfig(double dt) override {
		ASSERT(customer);
		customer->cfg.Update(dt, true);
	}
	
	RealtimeSourceConfig& GetConfig() override {ASSERT(customer); return customer->cfg;}
	
};



NAMESPACE_SERIAL_END

#endif
