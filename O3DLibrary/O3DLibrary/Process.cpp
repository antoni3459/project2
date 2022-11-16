#include "Process.h"
#include "FString.h"
#include "Booleain.h"
#include <shlObj_core.h>
#include <shObjIdl_core.h>

void Core::Diagnostics::Process::Start(const PrimitiveType::FString& _path, const PrimitiveType::FString& _parameters)
{
    if (PrimitiveType::FString::IsNullOrEmpty(_path)) return;
    const std::wstring _pathOpen = _path.ToWString();
    const std::wstring _params = _parameters.ToWString();
    ShellExecute(nullptr, nullptr, _pathOpen.c_str(), _params.c_str(), nullptr, SW_SHOWNORMAL);

}
