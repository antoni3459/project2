#pragma once
#include "Quaternion.h"
class Matrix4x4
{
#pragma region f/p
private:
	float m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44;
public:
	static const Matrix4x4 Identity;
#pragma endregion f/p

#pragma region constructeur 
public:
	Matrix4x4() = default;
	Matrix4x4(const float _m11, const float _m12, const float _m13, const float _m14,
		const float _m21, const float _m22, const float _m23, const float _m24,
		const float _m31, const float _m32, const float _m33, const float _m34,
		const float _m41, const float _m42, const float _m43, const float _m44);
	Matrix4x4(const Matrix4x4& _copy);

#pragma endregion constructeur 

public:
	static Matrix4x4 CreateTranslation(const float _x, const float _y, const float _z);
	static Matrix4x4 CreateScale(const float _x, const float _y, const float _z); 
	static Matrix4x4 CreateRotationX(const float _radians);
	static Matrix4x4 CreateRotationY(const float _radians);
	static Matrix4x4 CreateRotationZ(const float _radians);
	static Matrix4x4 CreateOrthographie(const float _width, const float _heigt, const float _nearPlane, const float _farPlane);
	static Matrix4x4 CreateFromQuaternion(Quaternion _quaternion);
	static Matrix4x4 CreateFromYawPitchRoll(const float _yaw, const float _pitch, const float _roll);
	static Matrix4x4 Lerp(Matrix4x4 _matrix1, Matrix4x4 _matrix2, float _a);
	static bool IsIdentity(const Matrix4x4 _matrix);
	float Determinant()const;

public:
	Matrix4x4 operator-() const;
	Matrix4x4 operator+(const Matrix4x4& _other)const ;
	Matrix4x4 operator-(const Matrix4x4& _other)const ;
	Matrix4x4 operator*(const Matrix4x4& _other)const  ;
	bool operator==(const Matrix4x4& _other) const ;
	bool operator!=(const Matrix4x4& _other)const  ;
};