#include "Interger.h"
#include "FString.h"
#include "boolean.h"
#include "Exception.h"
#include <limits>
#include <format>

//Core::PrimitiveType::Interger const Core::PrimitiveType::Interger::MaxValue = std::numeric_limits<int>::max();
//Core::PrimitiveType::Interger const Core::PrimitiveType::Interger::MinValue = std::numeric_limits<int>::min();
Core::PrimitiveType::Interger Core::PrimitiveType::Interger::MaxValue()
{
    return std::numeric_limits<int>::max();
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::MinValue()
{
    return std::numeric_limits<int>::min();
}

Core::PrimitiveType::Interger::Interger(const int _value)
{
    value = _value;
}

Core::PrimitiveType::Interger::Interger(const Interger& _copy)
{
    value = _copy.value;
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::Equals(const Interger& _other) const
{
    
    return value==_other.value;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::Parse(const FString& _str)
{
    return std::stoi(_str.ToCstr());
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::TryParse(const FString& _str, Interger& _out)
{
    try
    {
        _out = std::stoi(_str.ToCstr());
        return true;
    }
    catch (const std::exception&)
    {
        _out = -1;
        return false;
    }
}

Core::PrimitiveType::FString Core::PrimitiveType::Interger::ToString() const
{
    return std::to_string(value).c_str();
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::Equals(const Object* _obj) const
{
    const Interger* _other = dynamic_cast<const Interger*>(_obj);
    if (_other == nullptr) return false;
    return Equals(*_other);
}

Core::PrimitiveType::Interger::operator int() const
{
    return value;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator+(const Interger& _other) const
{
    return value+_other;
}

Core::PrimitiveType::Interger& Core::PrimitiveType::Interger::operator+=(const Interger& _other)
{
    value += _other;
    return *this;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator-(const Interger& _other) const
{
     return value - _other;
    
}

Core::PrimitiveType::Interger& Core::PrimitiveType::Interger::operator-=(const Interger& _other)
{
    value -= _other;
    return *this;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator*(const Interger& _other) const
{
    return value * _other;
}

Core::PrimitiveType::Interger& Core::PrimitiveType::Interger::operator*=(const Interger& _other)
{
    value *= _other;
    return *this;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator/(const Interger& _other) const
{
    if (_other == Interger(0))
        throw DivideByZeroException(std::format("Division of {} by zero.", (int)*this).c_str());
    return value / _other;
}

Core::PrimitiveType::Interger& Core::PrimitiveType::Interger::operator/=(const Interger& _other)
{
    if (_other == Interger(0))
        throw DivideByZeroException(std::format("Division of {} by zero.", (int)*this).c_str());
    value /= _other;
    return *this;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator%(const Interger& _other) const
{
    return value%_other;
}

Core::PrimitiveType::Interger& Core::PrimitiveType::Interger::operator%=(const Interger& _other)
{
    value %= _other;
    return *this;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator++(int)
{
    Interger tmp = *this;
    operator++();
    return tmp;
}

Core::PrimitiveType::Interger& Core::PrimitiveType::Interger::operator++()
{
    ++value;
    return *this;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator--(int)
{
    Interger tmp = *this;
    operator--();
    return tmp;
}

Core::PrimitiveType::Interger& Core::PrimitiveType::Interger::operator--()
{
    value--;
    return *this;
}

Core::PrimitiveType::Interger Core::PrimitiveType::Interger::operator-()
{
    return -value;
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::operator<(const Interger& _other) const
{
    return value<_other;
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::operator<=(const Interger& _other) const
{
    return value <= _other;
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::operator>(const Interger& _other) const
{
    return value > _other;
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::operator>=(const Interger& _other) const
{
    return value >= _other;
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::operator==(const Interger& _other) const
{
    return value==_other.value;
}

Core::PrimitiveType::boolean Core::PrimitiveType::Interger::operator!=(const Interger& _other) const
{
    return !this->operator==(_other);
}
