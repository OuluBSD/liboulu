#include "ParallelCore.h"


NAMESPACE_PARALLEL_BEGIN


Format GetDefaultFormat(ValDevCls type) {
	//DUMP(type)
	Format fmt;
	
	if (type.val == ValCls::AUDIO) {
		fmt.SetAudio(type.dev, SoundSample::U16_LE, 2, 44100, 1024);
	}
	else if (type.val == ValCls::ORDER) {
		fmt.SetOrder(type.dev);
	}
	else if (type.val == ValCls::RECEIPT) {
		fmt.SetReceipt(type.dev);
	}
	else if (type.val == ValCls::MIDI) {
		fmt.SetMidi(type.dev);
	}
	else if (type.val == ValCls::VOLUME) {
		fmt.SetVolume(type.dev, BinarySample::U8_LE_A, 512, 512, 512, 1, 1);
	}
	else if (type.val == ValCls::VIDEO) {
		fmt.SetVideo(type.dev, LightSampleFD::U8_LE_ABC, 1280, 720, 60, 1);
	}
	else if (type.val == ValCls::EVENT) {
		fmt.SetEvent(type.dev);
	}
	else if (type.val == ValCls::FBO) {
		fmt.SetFbo(type.dev, BinarySample::U8_LE_ABC, 1280, 720, 0, 60, 1);
	}
	else if (type.val == ValCls::PROG) {
		fmt.SetProg(type.dev);
	}
	else {
		TODO
	}
	
	return fmt;
}






NAMESPACE_PARALLEL_END
