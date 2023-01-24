#pragma once

#include "../../Engine/Object/Object.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Interger/Interger.h"

namespace Test
{
	class ReflectionTest :public Engine::Object
	{
	private:
		Engine::PrimaryType::String name = "toto";
		REGISTER_FIELD(name,&name,BindingFlags::NoPublic)

	public:
		Engine::PrimaryType::Interger age = 54;
		REGISTER_FIELD(age, &age, BindingFlags::Public)

	public:
		static void Test();
	};
}