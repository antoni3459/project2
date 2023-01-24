#pragma once
#include <SFML/Graphics/Font.hpp>

#include "../Base/BaseManager.h"

namespace Core
{
    namespace Manager
    {
        class FontManager : public BaseManager<FontManager, sf::Font>
        {
            DECLARE_CLASS_INFO(FontManager, BaseManager)
        public:
            void Init() override;
        };
    }
}
