#include "Question.h"
#include <random>

int Question::GetX()
{
	return x;
}

std::string Question::GetQuestion()
{
	bool* _reponse;
	srand((unsigned int)time(NULL));
	x = (rand() % (20 - 11) + 10);
	return question[x];
}

