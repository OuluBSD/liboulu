#include <Esc/Esc.h>


namespace UPP {

EscValue EscFromStdValue(const Object& v)
{
	EscValue r;
	Time t;
	if(!IsNull(v))
		switch(v.GetType()) {
		case BOOL_V:
		case INT_V:
		case INT64_V:
		case DOUBLE_V:
			r = (double)v;
			break;
		case STRING_V:
		case WSTRING_V:
			r = v.ToWString();
			break;
		case TIME_V:
			t = v;
			r.MapSet("hour", t.hour);
			r.MapSet("minute", t.minute);
			r.MapSet("second", t.second);
		case DATE_V:
			t = v;
			r.MapSet("year", t.year);
			r.MapSet("month", t.month);
			r.MapSet("day", t.day);
			break;
		case VALUEARRAY_V:
			ObjectArray va = v;
			r.SetEmptyArray();
			for(int i = 0; i < va.GetCount(); i++)
				r.ArrayAdd(EscFromStdValue(va[i]));
		}
	return r;
}

Object StdValueFromEsc(const EscValue& v)
{
	if(v.IsNumber())
		return v.GetNumber();
	if(v.IsArray())
		return (WString)v;
	if(IsTime(v))
		return Time(v.GetFieldInt("year"), v.GetFieldInt("month"), v.GetFieldInt("day"),
			v.GetFieldInt("hour"), v.GetFieldInt("minute"), v.GetFieldInt("second"));
	if(IsDate(v))
		return Date(v.GetFieldInt("year"), v.GetFieldInt("month"), v.GetFieldInt("day"));
	return Object();
}

void SIC_StdFormat(EscEscape& e)
{
	e = StdFormatObj(StdValueFromEsc(e[0]));
}

void StdValueLib(ArrayMap<String, EscValue>& global)
{
	Escape(global, "StdFormat(x)", SIC_StdFormat);
}

}
