#include "Double.h"
#include "../Boolean/Boolean.h"
#include "../FString/String.h"

const Engine::PrimaryType::Double Engine::PrimaryType::Double::MinValue = -1.7976931348623157E+308;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::MaxValue = 1.7976931348623157E+308;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::Epsilon = 4.94865645841247E-324;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::PositiveInfinity = (1e+300 * 1e+300);
const Engine::PrimaryType::Double Engine::PrimaryType::Double::NegativeInfinity = -PositiveInfinity;
const Engine::PrimaryType::Double Engine::PrimaryType::Double::NaN = 0.0f * PositiveInfinity;



Engine::PrimaryType::Double::Double(double _value)
{
    value = _value;
}

Engine::PrimaryType::Double::Double(const Double& _copy)
{
    value = _copy.value;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::Parse(const String& _str)
{
    return std::stod(_str.ToCstr());
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::TryParse(const String& _str, Double& _output)
{
    try
    {
        _output = std::stod(_str.ToCstr());
        return true;
    }
    catch (const std::exception&)
    {
        _output = NaN;
        return false;
    }
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsNaN(const Double& _value)
{
    return std::isnan(_value);
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsEpsilon(const Double& _value)
{
    return _value == Epsilon;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsPositiveInfinity(const Double& _value)
{
    return _value == PositiveInfinity;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::IsNegativeInfinity(const Double& _value)
{
    return _value == NegativeInfinity;
}

Engine::PrimaryType::String Engine::PrimaryType::Double::ToString() const
{
    if (IsNaN(*this)) return "NaN";
    if (IsPositiveInfinity(*this)) return "Positive Infinity";
    if (IsNegativeInfinity(*this)) return "Negative Infinity";
    return std::to_string(value).c_str();
}

void Engine::PrimaryType::Double::SerializeField(std::ostream& _os, const String& _fieldName)
{
    if (String::IsNullOrEmpty(_fieldName))
        _os << std::string("\"") + ToString().ToCstr() + "\":\"" + ToString().ToCstr() + "\"";
    else
        _os << std::string("\"") + _fieldName.ToString().ToCstr() + "\":\"" + ToString().ToCstr() + "\"";
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator=(const Double& _other)
{
    value = _other.value;
    return *this;
}

Engine::PrimaryType::Double::operator double()
{
    return value;
}

Engine::PrimaryType::Double::operator double() const
{
    return value;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator+(double _other) const
{
    return value + _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator-(double _other) const
{
    return value - _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator*(double _other) const
{
    return value * _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator/(double _other) const
{
    return value / _other;
}

Engine::PrimaryType::Double Engine::PrimaryType::Double::operator-() const
{
    return -value;
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator+=(double _other)
{
    value += _other;
    return *this;
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator-=(double _other)
{
    value -= _other;
    return *this;
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator*=(double _other)
{
    value *= _other;
    return *this;
}

Engine::PrimaryType::Double& Engine::PrimaryType::Double::operator/=(double _other)
{
    value /= _other;
    return *this;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator<(double _other) const
{
    return value < _other;;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator<=(double _other) const
{
    return value <= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator>(double _other) const
{
    return value > _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator>=(double _other) const
{
    return value >= _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator==(double _other) const
{
    return value == _other;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Double::operator!=(double _other) const
{
    return value != _other;
}
