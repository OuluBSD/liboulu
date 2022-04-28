#include "IGraphics.h"

NAMESPACE_PARALLEL_BEGIN





template <class Gfx>
typename CpuGfxT<Gfx>::Thread& CpuGfxT<Gfx>::Local() {thread_local static Thread t; return t;}

template <class Gfx>
SoftRendT<Gfx>& CpuGfxT<Gfx>::Rend() {return Local().rend;}



template <class Gfx>
void CpuGfxT<Gfx>::SetDebugOutput(bool b) {
	Rend().SetDebugOutput(b);
}

template <class Gfx>
void CpuGfxT<Gfx>::ClearBuffers() {
	auto fb = Local().fb;
	ASSERT(fb);
	if (fb)
		Rend().DrawDefault(*fb);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetSmoothShading(bool b) {
	Rend().SetSmoothShading(b);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetDepthTest(bool b) {
	Rend().SetDepthTest(b);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetDepthOrderLess(bool b) {
	Rend().SetDepthOrderLess(b);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetClearValue(RGBA clr, byte depth) {
	Rend().SetClearValue(clr, depth);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetFastPerspectiveCorrection(bool b) {
	Rend().SetFastPerspectiveCorrection(b);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetTriangleBacksideCulling(bool b) {
	Rend().SetTriangleBacksideCulling(b);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetTriangleFrontsideCCW(bool b) {
	Rend().SetTriangleFrontsideCCW(b);
}

template <class Gfx>
void CpuGfxT<Gfx>::SetViewport(Size sz) {
	Rend().SetViewport(sz);
}

template <class Gfx>
void CpuGfxT<Gfx>::UseProgram(NativeProgram& prog) {
	Local().prog = &prog;
}

template <class Gfx>
void CpuGfxT<Gfx>::BindProgramPipeline(NativePipeline& pipeline) {
	Local().pipe = &pipeline;
}

template <class Gfx>
void CpuGfxT<Gfx>::UnbindProgramPipeline() {
	Local().pipe = 0;
	Local().prog = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::DrawBuffers(GVar::RenderTarget tgt) {
	auto& l = Local();
	l.rend.SetDrawBuffers(tgt);
	/*l.rend.SetTarget(tgt);
	for(int i = 0; i < CHANNEL_COUNT; i++) {
		uint32 j = 1 << i;
		if ((uint32)tgt & j) {
			auto rw = l.texture[i].rw;
			ASSERT(rw);
			if (rw)
				l.rend.AddTarget(*rw);
		}
	}*/
}

/*void CpuGfxT<Gfx>::Clear_Color() {
	glClear(GL_COLOR_BUFFER_BIT);
}*/

template <class Gfx>
void CpuGfxT<Gfx>::ActiveTexture(int ch) {
	ASSERT(ch >= 0 && ch < CHANNEL_COUNT);
	Local().active_texture = ch;
}

template <class Gfx>
void CpuGfxT<Gfx>::DeactivateTexture() {
	Local().active_texture = -1;
}

/*void CpuRendererBase::ActivateNextFrame() {
	// pass
}*/

template <class Gfx>
const char* CpuGfxT<Gfx>::GetShaderTemplate(GVar::ShaderType t) {
	static const char* shader_tmpl = "";
	return shader_tmpl;
}

template <class Gfx>
void CpuGfxT<Gfx>::HotfixShaderCode(String& s) {}

template <class Gfx>
void CpuGfxT<Gfx>::Uniform1i(int idx, int i) {
	auto& prog = Local().prog;
	ASSERT(prog)
	if (prog) prog->SetVar(idx, i);
}

template <class Gfx>
void CpuGfxT<Gfx>::Uniform1f(int idx, float f) {
	auto& prog = Local().prog;
	ASSERT(prog)
	if (prog) prog->SetVar(idx, f);
}

template <class Gfx>
void CpuGfxT<Gfx>::Uniform2f(int idx, float f0, float f1) {
	auto& prog = Local().prog;
	ASSERT(prog)
	if (prog) prog->SetVar(idx, f0, f1);
}

template <class Gfx>
void CpuGfxT<Gfx>::Uniform3f(int idx, float f0, float f1, float f2) {
	auto& prog = Local().prog;
	ASSERT(prog)
	if (prog) prog->SetVar(idx, f0, f1, f2);
}

template <class Gfx>
void CpuGfxT<Gfx>::Uniform4f(int idx, float f0, float f1, float f2, float f3) {
	auto& prog = Local().prog;
	ASSERT(prog)
	if (prog) prog->SetVar(idx, f0, f1, f2, f3);
}

template <class Gfx>
void CpuGfxT<Gfx>::UniformMatrix4fv(int idx, const mat4& mat) {
	auto& prog = Local().prog;
	ASSERT(prog)
	if (prog) prog->SetVar(idx, mat);
}

template <class Gfx>
bool CpuGfxT<Gfx>::CreateShader(GVar::ShaderType t, NativeShaderRef& new_shdr) {
	new_shdr = new SoftShaderT<Gfx>();
	new_shdr->SetType(t);
	return true;
}

template <class Gfx>
void CpuGfxT<Gfx>::ShaderSource(NativeShaderRef s, String code) {
	s->SetSource(code);
}

template <class Gfx>
bool CpuGfxT<Gfx>::CompileShader(NativeShaderRef s) {
	/*ASSERT(ctx && rt && shdr);
	if (!ctx || !rt || !shdr)
		return false;
	
	if (comp.IsEmpty())
		comp.Create();
	
	return comp->Compile(*ctx, *rt, *shdr, s, s->GetType();*/
	return Local().comp.Compile(*s);
}

template <class Gfx>
String CpuGfxT<Gfx>::GetLastErrorS(NativeShaderRef s) {
	return s->GetLastError();
}

template <class Gfx>
String CpuGfxT<Gfx>::GetLastErrorP(NativeProgram& p) {
	return p.GetLastError();
}

template <class Gfx>
bool CpuGfxT<Gfx>::CreateProgram(NativeProgram& prog) {
	return prog.Create();
}

template <class Gfx>
void CpuGfxT<Gfx>::ProgramParameteri(NativeProgram& prog, GVar::ParamType type, int i) {
	prog.SetParameter(type, i);
}

template <class Gfx>
bool CpuGfxT<Gfx>::LinkProgram(NativeProgram& prog) {
	return prog.LinkProgram();
}

template <class Gfx>
void CpuGfxT<Gfx>::GetProgramiv(NativeProgram& prog, GVar::ProgParamType type, int& out) {
	out = prog.GetParamInt(type);
}

template <class Gfx>
String CpuGfxT<Gfx>::GetActiveUniform(NativeProgram& prog, int i, int* size_out, int* type_out) {
	if (size_out)
		*size_out = prog.GetVarSize(i);
	if (type_out)
		*type_out = prog.GetVarType(i);
	
	return prog.GetVar(i);
}

template <class Gfx>
void CpuGfxT<Gfx>::Clear(GVar::BufferType type) {
	auto& fb = Local().fb;
	ASSERT(fb);
	if (fb)
		fb->ClearData(type);
}

template <class Gfx>
void CpuGfxT<Gfx>::AttachShader(NativeProgram& prog, NativeShaderRef shdr) {
	prog.Attach(*shdr);
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteShader(NativeShaderRef& shdr) {
	shdr->Clear();
	shdr = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::GenProgramPipeline(NativePipeline& pipe) {
	pipe.Create();
}

template <class Gfx>
void CpuGfxT<Gfx>::UseProgramStages(NativePipeline& pipe, uint32 bmask, NativeProgram& prog) {
	pipe.Use(prog, bmask);
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteProgramPipeline(NativePipeline& pipe) {
	pipe.Clear();
}

template <class Gfx>
void CpuGfxT<Gfx>::TexParameteri(GVar::TextureType type, GVar::Filter filter, GVar::Wrap repeat) {
	auto& fb = Local().fb;
	ASSERT(fb);
	if (fb)
		fb->SetParam(type, filter, repeat);
	/*if (Local().active_texture >= 0) {
		auto& t = Local().T();
		if (t.rw)
			t.rw->SetParam(type, filter, repeat);
	}*/
}

template <class Gfx>
void CpuGfxT<Gfx>::BindFramebuffer(NativeFrameBufferRef fb) {
	auto& l = Local();
	ASSERT_(!l.fb || (l.ctx_default_fb && l.fb == l.ctx_default_fb), "previous frambuffer have not been unbound");
	l.fb = fb;
}

template <class Gfx>
void CpuGfxT<Gfx>::BindTextureRO(GVar::TextureType type, NativeColorBufferConstRef tex) {
	auto& t = Local().T();
	t.r = tex;
	t.rw = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::BindTextureRW(GVar::TextureType type, NativeColorBufferRef tex) {
	auto& t = Local().T();
	t.r = 0;
	t.rw = tex;
}

template <class Gfx>
void CpuGfxT<Gfx>::UnbindTexture(GVar::TextureType type) {
	auto& t = Local().T();
	t.r = 0;
	t.rw = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::GenerateMipmap(GVar::TextureType type) {
	// not supported
}

template <class Gfx>
void CpuGfxT<Gfx>::BindFramebufferDefault() {
	Local().fb = Local().ctx_default_fb;
}

template <class Gfx>
void CpuGfxT<Gfx>::RenderScreenRect() {
	auto& l = Local();
	ASSERT_(l.fb, "framebuffer is not bound yet");
	//ASSERT_(l.shdr, "shader is not bound yet");
	//ASSERT_(l.prog, "program is not bound yet");
	ASSERT_(l.pipe, "pipe is not bound yet");
	ASSERT_(*l.pipe, "pipeline is not inited");
	
	l.rend.SetTarget(*l.pipe, *l.fb);
	l.rend.RenderScreenRect();
}

template <class Gfx>
bool CpuGfxT<Gfx>::GenTexture(NativeColorBufferRef& b) {
	ASSERT(!b);
	b = new ByteImage();
	return true;
}

template <class Gfx>
void CpuGfxT<Gfx>::SetContextDefaultFramebuffer(NativeFrameBufferRef fb) {
	auto& l = Local();
	l.ctx_default_fb = fb;
	if (!l.fb)
		l.fb = fb;
}

template <class Gfx>
void CpuGfxT<Gfx>::GenVertexArray(NativeVertexArray& va) {
	va.Create();
}

template <class Gfx>
void CpuGfxT<Gfx>::GenVertexBuffer(NativeVertexBuffer& vb) {
	vb.Create();
}

template <class Gfx>
void CpuGfxT<Gfx>::GenElementBuffer(NativeElementBuffer& eb) {
	eb.Create();
}

template <class Gfx>
void CpuGfxT<Gfx>::BindVertexArray(NativeVertexArray& vao) {
	Local().vao = &vao;
}

template <class Gfx>
void CpuGfxT<Gfx>::BindVertexBuffer(NativeVertexBuffer& vbo) {
	auto& l = Local();
	ASSERT(l.vao);
	l.vao->vbo = &vbo;
}

template <class Gfx>
void CpuGfxT<Gfx>::VertexBufferData(const Vector<Vertex>& vtx) {
	auto& l = Local();
	ASSERT(l.vao);
	ASSERT(l.vao->vbo);
	l.vao->vbo->vertices <<= vtx;
}

template <class Gfx>
void CpuGfxT<Gfx>::BindElementBuffer(NativeElementBuffer& ebo) {
	auto& l = Local();
	ASSERT(l.vao);
	l.vao->ebo = &ebo;
}

template <class Gfx>
void CpuGfxT<Gfx>::ElementBufferData(const Vector<uint32>& el) {
	auto& l = Local();
	ASSERT(l.vao);
	ASSERT(l.vao->ebo);
	l.vao->ebo->indices <<= el;
}

template <class Gfx>
void CpuGfxT<Gfx>::UnbindVertexArray() {
	Local().vao = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::UnbindVertexBuffer() {
	auto& l = Local();
	ASSERT(l.vao);
	l.vao->vbo = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::UnbindElementBuffer() {
	auto& l = Local();
	ASSERT(l.vao);
	l.vao->ebo = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::DrawVertexElements(int element_limit) {
	auto& l = Local();
	ASSERT(l.vao);
	ASSERT(l.vao->vbo);
	ASSERT(l.vao->ebo);
	ASSERT_(l.fb, "framebuffer is not bound yet");
	ASSERT_(l.pipe, "pipe is not bound yet");
	ASSERT_(*l.pipe, "pipeline is not inited");
	
	for(int i = 0; i < TEXTYPE_COUNT; i++)
		l.rend.BindTexture(i, l.texture[i].GetReadTexture());
	
	l.rend.Render(*l.vao);
}

template <class Gfx>
void CpuGfxT<Gfx>::TexImage2D(ByteImage& tex) {
	auto& t = Local().T();
	ASSERT(!t.r);
	ASSERT(t.rw);
	*t.rw = tex;
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteVertexArray(NativeVertexArray& vao) {
	vao.Clear();
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteVertexBuffer(NativeVertexBuffer& vbo) {
	vbo.Clear();
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteElementBuffer(NativeElementBuffer& ebo) {
	ebo.Clear();
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteTexture(NativeColorBufferRef& b) {
	ASSERT(b);
	if (b) {
		delete b;
		b = 0;
	}
	//b.Clear();
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteRenderbuffer(NativeDepthBufferRef& b) {
	ASSERT(b);
	if (b) {
		delete b;
		b = 0;
	}
	//b.Clear();
}

template <class Gfx>
void CpuGfxT<Gfx>::DeleteFramebuffer(NativeFrameBufferRef& b) {
	ASSERT(b);
	if (b)
		delete b;
	b = 0;
}

template <class Gfx>
void CpuGfxT<Gfx>::DeactivateVertexStructure() {
	// pass
}

template <class Gfx>
void CpuGfxT<Gfx>::BeginRender() {
	auto& l = Local();
	ASSERT_(l.fb, "framebuffer is not bound yet");
	ASSERT_(l.pipe, "pipe is not bound yet");
	ASSERT_(*l.pipe, "pipeline is not inited");
	
	/*GVar::RenderTarget tgt = l.rend.GetTargets();
	ASSERT(tgt);
	l.rend.ClearBuffers();
	for(int i = 0; i < CHANNEL_COUNT; i++) {
		uint32 j = 1 << i;
		if ((uint32)tgt & j) {
			auto rw = l.texture[i].rw;
			ASSERT(rw);
			if (rw)
				l.rend.AddBuffer(*rw);
		}
	}
	*/
	l.rend.SetTarget(*l.pipe, *l.fb);
	//l.rend.SetPipeline(*l.pipe);
	l.rend.Begin();
}

template <class Gfx>
void CpuGfxT<Gfx>::EndRender() {
	auto& l = Local();
	l.rend.End();
}

template <class Gfx> void CpuGfxT<Gfx>::SetupVertexStructure() {}
template <class Gfx> void CpuGfxT<Gfx>::ActivateVertexStructure() {}

template <class Gfx> bool CpuGfxT<Gfx>::CreateRenderbuffer(NativeDepthBufferRef& b) {
	ASSERT(!b);
	b = new DepthImage();
	return true;
}

template <class Gfx> void CpuGfxT<Gfx>::BindRenderbuffer(NativeDepthBufferRef rb) {
	Local().depth = rb;
}

template <class Gfx> void CpuGfxT<Gfx>::RenderbufferStorage(Size sz) {
	auto& depth = Local().depth;
	ASSERT(depth);
	if (depth)
		depth->Set(sz, 1);
}

template <class Gfx> void CpuGfxT<Gfx>::UnbindRenderbuffer() {
	Local().depth = 0;
}

template <class Gfx> bool CpuGfxT<Gfx>::CreateFramebuffer(NativeFrameBufferRef& fb) {
	fb = new SoftFramebuffer;
	return true;
}

template <class Gfx> void CpuGfxT<Gfx>::FramebufferTexture2D(TexType tgt, NativeColorBufferRef tex) {
	auto& fb = Local().fb;
	ASSERT(fb);
	ASSERT(tex);
	if (fb && tex)
		fb->SetColor(tgt, tex);
}

template <class Gfx> void CpuGfxT<Gfx>::FramebufferRenderbuffer(NativeDepthBufferRef depth) {
	auto& fb = Local().fb;
	ASSERT(fb);
	ASSERT(depth);
	if (fb && depth)
		fb->SetDepth(depth);
}

template <class Gfx> void CpuGfxT<Gfx>::UnbindFramebuffer() {
	Local().fb = 0;
}

#if defined flagSDL2
template struct CpuGfxT<SdlCpuGfx>;
#endif

template struct CpuGfxT<X11SwGfx>;


NAMESPACE_PARALLEL_END
