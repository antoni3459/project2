#pragma once
#include "IGame.h"
 

class MorpionBoard;
class MorpionAI;

class MorpionGame : public IGame 
{
private:
	MorpionBoard* board = nullptr;
	MorpionAI* ai = nullptr;
	int winner = 0;
	int currentPlayer = 1;

public:
	MorpionGame();
	~MorpionGame() override;
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	void PlayerTurn(const bool& _isPlayerTwo, int& _currentMove, int& _moves);
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
};

