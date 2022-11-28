#include "pch.h"
#include "Object.h"
#include "FString.h"
#include "Boolean.h"
#include <string>


Core::PrimitiveType::Boolean Core::Object::Equals(const Object* _obj) const
{
	return this == _obj;
}

Core::PrimitiveType::FString Core::Object::ToString() const
{
	return "";
}
