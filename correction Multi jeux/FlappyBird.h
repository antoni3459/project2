#pragma once
#include "IGame.h"

#pragma warning(disable: 4996)

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define GAP_SIZE 7
#define PIPE_DIF 45
#define SPACE 32
#define ESCAPE 27





class FlappyBird:public IGame
{
#pragma region f/p
private:
    char bird[2][6] = { '/','-','-','o','\\',' ',
                    '|','_','_','_',' ','>' };
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
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
	void DrawBorder();
	void DrawBird();
	void EraseBird();
	void GeneratePipe(int _index);
#pragma endregion method

};

