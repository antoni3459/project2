#pragma once
#include <iostream>
#include <string>
#include "Question.h"

class Réponse
{
private:
	std::string reponse[6] = { "1939-1945","1914-1918","6 juin 1944","1941","eisenhower","1940" };
	 int score = 0;
public:
	Réponse() = default;
	~Réponse() = default;

public:
	 bool GetReponse();
	  int GetScore();
};

