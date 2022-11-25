#include "Shape.h"

Core::Shape::Shape(Position _position)
{
	position = _position;
}

Core::Shape::~Shape()
{
	delete pen;
	pen = nullptr;
	delete graphics;
	graphics = nullptr;
}

Core::Style Core::Shape::GetStyle()
{
	return style;
}

Core::Position& Core::Shape::GetPositio()
{
	return position;
}

bool Core::Shape::IsValid() const
{
	return pen != nullptr && graphics != nullptr;
}

void Core::Shape::Init(HDC _hdc)
{
	graphics = new Gdiplus::Graphics(_hdc);
	pen = new Gdiplus::Pen(style.backroufColor);
}

void Core::Shape::Draw(HDC _hdc)
{
	if (!IsValid()) Init(_hdc);
}
