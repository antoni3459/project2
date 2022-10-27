#include "FlappyBird.h"
#include "Utils.h"
#include <conio.h>
#include <iostream>

FlappyBird::FlappyBird()
{

}

FlappyBird::~FlappyBird()
{
}

void FlappyBird::OnStart()
{
}

void FlappyBird::OnUpdate()
{
}

void FlappyBird::PlayerTurn(const bool& _isPlayerTwo, int& _currentMove, int& _moves)
{
}

void FlappyBird::OnEnd()
{
}

void FlappyBird::DisplayMenu()
{
	Utils::ClearConsole();
	Utils::LogTitle(GameName());
	const std::string _msg = "1- Play\n2- instruction\n3- quit";
	char _choice = Utils::UserChoice<char>(_msg, '0', '1', '2');
	if (_choice == '2')
		std::cout << "espace pour sauter" << std::endl;
	else
	{
		Utils::ClearConsole();
	    DrawBorder();
	}
}

std::string FlappyBird::GameName() const
{
    return "FlappyBird";
}

std::string FlappyBird::GameDescription() const
{
    return std::string();
}

void FlappyBird::DrawBorder()
{
	for (int i = 0;i < SCREEN_WIDTH;i++)
	{
		Utils::SetCursorPosition(i, 0);
		std::cout << "±";
		Utils::SetCursorPosition(i, SCREEN_HEIGHT);
		std::cout << "±";
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		Utils::SetCursorPosition(0, i);
		std::cout << "±";
		Utils::SetCursorPosition(SCREEN_WIDTH, i);
		std::cout << "±";
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		Utils::SetCursorPosition(WIN_WIDTH, i);
		std::cout << "±";
	}


	DrawBird(x);
	while (Dead())
	{
		MoveBird();
		Tuyaux();
	}
}

void FlappyBird::DrawBird( const int _x)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6;j++)
		{
			Utils::SetCursorPosition(j + 2, i + _x);
			std::cout << bird[i][j];
		}
	}
}

void FlappyBird::EraseBird(int _x)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6;j++)
		{
			Utils::SetCursorPosition(j + 2, i + _x);
			std::cout << birdNull[i][j];
		}
	}
}

void FlappyBird::GeneratePipe(int _index)
{
}

void FlappyBird::MoveBird()
{
	DrawBird(x);
	while (Dead())
	{
		if (Utils::CinNOBlock() == ' ')
		{
			Jump();
		}
		Down();
		Sleep(100);
	}
}

void FlappyBird::Jump()
{
	EraseBird(x);
	x -= 3;
	DrawBird(x);
}

void FlappyBird::Down()
{
	EraseBird(x);
	x++ ;
	DrawBird(x);
}

bool FlappyBird::Wall()
{
    if (x>23 || x<2)
	{
		return false;
	}
	else
		return true ;
}

bool FlappyBird::Dead()
{
	if (Wall() == false)
	{
		system("cls");
		std::cout << "GAME OVER"<<std::endl;
		Utils::Pause();
		return false;
	}
		
}
void FlappyBird::Tuyaux()
{
	
}
