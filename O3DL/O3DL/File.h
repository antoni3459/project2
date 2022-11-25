#pragma once
#include "Object.h" 

namespace Core
{
	namespace IO
	{
		class TestWritter;
		class TextReader;
		class FileStream;

		class O3DLIBRAIRY_API File : public Object
		{
		private:
			const char* path = nullptr;

		public:
			File() = default;
			 File(const char* _path);
			 File(const File& _copy);
			 ~File()override;

		public:
			 static FileStream* Create(const Core::PrimitiveType::FString& _path);
			 static PrimitiveType::Boolean Exist(const Core::PrimitiveType::FString& _path);
		};
	}
}