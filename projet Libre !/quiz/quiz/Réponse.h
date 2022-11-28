#pragma once
#include <iostream>
#include <string>
#include "Question.h"

class Réponse
{
private:
<<<<<<< Updated upstream
	std::string reponse[6] = { "1939-1945","1914-1918","6 juin 1944","1941","eisenhower","1940" };
	 int score = 0;
=======
	 std::string reponse[2] = { "1939-1945","1914-1918" };
	int count = 0;
>>>>>>> Stashed changes
public:
	Réponse() = default;
	~Réponse() = default;

public:
<<<<<<< Updated upstream
	 bool GetReponse();
	  int GetScore();
=======
	bool GetReponse();
>>>>>>> Stashed changes
};

