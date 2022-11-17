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
		private :
			const char* path = nullptr;

		public:
			File() = default;
			O3DLIBRAIRY_API File(const char* _path);
			O3DLIBRAIRY_API File(const File& _copy);
			O3DLIBRAIRY_API ~File()override;

		public:
			O3DLIBRAIRY_API static FileStream* Create(const Core::PrimitiveType::FString& _path);
			O3DLIBRAIRY_API static PrimitiveType::Boolean Exist(const Core::PrimitiveType::FString& _path);
		};
	}
}