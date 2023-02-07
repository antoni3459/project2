#pragma once
#include "../ValueType/ValueType.h"
namespace Engine::PrimaryType
{
	UCLASS()
	class Float : public ValueType
	{
		DECLARE_CLASS_INFO(Float, ValueType)

	private:
		float value = -1.0f;

	public:
		static const Float MinValue;
		static const Float MaxValue;
		static const Float Epsilon;
		static const Float NaN;
		static const Float PositiveInfinity;
		static const Float NegativeInfinity;

	public:
		Float() = default;
		Float(float _value);
		Float(const Float& _copy);

	public:
		static Float Parse(const String& _str);
		static class Boolean TryParse(const String& _str, Float& _output);
		static Boolean IsNaN(const Float& _value);
		static Boolean IsEpsilon(const Float& _value);
		static Boolean IsPositiveInfinity(const Float& _value);
		static Boolean IsNegativeInfinity(const Float& _value);


	public:
		String ToString() const override;
		void SerializeField(std::ostream& _os, const String& _fieldName, int _index)override;
		void DeSerializeField(std::istream& _is, const String& _fieldName)override;

	public:
		Float& operator=(const Float& _other);
		operator float();
		operator float() const;
		Float operator+(float _other) const;
		Float operator-(float _other) const;
		Float operator*(float _other) const;
		Float operator/(float _other) const;
		Float operator-() const;

		Float& operator+=(float _other) ;
		Float& operator-=(float _other) ;
		Float& operator*=(float _other) ;
		Float& operator/=(float _other) ;

		Boolean operator<(float _other) const;
		Boolean operator<=(float _other) const;
		Boolean operator>(float _other) const;
		Boolean operator>=(float _other) const;
		Boolean operator==(float _other) const;
		Boolean operator!=(float _other) const;
	};
}

