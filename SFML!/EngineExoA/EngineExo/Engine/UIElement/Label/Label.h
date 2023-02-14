#pragma once
#include "../UIElement.h"

namespace Engine::UI
{
	class Label :public UIElement
	{
		DECLARE_CLASS_INFO(Label, UIElement)

	private:
		sf::Text* text = nullptr;
		sf::Font* font = nullptr;

	public:
		Label(const std::string _text, const int _height, const int _posX, const int _posY);
		~Label()override;

	public:
		void OnUpdate() override;
		void OnDraw() override;
	};
}

