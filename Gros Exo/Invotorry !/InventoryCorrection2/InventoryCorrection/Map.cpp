#include "Map.h"
#include "Path.h"
#include "Environement.h"
#include "File.h"
#include "Case.h"
#include "Vector2.h"
#include "Player.h"
#include "Utils.h"
#include <iostream>

Map::Map(const std::string& _mapName)
{
	SetMapName();
	player = new Player(Utils::UserChoice<std::string>("enter your username: "), this, new Vector2(0, 0));
	Init();
}

Map::Map(const Map& _copy)
{
	mapName = _copy.mapName;
	cases = _copy.cases;
}

Map::~Map()
{
	cases.clear();
}

Player* Map::GetPlayer()
{
	return player;
}

void Map::Init()
{
	const std::string& _path = Path::Combine(Environement::CurrentDirectory(), "Maps", mapName + ".txt");
	std::vector<std::string> _lines = File::GetAllLines(_path);
	const size_t _size = _lines.size();
	std::cout << 555 << std::endl;
	for (size_t y = 0; y < _size;y++)
	{
		const std::string _line = _lines[y];
		const size_t _length = _line.length();
		for (size_t x = 0; x < _length; x++)
		{
			Vector2* _position = new Vector2(x, y);
			Case* _case = new Case(_line[x], _position);
			if (_case->IsEnter())
			{
				enter = _case;
				player->Position()->Set(*_position);
			}
			else if (_case->IsExit()) exit = _case;
			cases.push_back(_case);
		}
		cases.push_back(new Case('\n', new Vector2(-1, -1)));//TODO to chaange!
	}
}


void Map::Display()
{
	const size_t _size = cases.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (player->Position()->Equal(cases[i]->Position()))
			std::cout << MapDataBase::Player;
		else
			std::cout << cases[i]->CaseValue();
	}
}

bool Map::IsValid() const
{
	return enter != nullptr && exit !=nullptr;
}

Case* Map::GetCaseAtPosition(const Vector2& _position)
{
	const size_t _size = cases.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (cases[i]->Position()->Equal(&_position))
			return cases[i];
	}
	return nullptr;
}

Player* Map::GetPlayer() const
{
	return player;
}

Case* Map::Enter() const
{
	return enter;
}

Case* Map::Exit() const
{
	return exit;
}

void Map::SetMapName() 
{
	std::cout <<"1. " << map1 << std::endl;
	std::cout << "2. " << map2 << std::endl;
	std::cout << "3. " << map3 << std::endl;
    char _map = Utils::UserChoice<char>("Choose the map you want to play on: ");
	switch (std::tolower(_map))
	{
	case '1':
		mapName = map1;
		break;
	case '2':
		mapName = map2;
		break;
	case '3':
		mapName = map3;
		break;
	}
}

std::string Map::MapName() 
{
	return mapName;
}
