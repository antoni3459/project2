#pragma once
#include "Object.h"
#include "FString.h"
#include <filesystem>
namespace Core
{
	enum class ESpecialFolder
	{
		Dekstop=0x0000,
		Programs=0x0002,
		MyDocuments=0x0005,
		MyMusic=0x000d,
		MyVideo=0x000e,
		LocalAppData=0x00c,
		ProgramsFiles=0x0026,
		MyPictures=0x0027,
		Profile=0x0028,
		ProgramFilesx86=0x002a
	};

	class Environement: public Object
	{
	public:
		O3DLIBRARY_API static PrimitiveType::FString CurrentDirectory = std::filesystem::current_path().string().c_str();
		O3DLIBRARY_API static PrimitiveType::FString SpecialFolder(const ESpecialFolder& _specialFolder);
	};
	
}
