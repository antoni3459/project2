#include "Vector2.h"
#include "../Boolean/Boolean.h"
#include "../../Exception/Exception.h"

Engine::PrimaryType::Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

Engine::PrimaryType::Vector2::operator sf::Vector2<float>() const
{
    return sf::Vector2f(x, y);
}

Engine::PrimaryType::Vector2  Engine::PrimaryType::Vector2::MoveTowars(const Vector2& _current, const Vector2& _target, float _dt)
{
    const float _x = _target.x - _current.x;
    const float _y = _target.y - _current.y;

    const float _distance = _x * _x + _y * _y;
    if (_distance == 0 || (_dt >= 0 && _distance <= _dt * _dt))
        return _target;

    const float _dist = sqrt(_distance);
    return Vector2(_current.x + _x / _dist * _dt, _current.y / _dist * _dt);
}

Engine::PrimaryType::String Engine::PrimaryType::Vector2::ToString() const
{
    return std::format("X {} ,Y {} ",x,y).c_str();
}

void Engine::PrimaryType::Vector2::SerializeField(std::ostream& _os, const String& _fieldName)
{
    if (String::IsNullOrEmpty(_fieldName))
        _os << std::string("\"") + ToString().ToCstr() + "\":\"" + ToString().ToCstr() + "\"";
    else
        _os << std::string("\"") + _fieldName.ToString().ToCstr() + "\":\"" + ToString().ToCstr() + "\"";
}

Engine::Object& Engine::PrimaryType::Vector2::operator=(const Object* _obj)
{
    const Vector2* _other = dynamic_cast<const Vector2*>(_obj);
    if (_other == nullptr)return *this;
    super::operator=(_obj);
    x = _other->x;
    y = _other->y;
}

Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator=(const Vector2& _other)
{
    x = _other.x;
    y = _other.y;
    return *this;
}

Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator+=(const Vector2& _other)
{
    x+=_other.x;
    y += _other.y;
    return *this;
}

Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator-=(const Vector2& _other)
{
    x -= _other.x;
    y -= _other.y;
    return *this;

}

Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator*=(const Vector2& _other)
{
    x *= _other.x;
    y *= _other.y;
    return *this;
}

Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator/=(const Vector2& _other)
{
    x /= _other.x;
    y /= _other.y;
    return *this;
}

Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator+(const Vector2& _other) const
{
    Vector2 _result = *this;
    _result += _other;
    return _result;
}

Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator-(const Vector2& _other) const
{
    Vector2 _result = *this;
    _result -= _other;
    return _result;
}

Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator*(const Vector2& _other) const
{
    Vector2 _result = *this;
    _result *= _other;
    return _result;
}

Engine::PrimaryType::Vector2 Engine::PrimaryType::Vector2::operator/(const Vector2& _other) const
{
    Vector2 _result = *this;
    _result /= _other;
    return _result;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Vector2::operator==(const Vector2& _other) const
{
    return x == _other.x && y == _other.y;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Vector2::operator!=(const Vector2& _other) const
{
    return x != _other.x && y != _other.y;
}

Engine::PrimaryType::Float& Engine::PrimaryType::Vector2::operator[](size_t _index)
{
    switch (_index)
    {
    case 0: return x;
    case 1: return y;
    default:
        throw Exception("[Vector2] => index out of range !");
    }
}

Engine::PrimaryType::Float Engine::PrimaryType::Vector2::operator[](size_t _index) const
{
    switch (_index)
    {
    case 0: return x;
    case 1: return y;
    default:
        throw Exception("[Vector2] => index out of range !");
    }
}
