#pragma once
#include "Object.h"


namespace Core
{
	namespace Collections
	{

		template <typename TKey, typename TValue>
		class O3DLIBRAIRY_API KeyValuePair :public Object
		{
			static_assert(std::is_base_of_v<Object, TKey>, "Key must be an inherited of Object");
			static_assert(std::is_base_of_v<Object, TValue>, "Value must be an inherited of Object");
		private:
			TKey key = TKey();
			TValue value = TValue();



		public:
			KeyValuePair() = default;
			KeyValuePair(const TKey& _key, const TValue& _value)
			{
				key = _key;
				value = _value;
			}
			KeyValuePair(const KeyValuePair& _copy)
			{
				key = _copy.key;
				value = _copy.value;
			}

		public:
			TKey Key() const
			{
				return key;
			}
			TValue Value()const
			{
				return value;
			}
			TValue& Value()const
			{
				return value;
			}
			
		public:
			PrimitiveType::FString ToString() const override
			{
				const PrimitiveType::FString& _keyStr = Utils::Hash::GetObjectToString(key);
				const PrimitiveType::FString& _valueStr = Utils::Hash::GetObjectToString(value);

				return PrimitiveType::FString::Format("key: {}, Value: {}", _keyStr, _valueStr);
			}
			int GetHashCosde()const override
			{
				return GetObjectHashCode(key) ^ GetObjectHashCode(value) << 1;
			}

		public:
			KeyValuePair operator=(const KeyValuePair& _other)
			{
				key = _other.key;
				value = _other.value;
				return *this;
			}
			bool operator==(const KeyValuePair& _other)
			{
				return key == key = _other.key && value == _other.value;
			}
			bool operator!=(const KeyValuePair& _other)
			{
				return !(*this == _other);//return !this->operator==(other); //method 2
			}
			bool operator==(const TKey& _key)
			{
				return key == _key;
			}
			bool operator!=(const TKey& _key)
			{
				return !(*this == _key);
			}

		};
	}
}