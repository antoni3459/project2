#pragma once
#include "../Base/BaseManager.h"
#include <SFML/Graphics/Font.hpp>

namespace Core
{
    namespace Manager
    {
        class TextureManger :public BaseManager< TextureManger, sf::Texture>
        {
        public:
            void Init()override;
        };
    }
}

