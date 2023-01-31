#pragma once
#include "../Component/Component.h"
#include "../PrimaryType/Vector2/Vector2.h"
#include <SFML/System/Vector2.hpp>

namespace Engine
{
	UCLASS()
	class Transform:public Component
	{
		DECLARE_CLASS_INFO(Transform, Component)

	public:
		UPROPERTY() PrimaryType::Vector2 position = PrimaryType::Vector2(0, 0);
REGISTER_FIELD(position, &position, BindingFlags::Public)
	};
}

