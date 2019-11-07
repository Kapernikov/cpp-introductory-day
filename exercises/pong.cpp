#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& value) {
    os << "[" << value.x << "," << value.y << "]";
    return os;
}

int main(int /*argc*/, char** /*argv*/) {
    std::cout << "Hello world!!!" << std::endl;

    sf::Vector2f printVector(42, 43);
    std::cout << printVector << std::endl;

    sf::RenderWindow window(sf::VideoMode(200, 200, 16), "SFML works!");

    // <-- Do your one-time calculations here -->

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

        // <-- Do your iterative calculations here -->
        
        
        
        // <-- Call all objects to (re-)render here

        window.display();
    }
    return EXIT_SUCCESS;
}
