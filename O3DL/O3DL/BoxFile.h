#pragma once
#include "Object.h"
#include "FString.h"
#include <ShObjIdl_core.h>

namespace Core
{
	class O3DLIBRAIRY_API BoxFile :public Object
	{
#pragma region f/p
	private:
		const char* title = "find path";
		PrimitiveType::FString pathResult = "";
		HRESULT hResult = HRESULT();
#pragma endregion f/p

#pragma region constructor
	public:
		BoxFile() = default;
		 BoxFile(const char* _title);
		 BoxFile(const BoxFile& _copy);
		 ~BoxFile()override = default;
#pragma endregion constructor

#pragma region method
	private:
		 bool InitializeBox();
		 bool CreateInstanceDialog(IFileOpenDialog*& _fileOpen);
		 bool OpenFile(IFileOpenDialog* _fileOpen, IShellItem*& _item);
		 bool GetDisplayName(IShellItem* _item, PWSTR& _filePath);
		 void SaveResult(IFileOpenDialog* _fileOpen, IShellItem* _item, PWSTR _filePath);
	public:
		 void Open();
		Core::PrimitiveType::FString Result() const;

#pragma endregion method
	};
}
