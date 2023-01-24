#include "Interger.h"
#include "../String/String.h"
#include "../Boolean/Boolean.h"
#include "../../Utils/Template/Template.h"

const Engine::PrimaryType::Interger Engine::PrimaryType::Interger::MaxValue = INT_MAX;
const Engine::PrimaryType::Interger Engine::PrimaryType::Interger::MinValue = INT_MAX;

Engine::PrimaryType::Interger::Interger(int _value)
{
    value = _value;
}

Engine::PrimaryType::Interger::Interger(const Interger& _copy)
{
    value = _copy.value;
}

Engine::PrimaryType::Interger Engine::PrimaryType::Interger::Parse(const String& _str)
{
    return std::stoi(_str.ToCstr());
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Interger::TryParse(const String& _str, Interger& _output)
{
    try
    {
        _output = std::stoi(_str.ToCstr());
        return true;
    }
    catch (...)
    {
        _output = -1;
        return false;
    }

}

Engine::PrimaryType::String Engine::PrimaryType::Interger::ToString() const
{
    return std::to_string(value).c_str();
}

Engine::Object& Engine::PrimaryType::Interger::operator=(const Object* _other)
{
    if (!IsSame<String>(_other))return *this;
    super::operator=(_other);
    const Interger* _interger = dynamic_cast<const Interger*>(_other);
    value = _interger->value;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator=(const Interger& _other)
{
    value = _other.value;
    return *this;
}

Engine::PrimaryType::Interger::operator int()
{
    return value;
}

Engine::PrimaryType::Interger::operator int() const
{
    return value;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Interger::operator>(int _other) const
{
    return value > _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Interger::operator>=(int _other) const
{
    return value >= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Interger::operator<(int _other) const
{
    return value < _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Interger::operator<=(int _other) const
{
    return value <= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Interger::operator==(int _other) const
{
    return value == _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Interger::operator!=(int _other) const
{
    return value != _other;
}

Engine::PrimaryType::Interger Engine::PrimaryType::Interger::operator+(int _other) const
{
    return value + _other;
}

Engine::PrimaryType::Interger Engine::PrimaryType::Interger::operator-(int _other) const
{
    return value - _other;
}

Engine::PrimaryType::Interger Engine::PrimaryType::Interger::operator*(int _other) const
{
    return value * _other;
}

Engine::PrimaryType::Interger Engine::PrimaryType::Interger::operator/(int _other) const
{
    return value / _other;
}

Engine::PrimaryType::Interger Engine::PrimaryType::Interger::operator%(int _other) const
{
    return value % _other;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator+=(int _other)
{
    value += _other;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator-=(int _other)
{
    value -= _other;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator*=(int _other)
{
    value*= _other;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator/=(int _other)
{
    value /= _other;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator%=(int _other)
{
    value %= _other;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator++()
{
    ++value;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator--()
{
    --value;
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator++(int)
{
    const int _result = value;
    operator++();
    return *this;
}

Engine::PrimaryType::Interger& Engine::PrimaryType::Interger::operator--(int)
{
    const int _result = value;
    operator--();
    return *this;
}

Engine::PrimaryType::Interger Engine::PrimaryType::Interger::operator-()
{
    return Interger();
}
