#pragma once
#include "../Object/Object.h"

namespace Engine
{
	UCLASS()
	class AssetDataBase : public Object
	{
		DECLARE_CLASS_INFO(AssetDataBase, Object)
	public:
		AssetDataBase() = default;
	public:
		static void CreateAsset(Object* _asset, PrimaryType::FString _path);
	};
}

