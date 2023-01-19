#pragma once
#include "../../../Core/GameObject/GameObject.h"

namespace Game
{
	namespace Interfarce 
	{
		class IInteractable :public Core::GameObject
		{
			DECLARE_CLASS_INFO(IInteractable, GameObject)

		public:
			IInteractable();
			~IInteractable()override;

		public:
			virtual void OnInteract(class Player* _player) = 0;

		};
	}
}

