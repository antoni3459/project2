#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class TextReader;
		class TestWritter;


		class O3DLIBRAIRY_API FileStream :public Object
		{
		private:

#pragma region f/p

			const char* path = "";
			TextReader* reader = nullptr;
			TestWritter* writter = nullptr;
#pragma endregion f/p

#pragma region constructor

		public:
			 FileStream() = default;
			 FileStream(const char* _path);
			 FileStream(const FileStream& _copy);
			 ~FileStream()override;

#pragma endregion constructor

#pragma region method

		public:
			 void Close();
			 TextReader* Reader()const;
			 TestWritter* Writter()const;
			 PrimitiveType::FString Path()const;
			 PrimitiveType::Boolean Equals(const FileStream& _other)const;
#pragma endregion method

#pragma region override

		public:
			PrimitiveType::FString ToString()const override;
			PrimitiveType::Boolean Equals(const Object* _obj)const override;
#pragma endregion override

#pragma region operator

		public:
			void operator<<(const Object* _obj);
			void operator<<(const Object& _obj);
#pragma endregion operator

		};
	}
}

