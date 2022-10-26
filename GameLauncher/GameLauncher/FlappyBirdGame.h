#pragma once
#include "Object.h"
#pragma warning(disable: 4996)

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define GAP_SIZE 7
#define PIPE_DIF 45
#define SPACE 32
#define ESCAPE 27

class FlappyBirdGame : public Object
{
#pragma region f/p
private:
	char bird[2][6] = { '/','-','-','o','\\',' ',
				'|','_','_','_',' ','>' };
	int birdPos;
	#pragma endregion f/p

#pragma region constructeur

public:
	FlappyBirdGame() = default;
	~FlappyBirdGame() = default;
#pragma endregion constructeur

#pragma region method
public:
	void DrawBorder();
	void DrawBird();
	void EraseBird();
	void GeneratePipe(int _index);
#pragma endregion method
};

