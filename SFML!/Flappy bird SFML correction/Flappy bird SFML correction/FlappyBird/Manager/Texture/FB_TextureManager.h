#pragma once
#include "../../../Singleton/Singleton.h"
#include <map>
#include <SFML/Graphics.hpp>

class FB_TextureManager : public Singleton< FB_TextureManager>
{
private:
	std::map<const char*, sf::Texture*>texture = std::map<const char*, sf::Texture*>();

public:
	FB_TextureManager() = default;

public:
	sf::Texture* Get(const char* _path);

	void Ondestroy();
};

