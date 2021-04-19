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
var img_u8,img_gxgy,img_mag;

function demo_app(videoWidth, videoHeight) {
    canvasWidth  = canvas.width;
    canvasHeight = canvas.height;
    ctx = canvas.getContext('2d');

    ctx.fillStyle = "rgb(0,255,0)";
    ctx.strokeStyle = "rgb(0,255,0)";

    img_u8 = new jsfeat.matrix_t(640, 480, jsfeat.U8C1_t);
    img_gxgy = new jsfeat.matrix_t(640, 480, jsfeat.S32C2_t);
    img_mag = new jsfeat.matrix_t(640, 480, jsfeat.S32C1_t);

    stat.add("grayscale");
    stat.add("blur");
    stat.add("sobel");
    stat.add("edges");
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

        stat.start("blur");
        jsfeat.imgproc.gaussian_blur(img_u8, img_u8, 3);
        stat.stop("blur");

        stat.start("sobel");
        jsfeat.imgproc.sobel_derivatives(img_u8, img_gxgy);
        stat.stop("sobel");

        stat.start("edges");


        var i = img_u8.cols*img_u8.rows, gx = 0, gy = 0;
        var x=0,y=0,dx=0,dy=0;
        var agx=0, agy=0;
        var gd=img_gxgy.data, mag=img_mag.data, id=img_u8.data;

        while(--i >= 0) {
            gx = gd[i<<1];
            gy = gd[(i<<1)+1];
            mag[i] = gx*gx + gy*gy;
        }

        for(y = 1; y < img_u8.rows - 1; ++y) {
            i = (y * img_u8.cols + 1)|0;
            for(x = 1 ; x < img_u8.cols - 1; ++x, ++i) {

                gx = gd[i<<1];
                gy = gd[(i<<1)+1];
                agx = ((gx ^ (gx >> 31)) - (gx >> 31))|0;
                agy = ((gy ^ (gy >> 31)) - (gy >> 31))|0;

                if(gx > 0) dx = 1;
                else dx = -1;

                if(gy > 0) dy = img_u8.cols;
                else dy = -img_u8.cols;

                var a1, a2, b1, b2, A, B, point;
                if(agx > agy) {
                    a1 = mag[i+dx];
                    a2 = mag[i+dx+(-dy)];
                    b1 = mag[i-dx];
                    b2 = mag[i-dx+dy];
                    A = (agx - agy)*a1 + agy*a2;
                    B = (agx - agy)*b1 + agy*b2;
                    point = mag[i] * agx;
                    if(point >= A && point > B) {
                        id[i] = agx&0xff;
                    }
                    else {
                        id[i] = 0x0;
                    }
                } else  {
                    a1 = mag[i+(-dy)];
                    a2 = mag[i+dx+(-dy)];
                    b1 = mag[i+dy];
                    b2 = mag[i-dx+dy];
                    A = (agy - agx)*a1 + agx*a2;
                    B = (agy - agx)*b1 + agx*b2;
                    point = mag[i] * agy;
                    if(point >= A && point > B) {
                        id[i] = agy&0xff;
                    }
                    else {
                        id[i] = 0x0;
                    }
                }
            }
        }

        stat.stop("edges");


        // render result back to canvas
        var data_u32 = new Uint32Array(imageData.data.buffer);
        var alpha = (0xff << 24);
        var pix = 0;
        i = img_u8.cols*img_u8.rows;
        while(--i >= 0) {
            pix = id[i];
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
