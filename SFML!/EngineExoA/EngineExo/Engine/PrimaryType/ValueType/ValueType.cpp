#include "ValueType.h"

Engine::PrimaryType::ValueType::ValueType(const ValueType& _copy) :super(_copy)
{
}

Engine::Object& Engine::PrimaryType::ValueType::operator=(const Object* _obj)
{
	return super::operator=(_obj);
}
