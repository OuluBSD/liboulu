#ifndef _Local_GEnums_h_
#define _Local_GEnums_h_

NAMESPACE_TOPSIDE_BEGIN
namespace GVar {
	

// note: relative to GL_VERTEX_SHADER_BIT etc.
typedef enum {
	SHADERTYPE_NULL = -1,
	
	VERTEX_SHADER,
	GEOMETRY_SHADER,
	TESS_CONTROL_SHADER,
	TESS_EVALUATION_SHADER,
	FRAGMENT_SHADER,
	
	SHADERTYPE_COUNT
} ShaderType;

#define GVAR_SHADERTYPE_LIST \
	GVAR_SHADERTYPE(VERTEX_SHADER) \
	GVAR_SHADERTYPE(FRAGMENT_SHADER) \
	GVAR_SHADERTYPE(GEOMETRY_SHADER) \
	GVAR_SHADERTYPE(TESS_CONTROL_SHADER) \
	GVAR_SHADERTYPE(TESS_EVALUATION_SHADER)

typedef enum : uint32 {
	PROGRAM_SEPARABLE,
} ParamType;

#define GVAR_PARAMTYPE_LIST \
	PARAM_TYPE(PROGRAM_SEPARABLE)
	
typedef enum : uint32 {
	ACTIVE_UNIFORMS,
} ProgParamType;

#define GVAR_PROGPARAMTYPE_LIST \
	PARAM_TYPE(ACTIVE_UNIFORMS)

typedef enum : uint32 {
	COLOR_BUFFER,
	DEPTH_BUFFER,
	STENCIL_BUFFER,
} BufferType;

#define GVAR_BUFFERTYPE_LIST \
	BUFFER_TYPE(COLOR_BUFFER) \
	BUFFER_TYPE(DEPTH_BUFFER) \
	BUFFER_TYPE(STENCIL_BUFFER)

typedef enum {
	FILTER_NEAREST,
	FILTER_LINEAR,
	FILTER_MIPMAP,
	
	DEFAULT_FILTER = FILTER_LINEAR
} Filter;

#define FILTER_LIST \
	FILTER(NEAREST) \
	FILTER(LINEAR) \
	FILTER(MIPMAP)

typedef enum {
	WRAP_CLAMP,
	WRAP_REPEAT,
	
	DEFAULT_WRAP = WRAP_REPEAT
} Wrap;

#define WRAP_LIST \
	WRAP(CLAMP) \
	WRAP(REPEAT)

typedef enum : uint32 {
	TEXTYPE_2D,
	TEXTYPE_3D,
	TEXTYPE_CUBE_MAP,
	TEXTYPE_CUBE_MAP_SIDE_0,
	TEXTYPE_CUBE_MAP_SIDE_1,
	TEXTYPE_CUBE_MAP_SIDE_2,
	TEXTYPE_CUBE_MAP_SIDE_3,
	TEXTYPE_CUBE_MAP_SIDE_4,
	TEXTYPE_CUBE_MAP_SIDE_5,
	
	TEXTYPE_COUNT
} TextureType;

#define GVAR_TEXTYPE_LIST \
	TEX_TYPE(_3D) \
	TEX_TYPE(_CUBE_MAP) \
	TEX_TYPE(_2D)


















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










typedef enum : unsigned short {
	DBGSRC_WINDOW_SYSTEM	= 0x8247,
	DBGSRC_SHADER_COMPILER,
	DBGSRC_THIRD_PARTY,
	DBGSRC_APPLICATION,
	DBGSRC_OTHER
} DbgSource;

typedef enum : unsigned short {
	DBGTYPE_ERROR		= 0x824C,
	DBGTYPE_DEPRECATED_BEHAVIOR,
	DBGTYPE_UNDEFINED_BEHAVIOR,
	DBGTYPE_PORTABILITY,
	DBGTYPE_PERFORMANCE,
	DBGTYPE_OTHER,
	
	DBGTYPE_MARKER		= 0x8268,
	DBGTYPE_PUSH_GROUP,
	DBGTYPE_POP_GROUP,
	
	DBGTYPE_ERROR_ARB	= 0x824C,
	DBGTYPE_DEPRECATED_BEHAVIOR_ARB,
	DBGTYPE_UNDEFINED_BEHAVIOR_ARB,
	DBGTYPE_PORTABILITY_ARB,
	DBGTYPE_PERFORMANCE_ARB,
} DbgType;

typedef enum : unsigned short {
	DBGSEV_DEBUG_SEVERITY_HIGH            = 0x9146,
	DBGSEV_DEBUG_SEVERITY_MEDIUM,
	DBGSEV_DEBUG_SEVERITY_LOW,
} DbgSeverity;

typedef enum : unsigned short {
	TEXTURE0_ARB		= 0x84C0,
	TEXTURE1_ARB,
	TEXTURE2_ARB,
	TEXTURE3_ARB,
	TEXTURE4_ARB,
	TEXTURE5_ARB,
	TEXTURE6_ARB,
	TEXTURE7_ARB,
	TEXTURE8_ARB,
	TEXTURE9_ARB,
	TEXTURE10_ARB,
	TEXTURE11_ARB,
	TEXTURE12_ARB,
	TEXTURE13_ARB,
	TEXTURE14_ARB,
	TEXTURE15_ARB,
	TEXTURE16_ARB,
	TEXTURE17_ARB,
	TEXTURE18_ARB,
	TEXTURE19_ARB,
	TEXTURE20_ARB,
	TEXTURE21_ARB,
	TEXTURE22_ARB,
	TEXTURE23_ARB,
	TEXTURE24_ARB,
	TEXTURE25_ARB,
	TEXTURE26_ARB,
	TEXTURE27_ARB,
	TEXTURE28_ARB,
	TEXTURE29_ARB,
	TEXTURE30_ARB,
	TEXTURE31_ARB,
	ACTIVE_TEXTURE_ARB,
	CLIENT_ACTIVE_TEXTURE_ARB,
	
	MAX_TEXTURE_UNITS_ARB
} TexArb;

typedef enum : unsigned short {
	TEXTGT_TEXTURE_ENV				= 0x2300,
	TEXTGT_TEXTURE_FILTER_CONTROL	= 0x2200,
	TEXTGT_POINT_SPRIT				= 0x8861
} TexTgt;

typedef enum : unsigned short {
	TEXPARAM_TEXTURE_ENV_MODE		= 0x2200,
	TEXPARAM_TEXTURE_ENV_COLOR,
	TEXPARAM_TEXTURE_LOD_BIAS		= 0x8501
} TexParam;

typedef enum : unsigned short {
	TB_TEXTURE_1D					= 0x0DE0,
	TB_TEXTURE_2D,
	TB_TEXTURE_3D					= 0x806F,
	TB_TEXTURE_1D_ARRAY				= 0x8C18,
	TB_TEXTURE_2D_ARRAY				= 0x8C1A,
	TB_TEXTURE_RECTANGLE			= 0x84F5,
	TB_TEXTURE_CUBE_MAP				= 0x8513,
	TB_TEXTURE_CUBE_MAP_ARRAY		= 0x9009,
	TB_TEXTURE_BUFFER				= 0x8C2A,
	TB_TEXTURE_2D_MULTISAMPLE		= 0x9100,
	TB_TEXTURE_2D_MULTISAMPLE_ARRAY	= 0x9102
} TexBind;

typedef enum : unsigned short {
	ALPHA_TEST				= 0x0BC0,
	//AUTO_NORMAL				= 0x0D80,
	BLEND					= 0x0BE2,
	//CLIP_PLANE0				= 0x3000,
	//CLIP_PLANE1,
	//CLIP_PLANE2,
	//CLIP_PLANE3,
	//CLIP_PLANE4,
	//CLIP_PLANE5,
	COLOR_LOGIC_OP			= 0x0BF2,
	//COLOR_MATERIAL			= 0x0B57,
	//COLOR_TABLE				= 0x80D0,
	//CONVOLUTION_1D			= 0x8010,
	//CONVOLUTION_2D,
	CULL_FACE				= 0x0B44,
	DEPTH_TEST				= 0x0B71,
	DITHER					= 0x0BD0,
	FOG						= 0x0B60,
	//HISTOGRAM				= 0x8024,
	//INDEX_LOGIC_OP			= 0x0BF1,
	//LIGHT0					= 0x4000,
	//LIGHT1,
	//LIGHT2,
	//LIGHT3,
	//LIGHT4,
	//LIGHT5,
	//LIGHT6,
	//LIGHT7,
	//LIGHTING				= 0x0B50,
	//LINE_SMOOTH				= 0x0B20,
	//LINE_STIPPLE			= 0x0B24,
	//MAP1_COLOR_4			= 0x0D90,
	//MAP1_INDEX				= 0x0D91,
	
	
	// UNDEFINED
	
	//MAP1_NORMAL,
	//MAP1_TEXTURE_COORD_1,
	//MAP1_TEXTURE_COORD_2,
	//MAP1_TEXTURE_COORD_3,
	//MAP1_TEXTURE_COORD_4,
	//MAP1_VERTEX_3,
	//MAP1_VERTEX_4,
	//MAP2_COLOR_4,
	//MAP2_INDEX,
	//MAP2_NORMAL,
	//MAP2_TEXTURE_COORD_1,
	//MAP2_TEXTURE_COORD_2,
	//MAP2_TEXTURE_COORD_3,
	//MAP2_TEXTURE_COORD_4,
	//MAP2_VERTEX_3,
	//MAP2_VERTEX_4,
	//MINMAX,
	//NORMALIZE,
	//POINT_SMOOTH,
	POLYGON_OFFSET_FILL		= 0x8037,
	POLYGON_OFFSET_LINE		= 0x2A02,
	POLYGON_OFFSET_POINT	= 0x2A01,
	//POLYGON_SMOOTH,
	//POLYGON_STIPPLE,
	//POST_COLOR_MATRIX_COLOR_TABLE,
	//POST_CONVOLUTION_COLOR_TABLE,
	//RESCALE_NORMAL,
	//SEPARABLE_2D,
	SCISSOR_TEST			= 0x0C11,
	//STENCIL_TEST,
	//TEXTURE_1D,
	TEXTURE_2D				= 0x0DE1,
	//TEXTURE_3D,
	//TEXTURE_GEN_Q,
	//TEXTURE_GEN_R,
	//TEXTURE_GEN_S,
	//TEXTURE_GEN_T
} SysAttr;

typedef enum : unsigned short {
	POINTS				= 0x0000,
	LINES,
	LINE_STRIP,
	LINE_LOOP,
	TRIANGLES,
	TRIANGLE_STRIP,
	TRIANGLE_FAN,
	QUADS,
	QUAD_STRIP,
	POLYGON,
} PrimType;

typedef enum : unsigned short {
	MODELVIEW		= 0x1700,
	PROJECTION,
	TEXTURE,
	COLOR			= 0x1800
} MtxMode;

typedef enum : unsigned short {
	// PARAM_ACCUM_ALPHA_BITS,
	// PARAM_ACCUM_BLUE_BITS,
	// PARAM_ACCUM_CLEAR_VALUE,
	// PARAM_ACCUM_GREEN_BITS,
	// PARAM_ACCUM_RED_BITS,
	// PARAM_ALPHA_BIAS,
	// PARAM_ALPHA_BITS,
	// PARAM_ALPHA_SCALE,
	// PARAM_ALPHA_TEST,
	// PARAM_ALPHA_TEST_FUNC,
	// PARAM_ALPHA_TEST_REF,
	// PARAM_ATTRIB_STACK_DEPTH,
	// PARAM_AUTO_NORMAL,
	// PARAM_AUX_BUFFERS,
	// PARAM_BLEND,
	// PARAM_BLEND_DST,
	// PARAM_BLEND_SRC,
	// PARAM_BLUE_BIAS,
	// PARAM_BLUE_BITS,
	// PARAM_BLUE_SCALE,
	// PARAM_CLIENT_ATTRIB_STACK_DEPTH,
	// PARAM_CLIP_PLANEi,
	// PARAM_COLOR_ARRAY,
	// PARAM_COLOR_ARRAY_SIZE,
	// PARAM_COLOR_ARRAY_STRIDE,
	// PARAM_COLOR_ARRAY_TYPE,
	// PARAM_COLOR_CLEAR_VALUE,
	// PARAM_COLOR_LOGIC_OP,
	// PARAM_COLOR_MATERIAL,
	// PARAM_COLOR_MATERIAL_FACE,
	// PARAM_COLOR_MATERIAL_PARAMETER,
	// PARAM_COLOR_WRITEMASK,
	// PARAM_CULL_FACE,
	// PARAM_CULL_FACE_MODE,
	// PARAM_CURRENT_COLOR,
	// PARAM_CURRENT_INDEX,
	// PARAM_CURRENT_NORMAL,
	// PARAM_CURRENT_RASTER_COLOR,
	// PARAM_CURRENT_RASTER_DISTANCE,
	// PARAM_CURRENT_RASTER_INDEX,
	// PARAM_CURRENT_RASTER_POSITION,
	// PARAM_CURRENT_RASTER_POSITION_VALID,
	// PARAM_CURRENT_RASTER_TEXTURE_COORDS,
	// PARAM_CURRENT_TEXTURE_COORDS,
	// PARAM_DEPTH_BIAS,
	// PARAM_DEPTH_BITS,
	// PARAM_DEPTH_CLEAR_VALUE,
	// PARAM_DEPTH_FUNC,
	// PARAM_DEPTH_RANGE,
	// PARAM_DEPTH_SCALE,
	// PARAM_DEPTH_TEST,
	 PARAM_DEPTH_WRITEMASK		= 0x0B72,
	// PARAM_DITHER,
	// PARAM_DOUBLEBUFFER,
	// PARAM_DRAW_BUFFER,
	// PARAM_EDGE_FLAG,
	// PARAM_EDGE_FLAG_ARRAY,
	// PARAM_EDGE_FLAG_ARRAY_STRIDE,
	// PARAM_FOG,
	// PARAM_FOG_COLOR,
	// PARAM_FOG_DENSITY,
	// PARAM_FOG_END,
	// PARAM_FOG_HINT,
	// PARAM_FOG_INDEX,
	// PARAM_FOG_MODE,
	// PARAM_FOG_START,
	// PARAM_FRONT_FACE,
	// PARAM_GREEN_BIAS,
	// PARAM_GREEN_BITS,
	// PARAM_GREEN_SCALE,
	// PARAM_INDEX_ARRAY,
	// PARAM_INDEX_ARRAY_STRIDE,
	// PARAM_INDEX_ARRAY_TYPE,
	// PARAM_INDEX_BITS,
	// PARAM_INDEX_CLEAR_VALUE,
	// PARAM_INDEX_LOGIC_OP,
	// PARAM_INDEX_MODE,
	// PARAM_INDEX_OFFSET,
	// PARAM_INDEX_SHIFT,
	// PARAM_INDEX_WRITEMASK,
	// PARAM_LIGHTi,
	// PARAM_LIGHTING,
	// PARAM_LIGHT_MODEL_AMBIENT,
	// PARAM_LIGHT_MODEL_LOCAL_VIEWER,
	// PARAM_LIGHT_MODEL_TWO_SIDE,
	// PARAM_LINE_SMOOTH,
	// PARAM_LINE_SMOOTH_HINT,
	// PARAM_LINE_STIPPLE,
	// PARAM_LINE_STIPPLE_PATTERN,
	// PARAM_LINE_STIPPLE_REPEAT,
	// PARAM_LINE_WIDTH,
	// PARAM_LINE_WIDTH_GRANULARITY,
	// PARAM_LINE_WIDTH_RANGE,
	// PARAM_LIST_BASE,
	// PARAM_LIST_INDEX,
	// PARAM_LIST_MODE,
	// PARAM_LOGIC_OP,
	// PARAM_LOGIC_OP_MODE,
	// PARAM_MAP1_COLOR_4,
	// PARAM_MAP1_GRID_DOMAIN,
	// PARAM_MAP1_GRID_SEGMENTS,
	// PARAM_MAP1_INDEX,
	// PARAM_MAP1_NORMAL,
	// PARAM_MAP1_TEXTURE_COORD_1,
	// PARAM_MAP1_TEXTURE_COORD_2,
	// PARAM_MAP1_TEXTURE_COORD_3,
	// PARAM_MAP1_TEXTURE_COORD_4,
	// PARAM_MAP1_VERTEX_3,
	// PARAM_MAP1_VERTEX_4,
	// PARAM_MAP2_COLOR_4,
	// PARAM_MAP2_GRID_DOMAIN,
	// PARAM_MAP2_GRID_SEGMENTS,
	// PARAM_MAP2_INDEX,
	// PARAM_MAP2_NORMAL,
	// PARAM_MAP2_TEXTURE_COORD_1,
	// PARAM_MAP2_TEXTURE_COORD_2,
	// PARAM_MAP2_TEXTURE_COORD_3,
	// PARAM_MAP2_TEXTURE_COORD_4,
	// PARAM_MAP2_VERTEX_3,
	// PARAM_MAP2_VERTEX_4,
	// PARAM_MAP_COLOR,
	// PARAM_MAP_STENCIL,
	// PARAM_MATRIX_MODE,
	// PARAM_MAX_CLIENT_ATTRIB_STACK_DEPTH,
	// PARAM_MAX_ATTRIB_STACK_DEPTH,
	// PARAM_MAX_CLIP_PLANES,
	// PARAM_MAX_EVAL_ORDER,
	// PARAM_MAX_LIGHTS,
	// PARAM_MAX_LIST_NESTING,
	// PARAM_MAX_MODELVIEW_STACK_DEPTH,
	// PARAM_MAX_NAME_STACK_DEPTH,
	// PARAM_MAX_PIXEL_MAP_TABLE,
	// PARAM_MAX_PROJECTION_STACK_DEPTH,
	// PARAM_MAX_TEXTURE_SIZE,
	// PARAM_MAX_TEXTURE_STACK_DEPTH,
	// PARAM_MAX_VIEWPORT_DIMS,
	// PARAM_MODELVIEW_MATRIX,
	// PARAM_MODELVIEW_STACK_DEPTH,
	// PARAM_NAME_STACK_DEPTH,
	// PARAM_NORMAL_ARRAY,
	// PARAM_NORMAL_ARRAY_STRIDE,
	// PARAM_NORMAL_ARRAY_TYPE,
	// PARAM_NORMALIZE,
	// PARAM_PACK_ALIGNMENT,
	// PARAM_PACK_LSB_FIRST,
	// PARAM_PACK_ROW_LENGTH,
	// PARAM_PACK_SKIP_PIXELS,
	// PARAM_PACK_SKIP_ROWS,
	// PARAM_PACK_SWAP_BYTES,
	// PARAM_PERSPECTIVE_CORRECTION_HINT,
	// PARAM_PIXEL_MAP_A_TO_A_SIZE,
	// PARAM_PIXEL_MAP_B_TO_B_SIZE,
	// PARAM_PIXEL_MAP_G_TO_G_SIZE,
	// PARAM_PIXEL_MAP_I_TO_A_SIZE,
	// PARAM_PIXEL_MAP_I_TO_B_SIZE,
	// PARAM_PIXEL_MAP_I_TO_G_SIZE,
	// PARAM_PIXEL_MAP_I_TO_I_SIZE,
	// PARAM_PIXEL_MAP_I_TO_R_SIZE,
	// PARAM_PIXEL_MAP_R_TO_R_SIZE,
	// PARAM_PIXEL_MAP_S_TO_S_SIZE,
	// PARAM_POINT_SIZE,
	// PARAM_POINT_SIZE_GRANULARITY,
	// PARAM_POINT_SIZE_RANGE,
	// PARAM_POINT_SMOOTH,
	// PARAM_POINT_SMOOTH_HINT,
	// PARAM_POLYGON_MODE,
	// PARAM_POLYGON_OFFSET_FACTOR,
	// PARAM_POLYGON_OFFSET_UNITS,
	// PARAM_POLYGON_OFFSET_FILL,
	// PARAM_POLYGON_OFFSET_LINE,
	// PARAM_POLYGON_OFFSET_POINT,
	// PARAM_POLYGON_SMOOTH,
	// PARAM_POLYGON_SMOOTH_HINT,
	// PARAM_POLYGON_STIPPLE,
	// PARAM_PROJECTION_MATRIX,
	// PARAM_PROJECTION_STACK_DEPTH,
	// PARAM_READ_BUFFER,
	// PARAM_RED_BIAS,
	// PARAM_RED_BITS,
	// PARAM_RED_SCALE,
	// PARAM_RENDER_MODE,
	// PARAM_RGBA_MODE,
	// PARAM_SCISSOR_BOX,
	// PARAM_SCISSOR_TEST,
	// PARAM_SHADE_MODEL,
	// PARAM_STENCIL_BITS,
	// PARAM_STENCIL_CLEAR_VALUE,
	// PARAM_STENCIL_FAIL,
	// PARAM_STENCIL_FUNC,
	// PARAM_STENCIL_PASS_DEPTH_FAIL,
	// PARAM_STENCIL_PASS_DEPTH_PASS,
	// PARAM_STENCIL_REF,
	// PARAM_STENCIL_TEST,
	// PARAM_STENCIL_VALUE_MASK,
	// PARAM_STENCIL_WRITEMASK,
	// PARAM_STEREO,
	// PARAM_SUBPIXEL_BITS,
	// PARAM_TEXTURE_1D,
	// PARAM_TEXTURE_2D,
	// PARAM_TEXTURE_COORD_ARRAY,
	// PARAM_TEXTURE_COORD_ARRAY_SIZE,
	// PARAM_TEXTURE_COORD_ARRAY_STRIDE,
	// PARAM_TEXTURE_COORD_ARRAY_TYPE,
	// PARAM_TEXTURE_ENV_COLOR,
	// PARAM_TEXTURE_ENV_MODE,
	// PARAM_TEXTURE_GEN_Q,
	// PARAM_TEXTURE_GEN_R,
	// PARAM_TEXTURE_GEN_S,
	// PARAM_TEXTURE_GEN_T,
	// PARAM_TEXTURE_MATRIX,
	// PARAM_TEXTURE_STACK_DEPTH,
	// PARAM_UNPACK_ALIGNMENT,
	// PARAM_UNPACK_LSB_FIRST,
	// PARAM_UNPACK_ROW_LENGTH,
	// PARAM_UNPACK_SKIP_PIXELS,
	// PARAM_UNPACK_SKIP_ROWS,
	// PARAM_UNPACK_SWAP_BYTES,
	// PARAM_VERTEX_ARRAY,
	// PARAM_VERTEX_ARRAY_SIZE,
	// PARAM_VERTEX_ARRAY_STRIDE,
	// PARAM_VERTEX_ARRAY_TYPE,
	// PARAM_VIEWPORT,
	// PARAM_ZOOM_X,
	// PARAM_ZOOM_Y,
} ParamEnum;

typedef enum : unsigned short {
	PN_DEPTH_STENCIL_TEXTURE_MODE	= 0x90EA,
	PN_TEXTURE_BASE_LEVEL			= 0x813C,
	PN_TEXTURE_COMPARE_FUNC			= 0x884D,
	PN_TEXTURE_COMPARE_MODE			= 0x884C,
	PN_TEXTURE_LOD_BIAS				= 0x8501,
	PN_TEXTURE_MIN_FILTER			= 0x2801,
	PN_TEXTURE_MAG_FILTER			= 0x2800,
	PN_TEXTURE_MIN_LOD				= 0x813A,
	PN_TEXTURE_MAX_LOD				= 0x813B,
	PN_TEXTURE_MAX_LEVEL			= 0x813D,
	PN_TEXTURE_SWIZZLE_R			= 0x8E42,
	PN_TEXTURE_SWIZZLE_G,
	PN_TEXTURE_SWIZZLE_B,
	PN_TEXTURE_SWIZZLE_A,
	PN_TEXTURE_WRAP_S				= 0x2802,
	PN_TEXTURE_WRAP_T,
	PN_TEXTURE_WRAP_R				= 0x8072
} ParamName;

enum {
	BF_CURRENT_BIT                          = 0x00000001,
	BF_POINT_BIT                            = 0x00000002,
	BF_LINE_BIT                             = 0x00000004,
	BF_POLYGON_BIT                          = 0x00000008,
	BF_POLYGON_STIPPLE_BIT                  = 0x00000010,
	BF_PIXEL_MODE_BIT                       = 0x00000020,
	BF_LIGHTING_BIT                         = 0x00000040,
	BF_FOG_BIT                              = 0x00000080,
	BF_DEPTH_BUFFER_BIT                     = 0x00000100,
	BF_ACCUM_BUFFER_BIT                     = 0x00000200,
	BF_STENCIL_BUFFER_BIT                   = 0x00000400,
	BF_VIEWPORT_BIT                         = 0x00000800,
	BF_TRANSFORM_BIT                        = 0x00001000,
	BF_ENABLE_BIT                           = 0x00002000,
	BF_COLOR_BUFFER_BIT                     = 0x00004000,
	BF_HINT_BIT                             = 0x00008000,
	BF_EVAL_BIT                             = 0x00010000,
	BF_LIST_BIT                             = 0x00020000,
	BF_TEXTURE_BIT                          = 0x00040000,
	BF_SCISSOR_BIT                          = 0x00080000,
	BF_ALL_ATTRIB_BITS                      = 0xFFFFFFFF,
};

typedef enum : unsigned short {
	CM_FRONT			= 0x0404,
	CM_BACK				= 0x0405,
	CM_FRONT_AND_BACK	= 0x0408,
} CullMode;

typedef enum : unsigned short {
	FLAT				= 0x1D00,
	SMOOTH
} ShadeMode;

typedef enum : unsigned short {
	FOGPARAM_INDEX		= 0x0B61,
	FOGPARAM_DENSITY,
	FOGPARAM_START,
	FOGPARAM_END,
	FOGPARAM_MODE,
	FOGPARAM_COLOR,
} FogParam;

typedef enum : unsigned short {
	FOGMODE_LINEAR		= 0x2601,
	FOGMODE_EXP			= 0x0800,
	FOGMODE_EXP2
} FogMode;

typedef enum : unsigned short {
	SRCFAC_ZERO					= 0x0000,
	SRCFAC_ONE,
	SRCFAC_DST_COLOR			= 0x0306,
	SRCFAC_ONE_MINUS_DST_COLOR,
	SRCFAC_SRC_ALPHA			= 0x0302,
	SRCFAC_ONE_MINUS_SRC_ALPHA,
	SRCFAC_DST_ALPHA			= 0x0304,
	SRCFAC_ONE_MINUS_DST_ALPHA,
	SRCFAC_SRC_ALPHA_SATURATE	= 0x0308
} SrcFactor;

typedef enum : unsigned short {
	DSTFAC_ZERO					= 0x0000,
	DSTFAC_ONE,
	DSTFAC_SRC_COLOR			= 0x0300,
	DSTFAC_ONE_MINUS_SRC_COLOR,
	DSTFAC_SRC_ALPHA,
	DSTFAC_ONE_MINUS_SRC_ALPHA,
	DSTFAC_DST_ALPHA,
	DSTFAC_ONE_MINUS_DST_ALPHA
} DstFactor;

typedef enum : unsigned short {
	LOGOP_CLEAR			= 0x1500,
	LOGOP_SET			= 0x150F,
	LOGOP_COPY			= 0x1503,
	LOGOP_COPY_INVERTED	= 0x150C,
	LOGOP_NOOP			= 0x1505,
	LOGOP_INVERT		= 0x150A,
	LOGOP_AND			= 0x1501,
	LOGOP_NAND			= 0x150E,
	LOGOP_OR			= 0x1507,
	LOGOP_NOR			= 0x1508,
	LOGOP_XOR			= 0x1506,
	LOGOP_EQUIV			= 0x1509,
	LOGOP_AND_REVERSE	= 0x1502,
	LOGOP_AND_INVERTED	= 0x1504,
	LOGOP_OR_REVERSE	= 0x150B,
	LOGOP_OR_INVERTED	= 0x150D,
} LogicOpType;

typedef enum : unsigned short {
	LOGFU_NEVER			= 0x0200,
	LOGFU_LESS,
	LOGFU_EQUAL,
	LOGFU_LEQUAL,
	LOGFU_GREATER,
	LOGFU_NOTEQUAL,
	LOGFU_GEQUAL,
	LOGFU_ALWAYS,
} LogicFuncType;

typedef enum : unsigned short {
	INF_1 = 1,
	INF_2,
	INF_3,
	INF_4,
	/*INF_ALPHA					= 0x1906,
	
	// UNDEFINED
	
	INF_ALPHA4,
	INF_ALPHA8,
	INF_ALPHA12,
	INF_ALPHA16,
	INF_LUMINANCE,
	INF_LUMINANCE4,
	INF_LUMINANCE8,
	INF_LUMINANCE12,
	INF_LUMINANCE16,
	INF_LUMINANCE_ALPHA,
	INF_LUMINANCE4_ALPHA4,
	INF_LUMINANCE6_ALPHA2,
	INF_LUMINANCE8_ALPHA8,
	INF_LUMINANCE12_ALPHA4,
	INF_LUMINANCE12_ALPHA12,
	INF_LUMINANCE16_ALPHA16,
	INF_INTENSITY,
	INF_INTENSITY4,
	INF_INTENSITY8,
	INF_INTENSITY12,
	INF_INTENSITY16,
	INF_R3_G3_B2,
	INF_RGB,
	INF_RGB4,
	INF_RGB5,
	INF_RGB8,
	INF_RGB10,
	INF_RGB12,
	INF_RGB16,
	INF_RGBA,
	INF_RGBA2,
	INF_RGBA4,
	INF_RGB5_A1,
	INF_RGBA8,
	INF_RGB10_A2,
	INF_RGBA12,
	INF_RGBA16*/
} InFmt;

typedef enum : unsigned short {
	PF_COLOR_INDEX		= 0x1900,
	PF_STENCIL_INDEX,
	PF_DEPTH_COMPONENT,
	PF_RED,
	PF_GREEN,
	PF_BLUE,
	PF_ALPHA,
	PF_RGB,
	PF_RGBA,
	PF_LUMINANCE,
	PF_LUMINANCE_ALPHA,
	PF_BGR_EXT			= 0x80E0,
	PF_BGRA_EXT,
} PixFmt;

typedef enum : unsigned short {
	PT_BYTE				= 0x1400,
	PT_UNSIGNED_BYTE,
	PT_SHORT,
	PT_UNSIGNED_SHORT,
	PT_INT,
	PT_UNSIGNED_INT,
	PT_FLOAT,
	PT_BITMAP			= 0x1A00,
} PixType;

typedef enum : unsigned short {
	PA_PACK_SWAP_BYTES		= 0x0D00,
	PA_PACK_LSB_FIRST,
	PA_PACK_ROW_LENGTH,
	PA_PACK_SKIP_PIXELS,
	PA_PACK_SKIP_ROWS,
	PA_PACK_ALIGNMENT,
	
	PA_UNPACK_SWAP_BYTES	= 0x0CF0,
	PA_UNPACK_LSB_FIRST,
	PA_UNPACK_ROW_LENGTH,
	PA_UNPACK_SKIP_ROWS,
	PA_UNPACK_SKIP_PIXELS,
	PA_UNPACK_ALIGNMENT
} PixAlign;

typedef enum : unsigned short {
	PTRANS_MAP_COLOR		= 0x0D10,
	PTRANS_MAP_STENCIL,
	PTRANS_INDEX_SHIFT,
	PTRANS_INDEX_OFFSET,
	PTRANS_RED_SCALE,
	PTRANS_RED_BIAS,
	PTRANS_GREEN_SCALE,
	PTRANS_GREEN_BIAS,
	PTRANS_BLUE_SCALE,
	PTRANS_BLUE_BIAS,
	PTRANS_ALPHA_SCALE,
	PTRANS_ALPHA_BIAS,
	PTRANS_DEPTH_SCALE,
	PTRANS_DEPTH_BIAS
} PixTrans;

typedef enum : unsigned short {
	TEV_MODULATE			= 0x2100,
	TEV_DECAL,
	TEV_BLEND				= 0x0BE2,
	TEV_REPLACE				= 0x1E01
} TexEnvValue;

typedef enum : unsigned short {
	TW_CLAMP_TO_EDGE		= 0x812F,
	TW_CLAMP_TO_BORDER		= 0x812D,
	TW_MIRRORED_REPEAT		= 0x8370,
	TW_CLAMP				= 0x2900,
	TW_REPEAT,
	TW_MIRROR_CLAMP_TO_EDGE	= 0x8743,
} TexWrap;

typedef enum : unsigned short {
	MAGF_NEAREST			= 0x2600,
	MAGF_LINEAR
} MagFilter;

typedef enum : unsigned short {
	MINF_NEAREST			= 0x2600,
	MINF_LINEAR,
	MINF_NEAREST_MIPMAP_NEAREST	= 0x2700,
	MINF_LINEAR_MIPMAP_NEAREST,
	MINF_NEAREST_MIPMAP_LINEAR,
	MINF_LINEAR_MIPMAP_LINEAR,
} MinFilter;

}




NAMESPACE_TOPSIDE_END

#endif
