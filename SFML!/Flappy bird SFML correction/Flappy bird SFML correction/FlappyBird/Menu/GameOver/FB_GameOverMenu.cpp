#include "FB_GameOverMenu.h"
#include "../../../Window/Window.h"
#include "../../../UI/Image/FB_Image.h"
#include "../../../UI/Button/FB_Button.h"
#include "../../Score/FB_Score.h"
#include "../../../UI/Label/FB_Label.h"

FB_GameOverMenu::FB_GameOverMenu(Window* _owner) :BaseMenu(_owner)
{
    const float _centerWidth = _owner->Width() / 2;
    const float _centerHeight = _owner->Height() / 2;

    gameOverImage = new FB_Image(_owner, "C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/flappyBirdGameOver.png");
    gameOverImage->SetScale(sf::Vector2f(0.2f, 0.2f));
    sf::Vector2f _position = sf::Vector2f(_centerWidth- (gameOverImage->GetGlobalBound().width/2),
        _centerHeight-(gameOverImage->GetGlobalBound().height*2));
    gameOverImage->SetPosition(_position);
    elements.push_back(gameOverImage);

    titleImage = new FB_Image(owner, "C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/Flappy_Logo.png");
    titleImage->SetPosition(sf::Vector2f(_centerWidth - 150, 20));
    titleImage->SetScale(sf::Vector2f(0.1f, 0.1f));
    titleImage->SetOrigin(sf::Vector2f(titleImage->GetGlobalBounds().width / 2, titleImage->GetGlobalBounds().height / 2));
    elements.push_back(titleImage);

    restartButton = new FB_Button(owner, "C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/flappybird_play_button.png");
    restartButton->SetScale(sf::Vector2f(0.3f, 0.3f));
    restartButton->SetPosition(sf::Vector2f(_centerWidth - (restartButton->GetGlobalBound().width + 100), _centerHeight));
    elements.push_back(restartButton);
    InitScoreText(_centerWidth, _centerHeight);
}

FB_GameOverMenu::~FB_GameOverMenu()
{

}

FB_Button* FB_GameOverMenu::RestartButton() const
{
    return restartButton;
}

void FB_GameOverMenu::InitScoreText(const float _centerWidth, const float _centerHeight)
{
    scoreText = new FB_Label(owner, "0");
    scoreText->SetColor(sf::Color::Black);
    scoreText->SetPosition(sf::Vector2f(_centerWidth - (gameOverImage->GetGlobalBound().width / 2)+scoreText->GetGlobalBound().width,
        _centerHeight - (gameOverImage->GetGlobalBound().height * 2) + 50));
    elements.push_back(scoreText);
}

void FB_GameOverMenu::SetScore(const int _score)
{
    scoreText->SetText(("Score: "+std::to_string(_score)).c_str());
}


void FB_GameOverMenu::Draw()
{
    BaseMenu::Draw();
}
