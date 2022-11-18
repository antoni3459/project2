#pragma once
#include "Object.h"
#include "Boolean.h"

namespace Core
{
	namespace IO
	{
		class Directory : public Object
		{
		public:
			O3DLIBRAIRY_API static void MakeDirectory(const Core::PrimitiveType::FString& _path);
			O3DLIBRAIRY_API static PrimitiveType::Boolean Exist(const Core::PrimitiveType::FString& _path);
		};
	}
}