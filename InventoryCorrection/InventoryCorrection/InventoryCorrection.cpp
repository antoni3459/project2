#include <iostream>
#include "Map.h"
#include "Utils.h"
#include "Player.h"
#include "Case.h"
#include "environement.h"
#include "Vector2.h"
#include "Inventory.h"
#include "Path.h"

int main()
{
	Map map = Map("mapTest");
	if (!map.IsValid())return -4;

	while (!map.GetPlayer()->Position()->Equal(map.Exit()->Position()))
	{
		system("cls");
		map.Display();
		map.GetPlayer()->Move();
	}
	system("cls");
	Utils::Log(map.GetPlayer()->Name() + "findthe Exit!");
	return 0;
} 