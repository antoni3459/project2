#include "Game.h"
#include "../../Input/Input.h"
#include "../../Time/Time.h"
#include "Flappy/Flappy.h"
#include "Pipe/Pipe.h"
#include "../Lose/Lose.h"
#include <iostream>

Game::Game()
{
	flappy = new sf::Sprite();
	pipe = new sf::Sprite();
	pipe2 = new sf::Sprite();

	textureBird = new sf::Texture();
	texturePipe1 = new sf::Texture();
	texturePipe2 = new sf::Texture();

	textureArriere = new sf::Texture();
	arriere = new sf::Sprite();

	font = new sf::Font();
	text = new sf::Text();

	etbox = new sf::RectangleShape(sf::Vector2f(10,10));
	boxscore = new sf::RectangleShape(sf::Vector2f(10,10));

	if (!textureArriere->loadFromFile("../FP/arriere.png")) return;
	arriere->setTexture(*textureArriere);
	arriere->setScale(sf::Vector2f(1.9f, 1.4f));


	if (!textureBird->loadFromFile("../FP/flappy.png")) return;
	flappy->setTexture(*textureBird);
	flappy->setScale(sf::Vector2f(0.3f, 0.3f));
	flappy->setPosition(600, 400);

	if (!texturePipe1->loadFromFile("../FP/pipes.png")) return;
	pipe->setTexture(*texturePipe1);
	pipe->setScale(sf::Vector2f(0.2f, 0.3f));
	pipe->setPosition(1300, 600);

	if (!texturePipe2->loadFromFile("../FP/pipes2.png")) return;
	pipe2->setTexture(*texturePipe2);
	pipe2->setScale(sf::Vector2f(0.2f, 0.2f));
	pipe2->setPosition(1300, 1);

	etbox->setPosition(627, 442);
	etbox->setScale(sf::Vector2f(9.f, 6.6f));
	etbox->setFillColor(sf::Color::Transparent);

	boxscore->setPosition(420, 900);
	boxscore->setScale(sf::Vector2f(9.f, 10.f));
	boxscore->setFillColor(sf::Color::Transparent);

	if (!font->loadFromFile("../font/thundernova3d.ttf")) return;
	text->setFont(*font);
	text->setString(score);
	text->setFillColor(sf::Color::White);
	text->setCharacterSize(200);
	text->setPosition(1800, 30);

}

Game::~Game()
{
	delete etbox;
	etbox = nullptr;
	delete flappy;
	flappy = nullptr;
	delete pipe;
	pipe = nullptr;
	delete arriere;
	arriere = nullptr;
}

void Game::FLose()
{
	Close();
	Lose _lose = Lose();
	_lose.Open();
}

void Game::Score()
{
	score++;
	std::cout << score << std::endl;
	pipe->setPosition(1920, 600);
	pipe2->setPosition(1920, 1);
	text->setString(score);

}

void Game::OnDraw()
{
	Draw(arriere);
	Draw(flappy);
	Draw(pipe);
	Draw(pipe2);
	Draw(etbox);
	Draw(boxscore);
	Draw(text);
}

void Game::OnUpdate()
{

	Pipe _pipe = Pipe();
	Flappy _bird = Flappy();
	float _deltatime = Time::deltaTime;
	const float _speed = 20.f;
	const float _speedpipe = 20.f;

	if (Input::IsKeyDown(sf::Keyboard::Space))
	{
		_bird.MoveBird(flappy,etbox);
	}
	flappy->setPosition(flappy->getPosition() + sf::Vector2f(0, 10) * _deltatime * _speed);
	etbox->setPosition(etbox->getPosition() + sf::Vector2f(0, 10) * _deltatime * _speed);
	pipe->setPosition(pipe->getPosition() + sf::Vector2f(-10, 0) * _deltatime * _speedpipe);
	pipe2->setPosition(pipe2->getPosition() + sf::Vector2f(-10, 0) * _deltatime * _speedpipe);

	if (_pipe.Contact(etbox, pipe) || _pipe.Contact(etbox,pipe2))
	{
		FLose();
	}

	sf::Vector2f _positionPipe = pipe->getPosition();
	sf::Vector2f _positionFlap = flappy->getPosition();
	//std::cout << _positionPipe.x << std::endl;
	if (_pipe.Contact(boxscore,pipe))
	{
		Score();
	}
}
