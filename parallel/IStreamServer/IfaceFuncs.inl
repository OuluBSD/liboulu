// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.7 20:44:33

static bool StreamServer_Initialize(AtomBase&, const Script::WorldState&);
static bool StreamServer_PostInitialize(AtomBase&);
static bool StreamServer_Start(AtomBase&);
static void StreamServer_Stop(AtomBase&);
static void StreamServer_Uninitialize(AtomBase&);
static bool StreamServer_ProcessPacket(AtomBase&, PacketValue& in, PacketValue& out);

	
bool CreateServerInstance(NativeStreamServer& a0);
void ClearServerInstance(NativeStreamServer& a0);
void SetPort(NativeStreamServer& a0, int port);
bool Open(NativeStreamServer& a0);
bool Close(NativeStreamServer& a0);
