#ifndef _Multimedia_ECS_OpenCV_h_
#define _Multimedia_ECS_OpenCV_h_

#if HAVE_OPENCV

NAMESPACE_OULU_BEGIN


class OpenCVComponent :
	public Component<OpenCVComponent>,
	public AudioSource,
	public VideoSource
{
	String last_error;
	OpenCVCaptureDevice cap;
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
	
	bool LoadFileAny(String path) override;
	
	bool LoadInput(int id);
	
	String GetLastError() const {return last_error;}
	
	MediaStreamThread& GetInput() {return vi;}
	
	
	static bool AllowDuplicates() {return true;}
	
	
	// Audio
	AudioStream&	GetAudioSource() override;
	void			BeginAudioSource() override;
	void			EndAudioSource(bool any_sink_consumed) override;
	
	// Video
	VideoStream&	GetVideoSource() override;
	void			BeginVideoSource() override;
	void			EndVideoSource(bool any_sink_consumed) override;
	
};


NAMESPACE_OULU_END

#endif
#endif
