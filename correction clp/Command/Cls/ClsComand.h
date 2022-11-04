#pragma once
#include "../ICommand.h"

class ClsCommand:public ICommand
{
public:
	ClsCommand() = default;


	bool Execute(const std::vector<std::string>& _args)override;
	 std::string CommandName()const override;
	 std::string Help()const  override;
	 std::string AdvaceHelp()const  override;
};

