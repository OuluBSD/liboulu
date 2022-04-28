
static void BindProgramPipeline(NativePipeline& pipeline);
static void UseProgram(NativeProgram& prog);
//static void EnterFramebuffer(NativeFrameBuffer& fb);
static void FramebufferTexture2D(TexType tgt, NativeColorBufferRef b);
static void FramebufferRenderbuffer(NativeDepthBufferRef fb);
static void BindFramebuffer(NativeFrameBufferRef fb);
static void BindRenderbuffer(NativeDepthBufferRef rb);
static void UnbindRenderbuffer();
static void RenderbufferStorage(Size sz);
static void UnbindProgramPipeline();
static void BindFramebufferDefault();
static void DrawBuffers(GVar::RenderTarget tgt);
//static void SetRender_Color();
static void RenderScreenRect();
static const char* GetShaderTemplate(GVar::ShaderType t);
static void HotfixShaderCode(String& s);
static void ActiveTexture(int ch);
static void DeactivateTexture();
static void BindTextureRO(GVar::TextureType type, NativeColorBufferConstRef tex);
static void BindTextureRW(GVar::TextureType type, NativeColorBufferRef tex);
static void UnbindTexture(GVar::TextureType type);
static void GenerateMipmap(GVar::TextureType type);
static bool CreateShader(GVar::ShaderType t, NativeShaderRef& new_shdr);
static void ShaderSource(NativeShaderRef s, String code);
static bool CompileShader(NativeShaderRef s);
static String GetLastErrorS(NativeShaderRef s);
static String GetLastErrorP(NativeProgram& s);
static bool CreateProgram(NativeProgram& prog);
static bool CreateRenderbuffer(NativeDepthBufferRef& b);
static void ProgramParameteri(NativeProgram& prog, GVar::ParamType type, int i);
static void AttachShader(NativeProgram& prog, NativeShaderRef shdr);
static void DeleteShader(NativeShaderRef& shdr);
static bool LinkProgram(NativeProgram& prog);
static void GetProgramiv(NativeProgram& prog, GVar::ProgParamType type, int& out);
static String GetActiveUniform(NativeProgram& prog, int i, int* size_out=0, int* type_out=0);
static void Clear(GVar::BufferType type);
static void GenProgramPipeline(NativePipeline& pipe);
static void UseProgramStages(NativePipeline& pipe, uint32 shader_type_bmask, NativeProgram& prog);
static void DeleteProgramPipeline(NativePipeline& pipe);
static void TexParameteri(GVar::TextureType type, GVar::Filter filter, GVar::Wrap repeat);
static bool GenTexture(NativeColorBufferRef& fb);
static bool CreateFramebuffer(NativeFrameBufferRef& fb);
static void GenVertexArray(NativeVertexArray& vao);
static void GenVertexBuffer(NativeVertexBuffer& vbo);
static void GenElementBuffer(NativeElementBuffer& ebo);
static void BindVertexArray(NativeVertexArray& vao);
static void BindVertexBuffer(NativeVertexBuffer& vbo);
static void BindElementBuffer(NativeElementBuffer& ebo);
static void DeleteVertexArray(NativeVertexArray& vao);
static void DeleteVertexBuffer(NativeVertexBuffer& vbo);
static void DeleteElementBuffer(NativeElementBuffer& ebo);
static void VertexBufferData(const Vector<Vertex>& vtx);
static void ElementBufferData(const Vector<uint32>& el);
static void SetupVertexStructure();
static void UnbindVertexArray();
static void UnbindVertexBuffer();
static void UnbindElementBuffer();
static void UnbindFramebuffer();
static void ActivateVertexStructure();
static void DeactivateVertexStructure();
static void DrawVertexElements(int element_limit);
static void TexImage2D(ByteImage& tex);
static void DeleteTexture(NativeColorBufferRef& b);
static void DeleteRenderbuffer(NativeDepthBufferRef& b);
static void DeleteFramebuffer(NativeFrameBufferRef& b);
static void SetContextDefaultFramebuffer(NativeFrameBufferRef fb);
static void BeginRender();
static void EndRender();
//static NativeColorBufferConstRef GetFrameBufferColor(NativeFrameBufferConstRef fb, TexType t);
static void Uniform1i(int idx, int f);
static void Uniform1f(int idx, float f);
static void Uniform2f(int idx, float f0, float f1);
static void Uniform3f(int idx, float f0, float f1, float f2);
static void Uniform4f(int idx, float f0, float f1, float f2, float f3);
static void UniformMatrix4fv(int idx, const mat4& mat);

static void ClearBuffers();
static void SetSmoothShading(bool b=true);
static void SetDepthTest(bool b=true);
static void SetDepthOrderLess(bool b=true);
static void SetClearValue(RGBA clr, byte depth);
static void SetFastPerspectiveCorrection(bool b=true);
static void SetTriangleBacksideCulling(bool b=true);
static void SetTriangleFrontsideCCW(bool b=true);
static void SetViewport(Size sz);
//static void ActivateNextFrame();
static void SetDebugOutput(bool b=true);

