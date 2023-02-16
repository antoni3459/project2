#pragma once
#include "../Element/UIElement.h"
#include <SFML/Graphics.hpp>

namespace Engine::UI
{
	class Rectangle:public UIElement
	{
		DECLARE_CLASS_INFO(Rectangle, UIElement)

	private:
		float width = 0.f;
		float height = 0.f;

	public:
		Rectangle() = default;
		Rectangle(float _width, float _height);

	public:
		void SetPosition(const PrimaryType::Vector2& _position) override;
		void Draw(sf::RenderWindow* _window) override;
	};
}

