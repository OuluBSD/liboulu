// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 2022.4.3 11:11:55

static bool MessageBus_Initialize(AtomBase&, const Script::WorldState&);
static bool MessageBus_PostInitialize(, AtomBase&);
static bool MessageBus_Start(, AtomBase&);
static void MessageBus_Stop(, AtomBase&);
static void MessageBus_Uninitialize(, AtomBase&);
static bool MessageBus_ProcessPacket(AtomBase&, PacketValue& v);

	
static bool ProcessManager_Initialize(AtomBase&, const Script::WorldState&);
static bool ProcessManager_PostInitialize(, AtomBase&);
static bool ProcessManager_Start(, AtomBase&);
static void ProcessManager_Stop(, AtomBase&);
static void ProcessManager_Uninitialize(, AtomBase&);
static bool ProcessManager_ProcessPacket(AtomBase&, PacketValue& v);

	
static bool DesktopManager_Initialize(AtomBase&, const Script::WorldState&);
static bool DesktopManager_PostInitialize(, AtomBase&);
static bool DesktopManager_Start(, AtomBase&);
static void DesktopManager_Stop(, AtomBase&);
static void DesktopManager_Uninitialize(, AtomBase&);
static bool DesktopManager_ProcessPacket(AtomBase&, PacketValue& v);

	
bool CreateMessageBus(NativeMessageBus& a0);
void ClearMessageBus(NativeMessageBus& a0);
