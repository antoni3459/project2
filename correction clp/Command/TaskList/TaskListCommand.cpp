#include "TaskListCommand.h"

bool TaskListCommand::Execute(const std::vector<std::string>& _args)
{
    system("tasklist");
    return true;
}

std::string TaskListCommand::CommandName() const
{
    return "tasklist";
}

std::string TaskListCommand::Help() const
{
    return "display all currenty running tasks including services.";
}

std::string TaskListCommand::AdvaceHelp() const
{
    std::string _result = "description:\n";
    _result += "\tThis tool displays a list of curently running process on local machine";
    return _result;
}
