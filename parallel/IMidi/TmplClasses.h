// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 29.3.29 19:55:44

#ifndef _IMidi_TmplClasses_h_
#define _IMidi_TmplClasses_h_

NAMESPACE_PARALLEL_BEGIN

template <class Mid> struct MidiMidiSinkDeviceT;
template <class Mid> struct MidiMidiSourceDeviceT;


template <class Mid>
struct MidiMidiSinkDeviceT : MidMidiSinkDevice {
	typename Mid::NativeSinkDevice dev;
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!Mid::SinkDevice_Initialize(dev, *this, ws))
			return false;
		return true;
	}

	void Uninitialize() override {
		Mid::SinkDevice_Uninitialize(dev);
	}

	bool ProcessPacket(PacketValue& v) override {
		if (!Mid::SinkDevice_ProcessPacket(dev, v))
			return false;
		return true;
	}

	int GetSinkDeviceCount() {
		return Mid::MidiSinkDevice_GetSinkDeviceCount();
	}
	
	bool CreateSinkDevice(int dev_i) {
		return Mid::MidiSinkDevice_CreateSinkDevice(dev_i, this->dev);
	}
	
	void ClearSinkDevice() {
		Mid::MidiSinkDevice_ClearSinkDevice(this->dev);
	}
	
	bool PollSink(NativeEvent& ev) {
		return Mid::MidiSinkDevice_PollSink(this->dev, ev);
	}
	
	
};

template <class Mid>
struct MidiMidiSourceDeviceT : MidMidiSourceDevice {
	typename Mid::NativeSourceDevice dev;
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!Mid::SourceDevice_Initialize(dev, *this, ws))
			return false;
		return true;
	}

	void Uninitialize() override {
		Mid::SourceDevice_Uninitialize(dev);
	}

	bool ProcessPacket(PacketValue& v) override {
		if (!Mid::SourceDevice_ProcessPacket(dev, v))
			return false;
		return true;
	}

	int GetSourceDeviceCount() {
		return Mid::MidiSourceDevice_GetSourceDeviceCount();
	}
	
	bool CreateSourceDevice(int dev_i) {
		return Mid::MidiSourceDevice_CreateSourceDevice(dev_i, this->dev);
	}
	
	void ClearSourceDevice() {
		Mid::MidiSourceDevice_ClearSourceDevice(this->dev);
	}
	
	bool PollSource(NativeEvent& ev) {
		return Mid::MidiSourceDevice_PollSource(this->dev, ev);
	}
	
	
};

using PortmidiMidiSinkDevice = MidiMidiSinkDeviceT<MidPortmidi>;
using PortmidiMidiSourceDevice = MidiMidiSourceDeviceT<MidPortmidi>;


NAMESPACE_PARALLEL_END



#endif

