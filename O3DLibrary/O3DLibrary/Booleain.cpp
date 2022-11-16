#include "pch.h"
#include "Booleain.h"
#include "FString.h"

Core::PrimitiveType::Booleain::Booleain(const bool _value)
{
	value = _value;
}

Core::PrimitiveType::Booleain::Booleain(const Booleain& _copy)
{
	value = _copy.value;
}

Core::PrimitiveType::FString Core::PrimitiveType::Booleain::ToString() const
{
	return value ? "true" : "false";
}

Core::PrimitiveType::Booleain Core::PrimitiveType::Booleain::operator==(const Booleain& _other) const
{
	return value == _other.value;
}

Core::PrimitiveType::Booleain Core::PrimitiveType::Booleain::operator!=(const Booleain& _other) const
{
	return value != _other.value;
}

Core::PrimitiveType::Booleain::operator bool() const
{
	return value;
}

Core::PrimitiveType::Booleain Core::PrimitiveType::Booleain::operator!() const
{
	return !value;
}
