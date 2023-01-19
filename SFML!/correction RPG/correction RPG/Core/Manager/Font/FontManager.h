#pragma once
#include "../Base/BaseManager.h"
#include <SFML/Graphics/Font.hpp>

namespace Core
{
	namespace Manager
	{
		class FontManager:public BaseManager< FontManager, sf::Font>
		{
		public:
			void Init()override;
		};

	}
}

