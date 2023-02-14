#include <filesystem>
#include <iostream>

#include "Engine/GameObject/GameObject.h"
#include "Engine/Window/Engine/EngineWindow.h"
#include "Test/Reflection/Json/JsonTest.h"
#include "Assembly.h"
#include "Engine/AssetDataBase/AssetDataBase.h"
#include "Engine/Manager/FontManager.h"
#include "Engine/Manager/GameObject/GameObjectManager.h"

int main()
{
    Manager::FontManager::Instance()->Init();
    // Test::JsonTest::Test();
    // Engine::GameObject* _gameObject = Engine::GameObject::CreatePrimitive(PrimitiveType::Circle, "Test");
    // _gameObject->AddComponent<Test::PlayerComponent>();
    //
    // Engine::AssetDataBase::CreateAsset(_gameObject, "Assets/GameObjectTest.asset");
    
    Engine::Window::EngineWindow::Instance()->Open();

    
    Manager::GameObjectManager::Instance()->Destroy();
    Manager::FontManager::Instance()->Destroy();
    return 0;
}
