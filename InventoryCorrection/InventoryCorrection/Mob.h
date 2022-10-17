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
//il te manquais le public devans Entity, c'est pour �a que tu reussissais pas a utiliser les fonctions qui en viennent
class Mob: public Entity //J'ai fait despragma regions, c'eest lisible plus facilement
{
#pragma region f/p 
private:
	int damage = 10;//pas besoin, je t'explique plus bas
	int life = 50;//pas besoin, c'est deja dans entity
	bool dead = false;//pas besoin, c'est deja dans entity
	Inventory* inventory=nullptr; //bonne id�e
	char caseValue = MapDataBase::Mob; //pas besoin de �a, on y a deja acc�s avec la mapDataBase
	Vector2 positionMob; //pas besoin, c'est deja dans entity
	Weapon* weapon = nullptr; //au lieu de faire une variable "degats" je lui une arme, comme �a on a deja acc�s a tout ce qu'il nous faut
	Map* map = nullptr;
#pragma endregion

#pragma region constructor/destructor
public : 
	Mob() = default;
	Mob(const std::string& _name, Vector2* _position = new Vector2(0,0), Weapon* _weapon = new Weapon("Poings",5)); // je fais un constructeur avec tout ce dont on a besoin
	Mob(const char _value, Vector2 _position); //bonne id�e de mettre un _position en parametre, j'y avais pas prens� en soit, mais il manque les autres valeurs quoi
	Mob(const Mob& _copy);
	~Mob(); //bonne id�e
#pragma endregion
#pragma region methods
	int SetDammage(); // ducoup ya plus besoin de �a
	int SetLife();//et cete fonction existe d�ja dans Entity, pas besoin de la refaire
	Inventory* GetInventory()const;
	void MoveMob(); //comme tu l'as appel� MoveMob et pas Move, tu as pas remplis le prerequis de faire une definition en override de Move, �a marchais sans doute pas a cause de �a non plus
	void Move() override;
	void AttackPlayer(Player* _player);
	Weapon* GetWeapon();
	

#pragma endregion
};

