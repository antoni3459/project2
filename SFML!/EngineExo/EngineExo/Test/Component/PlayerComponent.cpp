#include "PlayerComponent.h"
#include "../../Engine/GameObject/GameObject.h"
#include "../../Engine/Utils/DebugMacro.h"
#include "../../Engine/Time/Time.h"

void Test::PlayerComponent::Update()
{
	Engine::PrimaryType::Vector2& _position = gameobject->transform->position;
	_position = Engine::PrimaryType::Vector2::MoveTowars(_position, Engine::PrimaryType::Vector2(100, 0), Engine::Time::Time::deltaTime * 10.f);
}
