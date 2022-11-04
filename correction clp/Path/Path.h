#pragma once
#include "../Object/Object.h"

class Path:public Object
{
public:
	static const char directorySeparator = '/';
	static std::string GetPath(const std::string& _path);
	static std::string Combine(const std::initializer_list<std::string>& _poaths);
	static std::string GetParentDirectory(const std::string& _path);
	static bool HasExtension(const std::string& _path);
};

