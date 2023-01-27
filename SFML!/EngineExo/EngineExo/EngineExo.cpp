#include <iostream>
#include <SFML/Graphics.hpp>
#include "Test/Reflection/ReflectionTest.h"
#include "Engine/PrimaryType/FString/String.h"
#include "Engine/PrimaryType/Boolean/Boolean.h"
#include "Engine/Utils/DebugMacro.h"

int main(int argc, char* argv[])
{
    Engine::PrimaryType::String str = "";
    try
    {
        Engine::PrimaryType::Boolean b = str.Invoke<Engine::PrimaryType::Boolean, const Engine::PrimaryType::String&>("IsNullOrEmpty", nullptr, Engine::PrimaryType::String(""));
        LOG(b)

    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}