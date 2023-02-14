#include "AssetDataBase.h"

#include <filesystem>
#include <fstream>

#include "../PrimaryType/FString/FString.h"
#include "../PrimaryType/Boolean/Boolean.h"

Engine::AssetDataBase::AssetDataBase(const AssetDataBase& _copy)
	: super() {}




void Engine::AssetDataBase::CreateAsset(Object* _asset, PrimaryType::FString _path)
{
	if (_path.StartWith("Assets"))
	{
		std::string _assetPath = std::filesystem::current_path().string();
 		_path = PrimaryType::FString((_assetPath + "/" + _path.ToCstr()).c_str());
	}
	std::ofstream _stream = std::ofstream(_path);
	_asset->Serialize(_stream);
	_stream.close();
}
