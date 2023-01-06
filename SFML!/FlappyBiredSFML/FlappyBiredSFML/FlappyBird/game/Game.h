#pragma once
#include "../../Window/Window.h"
#include "../menu/Menu.h"

class Game : public Window
{
private:
    sf::Sprite* flappy=nullptr;
    sf::Sprite* pipe=nullptr;
    sf::Sprite* pipe2=nullptr;
    sf::Sprite* arriere=nullptr;

    sf::Texture* textureBird=nullptr;
    sf::Texture* texturePipe1=nullptr;
    sf::Texture* texturePipe2 = nullptr;
    sf::Texture* textureArriere = nullptr;

    sf::Font* font = nullptr;
    sf::Text* text = nullptr;

    sf::RectangleShape* etbox = nullptr;
    sf::RectangleShape* boxscore = nullptr;

    char score;
public:
    Game();
    ~Game() override;

public:
    void FLose();

public:
    void Score();

public:
    virtual void OnDraw() override;
    virtual void OnUpdate() override;
};

