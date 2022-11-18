#include "Environement.h"
#include "FString.h"
#include <filesystem>
#include <ShlObj_core.h>


Core::PrimitiveType::FString Core::Environement::SpecialFolder(const ESpecialFolder& _specialFolder)
{
	TCHAR _buffer[MAX_PATH];
	SHGetSpecialFolderPath(0, _buffer, (int)_specialFolder, false);
	std::wstring _str = _buffer;
	return std::string(_str.begin(), _str.end()).c_str();
}
