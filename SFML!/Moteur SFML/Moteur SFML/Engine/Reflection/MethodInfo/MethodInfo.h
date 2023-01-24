#pragma once
#include "../../Object/Object.h"
#include "../../PrimaryType/String/String.h"
#include "../../PrimaryType/Boolean/Boolean.h"
#include "../Flags/BindingFlags.h"
#include "../Field/FieldInfo.h"
#include <vector>


namespace Engine::Reflection
{
    UCLASS()
    template<typename Res,typename Class>
    class MethodInfo : public Object
    {
        DECLARE_CLASS_INFO(MethodInfo, Object)

#pragma region f/p

    private:
        PrimaryType::String name = "";
        std::vector<FieldInfo> info = std::vector<FieldInfo>();
        Object* instance = nullptr;
        BindingFlags flags = BindingFlags::NoPublic;
#pragma endregion f/p

#pragma region constructor

    public:
        MethodInfo() = default;
        MethodInfo(const PrimaryType::String _name, Object* _instance, BindingFlags _flags)
        {
            name = _name;
            instance = _instance;
            flags = _flags;
        }
        MethodInfo(const MethodInfo& _copy)
        {
            name = _copy.name;
            instance = _copy.instance;
            flags = _copy.flags;
        }
        ~MethodInfo()override
        {
            delete instance;
            instance = nullptr;
        }

#pragma endregion constructor

#pragma region method

    public:
        PrimaryType::Boolean IsPublic()const
        {
            return flags & BindingFlags::Public;
        }

        PrimaryType::Boolean IsPrivate()const
        {
            return flags & BindingFlags::NoPublic;
        }

        PrimaryType::Boolean IsStatic()const
        {
            return flags & BindingFlags::Static;
        }

        PrimaryType::Boolean IsArray()const
        {
            return flags & BindingFlags::Array;
        }

        PrimaryType::String Name()
        {
            return name;
        }

        Object * Instance()
        {
            return instance;
        }

        BindingFlags Flags()
        {
            return flags;
        }

        Res Invoke()
        {

        }


#pragma endregion method
    };
}