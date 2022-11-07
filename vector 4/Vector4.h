#pragma once
#include <vector >
#include <iostream>
#include <initializer_list>

class Vector4
{
#pragma region f/p
private :
	float vectorx = 0.0f;
	float vectory = 0.0f;
	float vectorz = 0.0f;
	float vectorw = 0.0f;
	Vector4* vector = nullptr;
	int count = 0;
#pragma region f/p

#pragma region constructor
public :
	Vector4() = default;
	Vector4(const std::initializer_list<Vector4> _vector);
	Vector4(const float _x, const float _y, const float _z, const float _w);
	Vector4(const Vector4& _copy);
	~Vector4();

#pragma region constructor

#pragma region method
private :
	bool FinOf();
public:
	float ABS();
	Vector4 Add(float _x, float _y, float _z, float _w);
	Vector4 Clamp(float _items);
	Vector4 Min();
	Vector4 Max();
	Vector4 Lerp(float _t);
	float Dot();
	float Magnitude();
	Vector4 Distance();
	Vector4 Set(float _x, float _y, float _z, float _w);
	Vector4 Lenght();
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

