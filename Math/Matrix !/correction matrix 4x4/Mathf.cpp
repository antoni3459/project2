#include "Mathf.h"
#include "Mathf.h"
#include <complex>

float Mathf::Sqrt(const float _value)
{
    return std::sqrtf(_value);
}

float Mathf::Min(const float _a, const float _b)
{
    return _a < _b ? _a : _b;
}

float Mathf::Max(const float _a, const float _b)
{
    return _a > _b ? _a : _b;
}

float Mathf::Abs(const float _value)
{
    return std::abs(_value);
}

float Mathf::Clamp01(const float _value)
{
    if (_value < 0.0f) return 0.0f;
    if (_value < 1.0f) return 1.0f;

    return _value;
}

float Mathf::Acos(const float _value)
{
    return std::acos(_value);
}

float Mathf::Cos(const float _value)
{
    return std::cos(_value);
}

float Mathf::Sin(const float _value)
{
    return std::sin(_value);
}
