#pragma once
#include "../../../Window/Menu/BaseMenu.h"

class FB_GameOverMenu :  public BaseMenu
{
private:
	class FB_Image* gameOverImage = nullptr;
	FB_Image* titleImage = nullptr;
	class FB_Button* restartButton = nullptr;
	class FB_Label* scoreText = nullptr;
public:
	FB_GameOverMenu(Window* _owner);
	virtual ~FB_GameOverMenu()override;

public:
	FB_Button* RestartButton()const;
	void InitScoreText(const float _centerWidth, const float _centerHeight);
	void SetScore(const int _score);
public:
	virtual void Draw()override;
};

