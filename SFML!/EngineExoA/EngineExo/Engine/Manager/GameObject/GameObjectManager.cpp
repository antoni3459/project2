#include "GameObjectManager.h"

Engine::Manager::GameObjectManager::GameObjectManager(const GameObjectManager& _copy) :super( _copy)
{
	gameObjects = _copy.gameObjects;
}

void Engine::Manager::GameObjectManager::Register(GameObject* _object)
{
	gameObjects.push_back(_object);
}

void Engine::Manager::GameObjectManager::UnRegister(GameObject* _object)
{
	std::erase(gameObjects, _object);
}

void Engine::Manager::GameObjectManager::Update() const
{
	for (GameObject* _gameobject : gameObjects)
	{
		for (Component* _component : _gameobject->Components())
		{
			if (_component->enabled)
			{
				Reflection::MethodInfo<void>* _method = _component->GetFunction<void>("Update");
				if (_method == nullptr)continue;
				_method->Invoke(_component);
			}
		}
	}
}

void Engine::Manager::GameObjectManager::Draw(const Engine::Window::EngineWindow* _window)
{
	for (const GameObject* _object : gameObjects)
		_object->Draw(_window);

}

void Engine::Manager::GameObjectManager::OnDestroy()
{
	for (GameObject*& _gameObject : gameObjects)
	{
		delete _gameObject;
		_gameObject = nullptr;
	}
	gameObjects.clear();
}
