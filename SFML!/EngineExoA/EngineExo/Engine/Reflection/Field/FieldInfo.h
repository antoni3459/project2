#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/FString/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../Flags/BindingFlags.h"
namespace Engine::Reflection
{
	UCLASS()
	class FieldInfo : public Object
	{
		DECLARE_CLASS_INFO(FieldInfo, Object)

#pragma region f/p
	private:
		Engine::PrimaryType::String name = "";
		Engine::Object* reflectedObject = nullptr;
		BindingFlags flags = BindingFlags::NoPublic;
#pragma endregion f/p

#pragma region constructor
	public:
		FieldInfo() = default;
		FieldInfo(const Engine::PrimaryType::String _name, Object* _reflectedObject, BindingFlags _flags);
#pragma endregion constructor

#pragma region method
	public:
		Engine::PrimaryType::Boolean IsPublic() const;
		Engine::PrimaryType::Boolean IsPrivate() const;
		Engine::PrimaryType::Boolean IsStatic() const;
		Engine::PrimaryType::Boolean IsArray() const;
		Engine::PrimaryType::Boolean IsReflectedClass() const;
		Engine::PrimaryType::String Name() const;
		Engine::Object* ReflectedObject() const;
		BindingFlags Flags() const;
#pragma endregion method

#pragma region override
	public:
		Engine::PrimaryType::String ToString() const override;
#pragma endregion override

#pragma region operator
	public:
		Object& operator=(const Object* _obj) override;
#pragma endregion operator
	};
}

