#ifdef LIBTOPSIDE
	#include <Esc/Esc.h>
#else
	#include <Esc/Esc.h>
#endif

using namespace UPP;

#define PRINT(x) {Cout() << x; VppLog() << x;}

void SIC_Print(EscEscape& e)
{
	if(e[0].IsArray())
		PRINT((String) e[0])
	else
	if(e[0].IsNumber())
		PRINT(e[0].GetNumber())
	else
	if(!e[0].IsVoid())
		e.ThrowError("invalid argument to 'Print'");
}

void SIC_Input(EscEscape& e)
{
	e = ReadStdIn();
}

void SIC_InputNumber(EscEscape& e)
{
	e = atof(ReadStdIn());
}

CONSOLE_APP_MAIN
{
	ArrayMap<String, EscValue> global;
	Escape(global, "Print(x)", SIC_Print);
	Escape(global, "Input()", SIC_Input);
	Escape(global, "InputNumber()", SIC_InputNumber);
	StdLib(global);
	try {
		Scan(global, LoadFile(GetDataFile("script.esc")));
		Execute(global, "main", INT_MAX);
	}
	catch(CParser::Error e) {
		PRINT("ERROR: " << e << "\n");
	}
}
