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
		class O3DLIBRAIRY_API TextReader : public Object
		{
#pragma region f/p
		private:
			const char* path = nullptr;
			std::ifstream stream = std::ifstream();
#pragma endregion f/p

#pragma region constructor
		public:
			 TextReader() = default;
			 TextReader(const char* _path);
			 TextReader(const TextReader& _copy);
			 TextReader(const PrimitiveType::FString& _path);
#pragma endregion constructor

#pragma region method

		public:
			 void Close();
			 PrimitiveType::Boolean IsOpen() const;
			 PrimitiveType::Boolean IsValid() const;
			 PrimitiveType::Boolean ReadLine(PrimitiveType::FString& _out);
			 PrimitiveType::FString ReadLine();
			 PrimitiveType::FString ReadToEnd();
			 PrimitiveType::FString Path() const;
			 PrimitiveType::Boolean Equals(const TextReader& _textReader)const;
#pragma endregion method

#pragma region override

		public:
			 PrimitiveType::FString ToString()const override;
			 PrimitiveType::Boolean Equals(const Object* _obj)const override;
#pragma endregion override

		};
	}
}
