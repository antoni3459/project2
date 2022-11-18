#include "pch.h"
#include "Object.h"
#include "FString.h"
#include "Boolean.h"

Core::PrimitiveType::Boolean Core::Object::Equals(const Object* _obj) const
{
	return this == _obj;
}

O3DLIBRAIRY_API Core::PrimitiveType::FString Core::Object::ToString() const
{
	return "";
}
