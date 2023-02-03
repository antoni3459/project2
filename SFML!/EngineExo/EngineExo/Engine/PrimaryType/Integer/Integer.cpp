#include "Integer.h"
#include "../FString/String.h"
#include "../Boolean/Boolean.h"
#include "../../Utils/Template/Template.h"
#include <iostream>

const Engine::PrimaryType::Integer Engine::PrimaryType::Integer::MaxValue = INT_MAX;
const Engine::PrimaryType::Integer Engine::PrimaryType::Integer::MinValue = INT_MIN;

Engine::PrimaryType::Integer::Integer(int _value) : super()
{
    value = _value;
}

Engine::PrimaryType::Integer::Integer(const Integer& _copy) : super(_copy)
{
    value = _copy.value;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::Parse(const String& _str)
{
    return std::stoi((std::string)_str);
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::TryParse(const String& _str, Integer& _output)
{
	try
	{
		_output = std::stoi((std::string)_str);
		return true;
	}
	catch (...)
	{
		_output = -1;
		return false;
	}
}

Engine::PrimaryType::String Engine::PrimaryType::Integer::ToString() const
{
	return std::to_string(value).c_str();
}

void Engine::PrimaryType::Integer::SerializeField(std::ostream& _os, const String& _fieldName, int _index)
{
	Reflection::ReflectionUtils::SerializePrimaryType(_os, this, _fieldName);
}

void Engine::PrimaryType::Integer::DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName)
{
	String _str = Reflection::ReflectionUtils::GetLine(_is, _fieldName);
	_str = _str.Replace("\"", "").Replace("\t", "").Replace(",", "").Replace(_fieldName, "").Replace(":", "").Trim();
	*this = std::stoi(_str.ToCstr());
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator=(const Integer& _other)
{
	value = _other.value;
	return *this;
}

Engine::PrimaryType::Integer::operator int()
{
	return value;
}

Engine::PrimaryType::Integer::operator int() const
{
	return value;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator>(int _other) const
{
	return value > _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator<(int _other) const
{
	return value < _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator==(int _other) const
{
	return value == _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator!=(int _other) const
{
	return value != _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator>=(int _other) const
{
	return value >= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Integer::operator<=(int _other) const
{
	return value <= _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator+(int _other) const
{
	return value + _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator-(int _other) const
{
	return value - _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator*(int _other) const
{
	return value * _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator/(int _other) const
{
	return value / _other;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator%(int _other) const
{
	return value % _other;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator/=(int _other)
{
	value /= _other;
	return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator*=(int _other)
{
	value *= _other;
	return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator+=(int _other)
{
	value += _other;
	return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator-=(int _other)
{
	value -= _other;
	return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator%=(int _other)
{
	value %= _other;
	return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator++()
{
	value++;
	return *this;
}

Engine::PrimaryType::Integer& Engine::PrimaryType::Integer::operator--()
{
	value--;
	return *this;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator++(int)
{
	const int _result = value;
	operator++();
	return _result;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator--(int)
{
	const int _result = value;
	operator--();
	return _result;
}

Engine::PrimaryType::Integer Engine::PrimaryType::Integer::operator-()
{
	return -value;
}

Engine::Object& Engine::PrimaryType::Integer::operator=(const Object* _obj)
{
	if (!IsSame<Integer>(_obj)) return *this;
	super::operator=(_obj);
	const Integer* _int = dynamic_cast<const Integer*>(_obj);
	value = _int->value;
	return *this;
}
