#ifndef _SerialCore_Atom_h_
#define _SerialCore_Atom_h_

NAMESPACE_TOPSIDE_BEGIN
namespace Serial {

namespace Script {
class WorldState;
class Plan;
}

}
NAMESPACE_TOPSIDE_END


NAMESPACE_PARALLEL_BEGIN
using namespace Serial;

class AtomBase;

template <class T> inline SideStatus MakeSide(const AtomTypeCls& src_type, const Script::WorldState& from, const AtomTypeCls& sink_type, const Script::WorldState& to) {Panic("Unimplemented"); NEVER();}
template <class T> inline RefT_Atom<T> AtomBase_Static_As(AtomBase*) {return RefT_Atom<T>();}

class AtomBase :
	public Destroyable,
	public Enableable,
	public PacketForwarderData,
	public RefScopeEnabler<AtomBase, MetaSpaceBase>
{
	
	
public:
	using AtomBaseRef = Ref<AtomBase, AtomParent>;
	
	struct CustomerData {
		RealtimeSourceConfig	cfg;
		off32_gen				gen;
		
		CustomerData();
		~CustomerData();
	};
	
	
	
protected:
	friend class Serial::ScriptLoopLoader;
	friend class Serial::ScriptDriverLoader;
	friend class Serial::Loop;
	
	int						id = -1;
	bool					is_running = false;
	
	void					SetId(int i) {id = i;}
	void					SetRunning(bool b=true) {is_running = b;}
	
protected:
	friend class Serial::LinkBase;
	
	Mutex					fwd_lock;
	IfaceConnTuple			iface;
	Serial::LinkBase*		link = 0;
	//Format				user_internal_fmt;
	AtomBaseRef				atom_dependency;
	HiValue					user_data;
	
	
public:
	virtual AtomTypeCls		GetType() const = 0;
	virtual void			CopyTo(AtomBase* atom) const = 0;
	virtual bool			Initialize(const Script::WorldState& ws) = 0;
	virtual bool			InitializeAtom(const Script::WorldState& ws) = 0;
	virtual void			Uninitialize() = 0;
	virtual void			UninitializeAtom() = 0;
	virtual void			VisitSource(RuntimeVisitor& vis) = 0;
	virtual void			VisitSink(RuntimeVisitor& vis) = 0;
	virtual void			ClearSinkSource() = 0;
	virtual ISourceRef		GetSource() = 0;
	virtual ISinkRef		GetSink() = 0;
	virtual bool			ProcessPacket(PacketValue& in, PacketValue& out) = 0;
	
	virtual bool			Start() {return true;}
	virtual void			Stop() {}
	virtual void			Visit(RuntimeVisitor& vis) {vis & atom_dependency;}
	virtual bool			PostInitialize() {return true;}
	virtual void			Update(double dt) {}
	virtual String			ToString() const;
	virtual bool			IsReady(PacketIO& io) {return true;}
	virtual void			UpdateConfig(double dt) {Panic("Unimplemented"); NEVER();}
	virtual bool			Recv(int sink_ch, PacketValue& in) {Panic("Unimplemented"); NEVER();}
	virtual void			Finalize(RealtimeSourceConfig& cfg) {Panic("Unimplemented"); NEVER();}
	// internal format should be sink:0
	//virtual const Format&	GetInternalFormat() const {ASSERT(user_internal_fmt.IsValid()) return user_internal_fmt;}
	//virtual void			SetInternalFormat(const Format& f) {user_internal_fmt = f;}
	virtual bool			Consume(const void* data, int len) {Panic("Unimplemented"); return false;}
	virtual bool			IsForwardReady() {Panic("Unimplemented"); NEVER();}
	virtual void			ForwardPacket(PacketValue& in, PacketValue& out) {Panic("Unimplemented"); NEVER();}
	virtual bool			AttachContext(AtomBase& a) {Panic("Unimplemented"); NEVER();}
	virtual void			DetachContext(AtomBase& a) {Panic("Unimplemented"); NEVER();}
	virtual RealtimeSourceConfig* GetConfig() {return 0;}
	virtual bool			NegotiateSinkFormat(Serial::Link& link, int sink_ch, const Format& new_fmt) {return false;}
	
	HiValue&				UserData() {return user_data;}
	bool					IsRunning() const {return is_running;}
	void					AddAtomToUpdateList();
	void					RemoveAtomFromUpdateList();
	void					SetDependency(AtomBaseRef a) {atom_dependency = a;}
	AtomBaseRef				GetDependency() const {return atom_dependency;}
	void					ClearDependency() {atom_dependency.Clear();}
	void					UpdateSinkFormat(ValCls val, Format fmt);
	void					PostContinueForward();
	
	static SideStatus MakeSide(const AtomTypeCls& src_type, const Script::WorldState& from, const AtomTypeCls& sink_type, const Script::WorldState& to) {
		ValDevCls common_vd = src_type.iface.src.GetCommon(sink_type.iface.sink);
		if (common_vd.IsValid())
			return SIDE_ACCEPTED;
		else
			return SIDE_NOT_ACCEPTED;
	}
	
	
	Machine&				GetMachine();
	void					UninitializeDeep();
	void					SetInterface(const IfaceConnTuple& iface);
	const IfaceConnTuple&	GetInterface() const;
	int						FindSourceWithValDev(ValDevCls vd);
	
public:
	RTTI_DECL_R3(AtomBase, Destroyable, Enableable, PacketForwarderData)
	AtomBase();
	virtual ~AtomBase();
	
	
	SpaceRef		GetSpace();
	Space&			GetParent();
	Serial::Link*	GetLink();
	int				GetId() const {return id;}
	
	template <class T> RefT_Atom<T> As() {return AtomBase_Static_As<T>(this);}
	
	template <class S, class R>
	void AddToSystem(R ref) {
		Ref<S> sys = GetMachine().Get<S>();
		if (sys)
			sys->Add(ref);
	}
	
	template <class S, class R>
	void RemoveFromSystem(R ref) {
		Ref<S> sys = GetMachine().Get<S>();
		if (sys)
			sys->Remove(ref);
	}
	
	template <class ValDevSpec, class T> bool LinkManually(T& o, String* err_msg=0);
	
	
};





struct Atom :
	public AtomBase,
	public DefaultInterfaceSink,
	public DefaultInterfaceSource
{
public:
	RTTI_DECL3(Atom, AtomBase, DefaultInterfaceSink, DefaultInterfaceSource)
	using SinkT = DefaultInterfaceSink;
	using SourceT = DefaultInterfaceSource;
	
	
	bool InitializeAtom(const Script::WorldState& ws) override {
		return SinkT::Initialize() && SourceT::Initialize();
	}
	
	void UninitializeAtom() override {
		SinkT::Uninitialize();
		SourceT::Uninitialize();
	}
	
	void ClearSinkSource() override {
		SinkT::ClearSink();
		SourceT::ClearSource();
	}
	
	void Visit(RuntimeVisitor& vis) override {
		vis.VisitThis<AtomBase>(this);
		vis.VisitThis<SinkT>(this);
		vis.VisitThis<SourceT>(this);
	}
	
	void VisitSource(RuntimeVisitor& vis) override {
		vis.VisitThis<SourceT>(this);
	}
	
	void VisitSink(RuntimeVisitor& vis) override {
		vis.VisitThis<SinkT>(this);
	}

	void CopyTo(AtomBase* target) const override {
		ASSERT(target->GetType() == ((AtomBase*)this)->GetType());
	    
	    TODO
		//*static_cast<T*>(target) = *static_cast<const T*>(this);
	}
	
	
	InterfaceSourceRef GetSource() override {
		InterfaceSource* src = static_cast<InterfaceSource*>(this);
		ASSERT(src);
		return InterfaceSourceRef(GetParentUnsafe(), src);
	}
	
	InterfaceSinkRef GetSink() override {
		InterfaceSink* sink = static_cast<InterfaceSink*>(this);
		ASSERT(sink);
		return InterfaceSinkRef(GetParentUnsafe(), sink);
	}
	
	AtomBase* AsAtomBase() override {return static_cast<AtomBase*>(this);}
	void ClearSink() override {TODO}
	void ClearSource() override {TODO}
	
	
	static ParallelTypeCls::Type GetSerialType() {return ParallelTypeCls::CUSTOM_ATOM;}
	
	
};


#define ATOM_RTTI(x)  RTTI_DECL1(x, Atom<x>)

using AtomRefMap	= ArrayMap<AtomTypeCls,Ref<AtomBase>>;

#if 0
using AtomMap	= RefAtomTypeMapIndirect<AtomBase>;
#else

using AtomMapBase	= RefAtomTypeMapIndirect<AtomBase>;

class AtomMap : public AtomMapBase {
	
	void ReturnAtom(AtomStore& s, AtomBase* c);
	
public:
	
	AtomMap() {}
	
	#define IS_EMPTY_SHAREDPTR(x) (x.IsEmpty())
	
	void Dump();
	
	template<typename AtomT>
	RefT_Atom<AtomT> Get() {
		CXX2A_STATIC_ASSERT(AtomStore::IsAtom<AtomT>::value, "T should derive from Atom");
		
		AtomMapBase::Iterator it = AtomMapBase::Find(AsParallelTypeCls<AtomT>());
		ASSERT(!IS_EMPTY_SHAREDPTR(it));
		if (it.IsEmpty())
			THROW(Exc("Could not find atom " + AsTypeString<AtomT>()));
		
		return it->AsRef<AtomT>();
	}
	
	template<typename AtomT>
	RefT_Atom<AtomT> Find() {
		CXX2A_STATIC_ASSERT(AtomStore::IsAtom<AtomT>::value, "T should derive from Atom");
		
		AtomMapBase::Iterator it = AtomMapBase::Find(AsParallelTypeCls<AtomT>());
		if (IS_EMPTY_SHAREDPTR(it))
			return Null;
		else
			return it->AsRef<AtomT>();
	}
	
	template<typename AtomT>
	void Add(AtomT* atom) {
		CXX2A_STATIC_ASSERT(AtomStore::IsAtom<AtomT>::value, "T should derive from Atom");
		
		AtomTypeCls type = atom->GetType();
		ASSERT(type.IsValid());
		AtomMapBase::Add(type, atom);
	}
	
	template<typename AtomT>
	void Remove(AtomStoreRef s) {
		CXX2A_STATIC_ASSERT(AtomStore::IsAtom<AtomT>::value, "T should derive from Atom");
		
		AtomMapBase::Iterator iter = AtomMapBase::Find(AsParallelTypeCls<AtomT>());
		ASSERT_(iter, "Tried to remove non-existent atom");
		
		TODO //iter.value().Uninitialize();
		
		//iter.value().Destroy();
		
		ReturnAtom(*s, iter.value.GetItem()->value.Detach());
		AtomMapBase::Remove(iter);
	}
	
	void AddBase(AtomBase* atom) {
		AtomTypeCls type = atom->GetType();
		ASSERT(type.IsValid());
		//AtomMapBase::Iterator it = AtomMapBase::Find(type);
		AtomMapBase::Add(type, atom);
	}
	
	#undef IS_EMPTY_SHAREDPTR
	
};
#endif


NAMESPACE_PARALLEL_END

#endif
