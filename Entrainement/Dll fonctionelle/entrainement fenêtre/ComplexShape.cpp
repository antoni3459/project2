#include "ComplexShape.h"

Core::ComplexShape::ComplexShape(const std::vector<Gdiplus::PointF>& _points)
	:Shape({ 0,0 })
{
	points = _points;
}

void Core::ComplexShape::Draw(HDC _hdc)
{
	Shape::Draw(_hdc);
	if (!IsValid())return;
	graphics->FillPolygon(new Gdiplus::SolidBrush(style.backgroundColor), points.data(), points.size());
}


