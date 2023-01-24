#pragma once
#include "../../Base/BaseSpell.h"

namespace Game
{

	namespace Spell
	{

		class FireBallSpell:public BaseSpell
		{
			DECLARE_CLASS_INFO(FireBallSpell, BaseSpell)
		private:

			Entity::Entity* owner = nullptr;

		public:
			FireBallSpell(Entity::Entity* _entity);

		public:
			void OnUse()override;
		};
	}
}

