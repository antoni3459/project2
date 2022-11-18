#pragma once
#include "Object.h"
namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}
	namespace Diagnostic
	{
		class Process :public Object
		{
			O3DLIBRARY_API static void Start(const PrimitiveType::FString& _path, const PrimitiveType::FString& _parameters);
		};
	}
}
