#pragma once

#include "../../Engine/Object/Object.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Interger/Interger.h"*
#include "../../Engine/Reflection/Function/Parameter/ParameterInfo.h"
#include <vector>

namespace Test
{
	class ReflectionTest :public Engine::Object
	{
	private:
		Engine::PrimaryType::String name = "toto";
		REGISTER_FIELD(name,&name,BindingFlags::NoPublic)

	public:
		Engine::PrimaryType::Interger age = 24;
		REGISTER_FIELD(age, &age, BindingFlags::Public)

		void Update();
		REGISTER_METHOD(Update, &ReflectionTest::Update, {}, BindingFlags::Public)

		void Display(const std::string& _msg);
		REGISTER_METHOD(Display, &ReflectionTest::Display, (std::vector{ new Engine::Reflection::ParameterInfo("_msg",0) }),BindingFlags::Public)

		static void Test();
	};
}