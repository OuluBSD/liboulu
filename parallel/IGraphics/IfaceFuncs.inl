// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!
// Last export: 25.3.25 19:11:33

void BindProgramPipeline(NativePipeline&);
void UseProgram(NativeProgram&);
void UnbindProgramPipeline();
const char* GetShaderTemplate(ShaderType);
void HotfixShaderCode(String&);
void DrawBuffers(RenderTarget);
void ActiveTexture(in);
bool CreateShader(ShaderType, NativeShader&);
void ShaderSource(NativeShader&, String);
bool CompileShader(NativeShader& s);
String GetLastErrorS(NativeShader& s);
String GetLastErrorP(NativeProgram& s);
bool CreateProgram(NativeProgram& prog);
void ProgramParameteri(NativeProgram& prog, GVar::ParamType type, int i);
void AttachShader(NativeProgram& prog, NativeShader& shdr);
void DeleteShader(NativeShader& shdr);
bool LinkProgram(NativeProgram& prog);
void GetProgramiv(NativeProgram& prog, GVar::ProgParamType type, int& out);
String GetActiveUniform(NativeProgram& prog, int i, int* size_out=0, int* type_out=0);
void Clear(GVar::BufferType type);
void GenProgramPipeline(NativePipeline& pipe);
void UseProgramStages(NativePipeline& pipe, uint32 shader_type_bmask, NativeProgram& prog);
void DeleteProgramPipeline(NativePipeline& pipe);
void TexParameteri(GVar::TextureType type, GVar::Filter filter, GVar::Wrap repeat);
bool GenTexture(NativeFrameBuffer& fb);
void GenVertexArray(NativeVertexArray& vao);
void GenVertexBuffer(NativeVertexBuffer& vbo);
void GenElementBuffer(NativeElementBuffer& ebo);
void BindVertexArray(NativeVertexArray& vao);
void BindVertexBuffer(NativeVertexBuffer& vbo);
void BindElementBuffer(NativeElementBuffer& ebo);
void VertexBufferData(const Vector<Vertex>& vtx);
void ElementBufferData(const Vector<uint32>& el);
void SetupVertexStructure();
void UnbindVertexArray();
void UnbindVertexBuffer();
void UnbindElementBuffer();
void ActivateVertexStructure();
void DeactivateVertexStructure();
void DrawVertexElements(int element_limit);
void TexImage2D(Texture& tex);
void DeleteVertexArray(NativeVertexArray& vao);
void DeleteVertexBuffer(NativeVertexBuffer& vbo);
void DeleteElementBuffer(NativeElementBuffer& ebo);
void DeleteTexture(NativeColorBuffer& b);
void Uniform1i(int idx, int f);
void Uniform1f(int idx, float f);
void Uniform2f(int idx, float f0, float f1);
void Uniform3f(int idx, float f0, float f1, float f2);
void Uniform4f(int idx, float f0, float f1, float f2, float f3);
void UniformMatrix4fv(int idx, const mat4& mat);
void ClearBuffers();
void SetSmoothShading(bool b=true);
void SetDepthTest(bool b=true);
void SetDepthOrderLess(bool b=true);
void SetClearValue(RGBA clr, byte depth);
void SetFastPerspectiveCorrection(bool b=true);
void SetTriangleBacksideCulling(bool b=true);
void SetTriangleFrontsideCCW(bool b=true);
void SetViewport(Size sz);
void SetDebugOutput(bool b=true);
void BindFramebufferEXT(NativeFrameBuffer& fb);
void BindTextureRO(GVar::TextureType type, const NativeFrameBuffer& tex);
void BindTextureRW(GVar::TextureType type, NativeFrameBuffer& tex);
void UnbindTexture(GVar::TextureType type);
void GenerateMipmap(GVar::TextureType type);
void BindFramebufferDefault();
void RenderScreenRect();
void SetContextDefaultFramebuffer(NativeFrameBuffer& fb);
void BeginRender();
void EndRender();
