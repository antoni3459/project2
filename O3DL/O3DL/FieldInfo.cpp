#include "FieldInfo.h"
#include "BindingFlags.h"
#include "Boolean.h"

Core::FieldInfo::FieldInfo(const PrimitiveType::FString& _name, const object _reflectadObject, const int _mask)
{
	name = _name;
	reflectObject = _reflectadObject;
	flags = (BindingFlags)_mask;
}

Core::FieldInfo::FieldInfo(const PrimitiveType::FString& _name, const object _reflectadObject)
{
	name = _name;
	reflectObject = _reflectadObject;
}

Core::PrimitiveType::Boolean Core::FieldInfo::IsPublic() const
{
	return flags & Core::BindingFlags::Public;
}

Core::PrimitiveType::Boolean Core::FieldInfo::IsPrivate() const
{
	return flags & Core::BindingFlags::Private;
}

Core::PrimitiveType::Boolean Core::FieldInfo::IsStatic() const
{
	return flags & Core::BindingFlags::Static;
}

Core::PrimitiveType::Boolean Core::FieldInfo::IsConst() const
{
	return flags & Core::BindingFlags::Const;
}

Core::PrimitiveType::FString Core::FieldInfo::Name() const
{
	return name;
}

Core::BindingFlags Core::FieldInfo::Flags() const
{
	return flags;
}

Core::object Core::FieldInfo::RefletdObject() const
{
	return  reflectObject;
}

Core::PrimitiveType::FString Core::FieldInfo::ToString() const
{
	return name;
}

Core::Object& Core::FieldInfo::operator=(const Object* obj)
{
	*reflectObject = obj;
	return *this;
}


