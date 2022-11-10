#pragma once
#include "Utils.h"
#include "Help.h"
#include <string>

class Cls :public Help
{
public:
	void Open();
	std::string Name()override;
	std::string Description()override;

};

