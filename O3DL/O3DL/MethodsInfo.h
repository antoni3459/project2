#pragma once
#include "Object.h"
#include "BindingFlags.h"
#include "FString.h"
#include "FieldInfo.h"
#include <map>

namespace Core
{
	class O3DLIBRAIRY_API MethodsInfo:public Object
	{
#pragma region f/p

	private:
		PrimitiveType::FString name = "";
		object reflectObject = nullptr;
		BindingFlags flags = BindingFlags::Public;
		std::map<const char*, MethodsInfo*> parametre = std::map<const char*, MethodsInfo*>();

#pragma endregion f/p

#pragma region constructor

	public:
		MethodsInfo() = default;
		MethodsInfo(const PrimitiveType::FString& _name, const object _reflectObject, std::map<const char*, MethodsInfo*> _parametre);

#pragma endregion constructor

#pragma region method

	public:
		PrimitiveType::Boolean IsPublic()const;
		PrimitiveType::Boolean IsPrivate()const;
		PrimitiveType::Boolean IsStatic()const;
		PrimitiveType::Boolean IsConst()const;
		PrimitiveType::FString Name()const;
		BindingFlags Flags()const;
		object RefletdObject()const;
		std::map<const char*, MethodsInfo*> Parametre()const;
#pragma endregion method

#pragma region operrator

	public:
		PrimitiveType::FString ToString()const override;
		Object& operator=(const Object* obj)override;

#pragma endregion operrator

	};
}
