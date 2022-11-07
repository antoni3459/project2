#include "Vector4.h"

Vector4::Vector4(float _x, float _y, float _z, float _w)
{
	vectorx = _x;
	vectory = _y;
	vectorz = _z;
	vectorw = _w;
}

Vector4::Vector4(const Vector4& _copy)
{
	vectorx=_copy.vectorx;
		vectory = _copy.vectory;
		vectorz = _copy.vectorz;
		vectorw = _copy.vectorw;
}

Vector4::~Vector4()
{
		Clear();
}


float Vector4::ABS()
{
	return std::abs(vectorx), std::abs(vectory),std::abs(vectorz), std::abs(vectorw);
}


Vector4 Vector4::Add(float _x,float _y,float _z,float _w)
{
	vectorx += _x;
	vectory += _y;
	vectorz += _z;
	vectorw += _w;
}

Vector4 Vector4::Clamp(float _items)
{
	if (std::abs(vectorx) > _items || std::abs(vectory) > _items || std::abs(vectorz) > _items || std::abs(vectorw) > _items)
		throw std::out_of_range("c'est trop grand");
}

Vector4 Vector4::Min()
{
	for (int i =0; i<4; 
}

Vector4 Vector4::Max()
{
}

float Vector4::Lerp(float _t)
{

	float a = vectorx + vectory;
	float b = vectorz + vectorw;
	float t = a /(b - a);
	if (t == 0)
		return a;
	if (t == 1)
		return b;
	else
		return a, b;
}

float Vector4::Dot(float _x, float _y, float _z, float _w)
{
	float x = (vectorx + vectorz) * (vectory + vectorw);
	return x;
}

float Vector4::Magnitude()
{
	float x = vectorx - vectory;
	float y = vectorz - vectorw;
	return x, y;
}

float Vector4::Distance(float _vector)
{
	float x = vectorx - vectorz;
	float y = vectory - vectorw;
	float z = x + y;
	return z;
}

Vector4 Vector4::Set(float _x, float _y, float _z, float _w)
{
	vectorx = _x;
		vectory = _y;
		vectorz = _z;
		vectorw = _w;
}

float Vector4::Lenght()
{
	return 0.0f;
}

float Vector4::LenghtSquared()
{
	return 0.0f;
}

Vector4 Vector4::Normalize()
{
}

void Vector4::Clear()
{
	vectorx = 0.0f;
	vectory = 0.0f;
	vectorz = 0.0f;
	vectorw = 0.0f;
}
