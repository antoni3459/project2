#pragma once
#include "../../Singleton/Singleton.h"
#include "../Game/FB_Game.h"
#include "../GameObject/GameObject.h"
#include <vector>

class FB_GameObjectManager :
    public Singleton< FB_GameObjectManager>
{
private:
    std::vector<GameObject*> gameobject = std::vector< GameObject*>();
    std::vector<GameObject*> objectToDestroy = std::vector<GameObject*>();

public:
    FB_GameObjectManager() = default;

public:
    void CheckCollision();

    void Register(GameObject* _gameObject);
    void UnRegister(GameObject* _gameObject);
    void Update();
    void Draw(class Window* _window);
    void Destroy(GameObject* _gameObject);
    void DestroyAllRequest();
    void DestroyAllObject();
private:
protected:
    void OnDestroy()override;
};

