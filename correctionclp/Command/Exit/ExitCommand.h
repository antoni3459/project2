#pragma once
#include "../ICommand.h"

UCLASS()

class ExitCommand:public ICommand
{
public:
	ExitCommand() = default;
	~ExitCommand()override = default;

public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName()const override;
	virtual std::string Help() const override;
	virtual std::string AdvaceHelp() const override;
};

