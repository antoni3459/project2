#pragma once
#include <iostream>
#include <string>
#include "Help.h"
 

class Echo : public Help
{
public:
	Echo()=default;
	~Echo() = default;

public:
	void Open();
	std::string Ecco();
	std::string Name() override;
	std::string Description() override;
};

