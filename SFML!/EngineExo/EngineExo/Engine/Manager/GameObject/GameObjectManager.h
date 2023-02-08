#pragma once
#include "../../Utils/Singleton/Singleton.h"
#include "../../GameObject/GameObject.h"

namespace Engine
{
	class GameObject;
	namespace Window
	{
		class EngineWindow;
	}
}
namespace Engine::Manager
{
	class GameObjectManager:public Utils::Singleton< GameObjectManager>
	{
		DECLARE_CLASS_INFO(GameObjectManager, Singleton< GameObjectManager>)

#pragma region f/p
	private:
		std::vector<GameObject*> gameObjects = std::vector<GameObject*>();
#pragma endregion f/p

#pragma region constructeur
	public:
		GameObjectManager() = default;
		GameObjectManager(const GameObjectManager&) {}
#pragma endregion constructeur

#pragma region method
	public:
		void Register(GameObject* _object);
		void UnRegister(GameObject* _object);
		void Update()const;
		void Draw(const Engine::Window::EngineWindow* _window);
		void OnDestroy();
#pragma endregion method
	};
}

