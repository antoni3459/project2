#pragma once
#include "../Window/Window.h"

class Menu : public Window
{
	sf::Sprite* arriere = nullptr;
	sf::Sprite* start = nullptr;
	sf::Sprite* flapbird = nullptr;

	sf::Texture* texture = nullptr;
	sf::Texture* textureStart = nullptr;
	sf::Texture* textureFlapBird = nullptr;

public:
	Menu();
	~Menu()override;

public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;

};

