#ifndef _AudioCore_JCREV_H
#define _AudioCore_JCREV_H


NAMESPACE_AUDIO_BEGIN



class JCRev : public Effect {
public:

	JCRev( double T60 = 1.0 );

	void Clear();
	void SetT60( double T60 );
	double GetLastOut( unsigned int channel = 0 );
	double Tick( double input, unsigned int channel = 0 );
	AudioFrames& Tick( AudioFrames& frames, unsigned int channel = 0 );
	AudioFrames& Tick( AudioFrames& in_frames, AudioFrames& out_frames, unsigned int in_channel = 0, unsigned int out_channel = 0 );

protected:

	Delay allpass_delays_[3];
	Delay comb_delays_[4];
	OnePole combFilters_[4];
	Delay outLeftDelay_;
	Delay outRightDelay_;
	double allpass_coeff_;
	double comb_coeff_[4];

};

inline double JCRev::GetLastOut( unsigned int channel ) {
	#if defined(flagDEBUG)

	if ( channel > 1 ) {
		LOG("JCRev::GetLastOut(): channel argument must be less than 2!");
		HandleError( AudioError::FUNCTION_ARGUMENT );
	}

	#endif
	return last_frame_[channel];
}

inline double JCRev::Tick( double input, unsigned int channel ) {
	#if defined(flagDEBUG)

	if ( channel > 1 ) {
		LOG("JCRev::Tick(): channel argument must be less than 2!");
		HandleError( AudioError::FUNCTION_ARGUMENT );
	}

	#endif
	double temp, temp0, temp1, temp2, temp3, temp4, temp5, temp6;
	double filtout;
	temp = allpass_delays_[0].GetLastOut();
	temp0 = allpass_coeff_ * temp;
	temp0 += input;
	allpass_delays_[0].Tick(temp0);
	temp0 = -(allpass_coeff_ * temp0) + temp;
	temp = allpass_delays_[1].GetLastOut();
	temp1 = allpass_coeff_ * temp;
	temp1 += temp0;
	allpass_delays_[1].Tick(temp1);
	temp1 = -(allpass_coeff_ * temp1) + temp;
	temp = allpass_delays_[2].GetLastOut();
	temp2 = allpass_coeff_ * temp;
	temp2 += temp1;
	allpass_delays_[2].Tick(temp2);
	temp2 = -(allpass_coeff_ * temp2) + temp;
	temp3 = temp2 + ( combFilters_[0].Tick( comb_coeff_[0] * comb_delays_[0].GetLastOut() ) );
	temp4 = temp2 + ( combFilters_[1].Tick( comb_coeff_[1] * comb_delays_[1].GetLastOut() ) );
	temp5 = temp2 + ( combFilters_[2].Tick( comb_coeff_[2] * comb_delays_[2].GetLastOut() ) );
	temp6 = temp2 + ( combFilters_[3].Tick( comb_coeff_[3] * comb_delays_[3].GetLastOut() ) );
	comb_delays_[0].Tick(temp3);
	comb_delays_[1].Tick(temp4);
	comb_delays_[2].Tick(temp5);
	comb_delays_[3].Tick(temp6);
	filtout = temp3 + temp4 + temp5 + temp6;
	last_frame_[0] = effect_mix_ * (outLeftDelay_.Tick(filtout));
	last_frame_[1] = effect_mix_ * (outRightDelay_.Tick(filtout));
	temp = (1.0 - effect_mix_) * input;
	last_frame_[0] += temp;
	last_frame_[1] += temp;
	return 0.7 * last_frame_[channel];
}

NAMESPACE_AUDIO_END

#endif

