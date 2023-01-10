#pragma once
#include "../../Object/Object.h"
#include <SFML/Graphics.hpp>

class GameObject : public Object
{
protected:
	sf::Drawable* drawable = nullptr;

public:
	GameObject();
	GameObject(const GameObject& _copy);
	~GameObject()override;
public:
	virtual void OnUpdate();
	virtual void OnDraw(class Window* _window);
	virtual void OnCollisionEnter(GameObject* _other);
	virtual sf::FloatRect GetGlobalBound()const=0;
	virtual sf::Vector2f Position() = 0;
};

