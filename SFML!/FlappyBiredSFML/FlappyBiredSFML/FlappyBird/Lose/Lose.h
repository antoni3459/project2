#pragma once
#include "../../Window/Window.h"

class Lose : public Window
{
private:
	sf::Font* font = nullptr;
	sf::Text* text = nullptr;
	sf::Text* text2 = nullptr;
	sf::Sprite* arriere = nullptr;
	sf::Texture* textureArriere = nullptr;

public:
	Lose();
	~Lose()override;

public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
};

