#pragma once
#include "Object.h"


namespace Core
{
	namespace PrimitiveType
	{
		class Boolean sealed : public Object
		{
#pragma region f/p
		private:
			bool value = false;
#pragma endregion f/p
#pragma region construtcor
		public:
			O3DLIBRAIRY_API Boolean() = default;
			O3DLIBRAIRY_API Boolean(const bool _value);
			O3DLIBRAIRY_API Boolean(const Boolean& _copy);
#pragma endregion constructor
#pragma region override
		public:
			O3DLIBRAIRY_API FString ToString() const override;
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

