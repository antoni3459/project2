#pragma once
#include <string>
#include <iostream>
#include "Map.h"
#include "Utils.h"
#include "Player.h"
#include "Case.h"
#include "environement.h"
#include "Vector2.h"
#include "Inventory.h"
#include "Path.h"

class Map;

class MapLoader
{
private:
	std::vector<Map*>  maps = std::vector<Map*>();
	int count = 0;
public:
	MapLoader() = default;
	MapLoader(const MapLoader& _copy);
	~MapLoader();
public:
	void Load();
	int Count() const;
	bool IsEmpty()const;
	std::vector<std::string> MapsName() const;
	Map* GetMap(const int _index) const;
	void DisplayMapName();
};

