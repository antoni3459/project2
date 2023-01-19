#include "Player.h"
#include "../../Core/Input/Input.h"
#include "../../Core/Time/Time.h"
Game::Player::Player():super("player")
{
	checkLow((sprite != nullptr), "[Player] => sprite is nullptr")
		SetOrigin(sf::Vector2f(0, 0));
	SetScale(sf::Vector2f(0.5f, 0.5f)); 
	stats.speed = 70.0f;
}

Game::Player::Player(const Player& _copy):super(_copy)
{
	
}

Game::Player::~Player()
{
}

void Game::Player::OnUpdate()
{
	super::OnUpdate();
	if (Core::Input::IsKey(Core::EKey::D))
	{
		SetPosition(Position() + sf::Vector2f(1, 0) * stats.speed * Core::Time::deltaTime);
	}
	if (Core::Input::IsKey(Core::EKey::Q))
		SetPosition(Position() + sf::Vector2f(1, 0) * stats.speed * Core::Time::deltaTime);

}

void Game::Player::OnCollisionEnter(GameObject* _object)
{
	super::OnCollisionEnter(_object);
}
