#include "Exception.h"
#include <format>
#pragma region constructeur

Exception::Exception(const std::source_location& _location)
{
    std::string _filName = _location.file_name();
    _filName = _filName.substr(_filName.find_last_of('\\') + 1);
    error = std::format("{} in class {} in function {} at line {}", "error", _filName,
        _location.function_name(), _location.line());
}

Exception::Exception(const std::string& _error, const std::source_location& _location)
{
    std::string _filName = _location.file_name();
    _filName = _filName.substr(_filName.find_last_of('\\') + 1);
    error = std::format("{} in class {} in function {} at line {}",_error, _filName,
        _location.function_name(), _location.line());
}
#pragma endregion constructeur

#pragma region override

std::string Exception::ToString() const
{
    return error;
}
#pragma endregion override
