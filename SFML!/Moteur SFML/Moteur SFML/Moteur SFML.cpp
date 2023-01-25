#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine/Utils/Console/Console.h"
#include "Test/PrimaryType/Float/FloatTest.h"
#include "Engine/Utils/Template/Template.h"
#include "Engine/PrimaryType/Boolean/Boolean.h"
#include "Engine/Utils/DebugMacro.h"
#include "Test/Reflection/ReflectionTest.h"
#include "Test.h"

int main()
{
	////Engine::Utils::Console console = Engine::Utils::Console();
	//console.Log("vubvbi");
	Test::ReflectionTest test = Test::ReflectionTest();
	test.Test();

	//LOG(IsPointer<int>::Value);
	//LOG(IsPointer<int*>::Value);
}
