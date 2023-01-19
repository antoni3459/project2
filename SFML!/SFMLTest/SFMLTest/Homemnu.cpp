#include "Homemnu.h"

Homemnu::Homemnu()
{
	spriteLifePotion = new sf::Sprite();
	textureLifePotion = new sf::Texture();

	spriteManaPotion = new sf::Sprite();
	textureManaPotion = new sf::Texture();

	spriteSamy = new sf::Sprite();
	textureSamy = new sf::Texture();

	spriteGoldenSeb = new sf::Sprite();
	textureGoldenSeb = new sf::Texture();

	spriteGoldenSeb2 = new sf::Sprite();
	textureGoldenSeb2 = new sf::Texture();


	spriteBackround = new sf::Sprite();
	textureBackround = new sf::Texture();

	buttonLifePotion = new sf::Sprite();
	textureLifePotionButtonLifePotion = new sf::Texture();

	buttonManaPotion = new sf::Sprite();
	textureManaPotionButtonLifePotion = new sf::Texture();

	message = new sf::Sprite();
	textureMessage = new sf::Texture();

	font = new sf::Font();
	labelLifePotion = new sf::Text();
	labelManaPotion = new sf::Text();


	if (!textureBackround->loadFromFile("../Image/Background/Shop.png")) return;
	spriteBackround->setTexture(*textureBackround);
	spriteBackround->setScale(sf::Vector2f(1.5f, 1.2f));

	if (!textureLifePotion->loadFromFile("../Image/Item/Potion/HealPotion.png")) return;
	spriteLifePotion->setTexture(*textureLifePotion);
	spriteLifePotion->setScale(sf::Vector2f(1.f, 1.f));
	spriteLifePotion->setPosition(270, 250);

	if (!textureManaPotion->loadFromFile("../Image/Item/Potion/ManaPotion.png")) return;
	spriteManaPotion->setTexture(*textureManaPotion);
	spriteManaPotion->setScale(sf::Vector2f(1.f, 1.f));
	spriteManaPotion->setPosition(520, 250);

	if (!textureLifePotionButtonLifePotion->loadFromFile("../Image/Button/Button.png")) return;
	buttonLifePotion->setTexture(*textureLifePotionButtonLifePotion);
	buttonLifePotion->setScale(sf::Vector2f(3.9f, 3.2f));
	buttonLifePotion->setPosition(230, 400);

	if (!textureManaPotionButtonLifePotion->loadFromFile("../Image/Button/Button.png")) return;
	buttonManaPotion->setTexture(*textureManaPotionButtonLifePotion);
	buttonManaPotion->setScale(sf::Vector2f(3.9f, 3.2f));
	buttonManaPotion->setPosition(480, 400);

	if (!textureGoldenSeb->loadFromFile("../Image/Item/Coin/Seb_dor.png")) return;
	spriteGoldenSeb->setTexture(*textureGoldenSeb);
	spriteGoldenSeb->setScale(sf::Vector2f(0.2f, 0.2f));
	spriteGoldenSeb->setPosition(580, 409);

	if (!textureGoldenSeb2->loadFromFile("../Image/Item/Coin/Seb_dor.png")) return;
	spriteGoldenSeb2->setTexture(*textureGoldenSeb2);
	spriteGoldenSeb2->setScale(sf::Vector2f(0.2f, 0.2f));
	spriteGoldenSeb2->setPosition(330, 409);

	if (!textureSamy->loadFromFile("../Image/Player/Samy/Samy.png")) return;
	spriteSamy->setTexture(*textureSamy);
	spriteSamy->setScale(sf::Vector2f(2.5f, 2.5f));
	spriteSamy->setPosition(1100, 300);

	if (!textureMessage->loadFromFile("../Image/Player/Samy/bulle_message.png")) return;
	message->setTexture(*textureMessage);
	message->setScale(sf::Vector2f(0.3f, 0.3f));
	message->setPosition(1000, 200);

	if (!font->loadFromFile("../Font/ShopMenu/Vogue.ttf")) return;
	labelLifePotion->setFont(*font);
	labelLifePotion->setString("500");
	labelLifePotion->setFillColor(sf::Color::White);
	labelLifePotion->setCharacterSize(50);
	labelLifePotion->setPosition(250, 395);

	if (!font->loadFromFile("../Font/ShopMenu/Vogue.ttf")) return;
	labelManaPotion->setFont(*font);
	labelManaPotion->setString("900");
	labelManaPotion->setFillColor(sf::Color::White);
	labelManaPotion->setCharacterSize(50);
	labelManaPotion->setPosition(500, 395);


}

Homemnu::~Homemnu()
{
	delete spriteLifePotion;
	spriteLifePotion = nullptr;
	delete spriteManaPotion;
	spriteManaPotion = nullptr;
	delete spriteSamy;
	spriteSamy = nullptr;
	delete spriteGoldenSeb;
	spriteGoldenSeb = nullptr;
	delete spriteBackround;
	spriteBackround = nullptr;
	delete buttonLifePotion;
	buttonLifePotion = nullptr;
	delete buttonManaPotion;
	buttonManaPotion = nullptr;

	delete labelLifePotion;
	labelLifePotion = nullptr;
	delete labelManaPotion;
	labelManaPotion = nullptr;


}

void Homemnu::OnDraw()
{	
	Draw(spriteBackround);
	Draw(spriteSamy);

	Draw(spriteLifePotion);
	Draw(spriteManaPotion);

	Draw(buttonLifePotion);

	Draw(buttonManaPotion);
	Draw(labelLifePotion);
	Draw(labelManaPotion);
	Draw(spriteGoldenSeb);
	Draw(spriteGoldenSeb2);

	Draw(message);

}

void Homemnu::OnUpdate()
{

	//sf::Vector2i mouseposition = sf::Mouse::getPosition(*window);
	//sf::Vector2f _mouse = sf::Vector2f(mouseposition);

	//sf::FloatRect positionStart = start->getGlobalBounds();
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//{
	//	if (positionStart.contains(_mouse))
	//	{
	//		Close();
	//		Game game = Game();
	//		game.Open();
	//	}
	//}
}