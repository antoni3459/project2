#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include <vector>

namespace Core
{
    class Window;
    class GameObject;

    namespace Manager
    {
        class GameObjectManager : public Utils::Singleton< GameObjectManager>
        {
            DECLARE_CLASS_INFO(GameObjectManager, Utils::Singleton< GameObjectManager>)

        private:
            std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
            std::vector<GameObject*> requestedDestroyObjects = std::vector<GameObject*>();

        private:
            void CheckCollision();
        public:
            void DestroyGameObject(GameObject* _item);
            void Register(GameObject* item);
            void UnRegister(GameObject* item);
            void DestroyAllRequest();
            void Update();
            void Draw(Window* _window);
            void OnDestroy()override;

        };
    }
}

