#include "SerialMach.h"

NAMESPACE_SERIAL_BEGIN







DevCls GetCenterDevCls() {
	DevCls c;
	c.type = DevCls::CENTER;
	return c;
}


String GetSubAtomString(SubAtomCls t) {
	TODO
	#if 0
	switch (t) {
		case CUSTOMER:		return "customer";
		case INPUT:			return "input";
		case OUTPUT:		return "output";
		case CONVERTER:		return "converter";
		case PIPE:			return "pipe";
		case SIDE_INPUT:	return "side-input";
		case SIDE_OUTPUT:	return "side-output";
		default: return "invalid";
	}
	#endif
}

String GetAtomRoleString(AtomRole t) {
	switch (t) {
		case CUSTOMER:		return "customer";
		case SOURCE:		return "source";
		case SINK:			return "sink";
		case CONVERTER:		return "converter";
		case PIPE:			return "pipe";
		case SIDE_SOURCE:	return "source";
		case SIDE_SINK:		return "sink";
		default:			return "invalid";
	}
}


String ValCls::GetName(Type t) {
	switch (t) {
		case AUDIO:			return "audio";
		case VIDEO:			return "video";
		case MIDI:			return "midi";
		case EVENT:			return "event";
		case DATA:			return "data";
		case ORDER:			return "order";
		case RECEIPT:		return "receipt";
		case INVALID:
		default: return "invalid";
	}
}

ValCls::Type ValCls::Get(String s) {
	if (s == "audio")
		return AUDIO;
	if (s == "video")
		return VIDEO;
	if (s == "midi")
		return MIDI;
	if (s == "event")
		return EVENT;
	if (s == "data")
		return DATA;
	if (s == "order")
		return ORDER;
	if (s == "receipt")
		return RECEIPT;
	
	return INVALID;
}



String DevCls::GetName(Type t) {
	switch (t) {
		case CENTER:	return "center";
		case PERMA:		return "perma";
		case ACCEL:		return "accel";
		case NET:		return "net";
		case INVALID:
		default: return "invalid";
	}
}

DevCls::Type DevCls::Get(String s) {
	if (s == "center")
		return CENTER;
	if (s == "perma")
		return PERMA;
	if (s == "accel")
		return ACCEL;
	if (s == "net")
		return NET;
	
	return INVALID;
}






hash_t AtomIfaceTypeCls::GetHashValue() const {
	CombineHash c;
	c.Put(sink.GetHashValue());
	c.Put(src.GetHashValue());
	c.Put(side.GetHashValue());
	c.Put(side_src);
	c.Put(side_multi);
	return c;
}

hash_t AtomTypeCls::GetHashValue() const {
	CombineHash c;
	c.Put(iface.GetHashValue());
	c.Put(sub);
	c.Put(role);
	return c;
}







String SerialTypeCls::GetTypeString(Type t) {
	TODO
	#if 0
	switch (t) {
		case IFACE:					return "interface";
		case COMP_EXT:				return "ext-component";
		case ATOM_TEST_CUSTOMER:		return "test-customer-component";
		case ATOM_TEST_AUDIO_OUT:	return "test-audio-out-component";
		case ATOM_DBG_CONVERTER:		return "dbg-conv-component";
		default: return "invalid";
	}
	#endif
}


NAMESPACE_SERIAL_END
