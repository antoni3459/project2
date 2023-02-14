﻿#include "AssetDataBase.h"
#include <filesystem>
#include "../PrimaryType/String/String.h"
#include "../PrimaryType/Boolean/Boolean.h"

Engine::AssetDataBase::AssetDataBase(const AssetDataBase& _copy) = default;

#pragma region methods
void Engine::AssetDataBase::CreateAsset(Object* _asset, PrimaryType::String _path)
{
    if (_path.StartWith("Assets"))
    {
        const std::string& _assetPath = std::filesystem::current_path().string();
        _path = PrimaryType::String((_assetPath + "/" + _path.ToCstr()).c_str());
    }
    std::ofstream _stream = std::ofstream(_path);
    _asset->Serialize(_stream);
    _stream.close();
}
#pragma endregion methods
