
#include "HomeMenu.h"
#include "Item.h"
#include "Laucher.h"
#include "QuizHist.h"

HomeMenu::HomeMenu() :
	Laucher({
	new Item(new QuizHist()),
		})
{
}
