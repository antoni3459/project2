#include "DriveCommand.h"
#include <Windows.h>
#include <iostream>
bool DriveCommand::Execute(const std::vector<std::string>& _args)
{
    if (_args.size() != 0)return false;
    char* _drives= new char[MAX_PATH];
    if (GetLogicalDriveStringsA(MAX_PATH, _drives))
    {
        for (int i = 0; i < 100; i += 4)
        {
            if (_drives[i] != (char)0 && _drives[i] != (char)-51)
                std::cout << std::string{ _drives[i], _drives[i + 1], _drives[i + 3] } << std::endl;
        }
    }
    else return false;
    return true;
}

std::string DriveCommand::CommandName() const
{
    return "drives";
}

std::string DriveCommand::Help() const
{
    return  "display all adrives in the computer";
}

std::string DriveCommand::AdvaceHelp() const
{
    return Help()+"\n\nDRIVES";
}
