#pragma once
#include "Object.h"
#include "FString.h"
#include <filesystem>

namespace Core
{
	enum class ESpecialFolder
	{
		Dekxtop = 0x0000,
		Programs = 0x0002,
		MyDocumments = 0x0005,
		MyMusic = 0x000d,
		MyVideo = 0x000e,
		LocalAppData = 0x001c,
		ProgramsFile = 0x0026,
		MyPictures = 0x0027,
		Profile = 0x0028,
		ProgramFilesx86 = 0x002a
	};


	class Environment : public Object
	{
	public:
		O3DLIBRAIRY_API static const inline PrimitiveType::FString CurrentDirectory = std::filesystem::current_path().string().c_str();
		O3DLIBRAIRY_API static PrimitiveType::FString SpecialFolder(const ESpecialFolder& _specialFolder);
	};
}

