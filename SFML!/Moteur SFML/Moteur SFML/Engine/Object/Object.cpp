#include "Object.h"
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include "../../Engine/Utils/DebugMacro.h"
#include "../Reflection/Field/FieldInfo.h"
#include <format>
#include <ranges>

Engine::Object::Object(const Object& _copy)
{
	flags = _copy.flags;
}

Engine::PrimaryType::String Engine::Object::ToString() const
{
	PrimaryType::String _str = typeid(*this).name();
	_str = _str.Replace("class", "");
	return _str.SubString(_str.FindLastOf(':') + 1).Trim();
}
Engine::Reflection::FieldInfo* Engine::Object::GetField(const Engine::PrimaryType::String& _name)
{
	check(fields.contains(_name.ToCstr()), std::format("[Object][Reflection] => {} doesn't exist in field !", _name), nullptr)
		return dynamic_cast<Engine::Reflection::FieldInfo*>(fields[_name.ToCstr()]);
}
std::vector<Engine::Reflection::FieldInfo*> Engine::Object::Field()const
{
	std::vector< Engine::Reflection::FieldInfo*> _result = std::vector< Engine::Reflection::FieldInfo*>();
	for (Object* _o : fields | std::ranges::views::values)
	{
		Engine::Reflection::FieldInfo* _field = dynamic_cast<Engine::Reflection::FieldInfo*>(_o);
		if (_field == nullptr)continue;
		_result.push_back(_field);
	}
	return _result;
}
std::vector<Engine::Reflection::FieldInfo*> Engine::Object::Field(const BindingFlags& _flags)
{
	std::vector< Engine::Reflection::FieldInfo*> _result = std::vector< Engine::Reflection::FieldInfo*>();
	for (Object* _o : fields | std::ranges::views::values)
	{
		Engine::Reflection::FieldInfo* _field = dynamic_cast<Engine::Reflection::FieldInfo*>(_o);
		if (_field == nullptr)continue;
		if (_field->Flags() & _flags)
			_result.push_back(_field);
	}
	return _result;
}


size_t Engine::Object::InsertField(const std::string& _name, Engine::Object* _var, const BindingFlags& _flags)
{
	check(!fields.contains(_name), std::format("[Object][Reflection] => {} already register in fields", _name), fields.size())
		fields.insert(std::pair(_name, new Reflection::FieldInfo(_name.c_str(), _var, _flags)));
	return fields.size();

}

Engine::Object& Engine::Object::operator=(const Object* _obj)
{
	flags = _obj->flags;
	fields = _obj->fields;
	return *this;
}

Engine::PrimaryType::Boolean Engine::Object::IsClass() const
{
	return flags == 0 || !(flags & (int)classFlags::Type);
}

int Engine::Object::RegisterClassInfo(int _flags)
{
	return flags = _flags;
}
