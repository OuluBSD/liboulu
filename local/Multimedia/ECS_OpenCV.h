#ifndef _Multimedia_ECS_OpenCV_h_
#define _Multimedia_ECS_OpenCV_h_

#if HAVE_OPENCV

NAMESPACE_OULU_BEGIN


class OpenCVComponent :
	public Component<OpenCVComponent>,
	public AudioSource,
	public VideoSource
{
	VIS_COMP_2_0(Audio, Video)
	
	OpenCVCaptureDevice cap;
	
	String last_error;
	V4L2_DeviceManager devmgr;
	MediaStreamThread vi;
	VideoProxy video_buf;
	AudioProxy audio_buf;
	Size def_cap_sz;
	int def_cap_fps;
	
public:
	COPY_PANIC(OpenCVComponent);
	IFACE_CB(AudioSource);
	IFACE_CB(VideoSource);
	IFACE_GENERIC;
	
	OpenCVComponent();
	
	void Initialize() override;
	void Uninitialize() override;
	void Visit(RuntimeVisitor& vis) override {vis % cap;}
	
	bool LoadFileAny(String path) override;
	
	bool LoadInput(int id);
	
	String GetLastError() const {return last_error;}
	
	MediaStreamThread& GetInput() {return vi;}
	
	
	static bool AllowDuplicates() {return true;}
	
	
	// Audio
	AudioStream&	GetAudioSource() override;
	void			BeginAudioSource() override;
	void			EndAudioSource() override;
	
	// Video
	VideoStream&	GetVideoSource() override;
	void			BeginVideoSource() override;
	void			EndVideoSource(bool any_sink_consumed) override;
	
};


NAMESPACE_OULU_END

#endif
#endif
