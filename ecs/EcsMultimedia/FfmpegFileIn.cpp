#include "EcsMultimedia.h"


#if HAVE_FFMPEG

NAMESPACE_TOPSIDE_BEGIN


FfmpegFileInput::FfmpegFileInput() :
	astream(this)
{
	
}

void FfmpegFileInput::Clear() {
	ClearDevice();
	
	has_audio = false;
	has_video = false;
	is_dev_open = false;
	path.Clear();
	errstr.Clear();
	
}

void FfmpegFileInput::ClearDevice() {
	is_eof = true;
	is_dev_open = 0;
	aframe.Clear();
	vframe.Clear();
	
	ClearPacket();
}

void FfmpegFileInput::InitPacket() {
	ClearPacket();
	pkt = av_packet_alloc();
    pkt->data = NULL;
    pkt->size = 0;
}

void FfmpegFileInput::ClearPacketData() {
	if (pkt_ref) {
		av_packet_unref(pkt);
		pkt_ref = false;
	}
    pkt->data = NULL;
    pkt->size = 0;
}

void FfmpegFileInput::ClearPacket() {
	if (pkt) {
		ClearPacketData();
		av_packet_free(&pkt);
		pkt = 0;
	}
	else {
		ASSERT(!pkt_ref);
	}
}

bool FfmpegFileInput::IsOpen() const {
	return is_dev_open;
}

bool FfmpegFileInput::OpenFile(String path) {
	Clear();
	
	this->path = path;
	
	// Open video file
	if(avformat_open_input(&file_fmt_ctx, path.Begin(), NULL, NULL) != 0) {
		errstr = "couldn't open file: " + path;
		return false;
	}
	
	// Retrieve stream information
	if(avformat_find_stream_info(file_fmt_ctx, NULL)<0) {
		errstr = "couldn't find stream information";
		return false;
	}
	
	// Dump information about file onto standard error
	av_dump_format(file_fmt_ctx, 0, path.Begin(), 0);
	
	// Find the first video stream
	has_audio = a.OpenAudio(file_fmt_ctx, aframe.fmt);
	has_video = v.OpenVideo(file_fmt_ctx, vframe.vid_fmt);
	
	if (has_audio) {
		aframe.Clear();
	}
	if (has_video) {
		vframe.Init(*v.codec_ctx);
	}
	
	return HasMediaOpen();
}

bool FfmpegFileInput::Open() {
	ClearDevice();
	
	if (!HasMediaOpen())
		return false;
	
	bool audio_open = has_audio ? a.OpenDevice() : false;
	bool video_open = has_video ? v.OpenDevice() : false;
	
	InitPacket();
    
	is_dev_open = audio_open || video_open;
	is_eof = !is_dev_open;
	return is_dev_open;
}

void FfmpegFileInput::Close() {
	Clear();
}

AudioStream& FfmpegFileInput::GetAudioStream() {
	return astream;
}

VideoStream& FfmpegFileInput::GetVideoStream() {
	TODO
}

void FfmpegFileInput::FillVideoBuffer() {
	while (!vframe.IsQueueFull() && !IsEof()) {
		if (ReadFrame()) {
			if (ProcessVideoFrame())
				continue;
			if (ProcessAudioFrame())
				continue;
		}
		else break;
	}
}

/*void FfmpegFileInput::FillAudioBuffer() {
	while (!aframe.IsQueueFull() && !IsEof()) {
		if (ReadFrame()) {
			if (ProcessVideoFrame())
				continue;
			if (ProcessAudioFrame())
				continue;
			
			ClearPacketData();
		}
		else break;
	}
	
	if (IsEof())
		FillBuffersNull();
	
	ClearPacketData();
}*/

bool FfmpegFileInput::ReadFrame() {
	ClearPacketData();
	
	ASSERT(!pkt->data && !pkt->size);
	if (av_read_frame(file_fmt_ctx, pkt) >= 0) {
		pkt_ref = true;
		is_eof = false;
		return true;
	}
	
	if (!is_eof) {
		RTLOG("FfmpegFileInput::ReadFrame: end of file");
		is_eof = true;
		WhenStopped();
	}
	
	return false;
}

bool FfmpegFileInput::ProcessVideoFrame() {
	ASSERT(pkt && pkt_ref);
	if (v.ReadFrame(*pkt)) {
		vframe.Process(v.frame_pos_time, v.frame);
		av_frame_free(&v.frame);
		ClearPacketData();
		return true;
	}
	
	return false;
}

bool FfmpegFileInput::ProcessAudioFrame() {
	ASSERT(pkt && pkt_ref);
	if (a.ReadFrame(*pkt)) {
		aframe.FillAudioBuffer(a.frame_pos_time, a.frame);
		av_frame_free(&a.frame);
		ClearPacketData();
		return true;
	}
	
	return false;
}

void FfmpegFileInput::FillBuffersNull() {
	if (has_audio)
		aframe.FillBuffersNull();
	if (has_video)
		vframe.FillBuffersNull();
}

void FfmpegFileInput::DropVideoFrames(int frames) {
	TODO
	/*frames = std::min(frames, vframe.GetQueueSize() / vframe.GetFormat(VidCtx).GetFrameBytes());
	
	if (frames)
		vframe.DropFrames(frames);*/
}

Audio& FfmpegFileInput::GetAudio() {
	return aframe;
}

Video& FfmpegFileInput::GetVideo() {
	return vframe;
}

String FfmpegFileInput::GetLastError() const {
	return errstr;
}

String FfmpegFileInput::GetPath() const {
	return path;
}

double FfmpegFileInput::GetSeconds() const {
	if (a.IsOpen())
		return a.GetSeconds();
	if (v.IsOpen())
		return v.GetSeconds();
	return 0;
}

bool FfmpegFileInput::IsEof() const {
	return is_eof;
}




bool FfmpegFileInput::LocalAudioStream::IsOpen() const {
	return par.is_dev_open && par.has_audio;
}

bool FfmpegFileInput::LocalAudioStream::Open(int fmt_idx) {
	ASSERT(!fmt_idx);
	if (par.is_dev_open)
		return par.has_audio;
	if (par.Open())
		return par.has_audio;
	return false;
}












int FfmpegFileChannel::DecodePacket(AVPacket& pkt, int *got_frame) {
    int ret = 0;
    int decoded = pkt.size;
    *got_frame = 0;
        
    // Decode frame
    ret = avcodec_send_packet(codec_ctx, &pkt);
    if (ret == AVERROR_EOF) {
        is_open = false;
        errstr = "Eof in packet decoding";
        return -1;
    }
    else if (ret != 0) {
        errstr = "Failed to decode packet";
        return -1;
    }
    
    // Receive frame
    if (!frame)
		frame = av_frame_alloc();
    ret = avcodec_receive_frame(codec_ctx, frame);
    if (ret == AVERROR_EOF) {
        is_open = false;
        errstr = "Eof in frame decoding";
        return -1;
    }
    else if (ret != 0) {
        errstr = "Error decoding frame";
        return -1;
    }
    else {
        *got_frame = 1;
        
		double frame_time = (double)codec_ctx->time_base.num / (double)codec_ctx->time_base.den;
		if (codec_ctx->time_base.num == 0)
			frame_time = 1.0 / 1000.0;
		frame_pos_time = frame->pts * frame_time;
    }
    
    return decoded;
}

void FfmpegFileChannel::Clear() {
	if (frame)
		av_frame_free(&frame);
	frame = 0;
	
	if (parser)
		av_parser_close(parser);
	parser = NULL;
	
	if (codec_ctx)
		avcodec_free_context(&codec_ctx);
	codec_ctx = NULL;
	
	stream_i = -1;
	codec = NULL;
	
	is_open = false;
}

void FfmpegFileChannel::ClearDevice() {
	codec = NULL;
	frame_pos_time = 0;
}

bool FfmpegFileChannel::OpenVideo(AVFormatContext* file_fmt_ctx, VideoFormat& fmt) {
	Clear();
	fmt.Clear();
	
	this->file_fmt_ctx = file_fmt_ctx;
	
	stream_i = -1;
	for (int i = 0; i < file_fmt_ctx->nb_streams; i++) {
		if (file_fmt_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO && stream_i < 0) {
			stream_i = i;
		}
	}
	if (stream_i == -1) {
		errstr = "did not find video stream";
		return false;
	}
	
	AVStream* vstream = file_fmt_ctx->streams[stream_i];
	AVCodecParameters* vcodec = vstream->codecpar;
	
	double fps = (double)vstream->avg_frame_rate.num / (double)vstream->avg_frame_rate.den;
	Size frame_sz(vcodec->width, vcodec->height);
	
	fmt.res = frame_sz;
	fmt.SetFPS(fps);
	
	#if FFMPEG_VIDEOFRAME_RGBA_CONVERSION
	fmt.SetType(LightSampleFD::S_RGBA_U8_LE);
	#else
	switch (vcodec->format) {
	case AV_PIX_FMT_RGB24:
		fmt.SetType(LightSampleFD::S_RGB_U8_LE);
		break;
	case AV_PIX_FMT_RGBA:
		fmt.SetType(LightSampleFD::S_RGBA_U8_LE);
		break;
	case AV_PIX_FMT_VAAPI:
		errstr = "VAAPI support unimplemented";
		return false;
	default:
		errstr = "unsupported video pixel format";
		return false;
	}
	#endif
	
	fmt.SetLinePadding(0); // unknown at this point. Only AVFrame can tell
	
	is_open = true;
	return true;
}

bool FfmpegFileChannel::OpenAudio(AVFormatContext* file_fmt_ctx, AudioFormat& fmt) {
	Clear();
	fmt.Clear();
	
	this->file_fmt_ctx = file_fmt_ctx;
	
	stream_i = -1;
	for (int i = 0; i < file_fmt_ctx->nb_streams; i++) {
		if (file_fmt_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO && stream_i < 0) {
			stream_i = i;
		}
	}
	if (stream_i == -1) {
		errstr = "did not find audio stream";
		return false;
	}
	
	AVStream* astream = file_fmt_ctx->streams[stream_i];
	AVCodecParameters* acodec = astream->codecpar;
	
	fmt.Clear();
	fmt.channels = acodec->channels;
	fmt.freq = acodec->sample_rate;
	fmt.sample_rate = acodec->frame_size;
	
	switch (acodec->format) {
		#define SET_FMT(f, t) \
		case f: \
			fmt.SetType(SoundSample::t); \
			break;
			
		#if CPU_LITTLE_ENDIAN
		SET_FMT(AV_SAMPLE_FMT_U8, S_U8_LE);
		SET_FMT(AV_SAMPLE_FMT_S16, S_S16_LE);
		SET_FMT(AV_SAMPLE_FMT_S32, S_S32_LE);
		SET_FMT(AV_SAMPLE_FMT_FLT, S_FLT_LE);
		SET_FMT(AV_SAMPLE_FMT_DBL, S_DBL_LE);
		
		SET_FMT(AV_SAMPLE_FMT_U8P, S_U8_LE);
		SET_FMT(AV_SAMPLE_FMT_S16P, S_S16_LE);
		SET_FMT(AV_SAMPLE_FMT_S32P, S_S32_LE);
	    SET_FMT(AV_SAMPLE_FMT_FLTP, S_FLT_LE);
	    SET_FMT(AV_SAMPLE_FMT_DBLP, S_DBL_LE);
	    #else
	    #error TODO
	    #endif
	    
		//SET_FMT(AV_SAMPLE_FMT_S64, 8, 0, 1, 0);
		//SET_FMT(AV_SAMPLE_FMT_S64P, 8, 0, 1, 0);
		
		default:
		errstr = "unexpected audio format";
		return false;
	}
	
	is_open = true;
	return true;
}

bool FfmpegFileChannel::OpenDevice() {
	if (!is_open)
		return false;
	
	// Find the decoder for the stream
	codec = avcodec_find_decoder(file_fmt_ctx->streams[stream_i]->codecpar->codec_id);
	if (codec == NULL) {
		errstr = "unsupported codec";
		is_open = false;
		return false;
	}
	
	parser = av_parser_init(codec->id);
	if (!parser) {
		// codecs like AV_CODEC_ID_PCM_F32LE doesn't require parser...
		if (codec->id >= AV_CODEC_ID_PCM_S16LE &&
			codec->id <  AV_CODEC_ID_ADPCM_IMA_QT) {
			// pass
		}
		else {
			errstr = "parser not found";
			is_open = false;
			return false;
		}
	}

    frame = av_frame_alloc();
    
	codec_ctx = avcodec_alloc_context3(codec);
	
	// Copy context
	avcodec_parameters_to_context(codec_ctx, file_fmt_ctx->streams[stream_i]->codecpar);
	
	// Open codec
	AVDictionary* opts = NULL;
	if (avcodec_open2(codec_ctx, codec, &opts) < 0) {
		errstr = "could not open codec";
		is_open = false;
		return false; // Could not open codec
	}
	
	return true;
}

bool FfmpegFileChannel::ReadFrame(AVPacket& pkt) {
    if (pkt.stream_index != stream_i)
        return false;
    
	int got_frame = 0;
	do {
		int ret = DecodePacket(pkt, &got_frame);
		if (ret < 0)
			break;
		pkt.data += ret;
		pkt.size -= ret;
		if (got_frame)
			return true;
	}
	while (pkt.size > 0);
	
	return false;
}













void FfmpegAudioFrameQueue::FillAudioBuffer(double time_pos, AVFrame* frame) {
	// Sometimes you get the sample rate at this point
	if (!fmt.sample_rate)
		fmt.sample_rate = frame->nb_samples;
	//breaks in the end of file: ASSERT(fmt.sample_rate == frame->nb_samples);
	ASSERT(fmt.IsValid());
	int var_size = av_get_bytes_per_sample((AVSampleFormat)frame->format);
	
	#ifdef flagDEBUG
	bool is_var_float =
		frame->format == AV_SAMPLE_FMT_FLT ||
		frame->format == AV_SAMPLE_FMT_DBL ||
		frame->format == AV_SAMPLE_FMT_FLTP ||
		frame->format == AV_SAMPLE_FMT_DBLP;
	ASSERT(fmt.IsValid());
	ASSERT(frame->sample_rate == fmt.freq);
	ASSERT(frame->channels == fmt.channels);
	ASSERT(var_size == fmt.GetSampleSize());
	#endif
	
	int frame_sz = frame->nb_samples * frame->channels * var_size;
	
	// Non-planar data
	if (frame->data[1] == 0) {
		if (frame->data[0]) {
			ASSERT(fmt.GetFrameSize() >= frame->linesize[0]);
			auto& p = buf.Add();
			p = CreateAudioPacket();
			RTLOG("FfmpegAudioFrameQueue::FillAudioBuffer: rendering packet " << IntStr64(frame_counter));
			off32 offset{frame_counter++};
			p->Set(fmt, offset, time_pos);
			Vector<byte>& data = p->Data();
			data.SetCount(frame->linesize[0], 0);
			memcpy(data.begin(), frame->data[0], frame->linesize[0]);
		}
	}
	// Planar data
	else {
		byte* srcn[AV_NUM_DATA_POINTERS];
		memset(srcn, 0, sizeof(srcn));
		auto& p = buf.Add();
		p = CreateAudioPacket();
		RTLOG("FfmpegAudioFrameQueue::FillAudioBuffer: rendering packet " << IntStr64(frame_counter));
		off32 offset{frame_counter++};
		p->Set(fmt, offset, time_pos);
		
		if (0) {
			LOG("frame-sz:     " << frame_sz);
			LOG("fmt:          " << fmt.ToString());
			LOG("f-nb-samples: " << frame->nb_samples);
			LOG("f-channels:   " << frame->channels);
			__BREAK__
		}
		
		Vector<byte>& data = p->Data();
		data.SetCount(frame_sz, 0);
		byte* dst = data.Begin();
		
		for(int i = 0; i < frame->channels; i++)
			srcn[i] = frame->data[i];
		
		for (int i = 0; i < frame->nb_samples; i++) {
			for(int j = 0; j < frame->channels; j++) {
				byte*& src = srcn[j];
				for(int k = 0; k < var_size; k++)
					*dst++ = *src++;
			}
		}
		ASSERT(dst == data.End());
	}
	
	exchange_count = 0;
}



#if HAVE_OPENGL

#if 0
bool FfmpegAudioFrameQueue::PaintOpenGLTexture(int texture) {
	if (buf.IsEmpty())
		return false;
	TODO
	/*auto frame_iter = buf.begin();
	Frame& f = *frame_iter();
	
	int var_size = av_get_bytes_per_sample(f.frame->format);
	ASSERT(f.frame->nb_samples == fmt.sample_rate);
	ASSERT(f.frame->sample_rate == fmt.freq);
	ASSERT(f.frame->channels == fmt.channels);
	ASSERT(var_size == fmt.var_size);
	
	glBindTexture (GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	Size res(fmt.sample_rate, fmt.channels);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R32F,
		res.cx,
		res.cy,
		0, GL_RED, GetOglDataType(fmt.var_size, fmt.is_var_float),
		f.frame->data[0]);
	
	av_frame_free(&f.frame);
	buf.Remove(frame_iter);*/
	return true;
}
#endif

#endif

















void FfmpegVideoFrameQueue::Init(AVCodecContext& ctx) {
	Clear();
	ASSERT(vid_fmt.IsValid());
	
	Size sz = vid_fmt.res;
	
	img_convert_ctx =
		sws_getContext(
		sz.cx, sz.cy, ctx.pix_fmt,
		sz.cx, sz.cy, AV_PIX_FMT_RGBA,
		SWS_FAST_BILINEAR, NULL, NULL, NULL);
		
}

void FfmpegVideoFrameQueue::Frame::Init(const VideoFormat& vid_fmt) {
	if (!video_dst_bufsize) {
		Size sz = vid_fmt.res;
		
	    video_dst_bufsize =
			av_image_alloc(	video_dst_data, video_dst_linesize,
							sz.cx, sz.cy, AV_PIX_FMT_RGBA, 1);
	}
}

void FfmpegVideoFrameQueue::FillBuffersNull() {
	TODO
}

void FfmpegVideoFrameQueue::Clear() {
	frames.Clear();
	
	if (img_convert_ctx) {
		sws_freeContext(img_convert_ctx);
		img_convert_ctx = 0;
	}
}

void FfmpegVideoFrameQueue::Frame::Clear() {
	if (video_dst_bufsize) {
		av_free(video_dst_data[0]);
		video_dst_data[0] = 0;
		video_dst_bufsize = 0;
	}
}

void FfmpegVideoFrameQueue::Exchange(VideoEx& e) {
	if (e.IsLoading()) {
		TODO
	}
	else {
		Panic("Invalid VideoEx in FfmpegVideoFrameQueue");
	}
}

int FfmpegVideoFrameQueue::GetQueueSize() const {
	//return frames.GetCount() * vid_fmt.GetFrameBytes();
	TODO
}

bool FfmpegVideoFrameQueue::IsQueueFull() const {
	//return frames.GetCount() >= min_buf_size;
	TODO
}

VideoFormat FfmpegVideoFrameQueue::GetFormat() const {
	return vid_fmt;
}

void FfmpegVideoFrameQueue::DropFrames(int i) {
	frames.RemoveFirst(i);
}

void FfmpegVideoFrameQueue::Process(double time_pos, AVFrame* frame, bool vflip) {
	ASSERT(vid_fmt.IsValid());
	auto& f = frames.Add();
	f.Create(pool);
	f->Init(vid_fmt);
	f->time_pos = time_pos;
	f->Process(time_pos, frame, vflip, vid_fmt, img_convert_ctx);
}


void FfmpegVideoFrameQueue::Frame::Process(double time_pos, AVFrame* frame, bool vflip, const VideoFormat& vid_fmt, SwsContext* img_convert_ctx) {
	TODO // Look FfmpegAudioFrameQueue::Process
	
	#if FFMPEG_VIDEOFRAME_RGBA_CONVERSION
	if (vflip) {
		for(int i = 0; i < 4; i++) {
			video_dst_linesize_vflip[i] = -video_dst_linesize[i];
			video_dst_data_vflip[i] = video_dst_data[i] + (vid_fmt.res.cy - 1) * video_dst_linesize[i];
		}
	    sws_scale(
			img_convert_ctx,
			frame->data, frame->linesize,
			0, vid_fmt.res.cy,
			video_dst_data_vflip, video_dst_linesize_vflip);
	}
	else {
	    sws_scale(
			img_convert_ctx,
			frame->data, frame->linesize,
			0, vid_fmt.res.cy,
			video_dst_data, video_dst_linesize);
	}
	#else
	#error Unimplemented
	#endif
}

#if HAVE_OPENGL

#if 0
bool FfmpegVideoFrameQueue::PaintOpenGLTexture(int texture) {
	TODO
	/*if (frames.IsEmpty())
		return false;
	auto frame_iter = frames.begin();
	Frame& f = *frame_iter();
	bool b = f.PaintOpenGLTexture(texture, vid_fmt);
	frames.Remove(frame_iter);
	return b;*/
}

bool FfmpegVideoFrameQueue::Frame::PaintOpenGLTexture(int texture, const VideoFormat& vid_fmt) {
	if (!video_dst_bufsize)
		return false;
	
	glBindTexture (GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F,
		vid_fmt.res.cx,
		vid_fmt.res.cy,
		0, GL_RGBA, GL_UNSIGNED_BYTE,
		video_dst_data[0]);
	
	return true;
}
#endif

#endif


NAMESPACE_TOPSIDE_END

#endif