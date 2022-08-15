#ifndef _AudioCore_SIMPLE_H
#define _AudioCore_SIMPLE_H


NAMESPACE_AUDIO_BEGIN

class Simple : public Instrument {
public:

	Simple();
	~Simple();
	void SetFrequency( double frequency );
	void KeyOn();
	void KeyOff();
	void NoteOn( double frequency, double amplitude );
	void NoteOff( double amplitude );
	void ControlChange( int number, double value );
	double Tick( unsigned int channel = 0 );
	AudioFrames& Tick( AudioFrames& frames, unsigned int channel = 0 );

protected:

	ADSR      adsr_;
	FileLoop* loop_;
	OnePole   filter_;
	BiQuad    biquad_;
	Noise     noise_;
	double  base_frequency_;
	double  loop_gain_;

};

inline double Simple::Tick( unsigned int ) {
	last_frame_[0] = loop_gain_ * loop_->Tick();
	biquad_.Tick( noise_.Tick() );
	last_frame_[0] += (1.0 - loop_gain_) * biquad_.GetLastOut();
	last_frame_[0] = filter_.Tick( last_frame_[0] );
	last_frame_[0] *= adsr_.Tick();
	return last_frame_[0];
}

inline AudioFrames& Simple::Tick( AudioFrames& frames, unsigned int channel ) {
	unsigned int channel_count = last_frame_.GetChannelCount();
	#if defined(flagDEBUG)

	if ( channel > frames.GetChannelCount() - channel_count ) {
		LOG("Simple::Tick(): channel and AudioFrames arguments are incompatible!");
		HandleError( AudioError::FUNCTION_ARGUMENT );
	}

	#endif
	double* samples = &frames[channel];
	unsigned int j, step = frames.GetChannelCount() - channel_count;

	if ( channel_count == 1 ) {
		for ( unsigned int i = 0; i < frames.GetFrameCount(); i++, samples += step )
			* samples++ = Tick();
	}
	else {
		for ( unsigned int i = 0; i < frames.GetFrameCount(); i++, samples += step ) {
			*samples++ = Tick();

			for ( j = 1; j < channel_count; j++ )
				*samples++ = last_frame_[j];
		}
	}

	return frames;
}

NAMESPACE_AUDIO_END

#endif
