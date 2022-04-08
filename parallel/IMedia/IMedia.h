#ifndef _IMedia_IMedia_h_
#define _IMedia_IMedia_h_


#include <ParallelLib/ParallelLib.h>


#ifdef flagFFMPEG
extern "C" {
	#include <libavdevice/avdevice.h>
	#include <libavcodec/avcodec.h>
	#include <libavformat/avformat.h>
	#include <libswscale/swscale.h>
	#include <libavutil/imgutils.h>
}

#define FFMPEG_VIDEOFRAME_RGBA_CONVERSION 1

#endif


#include "Types.h"
#include "Audio.h"
#include "Video.h"
#include "Media.h"
#include "FileIn.h"
#include "MediaAtomBase.h"


#endif
