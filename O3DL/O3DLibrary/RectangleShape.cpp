#include "RectangleShape.h"

Core::RectangleShape::RectangleShape(Position _position, int _width, int _height)
	: Shape(_position)
{
	width = _width;
		height = _height;
}

void Core::RectangleShape::Draw(HDC _hdc)
{
	Shape::Draw(_hdc);
	if (!IsValid()) return;
	Gdiplus::SolidBrush brush(style.backroufColor);
	graphics->FillRectangle(&brush, Gdiplus::Rect(position.x, position.y, width, height));
}
