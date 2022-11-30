#pragma once

struct ParameterInfo
{
#pragma region f/p

private:
	const char* typeName = "";
	int position = 0;
	const char* name = "";
#pragma region f/p
#pragma region contructor

public:
	ParameterInfo(const char* _typeName,const char* _name, int _position)
	{
		typeName = _typeName;
		position = _position;
		name = _name;
	}

#pragma region contructor
#pragma region method

public:
	const char* TypeName()const
	{
		return typeName;
	}
	const char* Name()const
	{
		return name;
	}
	int Position()const
	{
		return position;
	}

#pragma region method

};
