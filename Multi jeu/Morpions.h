#pragma once
#include <iostream>
#include "Menu.h"

class Morpions :public Menu
{
#pragma region f/p
private:
	std::string plateaux[3][5] = { {"- ", "||", "-","||", "-"},
							 {"- ", "||", "-","||", "-"},
							 {"- ", "||", "-","||", "-"}
	};
	char jeux[3][5] = { {'7', ' ', '8',' ', '9'},
						{'4', ' ', '5',' ', '6'},
						{'1', ' ', '2',' ','3'} 
	};
	bool end = false,
		players = true;
#pragma endregion f/p

#pragma region constructeur
public :
	Morpions() ;
	~Morpions();

#pragma endregion constructeur
#pragma region method
public:
	void Open() override;
	void Play();
	void Display();
	void Players();
	void Play1();
	void Play2();
	bool EndGame();
#pragma endregion method
};

