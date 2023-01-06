#include "Lose.h"
#include "../../Input/Input.h"
#include "../menu/Menu.h"

Lose::Lose()
{
	font = new sf::Font();
	text = new sf::Text();
	text2 = new sf::Text();

	textureArriere = new sf::Texture();
	arriere = new sf::Sprite();

	if (!textureArriere->loadFromFile("../FP/arriere.png")) return;
	arriere->setTexture(*textureArriere);
	arriere->setScale(sf::Vector2f(1.9f, 1.4f));

	if (!font->loadFromFile("../font/Purple Smile.ttf")) return;
	text->setFont(*font);
	text->setString("GAME OVER");
	text->setFillColor(sf::Color::Yellow);
	text->setCharacterSize(100);
	text->setPosition(650, 250);

	text2->setFont(*font);
	text2->setString("appuie sur espace pour quit");
	text2->setFillColor(sf::Color::White);
	text2->setCharacterSize(50);
	text2->setPosition(600, 600);
}

Lose::~Lose()
{
	delete font;
	font = nullptr;
	delete text;
	text = nullptr;
	delete text2;
	text2 = nullptr;
}

void Lose::OnDraw()
{	
	Draw(arriere);
	Draw(text);
	Draw(text2);
}

void Lose::OnUpdate()
{
	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		Close();
		Menu menu = Menu();
		menu.Open();
	}
}
