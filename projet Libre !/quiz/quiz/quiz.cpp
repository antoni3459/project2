#include <iostream>
#include "Question.h"
#include "R�ponse.h"
#include "QuizHist.h"
#include "HomeMenu.h"
#include "Item.h"
#include <windows.h>


int main()
{
	SetConsoleTitle(L"Launcher");
	Laucher _laucher = Laucher({
	new Item(new QuizHist()),
		});
	_laucher.Open(); 
}

