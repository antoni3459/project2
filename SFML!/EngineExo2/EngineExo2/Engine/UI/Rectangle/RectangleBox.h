#pragma once
#include "../Element/UIElement.h"
#include <SFML/Graphics.hpp>

namespace Engine::UI
{
	UCLASS()
	class RectangleBox:public UIElement
	{
		DECLARE_CLASS_INFO(RectangleBox, UIElement)

	private:
		float width = 0.f;
		float height = 0.f;

	public:
		RectangleBox() = default;
		RectangleBox(float _width, float _height);

	public:
		void SetPosition(const PrimaryType::Vector2& _position) override;
		void Draw(sf::RenderWindow* _window) override;
	};
}

