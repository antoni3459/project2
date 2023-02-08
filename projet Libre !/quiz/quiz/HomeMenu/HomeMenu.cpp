
#include "HomeMenu.h"
#include "../Launcher/Item/Item.h"
#include "../Launcher/Launcher.h"
#include "../quiz/Quizhis/QuizHist.h"

HomeMenu::HomeMenu() :
	Launcher({
	new Item(new QuizHist()),
		})
{
}
