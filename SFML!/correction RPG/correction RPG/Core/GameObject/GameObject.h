#pragma once
#include "../Object/Object.h"
#include <SFML/Graphics.hpp>

namespace Core
{
    class GameObject :public Object
    {
        DECLARE_CLASS_INFO(GameObject, Object)

    protected:
        sf::Sprite* sprite = nullptr;
        sf::RectangleShape* debugShape = nullptr;
        bool canDebug = false;
        std::vector<GameObject*> collideObject = std::vector<GameObject*>();

    public:
        GameObject();
        GameObject(const GameObject& _copy);
        ~GameObject();

    public:
        static void Destroy(GameObject* _gameObject);
        std::vector<GameObject*>& CollidedObject();

        void SetCanDebug(bool _satus);
        virtual void SetPosition(const sf::Vector2f& _position);
        virtual void SetOrigin(const sf::Vector2f& _origin);
        virtual sf::Vector2f Position()const;
        virtual sf::Vector2f Origin()const;
        virtual bool IsValid()const;
        virtual void Draw(class Window* _window);
        virtual void OnUpdate();
        virtual void OnCollisionEnter(GameObject* _object);
        virtual void OnCollisionExit(GameObject* _object);
        virtual void SetScale(const sf::Vector2f& _scale);
        virtual sf::Vector2f Scale()const;
        virtual sf::FloatRect GetGlobalBounds()const;
    };
}

