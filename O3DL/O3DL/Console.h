#pragma once
#include "Object.h"
#include "DateTime.h"
#include "EConsoleColor.h"
#include <Windows.h>
namespace Core
{
#define LOG(obj) Core::Console::WritLine("[LOG]", obj);
#define LOG_WARNING(obj) Core::Console::WritLine("[WARNING]", obj, Core::EConsoleColor::Yellow);
#define LOG_ERROR(obj) Core::Console::WritLine("[ERROR]", obj, Core::EConsoleColor::Red);

    namespace IO
    {
        class TestWritter;
    }

    class Console : public Object
    {
#pragma region f/p

    private:
        static inline HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    public:
        static IO::TestWritter* Out;
#pragma endregion f/p

#pragma region method

    private:
        O3DLIBRAIRY_API static IO::TestWritter* Out_Internal();
    public:
        O3DLIBRAIRY_API static void WritLine(const PrimitiveType::FString& _label, const object _obj, const EConsoleColor& _color = EConsoleColor::Reset);
        O3DLIBRAIRY_API static void WritLine(const PrimitiveType::FString& _label, const object& _obj, const EConsoleColor& _color = EConsoleColor::Reset);

#pragma endregion method

    };
}
