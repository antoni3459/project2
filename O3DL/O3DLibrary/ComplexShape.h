#pragma once
#include "Shape.h"
#include "FString.h"
#include <vector>

namespace Core
{
    class O3DLIBRAIRY_API ComplexShape : public Shape
    {
#pragma region f/p
    private:
        std::vector<Gdiplus::PointF> points = std::vector<Gdiplus::PointF>();

#pragma endregion f/p

#pragma region constructeur

    public:
        ComplexShape(const std::vector<Gdiplus::PointF>& _points);

#pragma endregion constructeur

#pragma region method

    public:
        void Draw(HDC _hdc);

#pragma endregion method

    };
}

