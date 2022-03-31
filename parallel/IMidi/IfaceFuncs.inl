// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.3.31 23:44:55

static bool MidiSinkDevice_Initialize(NativeSinkDevice& dev, AtomBase&, const Script::WorldState&);
static bool MidiSinkDevice_PostInitialize(NativeSinkDevice& dev);
static bool MidiSinkDevice_Start(NativeSinkDevice& dev);
static void MidiSinkDevice_Stop(NativeSinkDevice& dev);
static void MidiSinkDevice_Uninitialize(NativeSinkDevice& dev);
static bool MidiSinkDevice_ProcessPacket(NativeSinkDevice& dev, PacketValue& v);

static int MidiSinkDevice_GetSinkDeviceCount();
static bool MidiSinkDevice_CreateSinkDevice(int dev_i, NativeSinkDevice& o);
static void MidiSinkDevice_ClearSinkDevice(NativeSinkDevice& o);
static bool MidiSinkDevice_PollSink(NativeSinkDevice& o, NativeEvent& ev);
	
static bool MidiSourceDevice_Initialize(NativeSourceDevice& dev, AtomBase&, const Script::WorldState&);
static bool MidiSourceDevice_PostInitialize(NativeSourceDevice& dev);
static bool MidiSourceDevice_Start(NativeSourceDevice& dev);
static void MidiSourceDevice_Stop(NativeSourceDevice& dev);
static void MidiSourceDevice_Uninitialize(NativeSourceDevice& dev);
static bool MidiSourceDevice_ProcessPacket(NativeSourceDevice& dev, PacketValue& v);

static int MidiSourceDevice_GetSourceDeviceCount();
static bool MidiSourceDevice_CreateSourceDevice(int dev_i, NativeSourceDevice& o);
static void MidiSourceDevice_ClearSourceDevice(NativeSourceDevice& o);
static bool MidiSourceDevice_PollSource(NativeSourceDevice& o, NativeEvent& ev);
	
