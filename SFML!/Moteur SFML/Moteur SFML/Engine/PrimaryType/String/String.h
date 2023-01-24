#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
    class Boolean;
    UCLASS()
        
    class String :
        public ValueType
    {
        DECLARE_CLASS_INFO(String, ValueType)
#pragma region f/p
    private:
        const char* value = nullptr;
        size_t length = 0;
#pragma endregion f/p

#pragma region constructor
    public:
        String() = default;
        String(const char* _value);
        String(const String& _copy);
#pragma endregion constructor

#pragma region method
    public:
        Boolean StartWth(char _c)const;
        Boolean EndWth(char _c)const;
        Boolean StartWth(const String& _str)const;
        Boolean EndWth(const String& _str)const;
        Boolean EqualsIngnoreCase(const String& _str)const;
        Boolean Containds(const String& _str)const;
        static Boolean IsNullOrEmpty(const String& _str);
        String Tolower()const;
        String ToUpper()const;
        const char* ToCstr()const;
        String SubString(int _begin)const;
        String SubString(int _begin, int _end)const;
        String Replace(char _old, char _new);
        String Replace(const String& _old, const String& _new)const;
        String Trim()const;
        int FindFirstOf(char _c);//TODO replace int with interger class
        int FindLastOf(char _c);//TODO replace int with interger class
        int Length()const;//TODO replace int with interger class
        void Append(const char* _str);
        void Append(const String& _str);
#pragma endregion method

#pragma region override
    public:
        String ToString()const override;
        Object& operator=(const Object* _other);
#pragma endregion override

#pragma region operator
    public:
        String& operator=(const String& _other);
        operator const char* ();
        operator const char* ()const;
        Boolean operator==(const String& _str);
        Boolean operator!=(const String& _str);
#pragma endregion operator
    };
}

