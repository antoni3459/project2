#pragma once
#include "Object.h"
#include "ETimeZoneName.h"
#include "EDayOfWeek.h"
#include <chrono>
#include <time.h>
#include <iostream>
#include <chrono>
#include <map>

namespace Core
{
	class TimeZone:public Object
	{
#pragma region f/p

	private:
		EDayOfWeek dayOfWeek = EDayOfWeek::Sunday;
		ETimeZoneName region = ETimeZoneName::Central_Standard_Time;
		int year=0,
			month=0,
			day=0,			
			hour = 0,
			minute = 0,
			second = 0;

#pragma endregion f/p

#pragma region constructor

	public:
		TimeZone() = default;
		TimeZone(ETimeZoneName _region);
		TimeZone(const int _year, const int _month, const int _day,const int _hour, const int _minute, const int _seconde);
		TimeZone(const int _month, const int _day,const int _hour, const int _minute, const int _seconde);
		TimeZone(const int _day,const int _hour, const int _minute, const int _seconde);
		TimeZone(const int _hour, const int _minute, const int _seconde);

		TimeZone(const TimeZone& _copy);

#pragma endregion constructor

#pragma region method

	public:
		ETimeZoneName Region();
		EDayOfWeek DayOfWeek();
		int CalculateHourOfRegion()const;
		int CalculateDayOfWeek()const ;
		void AddYear(const int _value);
		void AddMonth(const int _value);
		void AddDay(const int _value);
		void AddHour(const int _value);
		void AddMinute(const int _value);
		void AddSeconde(const int _value);

#pragma endregion method

#pragma region override

	public:
		PrimitiveType::FString ToString()const override;

#pragma endregion override
	};
}

