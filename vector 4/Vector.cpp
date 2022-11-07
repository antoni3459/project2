#include "Vector4.h"

Vector4::Vector4(const std::initializer_list<Vector4> _vector)
{
	count = _vector.size();
	vector = new Vector4[count];
}

Vector4::Vector4(const float _x, const float _y, const float _z, const float _w)
{
	
	vectorx = _x;
	vectory = _y;
	vectorz = _z;
	vectorw = _w;
}

Vector4::Vector4(const Vector4& _copy)
{
	vector = _copy.vector;
	vectorx=_copy.vectorx;
		vectory = _copy.vectory;
		vectorz = _copy.vectorz;
		vectorw = _copy.vectorw;
}

Vector4::~Vector4()
{
		Clear();
}


bool Vector4::FinOf()
{
	if (count < 1)
	{
		return false;
	}
	return true;

}

float Vector4::ABS()
{
	return std::abs(vectorx), std::abs(vectory),std::abs(vectorz), std::abs(vectorw);
}


Vector4 Vector4::Add(float _x,float _y,float _z,float _w)
{
	vectorx += _x;
	vectory += _y;
	vectorz += _z;
	vectorw += _w;
	Vector4* tmp = vector;
	vector = new Vector4();
	for (int i = 0; i < count; i++)
	{
		tmp[i] = vector[i];
	}
	vector[count] = Vector4(vectorx, vectory, vectorz, vectorw);
	count++;
	return  Vector4(vectorx, vectory, vectorz, vectorw);
}

Vector4 Vector4::Clamp(float _items)
{
	if (std::abs(vectorx) > _items || std::abs(vectory) > _items || std::abs(vectorz) > _items || std::abs(vectorw) > _items)
		throw std::out_of_range("c'est trop grand");
}

Vector4 Vector4::Min()
{
	for (int i =0; i<4; 
}

Vector4 Vector4::Max()
{
}

Vector4 Vector4::Lerp(float _t)
{
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
	Vector4(x, y, z, w) = vector[1];
	Vector4(vectorx, vectory, vectorz, vectorw) = vector[count];
	
	float a = x + y+z+w;
	float b = vectorx + vectory + vectorz + vectorw;
	float t = a /(b - a);
	if (t == 0)
		return vector[1];
	if (t == 1)
		return vector[count];
	else
		return vector[1], vector[count];
}

float Vector4::Dot()
{
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
	float a = 0;
	if (FinOf())
	{
		Vector4(x, y, z, w) = vector[1];
		Vector4(vectorx, vectory, vectorz, vectorw) = vector[count];
		a = (x + y + z + w) * (vectorx + vectory + vectorz + vectorw);
		return a;
		
	}
	else
	{
		throw std::out_of_range("pas assez de vecteur");
		return -1;
	}
}

float Vector4::Magnitude()
{
	float x = vectorx - vectory - vectorz - vectorw;
	return x;
}

float Vector4::Distance()
{
	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;
	float a = 0;
	if (FinOf())
	{
		Vector4(x, y, z, w) = vector[1];
		Vector4(vectorx, vectory, vectorz, vectorw) = vector[count];
		a = (x + y + z + w) - (vectorx + vectory + vectorz + vectorw);
		return a;
	}
	else
	{
		throw std::out_of_range("pas assez de vecteur");
		return -1;
	}
}
	

Vector4 Vector4::Set(float _x, float _y, float _z, float _w)
{
	vectorx = _x;
	vectory = _y;
	vectorz = _z;
	vectorw = _w;
	Vector4* tmp = vector;
	vector = new Vector4();
	for (int i = 0; i < count; i++)
	{
		tmp[i] = vector[i];
	}
	vector[count] = Vector4(vectorx, vectory, vectorz, vectorw);
	count++;
	return  Vector4(vectorx, vectory, vectorz, vectorw);
}

Vector4 Vector4::Lenght()
{
	return ;
}

float Vector4::LenghtSquared()
{
	return 0.0f;
}

Vector4 Vector4::Normalize()
{
}

void Vector4::Clear()
{
	delete vector;
	vector = nullptr;
	vectorx = 0.0f;
	vectory = 0.0f;
	vectorz = 0.0f;
	vectorw = 0.0f;
}
