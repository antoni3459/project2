#pragma once
#include "../../../Core/Object/Object.h"




namespace Game
{
    namespace Entity
    {
        class Entity;
    }

    namespace Spell
    {
        class BaseSpell :
            public Core::Object
        {
            DECLARE_CLASS_INFO(BaseSpell, Object)

        private:
            std::string name = "Default spell name";
            float cooldown = 5.0f;
            float currentCooldown = 0.0f;
            float manaCost = 1.0f;
            Entity::Entity* entity = nullptr;

        public:
            BaseSpell(const char* _name);

        public:
            virtual void OnUse() = 0;
            float Clooldown()const;
            float ManaCost()const;
            float CurrentCooldown()const;
            std::string Name()const;
            Entity::Entity* Owner()const;

        };
    }
}

