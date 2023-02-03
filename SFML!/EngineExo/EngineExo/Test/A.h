#pragma once
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Float/Float.h"
#include "../Engine/PrimaryType/Double/Double.h"
#include "../Engine/PrimaryType/FString/String.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
#include "../Engine/PrimaryType/Vector2/Vector2.h"
#include "../Engine/PrimaryType/List/List.h"
#include "B.h"

namespace Test
{
	UCLASS()
		class A : public Engine::Object
	{
	public:
		UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::Integer> classes = { 1,2,4,5,6,8 };
REGISTER_FIELD(classes, &classes, BindingFlags::Public)

			UPROPERTY() Engine::PrimaryType::List<B*> blist = { new B(),new B(),new B() };
REGISTER_FIELD(blist, &blist, BindingFlags::Public)



	};
}

