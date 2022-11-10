#include "Matrix.h"
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
	return std::format("({},{},{},{}\n{},{},{},{}\n{},{},{},{}\n{},{},{},{}", m11, m12, m13, m14,m21, m22, m23, m24,m31, m32, m33, m34,m41, m42, m43, m44);
}																			 

Matrix Matrix::CreateTranslation(float _x, float _y, float _z)				 
{
	return Matrix(
		m11, m12, m13, m14 + _x,
		m21, m22, m23, m24 + _y,
		m31, m32, m33, m34 + _z,
		m41, m42, m43, m44);
}

Matrix Matrix::CreateScale(float _x, float _y, float _z)
{
	return Matrix(
		m11*_x, m12, m13, m14,
		m21, m22*_y, m23, m24,
		m31, m32, m33*_z, m34,
		m41, m42, m43, m44);
}

Matrix Matrix::CreateRotationX(float _radians)
{
	return Matrix(
		m11, m12,            m13,           m14,
		m21, cos(_radians),  sin(_radians), m24,
		m31, -sin(_radians), cos(_radians), m34,
		m41, m42,            m43,           m44	
	);
}

Matrix Matrix::CreateRotationY(float _radians)
{
	return Matrix(
		cos(_radians), m12, -sin(_radians), m14,
		m21,           m22, m23,            m24,
		sin(_radians), m32, cos(_radians),  m34,
		m41,           m42, m43,            m44);
}
Matrix Matrix::CreateRotationZ(float _radians)
{
	return Matrix(cos(_radians),  sin(_radians), m13, m14,
				  -sin(_radians), cos(_radians), m23, m24,
				  m31,            m32,           m33, m34,
				  m41,            m42,           m43, m44);
}

Matrix Matrix::CreateOrthographie(float _width, float _heigt, float _nearPlane, float _farPlane)
{
	return Matrix(IdentityM);
}

Matrix Matrix::CreateFromQuaternion(Quaternion _quaternion)
{
	return Matrix(IdentityM);
}

Matrix Matrix::Lerp(Matrix _matrix1, Matrix _matrix2, float _a)
{
	return Matrix(IdentityM);
}
