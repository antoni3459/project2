#pragma once
#include "Object.h"
#include "FString.h"
#include "BindingFlags.h"

namespace Core
{
	namespace PrimitiveType
	{
		class Boolean;
	}
	class FieldInfo :public Object
	{
#pragma region f/p

	private:
		PrimitiveType::FString name = "";
		object reflectObject = nullptr;
		BindingFlags flags = BindingFlags::Private;

#pragma endregion f/p

#pragma region constructeur 

	public:
		FieldInfo() = default;
		FieldInfo(const PrimitiveType::FString& _name, const object _reflectadObject, const int _mask);
		FieldInfo(const PrimitiveType::FString& _name, const object _reflectadObject);

#pragma endregion constructeur 

#pragma region method

	public:
		PrimitiveType::Boolean IsPublic()const;
		PrimitiveType::Boolean IsPrivate()const;
		PrimitiveType::Boolean IsStatic()const;
		PrimitiveType::Boolean IsConst()const;
		PrimitiveType::FString Name()const;
		BindingFlags Flags()const;
		object RefletdObject()const;

#pragma endregion method

#pragma region override 

	public:
		PrimitiveType::FString ToString()const override;
		Object& operator=(const Object* obj)override;

#pragma endregion override 

	};

}


