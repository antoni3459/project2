#include "pch.h"
#include "Object.h"
#include "Fstring.h"
#include "boolean.h"

Core::PrimitiveType::FString Core::Object::ToString() const
{
	return " ";
}

Core::PrimitiveType::boolean Core::Object::Equals(const Object* _obj) const
{
	return this == _obj;
}
