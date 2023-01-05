#include "Pipe.h"

Pipe::Pipe()
{
	pipe = new sf::Sprite();
	texture = new sf::Texture();
	if (!texture->loadFromFile("../FP/pipes.png")) return;
	pipe->setTexture(*texture);
	pipe->setScale(sf::Vector2f(0.3f, 0.3f));
	pipe->setPosition(900, 400);
}

Pipe::~Pipe()
{
	delete texture;
	texture = nullptr;
	delete pipe;
	pipe = nullptr;
}

void Pipe::OnDraw()
{
	Draw(pipe);
}

void Pipe::OnUpdate()
{

}
