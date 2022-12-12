#pragma once
#include "../../Object/Object.h"

struct Rect : Object
{
	DECLARE_CLASS_INFO(Object)

protected:
	int x = 0;
	int y = 0;
	int width = 0;
	int heigth = 0;

public:
	Rect() = default;
	Rect(int _x, int _y, int _width, int _heigth);
	Rect(const Rect& _copy);

public:
	int X()const;
	int Y()const;
	int Width()const;
	int Heigth()const;

};