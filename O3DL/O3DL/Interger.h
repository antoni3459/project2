#pragma once
#include "Object.h"
#include "Boolean.h"
#include "FString.h"


namespace Core
{
	namespace PrimitiveType
	{
		class O3DLIBRAIRY_API Integer sealed : public Object
		{
#pragma region f/p

		private:
			int value = 0;
		public:
			 static Integer MaxValue();
			 static Integer MinValue();
#pragma endregion f/p

#pragma region constructor

		public:
			 Integer() = default;
			 Integer(const int _value);
			 Integer(const Integer& _copy);
#pragma endregion constructor

#pragma region methods
		public:
			 Boolean Equals(const Integer& _other) const;
			 static Integer Parse(const FString& _str);
			 static Boolean TryParse(const FString& _str, Integer& _out);
#pragma endregion methods

#pragma region override

		public:
			 FString ToString() const override;
			 Boolean Equals(const Object* _obj) const override;
#pragma endregion override

#pragma region operator

		public:
			 operator int()const;
			 Integer operator+(const Integer& _other) const;
			 Integer& operator+=(const Integer& _other);
			 Integer operator-(const Integer& _other) const;
			 Integer& operator-=(const Integer& _other);
			 Integer operator*(const Integer& _other) const;
			 Integer& operator*=(const Integer& _other);
			 Integer operator/(const Integer& _other) const;
			 Integer& operator/=(const Integer& _other);
			 Integer operator%(const Integer& _other)const;
			 Integer& operator%=(const Integer& _other);

			 Integer operator++(int);
			 Integer operator--(int);
			 Integer& operator++();
			 Integer& operator--();
			 Integer operator-();

			 Boolean operator<(const Integer& _other) const;
			 Boolean operator<=(const Integer& _other) const;
			 Boolean operator>(const Integer& _other) const;
			 Boolean operator>=(const Integer& _other) const;
			 Boolean operator==(const Integer& _other) const;
			 Boolean operator!=(const Integer& _other) const;
#pragma endregion operator
		};
	}
}
