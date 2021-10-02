#ifndef _SerialLib_AtomUtil_h_
#define _SerialLib_AtomUtil_h_

NAMESPACE_SERIAL_BEGIN


class AsyncMemForwarderBase :
	virtual public AtomBase
{
	Packet		partial_packet;
	byte*		write_mem = 0;
	int			write_size = 0;
	int			write_pos = 0;
	int			partial_pos = 0;
	
	
	void	Consume(int data_begin, Packet p);
	
public:
	
	bool	IsReady(ValDevCls vd) override;
	bool	ForwardAsyncMem(byte* mem, int size) override;
	bool	LoadPacket(int ch_i, const Packet& p) override;
	void	AltStorePacket(int sink_ch,  int src_ch, Packet& p) override;
	bool	IsConsumedPartialPacket() override {return partial_packet;}
	virtual bool PassLoadPacket(int ch_i, const Packet& p) {return ch_i == GetSink()->GetSinkCount()-1;}
	
};


class FramePollerBase :
	virtual public AtomBase
{
	double		dt = 0;
	double		frame_age = 0;
	
	
public:
	
	void	AltUpdate(double dt) override;
	bool	IsReady(ValDevCls vd) override;
	
	void SetFPS(int fps) {dt = 1.0 / (double)fps;}
	
};


NAMESPACE_SERIAL_END

#endif
