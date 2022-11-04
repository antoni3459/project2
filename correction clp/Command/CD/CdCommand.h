#pragma once
#include "../ICommand.h"

class CdCommand:public ICommand
{
private:
	static std::string GetProfileFolder();

public:
	static inline std::string CurrentPath = GetProfileFolder();
public:
	CdCommand() = default;
	~CdCommand() override = default;

public:
	virtual bool Execute(const std::vector<std::string>& _args) override;
	virtual std::string CommandName()const override;
	virtual std::string Help() const override;
	virtual std::string AdvaceHelp() const override;
};

