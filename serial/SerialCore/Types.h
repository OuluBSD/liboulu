#ifndef _SerialCore_Types_h_
#define _SerialCore_Types_h_


NAMESPACE_SERIAL_BEGIN





Format GetDefaultFormat(ValDevCls type);




String GetSubAtomString(SubAtomCls t) {
	switch (t) {
		#define ATOM_TYPE(x) case x:	return #x;
		ATOM_TYPE_LIST
		
		#ifdef flagSCREEN
		flagSCREEN_ATOM_TYPE_LIST
		#endif
		
		#ifdef HAVE_OPENCV
		HAVE_OPENCV_ATOM_TYPE_LIST
		#endif
		
		#undef ATOM_TYPE
		default: return "invalid";
	}
}

String GetAtomRoleString(AtomRole t) {
	switch (t) {
		#define ATOM_ROLE(x) case x: return #x;
		ATOM_ROLE_LIST
		#undef ATOM_ROLE
		default:			return "invalid";
	}
}



hash_t AtomIfaceTypeCls::GetHashValue() const {
	CombineHash c;
	c.Put(sink.GetHashValue());
	c.Put(src.GetHashValue());
	c.Put(content.GetHashValue());
	return c;
}

hash_t AtomTypeCls::GetHashValue() const {
	CombineHash c;
	c.Put(iface.GetHashValue());
	c.Put(sub);
	c.Put(role);
	c.Put(user_sink_count);
	c.Put(user_src_count);
	return c;
}

bool AtomTypeCls::IsSinkChannelOptional(int ch_i) const {
	int sink_begin = iface.sink.count - user_sink_count;
	int sink_end = iface.sink.count;
	return ch_i >= sink_begin && ch_i < sink_end;
}

bool AtomTypeCls::IsSourceChannelOptional(int ch_i) const {
	int src_begin = iface.src.count - user_src_count;
	int src_end = iface.src.count;
	return ch_i >= src_begin && ch_i < src_end;
}

AtomTypeCls::AtomTypeCls(SubAtomCls cls, AtomRole role, const ValDevCls& si0, const ValDevCls& content, const ValDevCls& sr0, int side_sinks, int side_srcs, int user_sinks, int user_srcs, const ValDevCls& si1, const ValDevCls& sr1) : iface(si0,content,sr0), sub(cls), role(role) {
	ASSERT(side_sinks > 0 || side_srcs > 0);
	ASSERT(side_sinks == 0 || si1.IsValid());
	ASSERT(side_srcs == 0 || sr1.IsValid());
	for(int i = 0; i < side_sinks; i++)
		iface.AddSink(si1);
	for(int i = 0; i < side_srcs; i++)
		iface.AddSource(sr1);
	user_sink_count = user_sinks;
	user_src_count = user_srcs;
}

AtomTypeCls::AtomTypeCls(
	SubAtomCls cls, AtomRole role,
	const ValDevCls& si0, const ValDevCls& content, const ValDevCls& sr0,
	int side_sinks, int side_srcs, int user_sinks, int user_srcs,
	const ValDevCls& si1, const ValDevCls& si2, const ValDevCls& sr1, const ValDevCls& sr2)
: iface(si0,content,sr0), sub(cls), role(role) {
	ASSERT(side_sinks > 0 || side_srcs > 0);
	ASSERT(side_sinks == 0 || (si0.IsValid() && si1.IsValid()));
	ASSERT(side_srcs == 0 || (sr0.IsValid() && sr1.IsValid()));
	ValDevCls last_valid;
	for(int i = 0; i < side_sinks; i++) {
		switch (i+1) {
			case 1: if (si1.IsValid()) last_valid = si1; break;
			case 2: if (si2.IsValid()) last_valid = si2; break;
		}
		iface.AddSink(last_valid);
	}
	last_valid.Clear();
	for(int i = 0; i < side_srcs; i++) {
		switch (i+1) {
			case 1: if (sr1.IsValid()) last_valid = sr1; break;
			case 2: if (sr2.IsValid()) last_valid = sr2; break;
		}
		iface.AddSource(last_valid);
	}
	user_sink_count = user_sinks;
	user_src_count = user_srcs;
}

AtomTypeCls::AtomTypeCls(
	SubAtomCls cls, AtomRole role,
	const ValDevCls& si0, const ValDevCls& content, const ValDevCls& sr0,
	int side_sinks, int side_srcs, int user_sinks, int user_srcs,
	const ValDevCls& si1, const ValDevCls& si2, const ValDevCls& si3,
	const ValDevCls& sr1, const ValDevCls& sr2, const ValDevCls& sr3
)
: iface(si0,content,sr0), sub(cls), role(role) {
	ASSERT(side_sinks > 0 || side_srcs > 0);
	ASSERT(side_sinks == 0 || (si0.IsValid() && si1.IsValid()));
	ASSERT(side_srcs == 0 || (sr0.IsValid() && sr1.IsValid()));
	ValDevCls last_valid;
	for(int i = 0; i < side_sinks; i++) {
		switch (i+1) {
			case 1: if (si1.IsValid()) last_valid = si1; break;
			case 2: if (si2.IsValid()) last_valid = si2; break;
			case 3: if (si3.IsValid()) last_valid = si3; break;
		}
		iface.AddSink(last_valid);
	}
	last_valid.Clear();
	for(int i = 0; i < side_srcs; i++) {
		switch (i+1) {
			case 1: if (sr1.IsValid()) last_valid = sr1; break;
			case 2: if (sr2.IsValid()) last_valid = sr2; break;
			case 3: if (sr3.IsValid()) last_valid = sr3; break;
		}
		iface.AddSource(last_valid);
	}
	user_sink_count = user_sinks;
	user_src_count = user_srcs;
}

AtomTypeCls::AtomTypeCls(
	SubAtomCls cls, AtomRole role,
	const ValDevCls& si0, const ValDevCls& content, const ValDevCls& sr0,
	int side_sinks, int side_srcs, int user_sinks, int user_srcs,
	const ValDevCls& si1, const ValDevCls& si2, const ValDevCls& si3, const ValDevCls& si4,
	const ValDevCls& sr1, const ValDevCls& sr2, const ValDevCls& sr3, const ValDevCls& sr4
)
: iface(si0,content,sr0), sub(cls), role(role) {
	ASSERT(side_sinks > 0 || side_srcs > 0);
	ASSERT(side_sinks == 0 || (si0.IsValid() && si1.IsValid()));
	ASSERT(side_srcs == 0 || (sr0.IsValid() && sr1.IsValid()));
	ValDevCls last_valid;
	for(int i = 0; i < side_sinks; i++) {
		switch (i+1) {
			case 1: if (si1.IsValid()) last_valid = si1; break;
			case 2: if (si2.IsValid()) last_valid = si2; break;
			case 3: if (si3.IsValid()) last_valid = si3; break;
			case 4: if (si4.IsValid()) last_valid = si4; break;
		}
		iface.AddSink(last_valid);
	}
	last_valid.Clear();
	for(int i = 0; i < side_srcs; i++) {
		switch (i+1) {
			case 1: if (sr1.IsValid()) last_valid = sr1; break;
			case 2: if (sr2.IsValid()) last_valid = sr2; break;
			case 3: if (sr3.IsValid()) last_valid = sr3; break;
			case 4: if (sr4.IsValid()) last_valid = sr4; break;
		}
		iface.AddSource(last_valid);
	}
	user_sink_count = user_sinks;
	user_src_count = user_srcs;
}



NAMESPACE_SERIAL_END


#endif
