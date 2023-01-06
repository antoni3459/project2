#include "Menu.h"
#include "../game/Game.h"
#include <iostream>

Menu::Menu()
{	
	arriere = new sf::Sprite();
	texture = new sf::Texture();

	start = new sf::Sprite();
	textureStart = new sf::Texture();

	flappy = new sf::Sprite();
	textureFlappy = new sf::Texture();

	score = new sf::Sprite();
	textureScore = new sf::Texture();

	flapbird = new sf::Font();
	textFlapBird = new sf::Text();

	if (!texture->loadFromFile("../FP/arriere.png")) return;
	arriere->setTexture(*texture);
	arriere->setScale(sf::Vector2f(1.9f, 1.4f));

	if (!flapbird->loadFromFile("../font/Purple Smile.ttf")) return;
	textFlapBird->setFont(*flapbird);
	textFlapBird->setString("FLAPPY BIRD");
	textFlapBird->setFillColor(sf::Color::Yellow);
	textFlapBird->setCharacterSize(100);
	textFlapBird->setPosition(550, 250);

	if (!textureFlappy->loadFromFile("../FP/flappy.png")) return;
	flappy->setTexture(*textureFlappy);
	flappy->setScale(sf::Vector2f(0.6f, 0.6f));
	flappy->setPosition(700, 350);

	if (!textureStart->loadFromFile("../FP/start.png")) return;
	start->setTexture(*textureStart);
	start->setScale(sf::Vector2f(0.5f, 0.5f));
	start->setPosition(650, 700);

	if (!textureScore->loadFromFile("../FP/score.png")) return;
	score->setTexture(*textureScore);
	score->setScale(sf::Vector2f(0.8f, 0.8f));
	score->setPosition(1000, 700);
}

Menu::~Menu()
{
	delete arriere;
	arriere = nullptr;
	delete start;
	start = nullptr;
	delete texture;
	texture = nullptr;
	delete textureStart;
	textureStart = nullptr;
}

void Menu::OnDraw()
{
	Draw(arriere);
	Draw(textFlapBird);
	Draw(flappy);
	Draw(start);
	Draw(score);
}

void Menu::OnUpdate()
{
	
	sf::Vector2i mouseposition = sf::Mouse::getPosition(*window);
	sf::Vector2f _mouse = sf::Vector2f(mouseposition);

	sf::FloatRect positionStart = start->getGlobalBounds();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (positionStart.contains(_mouse))
		{
			Close();
			Game game = Game();
			game.Open();
		}
	}
}
