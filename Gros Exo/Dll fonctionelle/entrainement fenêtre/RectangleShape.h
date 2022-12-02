#pragma once
#include "Shape.h"

namespace Core
{

    class RectangleShape :public Shape
    {
    private:
        int width = 20,
            height = 10;

    public:
        RectangleShape(Position _position, int  _width, int _height);

    public:
        void Draw(HDC _hdc)override;
    };
}

