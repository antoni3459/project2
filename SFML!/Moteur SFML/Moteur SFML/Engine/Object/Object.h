#pragma once
#include "../PrimaryType/Enum/Enum.h"
#include "../Reflection/Flags/BindingFlags.h"

#pragma warning(disable: 4996)
#pragma region define
#define UFUNCTION(...)
#define UPROPERTY(...)

#define REGISTER_FIELD(name,field,flags)const int field##name = InsertField(#name,field,flags);

#define UCLASS(...)

#define DECLARE_CLASS_FLAGS(current,parent,flags)\
	public:\
		typedef current self;\
		typedef parent super;\
		const int flagsInfo = RegisterClassInfo((int)flags);

#define DECLARE_CLASS_INFO(current,parent)\
	public:\
		typedef current self;\
		typedef parent super;\

#pragma endregion define

ENUM(classFlags, Class, Type)

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
#pragma region f/p
	private:
		int flags = 0;
		std::map<std::string, Object*> fields = std::map<std::string, Object*>();
#pragma endregion f/p

#pragma region costructor
	public:
		Object() = default;
		Object(const Object& _copy);
		virtual ~Object() = default;
#pragma endregion costructor

#pragma region method
	public:
		virtual PrimaryType::String ToString()const;
		PrimaryType::Boolean IsClass()const;
		Reflection::FieldInfo* GetField(const PrimaryType::String& _name);
		std::vector<Engine::Reflection::FieldInfo*> Field()const;
		std::vector<Engine::Reflection::FieldInfo*> Field(const BindingFlags& _flags);
		template<typename T>
		void SetValue(Object* _obj);
		template<typename T>
		void SetFieldValue(const std::string& _name, T* _value);
	protected:
		int RegisterClassInfo(int _flags);
		size_t InsertField(const std::string& _name, Object* _var, const BindingFlags& _flags);
#pragma endregion method

#pragma region operator
	public:
		virtual Object& operator=(const Object* _obj);
#pragma endregion operator
	};

	template<typename T>
	inline void Object::SetValue(Object* _obj)
	{
		*((T*)this) = _obj;
	}
	template<typename T>
	inline void Object::SetFieldValue(const std::string& _name, T* _value)
	{
		if (!fields.contains(_name))return;
		fields[_name]->SetValue<T>(_value);

	}
}

