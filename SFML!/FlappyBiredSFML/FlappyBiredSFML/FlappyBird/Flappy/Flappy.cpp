#include "Flappy.h"
#include "../../Input/Input.h"
#include "../../Time/Time.h"
#include <iostream>

Flappy::Flappy()
{
	flappy = new sf::Sprite();
	pipe = new sf::Sprite();
	texture = new sf::Texture();
	texture1 = new sf::Texture();

	//texture2 = new sf::Texture();
	//arriere = new sf::Sprite();
	//if (!texture2->loadFromFile("../FP/arriere.png")) return;
	//arriere->setTexture(*texture2);
	//arriere->setScale(sf::Vector2f(1.9f, 1.4f));


	if (!texture->loadFromFile("../FP/flappy.png")) return;
	flappy->setTexture(*texture);
	flappy->setScale(sf::Vector2f(0.3f, 0.3f));
	flappy->setPosition(600, 400);

	if (!texture1->loadFromFile("../FP/pipes.png")) return;
	pipe->setTexture(*texture1);
	pipe->setScale(sf::Vector2f(0.2f, 0.6f));
	pipe->setPosition(1300, 400);
}

Flappy::~Flappy()
{
	delete texture;
	texture = nullptr;
	delete flappy;
	flappy = nullptr;
	delete pipe;
	pipe = nullptr;
	//delete arriere;
	//arriere = nullptr;
}

void Flappy::Loose()
{
	sf::Font* font = nullptr;
	font = new sf::Font();
	
	sf::Text* text = nullptr;
	text = new sf::Text();

	if (!font->loadFromFile("../font/thundernova3d.ttf"))return;
	text->setFont(*font);
	text->setString("FP");
	text->setCharacterSize(24);
	Draw(text);

}

void Flappy::OnDraw()
{
	//Draw(arriere);
	Draw(flappy);
	Draw(pipe);
}

void Flappy::OnUpdate()
{
	float _deltatime = Time::deltaTime;
	const float _speed = 10.f;
	const float _speedpipe = 10.f;

	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		flappy->setPosition(flappy->getPosition() + sf::Vector2f(0, -50));
	}
	flappy->setPosition(flappy->getPosition() + sf::Vector2f(0, 10)*_deltatime*_speed);
	pipe->setPosition(pipe->getPosition() + sf::Vector2f(-10, 0)*_deltatime * _speedpipe);

	if (flappy->getGlobalBounds().intersects(pipe->getGlobalBounds()))
	{
		std::cout << "contact" << std::endl;
		Loose();
	}
}
