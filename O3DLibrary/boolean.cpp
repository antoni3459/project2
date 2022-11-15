#include "pch.h"
#include "boolean.h"

Core::PrimitiveType::boolean::boolean(const bool _value)
{
	value = _value;
}

Core::PrimitiveType::boolean::boolean(const boolean& _copy)
{
	value = _copy.value;
}

Core::PrimitiveType::boolean Core::PrimitiveType::boolean::ToString() const
{
	return value ? "true" : "false";
}

Core::PrimitiveType::boolean Core::PrimitiveType::boolean::operator==(const boolean& _other) const
{
	return value==_other.value;
}

Core::PrimitiveType::boolean Core::PrimitiveType::boolean::operator!=(const boolean& _other) const
{
	return value!=_other.value;
}

Core::PrimitiveType::boolean::operator bool() const
{
	return value;
}

Core::PrimitiveType::boolean Core::PrimitiveType::boolean::operator!() const
{
	return !value;
}
