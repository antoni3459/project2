#include "QuizHist.h"
#include <iostream>
#include "Reponse/Réponse.h"
#include "../../Utils/Utils.h"
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
		system("cls");
		Utils::Print("SCORE : ",std::to_string(score));
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
