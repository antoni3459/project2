#pragma once
#include <vector >
#include <iostream>

class Vector
{
#pragma region f/p
private :
	float vectorx = 0.0f;
	float vectory = 0.0f;
	float vectorz = 0.0f;
	float vectorw = 0.0f;
#pragma region f/p

#pragma region constructor
public :
	Vector(float _x, float _y, float _z, float _w);
	Vector(const Vector& _copy);
	~Vector();

#pragma region constructor

#pragma region method
public:
	float ABS();
	Vector Add(float _x, float _y, float _z, float _w);
	Vector Clamp(float _items);
	Vector Min();
	Vector Max();
	Vector Lerp(float _t);
	float Dot(float _x, float _y, float _z, float _w);
	float Magnitude();
	float Distance(float _vector);
	Vector Set(float _x, float _y, float _z, float _w);
	float Lenght();
	float LenghtSquared();
	Vector Normalize();
	void Clear();
#pragma region method


#pragma region method
public:
	/*operator==();
	operator=();
	operator+();
	operator+=();
	operator-();
	operator-=();
	operator*();
	operator*=();
	operator/();
	operator/=();
	operator>();
	operator>=();
	operator<();
	operator<=();
	operator[]();*/

#pragma region method

};

