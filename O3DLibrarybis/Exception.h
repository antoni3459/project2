#pragma once
#include "Object.h"
#include "FString.h"
#include <source_location>
namespace Core
{
	class Exception:public Object
	{
	private:
		Core::PrimitiveType::FString error = "";
		
	public:
		O3DLIBRARY_API Exception(const Core::PrimitiveType::FString& _error = "exception", const std::source_location& _locatio =std::source_location::current());

	public:
		O3DLIBRARY_API Core::PrimitiveType::FString ToString() const override;
	};
typedef Exception OutOfRangeException;
typedef Exception DivideByZeroException;
}
