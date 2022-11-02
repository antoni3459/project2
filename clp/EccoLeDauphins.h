#pragma once
#include <iostream>
#include "ShowConsole.h"

class EccoLeDauphins : public ShowConsole
{
private:
	std::string name = "echo";


public:
	EccoLeDauphins()=default;
	~EccoLeDauphins();

public:
	void Open();
	std::string Ecco();
	std::string GetName();
};

