#include <iostream>
#include "Question.h"
#include "Réponse.h"

int main()
{
	Réponse _rep = Réponse();
	Question _ques = Question();
<<<<<<< Updated upstream
	while(_rep.GetScore()<5)
	{
		std::cout << _ques.GetQuestion() << std::endl;
		_rep.GetReponse();
	}
	std::cout << "vous êtes le grand gagnant " << std::endl;
	return 0;
=======
	std::cout << _ques.GetQuestion() << std::endl;
	_rep.GetReponse();
>>>>>>> Stashed changes
}

