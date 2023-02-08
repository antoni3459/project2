#pragma once
#include "../../Menu/Menu.h"
#include "Reponse/Réponse.h"
#include "Question/Question.h"

class QuizHist:public Menu
{
private:
	int score=0 ;
public:
	 std::string GameName() override;
	 void Update() override;
	 virtual void Open() override;
	 virtual void Close() override;
};

