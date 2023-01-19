#pragma once
#include "../Object/Object.h"
#include <vector>

namespace Core
{


		class Environement :
			public Object
		{
			DECLARE_CLASS_INFO(Environement,Object)

		public:
			static const std::string CurrentDirectory;
			static const std::string AssetPath;
			static std::vector<std::string> GetAllFilesWithExtension(const char* _directory, const char* _extension);

		};

}
