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
#include "Engine/GameObject/GameObject.h"
#include "Engine/AssetDataBase/AssetDataBase.h"
#include "Engine/Utils/ObjectMacro.h"

int main(int argc, char* argv[])
{
    //Engine::GameObject* _gameObject = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "Test");
    //_gameObject->AddComponent<Test::PlayerComponent>();

    //Engine::AssetDataBase::CreateAsset(_gameObject, "Assets/test.asset");

    //Engine::Window::EngineWindow::Instance()->Open();
    //Engine::Manager::GameObjectManager::Instance()->Destroy();

    Test::JsonTest::Test();
    for (std::pair<std::string, Engine::Object*> _type : TypeOfData::Types)
    {
        std::cout << _type.first << std::endl;
    }
    return 0;
}