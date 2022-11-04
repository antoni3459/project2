#pragma once
#include "../ICommand.h"

class TreeCommand :public ICommand
{
public:
	void RecursiveDirectory(const std::string& _path, int _index);
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName()const override;
	virtual std::string Help() const override;
	virtual std::string AdvaceHelp() const override;
};

