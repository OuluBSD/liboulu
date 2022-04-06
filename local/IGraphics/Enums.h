#ifndef _IGraphics_Enums_h_
#define _IGraphics_Enums_h_


NAMESPACE_TOPSIDE_BEGIN

namespace GVar {
enum {
	VAR_AUDIOTIME,
	VAR_VIEW,
	VAR_LIGHTDIR,
	VAR_VIEWOVERRIDE,
	VAR_PROJECTIONOVERRIDE,
	VAR_SCALE,
	VAR_MODEL,
	VAR_NONE,
	VAR_DIFFUSE,
	VAR_SPECULAR,
	VAR_AMBIENT,
	VAR_EMISSIVE,
	VAR_HEIGHT,
	VAR_NORMALS,
	VAR_SHININESS,
	VAR_OPACITY,
	VAR_DISPLACEMENT,
	VAR_LIGHTMAP,
	VAR_REFLECTION,
	VAR_UNKNOWN,
	
	VAR_COMPAT_RESOLUTION,
	VAR_COMPAT_TIME,
	VAR_COMPAT_TIMEDELTA,
	VAR_COMPAT_FRAME,
	VAR_COMPAT_MOUSE,
	VAR_COMPAT_DATE,
	VAR_COMPAT_SAMPLERATE,
	VAR_COMPAT_OFFSET,
	VAR_COMPAT_CHANNEL0,
	VAR_COMPAT_CHANNEL1,
	VAR_COMPAT_CHANNEL2,
	VAR_COMPAT_CHANNEL3,
	VAR_COMPAT_FRAMERATE,
	VAR_COMPAT_CHANNELTIME,
	VAR_COMPAT_CHANNELRESOLUTION0,
	VAR_COMPAT_CHANNELRESOLUTION1,
	VAR_COMPAT_CHANNELRESOLUTION2,
	VAR_COMPAT_CHANNELRESOLUTION3,
	VAR_COMPAT_BLOCKOFFSET,
	
	VAR_COUNT,
};

typedef enum {
	SAMPLE_FLOAT,
	SAMPLE_U8,
	SAMPLE_U16,
	SAMPLE_U32,
	SAMPLE_S32,
} Sample;

inline int GetSampleSize(Sample s) {
	switch (s) {
		case SAMPLE_FLOAT:	return 4;
		case SAMPLE_U8:		return 1;
		case SAMPLE_U16:	return 2;
		case SAMPLE_U32:	return 4;
		case SAMPLE_S32:	return 4;
	}
	return 0;
}


typedef enum {
	INVALID = -1,
	EMPTY_INPUT,
	BUFFER_INPUT,
	KEYBOARD_INPUT,
	TEXTURE_INPUT,
	CUBEMAP_INPUT,
	WEBCAM_INPUT,
	MUSIC_INPUT,
	MUSICSTREAM_INPUT,
	VOLUME_INPUT,
	VIDEO_INPUT,
} InputType;

typedef enum {
	UNDEFINED,
	SW,
	OGL,
	DX,
	VLK,
	METAL,
} GfxType;

extern const char* names[GVar::VAR_COUNT+1];
extern const bool is_obj_var[GVar::VAR_COUNT+1];

static const int INPUT_COUNT = 4;


}

NAMESPACE_TOPSIDE_END

#endif