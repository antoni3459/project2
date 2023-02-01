#include "Float.h"
#include "../FString/String.h"
#include "../Boolean/Boolean.h"

const Engine::PrimaryType::Float Engine::PrimaryType::Float::MinValue = -3.40282347E+38f;
const Engine::PrimaryType::Float Engine::PrimaryType::Float::MaxValue = 3.40282347E+38f;
const Engine::PrimaryType::Float Engine::PrimaryType::Float::Epsilon = 1.401298E-45f;
const Engine::PrimaryType::Float Engine::PrimaryType::Float::PositiveInfinity = (1e+300 * 1e+300);
const Engine::PrimaryType::Float Engine::PrimaryType::Float::NegativeInfinity = -PositiveInfinity;
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

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::TryParse(const String& _str, Float& _output)
{
	try
	{
		_output = std::stof(_str.ToCstr());
		return true;
	}
	catch (const std::exception&)
	{
		_output = NaN;
		return false;
	}
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::IsNaN(const Float& _value)
{
	return std::isnan(_value);
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::IsEpsilon(const Float& _value)
{
	return _value == Epsilon;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::IsPositiveInfinity(const Float& _value)
{
	return _value == PositiveInfinity;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Float::IsNegativeInfinity(const Float& _value)
{
	return _value == NegativeInfinity;
}

Engine::PrimaryType::String Engine::PrimaryType::Float::ToString() const
{
	if (IsNaN(*this)) return "NaN";
	if (IsPositiveInfinity(*this)) return "Positive Infinity";
	if (IsNegativeInfinity(*this)) return "Negative Infinity";
	return std::to_string(value).c_str();
}

void Engine::PrimaryType::Float::SerializeField(std::ostream& _os, const String& _fieldName)
{
	if (String::IsNullOrEmpty(_fieldName))
		_os << std::string("\"") + ToString().ToCstr() + "\":\"" + ToString().ToCstr() + "\"";
	else
		_os << std::string("\"") + _fieldName.ToString().ToCstr() + "\":\"" + ToString().ToCstr() + "\"";
}

void Engine::PrimaryType::Float::DeSerializeField(std::istream& _is, const String& _fieldName)
{
	std::string _line;
	while (std::getline(_is, _line))
	{
		if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
		{
			String _str = _line.c_str();
			_str = _str.SubString(_str.FindFirstOf(':'));
			_str = _str.SubString(_str.FindFirstOf('"') + 1, _str.FindLastOf('"')).Replace("\"", "");
			*this = std::stoi(_str.ToCstr());
			break;
		}
	}
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
	return value + _other;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator-(float _other) const
{
	return value - _other;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator*(float _other) const
{
	return value * _other;
}

Engine::PrimaryType::Float Engine::PrimaryType::Float::operator/(float _other) const
{
	return value / _other;
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

Engine::PrimaryType::Float& Engine::PrimaryType::Float::operator*=(float _other)
{
	value *= _other;
	return *this;
}

Engine::PrimaryType::Float& Engine::PrimaryType::Float::operator/=(float _other)
{
	value /= _other;
	return *this;
}


Engine::PrimaryType::Boolean Engine::PrimaryType::Float::operator<(float _other) const
{
	return value < _other;;
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
