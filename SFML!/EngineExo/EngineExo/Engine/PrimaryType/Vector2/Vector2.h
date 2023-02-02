#pragma once
#include "../ValueType/ValueType.h"
#include "../Float/Float.h"
#include "../Vector2/Vector2.h"
#include <SFML/System/Vector2.hpp>

namespace Engine::PrimaryType
{
	UCLASS()
	class Vector2:public ValueType
	{
		DECLARE_CLASS_INFO(Vector2, ValueType)

	private:
		UPROPERTY() Float x = 0.f;
REGISTER_FIELD(x, &x, BindingFlags::NoPublic)
		UPROPERTY() Float y = 0.f;
REGISTER_FIELD(y, &y, BindingFlags::NoPublic)

	public:
		Vector2() = default;
		Vector2(float _x, float _y);
		Vector2(const Vector2&)=default;

	public:
		static Vector2 MoveTowars(const Vector2& _current, const Vector2& _target, float _dt);

	public:
		String ToString()const override;
		void SerializeField(std::ostream& _os, const String& _fieldName, int _index)override;
		void DeSerializeField(std::istream& _os, const PrimaryType::String& _fieldName)override;

	public:
		operator sf::Vector2<float> ()const;
		Object& operator=(const Object* _obj);
		Vector2& operator=(const Vector2& _other);
		Vector2& operator+=(const Vector2& _other);
		Vector2& operator-=(const Vector2& _other);
		Vector2& operator*=(const Vector2& _other);
		Vector2& operator/=(const Vector2& _other);
		Vector2 operator+(const Vector2& _other)const;
		Vector2 operator-(const Vector2& _other)const;
		Vector2 operator*(const Vector2& _other)const;
		Vector2 operator/(const Vector2& _other)const;
		Boolean operator==(const Vector2& _other)const;
		Boolean operator!=(const Vector2& _other)const;
		Float& operator[](size_t _index);
		Float operator[](size_t _index)const;
	};
}
