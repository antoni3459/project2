#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ShowConsole.h"
#include "Utils.h"



class Help
{
private:
	std::string name = "Help";
	std::vector<std::string> classNames = std::vector<std::string>();
	int count = 0;

public:
	Help()=default;
	Help(const std::initializer_list<std::string> _className);
	Help(const Help& _copy);
	virtual ~Help() = default;

public:
	void PushBack();
	virtual std::string Name() ;
	virtual std::string Description();
	void Open();
	int FindIndex(const std::string _cmd);
	void Display();
};

