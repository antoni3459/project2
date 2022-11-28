#pragma once
#include "Object.h"


namespace Core
{
	namespace PrimitiveType
	{
		class O3DLIBRAIRY_API Boolean sealed : public Object
		{
#pragma region f/p
		private:
			bool value = false;
#pragma endregion f/p

#pragma region construtcor
		public:
			 Boolean() = default;
			 Boolean(const bool _value);
			 Boolean(const Boolean& _copy);
#pragma endregion constructor

#pragma region override
		public:
			 FString ToString() const override;
#pragma endregion override

#pragma region operator
		public:
			Boolean operator==(const Boolean& _other) const;
			Boolean operator!=(const Boolean& _other) const;
			operator bool() const;
			Boolean operator!() const;
#pragma endregion operator
		};
	}
}

