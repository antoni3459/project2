#include "Environment.h"
#include <shlObj_core.h>
#include <filesystem>

Core::PrimitiveType::FString Core::Environment::SpecialFolder(const ESpecialFolder& _specialFolder)
{
    TCHAR _buffer[MAX_PATH];
    SHGetSpecialFolderPath(0, _buffer, (int)_specialFolder, false);
    std::wstring _str = _buffer;
    return std::string(_str.begin(), _str.end()).c_str();
}
