#include "Geometry.h"


NAMESPACE_UPP


ProgPainter::ProgPainter(Size sz, ProgPainter& p, DrawCommand& begin, DrawCommand& end)
	: sz(sz), begin(&begin), end(&end) {
	prev = p.cur ? p.cur : p.begin;
	next = p.end;
	begin.prev = prev;
	end.next = next;
	prev->next = &begin;
	next->prev = &end;
}

Size ProgPainter::GetPageSize() const {
	return sz;
}

void ProgPainter::DrawLineOp(int x1, int y1, int x2, int y2, int width, Color color) {
	DrawLine(x1,y1,x2,y2,width,RGBA(color));
}

void ProgPainter::DrawRectOp(int x, int y, int cx, int cy, Color color) {
	DrawRect(x,y,cx,cy,RGBA(color));
}

void ProgPainter::DrawTextOp(int x, int y, int angle, const wchar *text, Font font,
	                    Color ink, int n, const int *dx) {
	DrawText(x, y, WString(text).ToString(), font, RGBA(ink));
}

void ProgPainter::DrawPolyPolylineOp(const Point *vertices, int vertex_count,
                                const int *counts, int count_count,
                                int width, Color color, Color doxor) {
	DrawPolyline(vertices, vertex_count, width, color);
}

bool ProgPainter::ClipOp(const Rect& r) {
	Offset(r);
	return true;
}

void ProgPainter::EndOp() {
	End();
}




DrawCommand& ProgPainter::GetNext() {
	DrawCommand* cmd = &DrawCommandCache::Local().Get();
	cmd->prev = cur;
	if (cur)
		cur->next = cmd;
	cur = cmd;
	if (!cur_begin)
		cur_begin = cur;
	return *cur;
}

void ProgPainter::DrawLine(int x0, int y0, int x1, int y1, int line_width, RGBA c) {
	if (line_width <= 0) return;
	
	if (line_width == 1) {
		DrawCommand& cmd = GetNext();
		cmd.type = DRAW_LINE;
		cmd.i[0] = x0;
		cmd.i[1] = y0;
		cmd.i[2] = x1;
		cmd.i[3] = y1;
		cmd.clr = c;
	}
	else {
		Point a(x0, y0), b(x1, y1);
		Point off = GetOffsets(a, b, line_width);
		Point p0a(a.x - off.x, a.y - off.y);
		Point p1a(b.x - off.x, b.y - off.y);
		Point p0b(a.x + off.x, a.y + off.y);
        Point p1b(b.x + off.x, b.y + off.y);
        
		DrawCommand& cmd = GetNext();
		cmd.type = DRAW_TRIANGLES;
		cmd.triangles.SetCount(2);
		cmd.clr = c;
		
		TODO
		/*
		double signed_area = GetSignedArea(p0a, p1a, p0b);
		if (signed_area >= 0) {
			cmd.triangles[0].Set(p0a, p1a, p0b);
			cmd.triangles[1].Set(p0b, p1a, p1b);
		}
		else {
			cmd.triangles[0].Set(p0a, p0b, p1a);
			cmd.triangles[1].Set(p0b, p1b, p1a);
		}*/
	}
}

void ProgPainter::DrawImage(int x, int y, Image img, byte alpha) {
	DrawCommand& cmd = GetNext();
	cmd.type = DRAW_IMAGE;
	cmd.i[0] = x;
	cmd.i[1] = y;
	cmd.img = img;
	//cmd.img.MakeSysAccel();
	cmd.clr.a = (byte)(alpha / 255.0);
}

void ProgPainter::DrawRect(Rect r, RGBA clr) {
	DrawRect(r.left, r.top, r.Width(), r.Height(), clr);
}

void ProgPainter::DrawRect(int x, int y, int w, int h, RGBA clr) {
	DrawCommand& cmd = GetNext();
	cmd.type = DRAW_RECT;
	cmd.i[0] = x;
	cmd.i[1] = y;
	cmd.i[2] = x+w;
	cmd.i[3] = y+h;
	cmd.clr = clr;
}

void ProgPainter::DrawText(int x, int y, String txt, Font fnt, RGBA clr) {
	if (txt.GetCount() == 0 || fnt.IsEmpty())
		return;
	
	SysColor c;
	c.r = (byte)(clr.r * 255.0);
	c.g = (byte)(clr.g * 255.0);
	c.b = (byte)(clr.b * 255.0);
	c.a = 255;
	RawSysImage* surf = fnt.GetSysFont()->RenderTextBlended(txt.Begin(), c);
	if (!surf) {
		#if HAVE_SDL2
		DLOG("Couldn't render text: " << SDL_GetError());
		#else
		DLOG("Couldn't render text");
		#endif
		return;
	}
	
	DrawCommand& cmd = GetNext();
	cmd.type = DRAW_IMAGE;
	cmd.i[0] = x;
	cmd.i[1] = y;
	cmd.img = Image(surf);
	//cmd.img.MakeSysAccel();
	cmd.clr.a = clr.a;
}

void ProgPainter::DrawPolyline(const Point* pts, int pt_count, int line_width, RGBA c) {
	ASSERT(pt_count >= 3);
	DrawCommand& cmd = GetNext();
	cmd.clr = c;
	
	static thread_local Vector<vec2> tmp1; // can't inherit Geometry to headers
	
	if (line_width == 1) {
		cmd.type = DRAW_POLYLINE;
		cmd.i[0] = line_width;
		cmd.pts.SetCount(pt_count);
		memcpy(cmd.pts.Begin(), pts, pt_count * sizeof(Point));
	}
	else {
		
		tmp0.SetCount(pt_count-1);
		tmp1.SetCount(0);
		angles.SetCount(pt_count-1);
		const Point* a = NULL;
		const Point* b = &pts[0];
		for(int i = 0; i < pt_count-1; i++) {
			a = b;
			b = &pts[i+1];
			tmp0[i] = GetOffsets(*a, *b, line_width);
			
			double dx = b->x - a->x;
			double dy = b->y - a->y;
			double theta = atan(dy / dx) * 360 / (2*M_PI);
			if (dx < 0)
				theta *= -1;
			angles[i] = theta;
		}
		a = NULL;
		b = &pts[0];
		const Point* c = &pts[1];
		double a0, a1 = angles[0];
		Point* o0, *o1 = &tmp0[0];
		
		// Loop "left side"
		for(int i = 0; i < angles.GetCount()-1; i++) {
			a = b;
			b = c;
			c = &pts[i+2];
			a0 = a1;
			a1 = angles[i+1];
			double diff = a1 - a0;
			
			o0 = o1;
			o1 = &tmp0[i+1];
			
			vec2 al	(a->x - o0->x, a->y - o0->y);
			vec2 b0l(b->x - o0->x, b->y - o0->y);
			vec2 b1l(b->x - o1->x, b->y - o1->y);
			vec2 cl	(c->x - o1->x, c->y - o1->y);
			
			if (!i)
				tmp1.Add(al);
			
			if (diff == 0) {
				tmp1.Add(b0l);
			}
			else if (diff > 0) {
				vec2 is = Intersect(al, b0l, b1l, cl);
				tmp1.Add(is);
			}
			else {
				tmp1.Add(b0l);
				tmp1.Add(b1l);
			}
			
			if (i == angles.GetCount()-2)
				tmp1.Add(cl);
		}
		
		// Loop "right side" in reverse
		a = &pts[angles.GetCount()-1];
		b = &pts[angles.GetCount()];
		c = NULL;
		a0 = angles[angles.GetCount()-1];
		o0 = &tmp0[angles.GetCount()-1];
		for (int i = angles.GetCount()-2; i >= 0; i--) {
			c = b;
			b = a;
			a = &pts[i];
			a1 = a0;
			a0 = angles[i];
			double diff = a1 - a0;
			o1 = o0;
			o0 = &tmp0[i];
			
			vec2 ar	(a->x + o0->x, a->y + o0->y);
			vec2 b0r	(b->x + o0->x, b->y + o0->y);
			vec2 b1r	(b->x + o1->x, b->y + o1->y);
			vec2 cr	(c->x + o1->x, c->y + o1->y);
			
			if (i == angles.GetCount()-2)
				tmp1.Add(cr);
			
			if (diff == 0) {
				tmp1.Add(b0r);
			}
			else if (diff < 0) {
				vec2 is = Intersect(ar, b0r, b1r, cr);
				tmp1.Add(is);
			}
			else {
				tmp1.Add(b1r);
				tmp1.Add(b0r);
			}
			
			if (!i)
				tmp1.Add(ar);
		}
		
		cmd.type = DRAW_TRIANGLES;
		Triangulate::Process(tmp1, cmd.triangles);
		
		//cmd.type = DRAW_POLYLINE;
		//cmd.pts <<= tmp1;
	}
}

void ProgPainter::DrawPolygon(const Vector<Point>& pts, RGBA c) {
	DrawCommand& cmd = GetNext();
	cmd.type = DRAW_TRIANGLES;
	cmd.clr = c;
	
	TODO //Triangulate::Process(pts, cmd.triangles);
}

void ProgPainter::Offset(const Rect& r) {
	DrawCommand& cmd = GetNext();
	cmd.type = DRAW_OFFSET;
	cmd.i[0] = r.left;
	cmd.i[1] = r.top;
	cmd.i[2] = r.right;
	cmd.i[3] = r.bottom;
}

void ProgPainter::End() {
	DrawCommand& cmd = GetNext();
	cmd.type = DRAW_END;
}

/*void ProgPainter::Attach(Ctrl& c) {
	Attach(c.cmd_begin, c.cmd_end);
}*/

void ProgPainter::Attach(DrawCommand& begin, DrawCommand& end) {
	//ASSERT(!begin.prev && !end.next);
	if (this->begin->next == &begin && this->end->prev == &end) {
		//cur = &end;
		//cur_begin = &begin;
		cur = 0;
		cur_begin = 0;
		return;
	}
	if (cur) {
		TODO
	}
	/*if (cur) {
		end.next = cur->next;
		ASSERT(end.next);
		end.next->prev = &end;
		cur->next = &begin;
		begin.prev = cur;
		cur = &end;
		//cur_begin = &begin;
	}*/
	else
	{
		ASSERT(this->begin && this->end);
		begin.prev = this->begin;
		this->begin->next = &begin;
		end.next = this->end;
		this->end->prev = &end;
		cur = &end;
		cur_begin = &begin;
		/*prev->next = &begin;
		begin.prev = prev,
		end.next = &begin;
		begin.prev = &end;*/
	}
	/*if (cur) {
		end.next = cur->next;
		end.next->prev = &end;
		cur->next = &begin;
		begin.prev = cur;
		cur = &end;
		cur_begin = cur;
	}
	else {
		TODO
	}*/
}

void ProgPainter::AppendPick(DrawCommand* begin, DrawCommand* end) {
	ASSERT(begin && end);
	
	if (cur) {
		end->next = cur->next;
		ASSERT(end->next);
		end->next->prev = end;
		cur->next = begin;
		begin->prev = cur;
		cur = end;
		//cur_begin = begin;
	}
	else {
		ASSERT(this->begin && this->end);
		begin->prev = this->begin;
		this->begin->next = begin;
		end->next = this->end;
		this->end->prev = end;
		cur = end;
		cur_begin = begin;
	}
}

void ProgPainter::Link() {
	ASSERT(prev != begin && next != end);
	DrawCommand* free_begin = NULL;
	DrawCommand* free_end = NULL;
	if (begin->next != end) {
		free_begin = begin->next;
		free_end = end->prev;
	}
	if (!cur) {
		end->prev = begin;
		begin->next = end;
	}
	else {
		end->prev = cur;
		cur->next = end;
		cur_begin->prev = begin;
		begin->next = cur_begin;
	}
	end->next = next;
	begin->prev = prev;
	next->prev = end;
	prev->next = begin;
	if (free_begin) {
		DrawCommand* free = free_begin;
		while (free && free != free_end) {
			if (free->is_cached)
				DrawCommandCache::Local().Return(free);
			free = free->next;
		}
	}
	
	ASSERT(begin->next != begin);
}

void ProgPainter::Clear() {
	DrawCommand* free_begin = NULL;
	DrawCommand* free_end = NULL;
	if (begin->next != end) {
		free_begin = begin->next;
		free_end = end->prev;
	}
	
	if (free_begin) {
		DrawCommand* free = free_begin;
		while (free && free != free_end) {
			if (free->is_cached)
				DrawCommandCache::Local().Return(free);
			free = free->next;
		}
		begin->next = 0;
		end->prev = 0;
	}
}



END_UPP_NAMESPACE
