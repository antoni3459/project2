#include "TreeCommand.h"
#include "../CD/CdCommand.h"
#include "../../Path/Path.h"
#include <iostream>
#include <filesystem>
#include <io.h>
#include <fcntl.h>
namespace fs = std::filesystem;
void TreeCommand::RecursiveDirectory(const std::string& _path, int _index)
{
   
    const fs::directory_options _options = fs::directory_options::follow_directory_symlink | fs::directory_options::skip_permission_denied;
    for (const fs::directory_entry& _entry : fs::directory_iterator(_path, _options))
    {
        const fs::path& _path = _entry.path();
        if (_path.has_extension() || !_entry.exists() || !_entry.is_directory())continue;
        if (_index > 0)
        {
            std::string _separator = std::string(_index - 1, '\t');
            _setmode(_fileno(stdout), _O_U16TEXT);
            std::wcout << L"│";
            std::wcout << std::wstring(_separator.begin(), _separator.end());
            std::wcout << L"└───";

            _setmode(_fileno(stdout), _O_TEXT);
        }
        std::cout << _path.filename() << std::endl;
        RecursiveDirectory(_path.string(), _index + 1);
    }
}

bool TreeCommand::Execute(const std::vector<std::string>& _args)
{
    std::string _path = _args.empty() ? CdCommand::CurrentPath : _args[0];
    std::cout << _path << std::endl;
    RecursiveDirectory(_path, 1);
    return true;
}

std::string TreeCommand::CommandName() const
{
    return  "tree";
}

std::string TreeCommand::Help() const
{
    return "Graphically displays the directory structure of a drive or path.";
}

std::string TreeCommand::AdvaceHelp() const
{
    return Help() + "\n\nTREE [drive:][path]";
}
