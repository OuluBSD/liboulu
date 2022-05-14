#include "Draw.h"


NAMESPACE_UPP


DrawCommand& DrawCommandCache::Get() {
	if (unused.IsEmpty()) {
		DrawCommand& cmd = owned.Add();
		cmd.type = 0;
		cmd.is_cached = true;
		return cmd;
	}
	DrawCommand& cmd = *unused.Pop();
	cmd.next = NULL;
	cmd.prev = NULL;
	cmd.type = 0;
	cmd.is_cached = true;
	return cmd;
}

void DrawCommandCache::Return(DrawCommand* cmd) {
	unused.Add(cmd);
}



String DrawCommand::GetTypeString() const {
	switch (type) {
		case DRAW_NULL:			return "null";
		case DRAW_LINE:			return "line";
		case DRAW_IMAGE:		return "image";
		case DRAW_RECT:			return "rect";
		case DRAW_TRIANGLES:	return "triangles";
		case DRAW_POLYLINE:		return "polyline";
		case DRAW_OFFSET:		return "offset";
		case DRAW_END:			return "end";
		default: return "<invalid type>";
	}
}

String DrawCommand::ToString() const {
	String s;
	switch (type) {
		case DRAW_NULL:			s << "null"; break;
		case DRAW_LINE:			s << "line([" << i[0] << "," << i[1] << "], [" << i[2] << "," << i[3] << "])"; break;
		case DRAW_IMAGE:		s << "image([" << i[0] << "," << i[1] << "], " << img.ToString() << ")"; break;
		case DRAW_RECT:			s << "rect(pt[" << i[0] << "," << i[1] << "], sz[" << i[2]-i[0] << "," << i[3]-i[1] << "])"; break;
		case DRAW_TRIANGLES:	s << "triangles(" << clr.ToString() << ")"; break;
		case DRAW_POLYLINE:		s << "polyline(width=" << i[0] << ", pts-count=" << pts.GetCount() << ")"; break;
		case DRAW_OFFSET:		s << "offset(" << i[0] << "," << i[1] << ", " << i[2] << "," << i[3] << ")"; break;
		case DRAW_END:			s << "end()"; break;
		default: s << "<invalid type>"; break;
	}
	return s;
}

String DrawCommand::GetQueueString() const {
	String s;
	const DrawCommand* it = this;
	int i = 0;
	while (it) {
		s << i++ << ": " << it->ToString() << "\n";
		it = it->next;
		if (it == this)
			break;
	}
	return s;
}


END_UPP_NAMESPACE
