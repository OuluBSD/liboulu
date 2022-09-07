#include "WebcamCV.h"

#if 0


// lets do some fun
var video = document.getElementById('webcam');
var canvas = document.getElementById('canvas');
try {
    var attempts = 0;
    var readyListener = function(event) {
        findVideoSize();
    };
    var findVideoSize = function() {
        if(video.videoWidth > 0 && video.videoHeight > 0) {
            video.removeEventListener('loadeddata', readyListener);
            onDimensionsReady(video.videoWidth, video.videoHeight);
        } else {
            if(attempts < 10) {
                attempts++;
                setTimeout(findVideoSize, 200);
            } else {
                onDimensionsReady(640, 480);
            }
        }
    };
    var onDimensionsReady = function(width, height) {
        demo_app(width, height);
        compatibility.requestAnimationFrame(tick);
    };

    video.addEventListener('loadeddata', readyListener);

    compatibility.getUserMedia({video: true}, function(stream) {
        if(video.srcObject !== undefined){
            video.srcObject = stream
        } else {
            try {
                video.src = compatibility.URL.createObjectURL(stream);
            } catch (error) {
                video.src = stream;
            }
        }
        setTimeout(function() {
                video.play();
            }, 500);
    }, function (error) {
        $('#canvas').hide();
        $('#log').hide();
        $('#no_rtc').html('<h4>WebRTC not available.</h4>');
        $('#no_rtc').show();
    });
} catch (error) {
    $('#canvas').hide();
    $('#log').hide();
    $('#no_rtc').html('<h4>Something goes wrong...</h4>');
    $('#no_rtc').show();
}

var stat = new profiler();

var ctx,canvasWidth,canvasHeight;
var img_u8, img_u8_warp,mat_affine;

function demo_app(videoWidth, videoHeight) {
    canvasWidth  = canvas.width;
    canvasHeight = canvas.height;
    ctx = canvas.getContext('2d');

    ctx.fillStyle = "rgb(0,255,0)";
    ctx.strokeStyle = "rgb(0,255,0)";

    img_u8 = new jsfeat.matrix_t(640, 480, jsfeat.U8_t | jsfeat.C1_t);
    img_u8_warp = new jsfeat.matrix_t(640, 480, jsfeat.U8_t | jsfeat.C1_t);
    mat_affine = new jsfeat.matrix_t(3, 2, jsfeat.F32_t | jsfeat.C1_t);

    mat_affine.data[0] = 1.1548494156391083;
    mat_affine.data[1] = 0.4783542904563622;
    mat_affine.data[2] = -164.3568427140416;
    mat_affine.data[3] = -0.4783542904563622;
    mat_affine.data[4] = 1.1548494156391083;
    mat_affine.data[5] = 115.90951319264985;

    stat.add("grayscale");
    stat.add("warp affine");
}

function tick() {
    compatibility.requestAnimationFrame(tick);
    stat.new_frame();
    if (video.readyState === video.HAVE_ENOUGH_DATA) {
        ctx.drawImage(video, 0, 0, 640, 480);
        var imageData = ctx.getImageData(0, 0, 640, 480);

        stat.start("grayscale");
        jsfeat.imgproc.grayscale(imageData.data, 640, 480, img_u8);
        stat.stop("grayscale");

        stat.start("warp affine");
        jsfeat.imgproc.warp_affine(img_u8, img_u8_warp, mat_affine, 0);
        stat.stop("warp affine");

        // render result back to canvas
        var data_u32 = new Uint32Array(imageData.data.buffer);
        var alpha = (0xff << 24);
        var i = img_u8_warp.cols*img_u8_warp.rows, pix = 0;
        while(--i >= 0) {
            pix = img_u8_warp.data[i];
            data_u32[i] = alpha | (pix << 16) | (pix << 8) | pix;
        }

        ctx.putImageData(imageData, 0, 0);

        $('#log').html(stat.log());
    }
}

$(window).unload(function() {
    video.pause();
    video.src=null;
});


#endif
