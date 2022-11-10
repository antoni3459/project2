#pragma once
#include < vector>
#include < string>
class File
{
public:
	static std::vector<std::string>GetAllLines(const std::string& _path);
};

