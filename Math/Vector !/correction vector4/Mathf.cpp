#include "Mathf.h"
#include <complex>

float Mathf::Sqrt(const float _value)
{
    return std::sqrtf(_value);
}

float Mathf::Min(const float _a, const float _b)
{
    return _a<_b ? _a : _b;
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