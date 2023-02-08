#include <iostream>
#include "quiz/Quizhis/Question/Question.h"
#include "quiz/Quizhis/Reponse/Réponse.h"
#include "quiz/Quizhis/QuizHist.h"
#include "HomeMenu/HomeMenu.h"
#include "Launcher/Launcher.h"
#include "Launcher/Item/Item.h"
#include "quiz/O3P/O3P.h"
#include <windows.h>


int main()
{
	SetConsoleTitle(L"Launcher");
	Launcher _laucher = Launcher({
	new Item(new QuizHist()),
	new Item(new O3P())
		});
	_laucher.Open(); 
}

