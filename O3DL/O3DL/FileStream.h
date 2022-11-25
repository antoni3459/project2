#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class TextReader;
		class TestWritter;


		class FileStream :public Object
		{
		private:
			const char* path = "";
			TextReader* reader = nullptr;
			TestWritter* writter = nullptr;
#pragma region constructor

		public:
			O3DLIBRAIRY_API FileStream() = default;
			O3DLIBRAIRY_API FileStream(const char* _path);
			O3DLIBRAIRY_API FileStream(const FileStream& _copy);
			O3DLIBRAIRY_API ~FileStream()override;

#pragma endregion constructor

#pragma region method

		public:
			O3DLIBRAIRY_API void Close();
			O3DLIBRAIRY_API TextReader* Reader()const;
			O3DLIBRAIRY_API TestWritter* Writter()const;
			O3DLIBRAIRY_API PrimitiveType::FString Path()const;
			O3DLIBRAIRY_API PrimitiveType::Boolean Equals(const FileStream& _other)const;
#pragma endregion method

		public:
			O3DLIBRAIRY_API PrimitiveType::FString ToString()const override;
			O3DLIBRAIRY_API PrimitiveType::Boolean Equals(const Object* _obj)const override;


		public:
			O3DLIBRAIRY_API void operator<<(const Object* _obj);
			O3DLIBRAIRY_API void operator<<(const Object& _obj);

		};
	}
}

