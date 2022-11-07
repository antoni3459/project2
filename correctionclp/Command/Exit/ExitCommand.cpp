#include "ExitCommand.h"

bool ExitCommand::Execute(const std::vector<std::string>& _args)
{
    int _exitCode = 0;
    try
    {
        if (!_args.empty())
            _exitCode = std::stoi(_args[0]);
    }
    catch (const std::exception&)
    {
        _exitCode = -1;
    }
    exit(_exitCode);
    return true;
}

std::string ExitCommand::CommandName() const
{
    return "exit";
}

std::string ExitCommand::Help() const
{
    return "Quits the cmd.exe program (command interpreter)";
}

std::string ExitCommand::AdvaceHelp() const
{
    std::string _result = "Exit [exitcode]\n\n";
    _result += "\texitCode specifies a numeric number, sest the preocess exit code with that number";
    return _result;
}
