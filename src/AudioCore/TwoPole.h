#ifndef _AudioCore_TWOPOLE_H
#define _AudioCore_TWOPOLE_H


NAMESPACE_AUDIO_BEGIN


class TwoPole : public Filter {
public:

	TwoPole();
	~TwoPole();

	void IgnoreSampleRateChange( bool ignore = true ) {
		IgnoreSampleRateChange_ = ignore;
	};

	void SetB0( float b0 ) {
		b_[0] = b0;
	};
	
	void SetA1( float a1 ) {
		a_[1] = a1;
	};

	void SetA2( float a2 ) {
		a_[2] = a2;
	};

	void SetCoefficients( float b0, float a1, float a2, bool ClearState = false );
	void SetResonance(float frequency, float radius, bool normalize = false);

	float GetLastOut() const {
		return last_frame_[0];
	};

	float Tick( float input );
	AudioFrames& Tick( AudioFrames& frames, int channel = 0 );
	AudioFrames& Tick( AudioFrames& in_frames, AudioFrames& out_frames, int in_channel = 0, int out_channel = 0 );

protected:

	virtual void SampleRateChanged( float new_rate, float old_rate );
	
};

inline float TwoPole::Tick( float input ) {
	inputs_[0] = gain_ * input;
	last_frame_[0] = b_[0] * inputs_[0] - a_[1] * outputs_[1] - a_[2] * outputs_[2];
	outputs_[2] = outputs_[1];
	outputs_[1] = last_frame_[0];
	return last_frame_[0];
}

inline AudioFrames& TwoPole::Tick( AudioFrames& frames, int channel ) {
	#if defined(flagDEBUG)

	if ( channel >= frames.GetChannelCount() ) {
		LOG("TwoPole::Tick(): channel and AudioFrames arguments are incompatible!");
		HandleError( AudioError::FUNCTION_ARGUMENT );
	}

	#endif
	float* samples = &frames[channel];
	int step = frames.GetChannelCount();

	for ( int i = 0; i < frames.GetFrameCount(); i++, samples += step ) {
		inputs_[0] = gain_ * *samples;
		*samples = b_[0] * inputs_[0] - a_[1] * outputs_[1] - a_[2] * outputs_[2];
		outputs_[2] = outputs_[1];
		outputs_[1] = *samples;
	}

	last_frame_[0] = outputs_[1];
	return frames;
}

inline AudioFrames& TwoPole::Tick( AudioFrames& in_frames, AudioFrames& out_frames, int in_channel, int out_channel ) {
	#if defined(flagDEBUG)

	if ( in_channel >= in_frames.GetChannelCount() || out_channel >= out_frames.GetChannelCount() ) {
		LOG("TwoPole::Tick(): channel and AudioFrames arguments are incompatible!");
		HandleError( AudioError::FUNCTION_ARGUMENT );
	}

	#endif
	float* in_samples = &in_frames[in_channel];
	float* out_samples = &out_frames[out_channel];
	int in_step = in_frames.GetChannelCount(), out_step = out_frames.GetChannelCount();

	for ( int i = 0; i < in_frames.GetFrameCount(); i++, in_samples += in_step, out_samples += out_step ) {
		inputs_[0] = gain_ * *in_samples;
		*out_samples = b_[0] * inputs_[0] - a_[1] * outputs_[1] - a_[2] * outputs_[2];
		outputs_[2] = outputs_[1];
		outputs_[1] = *out_samples;
	}

	last_frame_[0] = outputs_[1];
	return in_frames;
}

NAMESPACE_AUDIO_END

#endif
