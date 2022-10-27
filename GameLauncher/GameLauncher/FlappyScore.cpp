#include "FlappyScore.h"
#include "Flappybird2.h"
#include "Utils.h"

void FlappyScore::Draw()
{
    Utils::SetCursorPosition(WIN_WIDTH + 7, 5);
    std::cout << "score: " << score;
}

void FlappyScore::Erase()
{
}

void FlappyScore::Update()
{
    score++;
}

FlappyScore::operator int() const
{
    return score;
}

FlappyScore& FlappyScore::operator=(const int _value)
{
    score = _value;
    return *this;
}

FlappyScore& FlappyScore::operator+=(const int _value)
{
    score += _value;
    return *this;
}
