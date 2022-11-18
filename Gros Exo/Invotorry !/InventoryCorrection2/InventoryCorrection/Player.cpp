#include "Player.h"
#include "Inventory.h"
#include "Vector2.h"
#include "Utils.h"
#include "Map.h"
#include <string>
#include <iostream>

#pragma region constructor/destructor
Player::Player(const std::string& _name,Map* _CurrentMap, Vector2* _position , const float _maxLife, const float _maxMana)
    : Entity(_name, _CurrentMap, _position ,_maxLife, _maxMana)
{
    inventory = new Inventory(_name + " Inventory", this);
    currentMap = _CurrentMap;
}

Player::Player(const Player& _copy) : Entity(_copy)
{
    inventory = _copy.inventory;
}

Player::~Player()
{
    delete inventory;
}
#pragma endregion constructor/destructor

#pragma region methods
Inventory* Player::GetInventory() const
{
    return inventory;
}
void Player::Move()
{
    char _input = Utils::UserChoice<char>("(z,q,s,d) for movement");
    Vector2 _position = *Position();
    switch (std::tolower(_input))
    {
    case 'z':
        //_position.Set(Vector2(_position.X(), _position.Y() - 1));
        _position -= Vector2(0, 1);
        break;
    case 'q':
        //_position.Set(Vector2(_position.X() - 1, _position.Y()));
        _position -= Vector2(1, 0);
        break;
    case 's':
        //_position.Set(Vector2(_position.X(), _position.Y() + 1));
        _position += Vector2(0, 1);
        break;
    case 'd':
        //_position.Set(Vector2(_position.X() + 1, _position.Y()));
        _position += Vector2(1, 0);
        break;
    }
    Case* _case = GetMap()->GetCaseAtPosition(_position);
    if (_case == nullptr || _case->IsWall()) return;
    Position()->Set(_position);
    
    
}
