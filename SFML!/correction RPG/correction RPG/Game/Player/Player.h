#pragma once
#include "../../Core/GameObject/GameObject.h"
#include "../Entity/Entity.h"

namespace Game
{
	class Player:public Entity::Entity
	{
		DECLARE_CLASS_INFO(Player,Entity)

	private:
		float jumpForce = 100.0f;

	public:
		Player();
		Player(const Player& _copy);
		~Player();

	public:
		void OnUpdate();
		void OnCollisionEnter(GameObject* _object);
	};
}

