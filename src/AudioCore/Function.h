#ifndef _AudioCore_FUNCTION_H
#define _AudioCore_FUNCTION_H


NAMESPACE_AUDIO_BEGIN


class Function : public Audio {
public:

	Function() {
		last_frame_.SetCount( 1, 1, 0.0 );
	};

	double GetLastOut() const {
		return last_frame_[0];
	};

	virtual double Tick( double input ) = 0;

protected:

	AudioFrames last_frame_;

};

NAMESPACE_AUDIO_END

#endif

