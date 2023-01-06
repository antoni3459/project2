#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>

int main()
{
    //sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    //sf::Texture texture;

    //sf::Vertex line[] =
    //{
    //    sf::Vertex(sf::Vector2f(10.f, 10.f)),
    //    sf::Vertex(sf::Vector2f(150.f, 150.f))
    //};
    //sf::Clock clock; // démarre le chrono



    //sf::Time elapsed2 = clock.getElapsedTime();
    //std::cout << elapsed2.asSeconds() << std::endl;

    //window.draw(line, 2, sf::Lines);

    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        switch (event.type)
    //        {
    //        case sf::Event::Closed:
    //        {
    //            window.close();
    //            break;
    //        }
    //        case sf::Event::KeyPressed:
    //        {
    //            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //                std::cout << "a" << std::endl;
    //            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    //                std::cout << "b" << std::endl;
    //            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //                std::cout << "b" << std::endl;

    //            break;
    //        }
    //        case sf::Event::MouseButtonPressed:
    //        {
    //            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    //            {
    //                std::cout << "left" << std::endl;
    //            }
    //        }
    //        default:
    //            break;
    //        }
    //    }


    //    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    //    window.clear();
    //    window.display();
    //}
    //clock.restart();
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    sf::Texture texture;

    while (window.isOpen())
    {
        sf::Sprite sprite;
        sf::Sprite sprite2;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (!texture.loadFromFile("../FP/flappy.png"))
            {
            }

        } 
        sprite.setScale(sf::Vector2f(0.3f, 0.3f)); // facteurs d'échelle absolus
        sprite2.setScale(sf::Vector2f(0.3f, 0.3f)); // facteurs d'échelle absolus
        sprite.setPosition(400, 400);
        sprite2.setPosition(400, 400);
        sprite.setTexture(texture);
        sprite2.setTexture(texture);
        sprite.setOrigin(400.f, 400.f);
        sprite2.setOrigin(400.f, 400.f);

        sprite.rotate(50.f);

        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        window.display();
    }
    return 0;
}
// pour chopper la lib mettre ".."a partir du projet du genre "..\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include"