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
			static void MakeDirectory(const Core::PrimitiveType::FString& _path);
			static PrimitiveType::Boolean Exist(const Core::PrimitiveType::FString& _path);
		};
	}
}