#ifndef _EcsCore_Interface_h_
#define _EcsCore_Interface_h_


NAMESPACE_OULU_BEGIN




class InterfaceBase : public LockedScopeEnabler<InterfaceBase> {
	void DbgChk(InterfaceBase* b);
	
protected:
	Vector<InterfaceBase*> conns;
	bool is_multi_connection = false;
	
	virtual bool Unlink0(InterfaceBase* iface) {return true;}
	
	static String GetComponentBaseTypeString(ComponentBase* base);
	
public:
	virtual ~InterfaceBase() {UnlinkAll();}
	
	void UnlinkAll() {for(auto c: conns) c->RemoveConnection(this); conns.Clear();}
	void RemoveConnection(InterfaceBase* b);
	void AddConnection(InterfaceBase* b) {ASSERT(Find(b) < 0); DbgChk(b); conns.Add(b);}
	int Find(InterfaceBase* b) {int i=0; for(auto c: conns) {if(c==b) return i; i++;} return -1;}
	
	const Vector<InterfaceBase*>& GetConnections() const {return conns;}
	int GetConnectionCount() const {return conns.GetCount();}

	void SetMultiConnection(bool b=true) {is_multi_connection = b;}
	bool IsMultiConnection() const {return is_multi_connection;}
	bool IsLinkable() const {return is_multi_connection || conns.IsEmpty();}
	
	virtual State* OnLink(InterfaceBase* iface) {return NULL;}
	virtual void OnUnlink(InterfaceBase* iface) {}
	virtual ComponentBase* AsComponentBase() = 0;
	virtual TypeId GetInterfaceType() = 0;
	
};

template <class I>
struct InterfaceSink : public InterfaceBase {
	
	
};

#ifdef flagDEBUG
void InterfaceDebugPrint(TypeId type, String s);
#endif

template <class I, class O>
struct InterfaceSource : public InterfaceBase {
	struct Connection : Moveable<Connection> {
		O* sink;
		State* src_state = 0;
		State* sink_state = 0;
		Connection(O* o) {sink = o;}
		bool operator==(const Connection& c) const {return sink == c.sink;}
	};
	
	bool LinkManually(O& sink, State** ret_src_state=0, State** ret_sink_state=0) {return Link0(sink, ret_src_state, ret_sink_state);}
	bool UnlinkManually(InterfaceBase& iface) {return Unlink0(&iface);}
	
	const Vector<Connection>& GetSinks() const {return sinks;}
	
	virtual bool Link(O& sink) {return true;}
	virtual bool Unlink(O& sink) {return true;}
	
protected:
	
	Vector<Connection> sinks;
	
	#ifdef flagDEBUG
	static const bool print_debug = true;
	#else
	static const bool print_debug = false;
	#endif
	
	bool LinkInterface(O& sink, State**& src_state, State**& sink_state) {
		int found = -1;
		Connection& conn = VectorFindAdd(sinks, Connection(&sink), &found);
		src_state = &conn.src_state;
		sink_state = &conn.sink_state;
		return found < 0;
	}
	bool UnlinkInterface(O& sink) {
		return VectorRemoveKey(sinks, Connection(&sink)) > 0;
	}
	
	
	bool Link0(O& sink, State** ret_src_state=0, State** ret_sink_state=0) {
		ASSERT(conns.IsEmpty() || IsMultiConnection());
		if (Find(&sink) >= 0)
			return false;
		State** src_state;
		State** sink_state;
		if (Link(sink) && LinkInterface(sink, src_state, sink_state)) {
			if (print_debug) {
				String s;
				TypeId t = GetTypeId<I>();
				s << t.CleanDemangledName() <<
					"<" << GetComponentBaseTypeString(AsComponentBase()) << "> linked to " <<
					GetTypeId<O>().CleanDemangledName() <<
					"<" << GetComponentBaseTypeString(sink.AsComponentBase()) << ">";
				InterfaceDebugPrint(t, s);
			}
			AddConnection(&sink);
			sink.AddConnection(this);
			*src_state = OnLink(&sink);
			*sink_state = sink.OnLink(this);
			if (ret_src_state)
				*ret_src_state = *src_state;
			if (ret_sink_state)
				*ret_sink_state = *sink_state;
			return true;
		}
		return false;
	}
	
	virtual bool Unlink0(InterfaceBase* iface) {
		O* o = dynamic_cast<O*>(iface);
		ASSERT_(o, "Unlink before destructor");
		if (o) {
			OnUnlink(iface);
			iface->OnUnlink(this);
			if (Unlink(*o) && UnlinkInterface(*o)) {
				if (print_debug) {
					TypeId t = GetTypeId<I>();
					String s;
					s << t.CleanDemangledName() << " unlinked from " << GetTypeId<O>().CleanDemangledName();
					InterfaceDebugPrint(t, s);
				}
				return true;
			}
			else {
				LOG("error: couldn't unlink " << GetTypeId<I>().CleanDemangledName() << " from " << GetTypeId<O>().DemangledName());
			}
		}
		return false;
	}
};
#define IO_OUT(x)		public InterfaceSink<x##Sink>
#define IO_IN(x)		public InterfaceSource<x##Source, x##Sink>
#define IFACE_BASE(x)	TypeId GetInterfaceType() override {return TypeId(typeid(x));}


//									---- Display ----

// The line between the display and the video connector is thin. Display IO is used by those
// components that primarily read or write video at display speed and resolution, and whose
// content would be human-viewable (rather than just processable).

struct DisplaySource;

struct DisplaySinkConfig {
	double fps;
	double fps_dt;
	double dt;
};

struct DisplaySink : IO_OUT(Display) {
	IFACE_BASE(DisplaySink)
	
	virtual void RecvDisplaySink(DisplaySource& src, double dt) = 0;
	virtual void SetTitle(String s) = 0;
	virtual uint32 GetTickCount() = 0;
	
};

struct DisplaySource : IO_IN(Display) {
	IFACE_BASE(DisplaySource)
	
	virtual void EmitDisplaySource(double dt) = 0;
	virtual bool Render(const DisplaySinkConfig& config, SystemDraw& draw) = 0;
	
	virtual void SetTitle(String s) {for (const Connection& c : GetSinks()) c.sink->SetTitle(s);}
	
};



//									---- Audio ----

// The boundary between audio playback and media streaming is also thin, as between display and
// video. The audio playback data format must conform to the hardware specification, but the
// media stream does not. Also, if the data to be transferred has clear beginnings and endings,
// and if only one source is transferred at a time, it is better to call it media. When audio
// data contains multiple unrelated audio sources, it is better to call it an audio stream.
struct AudioSinkConfig {
	double dt = 0;
	double sync_dt = 0;
	double sync_age = 0;
    dword last_sync_sink_frame = 0;
	dword frames_after_sync = 0;
	dword sink_frame = 0;
	bool sync = 0;
};

struct AudioSource;
struct AudioSink : IO_OUT(Audio) {
	IFACE_BASE(AudioSink)
	
	virtual void			RecvAudioSink(AudioSource& src, double dt) = 0;
	
	virtual SoundProxy&		BeginPlay() = 0;
	virtual void			CommitPlay() = 0;
	virtual void			UndoPlay() = 0;
	virtual SoundFormat		GetFormat() = 0;
	/*virtual bool			IsAudioSampleFloating() = 0;
	virtual int				GetAudioSampleSize() = 0;
	virtual int				GetAudioSampleRate() = 0;
	virtual int				GetAudioChannels() = 0;
	virtual int				GetAudioFrequency() = 0;*/
	
	void DefaultRecvAudioSink(AudioSinkConfig& cfg, AudioSource& src, double dt, Sound& snd);
	
};
struct AudioSource : IO_IN(Audio) {
	IFACE_BASE(AudioSource)
	
	virtual void EmitAudioSource(double dt) = 0;
	virtual void Play(const AudioSinkConfig& config, Sound& snd) = 0;
	
	void DefaultEmitAudioSource(double dt, int sink_limit=-1);
	
};
extern AudioSink* VirtualSoundPtr;






//									---- Camera ----

// With a camera connector, the component provides a location for viewing the virtual world.
// The connector can also move the camera slightly (for VR headset tracking) and modify its
// features.

struct CameraSource;
struct CameraSink : IO_OUT(Camera) {
	IFACE_BASE(CameraSink)
	
	virtual Ref<Camerable> GetCamerable() = 0;
	virtual Ref<Transform> GetTransform() = 0;
	
};

struct CameraSource : IO_IN(Camera) {
	IFACE_BASE(CameraSource)
	
};





//									---- Controller ----

// The controller connector can be used to transmit, for example, keyboard, mouse and game
// controller events. It can also send events to the controller, such as force feedback
// effects. The connector can also be used to transfer more abstract data, such as if
// artificial intelligence controls game entities.

// If the desired application does not match any other connector, then use the controller.

struct ControllerSink : IO_OUT(Controller) {
	IFACE_BASE(ControllerSink)
	
	virtual void RecvController(const EventFrame& e) = 0;
	
};

struct ControllerSource : IO_IN(Controller) {
	IFACE_BASE(ControllerSource)
	// force feedback, etc.
	
	typedef enum {
		CTRL_SYSTEM,
		CTRL_KEYBOARD,
		CTRL_MOUSE,
		CTRL_JOYSTICK,
		CTRL_GAMEPAD,
		CTRL_SENSOR,
	} CtrlType;
	
	virtual void EmitController(double dt) = 0;
	virtual bool IsSupported(CtrlType type) = 0;
	
	bool IsSupportedKeyboard() {return IsSupported(CTRL_KEYBOARD);}
	
};




//									---- Midi ----

// The controller connector can be used to transmit, for example, keyboard, mouse and game
// controller events. It can also send events to the controller, such as force feedback
// effects. The connector can also be used to transfer more abstract data, such as if
// artificial intelligence controls game entities.

// If the desired application does not match any other connector, then use the controller.

namespace Midi {
	class File;
	class Event;
}

class MidiFrame {
	
public:
	Vector<const Midi::Event*> midi;
	
	void Reset() {midi.SetCount(0);}
};

struct MidiSinkConfiguration {
	Vector<bool> track_accepted;
};

struct MidiSink : IO_OUT(Midi) {
	IFACE_BASE(MidiSink)
	MidiSinkConfiguration conf;
	
	bool AcceptsTrack(int i) const {return i >= 0 && i < conf.track_accepted.GetCount() && conf.track_accepted[i];}
	
	virtual void RecvMidi(const MidiFrame& e) = 0;
	virtual void Configure(const Midi::File& file) = 0;
	
};

struct MidiSource : IO_IN(Midi) {
	IFACE_BASE(MidiSource)
	
	typedef enum {
		MIDIDEV_PIANO,
		MIDIDEV_DRUMS,
		MIDIDEV_GUITAR,
	} DevType;
	
	virtual void EmitMidi(double dt) = 0;
	virtual bool IsSupported(DevType type) = 0;
	
	bool IsSupportedPiano() {return IsSupported(MIDIDEV_PIANO);}
	
};




//									---- Media ----

// The media connector can be used to transfer audio or AV data. Moving only video is also
// correct, but taking audio data into account in classes is forced to make classes more
// general.

struct MediaSink : IO_OUT(Media) {
	IFACE_BASE(MediaSink)
	
	
	virtual void RecvMedia(Media& media) = 0;
	
};

struct MediaSource : IO_IN(Media) {
	IFACE_BASE(MediaSource)
	
	virtual bool LoadFileAny(String path) {return false;}
	virtual Size GetResolution() const {return Size(0,0);}
	virtual void EmitMedia() = 0;
	
	
};





//									---- Model ----

// The model connector transfers 3D data with textures and other additional data. It takes into
// account dynamically changing detail. This can also be used for 3D streams.

typedef RTuple<Ref<Model>, Ref<Transform>, Ref<Renderable>> RendModel;
typedef Vector<RendModel> VectorRendModel;

struct ModelSink : IO_OUT(Model) {
	IFACE_BASE(ModelSink)
	
	virtual void GetModels(VectorRendModel& models) {}
	
};

struct ModelSource : IO_IN(Model) {
	IFACE_BASE(ModelSource)
	
	
};





//									---- Static ----

// The static connector is used for data that is in a grid format. Also, the data should not
// change itself, except for data set manually by the user. Different levels of detail are also
// supported. At its most complex, the connector enables octree-type solutions.

struct StaticSinkData {
	int obj_i;
	int w;
	int h;
	int d;
	int stride;
	int pitch;
	const byte* data;
};

struct StaticSink : IO_OUT(Static) {
	IFACE_BASE(StaticSink)
	
	virtual void RecvStatic(const StaticSinkData&) = 0;
};

struct StaticSource : IO_IN(Static) {
	IFACE_BASE(StaticSource)
	
	virtual bool LoadFileAny(String path) {return false;}
	virtual bool GetImage(Image& img) {return false;}
	virtual Size GetResolution() const {return Size(0,0);}
	virtual int GetDepth() const {return 1;}
	virtual void EmitStatic() = 0;
	
};






//									---- Fusion ----


class FusionComponentInput;

struct FusionSink : IO_OUT(Fusion) {
	IFACE_BASE(FusionSink)
	
	FusionSink() {
		SetMultiConnection();
	}
	
	
};

struct FusionSource : IO_IN(Fusion) {
	IFACE_BASE(FusionSource)
	
	FusionSource() {
		SetMultiConnection();
	}
	
	virtual const FusionComponentInput& GetHeader() const = 0;
	
};






//									---- Semantic ----


struct SemanticSink : IO_OUT(Semantic) {
	IFACE_BASE(SemanticSink)
	
	SemanticSink() {
		SetMultiConnection();
	}
	
	
};

struct SemanticSource : IO_IN(Semantic) {
	IFACE_BASE(SemanticSource)
	
	SemanticSource() {
		SetMultiConnection();
	}
	
};






//									---- Overlap ----

struct OverlapSink : IO_OUT(Overlap) {
	IFACE_BASE(OverlapSink)
	
	OverlapSink() {
		SetMultiConnection();
	}
	
	
};

struct OverlapSource : IO_IN(Overlap) {
	IFACE_BASE(OverlapSource)
	
	OverlapSource() {
		SetMultiConnection();
	}
	
};






//									---- Action ----

typedef int ActionGroup;
typedef int ActionId;
typedef int AtomId;
struct ActionSink;
struct ActionSource;

#define SOURCE_EXCHANGE(x) \
	virtual bool RequestExchange(x##Sink& sink) = 0; \
	virtual bool On##x##Source(x##Exchange& e) = 0;

#define SINK_EXCHANGE(x) \
	virtual bool RequestExchange(x##Source& src) = 0; \
	virtual bool On##x##Sink(x##Exchange& e) = 0;

struct ActionExchange : public Exchange {
	/*
	// Sink
	virtual bool Act(ActionGroup ag, ActionId act) = 0;
	virtual bool UpdateAct() = 0;
	
	// Source
	virtual ActionGroup AddActionGroup(ActionSink& sink, int act_count, int atom_count) = 0;
	virtual void SetActionName(ActionGroup ag, ActionId act_i, String name) = 0;
	virtual void SetCurrentAtom(ActionGroup ag, AtomId atom_i, bool value) = 0;
	virtual void SetGoalAtom(ActionGroup ag, AtomId atom_i, bool value) = 0;
	virtual void RefreshActionPlan() = 0;
	virtual void OnActionDone(ActionGroup ag, ActionId act_i, int ret_code) = 0;
	*/
};

struct ActionSink : IO_OUT(Action) {
	IFACE_BASE(ActionSink)
	SINK_EXCHANGE(Action);
	
	ActionSink() {
		SetMultiConnection();
	}
	
	State* OnLink(InterfaceBase* iface) override;
	virtual State* OnLinkActionSource(ActionSource& src) = 0;
	
	
	
	
};

struct ActionSource : IO_IN(Action) {
	IFACE_BASE(ActionSource)
	SOURCE_EXCHANGE(Action);
	
	ActionSource() {
		SetMultiConnection();
	}
	
	virtual void EmitActionSource(double dt) = 0;
	
	/*
	*/
};



//									---- Route ----


struct RouteSink : IO_OUT(Route) {
	IFACE_BASE(RouteSink)
	
	RouteSink() {
		SetMultiConnection();
	}
	
	
};

struct RouteSource : IO_IN(Route) {
	IFACE_BASE(RouteSource)
	
	RouteSource() {
		SetMultiConnection();
	}
	
	
	virtual void SetIdleCost(double d) = 0;
	virtual double GetStepValue(const Connection& conn) = 0;
	virtual double GetHeuristicValue(RouteSink& sink) = 0;
};



#define COPY_PANIC(T) void operator=(const T& t) {Panic("Can't copy " #T);}

#define IFACE_GENERIC	ComponentBase* AsComponentBase() override {return this;}
#define IFACE_CB(x)		Ref<x> As##x() override {return ((x*)this)->AsRef();}

#define IFACE_LIST \
	IFACE(Display)\
	IFACE(Audio)\
	IFACE(Controller)\
	IFACE(Midi)\
	IFACE(Camera)\
	IFACE(Media)\
	IFACE(Model)\
	IFACE(Static) \
	IFACE(Fusion) \
	IFACE(Semantic) \
	IFACE(Overlap) \
	IFACE(Action) \
	IFACE(Route)
	
	
typedef enum {
	#define IFACE(x) IFACE_##x##Source , IFACE_##x##Sink ,
	IFACE_LIST
	#undef IFACE
} IfaceType;


NAMESPACE_OULU_END


#endif
