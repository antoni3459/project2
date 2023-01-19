#pragma once
#include "../Object/Object.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>

namespace Core
{
	class Gif : public Object
	{
		DECLARE_CLASS_INFO(Gif, Object)

	private:
		sf::Vector2i size = sf::Vector2i(0, 0);
		sf::Clock clock = sf::Clock();
		sf::Time startTime = sf::Time();
		sf::Time totalDelay = sf::Time();
		std::vector<std::tuple<int, sf::Texture>> frames = std::vector<std::tuple<int, sf::Texture>>();
		std::vector<std::tuple<int, sf::Texture>>::iterator frameIterator;

	public:
		Gif() = delete;
		Gif(const char* _path);

	public:
		void Update(sf::Sprite& _sprite);
		sf::Vector2i GetSize()const;


	};
}

