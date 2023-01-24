#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../Object/Object.h"

namespace Core
{
    class GameObject : public Object
    {
        DECLARE_CLASS_INFO(GameObject, Object)
#pragma region f/p
    protected:
        sf::Sprite* sprite = nullptr;
        sf::RectangleShape* debugShape = nullptr;
        bool canDebug = false;
        std::vector<GameObject*> collidedObject = std::vector<GameObject*>();
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        GameObject();
        GameObject(const GameObject& _copy);
        ~GameObject() override;
#pragma endregion constructor/destructor
#pragma region methods
    public:
        static void Destroy(GameObject* _gameobject);
        std::vector<GameObject*>& CollidedObject();
        void SetCanDebug(bool _status);
        virtual void SetPosition(const sf::Vector2f& _position);
        virtual void SetOrigin(const sf::Vector2f& _origin);
        virtual sf::Vector2f Position() const;
        virtual sf::Vector2f Origin() const;
        virtual bool IsValid() const;
        virtual void Draw(class Window* _window);
        virtual void OnUpdate();
        virtual void OnCollisionEnter(GameObject* _object);
        virtual void OnCollisionExit(GameObject* _object);
        virtual void SetScale(const sf::Vector2f& _scale);
        virtual sf::Vector2f Scale() const;
        virtual sf::FloatRect GlobalBounds() const;
#pragma endregion methods
    };
}
