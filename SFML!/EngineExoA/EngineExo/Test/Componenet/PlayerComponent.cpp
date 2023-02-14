#include "PlayerComponent.h"
#include "../../Engine/GameObject/GameObject.h"
#include "../../Engine/Time/Time.h"

Test::PlayerComponent::PlayerComponent(const PlayerComponent& _copy) : super(_copy) {};

void Test::PlayerComponent::Update()
{
	Engine::PrimaryType::Vector2f& _position = gameObject->transform->position;
	_position = Engine::PrimaryType::Vector2f::MoveTowards(_position, Engine::PrimaryType::Vector2f(100, 0), Engine::Time::deltaTime * 10.0f);
}
