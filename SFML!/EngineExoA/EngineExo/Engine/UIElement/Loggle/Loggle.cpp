#include "Loggle.h"
#include <iostream>

Engine::UI::Loggle::Loggle(int _x,int _posX,int _posY) :super()
{
	rectangle = new sf::RectangleShape(sf::Vector2f(_x,_x));
	rectangle->setFillColor(sf::Color::Transparent);
	rectangle->setOutlineThickness(2);
	rectangle->setOutlineColor(sf::Color::White);
	rectangle->setPosition(sf::Vector2f(_posX, _posY));

	line1 = new sf::RectangleShape(sf::Vector2f(_x + 10, 5));
	line1->setPosition(sf::Vector2f(_posX, _posY));
	line1->rotate(57);

	line2 = new sf::RectangleShape(sf::Vector2f(_x-27, 5));
	line2->setPosition(sf::Vector2f(_posX + (_x + 10) / 2, _posY+ _x));
	line2->rotate(310);
}

Engine::UI::Loggle::Loggle(const Loggle& _copy)
{
	rectangle = _copy.rectangle;
	line1 = _copy.line1;
	line2 = _copy.line2;
}

Engine::UI::Loggle::~Loggle()
{
	delete rectangle;
	rectangle = nullptr;
	delete line1;
	line1=nullptr;
	delete line2;
	line2=nullptr;
}

bool Engine::UI::Loggle::Active()
{
	sf::FloatRect positionCirlce = rectangle->getGlobalBounds();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (positionCirlce.contains(GetMousePosition()))
		{
			return true;
		}
	}
	return false;
}

void Engine::UI::Loggle::OnUpdate()
{
	if (Active())
	{
		isCheck = true;
		OnDraw();
	}
}

void Engine::UI::Loggle::OnDraw()
{
	Draw(rectangle);
	if(isCheck)
	{
		Draw(line1);
		Draw(line2);
	}
}


