#include "QuizHist.h"
#include <iostream>
#include "Question.h"
#include "Réponse.h"
#include "Utils.h"
#include <string>

std::string QuizHist::GameName()
{
    return "Quizz Historique";
}

void QuizHist::Update()
{
	Reponse _rep = Reponse();
	Question _ques = Question();
	while (score < 5)
	{
		std::cout << _ques.GetQuestion() << std::endl;
		if (_rep.GetReponse())
		{
			score++;
		}
		Utils::Print(std::to_string(score));
	}
	std::cout << "vous êtes le grand gagnant " << std::endl;
}

void QuizHist::Open()
{
	system("cls");
}

void QuizHist::Close()
{
}
