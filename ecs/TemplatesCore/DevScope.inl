NAMESPACE_TOPSIDE_BEGIN



template <class DevSpec>
template <class ValSpec>
typename ScopeValMachT<ValSpec>::Format
ScopeDevCoreT<DevSpec>::GetDefaultFormat() {
	typename ScopeValMachT<ValSpec>::Format fmt;
	fmt.template SetDefault<DevSpec>();
	return fmt;
}


#define DEV(x) \
template <> template <> inline \
typename ScopeValMachT<AudioSpec>::Format \
ScopeDevCoreT<x##Spec>::GetDefaultFormat<AudioSpec>() { \
	typename ScopeValMachT<AudioSpec>::Format fmt; \
	fmt.Set<x##Spec>(SoundSample::S16_LE, 2, 44100, 1024); \
	return fmt; \
} \
template <> template <> inline \
typename ScopeValMachT<VideoSpec>::Format \
ScopeDevCoreT<x##Spec>::GetDefaultFormat<VideoSpec>() { \
	typename ScopeValMachT<VideoSpec>::Format fmt; \
	fmt.Set<x##Spec>(LightSampleFD::U8_LE_ABCD, Size(640, 480), 60, 1); \
	return fmt; \
}
DEV(Center)
DEV(Net)
DEV(Perma)
#undef DEV


NAMESPACE_TOPSIDE_END
