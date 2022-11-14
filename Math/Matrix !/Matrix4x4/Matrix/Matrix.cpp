#include "Matrix.h"
#include "../Mathf/Mathf.h"
#include "../AssertMacro/AssertMacro.h"
#include <format>
#include <cmath>
Matrix const Matrix::IdentityM = Matrix (1.0f,0.0f, 0.0f, 0.0f,
										 0.0f,1.0f, 0.0f, 0.0f,
										 0.0f, 0.0f, 1.0f, 0.0f,
										 0.0f, 0.0f, 0.0f, 1.0f);


Matrix::Matrix(const float _m11, const float _m12, const float _m13, const float _m14, 
	           const float _m21, const float _m22, const float _m23, const float _m24, 
			   const float _m31, const float _m32, const float _m33, const float _m34, 
			   const float _m41, const float _m42, const float _m43, const float _m44)
{
	m11 = _m11; m12 = _m12; m13 = _m13; m14 = _m14;
			    		    		    
	m21 = _m21; m22 = _m22; m23 = _m23; m24 = _m24;
			    		    		    
	m31 = _m31; m32 = _m32; m33 = _m33; m34 = _m34;
			    		    		    
	m41 = _m41; m42 = _m42; m43 = _m43; m44 = _m44;
}

Matrix::Matrix(const Matrix& _copy)
{
	m11 = _copy.m11; m12 = _copy.m12; m13 = _copy.m13; m14 = _copy.m14;
	
	m21 = _copy.m21; m22 = _copy.m22; m23 = _copy.m23; m24 = _copy.m24;
					 				  				   
	m31 = _copy.m31; m32 = _copy.m32; m33 = _copy.m33; m34 = _copy.m34;
					 				  				   
	m41 = _copy.m41; m42 = _copy.m42; m43 = _copy.m43; m44 = _copy.m44;
}

std::string Matrix::ToString()
{
	return std::format("{} , {} , {} , {}\n{} , {} , {} , {}\n{} , {} , {} , {}\n{} , {} , {} , {}", m11, m12, m13, m14,m21, m22, m23, m24,m31, m32, m33, m34,m41, m42, m43, m44);
}																			 

Matrix Matrix::CreateTranslation(const float _x, const float _y, const float _z)
{
	return Matrix(
		m11,      m12,      m13,      m14,
		m21,      m22,      m23,      m24,
		m31,      m32,      m33,      m34,
		m41 + _x, m42 + _y, m43 + _z, m44);
}

Matrix Matrix::CreateScale(const float _x, const float _y, const float _z)
{
	return Matrix(
		m11*_x, m12, m13, m14,
		m21, m22*_y, m23, m24,
		m31, m32, m33*_z, m34,
		m41, m42, m43, m44);
}

Matrix Matrix::CreateRotationX(const float _radians)
{
	return Matrix(
		m11, m12,            m13,           m14,
		m21, cos(_radians),  sin(_radians), m24,
		m31, -sin(_radians), cos(_radians), m34,
		m41, m42,            m43,           m44	
	);
}

Matrix Matrix::CreateRotationY(const float _radians)
{
	return Matrix(
		m11, m12,            m13,           m14,
		m21, cos(_radians),  sin(_radians), m24,
		m31, -sin(_radians), cos(_radians), m34,
		m41, m42,            m43,           m44);
}

Matrix Matrix::CreateRotationZ(const float _radians)
{
	return Matrix(m11, m12, m13, m14,
				  m21, cos(_radians), sin(_radians), m24,
				  m31, -sin(_radians), cos(_radians), m34,
				  m41,            m42,           m43, m44);
}

Matrix Matrix::CreateOrthographie(const float _width, const float _heigt, const float _nearPlane, const float _farPlane)
{
	return Matrix(
		(m11*2)/ _width,              m12,                                 m13,                           m14, 
		 m21,                         (m22*10) / (_nearPlane + _farPlane), m23,                           m24,
		 m31,                         m32,                                 1 / (_nearPlane - _farPlane),  m34,
		 m41,                         m42,                                 m43,                           m44);
}

Matrix Matrix::CreateFromQuaternion(Quaternion _quaternion)
{
	return Matrix(IdentityM);
}

Matrix Matrix::Lerp(Matrix _matrix1, Matrix _matrix2, float _a)
{
	float _x = Quaternion::GetX();
	float _y = Quaternion::GetY();
	float _z = Quaternion::GetZ();
	float _w = Quaternion::GetW();

	return Matrix(
		1 - (2 * Mathf::Pow(_y)) - (2 * Mathf::Pow(_z)), (2 * _x * _y) + (2 * _z * _w), (2 * _x * _z) - (2 * _y * _w), m14,
		(2 * _x * _y) - (2 * _z * _w), 1 - (2 * Mathf::Pow(_x)) - (2 * Mathf::Pow(_z)), (2 * _y * _z) + (2 * _x * _w), m24,
		(2 * _x * _z) + (2 * _y * _w), (2 * _y * _z) - (2 * _x * _w), 1 - (2 * Mathf::Pow(_x)) - (2 * Mathf::Pow(_y)), m34,
		m41, m42, m43, m44);
}

float Matrix::GetDeterminant()
{
	return m11*m22*m33*m44;
}

Matrix Matrix::operator+(const Matrix& _other) const
{
	return Matrix(
		m11 + _other.m11, m12 + _other.m12, m13+ _other.m13, m14+ _other.m14,
		m21 + _other.m21, m22 + _other.m22, m23+ _other.m23, m24+ _other.m24,
		m31 + _other.m31, m32 + _other.m32, m33 + _other.m33, m34 + _other.m34,
		m41 + _other.m41, m42 + _other.m42, m43 + _other.m43, m44 + _other.m44
	);
}

Matrix Matrix::operator-(const Matrix& _other) const
{
	return Matrix(
		m11 - _other.m11, m12 - _other.m12, m13 - _other.m13, m14 - _other.m14,
		m21 - _other.m21, m22 - _other.m22, m23 - _other.m23, m24 - _other.m24,
		m31 - _other.m31, m32 - _other.m32, m33 - _other.m33, m34 - _other.m34,
		m41 - _other.m41, m42 - _other.m42, m43 - _other.m43, m44 - _other.m44);
}

Matrix Matrix::operator*(const Matrix& _other) const
{
	return Matrix();
}

float& Matrix::operator[](const int _index)
{
	check(_index > 0 && _index < 4)
		switch (_index)
		{
		case 0:return x;
		case 1:return y;
		case 2:return z;
		case 3:return z;
		}
}
