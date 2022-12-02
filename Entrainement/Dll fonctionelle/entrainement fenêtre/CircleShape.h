#pragma once
#include "Shape.h"
#include "FString.h"

namespace Core
{

    class CircleShape :public Shape
    {
#pragma region f/p

    private:
        float radius = 10.0f;

#pragma endregion f/p

#pragma region constructeur

    public:
        CircleShape(const Position& _position, const float _radius);
#pragma endregion constructeur

#pragma region method
    public:
        void Draw(HDC _hdc) override;

#pragma endregion method
    };
}
