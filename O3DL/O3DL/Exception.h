#pragma once
#include "Object.h"
#include "FString.h"
#include <source_location>

namespace Core
{
	class Exception : public Object
	{
#pragma region f/p
	private:
		Core::PrimitiveType::FString error = "";
#pragma endregion f/p

#pragma region constructor
	public:
		O3DLIBRAIRY_API Exception(const Core::PrimitiveType::FString& _error = "exception", const std::source_location& _location = std::source_location::current());
#pragma endregion constructor

#pragma region override
	public:
		O3DLIBRAIRY_API Core::PrimitiveType::FString ToString() const override;
#pragma endregion override
	};

	typedef Exception OutOfRangeException;
	typedef Exception DivideByZeroException;
}

