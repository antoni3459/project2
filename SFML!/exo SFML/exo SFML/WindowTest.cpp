#include "WindowTest.h"
#include "Input.h"
#include "Time.h"

WindowTest::WindowTest()
{
	shape = new sf::RectangleShape(sf::Vector2f(50, 50));
	text = new sf::Text();
	font=new sf::Font();
	if (!font->loadFromFile("../font/thundernova3d.ttf")) return;
	text->setFont(*font);
	text->setString("FP");
	text->setCharacterSize(24);
}

WindowTest::~WindowTest()
{
	delete shape;
	shape = nullptr;
	delete text;
	text = nullptr;
	delete font;
	font = nullptr;
}

void WindowTest::OnDraw()
{
	Draw(shape);
	Draw(text);

}

void WindowTest::OnUpdate()
{
	if (Input::IsKeyDown(sf::Keyboard::D))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(5, 0));
	}
	if (Input::IsKeyDown(sf::Keyboard::Q))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(-5, 0));
	}
	if (Input::IsKeyDown(sf::Keyboard::Z))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(0, -5));
	}
	if (Input::IsKeyDown(sf::Keyboard::S))
	{
		shape->setPosition(shape->getPosition() + sf::Vector2f(0, 5));
	}

	//if (Input::IsKeyDown(sf::Keyboard::Left))
	//{
	//	shape1->setPosition(shape->getPosition() + sf::Vector2f(5, 0));
	//}
	//if (Input::IsKeyDown(sf::Keyboard::Right))
	//{
	//	shape1->setPosition(shape->getPosition() + sf::Vector2f(-5, 0));
	//}
	//if (Input::IsKeyDown(sf::Keyboard::Up))
	//{
	//	shape1->setPosition(shape->getPosition() + sf::Vector2f(0, -5));
	//}
	//if (Input::IsKeyDown(sf::Keyboard::Down))
	//{
	//	shape1->setPosition(shape->getPosition() + sf::Vector2f(0, 5));
	//}
}
