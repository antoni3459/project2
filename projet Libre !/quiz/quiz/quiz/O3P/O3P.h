#pragma once
#include "../../Menu/Menu.h"

class O3P:public Menu
{
private:
	int score = 0;

public:
	virtual void Open() override;

	virtual void Update() override;

	virtual void Close() override;

	virtual std::string GameName() override;

};

