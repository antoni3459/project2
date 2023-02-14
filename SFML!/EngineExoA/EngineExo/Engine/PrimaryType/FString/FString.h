#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
	class Boolean;
	UCLASS()
	class FString : public ValueType
	{
		DECLARE_CLASS_INFO(FString, ValueType)
	private:
		const char* value = nullptr;
		size_t length = 0;

	public:
		FString() = default;
		FString(const char* _value);

	public:
		Boolean StartWith(char _c) const;
		Boolean EndWith(char _c) const;
		Boolean StartWith(const FString& _str) const;
		Boolean EndWith(const FString& _str) const;
		Boolean EqualsIgnoreCase(const FString& _str) const;
		Boolean Contains(const FString& _str) const;
		static Boolean IsNullOrEmpty(const FString& _str);

		FString SubString(size_t _begin) const;
		FString SubString(size_t _begin, size_t _end) const;
		FString Replace(const FString& _old, const FString _new) const;
		FString Replace(char & _old, char _new);
		FString Trim();
		FString ToLower() const;
		FString ToUpper() const;
		size_t FindFirstOf(char _c) const;
		size_t FindLastOf(char _c) const;
		size_t Length() const;
		void Append(char _c);
		void Append(const char* _str);
		void Append(const FString& _str);
		const char* ToCstr() const;
	public:
		FString ToString() const override;
		void SerializeField(std::ostream& _os, const PrimaryType::FString& _fieldName, int _index) override;
		void DeSerializeField(std::istream& _is, const PrimaryType::FString& _fieldName) override;

	public:
		FString operator+(const FString& _str);
		FString& operator+=(const char* _str);
		FString& operator+=(char _c);
		FString& operator+=(const FString& _str);
		FString& operator=(const FString& _other);
		virtual Object& operator=(const Object* _obj);
		operator const char* ();
		operator const char* () const;
		Boolean operator==(const FString& _str) const;
		Boolean operator!=(const FString& _str) const;
		Boolean operator==(const char* _str) const;
		Boolean operator!=(const char* _str) const;
	};
}
