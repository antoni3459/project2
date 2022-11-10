#pragma once
#include "../ICommand.h"

UCLASS()

class EchoCommand:public ICommand
{
private :
	bool isOn = true;
public:
	EchoCommand() = default;
	~EchoCommand() override = default;
public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName()const override;
	virtual std::string Help() const override;
	virtual std::string AdvaceHelp() const override;
};

