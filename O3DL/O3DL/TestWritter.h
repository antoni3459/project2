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
		class TestWritter :public Object
		{
#pragma region f/p
		private:
			const char* path = nullptr;
			std::ofstream stream = std::ofstream();
#pragma endregion f/p

#pragma region constructeur
		public:
			O3DLIBRAIRY_API TestWritter() = default;
			O3DLIBRAIRY_API TestWritter(const char* _path);
			O3DLIBRAIRY_API TestWritter(const PrimitiveType::FString& _path);
			O3DLIBRAIRY_API TestWritter(const TestWritter& _copy);
#pragma endregion constructeur
#pragma region method
		public:
			O3DLIBRAIRY_API PrimitiveType::Boolean IsOpen()const;
			O3DLIBRAIRY_API PrimitiveType::Boolean Exsit()const;
			O3DLIBRAIRY_API PrimitiveType::FString Path()const;

			O3DLIBRAIRY_API void Close();
			O3DLIBRAIRY_API void Clear();
			O3DLIBRAIRY_API void Write(const Object& _obj);
			O3DLIBRAIRY_API void Write(const Object* _obj);
#pragma endregion method
		public:
			PrimitiveType::FString ToString()const override;
			PrimitiveType::Boolean Equals(const Object* _obj)const override;
			PrimitiveType::Boolean Equals(const TestWritter& _obj)const;

#pragma region operrator

		public:
			void operator<<(const Object& _obj);
			void operator<<(const Object* _obj);
#pragma endregion operrator

		};
	}
}