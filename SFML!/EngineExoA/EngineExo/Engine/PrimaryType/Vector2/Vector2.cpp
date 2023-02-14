#include "Vector2.h"
#include "../Boolean/Boolean.h"
#include "../FString/String.h"
#include "../../Exception/Exception.h"
#include "../../Reflection/Utils/ReflectionUtils.h"

#pragma region constructor
Engine::PrimaryType::Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

Engine::PrimaryType::Vector2::Vector2(const Vector2& _copy) :super(_copy)
{
    x = _copy.x;
    y = _copy.y;
}

#pragma endregion constructor

#pragma region method
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
#pragma endregion method

#pragma region override
Engine::PrimaryType::String Engine::PrimaryType::Vector2::ToString() const
{
    return std::format("({} , {})", x, y).c_str();
}

void Engine::PrimaryType::Vector2::SerializeField(std::ostream& _os, const String& _fieldName, int _index)
{
    Reflection::ReflectionUtils::SerializePrimaryType(_os, this, _fieldName);
}

void Engine::PrimaryType::Vector2::DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName)
{

    //_str = _str.Replace("\"", "").Replace("\t", "").Trim();
    const String& _str = Reflection::ReflectionUtils::GetLine(_is, _fieldName);
    const String& _x = _str.SubString(_str.FindFirstOf('(') + 1, _str.FindFirstOf(','));
    const String& _y = _str.SubString(_str.FindFirstOf(',') + 1, _str.FindFirstOf(')'));
    *this = Vector2(std::stof(_x.ToCstr()), std::stof(_y.ToCstr()));
}
#pragma endregion override

#pragma region operator
Engine::PrimaryType::Vector2::operator sf::Vector2<float>() const
{
    return sf::Vector2f(x, y);
}

Engine::Object& Engine::PrimaryType::Vector2::operator=(const Object* _obj)
{
    const Vector2* _other = dynamic_cast<const Vector2*>(_obj);
    if (_other == nullptr)return *this;
    super::operator=(_obj);
    x = _other->x;
    y = _other->y;
    return *this;
}

Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator=(const Vector2& _other)
{
    x = _other.x;
    y = _other.y;
    return *this;
}

Engine::PrimaryType::Vector2& Engine::PrimaryType::Vector2::operator+=(const Vector2& _other)
{
    x += _other.x;
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
#pragma endregion operator