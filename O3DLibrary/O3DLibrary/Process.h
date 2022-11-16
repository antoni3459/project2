#pragma once
#include "Object.h"

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}
	namespace Diagnostics
	{
		class Process : public Object
		{
		public:
			O3DLIBRAIRY_API static void Start(const PrimitiveType::FString& _path, const PrimitiveType::FString& _parameters);
		};
	}


}

