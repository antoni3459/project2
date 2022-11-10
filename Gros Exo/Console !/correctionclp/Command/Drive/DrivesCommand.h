#pragma once
#include "../ICommand.h"

UCLASS()

class DrivesCommand :public ICommand
{
#pragma region override

#pragma endregion


	// Inherited via ICommand
	virtual bool Execute(const std::vector<std::string>& _args) override;

	virtual std::string CommandName() const override;

	virtual std::string Help() const override;

	virtual std::string AdvaceHelp() const override;

};

