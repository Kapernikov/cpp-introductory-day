#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "smartBall.h"

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& value) {
    os << "[" << value.x << "," << value.y << "]";
    return os;
}

int main(int /*argc*/, char** /*argv*/) {
    std::cout << "Hello world!!!" << std::endl;

    sf::Vector2f printVector(42, 43);
    std::cout << printVector << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setVerticalSyncEnabled(true);

    pongShapes::SmartBall ball(10.0f, window.getSize());
    ball.setFillColor(sf::Color::White);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    // Ignore invalid events
                    break;
            }
        }

        ball.move();

        window.clear();
        window.draw(ball);
        window.display();
    }
    return EXIT_SUCCESS;
}
