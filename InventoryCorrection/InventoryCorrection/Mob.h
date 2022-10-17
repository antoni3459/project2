#pragma once
#include "Player.h"
#include "Inventory.h"
#include "Vector2.h"
#include "Utils.h"
#include "Map.h"
#include <string>
#include <iostream>
#include "Entity.h"
#include "Vector2.h"
#include"Weapon.h"
#include "Map.h"
class Inventory;
class Vector2;
class Case;
class Player;
class Weapon;
//il te manquais le public devans Entity, c'est pour ça que tu reussissais pas a utiliser les fonctions qui en viennent
class Mob: public Entity //J'ai fait despragma regions, c'eest lisible plus facilement
{
#pragma region f/p 
private:
	int damage = 10;//pas besoin, je t'explique plus bas
	int life = 50;//pas besoin, c'est deja dans entity
	bool dead = false;//pas besoin, c'est deja dans entity
	Inventory* inventory=nullptr; //bonne idée
	char caseValue = MapDataBase::Mob; //pas besoin de ça, on y a deja accés avec la mapDataBase
	Vector2 positionMob; //pas besoin, c'est deja dans entity
	Weapon* weapon = nullptr; //au lieu de faire une variable "degats" je lui une arme, comme ça on a deja accés a tout ce qu'il nous faut
	Map* map = nullptr;
#pragma endregion

#pragma region constructor/destructor
public : 
	Mob() = default;
	Mob(const std::string& _name, Vector2* _position = new Vector2(0,0), Weapon* _weapon = new Weapon("Poings",5)); // je fais un constructeur avec tout ce dont on a besoin
	Mob(const char _value, Vector2 _position); //bonne idée de mettre un _position en parametre, j'y avais pas prensé en soit, mais il manque les autres valeurs quoi
	Mob(const Mob& _copy);
	~Mob(); //bonne idée
#pragma endregion
#pragma region methods
	int SetDammage(); // ducoup ya plus besoin de ça
	int SetLife();//et cete fonction existe déja dans Entity, pas besoin de la refaire
	Inventory* GetInventory()const;
	void MoveMob(); //comme tu l'as appelé MoveMob et pas Move, tu as pas remplis le prerequis de faire une definition en override de Move, ça marchais sans doute pas a cause de ça non plus
	void Move() override;
	void AttackPlayer(Player* _player);
	Weapon* GetWeapon();
	

#pragma endregion
};

