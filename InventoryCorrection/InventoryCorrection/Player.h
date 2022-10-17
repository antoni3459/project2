#pragma once
#include "Entity.h"
#include "Case.h"
#include "Player.h"
#include "Map.h"
#include "Vector2.h"
class Inventory;
class Vector2;
class Case;

class Player : public Entity 
{
#pragma region f/p
private:
	Inventory* inventory = nullptr;
	int x = 0,
		y = 0;
	Vector2* position = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Player() = default;
	Player(const std::string& _name, Vector2* _position= new Vector2(0, 0), const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Player(const Player& _copy);
	~Player();
#pragma endregion constructor/destructor
#pragma region methods
	Inventory* GetInventory() const;
	void Move() override;

#pragma endregion methods
};

