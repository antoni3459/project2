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
class Case;
class Player;

class Map
{
#pragma region f/p
private:
	std::vector<Case*> cases = std::vector<Case*>();
	std::string mapName = "default name";
	Case* enter = nullptr;
	Case* exit = nullptr;
	Player* player = nullptr;
	std::string map1 = "The annoying map";
	std::string map2 = "The unpleasant map";
	std::string map3 = "The perfect map";
#pragma endregion f/p
#pragma region constructor
public:
	Map() = default;
	Map(const std::string& _mapName);
	Map(const Map& _copy);
	~Map();
#pragma endregion constructor
#pragma region method
	Player* GetPlayer();
	void Init();
	void Display();
	bool IsValid() const;
	Case* GetCaseAtPosition(const Vector2& _position);
	Player* GetPlayer() const;
	Case* Enter() const;
	Case* Exit() const;
	void SetMapName();
	std::string MapName() ;
#pragma endregion method

};

