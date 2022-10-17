#include "Map.h"
#include "Path.h"
#include "Environement.h"
#include "File.h"
#include "Case.h"
#include "Vector2.h"
#include "Player.h"
#include "Utils.h"
#include "Mob.h"
#include <iostream>



Map::Map(const std::string _mapPath)
{
	mapPath = _mapPath;
	mapName = Path::GetFileNameWhithoutExtension(mapPath);
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
	std::vector<std::string> _lines = File::GetAllLines(mapPath);
	const size_t _size = _lines.size();
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
			}
			else if (_case->IsExit()) exit = _case;
			else if (_case->HasMob())
			{
				Mob* temp = new Mob("orc",_position);
				temp->SetMap(this);
				mobList.push_back(temp);
			}
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
		{
			for (int j = 0;j < mobList.size();j++)
			{
				if (mobList[j]->Position()->Equal(cases[i]->Position()))
				{
					std::cout << MapDataBase::Mob;
				}
			}
			if (cases[i]->HasMob())//J'essaie de ne plus afficher les endroits ou les mobs ont spawn mais j'y arrive pas vraiment
				std::cout << MapDataBase::Passage;
			else
				std::cout << cases[i]->CaseValue();
		}
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

void Map::SetPlayer(Player* _player)
{
	player = _player;
	player->Position()->Set(*enter->Position());
	player->SetMap(this);
}

Player* Map::GetPlayer() const
{
	return player;
}


Mob* Map::GetMob() const
{
	return mob;
}

std::vector<Mob*> Map::GetMobList() const
{
	return mobList;
}

Case* Map::Enter() const
{
	return enter;
}

Case* Map::Exit() const
{
	return exit;
}

std::string Map::MapName() const
{
	return mapName;
}


