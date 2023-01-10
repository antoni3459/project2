#include "FB_Game.h"
#include "../Menu/Menu/MainMenu.h"
#include "../Menu/GameOver/FB_GameOverMenu.h"
#include "../Manager/FB_GameObjectManager.h"
#include "../../UI/Button/FB_Button.h"
#include "../../Event/Delegate/Delegate.h"
#include "../../UI/Image/FB_Image.h"
#include "../Bird/FB_Bird.h"
#include "../../FlappyBird/Pipe/FB_Pipe.h"
#include "../Score/FB_Score.h"
#include "../DeltaBase/FB_DeltaBase.h"
#include <iostream>

FB_Game::FB_Game():Window(900,500,"Flappy Bird")
{
	InitBackround();
	score = new FB_Score(this);
	score->SetPosition(sf::Vector2f(width / 2, 0));
}

FB_Game::~FB_Game()
{
	delete background;
	background = nullptr;
	delete score;
	score = nullptr;
}

void FB_Game::Start()
{
	score->Reset();
	FB_GameObjectManager::Instance()->DestroyAllRequest();
	CloseAllMenu();
	isStarted = true;
	bird = new FB_Bird();
	bird->SetWindowSize(sf::Vector2f(width, height));
	bird->OnDie.SetDynamic(this, &FB_Game::OnBirdDie);
	SpawnPipe();
	spawnerClock.restart();
}

void FB_Game::SpawnPipe()
{
	FB_Pipe* _pipe = new FB_Pipe();
	FB_Pipe* _upPiep = new FB_Pipe();
	_pipe->OnBirdPosition.SetDynamic(score, &FB_Score::UpdateScore);
	_upPiep->Rotate();

	int _random = rand() % 275 + 75;
	_pipe->SetPosition(sf::Vector2f(width + 100, _random +GAP) );
	_upPiep->SetPosition(sf::Vector2f(width + 100 + _upPiep->GetGlobalBound().width, _random));
}


void FB_Game::OnBirdDie()
{
	std::cout << "bird is die !" << std::endl;
	isStarted = false;
	dynamic_cast<FB_GameOverMenu*>(menu[GAME_OVER_MENU])->SetScore(score->CurrentScroe());
	OpenMenu(GAME_OVER_MENU);
	//TODO Open game over menu
}

void FB_Game::InitBackround()
{
	background = new FB_Image(this, "C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/background_flappybird.png");
	background->SetOrigin(sf::Vector2f(0, 0));
	background->SetPosition(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(3.0f, 3.5f));
}

void FB_Game::InitMenus()
{
	FB_MainMenu* _mainMenu = new FB_MainMenu(this);
	_mainMenu->PlayButton()->OnClick.SetDynamic(this, &FB_Game::Start);
	_mainMenu->Open();
	RegisterMenu(MAIN_MENU, _mainMenu);

	FB_GameOverMenu* _gameOverMenu = new FB_GameOverMenu(this);
	_gameOverMenu->RestartButton()->OnClick.SetDynamic(this, &FB_Game::Start);
	RegisterMenu(GAME_OVER_MENU, _gameOverMenu);
}

void FB_Game::OnDraw()
{
	background->Draw(this);
	for (std::pair<const char*, BaseMenu*> _pair : menu)
		_pair.second->Draw();
	if (!isStarted)return;
	FB_GameObjectManager::Instance()->Draw(this);
	score->Draw();
}

void FB_Game::OnUpdate()
{
	try
	{
		if (!isStarted)return;
		if (spawnerClock.getElapsedTime().asSeconds() >= TIME_FOR_SPAWN)
		{
			SpawnPipe();
			spawnerClock.restart();
		}
		FB_GameObjectManager* _instance = FB_GameObjectManager::Instance();
		_instance->CheckCollision();
		_instance->Update();
		_instance->DestroyAllRequest();
	}
	catch (const std::exception& _e)
	{
		std::cout << _e.what() << std::endl;
	}
}

void FB_Game::OnRecieveEvent(sf::Event& _event)
{
	if (_event.type == sf::Event::Resized)
	{
		width = _event.size.width;
		height = _event.size.height;
		if (bird !=nullptr)
			bird->SetWindowSize(sf::Vector2f(width, height));
	}
}
