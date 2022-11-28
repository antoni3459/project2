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

	class Shape
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
		O3DLIBRAIRY_API Shape() = default;
		O3DLIBRAIRY_API Shape(Position _position);
		O3DLIBRAIRY_API Shape(const Shape&) = default;
		O3DLIBRAIRY_API ~Shape();

#pragma endregion constructors

#pragma region methods
	public:
		O3DLIBRAIRY_API Style GetStyle();
		O3DLIBRAIRY_API Position& GetPositio();
		O3DLIBRAIRY_API bool IsValid()const;
		O3DLIBRAIRY_API void Init(HDC _hdc);
		O3DLIBRAIRY_API virtual void Draw(HDC _hdc);
#pragma endregion methods
	};
}

