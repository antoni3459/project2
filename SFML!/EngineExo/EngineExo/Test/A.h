#pragma once
#include "../Engine/Object/Object.h"
#include "../Engine/PrimaryType/FString/String.h"
#include "../Engine/PrimaryType/Integer/Integer.h"
#include "../Engine/Reflection/Function/Parameter/ParameterInfo.h"


UCLASS()
class A : public Engine::Object
{
    DECLARE_CLASS_INFO(A, Object)

private:
    UPROPERTY() static inline Engine::PrimaryType::String name = "";
REGISTER_FIELD(name, &name, BindingFlags::NoPublic | BindingFlags::Static)
    UPROPERTY() static inline Engine::PrimaryType::Integer* life = new Engine::PrimaryType::Integer(0);
REGISTER_FIELD(life, life, BindingFlags::NoPublic | BindingFlags::Static)
    
public:
    UFUNCTION() int Test(int _a);
REGISTER_METHOD(Test, &A::Test, (std::vector<Engine::Reflection::ParameterInfo*>{new Engine::Reflection::ParameterInfo("_a", 0)}), BindingFlags::Public)
};

