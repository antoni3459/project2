#pragma once
#include "../UIElement.h"

namespace Engine::UI
{
	class Slider : public UIElement
	{
		DECLARE_CLASS_INFO(Slider, UIElement)

	private:
		sf::PrimitiveType line = sf::PrimitiveType::Lines;
		sf::CircleShape* circle = nullptr;
		float circleInt = 0;
		float lineInt = 0;
		UIElement* posLins = nullptr;
		sf::Vector2f posCircle = sf::Vector2f(0,0);

	public:
		Slider();
		Slider(float _circleInt, float _lineInt);
		Slider(float _circleInt, float _lineInt, float x, float y);
		
	public:
		bool Active();


	public:
		void OnUpdate() override;
		void OnClear() const  override;
		void OnReciveEvent(const sf::Event& _event) const override;
	};
}

