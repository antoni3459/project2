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
	for (int i = 0; i < 10;i++)
	{
		std::cout << question[x] << std::endl;

		if (GetReponse())
		{
			std::cout << "gagné" << std::endl;
		}
		else
			std::cout << "perdu recommence " << i-- << std::endl;
	}
}

