#ifndef _AudioCore_HEVYMETL_H
#define _AudioCore_HEVYMETL_H


NAMESPACE_AUDIO_BEGIN


class HeavyMetal : public FM {
public:
	HeavyMetal();
	~HeavyMetal();
	void NoteOn( double frequency, double amplitude );
	double Tick( unsigned int channel = 0 );
	AudioFrames& Tick( AudioFrames& frames, unsigned int channel = 0 );

};

inline double HeavyMetal::Tick( unsigned int ) {
	double temp;
	temp = vibrato_.Tick() * mod_depth_ * 0.2;
	waves_[0]->SetFrequency(base_frequency_ * (1.0 + temp) * ratios_[0]);
	waves_[1]->SetFrequency(base_frequency_ * (1.0 + temp) * ratios_[1]);
	waves_[2]->SetFrequency(base_frequency_ * (1.0 + temp) * ratios_[2]);
	waves_[3]->SetFrequency(base_frequency_ * (1.0 + temp) * ratios_[3]);
	temp = gains_[2] * adsr_[2]->Tick() * waves_[2]->Tick();
	waves_[1]->AddPhaseOffset( temp );
	waves_[3]->AddPhaseOffset( twozero_.GetLastOut() );
	temp = (1.0 - (control2_ * 0.5)) * gains_[3] * adsr_[3]->Tick() * waves_[3]->Tick();
	twozero_.Tick(temp);
	temp += control2_ * 0.5 * gains_[1] * adsr_[1]->Tick() * waves_[1]->Tick();
	temp = temp * control1_;
	waves_[0]->AddPhaseOffset( temp );
	temp = gains_[0] * adsr_[0]->Tick() * waves_[0]->Tick();
	last_frame_[0] = temp * 0.5;
	return last_frame_[0];
}

inline AudioFrames& HeavyMetal::Tick( AudioFrames& frames, unsigned int channel ) {
	unsigned int channel_count = last_frame_.GetChannelCount();
	#if defined(flagDEBUG)

	if ( channel > frames.GetChannelCount() - channel_count ) {
		LOG("HeavyMetal::Tick(): channel and AudioFrames arguments are incompatible!");
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
