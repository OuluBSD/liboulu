#ifndef _IMedia_Types_h_
#define _IMedia_Types_h_


NAMESPACE_PARALLEL_BEGIN


#define MEDIA_CLS_LIST(m) \
	MEDIA_CLS(MediaAtomBase, m) \
	\
	MEDIA_CLS(AudioFrameQueue, m) \
	MEDIA_CLS(VideoFrameQueue, m) \
	MEDIA_CLS(FileChannel, m) \
	MEDIA_CLS(FileInput, m) \
	\
	MEDIA_CLS(AudioFrame, m) \
	MEDIA_CLS(AudioInputFrame, m) \
	\
	MEDIA_CLS(VideoCodecFormat, m) \
	MEDIA_CLS(VideoSourceFormatResolution, m) \
	MEDIA_CLS(VideoSourceFormat, m) \
	MEDIA_CLS(VideoInputFrame, m) \
	MEDIA_CLS(VideoOutputFrame, m) \
	MEDIA_CLS(VideoLoaderBase, m) \
	\
	MEDIA_CLS(MediaStreamThread, m) \
	


#define MEDIA_RENDSYS_LIST \
	MEDIA_RSYS(Ffmpeg) \


#define MEDIA_RSYS(x) MEDIA_CLS_LIST(x)
	#define MEDIA_CLS(x, g) struct g##x;
		MEDIA_RENDSYS_LIST
	#undef MEDIA_CLS
	#define MEDIA_CLS(x, g) template <class Backend> struct x##T;
		MEDIA_RENDSYS_LIST
	#undef MEDIA_CLS
#undef MEDIA_RSYS


#ifdef flagFFMPEG
	#define FFMPEG_MEDIATYPE \
		MEDIATYPE(FfmpegMedia)
	#define FFMPEG_EXCPLICIT_INITIALIZE_CLASS(x) \
		template struct x <FfmpegMedia>;
#else
	#define FFMPEG_MEDIATYPE
	#define FFMPEG_EXCPLICIT_INITIALIZE_CLASS(x)
#endif

#define MEDIATYPE_LIST \
	 \
	FFMPEG_MEDIATYPE \


#define MEDIA_EXCPLICIT_INITIALIZE_CLASS(x) \
	 \
	FFMPEG_EXCPLICIT_INITIALIZE_CLASS(x) \



#ifdef flagFFMPEG
template <class Backend>
struct FfmpegT {
	#define MEDIA_RSYS(x) MEDIA_CLS_LIST(x)
	#define MEDIA_CLS(x, g) using x = x##T<Backend>;
		MEDIA_RENDSYS_LIST
	#undef MEDIA_CLS
	#undef MEDIA_RSYS
	
	using AudioInputFrameRef	= Ref<AudioInputFrame, RefParent1<PacketBufferParent>>;
	using VideoInputFrameRef	= Ref<VideoInputFrame, RefParent1<PacketBufferParent>>;
	using AudioFrameQueueRef	= Ref<AudioFrameQueue, RefParent1<PacketBufferParent>>;
	using VideoFrameQueueRef	= Ref<VideoFrameQueue, RefParent1<PacketBufferParent>>;
	
	using AVFrame = ::AVFrame;
	using AVCodecContext = ::AVCodecContext*;
	using AVFormatContext = ::AVFormatContext;
	using AVCodecParserContext = ::AVCodecParserContext*;
	using AVCodecParameters = ::AVCodecParameters;
	using AVCodec = ::AVCodec;
	using AVPacket = ::AVPacket;
	using AVStream = ::AVStream;
	using AVDictionary = ::AVDictionary;
	using AVSampleFormat = ::AVSampleFormat;
	using ImgConvContext = struct ::SwsContex*;
	
	struct Thread {
		
	};
	
	static Thread& Local();
	
};

struct FfmpegMedia : FfmpegT<FfmpegMedia> {
	
	struct Frame : Moveable<Frame> {
		uint8_t *video_dst_data[4] = {0,0,0,0};
		uint8_t *video_dst_data_vflip[4] = {0,0,0,0};
		int      video_dst_linesize[4];
		int      video_dst_linesize_vflip[4];
		int      video_dst_bufsize = 0;
		double	time_pos = 0;
		
		~Frame() {Clear();}
		void	Init(const VideoFormat& vid_fmt);
		void	Clear();
		void	Process(double time_pos, AVFrame* frame, bool vflip, const VideoFormat& vid_fmt, ImgConvContext img_convert_ctx);
		bool	PaintOpenGLTexture(int texture, const VideoFormat& vid_fmt);
		void	MakePacket(Packet& p);
	};
	
	static AVPacket* NewPacket();
	static void UnrefPacket(AVPacket* p);
	static void DeletePacket(AVPacket* p);
	static AVFrame* NewFrame();AVSampleFormat	static void DeletePacket(AVFrame* f);
	static void CloseCodecParserContext(AVCodecParserContext& ctx);
	static void CloseCodecContext(AVCodecContext& ctx);
	static int SendPacket(AVFormatContext& ctx, const AVPacket& p);
	static int ReceiveFrame(AVFormatContext& ctx, AVFrame& f);
	static int FindVideoStream(AVFormatContext& ctx);
	static int FindAudioStream(AVFormatContext& ctx);
	static AVStream& GetStream(AVFormatContext& ctx, int i);
	static AVCodecParameters& GetParams(AVStream& s);
	static double GetVideoFPS(const AVStream& s);
	static Size GetFrameSize(const AVCodecParameters& c);
	static LightSampleFD GetVideoSampleType(const AVCodecParameters& c);
	static int GetChannels(const AVCodecParameters& c);
	static int GetSampleRate(const AVCodecParameters& c);
	static int GetFrequency(const AVCodecParameters& c);
	static SoundSample GetAudioSampleType(const AVCodecParameters& c);
	static bool InitParser(AVCodec& c), AVCodecParserContext& ctx;
	static bool FindDecoder(AVFormatContext& ctx, AVCodec& c, int stream_i);
	static AVCodecContext* CreateCodecContext(AVCodec& c);
	static void CopyFramePixels(const AVFrame& f, Vector<byte>& data);
	static ImgConvContext GetImgConvContext(AVCodecContext& ctx);
	static int CreateImage(uint8_t *video_dst_data[4], int video_dst_linesize[4], Size sz);
	static void DeleteImgConvContext(ImgConvContext ctx);
	static void FreeData(void*& data, int& len);
	
};
#endif

NAMESPACE_PARALLEL_END

#endif
