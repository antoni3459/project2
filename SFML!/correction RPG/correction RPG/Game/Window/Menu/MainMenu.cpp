#include "MainMenu.h"
#include "../../../Core/UI/Image/Image.h"
#include "../../../Core/Utils/Debug/Debug.h"
#include "../../../Core/Window/Window.h"
#include "../../../Core/UI/Button/Button.h"

Game::MainMenu::MainMenu(Core::Window* _owner):super(_owner)
{
	//background
	InitBackround();


	//title
	InitTitle();


	//play
	InitPlayButton();


	//quit
	InitQuitButton();
}


Game::MainMenu::MainMenu(const MainMenu& _copy) :super(_copy)
{
	background=_copy.background;
	title = _copy.title;

}

void Game::MainMenu::InitBackround()
{
	background = CreateImage(sf::Vector2f(0, 0), BACKGROUND_MAIN_MENU_PATH);
	checkLow((background != nullptr && background->IsValid()), "[MainMenu] => background is nullptr or not valuid !")
		background->SetOrigin(sf::Vector2f(0, 0));
	background->SetScale(sf::Vector2f(owner->Width() / background->GlobalBounds().width, owner->Height() / background->GlobalBounds().height));
}

void Game::MainMenu::InitTitle()
{
	title = CreateImage(sf::Vector2f(owner->Width() / 2, 80), TITLE_MAIN_MENU_PATH);
	checkLow((title != nullptr && title->IsValid()), "[MainMenu] => title is nullptr or not valid !")
		title->SetOrigin(sf::Vector2f(title->GlobalBounds().width / 2, title->GlobalBounds().height / 2));
	title->SetScale(sf::Vector2f(0.5f, 0.5f));

}

void Game::MainMenu::InitPlayButton()
{
	playButton = CreateButton(sf::Vector2f(owner->Width() - 250, (owner->Height() / 2) - 100), PLAY_BUTTON_MAIN_MENU_PATH, nullptr);
	checkLow((playButton != nullptr && playButton->IsValid()), "[MainMenu] => playButton is nullptr or not valid !")
		playButton->SetScale(sf::Vector2f(0.8f, 0.8f));
	playButton->SetOrigin(sf::Vector2f(0, 0));

}

void Game::MainMenu::InitQuitButton()
{
	quitButton = CreateButton(sf::Vector2f(owner->Width() - 250, (owner->Height() / 2)), QUIT_BUTTON_MAIN_MENU_PATH, nullptr);
	checkLow((quitButton != nullptr && quitButton->IsValid()), "[MainMenu] => playButton is nullptr or not valid !")
	quitButton->SetScale(sf::Vector2f(0.8f, 0.8f));
	quitButton->SetOrigin(sf::Vector2f(0, 0));

}

void Game::MainMenu::OnResize(const sf::Vector2f& _size)
{
	background->SetScale(sf::Vector2f(_size.x / background->GlobalBounds().width, _size.y / background->GlobalBounds().height));
	title->SetPosition(sf::Vector2f(_size.x / 2, 80));

}

Core::UI::Button*& Game::MainMenu::PlayButton()
{
	return playButton;
}

Core::UI::Button*& Game::MainMenu::QuitButton()
{
	return quitButton;
}
