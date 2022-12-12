#include "Rect.h"

Rect::Rect(int _x, int _y, int _width, int _heigth)
{
    x=_x;
    y = _y;
    width = _width;
    heigth = _heigth;
}

Rect::Rect(const Rect& _copy)
{
    x=_copy.x;
    y = _copy.y;
    width = _copy.width;
    heigth = _copy.heigth;
}

int Rect::X() const
{
    return x;
}

int Rect::Y() const
{
    return y;
}

int Rect::Width() const
{
    return width;
}

int Rect::Heigth() const
{
    return heigth;
}
