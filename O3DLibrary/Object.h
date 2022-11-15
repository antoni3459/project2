#pragma once


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
		virtual ~Object()=default;

#pragma endregion constructor 

#pragma region method
	public:
		virtual Core::PrimitiveType::FString ToString()const;

	};
#pragma endregion method
}

