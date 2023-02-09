#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>
#include "../PrimaryType/FString/String.h"
#include "../PrimaryType/List/List.h"
#include "../Component/Component.h"
#include "../PrimaryType/Vector2/Vector2.h"
#include "../Transform/Transform.h"

ENUM(PrimitiveType, Circle, Square)

namespace Engine
{
    namespace Window
    {
        class EngineWindow;
    }

    UCLASS()
    class GameObject : public Object
    {
        DECLARE_CLASS_INFO(GameObject, Object)

#pragma region f/p
    private:
        UPROPERTY() Engine::PrimaryType::List<Component*> components = Engine::PrimaryType::List<Component*>();
REGISTER_FIELD(components, &components, BindingFlags::NoPublic)

    public:
        sf::Shape* shape = nullptr;

    public:
        UPROPERTY() PrimaryType::String name = "";
REGISTER_FIELD(name, &name, BindingFlags::Public)
        UPROPERTY() Engine::Transform* transform = nullptr;
REGISTER_FIELD(transform, transform, BindingFlags::Public)

#pragma endregion f/p

#pragma region constructor/destructor
    public:
        GameObject() = default;
        GameObject(const PrimaryType::String& _name);
        ~GameObject() override;
#pragma endregion constructor/destructor

#pragma region method
    public:
        void AddComponent(Component* _component);
        Engine::PrimaryType::List<Engine::Component*> Components()const;
        sf::Shape* Shape() const;
        void SetColor(const sf::Color& _color);
        static GameObject* CreatePrimitive(const PrimitiveType _type, const PrimaryType::String& _name);
        void Draw(const class Engine::Window::EngineWindow* _window)const;
        template<typename T>
        T* AddComponent();
        template<typename T>
        T* GetComponent();
        void OnDeserializeFinish() override;
#pragma endregion method

#pragma region operator
    public:
        GameObject& operator=(const GameObject& _other);
        PrimaryType::Boolean operator==(const GameObject& _other) const;
        PrimaryType::Boolean operator!=(const GameObject& _other) const;
#pragma endregion operator
    };

    template<typename T>
    T* GameObject::AddComponent()
    {
        static_assert(std::is_base_of_v<Component, T>, "T must be inherited of Component");
        T* _component = new T ();
        _component->gameobject = this;
        components.Add(_component);
        return _component;
    }

    template<typename T>
    inline T* GameObject::GetComponent()
    {
        const size_t _size = (size_t)components.Count();
        for (size_t i = 0; i < _size; ++i)
        {
            T* _result = dynamic_cast<T*>(components[i]);
            if (_result != nullptr) return _result;
        }
        return nullptr;
    }

}
