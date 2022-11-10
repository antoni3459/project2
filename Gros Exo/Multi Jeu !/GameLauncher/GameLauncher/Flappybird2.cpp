#include "Flappybird2.h"
#include "Utils.h"
#include "FlappyMap.h"
#include "Pipe.h"
#include "FlappyScore.h"
#include <conio.h>

Flappybird2::Flappybird2()
{
    map = new FlappyMap();
    player = new FlappyPlayer();
    pipeOne=new Pipe();
    pipeTwo = new Pipe();
}

Flappybird2::~Flappybird2()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr;
    delete pipeOne;
    pipeOne = nullptr;
    delete pipeTwo;
    pipeTwo = nullptr;
}

bool Flappybird2::IsOutOfScreen() const
{
    const int _position = player->Position();
    return _position> SCREEN_HEIGHT - 2 || _position <= 3;
}

void Flappybird2::Draw()
{
    player->Draw();
    pipeOne->Draw();
    pipeTwo->Draw();
}

void Flappybird2::Clear()
{
    player->Erase();
    pipeOne->Erase();
    pipeTwo->Erase();
}

void Flappybird2::DisplayControle()
{
    Utils::SetCursorPosition(WIN_WIDTH + 5, 2);
    Utils::LogWhithEffect(GameName());
    Utils::SetCursorPosition(WIN_WIDTH + 6, 4);
    Utils::LogWhithEffect("----------");
    Utils::SetCursorPosition(WIN_WIDTH + 6, 6);
    Utils::LogWhithEffect("----------");
    Utils::SetCursorPosition(WIN_WIDTH + 7, 12);
    Utils::LogWhithEffect("Control"); 
    Utils::SetCursorPosition(WIN_WIDTH + 7, 13);
    Utils::LogWhithEffect("-------- "); 
    Utils::SetCursorPosition(WIN_WIDTH + 2, 14);
    Utils::LogWhithEffect("Spacebar for jump"); 

}

void Flappybird2::UpdatePipe()
{
    pipeOne->Update();
    pipeTwo->Update();
    const int _pipePosition = pipeOne->Position();
    if (_pipePosition >= 40 && _pipePosition < 42)
    {
        pipeTwo->SetCanDraw(true);
        pipeTwo->SetPosition(4);
        pipeTwo->SetGapPosition(3 + rand() % 14); //TODO change random
        pipeTwo->SetGapPosition(Utils::Random(3, 14)); 
    }
}

void Flappybird2::Init()
{
    isQuitting = false;
    score = 0;
    player->SetDead(false);
    player->SetPosition(6);
    pipeOne->SetCanDraw(true);
    pipeTwo->SetCanDraw(false);
    pipeOne->SetPosition(4);
    pipeTwo->SetPosition(4);
    pipeOne->SetGapPosition(3 + rand() % 14);
    pipeOne->SetGapPosition(Utils::Random(3, 14));
}

void Flappybird2::UpdateScore()
{
    if (pipeOne->Position() < 68)
    {
        //TODO score update
        score.Update();
        score.Draw();
        pipeTwo->SetCanDraw(false);
        pipeOne->SetGapPosition(pipeTwo->Position());
        pipeOne->SetGapPosition(pipeTwo->GapPosition());
    }
}

void Flappybird2::OnStart()
{

    Utils::SetCursor(false,0);
    Utils::ClearConsole(); 
    sleepTime = SLEEP_DEFAULT;
    map->Draw();
    Init();
}

void Flappybird2::OnUpdate()
{
    while (!player->IsDead() && !isQuitting)//TODO change true 
    {
        const char _input = Utils::CinNOBlock();
        if (_input == SPACE) player->Jump();
        else if (_input == ESCAPE)
        {
            isQuitting = true;
            continue;
        }
        Draw();
        
        if (player->IsCollide(pipeOne))
        {
            player->SetDead(true);
            continue;
        }
        Utils::Sleep(sleepTime);
        Clear();
        player->Update();

        if (IsOutOfScreen())
        {
            player->SetDead(true);
            continue;
        }
        
        UpdatePipe();
        UpdateScore();
    }
}

void Flappybird2::PlayerTurn(const bool& _isPlayerTwo, int& _currentMove, int& _moves)
{
}

void Flappybird2::OnEnd()
{
    player->Draw();
    Utils::SetCursorPosition(15, 5);
    std::cout << "SCORE: " << score;
    Utils::SetCursorPosition(15, 6);
    std::cout << PRESS_ANY_KEY;
    _getch();
    Utils::SetCursor(true, 20);


}

void Flappybird2::DisplayMenu()
{
    DisplayControle();
    score.Draw();
    std::cout << PRESS_ANY_KEY;
    Utils::SetCursorPosition(10, 5);
    _getch(); // _=> if not pragma warning
    Utils::SetCursorPosition(10, 5);
    std::cout << Utils::Separator(strlen(PRESS_ANY_KEY), ' ');

}

std::string Flappybird2::GameName() const
{
    return "FlappyBird !";
}

std::string Flappybird2::GameDescription() const
{
    return "Flappy Bird Game !";
}
