#pragma once
#include "../UIElement.h"

namespace Engine::UI
{
	class TextField :public UIElement
	{
		DECLARE_CLASS_INFO(TextField, UIElement)
			
	private:
		sf::RectangleShape* rectangle = nullptr;
		sf::Text* text = nullptr;
		sf::Font* font = nullptr;

	public:
		TextField(const int _posX,const int _posY,const int _height);
		~TextField() override;

	public:
		bool Active();

	public:
		void OnUpdate() override;
		void OnDraw() override;

	};
}

