#include "WebcamCV.h"


NAMESPACE_TOPSIDE_BEGIN


HaarFaceBase::HaarFaceBase() {
	LoadCascadeFrontalFace(classifier);
}

void HaarFaceBase::SetSize(Size sz) {
	auto& videoWidth = sz.cx;
	auto& videoHeight = sz.cy;
	
    double scale = min((double)max_work_size/videoWidth, (double)max_work_size/videoHeight);
    int w = (videoWidth*scale);
    int h = (videoHeight*scale);
    this->sz.cx = w;
    this->sz.cy = h;
	
	auto& img_u8 = tmp0;
	auto& edg = tmp1;
    img_u8.SetSize(w, h, 1);
    edg.SetSize(w, h, 1);
    
    ii_sum.SetCount((w+1)*(h+1));
    ii_sqsum.SetCount((w+1)*(h+1));
    ii_tilted.SetCount((w+1)*(h+1));
    ii_canny.SetCount((w+1)*(h+1));
	
}

void HaarFaceBase::Process() {
	auto& img_u8 = tmp0;
	auto& edg = tmp1;
	
    Grayscale(input, sz.cx, sz.cy, img_u8);

    // possible options
    if(is_equalize_histogram) {
        equalize_histogram(img_u8, img_u8);
    }
    //gaussian_blur(img_u8, img_u8, 3);

    compute_integral_image(img_u8, ii_sum, &ii_sqsum, classifier.tilted ? &ii_tilted : 0);

    if(use_canny) {
        canny(img_u8, edg, 10, 50);
        compute_integral_image(edg, ii_canny, 0, 0);
    }

    h.SetEdgeDensity(edges_density);
    h.detect_multi_scale(rects, ii_sum, ii_sqsum, ii_tilted, use_canny ? &ii_canny : 0, img_u8.cols, img_u8.rows, classifier, scale_factor, min_scale);
    group_rectangles(rects, result_seq, 1);
    
}

/*void HaarFaceBase::draw_faces(Vector<BBox>& result_seq, double sc, bool max) {
    var on = result_seq.length;
    if(on && max) {
        jsfeat.math.qsort(result_seq, 0, on-1, function(a,b){return (b.confidence<a.confidence);})
    }
    var n = max || on;
    n = Math.min(n, on);
    var r;
    for(var i = 0; i < n; ++i) {
        r = result_seq[i];
        ctx.strokeRect((r.x*sc),(r.y*sc),(r.width*sc),(r.height*sc));
    }
}*/


NAMESPACE_TOPSIDE_END
