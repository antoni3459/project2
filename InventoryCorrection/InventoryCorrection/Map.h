#pragma once
#include <vector>
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
#include "Mob.h"
class Case;
class Player;
class Mob;

class Map : Case
{
#pragma region f/p
private:
	std::vector<Case*> cases = std::vector<Case*>();
	std::string mapName = "default name";
	std::string mapPath = "";
	Case* enter = nullptr;
	Case* exit = nullptr;
	Player* player = nullptr;
	Mob* mob =nullptr;// presque, j'ai fait un vector, comme ça on peux avoir plus d'un seul Mob dans notre map
	std::vector<Mob*> mobList = std::vector<Mob*>();
#pragma endregion f/p
#pragma region constructor
public:
	Map() = default;
	Map(const std::string _mapPath);
	Map(const Map& _copy);
	~Map();
#pragma endregion constructor
#pragma region method
	Player* GetPlayer();
	void Init();
	void Display();
	bool IsValid() const;
	Case* GetCaseAtPosition(const Vector2& _position);
	void SetPlayer(Player* _player);
	Player* GetPlayer() const;
	Mob* GetMob() const;
	std::vector<Mob*> GetMobList() const;
	Case* Enter() const;
	Case* Exit() const;
	std::string MapName() const;
#pragma endregion method

};

