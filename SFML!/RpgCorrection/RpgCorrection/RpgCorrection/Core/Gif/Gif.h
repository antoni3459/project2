#pragma once
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include <SFML/Graphics.hpp>

#include "../Object/Object.h"

namespace Core
{
    class Gif : public Object
    {
        DECLARE_CLASS_INFO(Gif, Object)
#pragma region f/p
    private:
        sf::Vector2i size = sf::Vector2i(0,0);
        sf::Clock clock = sf::Clock();
        sf::Time startTime = sf::Time();
        sf::Time totalDelay = sf::Time();
        std::vector<std::tuple<int, sf::Texture>> frames = std::vector<std::tuple<int, sf::Texture>>();
        std::vector<std::tuple<int, sf::Texture>>::iterator frameIterator;
#pragma endregion f/p
#pragma region constructor
    public:
        Gif() = delete;
        Gif(const char* _path);
#pragma endregion constructor
#pragma region methods
    public:
        void Update(sf::Sprite& _sprite);
        sf::Vector2i GetSize() const;
#pragma endregion methods
    };
}
