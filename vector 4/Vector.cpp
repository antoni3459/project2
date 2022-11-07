#include "Vector.h"

Vector::Vector(float _x, float _y, float _z, float _w)
{
	vectorx = _x;
	vectory = _y;
	vectorz = _z;
	vectorw = _w;
}

Vector::Vector(const Vector& _copy)
{
	vectorx=_copy.vectorx;
		vectory = _copy.vectory;
		vectorz = _copy.vectorz;
		vectorw = _copy.vectorw;
}

Vector::~Vector()
{
		Clear();
}


float Vector::ABS()
{
	return std::abs(vectorx), std::abs(vectory),std::abs(vectorz), std::abs(vectorw);
}


Vector Vector::Add(float _x,float _y,float _z,float _w)
{
	vectorx += _x;
	vectory += _y;
	vectorz += _z;
	vectorw += _w;
}

Vector Vector::Clamp(float _items)
{
	if (std::abs(vectorx) > _items || std::abs(vectory) > _items || std::abs(vectorz) > _items || std::abs(vectorw) > _items)
		throw std::out_of_range("c'est trop grand");
}

Vector Vector::Min()
{
	for (int i =0; i<4; 
}

Vector Vector::Max()
{
}

float Vector::Lerp(float _t)
{

	float a = vectorx + vectory;
	float b = vectorz + vectorw;
	float L = a + (b - a);
	
}

float Vector::Dot(float _x, float _y, float _z, float _w)
{
	float x = (vectorx + vectorz) * (vectory + vectorw);
	return x;
}

float Vector::Magnitude()
{
	float x = vectorx - vectory;
	float y = vectorz - vectorw;
	return x, y;
}

float Vector::Distance(float _vector)
{
	float x = vectorx - vectorz;
	float y = vectory - vectorw;
	float z = x + y;
	return z;
}

Vector Vector::Set(float _x, float _y, float _z, float _w)
{
	vectorx = _x;
		vectory = _y;
		vectorz = _z;
		vectorw = _w;
}

float Vector::Lenght()
{
	return 0.0f;
}

float Vector::LenghtSquared()
{
	return 0.0f;
}

Vector Vector::Normalize()
{
}

void Vector::Clear()
{
	vectorx = 0.0f;
	vectory = 0.0f;
	vectorz = 0.0f;
	vectorw = 0.0f;
}
