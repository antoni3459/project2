#pragma once
#include <iostream>
#include <string>
#include "Question.h"

class Reponse
{
private:
	std::string reponse[6] = { "1939-1945","1914-1918","6-juin-1944","1941","eisenhower","1940" };
public:
	Reponse() = default;
	~Reponse() = default;

public:
	 bool GetReponse();
};

