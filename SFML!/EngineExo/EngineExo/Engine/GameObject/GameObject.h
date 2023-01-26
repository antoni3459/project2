#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>
#include "../PrimaryType/FString/String.h"

ENUM(PrimitiveType, Circle, Square)

namespace Engine
{
    UCLASS()
        class GameObject : public Object
    {
        DECLARE_CLASS_INFO(GameObject, Object)

    protected:
        sf::Shape* shape = nullptr;
        PrimaryType::String name = "";

    public:
        GameObject() = default;
        GameObject(const PrimaryType::String& _name);
        GameObject(const GameObject& _copy);
        ~GameObject() override;

    public:
        sf::Shape* Shape() const;
        void SetColor(const sf::Color& _color);
        static GameObject* CreatePrimitive(const PrimitiveType _type, const PrimaryType::String& _name);

    public:
        GameObject& operator=(const GameObject& _other);
        PrimaryType::Boolean operator==(const GameObject& _other) const;
        PrimaryType::Boolean operator!=(const GameObject& _other) const;
    };

}