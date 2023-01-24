#pragma once
#include <SFML/Graphics/Texture.hpp>

#include "../Base/BaseManager.h"

namespace Core
{
    namespace Manager
    {
        class TextureManager : public BaseManager<TextureManager, sf::Texture>
        {
            DECLARE_CLASS_INFO(TextureManager, BaseManager)
        public:
            void Init() override;
        };
    }
}
