#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/FString/String.h"
#include <source_location>


namespace Engine
{
	UCLASS()
	class Exception : public Object
	{
		DECLARE_CLASS_INFO(Exception , Object)

	private:
		PrimaryType::String message = "";

	public:
		Exception(const std::source_location& _source = std::source_location::current());
		Exception(const char* _error, const std::source_location& _source = std::source_location::current());
		Exception(const Exception& _copy);

	public:
		PrimaryType::String Error() const;

	public:
		PrimaryType::String ToString() const override;
	};
}

