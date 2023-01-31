#pragma once
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/PrimaryType/Float/Float.h"
#include "../Engine/PrimaryType/Double/Double.h"
#include "../Engine/PrimaryType/FString/String.h"
#include "../Engine/PrimaryType/Boolean/Boolean.h"
#include "../Engine/PrimaryType/Vector2/Vector2.h"


namespace Test
{
	UCLASS()
		class A : public Engine::Object
	{
	private:
		UPROPERTY() Engine::PrimaryType::Integer age = 0;
REGISTER_FIELD(age, &age, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Float f = 20.f;
REGISTER_FIELD(f, &f, BindingFlags::NoPublic)
		
		UPROPERTY() Engine::PrimaryType::Double Dooble = 10;
REGISTER_FIELD(Dooble, &Dooble, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::String name = "st";
REGISTER_FIELD(name, &name, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Boolean boolean = true;
REGISTER_FIELD(boolean, &boolean, BindingFlags::NoPublic)

		UPROPERTY() Engine::PrimaryType::Vector2 vector2 = Engine::PrimaryType::Vector2(5,6);
REGISTER_FIELD(vector2, &vector2, BindingFlags::NoPublic)

	};
}

