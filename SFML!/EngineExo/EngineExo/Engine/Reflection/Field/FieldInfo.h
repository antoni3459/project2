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

	private:
		Engine::PrimaryType::String name = "";
		Engine::Object* reflectedObject = nullptr;
		BindingFlags flags = BindingFlags::NoPublic;

	public:
		FieldInfo() = default;
		FieldInfo(const Engine::PrimaryType::String _name, Object* _reflectedObject, BindingFlags _flags);


	public:

		Engine::PrimaryType::Boolean IsPublic() const;
		Engine::PrimaryType::Boolean IsPrivate() const;
		Engine::PrimaryType::Boolean IsStatic() const;
		Engine::PrimaryType::Boolean IsArray() const;
		Engine::PrimaryType::Boolean IsReflectedClass() const;
		Engine::PrimaryType::String Name() const;
		Engine::Object* ReflectedObject() const;
		BindingFlags Flags() const;

		virtual Object& operator=(const Object* _obj) override;

		Engine::PrimaryType::String ToString() const override;

	};
}

