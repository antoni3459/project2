#include "Flappy.h"
#include "../../Input/Input.h"
#include "../../Time/Time.h"
#include <iostream>

void Flappy::MoveBird(sf::Sprite* _sprite, sf::RectangleShape* _etbox)
{
	_sprite->setPosition(_sprite->getPosition() + sf::Vector2f(0, -50));
	_etbox->setPosition(_etbox->getPosition() + sf::Vector2f(0, -50));

}



