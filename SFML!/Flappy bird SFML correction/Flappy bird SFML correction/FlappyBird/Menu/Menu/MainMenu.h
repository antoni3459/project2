#pragma once
#include "../../Window/Menu/BaseMenu.h"
#include "../../Utils/Gif/Gif.h"

class FB_Button;
class FB_Image;

class FB_MainMenu : public BaseMenu
{
protected:
	FB_Image* logoTitle = nullptr;
	FB_Button* playButton = nullptr;
	FB_Button* scoreboardButton = nullptr;
	sf::Sprite* gifSprite = nullptr;
	Gif gif = Gif("C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/giphy.gif");
public:
	FB_MainMenu(Window* _owner);
	virtual ~FB_MainMenu()override;
public:
	void InitLogoTitle();
	FB_Button* PlayButton()const;
	FB_Button* ScoreboardButton()const;
public:
	void Draw() override;

};

