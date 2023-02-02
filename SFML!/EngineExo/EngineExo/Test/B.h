#pragma once
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Float/Float.h"
#include "../Engine/PrimaryType/Double/Double.h"
#include "../Engine/PrimaryType/FString/String.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
#include "../Engine/PrimaryType/Vector2/Vector2.h"
#include "../Engine/PrimaryType/List/List.h"
#include "C.h"

namespace Test
{
	UCLASS()
		class B:public Engine::Object
	{
	private:
		UPROPERTY() C c = C();
REGISTER_FIELD(c, &c, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Float mana = 105.015452f;
REGISTER_FIELD(mana, &mana, BindingFlags::NoPublic)
	};
}
