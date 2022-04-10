// This file have been generated automatically.
// DO NOT MODIFY THIS FILE!

#ifndef _IWebcam_TmplClasses_h_
#define _IWebcam_TmplClasses_h_

NAMESPACE_PARALLEL_BEGIN

template <class Cam> struct WebcamWebcamT;


template <class Cam>
struct WebcamWebcamT : CamWebcam {
	using CLASSNAME = WebcamWebcamT<Cam>;
	RTTI_DECL1(CLASSNAME, CamWebcam)
	void Visit(RuntimeVisitor& vis) override {vis.VisitThis<CamWebcam>(this);}
	
	typename Cam::NativeWebcam dev;
	
	
	bool Initialize(const Script::WorldState& ws) override {
		if (!Cam::Webcam_Initialize(dev, *this, ws))
			return false;
		return true;
	}

	bool PostInitialize() override {
		if (!Cam::Webcam_PostInitialize(dev, *this))
			return false;
		return true;
	}

	bool Start() override {
		return Cam::Webcam_Start(dev, *this);
	}

	void Stop() override {
		Cam::Webcam_Stop(dev, *this);
	}

	void Uninitialize() override {
		Cam::Webcam_Uninitialize(dev, *this);
	}

	bool ProcessPacket(PacketValue& in, PacketValue& out) override {
		if (!Cam::Webcam_ProcessPacket(dev, *this, in, out))
			return false;
		return true;
	}

	bool CreateWebcam() {
		return Cam::Webcam_CreateWebcam(this->dev);
	}
	
	void ClearWebcam() {
		Cam::Webcam_ClearWebcam(this->dev);
	}
	
	
};


NAMESPACE_PARALLEL_END



#endif

