#pragma once
#include <iostream>
#include <string>
#include "Question.h"

class Réponse
{
private:
	std::string reponse[2] = { "1939-1945","1914-1918" };
	int* x = nullptr;
public:
	Réponse() = default;
	~Réponse() = default;

public:
	static bool GetReponse();
};

