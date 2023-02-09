#pragma once
#include "../Window/Window.h"
#include <SFML/Graphics.hpp>

namespace Engine::UI
{
	class UIElement : public Window::Window< UIElement>
	{
		DECLARE_CLASS_INFO(UIElement, Window< UIElement>)

	protected:
		float x = 0;
		float y = 0;
		sf::Vector2i mouse = sf::Vector2i();

	public:
		UIElement();
		UIElement(float _x, float _y);

	public:
		void Open();
		sf::Vector2f GetPosition()const;

		int GetPositionX()const;
		int GetPositionY()const;
		void SetPosition(int _x, int _y);
		sf::Vector2f GetMousePosition();
		
	public:
		void OnUpdate() override;
		void OnClear() const  override;
		void OnReciveEvent(const sf::Event& _event) const override;
	};
}

