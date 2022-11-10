#pragma once
#include "IGame.h"
#include "FlappyMap.h"
#include "FlappyPlayer.h"
#include "FlappyScore.h"
#include "Pipe.h"

#pragma warning(disable: 4996)

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WITDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45
#define SPACE 32
#define ESCAPE 27
#define SLEEP_DEFAULT 100
#define GAP_SIZE 7
#define PRESS_ANY_KEY "Press any key"

class FlappyMap;
class FlappyPlayer;
class Pipe;

class Flappybird2 :public IGame
{
private:
	FlappyMap* map = nullptr;
	FlappyPlayer* player = nullptr;
	bool isQuitting = false;
	int sleepTime = 0;
	Pipe* pipeOne = nullptr;
	Pipe* pipeTwo = nullptr;
	FlappyScore score = FlappyScore();


public:
	Flappybird2();
	~Flappybird2();
private :
	bool IsOutOfScreen()const;
	void Draw();
	void Clear();
	void DisplayControle();
	void UpdatePipe();
	void Init();
	void UpdateScore();
public:
	
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	void PlayerTurn(const bool& _isPlayerTwo, int& _currentMove, int& _moves);
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
	
};

