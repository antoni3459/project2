#include "Menu.h"

Menu::Menu()
{	
	arriere = new sf::Sprite();
	texture = new sf::Texture();

	start = new sf::Sprite();
	textureStart = new sf::Texture();

	flapbird = new sf::Sprite();
	textureFlapBird = new sf::Texture();

	if (!texture->loadFromFile("../FP/arriere.png")) return;
	arriere->setTexture(*texture);
	arriere->setScale(sf::Vector2f(1.9f, 1.4f));

	if (!textureFlapBird->loadFromFile("../FP/flapbird.png")) return;
	flapbird->setTexture(*textureFlapBird);
	flapbird->setScale(sf::Vector2f(3.f, 3.f));
	start->setPosition(550, 400);


	if (!textureStart->loadFromFile("../FP/start.png")) return;
	start->setTexture(*textureStart);
	start->setScale(sf::Vector2f(1.f, 1.f));
	start->setPosition(400, 900);


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
	Draw(flapbird);
	Draw(start);
}

void Menu::OnUpdate()
{
}
