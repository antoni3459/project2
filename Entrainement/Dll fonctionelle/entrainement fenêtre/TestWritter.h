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

#pragma region constructor
		public:
			TestWritter() = default;
			TestWritter(const char* _path);
			TestWritter(const PrimitiveType::FString& _path);
			TestWritter(const TestWritter& _copy);
#pragma endregion constructor

#pragma region methods

		public:
			PrimitiveType::Boolean IsOpen()const;
			PrimitiveType::Boolean Exsit()const;
			PrimitiveType::FString Path()const;

			void Close();
			void Clear();
			void Write(const Object& _obj);
			void Write(const Object* _obj);
#pragma endregion methods

#pragma region override

		public:
			PrimitiveType::FString ToString()const override;
			PrimitiveType::Boolean Equals(const Object* _obj)const override;
			PrimitiveType::Boolean Equals(const TestWritter& _obj)const;
#pragma endregion override

#pragma region operrator

		public:
			void operator<<(const Object& _obj);
			void operator<<(const Object* _obj);
#pragma endregion operrator

		};
	}
}