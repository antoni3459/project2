#pragma once
#include "../../ValueType/ValueType.h"
#include "../../Boolean/Boolean.h"
#include "../../Float/Float.h"
#include <SFML/System/Vector2.hpp>
namespace Engine::PrimaryType
{
    UCLASS()
    class Vector2f : public ValueType
    {
        DECLARE_CLASS_INFO(Vector2f, ValueType)
    private:

        UPROPERTY() Float x = 0;
REGISTER_FIELD(x, &x, BindingFlags::NoPublic)
            UPROPERTY() Float y = 0;
REGISTER_FIELD(y, &y, BindingFlags::NoPublic)

    public:
        Vector2f() = default;
        Vector2f(float _x, float _y);

    public:
        static Vector2f MoveTowards(const Vector2f& _current, const Vector2f& _target, float _dt);

        void SerializeField(std::ostream& _os, const PrimaryType::FString& _fieldName, int _index) override;

        void DeSerializeField(std::istream& _os, const PrimaryType::FString& _fieldName) override;


    public:
        PrimaryType::FString ToString() const override;


    public:
        Engine::Object& operator =(const Object* _obj) override;
        operator sf::Vector2<float>() const;
        Vector2f& operator=(const Vector2f& _other);
        Vector2f& operator+=(const Vector2f& _other);
        Vector2f& operator-=(const Vector2f& _other);
        Vector2f& operator*=(const Vector2f& _other);
        Vector2f& operator/=(const Vector2f& _other);
        Vector2f operator+(const Vector2f& _other) const;
        Vector2f operator-(const Vector2f& _other) const;
        Vector2f operator*(const Vector2f& _other) const;
        Vector2f operator/(const Vector2f& _other) const;
        Boolean operator==(const Vector2f& _other) const;
        Boolean operator!=(const Vector2f& _other) const;
        Float& operator[](size_t _index);
        Float operator[](size_t _index) const;



    };
}
