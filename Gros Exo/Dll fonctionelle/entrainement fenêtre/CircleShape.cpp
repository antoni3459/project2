#include "CircleShape.h"

Core::CircleShape::CircleShape(const Position& _position, const float _radius)
	: Shape(_position)
{
	radius = _radius;
}

void Core::CircleShape::Draw(HDC _hdc)
{
	Shape::Draw(_hdc);
	if (IsValid())return;
	Gdiplus::Rect _rect = Gdiplus::Rect(position.x, position.y, radius, radius);
	graphics->FillEllipse(new Gdiplus::SolidBrush(style.backgroundColor), _rect);
}

