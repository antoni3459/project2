#include "Button.h"
#include "Rect.h"
#include "Console.h"
#include <iostream>

Button::Button(const std::string& _content, Rect* _rect)
{
	content = _content;
		rect = _rect;
		Console::SetCursorPosition(_rect->X(), _rect->Y());
		std::cout << _content << std::endl;
}

Button::Button(const Button& _copy)
{
	content = _copy.content;
		rect = _copy.rect;
}

void Button::OnClick()
{
	std::cout << content << " on click ! " << std::endl;
}

Rect* Button::GetRect() const
{
	return rect;
}
