#pragma once
#include "Object.h"
namespace Core
{
	namespace PrimitiveType
	{
		class FString;
	}

	class O3DLIBRAIRY_API ClipBoard : public Object
	{
	public:
		static void Copy(const PrimitiveType::FString& _text);
	};
}

