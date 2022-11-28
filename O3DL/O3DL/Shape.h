#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include "Object.h"

#pragma comment(lib,"Gdiplus.lib")

namespace Core
{
	struct Position
	{
		float x;
		float y;
	};
	struct Style
	{
		Gdiplus::Color backroufColor = Gdiplus::Color::White;
	};

	class O3DLIBRAIRY_API Shape
	{
#pragma region f/p

	protected:
		Gdiplus::Pen* pen = nullptr;
		Gdiplus::Graphics* graphics = nullptr;
		Style style = Style();
		Position position = Position();
#pragma endregion f/p

#pragma region constructors

	public:
		 Shape() = default;
		 Shape(Position _position);
		 Shape(const Shape&) = default;
		 ~Shape();

#pragma endregion constructors

#pragma region methods
	public:
		 Style GetStyle();
		 Position& GetPositio();
		 bool IsValid()const;
		 void Init(HDC _hdc);
		 virtual void Draw(HDC _hdc);
#pragma endregion methods
	};
}

