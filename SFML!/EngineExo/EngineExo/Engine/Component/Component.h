#pragma once
#include "../Object/Object.h"
#include "../PrimaryType/Boolean/Boolean.h"

namespace Engine
{
	class GameObject;

	UCLASS()
	class Component :public Object
	{
		DECLARE_CLASS_INFO(Component, Object)
	public:
		UPROPERTY() PrimaryType::Boolean enabled = true;
REGISTER_FIELD(enabled, &enabled, BindingFlags::Public)

	public:
		UPROPERTY() GameObject* gameobject = nullptr;
REGISTER_FIELD(gameobject, gameobject, BindingFlags::Public)

	public:
		Component() = default;
		Component(const Component&) = default;
		~Component()override = default;

	public:
		Object& operator=(const Object* _obj)override;
	};
}

