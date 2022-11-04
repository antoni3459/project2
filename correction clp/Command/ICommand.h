#pragma once
#include "../Object/Object.h"
#include <vector>

class ICommand :public Object
{
#pragma region constructor
public:
	ICommand() = default;
	~ICommand() = default;
	#pragma endregion constructor

public:
	virtual bool Execute(const std::vector<std::string>& _args) = 0;
	virtual std::string CommandName()const = 0;
	virtual std::string Help() const = 0;
	virtual std::string AdvaceHelp() const = 0;
};