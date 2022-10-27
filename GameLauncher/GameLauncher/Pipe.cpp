#include "Pipe.h"
#include "Utils.h"
#include "FlappYbird2.h"

void Pipe::SetGapPosition(const int _gap)
{
    gapPosition = _gap;
}

void Pipe::SetPosition(const int _gap)
{
    position = _gap;
}

void Pipe::SetCanDraw(const bool _status)
{
    canDraw = _status;
}

int Pipe::GapPosition() const
{
    return gapPosition;
}

int Pipe::Position() const
{
    return position;
}

bool Pipe::CanDraw() const
{
    return canDraw;
}

void Pipe::Draw()
{
    if (!canDraw) return;
    for (int i = 0; i < gapPosition; i++)
    {
         Utils::SetCursorPosition(WIN_WIDTH - position, i + 1);
        std::cout << PIPE;
    }
    for (int i = gapPosition + GAP_SIZE; i < SCREEN_HEIGHT ; i++)
    {
        Utils::SetCursorPosition(WIN_WIDTH - position, i);
        std::cout << PIPE;
    }

}

void Pipe::Erase()
{
    if (!canDraw) return;
    for (int i = 0; i < gapPosition; i++)
    {
        Utils::SetCursorPosition(WIN_WIDTH - position, i + 1);
        std::cout << Utils::Separator(strlen(PIPE), ' ');
    }
    for (int i = gapPosition + GAP_SIZE; i < SCREEN_HEIGHT - 1; i++)
    {
        Utils::SetCursorPosition(WIN_WIDTH - position, i);
        std::cout << Utils::Separator(strlen(PIPE), ' ');
    }

}

void Pipe::Update()
{
    if (!canDraw) return;
    position += 2;
}