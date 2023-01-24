#pragma once
#include <vector>

#include "../../Utils/Singleton/Singleton.h"

namespace Core
{
    class Window;
    class GameObject;
    namespace Manager
    {
        class GameObjectManager : public Utils::Singleton<GameObjectManager>
        {
            DECLARE_CLASS_INFO(GameObjectManager, Singleton<GameObjectManager>)
#pragma region f/p
        private:
            std::vector<GameObject*> gameobjects = std::vector<GameObject*>();
            std::vector<GameObject*> requestedDestroyObject = std::vector<GameObject*>();
#pragma endregion f/p
#pragma region methods
        private:
            void CheckCollision();
        public:
            void DestroyGameObject(GameObject* _item);
            void Register(GameObject* _item);
            void UnRegister(GameObject* _item);
            void DestroyAllRequest();
            void Update();
            void Draw(Window* _window);
            void OnDestroy() override;
#pragma endregion methods
            
        };
    }
}
