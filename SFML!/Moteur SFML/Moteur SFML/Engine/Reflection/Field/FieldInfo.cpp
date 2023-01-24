#include "FieldInfo.h"
#include "../../PrimaryType/String/String.h"
#include "../Flags/BindingFlags.h"
#include "../../Object/Object.h"

Engine::Reflection::FieldInfo::FieldInfo(const PrimaryType::String _name, Object* _reflectedObject, BindingFlags _flags)
{
	name = _name;
	reflectedObject = _reflectedObject;
	flags = _flags;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsPublic()const
{

	return flags & BindingFlags::Public;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsPrivate()const
{
	return flags & BindingFlags::NoPublic;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsStatic()const
{
	return flags & BindingFlags::Static;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsArray()const
{
	return flags & BindingFlags::Array;
}

Engine::PrimaryType::Boolean Engine::Reflection::FieldInfo::IsReflectedClass() const
{
	return reflectedObject->IsClass();
}

Engine::PrimaryType::String Engine::Reflection::FieldInfo::Name() const
{
	return name;
}

BindingFlags Engine::Reflection::FieldInfo::Flags() const
{
	return flags;
}

Engine::Object* Engine::Reflection::FieldInfo::ReflectedObject() const
{
	return reflectedObject;
}

Engine::PrimaryType::String Engine::Reflection::FieldInfo::ToString() const
{
	return reflectedObject == nullptr ? PrimaryType::String("nullptr") : reflectedObject->ToString();
}

Engine::Object& Engine::Reflection::FieldInfo::operator=(const Object* _obj)
{
	return (*reflectedObject) = _obj;
}
