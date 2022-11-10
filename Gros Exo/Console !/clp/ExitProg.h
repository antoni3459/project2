#pragma once
#include "Help.h"
#include <iostream>
#include <stdlib.h>

class ExitProg :public Help
{

public :
	void Open();
public :
	std::string Name() override;
	std::string Description() override;



};

void ExitProg::Open()
{
	exit(0);
}

std::string ExitProg::Name()
{
	return "exit";
}
std::string ExitProg::Description()
{
	return "Quits the CMD.EXE program (comand interpreter). ";
}
