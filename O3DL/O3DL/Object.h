#pragma once
#include "O3DLibrary.h"
#include <map>
#include <vector>

namespace Core
{
#define REGISTER_FIELD(name,obj,mask) Core::Object::RegisterField(name,obj,mask);

	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	class FieldInfo;
	enum class BindingFlags;
	class MethodsInfo;
	class O3DLIBRAIRY_API Object
	{
#pragma region f/p

	private:
		std::map<const char*, FieldInfo*> fields = std::map<const char*, FieldInfo*>();
		std::map<const char*, MethodsInfo*> parametre = std::map<const char*, MethodsInfo*>();

#pragma endregion f/p

#pragma region constructor/destructor

	public:
		 Object() = default;
		virtual ~Object() = default;

#pragma endregion constructor/destructor

#pragma region methods

	protected :
		int RegisterField(const char* _name, Object* _obj, int _mask);
		int RegisterMethod(const char* _name, Object* _obj, int _mask, std::map<const char*, MethodsInfo*> _parametre);
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
#pragma endregion methods

	public:
		virtual Object& operator=(const Object* obj);
	};
	typedef Object* object;

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
}