#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Texture texture;

    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(10.f, 10.f)),
        sf::Vertex(sf::Vector2f(150.f, 150.f))
    };
    sf::Clock clock; // démarre le chrono



    sf::Time elapsed2 = clock.getElapsedTime();
    std::cout << elapsed2.asSeconds() << std::endl;

    window.draw(line, 2, sf::Lines);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    std::cout << "a" << std::endl;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                    std::cout << "b" << std::endl;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    std::cout << "b" << std::endl;

                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    std::cout << "left" << std::endl;
                }
            }
            default:
                break;
            }
        }


        sf::Vector2i globalPosition = sf::Mouse::getPosition();
        window.clear();
        window.display();
    }
    clock.restart();

    return 0;
}
// pour chopper la lib mettre ".."a partir du projet du genre "..\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include"