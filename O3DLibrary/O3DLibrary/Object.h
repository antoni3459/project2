#pragma once
#include "O3DLibrary.h"


namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	class Object
	{

#pragma region constructor/destructor
	public:
		Object() = default;
		virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
	public:
		O3DLIBRAIRY_API virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		O3DLIBRAIRY_API virtual Core::PrimitiveType::FString ToString() const;
#pragma endregion methods
	};
	//typedef Object* Object;
}



