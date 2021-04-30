#include "EcsLib.h"


NAMESPACE_OULU_BEGIN


bool AudioSystem::Initialize() {
	
	
	return true;
}

void AudioSystem::Start() {
	ents = GetMachine().Get<EntityStore>();
}

void AudioSystem::Update(double dt) {
	for(AudioSource* aud : audios) {
		aud->EmitAudioSource(dt);
	}
}

void AudioSystem::Stop() {
	
	
}

void AudioSystem::Uninitialize() {
	
	
}

void AudioSystem::Add(AudioSource* src) {
	VectorFindAdd(audios, src);
}

void AudioSystem::Remove(AudioSource* src) {
	VectorRemoveKey(audios, src);
}


NAMESPACE_OULU_END
