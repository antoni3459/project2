#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class String;
	class Boolean;

	UCLASS()
	class Integer : public ValueType
	{
		DECLARE_CLASS_INFO(Integer, ValueType)

#pragma region f/p
	private:
		int value = -1;

	public:
		static const Integer MinValue;
		static const Integer MaxValue;
#pragma endregion f/p

#pragma region constructor
	public:
		Integer() = default;
		Integer(int _value);
		Integer(const Integer& _copy);
#pragma endregion constructor

#pragma region method
	public:
		static Integer Parse(const String& _str);
		static class Boolean TryParse(const String& _str, Integer& _output);
#pragma endregion method

#pragma region override
	public:
		String ToString() const override;
		void SerializeField(std::ostream& _os, const String& _fieldName, int _index)override;
		void DeSerializeField(std::istream& _os, const PrimaryType::String& _fieldName)override;
#pragma endregion override

#pragma region operator
	public:
		Integer& operator=(const Integer& _other);
		operator int();
		operator int() const;
		Boolean operator>(int _other) const;
		Boolean operator<(int _other) const;
		Boolean operator==(int _other) const;
		Boolean operator!=(int _other) const;
		Boolean operator>=(int _other) const;
		Boolean operator<=(int _other) const;
		Integer operator+(int _other) const;
		Integer operator-(int _other) const;
		Integer operator*(int _other) const;
		Integer operator/(int _other) const;
		Integer operator%(int _other) const;
		Integer& operator/=(int _other);
		Integer& operator*=(int _other);
		Integer& operator+=(int _other);
		Integer& operator-=(int _other);
		Integer& operator%=(int _other);
		Integer& operator++();
		Integer& operator--();
		Integer operator++(int);
		Integer operator--(int);
		Integer operator-();
		Object& operator=(const Object* _obj) override;
#pragma endregion operator
	};
}

