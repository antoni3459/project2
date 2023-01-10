#include "FB_Score.h"
#include "../../UI/Label/FB_Label.h"
#include <string>

FB_Score::FB_Score(Window* _owner)
{
    owner = _owner;
    scoreText = new FB_Label(_owner, "0");
}

FB_Score::~FB_Score()
{
    delete scoreText;
    scoreText = nullptr;
}

int FB_Score::CurrentScroe() const
{
    return score;
}

void FB_Score::UpdateScore()
{
    score++;
    scoreText->SetText(std::to_string(score).c_str());
}

void FB_Score::Draw()
{
    scoreText->Draw(owner);
}

void FB_Score::SetPosition(const sf::Vector2f& _position)
{   
    scoreText->SetPosition(_position);

}

void FB_Score::Reset()
{
    score = 0;
    scoreText->SetText("0");
}
