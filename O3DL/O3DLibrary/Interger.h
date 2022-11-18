#pragma once
#include "Object.h"
#include "Boolean.h"
#include "FString.h"


namespace Core
{
	namespace PrimitiveType
	{
		class Integer sealed : public Object
		{
#pragma region f/p
		private:
			int value = 0;
		public:
			O3DLIBRAIRY_API static Integer MaxValue();
			O3DLIBRAIRY_API static Integer MinValue();
#pragma endregion f/p
#pragma region constructor
		public:
			O3DLIBRAIRY_API Integer() = default;
			O3DLIBRAIRY_API Integer(const int _value);
			O3DLIBRAIRY_API Integer(const Integer& _copy);
#pragma endregion constructor
#pragma region methods
		public:
			O3DLIBRAIRY_API Boolean Equals(const Integer& _other) const;
			O3DLIBRAIRY_API static Integer Parse(const FString& _str);
			O3DLIBRAIRY_API static Boolean TryParse(const FString& _str, Integer& _out);
#pragma endregion methods
#pragma region override
		public:
			O3DLIBRAIRY_API FString ToString() const override;
			O3DLIBRAIRY_API Boolean Equals(const Object* _obj) const override;
#pragma endregion override
#pragma region operator
		public:
			O3DLIBRAIRY_API operator int()const;
			O3DLIBRAIRY_API Integer operator+(const Integer& _other) const;
			O3DLIBRAIRY_API Integer& operator+=(const Integer& _other);
			O3DLIBRAIRY_API Integer operator-(const Integer& _other) const;
			O3DLIBRAIRY_API Integer& operator-=(const Integer& _other);
			O3DLIBRAIRY_API Integer operator*(const Integer& _other) const;
			O3DLIBRAIRY_API Integer& operator*=(const Integer& _other);
			O3DLIBRAIRY_API Integer operator/(const Integer& _other) const;
			O3DLIBRAIRY_API Integer& operator/=(const Integer& _other);
			O3DLIBRAIRY_API Integer operator%(const Integer& _other)const;
			O3DLIBRAIRY_API Integer& operator%=(const Integer& _other);

			O3DLIBRAIRY_API Integer operator++(int);
			O3DLIBRAIRY_API Integer operator--(int);
			O3DLIBRAIRY_API Integer& operator++();
			O3DLIBRAIRY_API Integer& operator--();
			O3DLIBRAIRY_API Integer operator-();

			O3DLIBRAIRY_API Boolean operator<(const Integer& _other) const;
			O3DLIBRAIRY_API Boolean operator<=(const Integer& _other) const;
			O3DLIBRAIRY_API Boolean operator>(const Integer& _other) const;
			O3DLIBRAIRY_API Boolean operator>=(const Integer& _other) const;
			O3DLIBRAIRY_API Boolean operator==(const Integer& _other) const;
			O3DLIBRAIRY_API Boolean operator!=(const Integer& _other) const;
#pragma endregion operator
		};
	}
}
