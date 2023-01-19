#include "Environement.h"
#include "../Utils/Path/Path.h"
#include <filesystem>

const std::string Core::Environement::CurrentDirectory = std::filesystem::current_path().string();
const std::string Core::Environement::AssetPath = Core::Utils::Path::Combine({ CurrentDirectory,"Asset" });

std::vector<std::string> Core::Environement::GetAllFilesWithExtension(const char* _directory, const char* _extension)
{
    std::vector<std::string> _result = std::vector<std::string>();
    if (!std::filesystem::is_directory(_directory))
        throw std::exception(std::format("[Environement] => {} is not directory !", _directory).c_str());
        
    for (const std::filesystem::directory_entry& _entry : std::filesystem::recursive_directory_iterator(_directory))
    {
        if (std::filesystem::is_regular_file(_entry) && _entry.path().extension() == _extension)
        {
            _result.push_back(Utils::Path::GetPath(_entry.path().string()) );
        }
    }
    return _result;
}
