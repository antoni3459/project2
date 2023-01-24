#include "Float.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "Float.h"

const Engine::PrimaryType::Float Engine::PrimaryType::Float::MinValue = -3.40282347E+38f;
const Engine::PrimaryType::Float Engine::PrimaryType::Float::MaxValue= 3.40282347E+38f;
const Engine::PrimaryType::Float Engine::PrimaryType::Float::Epsilon=1.401298E-45;
const Engine::PrimaryType::Float Engine::PrimaryType::Float::PositiveInfinity = (1e+300 * 1e+300);
const Engine::PrimaryType::Float Engine::PrimaryType::Float::NegativeInfinity= -PositiveInfinity;
const Engine::PrimaryType::Float Engine::PrimaryType::Float::NaN = 0.0f * PositiveInfinity;

Engine::PrimaryType::Float::Float(float _value)
{
	value = _value;
}

Engine::PrimaryType::Float::Float(const Float& _copy)
{
	value = _copy.value;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::Parse(const String& _str)
{
	return std::stof(_str.ToCstr());

}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::TryParse(const Engine::PrimaryType::String& _str, Engine::PrimaryType::Float _output)
{
	try
	{
		_output = std::stof(_str.ToCstr());
		return true;
	}
	catch (...)
	{
		_output = NAN;
		return false;
	}
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::IsNaN(const Float& _value)
{
	return std::isnan(_value);
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::IsPositiveInfinity(const Float& _value)
{
	return _value == PositiveInfinity;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::IsNegativeInfinity(const Float& _value)
{
	return _value == NegativeInfinity;
}

Engine::PrimaryType::String Engine::PrimaryType::Float::ToString()
{
	if (IsNaN(*this))return "NaN";
	if (IsPositiveInfinity(*this))return "Positive Infinity";
	if (IsNegativeInfinity(*this))return "Negative Infinity";

	return std::to_string(value).c_str();
}

Engine::PrimaryType::Float& Engine::PrimaryType::Float::operator=(const Float& _other)
{
	value = _other.value;
	return *this;
}

Engine::PrimaryType::Float::operator float()
{
	return value;
}

Engine::PrimaryType::Float::operator float() const
{
	return value;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator+(float _other) const
{
	return value+_other;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator-(float _other) const
{
	return value - _other;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator/(float _other) const
{
	return value / _other;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator*(float _other) const
{
	return value * _other;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator-() const
{
	return -value;
}

Engine::PrimaryType::Float& Engine::PrimaryType::Float::operator+=(float _other)
{
	value += _other;
	return *this;
}

Engine::PrimaryType::Float& Engine::PrimaryType::Float::operator-=(float _other)
{
	value -= _other;
	return *this;
}

Engine::PrimaryType::Float& Engine::PrimaryType::Float::operator/=(float _other)
{
	value /= _other;
	return *this;
}

Engine::PrimaryType::Float& Engine::PrimaryType::Float::operator*=(float _other)
{
	value *= _other;
	return *this;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::operator<(float _other) const
{
	return value < _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::operator<=(float _other) const
{
	return value <= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::operator>(float _other) const
{
	return value > _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::operator>=(float _other) const
{
	return value >= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::operator==(float _other) const
{
	return value == _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::operator!=(float _other) const
{
	return value != _other;
}

