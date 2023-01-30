#include "GameObjectManager.h"

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
				Reflection::MethodInfo<void>* _method = _component->GetFunction<void>("Upate");
				if (_method == nullptr)continue;
				_method->Invoke(_component);
			}
		}
	}
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
