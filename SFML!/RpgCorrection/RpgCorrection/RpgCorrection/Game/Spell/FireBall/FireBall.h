#pragma once
#include "../../../Core/GameObject/GameObject.h"
#include "../../../Core/Gif/Gif.h"

namespace Game
{
    namespace Entity
    {
        class Entity;
    }

    namespace Spell
    {
        class FireBall :
            public Core::GameObject
        {
            DECLARE_CLASS_INFO(FireBall, GameObject)

        private:
            Entity::Entity* owner = nullptr;
            Core::Gif* gif = nullptr;
            sf::Vector2f direction = sf::Vector2f(1, 0);
            float speed = 100.f;
            float lifeTime = 3.0f;
            float dammage = 3.0f;
            sf::Clock clock = sf::Clock();

        public:
            FireBall(Entity::Entity* _owner);
            ~FireBall()override;
        public:
            void SetDirection(const sf::Vector2f& _direction);
            void SetDammage(const float _dmg);


            void OnUpdate()override;
            void OnCollisionEnter(GameObject* _object)override;
        };
    }
}

