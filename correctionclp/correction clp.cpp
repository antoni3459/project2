// correction clp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "Manager/CommandManager.h"
#include "Assembly.h"
#include "Domain/AppDomain.h"
#include "Utils/Utils.h"
#include "Command/CD/CdCommand.h"

int main()
{
    SetConsoleTitle(L"Command Prompt");
    for (ICommand* _command : AppDomain::GetAssembliesOf<ICommand>()) 
    {
        CommandManager::Instance()->Register(_command);
    }

    std::string _command = "", _label="";
    std::cout << "Microsoft Windows [version " + Utils::GetWindowsVerson() + "]" << std::endl;
    std::cout << "(c) Microsoft Corporation. All rights reserved" << std::endl << std::endl;
    while (true)
    {
        std::cout << CdCommand::CurrentPath << '>';
        std::getline(std::cin, _command);
        if (_command == "") continue;
        std::vector<std::string> _arguments = Utils::GetArguments(_command, _label);
        CommandManager::Instance()->ExecuteCommand(_label, _arguments);

    }
}
