#pragma once
#include "Object.h"
#include <string>

class Menu : public Object
{
public:
	virtual ~Menu() = default;

public:
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Update() = 0;
	virtual std::string Name() = 0;
};
