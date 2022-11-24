#pragma once
#include "Shape.h"
#include "FString.h"

namespace Core
{

    class RectangleShape :public Shape
    {
    private:
        int width = 20,
            height = 10;

    public:
        O3DLIBRAIRY_API RectangleShape(Position _position, int  _width, int _height);

    public:
        O3DLIBRAIRY_API void Draw(HDC _hdc)override;

    };
}

