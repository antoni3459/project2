#include "MenuMorpion.h"
#include "Morpions.h"
#include "MorpionsIA.h"
#include "MenuItem.h"

MenuMorpion::MenuMorpion() : Menu("Morpions",
	{
		new MenuItem("1V1", new Morpions()),
		new MenuItem("1V IA ", new MorpionsIA()),
	})
{

}

void MenuMorpion::Open()
{
	Menu::Open();
	Update();
}
