#pragma once
#include "Object.h"
#include <initializer_list>
namespace Core
{
	namespace IO
	{
		class Path : public Object
		{
		private:
			static const char DirectorySeparator = '/';

		public:
			static PrimitiveType::FString GetPath(const PrimitiveType::FString& _path);
			static PrimitiveType::FString GetParent(const PrimitiveType::FString& _path);
			static PrimitiveType::FString Combine(const std::initializer_list < PrimitiveType::FString>& _path);

		};
	}
}