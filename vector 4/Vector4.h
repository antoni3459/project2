#pragma once
#include <vector >
#include <iostream>

class Vector4
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
	Vector4(float _x, float _y, float _z, float _w);
	Vector4(const Vector& _copy);
	~Vector4();

#pragma region constructor

#pragma region method
public:
	float ABS();
	Vector4 Add(float _x, float _y, float _z, float _w);
	Vector4 Clamp(float _items);
	Vector4 Min();
	Vector4 Max();
	Vector4 Lerp(float _t);
	float Dot(float _x, float _y, float _z, float _w);
	float Magnitude();
	float Distance(float _vector);
	Vector4 Set(float _x, float _y, float _z, float _w);
	float Lenght();
	float LenghtSquared();
	Vector4 Normalize();
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

