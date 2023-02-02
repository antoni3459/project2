#pragma once
#include "../ValueType/ValueType.h"
#include "../FString/String.h"

namespace Engine::PrimaryType
{
	UCLASS()
	class Boolean : public ValueType
	{
		DECLARE_CLASS_INFO(Boolean, ValueType)
	private:
		bool value = false;


	public:
		Boolean() = default;
		Boolean(bool _value);
		Boolean(const Boolean& _copy);


	public:
		PrimaryType::String ToString() const override;
		void SerializeField(std::ostream& _os, const String& _fieldName, int _index)override;
		void DeSerializeField(std::istream& _os, const PrimaryType::String& _fieldName)override;

	public:
		Boolean& operator=(const Boolean& _other);
		Boolean operator!() const;
		operator bool();
		operator bool() const;

	};
}

