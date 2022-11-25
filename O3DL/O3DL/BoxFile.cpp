#include "BoxFile.h"
#include "FString.h"
#include <string>

Core::BoxFile::BoxFile(const char* _title)
{
	title = _title;
}

Core::BoxFile::BoxFile(const BoxFile& _copy)
{
	title = _copy.title;
	pathResult = _copy.pathResult;
	hResult = _copy.hResult;
}

bool Core::BoxFile::InitializeBox()
{
	hResult = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	return SUCCEEDED(hResult);
}

bool Core::BoxFile::CreateInstanceDialog(IFileOpenDialog*& _fileOpen)
{
	_fileOpen = { 0 };
	hResult = CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_ALL, IID_IFileOpenDialog,
		reinterpret_cast<void**>(&_fileOpen));
	return SUCCEEDED(hResult);
}

bool Core::BoxFile::OpenFile(IFileOpenDialog* _fileOpen, IShellItem*& _item)
{
	std::string _str = title;
	_fileOpen->SetTitle(std::wstring(_str.begin(), _str.end()).c_str());
	hResult = _fileOpen->Show(nullptr);
	if (!SUCCEEDED(hResult))return false;
	hResult = _fileOpen->GetResult(&_item);
	return SUCCEEDED(hResult);
}

bool Core::BoxFile::GetDisplayName(IShellItem* _item, PWSTR& _filePath)
{
	_filePath = { 0 };
	hResult = _item->GetDisplayName(SIGDN_FILESYSPATH, &_filePath);
	return SUCCEEDED(hResult);
}

void Core::BoxFile::SaveResult(IFileOpenDialog* _fileOpen, IShellItem* _item, PWSTR _filePath)
{
	const std::wstring _str = _filePath;

	const std::string _path = std::string(_str.begin(), _str.end());
	pathResult = _path.c_str();
	CoTaskMemFree(_filePath);
	_item->Release();
	_fileOpen->Release();
	CoUninitialize();
}

void Core::BoxFile::Open()
{
	if (!InitializeBox())return;
	IFileOpenDialog* _fileDialog = nullptr;
	if (!CreateInstanceDialog(_fileDialog))return;
	IShellItem* _item = nullptr;
	if (!OpenFile(_fileDialog, _item))return;
	PWSTR _filePath;
	if (!GetDisplayName(_item, _filePath))return;
	SaveResult(_fileDialog, _item, _filePath);
}
