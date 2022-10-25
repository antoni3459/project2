#pragma once
#include "Object.h"
#include <vector> 

class MorpionBoard;

class MorpionAI:public Object
{
public :
	MorpionAI() = default;
	~MorpionAI() = default;

private :
	int MinMax(std::vector<int> _board, int _player);
public:
	int BestMove(MorpionBoard _board);
};

