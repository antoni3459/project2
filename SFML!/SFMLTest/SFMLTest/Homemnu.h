#pragma once
#include "Window.h"

class Homemnu : public Window
{
	sf::Sprite* spriteLifePotion = nullptr;
	sf::Sprite* spriteManaPotion = nullptr;
	sf::Sprite* spriteSamy = nullptr;
	sf::Sprite* spriteGoldenSeb = nullptr;
	sf::Sprite* spriteGoldenSeb2 = nullptr;
	sf::Sprite* spriteBackround = nullptr;

	sf::Sprite* buttonLifePotion = nullptr;
	sf::Sprite* buttonManaPotion = nullptr;

	sf::Sprite* message = nullptr;

	sf::Texture* textureLifePotion = nullptr;
	sf::Texture* textureManaPotion = nullptr;
	sf::Texture* textureSamy = nullptr;
	sf::Texture* textureGoldenSeb = nullptr;
	sf::Texture* textureGoldenSeb2 = nullptr;
	sf::Texture* textureBackround = nullptr;

	sf::Texture* textureLifePotionButtonLifePotion = nullptr;
	sf::Texture* textureManaPotionButtonLifePotion = nullptr;

	sf::Texture* textureMessage = nullptr;

	sf::Text* labelLifePotion = nullptr;
	sf::Text* labelManaPotion = nullptr;
	sf::Font* font = nullptr;

public:
	Homemnu();
	~Homemnu()override;

public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
};

