#pragma once
#include <iostream> 
#include "O3DLibrary.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class boolean;
	}

	class Object
	{
#pragma region constructor 
	public:
		Object() = default;
		virtual ~Object()=default;

#pragma endregion constructor 

#pragma region method
	public:
		O3DLIBRARY_API virtual Core::PrimitiveType::FString ToString()const;
		O3DLIBRARY_API virtual Core::PrimitiveType::boolean Equals(const Object* _obj) const;
	};
#pragma endregion method
}

