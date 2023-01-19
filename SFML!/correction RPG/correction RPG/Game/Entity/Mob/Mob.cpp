#include "Mob.h"
#include "../../../Core/Utils/Mathf/Mathf.h"
#include "../../../Core/Time/Time.h"
#include "../../../Core/GameObject/GameObject.h"

Game::Entity::Mob::Mob(const char* _texture):super(_texture)
{
	SetOrigin(sf::Vector2f(GetGlobalBounds().width / 2, GetGlobalBounds().height / 2));
	SetScale(sf::Vector2f(0.1f, 0.1f));
	OnDie.SetDynamic(this, &Mob::DestroyOnDie);
}

void Game::Entity::Mob::DestroyOnDie()
{
	Destroy(this);
}

void Game::Entity::Mob::OnPerformMovement()
{
	SetPosition(Position() + direction * stats.speed * Core::Time::deltaTime);
	const float _distance = Core::Utils::Mathf::Distance(Position(), nextPosition);
	if (_distance < 0.1f)
	{
		nextPosition = nextPosition == aPosition ? bPosition : aPosition;
		direction = -direction;
		SetScale(sf::Vector2f(-Scale().x, Scale().y));
	}
}

void Game::Entity::Mob::OnUpdate()
{
	Entity::OnUpdate();
	OnPerformMovement();
}

void Game::Entity::Mob::SetInitialPosition(const sf::Vector2f& _position)
{
	SetPosition(_position);
	aPosition = _position - sf::Vector2f(100, 0);
	bPosition = _position - sf::Vector2f(100, 0);
	nextPosition = bPosition;

}
