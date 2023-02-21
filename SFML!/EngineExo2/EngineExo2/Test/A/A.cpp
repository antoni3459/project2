#include "A.h"
#include "../../Engine/AssetDataBase/AssetDataBase.h"
void Test::A::Test()
{
	A* _a = new A();
	Engine::AssetDataBase::CreateAsset(_a, "Asset/A.asset");
}
