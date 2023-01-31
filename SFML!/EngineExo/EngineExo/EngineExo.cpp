#include <iostream>
#include <SFML/Graphics.hpp>
#include "Test/Reflection/ReflectionTest.h"
#include "Engine/PrimaryType/FString/String.h"
#include "Engine/PrimaryType/Boolean/Boolean.h"
#include "Engine/Utils/DebugMacro.h"
#include "Test/List/ListTest.h"
#include "Engine/Utils/Console/Console.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"
#include "Test/Component/PlayerComponent.h"
#include "Test/Reflection/Json/JsonTest.h"

int main(int argc, char* argv[])
{
    Test::JsonTest::Test();
    //Engine::GameObject* object = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "circle");
    //object->SetColor(sf::Color::Blue);
    //object->AddComponent<Test::PlayerComponent>();
    //Engine::Window::EngineWindow::Instance()->Open();
    //Engine::Manager::GameObjectManager::Instance()->Destroy();

    return 0;
}