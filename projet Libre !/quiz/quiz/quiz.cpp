#include <iostream>
#include "Question.h"
#include "R�ponse.h"

int main()
{
	R�ponse _rep = R�ponse();
	Question _ques = Question();
	while(_rep.GetScore()<5)
	{
		std::cout << _ques.GetQuestion() << std::endl;
		_rep.GetReponse();
	}
	std::cout << "vous �tes le grand gagnant " << std::endl;
	return 0;
}

