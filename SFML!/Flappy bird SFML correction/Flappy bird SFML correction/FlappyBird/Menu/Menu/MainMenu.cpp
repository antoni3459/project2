#include "MainMenu.h"
#include "../../UI/Image/FB_Image.h"
#include "../../UI/Button/FB_Button.h"

FB_MainMenu::FB_MainMenu(Window* _owner) :BaseMenu(_owner)
{
    gifSprite = new sf::Sprite();
    InitLogoTitle();
    playButton = new FB_Button(owner, "C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/flappybird_play_button.png");
    playButton->SetScale(sf::Vector2f(0.3f, 0.3f));
    const sf::Vector2f _position = sf::Vector2f((owner->Width() / 2) - (playButton->GetGlobalBound().width + 100), owner->Height()/2);
    playButton->SetPosition(_position);
    elements.push_back(playButton);
}


FB_MainMenu::~FB_MainMenu()
{

}



void FB_MainMenu::InitLogoTitle()
{
    logoTitle = new FB_Image(owner, "C:/Users/PRAIT2401/Desktop/project2/project2/SFML!/Flappy bird SFML correction/FlappyBird/Flappy_Logo.png");
    logoTitle->SetPosition(sf::Vector2f((owner->Width() / 2) - 150,20));
    logoTitle->SetScale(sf::Vector2f(0.1f, 0.1f));
    logoTitle->SetOrigin(sf::Vector2f(logoTitle->GetGlobalBounds().width / 2, logoTitle->GetGlobalBounds().height / 2));
    elements.push_back(logoTitle);
}

FB_Button* FB_MainMenu::PlayButton() const
{
    return playButton;
}

FB_Button* FB_MainMenu::ScoreboardButton() const
{
    return scoreboardButton;
}

void FB_MainMenu::Draw()
{
    BaseMenu::Draw();
    //gif.Update(*gifSprite);
    //gifSprite->setScale(sf::Vector2f(0.5f, 0.5f));
    //owner->Draw(gifSprite);
}
