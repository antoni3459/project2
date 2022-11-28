#pragma once
#include "Object.h"
#include "FString.h"
#include "EDayOfWeek.h"
#include <string>
#include <iostream>

namespace Core
{

	class O3DLIBRAIRY_API DateTime :public Object
	{
#pragma region f/p

	private:
		int day = 0,
			month = 0,
			year = 0,
			hour = 0,
			minute = 0,
			second = 0;
		EDayOfWeek dayOfWeek = EDayOfWeek::Sunday;
#pragma endregion f/p

#pragma region constructor
	private:
		 int CalculateDayOfWeek() const;

	public:
		 EDayOfWeek DayOfWeek()const;
		 DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute, const int _second);
		 DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute);
		 DateTime(const int _day, const int _month, const int _year, const int _hour);
		 DateTime(const int _day, const int _month, const int _year);
		 DateTime(const DateTime& _copy);
#pragma endregion constructor

#pragma region methods
	public:
		 static DateTime Now();
	public:
		 void AddDay(const int _value);
		 void AddMonth(const int _value);
		 void AddYear(const int _value);
		 void AddHour(const int _value);
		 void AddMinute(const int _value);
		 void AddSecond(const int _value);
		 PrimitiveType::FString ToStringFormat(const PrimitiveType::FString& _format)const;
		 PrimitiveType::Boolean Equals(const DateTime& _obj)const;
#pragma endregion methods

#pragma region override

	public:
		 PrimitiveType::FString ToString()const override;
		 PrimitiveType::Boolean Equals(const Object* _obj)const override;

#pragma endregion override

	};
}
