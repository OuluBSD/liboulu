#include "EcsCore.h"


NAMESPACE_TOPSIDE_BEGIN

Callback VideoSystem::WhenUninit;

bool VideoSystem::Initialize() {
	
	
	return true;
}

void VideoSystem::Start() {
	ents = GetMachine().Get<EntityStore>();
}

void VideoSystem::Update(double dt) {

	for (VideoSourceRef src : srcs) {
		VideoStream& stream = src->GetVideoSource();
		bool buffer_full = stream.GetVideoBufferSize() >= 2;
		
		src->Update(dt, buffer_full);
		if (src->Cfg().render)
			src->BeginVideoSource();
	}
	
	for (VideoExchangePointRef expt : expts) {
		VideoSourceRef src = expt->Source();
		
		expt->Update(dt);
		TODO
		//if (expt->AnySinkConsumed())
		//	src->SetConsumed();
	}
	
	for (VideoSourceRef src :srcs) {
		const auto& cfg = src->Cfg();
		TODO
		//if (cfg.exchanged)
		//	src->EndVideoSource(1);
	}
	
}

void VideoSystem::Stop() {
	
	
}

void VideoSystem::Uninitialize() {
	
	WhenUninit();
}

void VideoSystem::Add(VideoSourceRef src) {
	srcs.FindAdd(src);
}

void VideoSystem::Remove(VideoSourceRef src) {
	srcs.RemoveKey(src);
}

void VideoSystem::Add(VideoSinkRef sink) {
	sinks.FindAdd(sink);
}

void VideoSystem::Remove(VideoSinkRef sink) {
	sinks.RemoveKey(sink);
}

void VideoSystem::Add(VideoExchangePointRef expt) {
	expts.FindAdd(expt);
}

void VideoSystem::Remove(VideoExchangePointRef expt) {
	expts.RemoveKey(expt);
}








NAMESPACE_TOPSIDE_END
