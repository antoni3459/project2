#pragma once
#include <string>

namespace Core
{
	namespace Utils
	{
		namespace Hash
		{
			template <typename T>
			int GetObjectHashCode(const T& obj)
			{
				return obj.GetHashCode();
			}
			template <typename T>
			int GetObjectHashCode(const T* obj)
			{
				return obj->GetHashCode();
			}

			template <typename T>
			PrimitiveType::FString GetObjectToString(const T& obj)
			{
				return obj.ToString();
			}
			template <typename T>
			PrimitiveType::FString GetObjectToString(const T* obj)
			{
				return obj->ToString();
			}

			size_t HashCode(const char* _str)
			{
				size_t _result = 0;
				const size_t _length = std::strlen(_str);
				for (int i = 0; i < _length; i++)
				{
					int _multiplier = 1;
					for (int j = 0;j < _length - 1 - i;j++)
					{
						_multiplier *= 31;
					}
					_result += _str[i] * _multiplier;
				}
				return _result;
			}
		}
	}
}
