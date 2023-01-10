#pragma once
#include "../../Object/Object.h"
#include "../../Window/Window.h"
#include <SFML/Graphics.hpp>

class FB_UIElement  :public Object
{
protected:
	bool isActive = false;
	Window* owner = nullptr;

public:
	FB_UIElement(Window* _owner);
	FB_UIElement(const FB_UIElement& _copy);
	~FB_UIElement()override;

public:
	virtual void SetPosition(const sf::Vector2f& _position) = 0;
	virtual void SetScale(const sf::Vector2f& _scale) = 0;
	virtual void Draw(Window* _window) = 0;
	virtual void SetOrigin(const sf::Vector2f& _origin) = 0;
	virtual void OnUpdate();
	virtual sf::FloatRect GetGlobalBound()const = 0;
	void SetActive(const bool _status);
};

