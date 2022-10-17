#include "Player.h"
#include "Inventory.h"
#include "Vector2.h"
#include "Utils.h"
#include "Map.h"
#include "Mob.h"
#include "MapDaBase.h"
#include <string>
#include <iostream>


Mob::Mob(const char _value, Vector2 _position)
{
	if (_value == 'm')
	{
		caseValue = _value;
		positionMob = _position;
	}
}

Mob::Mob(const std::string& _name, Vector2* _position, Weapon* _weapon) : Entity(_name,_position)
{
	weapon = _weapon;
}

Weapon* Mob::GetWeapon()
{
	return weapon;
}

void Mob::Move()
{
	srand((unsigned int)time(NULL));
	int _move = rand() % 4;
	Vector2 positionMob = *Position();
	if (_move == 0)
		positionMob -= Vector2(0, 1);
	if (_move == 1)
		positionMob -= Vector2(1, 0);
	if (_move == 2)
		positionMob += Vector2(0, 1);
	if (_move == 3)
		positionMob += Vector2(1, 0);
	Case* _case = GetMap()->GetCaseAtPosition(positionMob);
	if (_case == nullptr || _case->IsWall()) return;
	Position()->Set(positionMob);
	
}

void Mob::AttackPlayer(Player* _player)
{
	if (weapon != nullptr)
		weapon->OnUse(_player);
}

Mob::Mob(const Mob& _copy) :Entity(_copy)
{
	inventory = _copy.inventory;
	weapon = _copy.weapon;
}

Mob::~Mob()
{
	delete inventory;
}

int Mob::SetDammage()//pas besoin du coup
{
	return damage;
}

int Mob::SetLife()//pas besoin 
{
	return life;
}

Inventory* Mob::GetInventory() const
{
	return inventory;
}

void Mob::MoveMob() // en théorie il bouge mais j'arrive pas à le tester
{
	srand((unsigned int)time(NULL));
	int _move = rand() % 4;
	Vector2 positionMob = *Position();
	if (_move==0)
		positionMob -= Vector2(0, 1);
	if (_move == 1)
		positionMob -= Vector2(1,0);
	if (_move == 2)
		positionMob += Vector2(0, 1);
	if (_move == 3)
		positionMob += Vector2(1,0);
	Case* _case = GetMap()->GetCaseAtPosition(positionMob);
	if (_case == nullptr || _case->IsWall()) return;
	Position()->Set(positionMob);
}

