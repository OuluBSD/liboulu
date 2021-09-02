#ifndef _SerialMach_Generated_h_
#define _SerialMach_Generated_h_


#define SERIAL_TYPE_LIST \
	SERIAL_TYPE(LOOP_STORE) \
	SERIAL_TYPE(REGISTRY_SYSTEM) \
	SERIAL_TYPE(ATOM_STORE) \
	SERIAL_TYPE(ATOM_SYSTEM) \
	\
	SERIAL_TYPE(CUSTOM_ATOM) \
	\
	SERIAL_TYPE(DUMMY_SERIAL_TYPE) \
	

#define SERIAL_BASE_LIST \
	SERIAL_BASE(DUMMY_SERIAL_BASE) \


#define IFACE_LIST \
	IFACE(AUDIO) \
	IFACE(VIDEO) \
	IFACE(MIDI) \
	IFACE(EVENT) \
	IFACE(DATA) \
	IFACE(ORDER) \
	IFACE(RECEIPT) \


#define DEV_IFACE(val) \
	IFACE_CTX_CLS(CENTER, val, ) \
	IFACE_CTX_CLS(PERMA, val, Perma) \
	IFACE_CTX_CLS(ACCEL, val, Accel) \
	IFACE_CTX_CLS(NET, val, Net) \


#endif
