// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.1 19:22:00

static bool SinkDevice_Initialize(NativeSinkDevice& dev, AtomBase&, const Script::WorldState&);
static bool SinkDevice_PostInitialize(NativeSinkDevice& dev, AtomBase&);
static bool SinkDevice_Start(NativeSinkDevice& dev, AtomBase&);
static void SinkDevice_Stop(NativeSinkDevice& dev, AtomBase&);
static void SinkDevice_Uninitialize(NativeSinkDevice& dev, AtomBase&);
static bool SinkDevice_ProcessPacket(NativeSinkDevice& dev, AtomBase&, PacketValue& v);

static int SinkDevice_GetSinkDeviceCount();
static bool SinkDevice_CreateSinkDevice(int sink_i, NativeSinkDevice& o);
static void SinkDevice_ClearSinkDevice(NativeSinkDevice& o);
static bool SinkDevice_SetSinkCallback(void* data, DataCallbackFn cb);
static int SinkDevice_GetSinkFormatCount(NativeSinkDevice& o);
static bool SinkDevice_GetSinkFormat(NativeSinkDevice& o, int ch_i, int& channels, int& samplerate, int& bytes, bool& is_signed, bool& is_float);
	
static bool SourceDevice_Initialize(NativeSourceDevice& dev, AtomBase&, const Script::WorldState&);
static bool SourceDevice_PostInitialize(NativeSourceDevice& dev, AtomBase&);
static bool SourceDevice_Start(NativeSourceDevice& dev, AtomBase&);
static void SourceDevice_Stop(NativeSourceDevice& dev, AtomBase&);
static void SourceDevice_Uninitialize(NativeSourceDevice& dev, AtomBase&);
static bool SourceDevice_ProcessPacket(NativeSourceDevice& dev, AtomBase&, PacketValue& v);

static int SourceDevice_GetSourceDeviceCount();
static bool SourceDevice_CreateSourceDevice(int sink_i, NativeSourceDevice& o);
static void SourceDevice_ClearSourceDevice(NativeSourceDevice& o);
static bool SourceDevice_SetSourceCallback(void* data, DataCallbackFn cb);
static int SourceDevice_GetSourceFormatCount(NativeSourceDevice& o);
static bool SourceDevice_GetSourceFormat(NativeSourceDevice& o, int ch_i, int& channels, int& samplerate, int& bytes, bool& is_signed, bool& is_float);
	
