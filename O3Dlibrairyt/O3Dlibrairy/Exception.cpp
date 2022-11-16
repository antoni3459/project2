#include "pch.h"
#include "Exception.h"
#include <format>



Core::Exception::Exception(const Core::PrimitiveType::FString& _error, const std::source_location& _location)
{
	error = std::format("{} in class {} in {} at {} line", _error.ToCstr(), _location.file_name(), _location.function_name(), _location.line()).c_str();
}


Core::PrimitiveType::FString Core::Exception::ToString() const
{
	return error;
}
