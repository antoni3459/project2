#include "MethodsInfo.h"
#include "BindingFlags.h"
#include "Boolean.h"

Core::MethodsInfo::MethodsInfo(const PrimitiveType::FString& _name, const object _reflectObject, std::map<const char*, MethodsInfo*> _parametre)
{
	name = _name;
	reflectObject = _reflectObject;
	parametre = _parametre;
}

Core::PrimitiveType::Boolean Core::MethodsInfo::IsPublic() const
{
	return flags & Core::BindingFlags::Public;
}

Core::PrimitiveType::Boolean Core::MethodsInfo::IsPrivate() const
{
	return flags & Core::BindingFlags::Private;
}

Core::PrimitiveType::Boolean Core::MethodsInfo::IsStatic() const
{
	return flags & Core::BindingFlags::Static;
}

Core::PrimitiveType::Boolean Core::MethodsInfo::IsConst() const
{
	return flags & Core::BindingFlags::Const;
}

Core::PrimitiveType::FString Core::MethodsInfo::Name() const
{
	return name;
}

Core::BindingFlags Core::MethodsInfo::Flags() const
{
	return flags;
}

Core::object Core::MethodsInfo::RefletdObject() const
{
	return  reflectObject;
}

std::map<const char*, Core::MethodsInfo*> Core::MethodsInfo::Parametre() const
{
	return parametre;
}

Core::PrimitiveType::FString Core::MethodsInfo::ToString() const
{
	return name;
}

Core::Object& Core::MethodsInfo::operator=(const Object* obj)
{
	*reflectObject = obj;
	return *this;
}
