#include "HomeMenu.h"
#include "Menu.h"
#include "Morpions.h"
#include "MenuMorpion.h"

HomeMenu::HomeMenu() :  Menu("Home", {
	new MenuItem("Morpions" , new MenuMorpion())
	})
{
}

