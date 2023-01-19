#include "Coin.h"
#include "../../Core/Environement/Environement.h"
#include "../../Core/Utils/Path/Path.h"
#include "../Player/Player.h"

Game::Coin::Coin():super()
{
	sprite = new sf::Sprite();
	gif = new Core::Gif(Core::Utils::Path::Combine({ Core::Environement::AssetPath,"Coin","coin.gif" }).c_str());
	SetOrigin(sf::Vector2f(GetGlobalBounds().width / 2, GetGlobalBounds().height / 2));
}

Game::Coin::~Coin()
{
	delete gif;
	gif = nullptr;
}

void Game::Coin::OnUpdate()
{
}

void Game::Coin::OnCollisionEnter(GameObject* _object)
{
	Player* _player = dynamic_cast<Player*>(_object);
	if (_player == nullptr) return;
	//TODO add coin to player inventory
	Destroy(this);

}
