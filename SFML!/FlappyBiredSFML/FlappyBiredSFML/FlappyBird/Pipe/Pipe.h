#pragma once
#include "../../Window/Window.h"

class Pipe : public Window
{
private:
	sf::Sprite* pipe = nullptr;
	sf::Texture* texture = nullptr;

public:
	Pipe();
	~Pipe()override;

public:
	virtual void OnDraw() override;
	virtual void OnUpdate() override;
};

