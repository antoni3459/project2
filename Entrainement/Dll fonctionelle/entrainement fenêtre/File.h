#pragma once
#include "Object.h" 

namespace Core
{
	namespace IO
	{
		class TestWritter;
		class TextReader;
		class FileStream;

		class File : public Object
		{
#pragma region f/p

		private:
			const char* path = nullptr;
#pragma endregion f/p

#pragma region constructors

		public:
			File() = default;
			File(const char* _path);
			File(const File& _copy);
			~File()override;
#pragma endregion constructors

#pragma region methods

		public:
			static FileStream* Create(const Core::PrimitiveType::FString& _path);
			static PrimitiveType::Boolean Exist(const Core::PrimitiveType::FString& _path);
#pragma endregion methods

		};
	}
}