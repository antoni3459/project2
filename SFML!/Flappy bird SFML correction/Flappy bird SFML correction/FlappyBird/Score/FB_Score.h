#pragma once
#include "../../Object/Object.h"
#include "../../Window/Window.h"
#include <SFML/Graphics.hpp>

class FB_Score : public Object
{
private:
	Window* owner = nullptr;
	int score = 0;
	class FB_Label* scoreText = nullptr;

public:
	FB_Score(Window* _owner);
	virtual ~FB_Score()override;
public:
	int CurrentScroe()const;
	void UpdateScore();
	void Draw();
	void SetPosition(const sf::Vector2f& _position);
	void Reset();
};

