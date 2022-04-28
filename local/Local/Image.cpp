#include "Local.h"

NAMESPACE_TOPSIDE_BEGIN


Image GetDefaultImage(int code) {
	static Image cube;
	
	switch (code) {
		case IMAGEID_GRID: return RealizeImage(cube, ShareDirFile("models" DIR_SEPS "cube.png"));
	}
	return Image();
}

Image RealizeImage(Image& img, String path) {
	if (img.IsEmpty())
		img = StreamRaster::LoadFileAny(path);
	return img;
}



void FloatImage::Clear() {
	if (data) {
		free(data);
		sz = Size(0, 0);
		pitch = 0;
		channels = 0;
		size = 0;
	}
}

void FloatImage::FlipVert() {
	int half = sz.cy / 2;
	for(int y = 0; y < half; y++) {
		int yb = sz.cy - 1 - y;
		float* a = data + y * pitch;
		float* b = data + yb * pitch;
		for(int i = 0; i != pitch; i++)
			Swap(*a++, *b++);
	}
}

void FloatImage::Set(const Image& img) {
	Size sz = img.GetSize();
	#ifdef LIBTOPSIDE
	Set(sz.cx, sz.cy, img.GetStride(), img.GetPitch(), img.Begin());
	#else
	Set(sz.cx, sz.cy, 4, sz.cx, (const byte*)img.Begin());
	#endif
}

void FloatImage::Set(int w, int h, int stride, int src_pitch, const byte* src_data) {
	Clear();
	
	sz = Size(w,h);
	channels = stride;
	pitch = sz.cx * channels;
	size = pitch * sz.cy;
	
	ASSERT(channels >= 1 && channels <= 4);
	data = (float*)malloc(sizeof(float) * size);
	
	float* f = data;
	const byte* it = src_data;
	const byte* end = src_data + sz.cy * pitch;
	
	if (src_pitch == pitch) {
		int exp_size = (int)(end - it);
		ASSERT(exp_size == size);
		while (it != end) {
			double v = *it++ / 255.0;
			ASSERT(IsFin(v));
			*f++ = (float)v;
		}
	}
	else {
		for(int y = 0; y < sz.cy; y++) {
			const byte* it0 = it + y * src_pitch;
			const byte* end0 = it0 + pitch;
			while (it0 != end0)
				*f++ = (float)(*it0++ / 255.0);
		}
	}
}

void FloatImage::Set(Size sz, int channels) {
	Clear();
	
	this->sz = sz;
	this->channels = channels;
	pitch = sz.cx * channels;
	size = pitch * sz.cy;
	
	ASSERT(channels >= 1 && channels <= 4);
	data = (float*)malloc(sizeof(float) * size);
}





void ByteImage::FlipVert() {
	int half = sz.cy / 2;
	for(int y = 0; y < half; y++) {
		int yb = sz.cy - 1 - y;
		byte* a = data + y * pitch;
		byte* b = data + yb * pitch;
		for(int i = 0; i != pitch; i++)
			Swap(*a++, *b++);
	}
}

void ByteImage::Set(const Image& img) {
	Size sz = img.GetSize();
	#ifdef LIBTOPSIDE
	Set(sz.cx, sz.cy, img.GetStride(), img.GetPitch(), img.Begin());
	#else
	Set(sz.cx, sz.cy, 4, sz.cx, (const byte*)img.Begin());
	#endif
}

void ByteImage::Set(int w, int h, int stride, int src_pitch, const byte* src_data) {
	Clear();
	sz = Size(w,h);
	channels = stride;
	pitch = sz.cx * channels;
	size = pitch * sz.cy;
	ASSERT(channels >= 1 && channels <= 4);
	
	data = (byte*)malloc(sizeof(byte) * size);
	
	if (src_data) {
		byte* b = data;
		const byte* it = src_data;
		const byte* end = src_data + size;
		
		if (src_pitch == pitch) {
			#if 1
			memcpy(b, it, size);
			#else
			while (it != end)
				*b++ = *it++;
			#endif
		}
		else {
			for(int y = 0; y < sz.cy; y++) {
				const byte* it0 = it + y * src_pitch;
				const byte* end0 = it0 + pitch;
				while (it0 != end0)
					*b++ = *it0++;
			}
		}
	}
}

void ByteImage::Set(Size sz, int channels) {
	if (this->sz == sz && this->channels == channels)
		return;
	Clear();
	this->sz = sz;
	this->channels = channels;
	pitch = sz.cx * channels;
	size = pitch * sz.cy;
	ASSERT(channels >= 1 && channels <= 4);
	
	data = (byte*)malloc(sizeof(byte) * size);
}

void ByteImage::Clear() {
	if (data) {
		free(data);
		sz = Size(0, 0);
		pitch = 0;
		channels = 0;
		size = 0;
		data = 0;
	}
}

void ByteImage::Zero(RGBA clr) {
	if (clr.r == 0 && clr.g == 0 && clr.b == 0 && clr.a == 0)
		Zero();
	else if (data) {
		ASSERT(channels >= 1 && channels <= 4);
		if (!((channels >= 1 && channels <= 4))) return;
		
		for(int y = 0; y < sz.cy; y++) {
			byte* dst = data + y * pitch;
			for (int x = 0; x < sz.cx; x++) {
				const byte* src = &clr.r;
				for(int i = 0; i < channels; i++)
					*dst++ = src[i];
			}
		}
	}
}

void ByteImage::Zero() {
	if (data)
		memset(data, 0, size);
}

void ByteImage::SwapRedBlue() {
	byte* it = data;
	byte* end = data + size;
	int stride = this->channels;
	if (stride >= 3 && (size % stride) == 0) {
		while (it != end) {
			byte s = it[0];
			it[0] = it[2];
			it[2] = s;
			it += stride;
		}
	}
}

void ByteImage::SetSwapRedBlue(const ByteImage& i) {
	if (this->sz != i.sz || this->channels != i.channels) {
		Clear();
		this->sz = i.sz;
		this->channels = i.channels;
		pitch = sz.cx * channels;
		size = pitch * sz.cy;
		ASSERT(channels >= 1 && channels <= 4);
		
		data = (byte*)malloc(sizeof(byte) * size);
	}
	
	if (channels == 4) {
		ASSERT(pitch == i.pitch);
		const dword* src = (const dword*)i.data;
		union {
			dword* dst;
			byte* b;
		};
		dst = (dword*)data;
		dword* end = dst + size / 4;
		while (dst != end) {
			*dst = *src++;
			byte s = b[0];
			b[0] = b[2];
			b[2] = s;
			dst++;
		}
	}
	else {
		TODO
	}
}

void ByteImage::Randomize() {
	byte* it = data;
	byte* end = data + size;
	while (it != end)
		*it++ = (byte)Random(256);
}

int ByteImage::GetPitch() const {
	return pitch;
}

int ByteImage::GetWidth() const {
	return sz.cx;
}

int ByteImage::GetHeight() const {
	return sz.cy;
}

int ByteImage::GetChannels() const {
	return channels;
}

int ByteImage::GetSize() const {
	return size;
}

byte* ByteImage::GetIter(int x, int y) {
	ASSERT(x >= 0 && y >= 0 && x < sz.cx && y < sz.cy);
	ASSERT(sz.cx && sz.cy && data && pitch && channels);
	return data + y * pitch + x * channels;
}

const byte* ByteImage::GetIter(int x, int y) const {
	ASSERT(x >= 0 && y >= 0 && x < sz.cx && y < sz.cy);
	ASSERT(sz.cx && sz.cy && data && pitch && channels);
	return data + y * pitch + x * channels;
}








void DataFromImage(const Image& img, Vector<byte>& out) {
	#ifdef UPP_VERSION
	
	TODO
	
	#else
	Image::ImageDataRef* data = img.GetData();
	if (!data)
		return;
	
	SysImage& simg = data->img;
	
	const byte* it = simg.GetData();
	int pitch = simg.GetPitch();
	int stride = simg.GetStride();
	int width = simg.GetWidth();
	int height = simg.GetHeight();
	
	int line = stride * width;
	int sz = line * height;
	ASSERT(pitch >= line);
	
	if (stride == 4) {
		out.SetCount(sz);
		
		if (line == pitch)
			memcpy(out.Begin(), it, sz);
		else {
			TODO
		}
	}
	else {
		ASSERT(stride < 4);
		int dst_stride = 4;
		int dst_size = dst_stride * width * height;
		out.SetCount(dst_size);
		
		byte* out_it = out.Begin();
		int line_pad = pitch - line;
		ASSERT(line_pad >= 0);
		
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				for (int i = 0; i < dst_stride; i++) {
					byte val = i < stride ? *it++ : 0;
					*out_it++ = val;
				}
			}
			it += line_pad;
		}
		
		ASSERT(out_it == out.End());
	}
	#endif
}

Image MirrorVertical(const Image& img) {
	#ifdef UPP_VERSION
	
	TODO
	
	#else
	Image::ImageDataRef* data = img.GetData();
	if (img.GetSize().IsNull() || !data)
		return img;
	
	SysImage& simg = data->img;
	
	const byte* it = simg.GetData();
	int pitch = simg.GetPitch();
	int stride = simg.GetStride();
	int width = simg.GetWidth();
	int height = simg.GetHeight();
	
	ImageBuffer ib(width, height);
	RGBA* dst = ib.End();
	
	int line = stride * width;
	int sz = line * height;
	ASSERT(pitch >= line);
	
	if (stride == 4) {
		
		if (line == pitch) {
			for (int y = height-1; y >= 0; y--) {
				dst -= width;
				memcpy(dst, it, line);
				it += line;
			}
		}
		else {
			TODO
		}
	}
	else {
		ASSERT(stride < 4);
		const int dst_stride = 4;
		int dst_size = dst_stride * width * height;
		
		int line_pad = pitch - line;
		ASSERT(line_pad >= 0);
		
		for (int y = height-1; y >= 0; y--) {
			dst -= width;
			byte* out_it = (byte*)dst;
			for (int x = 0; x < width; x++) {
				for (int i = 0; i < dst_stride; i++) {
					byte val = i < stride ? *it++ : 0;
					*out_it++ = val;
				}
			}
			it += line_pad;
		}
	}
	
	return ib;
	#endif
}


NAMESPACE_TOPSIDE_END
