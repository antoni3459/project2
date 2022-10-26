#pragma once
#include "IGame.h"
#include <vector>
#pragma warning(disable: 4996)

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WITDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45
#define SPACE 32
#define ESCAPE 27

class FlappyBird :public IGame
{
#pragma region f/p
private:
	char bird[2][6] = { {'/','-','-','o','\\',' '},{
					'|','_','_','_',' ','>'} };

	char birdNull[2][6] = { ' ',' ',' ',' ',' ',' ',
					' ',' ',' ',' ',' ',' ' };
	
	int x = 7;

#pragma endregion f/p

#pragma region constructeur
public:
	FlappyBird();
	~FlappyBird() override;

#pragma endregion constructeur

#pragma region method
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	void PlayerTurn(const bool& _isPlayerTwo, int& _currentMove, int& _moves);
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
	void DrawBorder();
	void DrawBird(int _x);
	void EraseBird(int _x );
	void GeneratePipe(int _index);
	void MoveBird();
	void Jump();
	void Down();
	bool Dead();
	bool Wall();
	void Tuyaux();
#pragma endregion method
};

