#include "ProtoVM.h"

NAMESPACE_TOPSIDE_BEGIN

void SetupTest1_Memory(Machine& mach) {
	struct MemTester : Chip {
		Vector<byte> data;
		int addr;
		byte chk_value = 0;
		byte writing = false;
		byte in_data = 0;
		uint16 in_addr = 0;
		
		RTTI_DECL1(MemTester, Chip)
		MemTester() {
			AddBidirectional("A0"); // 0
			AddBidirectional("A1");
			AddBidirectional("A2");
			AddBidirectional("A3");
			AddBidirectional("A4");
			AddBidirectional("A5");
			AddBidirectional("A6");
			AddBidirectional("A7");
			AddBidirectional("A8");
			AddBidirectional("A9");
			AddBidirectional("A10");
			AddBidirectional("A11");
			AddBidirectional("A12");
			AddBidirectional("A13");
			AddBidirectional("A14");
			AddBidirectional("A15");
			AddBidirectional("D0"); // 16
			AddBidirectional("D1");
			AddBidirectional("D2");
			AddBidirectional("D3");
			AddBidirectional("D4");
			AddBidirectional("D5");
			AddBidirectional("D6");
			AddBidirectional("D7");
			AddSource("~WRITE"); // 24
			AddSource("~READ"); // 25
			AddSource("~ENABLE"); // 26
			
			data.SetCount(256);
			for(int i = 0; i < data.GetCount(); i++)
				data[i] = Random(256);
		}
		bool Tick() override {
			if (!writing) {
				ASSERT(!in_data || in_data == chk_value);
				LOG("MemTester test ok: " << HexStr(chk_value));
			}
			writing = !writing;
			if (writing) {
				addr = Random(data.GetCount());
				chk_value = data[addr];
			}
			return true;
		}
		
		bool Process(ProcessType type, int bytes, int bits, uint16 conn_id, ElectricNodeBase& dest, uint16 dest_conn_id) override {
			union {
				byte tmp[2];
				uint16 tmp16;
			};
			if (type == WRITE) {
				switch (conn_id) {
				case 0:
					tmp16 = addr;
					return dest.PutRaw(dest_conn_id, &tmp[0], 2, 0);
				case 16:
					tmp[0] = this->data[this->addr];
					return dest.PutRaw(dest_conn_id, &tmp[0], 1, 0);
				case 24:
					tmp[0] = !writing; // ~WRITE
					return dest.PutRaw(dest_conn_id, &tmp[0], 0, 1);
				case 25:
					tmp[0] = !!writing; // ~READ
					return dest.PutRaw(dest_conn_id, &tmp[0], 0, 1);
				case 26:
					tmp[0] = false;
					return dest.PutRaw(dest_conn_id, &tmp[0], 0, 1);
				default:
					LOG("error: MemTester: unimplemented conn-id");
					return false;
				}
			}
			else {
				LOG("error: MemTester: unimplemented ProcessType");
				return false;
			}
				
			return true;
		}
		bool PutRaw(uint16 conn_id, byte* data, int data_bytes, int data_bits) override {
			switch (conn_id) {
			case 0:
				ASSERT(data_bytes == 2 && data_bits == 0);
				in_addr = *(uint16*)data;
				break;
			case 16:
				ASSERT(data_bytes == 1 && data_bits == 0);
				in_data = *data;
				break;
			default:
				LOG("error: MemTester: unimplemented conn-id");
				return false;
			}
			return true;
		}
	};
	
	// Add single static ram only
	Pcb& b = mach.AddPcb();
	
	Pin& ground = b.Add<Pin>("ground").SetReference(0);
	Pin& vcc = b.Add<Pin>("vcc").SetReference(1);
	IC62256& ram32k = b.Add<IC62256>();
	MemTester& tester = b.Add<MemTester>();
	Bus8& data_bus = b.Add<Bus8>();
	Bus16& addr_bus = b.Add<Bus16>();
	
	
	try {
		if (0) {
			tester["A0,16"] >> ram32k["A0,16"];
			tester["D0,8"]  >> ram32k["D0,8"];
		}
		else {
			tester["A0,16"] >> addr_bus;
			tester["D0,8"] >> data_bus;
			addr_bus >> ram32k["A0,16"];
			ram32k["D0,8"] >> data_bus;
		}
		
		tester["~WRITE"]  >> ram32k["~WR"];
		tester["~READ"]   >> ram32k["~OE"];
		tester["~ENABLE"] >> ram32k["~CS"];
	}
	catch (Exc e) {
		LOG("error: " << e);
	}
}

NAMESPACE_TOPSIDE_END
