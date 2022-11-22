#pragma once
#include <vector>
#include "App.h"

class Rect
{
#pragma region f/p

private:
	int width = 0.0f,
		height = 0.0f,
		x = 0,
		y = 0;

	int xMax = 0;
	int yMax = 0;
#pragma endregion f/p

#pragma region constructeur

public:
	Rect() = default;
	Rect(const int _width, const int, const  int _x, const  int _y);
	Rect(const Rect& _copy);
	~Rect();
#pragma endregion constructeur

#pragma region method

public:
	bool Contains(const int _x, const int _y);
	int X()const;
	int Y()const;

#pragma endregion method


};