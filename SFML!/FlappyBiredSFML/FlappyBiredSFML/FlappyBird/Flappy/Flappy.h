#pragma once
#include "../../Window/Window.h"

class Flappy : public Window
{
private:
	sf::Sprite* flappy = nullptr;
	sf::Sprite* pipe = nullptr;
	sf::Texture* texture = nullptr;
	sf::Texture* texture1 = nullptr;
	//sf::Sprite* arriere = nullptr;
	//sf::Texture* texture2 = nullptr;
public:
	Flappy();
	~Flappy()override;

public:
	void Loose();

public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;

};

