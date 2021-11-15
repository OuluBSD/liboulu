#include "WebcamCV.h"

NAMESPACE_TOPSIDE_BEGIN

void PyramidDownsampleBase::Process() {
	int levels = 4;
	img_pyr.SetSize(sz.cx, sz.cy, 1, levels);
	
    Grayscale(input, sz.cx, sz.cy, img_pyr.data[0]);
    
    // you do the same by executing img_pyr.build(img_pyr.data[0], true);
    int i = 2;
    auto* a = &img_pyr.data[0];
    auto* b = &img_pyr.data[1];
    DownsamplePyramid(*a, *b);
    for(; i < levels; ++i) {
        a = b;
        b = &img_pyr.data[i];
        DownsamplePyramid(*a, *b);
    }

    // render result back to canvas
    for(i=0; i < levels; ++i){
        auto& l = img_pyr.data[i];
        render_mono_image(l.data, output, l.cols, l.rows, sz.cx);
        break;
    }
}

void PyramidDownsampleBase::render_mono_image(const Vector<byte>& src, ByteMat& dst, int sw, int sh, int dw) {
	dst.SetSize(sh, sw, 4);
	byte* d = dst.data.Begin();
    for(int i = 0; i < sh; ++i) {
        for(int j = 0; j < sw; ++j) {
            byte pix = src[i*sw+j];
            int off = i*dw+j;
            d[off + 0] = pix;
            d[off + 1] = pix;
            d[off + 2] = pix;
            d[off + 3] = 255;
        }
    }
}

NAMESPACE_TOPSIDE_END
