#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"

#define PIPE_SPEED 250.f
#define GAP 150

class FB_Pipe :public GameObject
{
private:
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	bool passedBird = false;

public:
	Delegate<void> OnBirdPosition = nullptr;

public:
	FB_Pipe();
	~FB_Pipe();

public:
	void Rotate();
	void Move();
	void SetPosition(const sf::Vector2f& _position);

public:
	virtual sf::FloatRect GetGlobalBound() const override;
	virtual sf::Vector2f Position() override;
	void OnUpdate() override;
};

