#pragma once
#include "../ValueType/ValueType.h"

namespace Engine::PrimaryType
{
    UCLASS()

    class Interger :public ValueType
    {
        DECLARE_CLASS_INFO(Interger, ValueType)

    private:
        int value = -1;
    public:
        static const Interger MinValue;
        static const Interger MaxValue;
        
    public:
        Interger() = default;
        Interger(int _value);
        Interger(const Interger& _copy);

    public:
        static Interger Parse(const String& _str);
        static class Boolean TryParse(const String& _str, Interger& _output);

    public:
        String ToString()const override;
        Object& operator=(const Object* _other) override;

    public:
        Interger& operator=(const Interger& _other);
        operator int();
        operator int()const;
        Boolean operator>(int _other)const;
        Boolean operator>=(int _other)const;
        Boolean operator<(int _other)const;
        Boolean operator<=(int _other)const;
        Boolean operator==(int _other)const;
        Boolean operator!=(int _other)const;
        Interger operator+(int _other)const;
        Interger operator-(int _other)const;
        Interger operator*(int _other)const;
        Interger operator/(int _other)const;
        Interger operator%(int _other)const;
        Interger& operator+=(int _other);
        Interger& operator-=(int _other);
        Interger& operator*=(int _other);
        Interger& operator/=(int _other);
        Interger& operator%=(int _other);
        Interger& operator++();
        Interger& operator--();
        Interger& operator++(int);
        Interger& operator--(int);
        Interger operator-();

    };
}

