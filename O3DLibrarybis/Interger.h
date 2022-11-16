#pragma once
#include "Object.h"
#include"boolean.h"
#include <limits>
namespace Core
{
	namespace PrimitiveType
	{
		class Interger:public Object
		{
#pragma region f/p
		private:
			int value = 0;
		public:
			O3DLIBRARY_API static Interger MinValue();
			O3DLIBRARY_API static Interger MaxValue();
			/*O3DLIBRARY_API static const PrimitiveType::Interger MaxValue;
			O3DLIBRARY_API static const PrimitiveType::Interger MinValue;*/
#pragma endregion f/p

#pragma region constructeur
		public:
			O3DLIBRARY_API Interger() = default;
			O3DLIBRARY_API Interger(const int _value);
			O3DLIBRARY_API Interger(const Interger& _copy);
#pragma endregion constructeur

		public:
			O3DLIBRARY_API boolean Equals(const Interger& _other)const;
			O3DLIBRARY_API static Interger Parse(const FString& _str);
			O3DLIBRARY_API static boolean TryParse(const FString& _str, Interger& _out);
#pragma region override
		public:
			O3DLIBRARY_API FString ToString()const override;
			O3DLIBRARY_API boolean Equals(const Object* _obj)const override;
#pragma endregion override

		public:
			O3DLIBRARY_API operator int()const;
			O3DLIBRARY_API Interger operator+(const Interger& _other) const;
			O3DLIBRARY_API Interger& operator+=(const Interger& _other) ;
			O3DLIBRARY_API Interger operator-(const Interger& _other) const;
			O3DLIBRARY_API Interger& operator-=(const Interger& _other) ;
			O3DLIBRARY_API Interger operator*(const Interger& _other) const;
			O3DLIBRARY_API Interger& operator*=(const Interger& _other) ;
			O3DLIBRARY_API Interger operator/(const Interger& _other) const;
			O3DLIBRARY_API Interger& operator/=(const Interger& _other) ;
			O3DLIBRARY_API Interger operator%(const Interger& _other)const ;
			O3DLIBRARY_API Interger& operator%=(const Interger& _other) ;
	
			O3DLIBRARY_API Interger operator++(int) ;
			O3DLIBRARY_API Interger& operator++() ;
			O3DLIBRARY_API Interger operator--(int) ;
			O3DLIBRARY_API Interger& operator--() ;
			O3DLIBRARY_API Interger operator-() ;

			O3DLIBRARY_API boolean operator<(const Interger& _other) const;
			O3DLIBRARY_API boolean operator<=(const Interger& _other) const;
			O3DLIBRARY_API boolean operator>(const Interger& _other) const;
			O3DLIBRARY_API boolean operator>=(const Interger& _other) const;
			O3DLIBRARY_API boolean operator==(const Interger& _other) const;
			O3DLIBRARY_API boolean operator!=(const Interger& _other) const;
		};
		
	}
}
