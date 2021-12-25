#ifndef _Graphics_GfxClasses_h_
#define _Graphics_GfxClasses_h_

NAMESPACE_TOPSIDE_BEGIN




////////////// STATE

struct GfxDataState;

struct GfxVertexShaderArgs : RTTIBase {
	RTTI_DECL0(GfxVertexShaderArgs)
	
	virtual ~GfxVertexShaderArgs() {}
};

struct GfxFragmentShaderArgs : RTTIBase {
	RTTI_DECL0(GfxFragmentShaderArgs)
	
	virtual ~GfxFragmentShaderArgs() {}
};


#if 0
struct GfxBinderIface : RTTIBase {
	RTTI_DECL0(GfxBinderIface)
	
	virtual ~GfxBinderIface() {}
	
	virtual void Render(GfxDataState& data) = 0;
	
};
#endif

struct GfxDataObject : RTTIBase {
	RTTI_DECL0(GfxDataObject)
	
	virtual ~GfxDataObject() {}
	
    //virtual void Paint() = 0;
    virtual void MakeTexture(int tex_id, int w, int h, int pitch, int stride, const Vector<byte>& data) = 0;
    virtual void Refresh(Mesh& m) = 0;
    virtual GVar::GfxType GetGfxType() const = 0;
	
	/*
	virtual void SetBool(const String &name, bool value) const = 0;
	virtual void SetInt(const String &name, int value) const = 0;
	virtual void SetFloat(const String &name, float value) const = 0;
	virtual void SetVec2(const String &name, const vec2 &value) const = 0;
	virtual void SetVec3(const String &name, const vec3 &value) const = 0;
	virtual void SetVec4(const String &name, const vec4 &value) const = 0;
	virtual void SetMat2(const String &name, const mat2 &mat) const = 0;
	virtual void SetMat3(const String &name, const mat3 &mat) const = 0;
	virtual void SetMat4(const String &name, const mat4 &mat) const = 0;*/
	
	mat4 model;
	mat4 scale;
	//mat4 proj;
	int tex_id[TEXTYPE_COUNT] = {-1,-1,-1,-1,-1,-1, -1,-1,-1,-1,-1,-1,-1};
	
	void Set(const mat4& model, const mat4& scale) {this->model = model; this->scale = scale;}
	bool IsSoftware() const {return GetGfxType() == GVar::SW;}
	bool IsOpenGL() const {return GetGfxType() == GVar::OGL;}
	
};

struct GfxDataState : ErrorReporter {
	RTTI_DECL1(GfxDataState, ErrorReporter)
	
	// meta
	int		id = -1;
	
	// renderer
    mat4		view;
    vec3		light_dir;
	//GfxShader*	stages[GVar::SHADERTYPE_COUNT] = {0,0,0,0,0};
	
	virtual GfxDataObject& CreateObject() = 0;
	virtual void Refresh(ModelMesh& m) = 0;
	
	/*
	virtual bool LoadModel(ModelLoader& l, GfxDataObject& o) = 0;
	virtual bool LoadModelTextures(ModelLoader& l, GfxDataObject& o) = 0;*/
	
};


////////////// FRAMEBUFFER



struct GfxInputState : ErrorReporter {
	RTTI_DECL1(GfxInputState, ErrorReporter)
	
	using InputType = GVar::InputType;
	
	virtual ~GfxInputState() {}
	
	int id = -1;
	InputType type;
	
	void Clear() {id = -1; type = GVar::InputType::INVALID;}
	
};


struct GfxRenderer;
class Viewable;

struct GfxFramebuffer : ErrorReporter {
	using Sample = GVar::Sample;
	using Filter = GVar::Filter;
	using Wrap = GVar::Wrap;
	
	// stage
	bool	is_win_fbo = 0;
	bool	is_read_fb_output = 0;
	bool	is_audio = 0;
	bool	is_cubemap = 0;
	Filter	filter;
	Wrap	wrap;
	
	// framebuffer
	int8	channels = 0;
	Size	size;
	int		depth = 0;
	Sample	sample = GVar::SAMPLE_FLOAT;
	Point	offset;
	bool	is_doublebuf = 0;
	int		pitch = 0;
	int8	buf_i = 0;
	double	fps = 0;
	
	
	
	RTTI_DECL1(GfxFramebuffer, ErrorReporter)
	GfxFramebuffer() : size(0,0) {}
	virtual ~GfxFramebuffer() {}
	
	virtual bool Create(int w, int h, int channels=3) = 0;
	virtual void Enter() = 0;
	virtual void Leave() = 0;
	virtual byte* GetIterator(int x, int y) = 0;
	virtual void DrawFill(const byte* mem, int sz) = 0;
	
	int GetWidth() const {return size.cx;}
	int GetHeight() const {return size.cy;}
	int GetStride() const {return channels * GVar::GetSampleSize(sample);}
	int GetSampleSize() const {return GVar::GetSampleSize(sample);}
	int GetPitch() const {return pitch;}
	Size GetSize() const {return size;}
	
};




////////////// RUNTIME




struct GfxShader;

struct GfxShaderPipeline : RTTIBase {
	RTTI_DECL0(GfxShaderPipeline)
	GfxShaderPipeline() {}
	virtual ~GfxShaderPipeline() {}
	
	
};

struct GfxShader : RTTIBase {
	
protected:
	Vector<mat4> stack;
	bool is_loaded = false;
	
	
public:
	RTTI_DECL0(GfxShader)
	
	virtual ~GfxShader() {}
	
	void PushMultiplyMat4(String key, const mat4& mat);
	void PopMat4();
	void SetStackMat4(const mat4& mat);
	
	/*
	virtual bool Load(String vertex_path, String fragment_path, String geometry_path = "") = 0;
	virtual bool IsLoaded() const = 0;
	virtual void Refresh(ModelMesh& model) = 0;
    virtual void Refresh(ModelMesh& model, Mesh& mesh) = 0;
	virtual void Use() = 0;
	
	virtual void SetBool(const String &name, bool value) const = 0;
	virtual void SetInt(const String &name, int value) const = 0;
	virtual void SetFloat(const String &name, float value) const = 0;
	virtual void SetVec2(const String &name, const vec2 &value) const = 0;
	virtual void SetVec3(const String &name, const vec3 &value) const = 0;
	virtual void SetVec4(const String &name, const vec4 &value) const = 0;
	virtual void SetMat2(const String &name, const mat2 &mat) const = 0;
	virtual void SetMat3(const String &name, const mat3 &mat) const = 0;
	virtual void SetMat4(const String &name, const mat4 &mat) const = 0;
	
	virtual void SetVec2(const String &name, float x, float y) const {SetVec2(name, vec2(x,y));}
	virtual void SetVec3(const String &name, float x, float y, float z) const {SetVec3(name, vec3(x,y,z));}
	virtual void SetVec4(const String &name, float x, float y, float z, float w) const {SetVec4(name, vec4(x,y,z,w));}
	*/
	
	virtual GfxDataObject* CreateObject() = 0;
	
};

struct GfxCompiler : ErrorReporter {
	RTTI_DECL1(GfxCompiler, ErrorReporter)
	
	virtual ~GfxCompiler() {}
	
};

struct GfxLinker : ErrorReporter {
	RTTI_DECL1(GfxLinker, ErrorReporter)
	
	virtual ~GfxLinker() {}
	
};

struct GfxBuffer : ErrorReporter {
	RTTI_DECL1(GfxBuffer, ErrorReporter)
	
	
};

struct GfxRuntimeState : ErrorReporter {
	RTTI_DECL1(GfxRuntimeState, ErrorReporter)
	
	int		id = -1;
	
};



////////////// CONTEXT




struct GfxContextState : RTTIBase {
	RTTI_DECL0(GfxContextState)
	
	virtual ~GfxContextState() {}
	
	// meta
	String	name;
	String	description;
	
	// context values
	double	time_total = 0;
	double	frame_time = 0;
	double	block_offset = 0;
	int		frames = 0;
	double	time_us = 0;
	double	sample_rate = 0;
	Time	time;
	
	
};

struct GfxRenderer : RTTIBase {
	
protected:
	Size output_sz = Size(0,0);
	
	
public:
	RTTI_DECL0(GfxRenderer)
	GfxRenderer() {}
	virtual ~GfxRenderer() {}
	
	virtual GfxFramebuffer& GetOutputFramebuffer() = 0;
	virtual void PreFrame() = 0;
	virtual void PostFrame() = 0;
	
	virtual void SetSize(Size sz) {output_sz = sz;}
	
	Size GetSize() const {return output_sz;}
	
	
};




////////////// UTILS




struct GfxStateDraw : Draw {
	RTTI_DECL1(GfxStateDraw, Draw)
	
	/*
	virtual GfxRenderer* GetRenderer() = 0;
	virtual GfxFramebuffer* GetFramebuffer() = 0;
	
	virtual void DrawShaderPipeline(GfxShaderPipeline&) {Panic("not implemented");}
	*/
	
	virtual GfxDataState& GetGfxState() = 0;
	virtual bool HasTarget() const = 0;
	
};





NAMESPACE_TOPSIDE_END

#endif
