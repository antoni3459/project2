#pragma once
#include "../Exception/Exception.h"
#include "Console/Console.h"

#define LOG(msg) Engine::Utils::Console::Log(msg);
#define LOGWARNING(msg) Engine::Utils::Console::LogWarning(msg);
#define LOGERROR(msg) Engine::Utils::Console::LogError(msg);

#define checkLow(condition, msg)\
	if(!condition)\
	{\
		LOGERROR(msg);\
		return;\
	}

#define check(condition, msg, result)\
	if(!condition)\
	{\
		LOGERROR(msg);\
		return result;\
	}

#define checkBaseOf(a, b)\
	if constexpr (!std::is_base_of_v<a, b>)\
	{\
		LOGERROR(#b " must be inherited of " #a);\
		return;\
	}