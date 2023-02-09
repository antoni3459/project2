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

#pragma region f/p
	private:
		PrimaryType::String message = "";
#pragma endregion f/p

#pragma region constructor
	public:
		Exception(const std::source_location& _source = std::source_location::current());
		Exception(const char* _error, const std::source_location& _source = std::source_location::current());
#pragma endregion constructor

#pragma region method
	public:
		PrimaryType::String Error() const;
#pragma endregion method

#pragma region override
	public:
		PrimaryType::String ToString() const override;
#pragma endregion override
	};
}

