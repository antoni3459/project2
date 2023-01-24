#include "FireBall.h"
#include "../../../Core/Utils/Path/Path.h"
#include "../../../Core/Utils/Debug/Debug.h"
#include "../../../Core/Environment/Environment.h"
#include "../../../Core/Time/Time.h"
#include "../../Entity/Entity.h"

Game::Spell::FireBall::FireBall(Entity::Entity* _owner):super()
{
	owner = _owner;
	sprite = new sf::Sprite();
	gif = new Core::Gif(Core::Utils::Path::Combine({ Core::Environment::AssetPath,"Spell","fireballspell.gif" }).c_str());
	sprite->setScale(0.5f, 0.5f);
}

Game::Spell::FireBall::~FireBall()
{
	delete gif;
	gif = nullptr;
}

void Game::Spell::FireBall::SetDirection(const sf::Vector2f& _direction)
{
	direction = _direction;
}

void Game::Spell::FireBall::SetDammage(const float _dmg)
{
	dammage = _dmg;
}

void Game::Spell::FireBall::OnUpdate()
{
	checkLow((gif != nullptr && sprite != nullptr), "[FireBall] => gif or sprite is nullptr")
		SetPosition(Position() + direction * speed * Core::Time::deltaTime);
	gif->Update(*sprite);
	if (clock.getElapsedTime().asSeconds() > lifeTime)
		Destroy(this);
}

void Game::Spell::FireBall::OnCollisionEnter(GameObject* _object)
{
	Entity::Entity* _other = dynamic_cast<Entity::Entity*>(_object);
	if (_other == nullptr || _other == owner)return;
	_other->TakeDamage(10.f);//TODO dammage of spell
	Destroy(this);

}
