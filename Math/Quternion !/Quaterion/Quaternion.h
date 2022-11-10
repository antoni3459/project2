#pragma once
#include <string>
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
	static float Dot(const Quaternion& _a,const Quaternion& _b);
	Quaternion Identity(const Quaternion& _a);
	float Normalize(Quaternion& _a);
	static Quaternion Inverse(const Quaternion& _a);
	static Quaternion Lerp(const Quaternion& _a, const Quaternion& _b, const float _t);
	static float Length(const Quaternion& _a);
	float LengthSquared(const Quaternion& _a);
	static Quaternion Conjugate(Quaternion& _a);
	static Quaternion Negate(const Quaternion& _a);
	static float Angle(Quaternion& _a, Quaternion& _b);
	std::string ToString()const ;
#pragma endregion method

#pragma region operator
public:
	/*float& operator[](const int _index);*/
	bool operator==(const Quaternion& _other);
	bool operator!=(const Quaternion& _other);
	Quaternion operator+(const Quaternion& _other);
	Quaternion operator-(const Quaternion& _other);
	Quaternion operator*(const Quaternion& _other);
	Quaternion operator/(const Quaternion& _other);
	Quaternion operator=(const Quaternion& _other);
	Quaternion operator-();
#pragma endregion operator

};

