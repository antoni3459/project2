#pragma once

class Quaternion
{
#pragma region f/p
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;

#pragma endregion f/p

#pragma region constructor
public:
	Quaternion() = default;
	Quaternion(const float _x, const float _y, const float _z, const float _w);
	Quaternion(const Quaternion& _copy);
	~Quaternion() = default;

#pragma endregion constructor

#pragma region method
public:
	float GetX();
	float GetY();
	float GetZ();
	float GetW();
	float Identity();
	float Negative();
	Quaternion Lerp(float _t);
	float Dot(Quaternion* _a, Quaternion* _b);
	float Length(Quaternion* _a);
	float LengthSquared(Quaternion* _a);
	float Conjugate();
	Quaternion Negate();
	Quaternion Angle();
#pragma endregion method




};

