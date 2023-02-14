#include "Vector2f.h"
#include "../../../Utils/DebugMacro.h"
#include <format>
#include "../../../Reflection/Utils/ReflectionUtils.h"

#pragma region constructor
Engine::PrimaryType::Vector2f::Vector2f(float _x, float _y)
{
	x = _x;
	y = _y;
}

Engine::PrimaryType::Vector2f::Vector2f(const Vector2f& _copy)
	: super() { }
#pragma endregion 


Engine::PrimaryType::Vector2f Engine::PrimaryType::Vector2f::MoveTowards(const Vector2f& _current, const Vector2f& _target, float _dt)
{
	const float _x = _target.x - _current.x;
	const float _y = _target.y - _current.y;

	const float _distance = _x * _x + _y * _y;
	if (_distance == 0 || (_dt >= 0 && _distance <= _dt * _dt))
		return _target;

	const float _dist = sqrt(_distance);
	return Vector2f(_current.x + _x / _dist * _dt, _current.y + _y / _dist * _dt);
}

Engine::PrimaryType::FString Engine::PrimaryType::Vector2f::ToString() const
{
	return std::format("({}, {})", x, y).c_str();
}

void Engine::PrimaryType::Vector2f::SerializeField(std::ostream& _os, const PrimaryType::FString& _fieldName, int _index)
{
	Reflection::ReflectionUtils::SerializePrimaryType(_os, this, _fieldName);
}

void Engine::PrimaryType::Vector2f::DeSerializeField(std::istream& _is, const PrimaryType::FString& _fieldName)
{
	const FString& _str = Reflection::ReflectionUtils::GetLine(_is, _fieldName);
	const FString& _x = _str.SubString(_str.FindFirstOf('(') + 1, _str.FindFirstOf(','));
	const FString& _y = _str.SubString(_str.FindFirstOf(',') + 1, _str.FindFirstOf(')'));
	*this = Vector2f(std::stof(_x.ToCstr()), std::stof(_y.ToCstr()));
}

Engine::PrimaryType::Vector2f::operator sf::Vector2<float>() const
{
	return sf::Vector2f(x, y);
}

Engine::Object& Engine::PrimaryType::Vector2f::operator=(const Object* _obj)
{
	const Vector2f* _other = dynamic_cast<const Vector2f*>(_obj);
	if (_other == nullptr) return *this;
	super::operator=(_obj);
	x = _other->x;
	y = _other->y;
	return *this;
}

Engine::PrimaryType::Vector2f& Engine::PrimaryType::Vector2f::operator=(const Vector2f& _other)
{
	x = _other.x;
	y = _other.y;
	return *this;
}

Engine::PrimaryType::Vector2f& Engine::PrimaryType::Vector2f::operator+=(const Vector2f& _other)
{
	x += _other.x;
	y += _other.y;
	return *this;
}

Engine::PrimaryType::Vector2f& Engine::PrimaryType::Vector2f::operator-=(const Vector2f& _other)
{
	x -= _other.x;
	y -= _other.y;
	return *this;
}

Engine::PrimaryType::Vector2f& Engine::PrimaryType::Vector2f::operator*=(const Vector2f& _other)
{
	x *= _other.x;
	y *= _other.y;
	return *this;
}

Engine::PrimaryType::Vector2f& Engine::PrimaryType::Vector2f::operator/=(const Vector2f& _other)
{
	x /= _other.x;
	y /= _other.y;
	return *this;
}

Engine::PrimaryType::Vector2f Engine::PrimaryType::Vector2f::operator+(const Vector2f& _other) const
{
	Vector2f _result = *this;
	_result += _other;
	return _other;
}

Engine::PrimaryType::Vector2f Engine::PrimaryType::Vector2f::operator-(const Vector2f& _other) const
{
	Vector2f _result = *this;
	_result -= _other;
	return _other;
}

Engine::PrimaryType::Vector2f Engine::PrimaryType::Vector2f::operator*(const Vector2f& _other) const
{
	Vector2f _result = *this;
	_result *= _other;
	return _other;
}

Engine::PrimaryType::Vector2f Engine::PrimaryType::Vector2f::operator/(const Vector2f& _other) const
{
	Vector2f _result = *this;
	_result /= _other;
	return _other;
}


Engine::PrimaryType::Boolean Engine::PrimaryType::Vector2f::operator==(const Vector2f& _other) const
{
	return (x == _other.x) && (y == _other.y);
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Vector2f::operator!=(const Vector2f& _other) const
{
	return !this->operator==(_other);
}

Engine::PrimaryType::Float& Engine::PrimaryType::Vector2f::operator[](size_t _index)
{
	switch (_index)
	{
	case 0: return x;
	case 1: return y;
	default:
		throw std::exception("[Vector2f] => index out of range");
	}
}

Engine::PrimaryType::Float Engine::PrimaryType::Vector2f::operator[](size_t _index) const
{
	switch (_index)
	{
	case 0: return x;
	case 1: return y;
	default:
		throw std::exception("[Vector2f] => index out of range");
	}
}
