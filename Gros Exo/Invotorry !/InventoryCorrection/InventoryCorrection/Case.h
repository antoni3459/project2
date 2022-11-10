#pragma once
#include "MapDaBase.h"
class Vector2;

class Case
{
#pragma region f/p
private:
	char caseValue = MapDataBase::WAll;
	Vector2* position = nullptr;
#pragma endregion f/p
#pragma region constructor
public:
	Case() = default;
	Case(const char _value, Vector2* _position);
	Case(const Case& _copy);
	virtual ~Case();
#pragma endregion constructor
	
#pragma region method
public:
	bool IsWall() const;
	bool HasMob() const;
	bool IsEnter() const;
	bool IsExit() const;
	char CaseValue() const;
	Vector2* Position() const;
#pragma endregion method

};

