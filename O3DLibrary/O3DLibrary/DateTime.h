#pragma once
#include "Object.h"
#include "FString.h"
#include "EDayOfWeek.h"
#include <string>
#include <iostream>

namespace Core
{

	class DateTime :public Object
	{
#pragma region f/p

	private :
		int day = 0,
			month = 0,
			year = 0,
			hour = 0,
			minute = 0,
			second = 0;
		EDayOfWeek dayOfWeek = EDayOfWeek::Sunday;
#pragma endregion f/p

#pragma region constructeur
	private:
		O3DLIBRAIRY_API int CalculateDayOfWeek() const;

	public:
		O3DLIBRAIRY_API EDayOfWeek DayOfWeek()const;
		O3DLIBRAIRY_API DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute, const int _second);
		O3DLIBRAIRY_API DateTime(const int _day, const int _month, const int _year, const int _hour, const int _minute);
		O3DLIBRAIRY_API DateTime(const int _day, const int _month, const int _year, const int _hour);
		O3DLIBRAIRY_API DateTime(const int _day, const int _month, const int _year);
		O3DLIBRAIRY_API DateTime(const DateTime& _copy);
#pragma endregion constructeur

#pragma region method
	public :
		O3DLIBRAIRY_API static DateTime Now();
	public:
		O3DLIBRAIRY_API void AddDay(const int _value);
		O3DLIBRAIRY_API void AddMonth(const int _value);
		O3DLIBRAIRY_API void AddYear(const int _value);
		O3DLIBRAIRY_API void AddHour(const int _value);
		O3DLIBRAIRY_API void AddMinute(const int _value);
		O3DLIBRAIRY_API void AddSecond(const int _value);
		O3DLIBRAIRY_API PrimitiveType::FString ToStringFormat(const PrimitiveType::FString& _format)const;
		O3DLIBRAIRY_API PrimitiveType::Boolean Equals(const DateTime& _obj)const ;
#pragma endregion method

#pragma region override

	public:
		O3DLIBRAIRY_API PrimitiveType::FString ToString()const override;
		O3DLIBRAIRY_API PrimitiveType::Boolean Equals(const Object* _obj)const override;

#pragma endregion override

	};
}
