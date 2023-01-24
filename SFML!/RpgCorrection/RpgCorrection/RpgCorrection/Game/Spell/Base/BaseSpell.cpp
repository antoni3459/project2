#include "BaseSpell.h"
#include "../../Entity/Entity.h"

Game::Spell::BaseSpell::BaseSpell(const char* _name)
{
    name = _name;
}

float Game::Spell::BaseSpell::Clooldown() const
{
    return cooldown;
}

float Game::Spell::BaseSpell::ManaCost() const
{
    return manaCost;
}

float Game::Spell::BaseSpell::CurrentCooldown() const
{
    return currentCooldown>0.0f;
}

std::string Game::Spell::BaseSpell::Name() const
{
    return name;
}

Game::Entity::Entity* Game::Spell::BaseSpell::Owner() const
{
    return entity;
}
