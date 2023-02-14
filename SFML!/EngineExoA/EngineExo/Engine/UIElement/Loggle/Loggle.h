#pragma once
#include "../UIElement.h"

namespace Engine::UI
{
	class Loggle: public UIElement
	{
		DECLARE_CLASS_INFO(Loggle, UIElement)

	private:
		sf::RectangleShape* rectangle = nullptr;
		sf::RectangleShape* line1 = nullptr;
		sf::RectangleShape* line2 = nullptr;
		bool isCheck = false;

	public:
		Loggle(int _x, int _posX, int _posY);
		~Loggle()override;

	public:
		bool Active();

	public:
		void OnUpdate() override;
		void OnDraw() override;
	};
}
