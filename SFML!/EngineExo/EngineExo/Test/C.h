#pragma once
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Float/Float.h"
#include "../Engine/PrimaryType/Double/Double.h"
#include "../Engine/PrimaryType/FString/String.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
#include "../Engine/PrimaryType/Vector2/Vector2.h"
#include "../Engine/PrimaryType/List/List.h"

namespace Test
{
	UCLASS()
		class C :public Engine::Object
	{
	private:
		UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::Integer> integers = { 0,1,2,3,4,5,6,7,8,9 };
REGISTER_FIELD(integers, &integers, BindingFlags::NoPublic)

	};
}
