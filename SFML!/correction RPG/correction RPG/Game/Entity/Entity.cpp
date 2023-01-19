#include "Entity.h"
#include "../../Core/Manager/Texture/TextureManager.h"
#include "../../Core/Utils/Mathf/Mathf.h"
#include "../../Core/Time/Time.h"
#include "../Physics/Physique.h"
#include <SFML/Graphics/Texture.hpp>

Game::Entity::Entity::Entity(const char* _texturePath, const EntityStats& _stats)
{
	stats = _stats;
	sprite = new sf::Sprite();
	sf::Texture* _texture = Core::Manager::TextureManger::Instance()->Load(_texturePath);
	checkLow((_texture != nullptr), std::format("[Entity] => error eon loaded tetxure", _texturePath));
	sprite->setTexture(*_texture);
}

Game::Entity::Entity::Entity(const char* _texturePath):self(_texturePath,EntityStats::Default)
{
}

void Game::Entity::Entity::AddLife(float _life)
{
	checkLow(_life > 0, "life must be greater than 0")
		stats.life = Core::Utils::Mathf::Clamp(stats.life + _life, 0.0f, stats.maxLife);
}

void Game::Entity::Entity::SetLife(float _value)
{
	checkLow(_value > 0, "life must be greater than 0")
		stats.life = Core::Utils::Mathf::Clamp(_value, 0.0f, stats.maxLife);
}

void Game::Entity::Entity::SetMaxLife(float _value)
{
	checkLow(_value > 0, "life must be greater than 0")
		stats.maxLife =_value;
}

void Game::Entity::Entity::AddMana(float _mana)
{
	checkLow(_mana > 0, "mana must be greater than 0")
		stats.mana = Core::Utils::Mathf::Clamp(stats.mana +_mana , 0.0f, stats.maxMana);
}

void Game::Entity::Entity::SetMana(float _value)
{
	checkLow(_value > 0, "life must be greater than 0")
		stats.mana = Core::Utils::Mathf::Clamp(_value, 0.0f, stats.maxMana);
}

void Game::Entity::Entity::SetMaxMana(float _value)
{
	checkLow(_value > 0, "mana must be greater than 0")
		stats.maxMana = _value;
}

void Game::Entity::Entity::TakeDammage(float _value)
{
	checkLow(_value > 0, "life must be greater than 0")
		stats.life = Core::Utils::Mathf::Clamp(stats.life - _value, 0.0f, stats.maxLife);
	if (stats.life == 0.0f)
		Die();
}

void Game::Entity::Entity::Die()
{
	if (OnDie.IsValid()) OnDie.Invoke();
}

bool Game::Entity::Entity::IsAlive() const
{
	return stats.life>0.0f;
}

bool Game::Entity::Entity::IsGrounded() const
{
	return isGrounded;
}

void Game::Entity::Entity::OnUpdate()
{
	super::OnUpdate();
	if (!isGrounded)
		SetPosition(Position() + sf::Vector2f(0, 1) * GRAVITY * Core::Time::deltaTime);
}
