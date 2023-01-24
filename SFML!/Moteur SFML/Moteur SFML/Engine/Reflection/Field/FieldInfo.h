#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../Flags/BindingFlags.h"



namespace Engine::Reflection
{
    UCLASS()
    class FieldInfo :public Object
    {
        DECLARE_CLASS_INFO(FieldInfo, Object)

    private:
        PrimaryType::String name = "";
        Object* reflectedObject = nullptr;
        BindingFlags flags = BindingFlags::NoPublic;

    public:
        FieldInfo() = default;
        FieldInfo(const PrimaryType::String _name, Object* _reflectedObject, BindingFlags _flags);
        //FieldInfo(const FieldInfo& _copy);
        //~FieldInfo()override;

    public:
        PrimaryType::Boolean IsPublic()const;
        PrimaryType::Boolean IsPrivate()const;
        PrimaryType::Boolean IsStatic()const;
        PrimaryType::Boolean IsArray()const;
        PrimaryType::Boolean IsReflectedClass()const;
        PrimaryType::String Name()const;
        BindingFlags Flags()const;
        Object* ReflectedObject()const;
    public:
        PrimaryType::String ToString()const override;
        Object& operator=(const Object* _obj) override;
    };
}

