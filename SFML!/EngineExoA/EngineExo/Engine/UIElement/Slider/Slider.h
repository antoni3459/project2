#pragma once
#include "../UIElement.h"
#include "../../PrimaryType/Vector2/Vector2.h"

namespace Engine::UI
{
	class Slider : public UIElement
	{
		DECLARE_CLASS_INFO(Slider, UIElement)

	private:
		sf::RectangleShape* line = nullptr;
		sf::CircleShape* circle = nullptr;
		float circleInt = 0;
		float lineInt = 0;
		sf::Vector2f posLine = sf::Vector2f();
		sf::Vector2f posCircle = sf::Vector2f();

	public:
		Slider(float _circleInt, float _lineInt, float x, float y);
		~Slider()override;

	public:
		bool Active();
		bool InLine();

	public:
		void OnUpdate() override;
		void OnDraw() override;
	};
}

