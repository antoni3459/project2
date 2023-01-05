#pragma once
#include "Window.h"

class WindowTest:public Window
{
	sf::RectangleShape* shape = nullptr;
	//sf::RectangleShape* shape1 = nullptr;
	sf::Text* text = nullptr;
	sf::Font* font = nullptr;
public:
	WindowTest();
	~WindowTest()override;

protected:
	virtual void OnDraw() override;

	virtual void OnUpdate() override;

};

