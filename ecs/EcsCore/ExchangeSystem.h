#ifndef _EcsCore_ExchangeSystem_h_
#define _EcsCore_ExchangeSystem_h_


NAMESPACE_OULU_BEGIN




class ExchangeSystem : public System<ExchangeSystem> {

public:
	using System::System;
	
	
protected:
	
    bool Initialize() override;
    void Start() override;
    void Update(double dt) override;
    void Stop() override;
    void Uninitialize() override;
	
};





class AudioExchangePoint : public ExchangePoint {
	ConnectorBase* conn = 0;
	
public:
	typedef AudioExchangePoint CLASSNAME;
	AudioExchangePoint();
	~AudioExchangePoint() {Deinit();}
	
	void Init(ConnectorBase* conn);
	void Deinit();
	void Update(double dt) override;
	
};

typedef Ref<AudioExchangePoint>		AudioExchangePointRef;



class VideoExchangePoint : public ExchangePoint {
	ConnectorBase* conn = 0;
	
	
public:
	typedef VideoExchangePoint CLASSNAME;
	VideoExchangePoint();
	~VideoExchangePoint() {Deinit();}
	
	void Init(ConnectorBase* conn);
	void Deinit();
	void Update(double dt) override;
	
};

typedef Ref<VideoExchangePoint>		VideoExchangePointRef;


NAMESPACE_OULU_END


#endif
