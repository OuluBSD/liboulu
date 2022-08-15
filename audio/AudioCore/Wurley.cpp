#include "AudioCore.h"


NAMESPACE_AUDIO_BEGIN

Wurley::Wurley()
	: FM() {
	for ( unsigned int i = 0; i < 3; i++ )
		waves_[i] = new FileLoop( (Audio::GetRawWavePath() + "sinewave.raw").Begin(), true );

	waves_[3] = new FileLoop( (Audio::GetRawWavePath() + "fwavblnk.raw").Begin(), true );
	this->SetRatio(0, 1.0);
	this->SetRatio(1, 4.0);
	this->SetRatio(2, -510.0);
	this->SetRatio(3, -510.0);
	gains_[0] = fm_gains_[99];
	gains_[1] = fm_gains_[82];
	gains_[2] = fm_gains_[92];
	gains_[3] = fm_gains_[68];
	adsr_[0]->SetAllTimes( 0.001, 1.50, 0.0, 0.04);
	adsr_[1]->SetAllTimes( 0.001, 1.50, 0.0, 0.04);
	adsr_[2]->SetAllTimes( 0.001, 0.25, 0.0, 0.04);
	adsr_[3]->SetAllTimes( 0.001, 0.15, 0.0, 0.04);
	twozero_.SetGain( 2.0 );
	vibrato_.SetFrequency( 8.0 );
}

Wurley::~Wurley() {
}

void Wurley::SetFrequency( double frequency ) {
	#if defined(flagDEBUG)

	if ( frequency <= 0.0 ) {
		LOG("Wurley::SetFrequency: argument is less than or equal to zero!");
		HandleError( AudioError::WARNING );
		return;
	}

	#endif
	base_frequency_ = frequency;
	waves_[0]->SetFrequency( base_frequency_ * ratios_[0]);
	waves_[1]->SetFrequency( base_frequency_ * ratios_[1]);
	waves_[2]->SetFrequency( ratios_[2] );
	waves_[3]->SetFrequency( ratios_[3] );
}

void Wurley::NoteOn( double frequency, double amplitude ) {
	gains_[0] = amplitude * fm_gains_[99];
	gains_[1] = amplitude * fm_gains_[82];
	gains_[2] = amplitude * fm_gains_[82];
	gains_[3] = amplitude * fm_gains_[68];
	this->SetFrequency( frequency );
	this->KeyOn();
}

NAMESPACE_AUDIO_END
