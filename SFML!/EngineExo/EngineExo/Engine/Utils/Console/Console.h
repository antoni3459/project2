#pragma once
#include "../../Object/Object.h"
#include <Windows.h>

namespace Engine::Utils
{
#define color_red 4
#define color_yellow 14
#define color_white 15
	class Console : public Object
	{
		DECLARE_CLASS_INFO(Console, Object)

	private:
		static const inline HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	public:
		static void Log(const std::string& _msg);
		static void Log(const Object& _msg);
		static void Log(const ILogger* _msg);

		static void LogWarning(const std::string& _msg);
		static void LogWarning(const Object& _msg);
		static void LogWarning(const ILogger* _msg);

		static void LogError(const std::string& _msg);
		static void LogError(const Object& _msg);
		static void LogError(const ILogger* _msg);
	};
}

