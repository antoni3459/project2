#pragma once
#include "Menu.h"
#include "Réponse.h"
#include "Question.h"

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

