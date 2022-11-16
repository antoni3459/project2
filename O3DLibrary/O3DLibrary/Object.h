#pragma once
#include <iostream> 
#include "O3DLibrary.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}

	class Object
	{
#pragma region constructor 
	public:
		Object() = default;
		virtual ~Object() = default;

#pragma endregion constructor 

#pragma region method
	public:
		O3DLIBRARY_API virtual Core::PrimitiveType::FString ToString()const;

	};
#pragma endregion method
}
