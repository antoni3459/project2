#include "Question.h"
<<<<<<< Updated upstream
#include "List.h"
=======
#include <Windows.h>
>>>>>>> Stashed changes
#include <random>

int Question::GetX()
{
	return x;
}



std::string Question::GetQuestion()
{
	bool* _reponse;
	srand((unsigned int)time(NULL));
<<<<<<< Updated upstream
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
=======
	x = (rand() % 3);
	if (x < 3)
		return question[x];
	return "jbb";
};
>>>>>>> Stashed changes

