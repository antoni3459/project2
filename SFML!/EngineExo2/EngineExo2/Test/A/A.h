#pragma once
#include "../../Engine/Object/Object.h"
#include "../../Engine/PrimaryType/Integer/Integer.h"
#include "../../Engine/PrimaryType/String/String.h"
#include "../../Engine/PrimaryType/Boolean/Boolean.h"


namespace Test
{
    UCLASS()
        class A : public Engine::Object
    {
    private:
        UPROPERTY() Engine::PrimaryType::Integer age = 5;
REGISTER_FIELD(age, &age, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::String name = "Bastien";
REGISTER_FIELD(name, &name, BindingFlags::NoPublic)
            UPROPERTY() Engine::PrimaryType::Boolean alive = false;
REGISTER_FIELD(alive, &alive, BindingFlags::NoPublic)

    public:
        static void Test();
    };
}
