#include "TextField.h"
#include <iostream>

Engine::UI::TextField::TextField(const int _posX, const int _posY, const int _height)
{
	rectangle = new sf::RectangleShape(sf::Vector2f(300, _height));
	rectangle->setFillColor(sf::Color::Transparent);
	rectangle->setOutlineThickness(2);
	rectangle->setOutlineColor(sf::Color::White);
	rectangle->setPosition(sf::Vector2f(_posX, _posY));

	font = new sf::Font();
	text = new sf::Text();

	if (!font->loadFromFile("../Font/Vogue.ttf")) return;
	text->setFont(*font);
	text->setString("Text");
	text->setCharacterSize(_height);
	text->setPosition(_posX, _posY);

}

Engine::UI::TextField::TextField(const TextField& _copy)
{
	rectangle = _copy.rectangle;
	text = _copy.text;
	font = _copy.font;
}

Engine::UI::TextField::~TextField()
{
	delete rectangle;
	rectangle = nullptr;
	delete text;
	text=nullptr;
	delete font;
	font=nullptr;
}

bool Engine::UI::TextField::Active()
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



void Engine::UI::TextField::OnUpdate()
{
	if (Active())
	{
		while(sf::Keyboard::Escape)
		{
			if (sf::Event::TextEntered)
			{
				char _text = sf::Event::TextEntered;
				text->setString(_text);
				std::cout << _text << std::endl;
				OnDraw();
			}
		}
	}
}

void Engine::UI::TextField::OnDraw()
{
	Draw(rectangle);
	Draw(text);
}
