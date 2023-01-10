#include "FB_Pipe.h"
#include "../../Time/Time.h"
#include "../Manager/Texture/FB_TextureManager.h"
#include "../Manager/FB_GameObjectManager.h"

FB_Pipe::FB_Pipe()
{
	sprite = new sf::Sprite();
	texture = FB_TextureManager::Instance()->Get("C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/pipe.png");
	sprite->setTexture(*texture);
	sprite->scale(0.1f, 0.1f);
	drawable = sprite;
}

FB_Pipe::~FB_Pipe()
{
	delete sprite;
	sprite = nullptr;
}

void FB_Pipe::Rotate()
{
	sprite->rotate(180);
}	

void FB_Pipe::Move()
{
	SetPosition(sprite->getPosition() - sf::Vector2f(1, 0) * PIPE_SPEED * Time::deltaTime);
	if (!passedBird && sprite->getPosition().x <= -0.5f && OnBirdPosition.IsValid())
	{
		OnBirdPosition.Invoke();
		passedBird = true;
	}
	if (sprite->getPosition().x < 0 - GetGlobalBound().width)
		FB_GameObjectManager::Instance()->Destroy(this);
	
}

void FB_Pipe::SetPosition(const sf::Vector2f& _position)
{
	sprite->setPosition(_position);
}

sf::FloatRect FB_Pipe::GetGlobalBound() const
{
	return sprite->getGlobalBounds();
}

sf::Vector2f FB_Pipe::Position()
{
	return sprite->getPosition();
}

void FB_Pipe::OnUpdate()
{
	Move();
}
