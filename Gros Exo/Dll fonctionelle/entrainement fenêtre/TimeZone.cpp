#include "TimeZone.h"
#include "ETimeZoneName.h"
#include "EDayOfWeek.h"


Core::TimeZone::TimeZone(ETimeZoneName _region)
{
    dayOfWeek = _region;
}

Core::TimeZone::TimeZone(const int _year, const int _month, const int _day,const int _hour, const int _minute, const int _seconde)
{
    year=_year;
    month = _month;
    day = _day;
    hour=_hour;
    minute = _minute;
    second = _seconde;
    dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
    region = (ETimeZoneName)CalculateHourOfRegion();
}

Core::TimeZone::TimeZone(const int _month, const int _day, const int _hour, const int _minute, const int _seconde)
    :TimeZone(0, _month, _day, _hour, _minute, _seconde)
{
}

Core::TimeZone::TimeZone(const int _day, const int _hour, const int _minute, const int _seconde)
    :TimeZone(0, 0, _day, _hour, _minute, _seconde)
{
}

Core::TimeZone::TimeZone(const int _hour, const int _minute, const int _seconde)
    :TimeZone(0, 0, 0, _hour, _minute, _seconde)
{
}

Core::TimeZone::TimeZone(const TimeZone& _copy)
{
    year=_copy.year;
    month = _copy.month;
    day = _copy.day;
    hour=_copy.hour;
    minute = _copy.minute;
    second = _copy.second;
    dayOfWeek=_copy.dayOfWeek;
    region = _copy.region;
}

Core::ETimeZoneName Core::TimeZone::Region()
{
    return region;
}

Core::EDayOfWeek Core::TimeZone::DayOfWeek()
{
    return dayOfWeek;
}

int Core::TimeZone::CalculateHourOfRegion() const
{

    return 0;
}

int Core::TimeZone::CalculateDayOfWeek() const
{
    const int _m = month;
    int _y = year;
    const int _d = day;
    _y -= _m < 3;
    static int _t[] = { 0,3,2,5,0,3,5,1,4,6,2,4 };
    return (_y + _y / 4 - _y / 100 + _y / 400 + _t[_m - 1] + _d) % 7;
}

void Core::TimeZone::AddYear(const int _value)
{
    year += _value;
    dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

void Core::TimeZone::AddMonth(const int _value)
{
    month += _value;
    while (month > 12)
    {
        month -= 12;
        AddYear(1);
    }
    dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}

void Core::TimeZone::AddDay(const int _value)
{
    day += _value;
    while (day > 30)
    {
        day -= 30;
        AddMonth(1);
    }
    dayOfWeek = (EDayOfWeek)CalculateDayOfWeek();
}


void Core::TimeZone::AddHour(const int _value)
{
    hour += _value;
    while (hour > 24)
    {
        hour -= 24;
        AddDay(1);
    }
    region = (ETimeZoneName)CalculateHourOfRegion();
}

void Core::TimeZone::AddMinute(const int _value)
{
    minute += _value;
    while (minute > 60)
    {
        minute -= 60;
        AddHour(1);
    }
}

void Core::TimeZone::AddSeconde(const int _value)
{
    second += _value;
    while (second > 60)
    {
        second -= 60;
        AddMinute(1);
    }
}

Core::PrimitiveType::FString Core::TimeZone::ToString() const
{
    return ;
}
