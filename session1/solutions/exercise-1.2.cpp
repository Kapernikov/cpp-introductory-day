#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main(int /*argc*/, char** /*argv*/) {
    std::cout << "Hello world!!!" << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
        window.display();
    }
    return EXIT_SUCCESS;
}
