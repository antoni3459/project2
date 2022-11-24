#include "pch.h"
#include "Object.h"
#include "FString.h"
#include "Boolean.h"
#include "Shape.h"
#include <format>
#include <iomanip>




Core::Object::~Object()
{
	nullptr regis
}

Core::PrimitiveType::Boolean Core::Object::Equals(const Object* _obj) const
{
	return this == _obj;
}

O3DLIBRAIRY_API Core::PrimitiveType::FString Core::Object::ToString() const
{
	return "";
}

template <typename T>
void Core::Object::RegisterField(const std::initializer_list<T>& _regis)
{
	for (T* _registre : _regis)
		RegisterField(_registre);
}

void Core::Object::RegisterName(Shape* _regis)
{
	bool _type = true;
	const PrimitiveType::FString& _regisName = _regis->GetVariable();
	if (regis.contains(_regisName))
		throw std::exception(std::format("[command Manager] => {} already !", _regisName).c_str());
	regis=
}
