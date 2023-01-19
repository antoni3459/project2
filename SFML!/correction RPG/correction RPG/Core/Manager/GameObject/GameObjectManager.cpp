#include "GameObjectManager.h"
#include "../../GameObject/GameObject.h"
#include "../../Window/Window.h"
#include <ranges>

void Core::Manager::GameObjectManager::CheckCollision()
{
    for (GameObject* _a : gameObjects)
    {
        for (GameObject* _b : gameObjects)
        {
            if (_a == _b) continue;
            if (_a->GetGlobalBounds().intersects(_b->GetGlobalBounds()))
            {
                std::vector<GameObject*>& _collidedObject = _b->CollidedObject();
                if (std::ranges::find(_collidedObject, _a) == _collidedObject.end())
                {
                    _collidedObject.push_back(_a);
                    _b->OnCollisionEnter(_a);
                }
            }
            else
            {
                std::vector<GameObject*>& _collidedObject = _b->CollidedObject();
                const std::vector<GameObject*>::iterator& _index = std::ranges::find(_collidedObject, _a);
                if (_index != _collidedObject.end())
                {
                    _collidedObject.erase(_index);
                    _b->OnCollisionExit(_a);
                }
            }
        }
    }
}

void Core::Manager::GameObjectManager::DestroyGameObject(GameObject* _object)
{
    requestedDestroyObjects.push_back(_object);
}

void Core::Manager::GameObjectManager::Register(GameObject* _object)
{
    gameObjects.push_back(_object);
}

void Core::Manager::GameObjectManager::UnRegister(GameObject* _object)
{
    std::erase(gameObjects, _object);
}

void Core::Manager::GameObjectManager::DestroyAllRequest()
{
    for (GameObject* _object : requestedDestroyObjects)
    {
        delete _object;
        _object = nullptr;
    }
    requestedDestroyObjects.clear();
}

void Core::Manager::GameObjectManager::Update()
{
    CheckCollision();
    const std::vector<GameObject*> objects = gameObjects;
    for (GameObject* _object : objects)
        _object->OnUpdate();
}

void Core::Manager::GameObjectManager::Draw(Window* _window)
{
    CheckCollision();
    const std::vector<GameObject*> objects = gameObjects;
    for (GameObject* _object : objects)
        _object->Draw(_window);
}

void Core::Manager::GameObjectManager::OnDestroy()
{
    for (GameObject* _object : gameObjects)
    {
        if (_object == nullptr) continue;
        delete _object;
        _object = nullptr;
    }
    gameObjects.clear();
    requestedDestroyObjects.clear();
}