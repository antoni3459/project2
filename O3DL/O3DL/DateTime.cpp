#include "DateTime.h"
#include "FString.h"
#include "Boolean.h"
#include "EDayOfWeek.h"
#include <format>
#include <time.h>
#include <string>
#include <iostream>

Core::DateTime::DateTime(const SYSTEMTIME& _time)
{
	day=_time.wDay;
	month = _time.wMonth;
	year = _time.wYear;
	hour = _time.wHour;
	minute = _time.wMinute;
	second = _time.wSecond;
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

Core::DateTime::DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute, const int _second)
{
	day = _day;
	month = _month;
	year = _year;
	hour = _hour;
	minute = _minute;
	second = _second;
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

Core::DateTime::DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute)
	:DateTime(_day, _month, _year, _hour, _minute, 0)
{


}

Core::DateTime::DateTime(const int _day, const int _month, const int _year, const int _hour)
	:DateTime(_day, _month, _year, _hour, 0, 0)
{
}

Core::DateTime::DateTime(const int _day, const int _month, const int _year)
	:DateTime(_day, _month, _year, 0, 0, 0)
{
}

Core::DateTime::DateTime(const DateTime& _copy)
{
	day = _copy.day;
	month = _copy.month;
	year = _copy.year;
	hour = _copy.hour;
	minute = _copy.minute;
	second = _copy.second;
	dayOfWeek = _copy.dayOfWeek;
}
int Core::DateTime::CalculateDayOfWeek() const
{
	const int _m = month;
	int _y = year;
	const int _d = day;
	_y -= _m < 3;
	static int _t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
	return (_y + _y / 4 - _y / 100 + _y / 400 + _t[_m - 1] + _d) % 7;
}

Core::EDayOfWeek Core::DateTime::DayOfWeek()const
{
	return dayOfWeek;
}

void Core::DateTime::AddDay(const int _value)
{
	day += _value;
	while (day > 30)
	{
		day -= 30;
		AddMonth(1);
	}
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

void Core::DateTime::AddMonth(const int _value)
{
	month += _value;
	while (month > 12)
	{
		month -= 12;
		AddYear(1);
	}
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

void Core::DateTime::AddYear(const int _value)
{
	year += _value;
	dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

void Core::DateTime::AddHour(const int _value)
{
	hour += _value;
	while (hour > 24)
	{
		hour -= 24;
		AddDay(1);
	}
}

void Core::DateTime::AddMinute(const int _value)
{
	minute += _value;
	while (minute > 60)
	{
		minute -= 60;
		AddHour(1);
	}
}

void Core::DateTime::AddSecond(const int _value)
{
	second += _value;
	while (second > 60)
	{
		second -= 60;
		AddMinute(1);
	}
}

Core::DateTime Core::DateTime::Now()
{
	const time_t _now = time(nullptr);
	std::tm _tm = std::tm();
	localtime_s(&_tm, &_now);
	return DateTime(_tm.tm_mday, _tm.tm_mon + 1, _tm.tm_year + 1900, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
}

Core::PrimitiveType::FString Core::DateTime::ToStringFormat(const PrimitiveType::FString& _format) const
{
	if (PrimitiveType::FString::IsNullOrEmpty(_format)) return "format error";
	PrimitiveType::FString _result = _format;

	const PrimitiveType::FString _monthCstr = std::to_string(month).c_str();
	const PrimitiveType::FString _dayCstr = std::to_string(day).c_str();
	const PrimitiveType::FString _hourCstr = std::to_string(hour).c_str();
	const PrimitiveType::FString _minuteCstr = std::to_string(minute).c_str();
	const PrimitiveType::FString _secondCstr = std::to_string(second).c_str();
	_result = _result.Replace("Y", std::to_string(year).c_str());
	_result = _result.Replace("M", month < 10 ? PrimitiveType::FString("0") + _monthCstr : _monthCstr);
	_result = _result.Replace("D", day < 10 ? PrimitiveType::FString("0") + _dayCstr : _dayCstr);
	_result = _result.Replace("h", hour < 10 ? PrimitiveType::FString("0") + _hourCstr : _hourCstr);
	_result = _result.Replace("m", minute < 10 ? PrimitiveType::FString("0") + _minuteCstr : _minuteCstr);
	_result = _result.Replace("s", second < 10 ? PrimitiveType::FString("0") + _secondCstr : _secondCstr);
	return _result;
}

Core::PrimitiveType::Boolean Core::DateTime::Equals(const DateTime& _obj)const
{
	return day == _obj.day && month == _obj.month && year == _obj.year &&
		hour == _obj.hour && minute == _obj.minute && second == _obj.second;
}

Core::PrimitiveType::FString Core::DateTime::ToString()const
{
	return ToStringFormat("h:m:s D-M-Y");
}

Core::PrimitiveType::Boolean Core::DateTime::Equals(const Object* _obj)const
{
	const DateTime* _other = dynamic_cast<const DateTime*>(_obj);
	if (_other == nullptr) return false;
	return Equals(*_other);
}