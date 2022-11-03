#pragma once
#include "Help.h"
#include <string>

class Time:public Help
{
public:
	Time() = default;
	~Time() = default;

public:
	void Open();
	void GetTime();
	std::string Name() override;
	std::string Description() override;

};
