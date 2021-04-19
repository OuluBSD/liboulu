#include "Core.h"

NAMESPACE_UPP_BEGIN


int Stream::Get(Huge& h, int size)
{
	while(h.GetSize() < size) {
		int sz = (int)min((size_t)h.CHUNK, size - h.GetSize());
		int len = Get(h.AddChunk(), sz);
		if(len < h.CHUNK) {
			h.Finish(len);
			break;
		}
	}
	return h.GetSize();
}

int Stream::Get() {
	byte b = 0;
	Get(&b, 1);
	return b;
}

void Stream::PutEol() {
#ifdef flagWIN32
	char b[2] = {'\r', '\n'};
	Put(b, 2);
#else
	char b = '\n';
	Put(&b, 1);
#endif
}

void StdLogSetup(dword flags) {
	MultiStream& s = LogMulti();
	s.Clear();
	
	if (flags & LOG_FILE) {
		s.Add(LogFile());
	}
	if (flags & LOG_COUT) {
		s.Add(Cout());
	}
}


NAMESPACE_UPP_END
