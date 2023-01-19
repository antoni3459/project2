#pragma once
#include "../../Core/GameObject/GameObject.h"
#include "../../Core/Gif/Gif.h"

namespace Game
{

	class Coin :public Core::GameObject
	{
		DECLARE_CLASS_INFO(Coin, GameObject)
	private:
		Core::Gif* gif = nullptr;

	public:
		Coin();
		Coin(const Coin&) = delete;
		~Coin()override;

	public:
		void OnUpdate();
		void OnCollisionEnter(GameObject* _object)override;

	};
}

