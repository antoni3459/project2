#include "Vector4.h"

Vector4::Vector4(const float _x, const float _y, const float _z, const float _w)
{
	
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Vector4::Vector4(const Vector4& _copy)
{
	x=_copy.x;
		y = _copy.y;
		z = _copy.z;
		w = _copy.w;
}


float Vector4::Lenght(Vector4* _a)
{
	float a = _a->GetX() + _a->GetY() + _a->GetZ() + _a->GetW();
	return a;
}

float Vector4::GetX()
{
	return x;
}

float Vector4::GetY()
{
	return y;
}

float Vector4::GetZ()
{
	return z;
}

float Vector4::GetW()
{
	return w;
}

float Vector4::ABS()
{
	return std::abs(x), std::abs(y),std::abs(z), std::abs(w);
}


Vector4 Vector4::Add(float _x,float _y,float _z,float _w)
{
	x += _x;
	y += _y;
	z += _z;
	w += _w;
}

Vector4 Vector4::Min(Vector4 _a,Vector4 _b )
{
	x = _a.GetX() < _b.GetX() ? _a.GetX() : _b.GetX();
	y = _a.GetY() < _b.GetY() ? _a.GetY() : _b.GetY();
	z = _a.GetZ() < _b.GetZ() ? _a.GetZ() : _b.GetZ();
	w = _a.GetW() < _b.GetW() ? _a.GetW() : _b.GetW();
	Vector4 a = Vector4(x, y, z, w);
	return a;
}

Vector4 Vector4::Max(Vector4 _a, Vector4 _b)
{
	x = _a.GetX() > _b.GetX() ? _a.GetX() : _b.GetX();
	y = _a.GetY() > _b.GetY() ? _a.GetY() : _b.GetY();
	z = _a.GetZ() > _b.GetZ() ? _a.GetZ() : _b.GetZ();
	w = _a.GetW() > _b.GetW() ? _a.GetW() : _b.GetW();
	Vector4 a = Vector4(x, y, z, w);
	return a;
}

Vector4* Vector4::Lerp(Vector4* _a, Vector4* _b)
{
	float a = Lenght(_a);
	float b = Lenght(_b);
	float t = a / (b - a);
	if (t == 0)
		return _a;
	if (t == 1)
		return _b;
	else
		return _a, _b;
}

float Vector4::Dot(Vector4* _a, Vector4* _b)
{
	float a = (_a->GetX() + _a->GetY() + _a->GetZ() + _a->GetW()) * (_b->GetX() + _b->GetY() + _b->GetZ() + _b->GetW());
	return a;
}

float Vector4::Magnitude(Vector4* _a)
{
	float a = -Lenght(_a);
	return a;
}

float Vector4::Distance(Vector4* _a, Vector4* _b)
{
	return std::abs(_b->GetX() - _a->GetX()) + std::abs(_b->GetY() - _a->GetY()) + std::abs(_b->GetZ() - _a->GetZ()) + std::abs(_b->GetW() - _a->GetW());
}

Vector4 Vector4::Clamp(float _items)
{
	if (std::abs(x) > _items || std::abs(y) > _items || std::abs(z) > _items || std::abs(w) > _items)
		throw std::out_of_range("c'est trop grand");
}

Vector4 Vector4::Set(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

float Vector4::LenghtSquared(Vector4* _a)
{
	return Lenght( _a);
}

Vector4 Vector4::Normalize()
{

}


void Vector4::Display()
{
	std::cout << x << "\n" << y << "\n" << z << "\n" << w;
}


