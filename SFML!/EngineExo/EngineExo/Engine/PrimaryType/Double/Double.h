#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Double : ValueType
	{
		DECLARE_CLASS_INFO(Double, ValueType)

	private:
		float value = -1.0f;

	public:
		static const Double MinValue;
		static const Double MaxValue;
		static const Double Epsilon;
		static const Double NaN;
		static const Double PositiveInfinity;
		static const Double NegativeInfinity;

	public:
		Double() = default;
		Double(double _value);
		Double(const Double& _copy);

	public:
		static Double Parse(const String& _str);
		static class Boolean TryParse(const String& _str, Double& _output);
		static Boolean IsNaN(const Double& _value);
		static Boolean IsEpsilon(const Double& _value);
		static Boolean IsPositiveInfinity(const Double& _value);
		static Boolean IsNegativeInfinity(const Double& _value);


	public:
		String ToString() const override;


	public:
		Double& operator=(const Double& _other);
		operator double();
		operator double() const;
		Double operator+(double _other) const;
		Double operator-(double _other) const;
		Double operator*(double _other) const;
		Double operator/(double _other) const;
		Double operator-() const;

		Double& operator+=(double _other);
		Double& operator-=(double _other);
		Double& operator*=(double _other);
		Double& operator/=(double _other);

		Boolean operator<(double _other) const;
		Boolean operator<=(double _other) const;
		Boolean operator>(double _other) const;
		Boolean operator>=(double _other) const;
		Boolean operator==(double _other) const;
		Boolean operator!=(double _other) const;
	};

}
