#include "FB_Bird.h"
#include "../../Math/Mathf.h"
#include "../../Time/Time.h"
#include "../../Input/Input.h"

FB_Bird::FB_Bird() :GameObject()
{
	sprite = new sf::Sprite();
	texture = new sf::Texture();
	if (texture->loadFromFile("C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/flappy.png"))
	{
		sprite->setTexture(*texture);
	}
	sprite->setOrigin(sf::Vector2f(0, 0));
	sprite->setScale(sf::Vector2f(BIRD_SCALE, BIRD_SCALE));
	drawable = sprite;
}

FB_Bird::~FB_Bird()
{
	delete sprite;
	sprite = nullptr;
		delete texture;
	texture=nullptr;

}

void FB_Bird::Die()
{
	if (isDead)return;
	isDead = true;
	OnDie.Invoke();
}

void FB_Bird::SetWindowSize(const sf::Vector2f& _size)
{
	windowSize = _size;
}

void FB_Bird::OnUpdate()
{
	if (isDead)return;
	sprite->setPosition(Mathf::Lerp(sprite->getPosition(), sprite->getPosition() + sf::Vector2f(0, GRAVITY), BIRD_SPEED_GRAVITY * Time::deltaTime));
	if (sprite->getPosition().y <=  0 || sprite->getPosition().y >= windowSize.y-sprite->getGlobalBounds().height)
	{
		Die();
		return;
	}
	
	const float _elapsed = lastJumpTimer.getElapsedTime().asSeconds();
	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		sprite->setRotation(-15.0f);
		sprite->setPosition(sprite->getPosition() - sf::Vector2f(0, BIRD_JUMP_FORCE));
		lastJumpTimer.restart();
	}
	else if (_elapsed > 0.2f && _elapsed < 0.5f)
		sprite->setRotation(0);
	else if (_elapsed > 0.6f)
		sprite->setRotation(15.0f);
}

void FB_Bird::OnCollisionEnter(GameObject* _other)
{
	Die();
}

sf::FloatRect FB_Bird::GetGlobalBound() const
{
	return sprite->getGlobalBounds();
}

sf::Vector2f FB_Bird::Position()
{
	return sprite->getPosition();
}
