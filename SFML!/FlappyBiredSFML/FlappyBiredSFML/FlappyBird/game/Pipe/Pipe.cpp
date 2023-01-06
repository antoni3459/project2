#include "Pipe.h"
#include "../../../Time/Time.h"
#include <iostream>
#include <SFML/Graphics.hpp>

bool Pipe::Contact(sf::RectangleShape* _etbox, sf::Sprite* _sprite2)
{
	if (_etbox->getGlobalBounds().intersects(_sprite2->getGlobalBounds()))
	{
		return true;
	}
	return false;
}
