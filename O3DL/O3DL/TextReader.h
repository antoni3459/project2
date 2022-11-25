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
#pragma region method

		public:
			O3DLIBRAIRY_API void Close();
			O3DLIBRAIRY_API PrimitiveType::Boolean IsOpen() const;
			O3DLIBRAIRY_API PrimitiveType::Boolean IsValid() const;
			O3DLIBRAIRY_API PrimitiveType::Boolean ReadLine(PrimitiveType::FString& _out);
			O3DLIBRAIRY_API PrimitiveType::FString ReadLine();
			O3DLIBRAIRY_API PrimitiveType::FString ReadToEnd();
			O3DLIBRAIRY_API PrimitiveType::FString Path() const;
			O3DLIBRAIRY_API PrimitiveType::Boolean Equals(const TextReader& _textReader)const;
#pragma endregion method

#pragma region override

		public:
			O3DLIBRAIRY_API PrimitiveType::FString ToString()const override;
			O3DLIBRAIRY_API PrimitiveType::Boolean Equals(const Object* _obj)const override;
#pragma endregion override

		};
	}
}
