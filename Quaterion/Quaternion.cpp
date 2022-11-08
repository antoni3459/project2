#include "Quaternion.h"

Quaternion::Quaternion(const float _x, const float _y, const float _z, const float _w)
{
    x=_x;
        y = _y;
        z = _z;
        w = _w;
}

Quaternion::Quaternion(const Quaternion& _copy)
{
    x = _copy.x;
        y = _copy.y;
        z = _copy.z;
        w = _copy.w;

}

float Quaternion::GetX()
{
    return x;
}

float Quaternion::GetY()
{
    return y;
}

float Quaternion::GetZ()
{
    return z;
}

float Quaternion::GetW()
{
    return w;
}

float Quaternion::Identity()
{
    return 0.0f;
}

float Quaternion::Negative()
{
    return -x,-y,-z,-w;
}

Quaternion Quaternion::Lerp(float _t)
{
    return Quaternion();
}

float Quaternion::Dot(Quaternion* _a, Quaternion* _b)
{
    return 0.0f;
}

float Quaternion::Length(Quaternion* _a)
{
    return 0.0f;
}

float Quaternion::LengthSquared(Quaternion* _a)
{
    return 0.0f;
}

float Quaternion::Conjugate()
{
    return 0.0f;
}

Quaternion Quaternion::Negate()
{
    return Quaternion();
}

Quaternion Quaternion::Angle()
{
    return Quaternion();
}
