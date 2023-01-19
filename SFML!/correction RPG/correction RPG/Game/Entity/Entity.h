#pragma once
#include "../../Core/GameObject/GameObject.h"
#include "Stat/EntityStats.h"
#include "../../Core/Event/Delegate/Delegate.h"

namespace Game
{
    namespace Entity
    {
        class Entity :public Core::GameObject
        {
            DECLARE_CLASS_INFO(Entity, Core::GameObject)

        protected:
            bool isGrounded = false;
            EntityStats stats = EntityStats(100.0f, 100.0f, 10.0f);

        public:
            Core::Event::Delegate<void> OnDie = nullptr;

        public:
            Entity() = delete;
            Entity(const char* _texturePath, const EntityStats& _stats);
            Entity(const char* _texturePath);
            Entity(const Entity&) = default;

        public:
            void AddLife(float _life);
            void SetLife(float _value);
            void SetMaxLife(float _value);
            void AddMana(float _mana);
            void SetMana(float _value);
            void SetMaxMana(float _value);
            void TakeDammage(float _value);
            void Die();
            bool IsAlive()const;
            bool IsGrounded()const;
            void OnUpdate()override;

        };
    }
}

