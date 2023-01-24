#pragma once
#include "../ValueType/ValueType.h"
#include "../Boolean/Boolean.h"

namespace Engine::PrimaryType
{
    class Double :public ValueType
    {
        DECLARE_CLASS_INFO(Double, ValueType)
#pragma region f/p
    private:
        double value = -1.0;
    public:
        static const Double MinValue;
        static const Double MaxValue;
        static const Double Epsilon;
        static const Double NaN;
        static const Double PositiveInfinity;
        static const Double NegativeInfinity;
#pragma endregion f/p

#pragma region constructor
    public:
        Double() = default;
        Double(double _value);
        Double(const Double& _copy);
#pragma endregion constructor

#pragma region method
    public:
        static Double Parse(const String& _str);
        static Boolean TryParse(const Engine::PrimaryType::String& _str, Engine::PrimaryType::Double _output);
        static Boolean IsNaN(const Double& _value);
        static Boolean IsPositiveInfinity(const  Double& _value);
        static Boolean IsNegativeInfinity(const Double& _value);
#pragma endregion method

#pragma region operrator
    public:
        String ToString()const override;

#pragma endregion operrator

#pragma region operrator
    public:
        Double& operator=(const Double& _other);

        operator double();
        operator double()const;

        Double operator+(double _other)const;
        Double operator-(double _other)const;
        Double operator/(double _other)const;
        Double operator*(double _other)const;
        Double operator-()const;

        Double& operator+=(double _other);
        Double& operator-=(double _other);
        Double& operator/=(double _other);
        Double& operator*=(double _other);

        Boolean operator<(double _other)const;
        Boolean operator<=(double _other)const;
        Boolean operator>(double _other)const;
        Boolean operator>=(double _other)const;
        Boolean operator==(double _other)const;
        Boolean operator!=(double _other)const;
#pragma endregion operrator
    };
}

