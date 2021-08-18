#include "SerialMach.h"

NAMESPACE_SERIAL_BEGIN







DevCls GetCenterDevCls() {
	DevCls c;
	c.type = DevCls::CENTER;
	return c;
}



String ValCls::GetName(Type t) {
	switch (t) {
		case AUDIO:		return "audio";
		case VIDEO:		return "video";
		case MIDI:		return "midi";
		case EVENT:		return "event";
		case DATA:		return "data";
		case ORDER:		return "order";
		case RECEIPT:	return "receipt";
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






hash_t TypeAtomCls::GetHashValue() const {
	CombineHash c;
	c.Put(sink.GetHashValue());
	c.Put(src.GetHashValue());
	c.Put(side.GetHashValue());
	c.Put(sub);
	c.Put(ext);
	return c;
}


NAMESPACE_SERIAL_END
