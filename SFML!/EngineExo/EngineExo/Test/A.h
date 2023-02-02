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
	private:
		UPROPERTY() Engine::PrimaryType::List<Engine::PrimaryType::String> classes = { "Giusy","Romain","Benoit","Pierre-Louis" };
REGISTER_FIELD(classes, &classes, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Integer age = 20;
REGISTER_FIELD(age, &age, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Float f = 50.f;
REGISTER_FIELD(f, &f, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Vector2 vector2 = Engine::PrimaryType::Vector2(5,6);
REGISTER_FIELD(vector2, &vector2, BindingFlags::NoPublic)


	};
}

