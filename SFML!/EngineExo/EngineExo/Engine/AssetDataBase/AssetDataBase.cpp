#include "AssetDataBase.h"
#include "../PrimaryType/FString/String.h"
#include "../PrimaryType/Boolean/Boolean.h"
#include <filesystem>

void Engine::AssetDataBase::CreateAsset(Object* _asset, PrimaryType::String _path)
{
	if (_path.StartWith("Assets"))
	{
		std::string _assetPath = std::filesystem::current_path().string();
		_path= PrimaryType::String((_assetPath + "/" + _path.ToCstr()).c_str());
	}
	std::ofstream _stream = std::ofstream(_path);
	_asset->Serialize(_stream);
	_stream.close();
}
