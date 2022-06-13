#include "AtomVR.h"

namespace TS {

namespace Parallel {

#if defined flagOPENHMD
AtomTypeCls OpenHMDPipe::GetAtomType()
{
	return ATOM11(OPEN_H_M_D_PIPE, PIPE, CENTER, EVENT, CENTER, ORDER, CENTER, EVENT);
}

LinkTypeCls OpenHMDPipe::GetLinkType()
{
	return LINKTYPE(PIPE, PROCESS);
}

void OpenHMDPipe::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<OpenHMDSinkDevice>(this);
}

AtomTypeCls OpenHMDPipe::GetType() const
{
	return GetAtomType();
}

#endif
AtomTypeCls UsbHoloPipe::GetAtomType()
{
	return ATOM11(USB_HOLO_PIPE, PIPE, CENTER, EVENT, CENTER, ORDER, CENTER, EVENT);
}

LinkTypeCls UsbHoloPipe::GetLinkType()
{
	return LINKTYPE(PIPE, PROCESS);
}

void UsbHoloPipe::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<DevUsbSinkDevice>(this);
}

AtomTypeCls UsbHoloPipe::GetType() const
{
	return GetAtomType();
}

AtomTypeCls BluetoothHoloPipe::GetAtomType()
{
	return ATOM11(BLUETOOTH_HOLO_PIPE, PIPE, CENTER, EVENT, CENTER, ORDER, CENTER, EVENT);
}

LinkTypeCls BluetoothHoloPipe::GetLinkType()
{
	return LINKTYPE(PIPE, PROCESS);
}

void BluetoothHoloPipe::Visit(RuntimeVisitor& vis)
{
	vis.VisitThis<DevBluetoothSinkDevice>(this);
}

AtomTypeCls BluetoothHoloPipe::GetType() const
{
	return GetAtomType();
}

}

}

