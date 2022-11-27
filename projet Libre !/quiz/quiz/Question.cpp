#include "Question.h"
#include "List.h"
#include <random>

int Question::GetX()
{
	return x;
}



std::string Question::GetQuestion()
{
	bool* _reponse;
	srand((unsigned int)time(NULL));
	x = (rand() % 6);
	while (List::Contains(x)==true)
	{
		srand((unsigned int)time(NULL));
		x = (rand() % 6);
	}
	List::Add(x);
	if (x < 6)
		return question[x];
	else
		GetQuestion();
}

