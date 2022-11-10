#pragma once
#include <string>

#define Epsilon 0.0001

class Vector4
{
#pragma region f/p

private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	float w = 0.0f;
public:
	static const Vector4 Zero;
	static const Vector4 One;
	const float magnitude = Magnitude(*this);
#pragma endregion f/p

#pragma region constructor

public:
	Vector4(const float _x, const float _y, const float _z, const float _w);
	Vector4(const float _x, const float _y, const float _z);
	Vector4(const float _x, const float _y);
	Vector4(const float _value);
	Vector4(const Vector4& _copy);
#pragma endregion constructor

#pragma region method
public:
	std::string ToString();
	/// <summary>
	/// returns a vectors that is made from the absolute components
	/// </summary>
	/// <param name="_value">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Abs(const Vector4& _value);
	/// <summary>
	/// returns a vectors that is made from the absolute components
	/// </summary>
	/// <param name="_value">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Min(const Vector4& _a, const Vector4 _b);
	/// <summary>
	/// returns  a vectors that is made from larget componements of two vectors
	/// </summary>
	/// <param name="_a">vector</param>
	/// <param name="_b">vector</param>
	/// <returns>Vector4</returns>
	static Vector4 Max(const Vector4& _a, const Vector4 _b);
	/// <summary>
	/// Linearly intepolates between two vetors.
	/// </summary>
	/// <param name="_a">begin</param>
	/// <param name="_b">end</param>
	/// <param name="_t">time</param>
	/// <returns>Vector4</returns>
	static Vector4 Lerp(const Vector4& _a, const Vector4 _b, const float _t);
	/// <summary>
	/// Linearly intepolates between two vetors without clamping the interpolant.
	/// </summary>
	/// <param name="_a">begin</param>
	/// <param name="_b">end</param>
	/// <param name="_t">time</param>
	/// <returns>Vector4</returns>
	static Vector4 LerpUnclamped(const Vector4& _a, const Vector4& _b, const float _t);
	/// <summary>
	/// Dot product of two vector
	/// </summary>
	/// <param name="_a">vector</param>
	/// <returns></returns>
	static float Dot(const Vector4& _a, const Vector4& _b);
	/// <summary>
	/// return the lenght of vector
	/// </summary>
	/// <param name="_a">vector</param>
	/// <returns></returns>
	static float Magnitude(const Vector4& _value);
	/// <summary>
	/// return distance betweend a and b
	/// </summary>
	/// <param name="_a">vector</param>
	/// <returns></returns>
	static float Distance(const Vector4& _a, const Vector4& _b);

	float Length() const;
	float LengthSquared()const;
	/// <summary>
	/// Set components of the vector.
	/// </summary>
	/// <param name="_x"></param>
	/// <param name="_y"></param>
	/// <param name="_z"></param>
	/// <param name="_w"></param>
	void Set(const float _x, const float _y, const float _z, const float _w);
	static Vector4 Clamp(const Vector4& _current, const Vector4& _min, const Vector4& _max);
	/// <summary>
	/// Normalize vector between 0 and 1
	/// </summary>
	void Normalize();
#pragma endregion method

#pragma region operator 
public:
	float& operator[](const int _index);
	bool operator>(const Vector4& _other)const;
	bool operator>=(const Vector4& _other);
	bool operator<(const Vector4& _other)const;
	bool operator<=(const Vector4& _other);
	Vector4 operator+(const Vector4& _other)const;
	Vector4 operator+=(const Vector4& _other);
	Vector4 operator-(const Vector4& _other)const;
	Vector4 operator-=(const Vector4& _other);
	Vector4 operator*(const Vector4& _other)const;
	Vector4 operator*=(const Vector4& _other);
	Vector4 operator/(const Vector4& _other)const;
	Vector4 operator/=(const Vector4& _other);
	bool operator==(const Vector4& _other)const;
	bool operator!=(const Vector4& _other)const;
	Vector4 operator-();
	Vector4 operator=(const Vector4& _other);

#pragma endregion operator 
};

