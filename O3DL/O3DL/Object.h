#pragma once
#include "O3DLibrary.h"
#include "MethodInfo.h"
#include <map>
#include <vector>
#include <iostream>

#pragma warning(disable:4251)
#pragma warning(disable:4244)
#pragma warning(disable:4275)

#define REGISTER_FIELD(name,obj,mask) const int Field_##name=Core::Object::RegisterField(#name,obj,mask);
#define REGISTERMETHOD(name, function,instance, parameters) const int Function##name = RegisterFunction(#name, function, instance, parameters);



namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	class FieldInfo;
	enum class BindingFlags;

	class O3DLIBRAIRY_API Object
	{
#pragma region f/p

	private:
		std::map<const char*, FieldInfo*> fields = std::map<const char*, FieldInfo*>();
		std::map<const char*, BaseMethodeInfo*> method = std::map<const char*, BaseMethodeInfo*>();
#pragma endregion f/p

#pragma region constructor/destructor

	public:
		 Object() = default;
		virtual ~Object() = default;

#pragma endregion constructor/destructor

#pragma region methods

	protected :
		int RegisterField(const char* _name, Object* _obj, int _mask);
		template<typename Result, typename Class, typename... Param>
		int RegisterFunction(const char* _name, Result(Class::* ptr)(Param ...), Class* _instance);
	public:
		 virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
		 virtual Core::PrimitiveType::FString ToString() const;
		std::vector<FieldInfo*> GetFields()const;
		std::vector<FieldInfo*> GetFields(BindingFlags _flags)const;
		FieldInfo* GetField(const char* _name);
		template<typename T>
		void SetValue(Object* obj);
		template <typename T>
		void SetFieldValue(const char* _name, T* _value);

		template<typename Result, typename... Param>
		Result Invoke(const char* _name, Param... _params);

		template<typename Result, typename... Param>
		MethodInfo<Result, Param... >* GetMethod(const char* _name);
#pragma endregion methods

	public:
		virtual Object& operator=(const Object* obj);
	};
	typedef Object* object;

	template<typename Result, typename Class, typename ...Param>
	inline int Object::RegisterFunction(const char* _name, Result(Class::* ptr)(Param...), Class* _instance)
	{
		if (method.contains(_name)) return method.size();
		MethodInfo<Result, Param ...>* _method = new MethodInfo < Result, Param ...>(_instance, ptr);
		method.insert(std::pair(_name, _method));
		return method.size();
	}

	template<typename T>
	inline void Object::SetValue(Object* obj)
	{
		*((T*)this) = obj;
	}
	template<typename T>
	inline void Object::SetFieldValue(const char* _name, T* _value)
	{
		if (!fields.contains(_name)) return;
		*fields[_name] = _value;
	}
	template<typename Result, typename ...Param>
	inline Result Object::Invoke(const char* _name, Param ..._params)
	{
		MethodInfo<Result, Param...>* _method = GetMethod<Result, Param...>*(_name);
		if(_method-nullptr)return Result();
		return _method->Invoke(_params...);
	}
	template<typename Result, typename ...Param>
	inline MethodInfo<Result, Param...>* Object::GetMethod(const char* _name)
	{
		if (!method.contains(_name))return nullptr;
		return dynamic_cast<MethodInfo<Result, Param...>*>(method[_name]);
	}
}