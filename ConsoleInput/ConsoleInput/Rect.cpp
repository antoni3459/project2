#include "Rect.h"

Rect::Rect(const int _width, const int _height, const int _x, const int _y)
{
	width = _width;
	height = _height;
	x = _x;
	y = _y;
	xMax = _width + _x;
	yMax = _height + _y;
}

Rect::Rect(const Rect& _copy)
{
	width = _copy.width;
	height = _copy.height;
	x = _copy.x;
	y = _copy.y;
	xMax=_copy.xMax;
	yMax = _copy.yMax;
}

Rect::~Rect()
{
	width = 0;
	height=0;
	x=0;
	y = 0;

}

bool Rect::Contains(const int _x, const int _y)
{
	return (_x>=x) && (_x<xMax) && (_y>=y) && (_y<yMax);
}

int Rect::X() const 
{
	return x;
}

int Rect::Y() const 
{
	return y;
}


