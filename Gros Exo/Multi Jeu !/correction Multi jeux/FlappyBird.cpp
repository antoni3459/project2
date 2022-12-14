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
		std::cout << "-+";
		Utils::SetCursorPosition(i, SCREEN_HEIGHT);
		std::cout << "+-";
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		Utils::SetCursorPosition(0, 1);
		std::cout << "+-";
		Utils::SetCursorPosition(SCREEN_WIDTH, i);
		std::cout << "+-";
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		Utils::SetCursorPosition(WIN_WIDTH, i);
		std::cout << "+-";
	}

}

void FlappyBird::EraseBird()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0;j < 6; j++)
		{
			Utils::SetCursorPosition(j + 2, i + birdPos);
			std::cout << " ";
		}
	}
}
