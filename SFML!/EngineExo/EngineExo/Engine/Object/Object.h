#pragma once
#include "../PrimaryType/Enum/Enum.h"
#include "../Reflection/Flags/BindingFlags.h"
#include "../Reflection/Function/MethodInfo/MethodInfo.h"
#include "../Reflection/Function/Function.h"
#include <string>
#include <format>


#pragma warning(disable: 4996)


#define UFUNCTION(...)
#define UPROPERTY(...)
#define UCLASS(...)

#define REGISTER_FIELD(name, field, flags) const int field##name = InsertField(#name, (Object*)field, flags);

#define REGISTER_METHOD(name, method,params, flags) const int Method##name = InsertMethod(#name, method, params, flags);

#define DECLARE_CLASS_INFO_FLAGS(current, parent, flags)\
	public:\
		typedef current self;\
		typedef parent super;\
		const int flagsInfo = RegisterClassInfo((int)flags);

#define DECLARE_CLASS_INFO(current, parent)\
	public:\
		typedef current self;\
		typedef parent super;

ENUM(ClassFlags, Class, Type)



namespace Engine
{
	namespace PrimaryType
	{
		class String;
		class Boolean;
	}

	namespace Reflection
	{
		class FieldInfo;
	}
	class Object
	{
	private:
		int flags = 0;
		std::map<std::string, Object*> fields = std::map<std::string, Object*>();
		std::map<std::string, Reflection::Function*> functions = std::map<std::string, Reflection::Function*>();

	public:
		Object() = default;
		Object(const Object& _copy);
		virtual ~Object() = default;

	public:
		virtual PrimaryType::String ToString() const;
		virtual PrimaryType::Boolean IsClass() const;
		Reflection::FieldInfo* GetField(const PrimaryType::String& _name);
		std::vector<Reflection::FieldInfo*> Fields(const BindingFlags& _flags);
		std::vector<Reflection::FieldInfo*> Fields() const;

		template<typename T>
		void SetValue(Object* _obj);
		template<typename T>
		void SetFieldValue(const std::string& _name, T* _value);

		template<typename Res, typename... Params>
		Reflection::MethodInfo<Res, Params...>* GetFunction(const std::string& _name);

		template<typename Res, typename... Params>
		Res Invoke(const std::string& _name, Object* _instance, Params..._params);


		template<typename Res, typename... Params>
		Res Invoke(const std::string& _name, Params..._params);


	protected:
		int RegisterClassInfo(int _flags);
		template<typename Res, typename Class, typename... Params>
		int InsertMethod(const std::string& _name, Res(Class::*ptr)(Params...),const std::vector<Reflection::ParameterInfo*>& _params,  const BindingFlags& _flags);
		template<typename Res, typename... Params>

		int InsertMethod(const std::string& _name, Res(*ptr)(Params...),const std::vector<Reflection::ParameterInfo*>& _params,  const BindingFlags& _flags);


		int InsertField(const std::string& _name, Object* _var, const BindingFlags& _flags);
	public:
		virtual Object& operator=(const Object* _obj);
	};
	template<typename T>
	void Object::SetValue(Object* _obj)
	{
		*((T*)this) = _obj;
	}
	template<typename T>
	void Object::SetFieldValue(const std::string& _name, T* _value)
	{
		if (!fields.contains(_name)) return;
		fields[_name]->SetValue<T>(_value);
	}
	template<typename Res, typename Class, typename... Params>
	int Object::InsertMethod(const std::string& _name, Res(Class::* ptr)(Params...), const std::vector<Reflection::ParameterInfo*>& _params, const BindingFlags& _flags)
	{
		if (functions.contains(_name)) return functions.size();
		Reflection::MethodInfo<Res, Params...>* _function = new Reflection::MethodInfo<Res, Params...>(_name, ptr, _params, _flags);
		functions.insert(std::pair(_name, _function));
		return functions.size();
	}
	template<typename Res, typename... Params>
	int Object::InsertMethod(const std::string& _name, Res(*ptr)(Params...), const std::vector<Reflection::ParameterInfo*>& _params, const BindingFlags& _flags)
	{
		if (functions.contains(_name)) return functions.size();
		Reflection::MethodInfo<Res, Params...>* _function = new Reflection::MethodInfo<Res, Params...>(_name, ptr, _params, _flags);
		functions.insert(std::pair(_name, _function));
		return functions.size();
	}

	template<typename Res, typename... Params>
	Reflection::MethodInfo<Res, Params...>* Object::GetFunction(const std::string& _name)
	{
		if (!functions.contains(_name)) return nullptr;
		return reinterpret_cast<Reflection::MethodInfo<Res, Params...>*>(functions[_name]);
	}

	template<typename Res, typename... Params>
	Res Object::Invoke(const std::string& _name, Object* _instance, Params..._params)
	{
		Reflection::MethodInfo<Res, Params...>* _method = GetFunction<Res, Params...> (_name);
		if (_method == nullptr)
			throw std::exception(std::format("[Object][Reflection] => function {} doesn't exist", _name).c_str());
		return _method->Invoke(_instance, _params...);
	}


	template<typename Res, typename... Params>
	Res Object::Invoke(const std::string& _name, Params..._params)
	{
		return Invoke<Res, Params...>(_name, this, _params...);
	}
}