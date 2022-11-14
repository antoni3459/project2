#pragma once
#include "../quaternion/Quaternion.h"
#include <string>
class Matrix
{
#pragma region f/p
private:
	float m11, m12, m13, m14, 
		  m21, m22, m23, m24, 
		  m31, m32, m33, m34,
		  m41, m42, m43, m44;
public:
	static const Matrix IdentityM;
#pragma endregion f/p

#pragma region constructeur 
public:
	Matrix(const float _m11, const float _m12, const float _m13, const float _m14, 
		   const float _m21, const float _m22, const float _m23, const float _m24, 
		   const float _m31, const float _m32, const float _m33, const float _m34, 
		   const float _m41, const float _m42, const float _m43, const float _m44);
	Matrix(const Matrix& _copy);

#pragma endregion constructeur 

public:
	std::string ToString();
	Matrix CreateTranslation(const float _x, const float _y, const float _z);
	Matrix CreateScale (const float _x, const float _y, const float _z);
	Matrix CreateRotationX(const float _radians);
	Matrix CreateRotationY(const float _radians);
	Matrix CreateRotationZ(const float _radians);
	Matrix CreateOrthographie(const float _width, const float _heigt, const float _nearPlane, const float _farPlane);
	Matrix CreateFromQuaternion(Quaternion _quaternion);
	Matrix Lerp(Matrix _matrix1, Matrix _matrix2, float _a);
	float GetDeterminant();

public:
	Matrix operator+(const Matrix& _other) const;
	Matrix operator-(const Matrix& _other) const;
	Matrix operator*(const Matrix& _other) const;
	float& operator[](const int _index);
};

