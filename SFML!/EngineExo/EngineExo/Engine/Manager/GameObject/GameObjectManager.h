#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include "../../GameObject/GameObject.h"

namespace Engine
{
	class GameObject;
}
namespace Engine::Manager
{
	class GameObjectManager:public Utils::Singleton< GameObjectManager>
	{
		DECLARE_CLASS_INFO(GameObjectManager, Singleton< GameObjectManager>)

	private:
		std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
	public:
		void Register(GameObject* _object);
		void UnRegister(GameObject* _object);
		void Update()const;
		void OnDestroy();
		
	};
}

