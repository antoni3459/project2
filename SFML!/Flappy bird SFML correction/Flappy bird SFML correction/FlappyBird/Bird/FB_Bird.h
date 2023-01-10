#pragma once
#include "../GameObject/GameObject.h"
#include "../../Event/Delegate/Delegate.h"
#include <SFML/Graphics.hpp>

#define BIRD_SCALE 0.15f
#define GRAVITY 0.5f
#define BIRD_SPEED_GRAVITY 350
#define BIRD_JUMP_FORCE 40

class FB_Bird :public GameObject
{
private:
	bool isDead = false;
	sf::Clock lastJumpTimer = sf::Clock();
	sf::Sprite* sprite = nullptr;
	sf::Texture* texture = nullptr;
	sf::Vector2f windowSize = sf::Vector2f();
public:
	Delegate<void> OnDie = nullptr;

public:
	FB_Bird();
	virtual ~FB_Bird()override;

public:
	void Die();
	void SetWindowSize(const sf::Vector2f& _size);
	virtual void OnUpdate()override;
	virtual void OnCollisionEnter(GameObject* _other)override;
	virtual sf::FloatRect GetGlobalBound() const override;
	virtual sf::Vector2f Position() override;
};

