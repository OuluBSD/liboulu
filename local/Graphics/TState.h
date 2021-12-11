#ifndef _Graphics_TState_h_
#define _Graphics_TState_h_

NAMESPACE_TOPSIDE_BEGIN

template <class Gfx> struct DataStateT;

template <class Gfx>
struct VertexShaderArgsT : GfxVertexShaderArgs {
	using Base = VertexShaderArgsT<Gfx>;
	using DataState = typename Gfx::DataState;
	using DataObject = typename Gfx::DataObject;
	RTTI_DECL1(VertexShaderArgsT, GfxVertexShaderArgs)
	
	
	DataState* state = 0;
	DataObject* obj = 0;
	const vec3* pos = 0;
	const vec3* normal = 0;
	const vec2* tex_coords = 0;
	vec4* pos_out = 0;
	vec2* tex_coord_out = 0;
};

template <class Gfx>
struct FragmentShaderArgsT : GfxFragmentShaderArgs {
	using Base = FragmentShaderArgsT<Gfx>;
	RTTI_DECL1(FragmentShaderArgsT, GfxFragmentShaderArgs)
	
	
};

template <class Gfx>
struct DataObjectT : GfxDataObject {
	using Base = DataObjectT<Gfx>;
	RTTI_DECL1(DataObjectT, GfxDataObject)
	
	using DataState = typename Gfx::DataState;
	using NatTex = typename Gfx::NativeTexture;
	using NatVertexArray = typename Gfx::NativeVertexArray;
	using NatVertexBuffer = typename Gfx::NativeVertexBuffer;
	using NatElementBuffer = typename Gfx::NativeElementBuffer;
	using DataStateBase = DataStateT<Gfx>;
	
	DataStateBase* state = 0;
	VectorMap<int,NatTex> tex;
	uint32 element_count = 0;
	NatVertexArray vao;
	NatVertexBuffer vbo;
	NatElementBuffer ebo;
	
    mat4 view;
    mat4 proj;
    mat4 scale;
    mat4 model;
    bool is_global_view = false;
    int id = -1;
	
	
	DataObjectT();
	~DataObjectT();
	void SetState(DataStateBase* state) {this->state = state;}
	void Refresh(Mesh& m) override {TODO}
    void FreeOgl() {TODO}
    void Paint() override {TODO}
    void MakeTexture(int tex_id, int w, int h, int pitch, int stride, const Vector<byte>& data) override {TODO}
    
    GVar::GfxType GetGfxType() const override {return Gfx::Type;}
	
};

template <class Gfx>
struct DataStateT : GfxDataState {
	RTTI_DECL1(DataStateT, GfxDataState)
	using Base = DataStateT<Gfx>;
	using NatColorBuf = typename Gfx::NativeColorBuffer;
	using NatDepthBuf = typename Gfx::NativeDepthBuffer;
	using NatFrameBuf = typename Gfx::NativeFrameBuffer;
	using NatProgram  = typename Gfx::NativeProgram;
	using NatPipeline = typename Gfx::NativePipeline;
	using NatShader = typename Gfx::NativeShader;
	using ShaderState = typename Gfx::ShaderState;
	using InputState = typename Gfx::InputState;
	using DataObject = typename Gfx::DataObject;
	using Framebuffer = typename Gfx::Framebuffer;
	
	
	Array<DataObject> objects;
	
	
	DataStateT();
	DataObject& AddObject();
	GfxDataObject& CreateObject() override {return AddObject();}
	
	void Refresh(ModelMesh& m) override {TODO}
	void LoadModel(ModelLoader& l, String path) override {TODO}
	
};





NAMESPACE_TOPSIDE_END

#endif
