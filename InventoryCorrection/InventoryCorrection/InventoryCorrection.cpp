#include <iostream>
#include "Map.h"
#include "Utils.h"
#include "Player.h"
#include "Case.h"
#include "environement.h"
#include "Vector2.h"
#include "Inventory.h"
#include "Path.h"
#include "MapLoader.h"
#include "Mob.h"

int main()
{
	Player* _player = new Player(Utils::UserChoice<std::string > ("enter usename"));
	MapLoader _loader = MapLoader();
	
	_loader.Load();
	if (_loader.IsEmpty()) return -5;
	_loader.DisplayMapName();

	Map* map = _loader.GetMap(Utils::UserChoice<int>("choose map: "));
	if (!map->IsValid()) return -4;
	map->SetPlayer(_player);


	while (!map->GetPlayer()->Position()->Equal(map->Exit()->Position()))
	{
		std::vector<Mob* >mobList = map->GetMobList();// la maintenant je deplace mes truc a chaque fois que je bouge
		for (int i = 0;i < mobList.size();i++)
		{
			mobList[i]->Move();
		}
		system("cls");
		map->Display();
		map->GetPlayer()->Move();
		
	}
	system("cls");
	Utils::Log(map->GetPlayer()->Name() + " find the Exit!");
	return 0;
} 