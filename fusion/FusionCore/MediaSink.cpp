#include "FusionCore.h"

NAMESPACE_OULU_BEGIN


void FusionMediaSink::Initialize() {
	FusionComponent::Initialize();
	stream.Clear();
}

void FusionMediaSink::Uninitialize() {
	
	FusionComponent::Uninitialize();
}

void FusionMediaSink::Reset() {
	// pass
}

void FusionMediaSink::PreProcess() {
	// pass
}

void FusionMediaSink::PostProcess() {
	// pass
}

void FusionMediaSink::ClearData() {
	// pass
}

void FusionMediaSink::UpdateTexBuffers() {
	auto* stream = Stream();
	if (stream) {
		ClearTex();
		Size res;
		if (fmt.vid.res.IsEmpty())
			res = Size(fmt.snd.sample_rate, fmt.snd.channels);
		else
			res = fmt.vid.res;
		if (res.cx > 0 && res.cy > 0) {
#ifdef flagOPENGL
			Ogl_CreateTex(
				res, 4,
				0, 0,
				FusionComponentInput::FILTER_MIPMAP,
				FusionComponentInput::WRAP_CLAMP);
#endif
		}
	}
}

bool FusionMediaSink::LoadResources() {
	return true;
}

void FusionMediaSink::Event(const CtrlEvent& e) {
	TODO
}

bool FusionMediaSink::LoadAsInput(const FusionComponentInput& in) {
	const char* fn_name = "LoadAsInput";
	Entity& e = GetEntity();
	Machine& m = e.GetMachine();
	String err;
	String path = in.GetFilepath();
	
	cfg.SetHeader(in);
	stream.Clear();
	
	auto type = in.GetType();
	
	Connector* conn = GetEntity().GetConnector();
	if (!conn) {
		OnError(fn_name, "entity doesn't have Connector component");
		return false;
	}
	
	if (type != FusionComponentInput::WEBCAM && !FileExists(path)) {
		OnError(fn_name, "file does not exist: \"" + path + "\"");
		return false;
	}
	
	if (type == FusionComponentInput::VIDEO ||
		type == FusionComponentInput::WEBCAM ||
		type == FusionComponentInput::MUSIC) {
		MultiMediaComponent* comp = e.Add<MultiMediaComponent>();
		if (comp->LinkManually(*this)) {
			conn->SetUpdateInterfaces(true);
			if (path.IsEmpty() && type == FusionComponentInput::WEBCAM)
				path = "<input0>";
			if (comp->LoadFileAny(path)) {
				MultiMediaInput& in = comp->GetInput();
				fmt = comp->GetMedia().GetFormat();
				ASSERT(fmt.IsValid());
				if (fmt.vid.IsValid()) {
					stream.sz = fmt.vid.res;
					stream.depth = 0;
				}
				else {
					stream.sz = Size(fmt.snd.sample_rate, fmt.snd.channels);
					stream.depth = 0;
				}
				UpdateTexBuffers();
				DLOG("FusionMediaSink::LoadAsInput: successfully loaded " + path);
				return true;
			}
			err = comp->GetLastError();
		}
		else {
			err = "couldn't link MultiMediaComponent to FusionMediaSink";
		}
		comp->Destroy();
	}
	else if (type == FusionComponentInput::MUSICSTREAM) {
		TODO
	}
	else {
		err = "unsupported type";
	}
	
	
	if (err.IsEmpty()) err = "unknown error";
	OnError(fn_name, err);
	return false;
}

void FusionMediaSink::RecvMedia(Media& media) {
	MediaFormat fmt = media.GetFormat();
	
	if (fmt != this->fmt) {
		this->fmt = fmt;
		UpdateTexBuffers();
	}
	
#ifdef flagOPENGL
	GLuint tex = Ogl_GetTex();
	if (tex > 0) {
		if (fmt.vid.IsValid()) {
			if (fmt.snd.IsValid()) {
				TODO
			}
			else {
				if (!media.GetVideo().PaintOpenGLTexture(tex)) {
					OnError("RecvMedia", "painting opengl tex failed");
					ClearTex();
				}
			}
		}
		else if (fmt.snd.IsValid()) {
			if (!media.GetSound().PaintOpenGLTexture(tex)) {
				OnError("RecvMedia", "painting opengl tex failed");
				ClearTex();
			}
		}
	}
#else
	TODO
#endif
}


NAMESPACE_OULU_END
