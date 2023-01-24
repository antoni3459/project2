#pragma once
#include "../../Core/Event/Delegate/Delegate.h"
#include "../../Core/GameObject/GameObject.h"
#include "Stats/EntityStats.h"

namespace Game
{
    namespace Entity
    {
        class Entity : public Core::GameObject
        {
            DECLARE_CLASS_INFO(Entity, GameObject)
#pragma region f/p
        protected:
            bool isGrounded = false;
            EntityStats stats = EntityStats(100.0f, 100.0f, 10.0f);
        public:
            Core::Event::Delegate<void> OnDie = nullptr;
#pragma endregion f/p
#pragma region constructor/destructor
        public:
            Entity() = delete;
            Entity(const char* _texturePath, const EntityStats& _stats);
            Entity(const char* _texturePath);
            Entity(const Entity&) = default;
#pragma endregion constructor/destructor
#pragma region methods
        public:
            void AddLife(float _life);
            void SetLife(float _value);
            void SetMaxLife(float _value);
            void AddMana(float _mana);
            void SetMana(float _value);
            void SetMaxMana(float _value);
            void TakeDamage(float _value);
            void Die();
            bool IsAlive() const;
            bool IsGrounded() const;
            void OnUpdate() override;
            void OnCollisionEnter(GameObject* _object);
#pragma endregion methods
        };
    }
}
