#include "Path.h"
#include "../Utils/String/StringUtils.h"

std::string Path::GetPath(const std::string& _path)
{
    return StringUtils::Replace(_path, '\\', directorySeparator);
}

std::string Path::Combine(const std::initializer_list<std::string>& _paths)
{
    const size_t _size = _paths.size();
    size_t _index = 0;
    std::string _result = "";
    for (const std::string& _str : _paths)
    {
        _result += _str;
        if (_index < _size - 1)
            _result += directorySeparator;
        _index++;
    }
    return _result;
}

std::string Path::GetParentDirectory(const std::string& _path)
{
    std::string _result = GetPath(_path);
    return _result.substr(0, _result.find_last_of(directorySeparator));
}

bool Path::HasExtension(const std::string& _path)
{
    return _path.find('.') != std::string::npos;
}
