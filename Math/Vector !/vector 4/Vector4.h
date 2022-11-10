#pragma once
#include <vector >
#include <iostream>
#include <initializer_list>

class Vector4
{
#pragma region f/p
private :
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
#pragma endregion f/p

#pragma region constructor
public :
	Vector4() = default;
	Vector4(const float _x, const float _y, const float _z, const float _w);
	Vector4(const Vector4& _copy);
	~Vector4() = default;

#pragma endregion constructor

#pragma region method
public:
	float Lenght(Vector4* _a);
	float GetX();
	float GetY();
	float GetZ();
	float GetW();
	float ABS();
	Vector4 Add(float _x, float _y, float _z, float _w);
	Vector4 Clamp(float _items);
	Vector4 Min(Vector4 _a, Vector4 _b);
	Vector4 Max(Vector4 _a, Vector4 _b);
	Vector4* Lerp(Vector4* _a, Vector4* _b);
	float Dot(Vector4* _a, Vector4* _b);
	float Magnitude(Vector4* _a);
	float Distance(Vector4* _a,Vector4* _b);
	Vector4 Set(float _x, float _y, float _z, float _w);
	float LenghtSquared();
	Vector4 Normalize();
	void Display();
#pragma endregion method


#pragma region method
public:
	operator==();
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
	bool operator<(Vector4 vector);
	operator<=();
	operator[]();

#pragma region method

};

