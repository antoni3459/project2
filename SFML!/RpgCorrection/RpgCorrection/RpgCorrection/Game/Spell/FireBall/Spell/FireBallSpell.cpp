#include "FireBallSpell.h"
#include "../FireBall.h"
#include "../../../Entity/Entity.h"

Game::Spell::FireBallSpell::FireBallSpell(Entity::Entity* _entity):super("Fireball")
{
	owner = _entity;
}

void Game::Spell::FireBallSpell::OnUse()
{
	FireBall* _fireBall = new FireBall(owner);
	_fireBall->SetPosition(owner->Position() + sf::Vector2f(_fireBall->GlobalBounds().width, 0));

}
