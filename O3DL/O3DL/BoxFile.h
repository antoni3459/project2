#pragma once
#include "Object.h"
#include "FString.h"
#include <ShObjIdl_core.h>

namespace Core
{
	class BoxFile :public Object
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
		O3DLIBRAIRY_API BoxFile(const char* _title);
		O3DLIBRAIRY_API BoxFile(const BoxFile& _copy);
		O3DLIBRAIRY_API ~BoxFile()override = default;
#pragma endregion constructor

#pragma region method
	private:
		O3DLIBRAIRY_API bool InitializeBox();
		O3DLIBRAIRY_API bool CreateInstanceDialog(IFileOpenDialog*& _fileOpen);
		O3DLIBRAIRY_API bool OpenFile(IFileOpenDialog* _fileOpen, IShellItem*& _item);
		O3DLIBRAIRY_API bool GetDisplayName(IShellItem* _item, PWSTR& _filePath);
		O3DLIBRAIRY_API void SaveResult(IFileOpenDialog* _fileOpen, IShellItem* _item, PWSTR _filePath);
	public:
		O3DLIBRAIRY_API void Open();
		Core::PrimitiveType::FString Result() const;

#pragma endregion method
	};
}
