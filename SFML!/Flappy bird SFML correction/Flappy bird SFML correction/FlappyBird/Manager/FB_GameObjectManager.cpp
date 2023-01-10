#include "FB_GameObjectManager.h"
#include "../GameObject/GameObject.h"

void FB_GameObjectManager::CheckCollision()
{
    for (GameObject* _a : gameobject)
    {
        for (GameObject* _b : gameobject)
        {
             if (_a == _b || !_a->GetGlobalBound().contains(_b->Position())) continue;
            _b->OnCollisionEnter(_a);
        }
    }
}

void FB_GameObjectManager::Register(GameObject* _gameObject)
{
    gameobject.push_back(_gameObject);
}

void FB_GameObjectManager::UnRegister(GameObject* _gameObject)
{
    const size_t _size = gameobject.size();
    for (size_t i = 0; i < _size; i++)
    {
        if (gameobject[i] == _gameObject)
        {
            gameobject.erase(gameobject.begin() + 1);
            break;
        }
    }
}

void FB_GameObjectManager::Update()
{
    const size_t _size = gameobject.size();
    for (size_t i = 0; i < _size; i++)
    {
        gameobject[i]->OnUpdate();
    }
}

void FB_GameObjectManager::Destroy(GameObject* _gameObject)
{
    objectToDestroy.push_back(_gameObject);
}

void FB_GameObjectManager::DestroyAllRequest()
{
    for (GameObject* _object : objectToDestroy)
    {
        UnRegister(_object);
    }
    objectToDestroy.clear();
}

void FB_GameObjectManager::Draw(Window* _window)
{
    const size_t _size = gameobject.size();
    for (size_t i = 0; i < _size; i++)
    {
        gameobject[i]->OnDraw(_window);
    }
}

void FB_GameObjectManager::DestroyAllObject()
{
    for (GameObject* _object : objectToDestroy)
    {
        //std::erase(gameobject, _object);
        delete _object;
        _object = nullptr;
    }
    objectToDestroy.clear();
    gameobject.clear();
}

void FB_GameObjectManager::OnDestroy()
{
    const size_t _size = gameobject.size();
    for (size_t i = 0; i < _size; i++)
        delete gameobject[i];
    gameobject.clear();
}