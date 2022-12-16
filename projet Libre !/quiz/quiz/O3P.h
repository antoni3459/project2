#pragma once
#include "Menu.h"

class O3P:public Menu
{
private:
	int score = 0;

public:


	// Inherited via Menu
	virtual void Open() override;

	virtual void Update() override;

	virtual void Close() override;

	virtual std::string GameName() override;

};

