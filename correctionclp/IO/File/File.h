#pragma once
#include "../../Object/Object.h"

class File:public Object
{
public:
	static bool Exist(const std::string& _path);
	static std::string ReadToEnd(const std::string& _path);
};

