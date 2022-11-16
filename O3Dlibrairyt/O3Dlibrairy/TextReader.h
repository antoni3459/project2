#pragma once
#include "Object.h"
#include <fstream>

namespace Core
{
	namespace PrimitiveType
	{
		class FString;
		class Boolean;
	}
	namespace IO
	{
		class TextReader : public Object
		{
#pragma region f/p
		private:
			const char* path = nullptr;
			std::ifstream stream = std::ifstream();
#pragma endregion f/p
#pragma region constructor
		public:
			O3DLIBRAIRY_API TextReader() = default;
			O3DLIBRAIRY_API TextReader(const char* _path);
			O3DLIBRAIRY_API TextReader(const TextReader& _copy);
			O3DLIBRAIRY_API TextReader(const PrimitiveType::FString& _path);
#pragma endregion constructor



		};
	}
}

