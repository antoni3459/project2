#pragma once
#include "../Game.h"
#include <SFML/Graphics.hpp>

class Pipe 
{
public:
	Pipe() = default;

public:
	bool Contact(sf::RectangleShape* _etbox,sf::Sprite* _sprite2);

};

