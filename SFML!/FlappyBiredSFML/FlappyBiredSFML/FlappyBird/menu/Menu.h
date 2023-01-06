#pragma once
#include "../../Window/Window.h"

class Menu : public Window
{
	sf::Sprite* arriere = nullptr;
	sf::Sprite* start = nullptr;
	sf::Sprite* flappy = nullptr;
	sf::Sprite* score = nullptr;

	sf::Texture* texture = nullptr;
	sf::Texture* textureStart = nullptr;
	sf::Texture* textureFlappy = nullptr;
	sf::Texture* textureScore = nullptr;

	sf::Font* flapbird = nullptr;
	sf::Text* textFlapBird = nullptr;

public:
	Menu();
	~Menu()override;

public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;

};

