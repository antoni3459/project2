#pragma once
#include <iostream>
#include <string>
#include "Question.h"

class R�ponse
{
private:
	std::string reponse[2] = { "1939-1945","1914-1918" };
	int* x = nullptr;
public:
	R�ponse() = default;
	~R�ponse() = default;

public:
	static bool GetReponse();
};

