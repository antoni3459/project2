#pragma once
#include "Engine/Object/Object.h"
#include "Engine/PrimaryType/String/String.h"
#include "Engine/Reflection/Function/Parameter/ParameterInfo.h"

namespace Test
{
	UCLASS()
		class Test :public Engine::Object
	{
	private:
		UPROPERTY() Engine::PrimaryType::String name = "";

	public:
		UFUNCTION() void Test1();
	};
}