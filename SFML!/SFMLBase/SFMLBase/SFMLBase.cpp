// SFMLBase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow _window(sf::VideoMode(900, 800), "First SFML");
	_window.setFramerateLimit(60);
	sf::RectangleShape _shape(sf::Vector2f(200, 100));
	sf::RectangleShape _shape1(sf::Vector2f(200, 100));
	sf::Clock _clock;
	float _deltatime = 0.0f;
	const float _speed = 1.5f;
	_shape.setPosition(450, 400);
	_shape1.setPosition(800, 400);

	_shape.setFillColor(sf::Color::Red);
	while (_window.isOpen())
	{
		sf::Time _elapsed = _clock.restart();
		_deltatime = _elapsed.asSeconds();
		//std::cout << _deltatime << std::endl;
		//Event
		sf::Event _event;
		while (_window.pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
				_window.close();
			if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
				_window.close();
		}
		//Update
		//_shape.setPosition(_shape.getPosition() + sf::Vector2f(1000,0 ));
		_shape.setOrigin(0, 0);
		//_shape.rotate(_shape.getRotation() + 10 * _deltatime);
		_shape.setPosition(_shape.getPosition() + sf::Vector2f(5, 0) * _speed * _deltatime);
		if (_shape.getGlobalBounds().intersects(_shape1.getGlobalBounds()))
		{
			std::cout << "collision enter" << std::endl;
		}

		//Draw
		_window.clear();
		//if (_window.hasFocus())
		//	_window.draw(_shape);
		_window.draw(_shape);
		_window.draw(_shape1);
		//Display elements
		_window.display();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
