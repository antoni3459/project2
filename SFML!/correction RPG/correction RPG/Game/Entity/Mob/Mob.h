#pragma once
#include "../Entity.h"

namespace Game
{
    namespace Entity
    {
        class Mob :public Entity
        {
            DECLARE_CLASS_INFO(Mob, Entity)

        private:
            sf::Vector2f aPosition = sf::Vector2f(0, 0);
            sf::Vector2f bPosition = sf::Vector2f(0, 0);
            sf::Vector2f direction = sf::Vector2f(1, 0);
            sf::Vector2f nextPosition = sf::Vector2f(0, 0);

        public:
            Mob() = delete;
            Mob(const char* _texture);

        private:
            void DestroyOnDie();
        public:
            virtual void OnPerformMovement();
            void OnUpdate();
            void SetInitialPosition(const sf::Vector2f& _position);
        };
    }
}
