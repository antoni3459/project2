// correction clp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include "Manager/CommandManager.h"
#include "Command/Cls/ClsComand.h"
#include "Command/CD/CdCommand.h"
#include "Utils/Utils.h"
#include "Command/EchoCommand/EchoCommand.h"
#include "Command/Exit/ExitCommand.h"
#include "Command/TaskList/TaskListCommand.h"
#include "Command/Tree/TreeCommand.h"
#include "Command/Drive/DriveCommand.h"
#include "Command/Time/TimeCommand.h"
#include "Command/Type/TypeCommand.h"
#include "Command/Help/Help.h"
int main()
{
    SetConsoleTitle(L"Command Prompt");
    CommandManager::Instance()->Register({
        new ClsCommand(),
        new CdCommand(),
        new EchoCommand(),
        new ExitCommand(),
        new TaskListCommand(),
        new TreeCommand(),
        new DriveCommand(),
        new TimeCommand(),
        new TypeCommand(),
        new HelpCommand(),
        });


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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
