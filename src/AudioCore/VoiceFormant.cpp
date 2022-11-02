#include "AudioCore.h"


NAMESPACE_AUDIO_BEGIN

VoiceFormant::VoiceFormant() : Instrument() {
	voiced_ = new SingWave( (Audio::GetRawWavePath() + "impuls20.raw").Begin(), true );
	voiced_->SetGainRate( 0.001 );
	voiced_->SetGainTarget( 0.0 );

	for ( int i = 0; i < 4; i++ )
		filters_[i].SetSweepRate( 0.001 );

	onezero_.SetZero( -0.9 );
	onepole_.SetPole( 0.9 );
	noise_env_.SetRate( 0.001 );
	noise_env_.SetTarget( 0.0 );
	this->SetPhoneme( "eee" );
	this->Clear();
}

VoiceFormant::~VoiceFormant() {
	delete voiced_;
}

void VoiceFormant::Clear() {
	onezero_.Clear();
	onepole_.Clear();

	for ( int i = 0; i < 4; i++ )
		filters_[i].Clear();
}

void VoiceFormant::SetFrequency( double frequency ) {
	#if defined(flagDEBUG)

	if ( frequency <= 0.0 ) {
		LOG("VoiceFormant::SetFrequency: parameter is less than or equal to zero!");
		HandleError( AudioError::WARNING );
		return;
	}

	#endif
	voiced_->SetFrequency( frequency );
}

bool VoiceFormant::SetPhoneme( const char* phoneme ) {
	bool found = false;
	unsigned int i = 0;

	while ( i < 32 && !found ) {
		if ( !strcmp( Phonemes::name(i), phoneme ) ) {
			found = true;
			filters_[0].SetTargets( Phonemes::GetFormantFrequency(i, 0), Phonemes::GetFormantRadius(i, 0), pow(10.0, Phonemes::GetFormantGain(i, 0 ) / 20.0) );
			filters_[1].SetTargets( Phonemes::GetFormantFrequency(i, 1), Phonemes::GetFormantRadius(i, 1), pow(10.0, Phonemes::GetFormantGain(i, 1 ) / 20.0) );
			filters_[2].SetTargets( Phonemes::GetFormantFrequency(i, 2), Phonemes::GetFormantRadius(i, 2), pow(10.0, Phonemes::GetFormantGain(i, 2 ) / 20.0) );
			filters_[3].SetTargets( Phonemes::GetFormantFrequency(i, 3), Phonemes::GetFormantRadius(i, 3), pow(10.0, Phonemes::GetFormantGain(i, 3 ) / 20.0) );
			this->SetVoiced( Phonemes::GetVoiceGain( i ) );
			this->SetUnVoiced( Phonemes::GetNoiseGain( i ) );
		}

		i++;
	}

	if ( !found ) {
		LOG("VoiceFormant::SetPhoneme: phoneme " << phoneme << " not found!");
		HandleError( AudioError::WARNING );
	}

	return found;
}

void VoiceFormant::SetFilterSweepRate( unsigned int whichOne, double rate ) {
	if ( whichOne > 3 ) {
		LOG("VoiceFormant::SetFilterSweepRate: filter select argument outside range 0-3!");
		HandleError( AudioError::WARNING );
		return;
	}

	filters_[whichOne].SetSweepRate(rate);
}

void VoiceFormant::Quiet() {
	voiced_->NoteOff();
	noise_env_.SetTarget( 0.0 );
}

void VoiceFormant::NoteOn( double frequency, double amplitude ) {
	this->SetFrequency( frequency );
	voiced_->SetGainTarget( amplitude );
	onepole_.SetPole( 0.97 - (amplitude * 0.2) );
}

void VoiceFormant::ControlChange( int number, double value ) {
	#if defined(flagDEBUG)

	if ( Audio::InRange( value, 0.0, 128.0 ) == false ) {
		LOG("VoiceFormant::controlChange: value (" << value << ") is out of range!");
		HandleError( AudioError::WARNING );
		return;
	}

	#endif
	double normalizedValue = value * ONE_OVER_128;

	if (number == __SK_Breath_)	{
		this->SetVoiced( 1.0 - normalizedValue );
		this->SetUnVoiced( 0.01 * normalizedValue );
	}
	else if (number == __SK_FootControl_)	{
		double temp = 0.0;
		unsigned int i = (int) value;

		if (i < 32)
			temp = 0.9;
		else if (i < 64)	{
			i -= 32;
			temp = 1.0;
		}
		else if (i < 96)	{
			i -= 64;
			temp = 1.1;
		}
		else if (i < 128)	{
			i -= 96;
			temp = 1.2;
		}
		else if (i == 128)	{
			i = 0;
			temp = 1.4;
		}

		filters_[0].SetTargets( temp * Phonemes::GetFormantFrequency(i, 0), Phonemes::GetFormantRadius(i, 0), pow(10.0, Phonemes::GetFormantGain(i, 0 ) / 20.0) );
		filters_[1].SetTargets( temp * Phonemes::GetFormantFrequency(i, 1), Phonemes::GetFormantRadius(i, 1), pow(10.0, Phonemes::GetFormantGain(i, 1 ) / 20.0) );
		filters_[2].SetTargets( temp * Phonemes::GetFormantFrequency(i, 2), Phonemes::GetFormantRadius(i, 2), pow(10.0, Phonemes::GetFormantGain(i, 2 ) / 20.0) );
		filters_[3].SetTargets( temp * Phonemes::GetFormantFrequency(i, 3), Phonemes::GetFormantRadius(i, 3), pow(10.0, Phonemes::GetFormantGain(i, 3 ) / 20.0) );
		this->SetVoiced( Phonemes::GetVoiceGain( i ) );
		this->SetUnVoiced( Phonemes::GetNoiseGain( i ) );
	}
	else if (number == __SK_ModFrequency_)
		voiced_->SetVibratoRate( normalizedValue * 12.0);
	else if (number == __SK_ModWheel_)
		voiced_->SetVibratoGain( normalizedValue * 0.2);
	else if (number == __SK_AfterTouch_Cont_)	{
		this->SetVoiced( normalizedValue );
		onepole_.SetPole( 0.97 - ( normalizedValue * 0.2) );
	}

	#if defined(flagDEBUG)
	else {
		LOG("VoiceFormant::controlChange: undefined Control number (" << number << ")!");
		HandleError( AudioError::WARNING );
	}

	#endif
}

NAMESPACE_AUDIO_END
