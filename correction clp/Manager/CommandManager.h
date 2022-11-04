#pragma once
#include "../Sigleton/Singleton.h"
#include "../Command/ICommand.h"
#include <vector>
#include <map>
class ICommand;

class CommandManager :public Singleton<CommandManager>
{
private :
	std::map<std::string, ICommand* > commands = std::map<std::string, ICommand*>();

public:
	CommandManager() = default;
	~CommandManager() = default;
		
public:
	void DisplayAllHelp()const;
	void DisplayHelp(const std::string& _label);
	void Register(ICommand* _command);
	void Register(const std::initializer_list<ICommand*>& _commands);

	void ExecuteCommand(const std::string& _label, const std::vector<std::string>& _args);
	void DisplayNotRecognized(const std::string& _label);
};

