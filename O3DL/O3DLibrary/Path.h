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
			O3DLIBRAIRY_API static PrimitiveType::FString GetPath(const PrimitiveType::FString& _path);
			O3DLIBRAIRY_API static PrimitiveType::FString GetParent(const PrimitiveType::FString& _path);
			O3DLIBRAIRY_API static PrimitiveType::FString Combine(const std::initializer_list < PrimitiveType::FString>& _path);

		};
	}
}