#include "Boolean.h"

Engine::PrimaryType::Boolean::Boolean(bool _value) : super()
{
    value = _value;
}

Engine::PrimaryType::Boolean::Boolean(const Boolean& _copy) : super(_copy)
{
    value = _copy.value;
}

Engine::PrimaryType::String Engine::PrimaryType::Boolean::ToString() const
{
    return value ? "true" : "false";
}

Engine::PrimaryType::Boolean& Engine::PrimaryType::Boolean::operator=(const Boolean& _other)
{
    value = _other.value;
    return *this;
}

Engine::PrimaryType::Boolean Engine::PrimaryType::Boolean::operator!() const
{
    return !value;
}

Engine::PrimaryType::Boolean::operator bool()
{
    return value;
}

Engine::PrimaryType::Boolean::operator bool() const
{
    return value;
}


