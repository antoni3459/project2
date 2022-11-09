#include "Quaternion.h"
#include <cmath>
#include <format>
#include <iostream>

#pragma region constructeur 
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

#pragma endregion constructeur 

#pragma region method
float Quaternion::Dot(const Quaternion& _a,const Quaternion& _b)
{
    return _a.x * _b.x + _a.y * _b.y + _a.z * _b.z + _a.w * _b.w;
}

Quaternion Quaternion::Identity(const Quaternion& _a)
{
    return _a;
}

float Quaternion::Normalize(Quaternion& _a)
{
    return x/Length(_a),y/Length(_a),z/Length(_a),w/Length(_a) ;
}

Quaternion Quaternion::Inverse(const Quaternion& _a)
{
    return Quaternion (-_a.x,-_a.y,-_a.z,_a.w);
}

Quaternion Quaternion::Lerp(const Quaternion& _a, const Quaternion& _b, const float _t)
{
    return Quaternion(
        _a.x + (_b.x - _a.x) * _t,
        _a.y + (_b.y - _a.y) * _t,
        _a.z + (_b.z - _a.z) * _t,
        _a.w + (_b.w - _a.w) * _t);
}

float Quaternion::Length(const Quaternion& _a)
{
    return _a.x + _a.y + _a.z + _a.w;
}

float Quaternion::LengthSquared(const Quaternion& _a)
{
    return pow(Length(_a),2);
}

Quaternion Quaternion::Conjugate(Quaternion& _a)
{
    return Inverse(_a);
}

Quaternion Quaternion::Negate(const Quaternion& _a)
{
    return Quaternion (-x, -y, -z, -w);
}

float Quaternion::Angle(Quaternion& _a, Quaternion& _b)
{ 
    float b = Dot(_a, _b)/(Length(_a)* Length(_b));
    float a = acos(b);
    return a;
}


std::string Quaternion::ToString() const
{
    return std::format("{},{},{},{}", x, y, z, w);
}
#pragma endregion method

#pragma region operator

//
//float& Quaternion::operator[](const int _index)
//{
//
//}

bool Quaternion::operator==(const Quaternion& _other)
{
    return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}

bool Quaternion::operator!=(const Quaternion& _other) 
{
    return x != _other.x&& y != _other.y&& z != _other.z&& w != _other.w;;
}

Quaternion Quaternion::operator+(const Quaternion& _other)
{
    return Quaternion(x + _other.x, y + _other.y, z + _other.z, w + _other.w);
}

Quaternion Quaternion::operator-(const Quaternion& _other)
{
    return Quaternion(x - _other.x, y - _other.y, z - _other.z, w - _other.w);
}

Quaternion Quaternion::operator*(const Quaternion& _other)
{
    return Quaternion(x * _other.x, y * _other.y, z * _other.z, w * _other.w);
}

Quaternion Quaternion::operator/(const Quaternion& _other)
{
    return Quaternion(x / _other.x, y / _other.y, z / _other.z, w / _other.w);
}

Quaternion Quaternion::operator=(const Quaternion& _other)
{
    x = _other.x;
    y = _other.y;
    z = _other.z;
    w = _other.w;
    return *this;
}

Quaternion Quaternion::operator-()
{
    x = -x;
    y = -y;
    z = -z;
    w = -w;
    return *this;
}
#pragma endregion operator
