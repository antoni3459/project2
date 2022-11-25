#include "Interger.h"
#include "Exception.h"
#include <format>


Core::PrimitiveType::Integer Core::PrimitiveType::Integer::MaxValue()
{
	return std::numeric_limits<int>::max();
}

Core::PrimitiveType::Integer Core::PrimitiveType::Integer::MinValue()
{
	return std::numeric_limits<int>::min();
}

Core::PrimitiveType::Integer::Integer(const int _value)
{
	value = _value;
}

Core::PrimitiveType::Integer::Integer(const Integer& _copy)
{
	value = _copy.value;
}

#pragma region methods
Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::Equals(const Integer& _other) const
{
	return value == _other.value;
}
 Core::PrimitiveType::Integer Core::PrimitiveType::Integer::Parse(const FString& _str)
{
	return std::stoi(_str.ToCstr());
}
 Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::TryParse(const FString& _str, Integer& _out)
{
	try
	{
		_out = std::stoi(_str.ToCstr());
		return true;
	}
	catch (const std::exception)
	{
		_out = -1;
		return false;
	}
}
#pragma endregion methods


#pragma region override
Core::PrimitiveType::FString Core::PrimitiveType::Integer::ToString() const
{
	return std::to_string(value).c_str();
}

Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::Equals(const Object* _obj) const
{
	const Integer* _other = dynamic_cast<const Integer*>(_obj);
	if (_other == nullptr) return false;
	return Equals(*_other);
}
Core::PrimitiveType::Integer::operator int() const
{
	return value;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator+(const Integer& _other) const
{
	return value + _other;
}
Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator+=(const Integer& _other)
{
	value += _other;
	return *this;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator-(const Integer& _other) const
{
	return value - _other;
}
Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator-=(const Integer& _other)
{
	value -= _other;
	return *this;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator*(const Integer& _other) const
{
	return value * _other;
}
Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator*=(const Integer& _other)
{
	value *= _other;
	return *this;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator/(const Integer& _other) const
{
	if (_other.value == 0)
		throw DivideByZeroException(std::format("Division of {} by zero.", (int)*this).c_str());
	return value / _other;
}
Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator/=(const Integer& _other)
{
	if (_other.value == 0)
		throw DivideByZeroException(std::format("Division of {} by zero.", (int)*this).c_str());
	value /= _other;
	return *this;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator%(const Integer& _other) const
{
	return value % _other;
}
Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator%=(const Integer& _other)
{
	value %= _other;
	return *this;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator++(int)
{
	Integer tmp = -*this;
	operator++();
	return tmp;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator--(int)
{
	Integer tmp = -*this;
	operator--();
	return tmp;
}
Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator++()
{
	++value;
	return *this;
}
Core::PrimitiveType::Integer& Core::PrimitiveType::Integer::operator--()
{
	--value;
	return *this;
}
Core::PrimitiveType::Integer Core::PrimitiveType::Integer::operator-()
{
	return -value;
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator<(const Integer& _other) const
{
	return value < _other;
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator<=(const Integer& _other) const
{
	return value <= _other;
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator>(const Integer& _other) const
{
	return value > _other;
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator>=(const Integer& _other) const
{
	return value >= _other;
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator==(const Integer& _other) const
{
	return value == _other.value;
}
Core::PrimitiveType::Boolean Core::PrimitiveType::Integer::operator!=(const Integer& _other) const
{
	return !this->operator==(_other);
}
#pragma endregion override
