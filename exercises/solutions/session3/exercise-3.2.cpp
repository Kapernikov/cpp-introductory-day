#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "smartBall.h"
#include "bat.h"
#include "pongUtils.h"

const sf::Vector2f playerSize{10.0f, 150.0f};
const sf::Vector2f stepSize{0.0f, -20.0f};

std::ostream& operator<<(std::ostream& os, const sf::Vector2f& value) {
    os << "[" << value.x << "," << value.y << "]";
    return os;
}

template<typename T, typename U>
bool isHit(const T& shape1, const U& shape2) noexcept {
    return shape1.getGlobalBounds().intersects(shape2.getGlobalBounds());
}

int main(int /*argc*/, char** /*argv*/) {
    std::cout << "Hello world!!!" << std::endl;

    sf::Vector2f printVector(42, 43);
    std::cout << printVector << std::endl;

    sf::RenderWindow window(sf::VideoMode(400, 400, 16), "C++ Introductory day: Pong!");
    window.setVerticalSyncEnabled(true);

    std::vector<utils::RoundResult> score;

    pongShapes::SmartBall ball(10.0f, window.getSize(), [&score, &window](utils::WindowSide side) {
            static float yPosition = 150.0f;
            switch(side) {
                case utils::WindowSide::LEFT:
                case utils::WindowSide::RIGHT:
                    score.emplace_back(window.getSize().x/2.0f, yPosition, side == utils::WindowSide::RIGHT);
                    yPosition += 20.0f;
                    break;
                default:
                    break;
            }
        });
    ball.setFillColor(sf::Color::White);

    std::unique_ptr<pongShapes::Bat> player1(new pongShapes::Bat(playerSize));
    player1->setFillColor(sf::Color::White);
    player1->setPosition(0.0f, (window.getSize().y-playerSize.y)/2.0f);

    std::unique_ptr<pongShapes::Bat> player2(new pongShapes::Bat(*player1)); // Use the copy constructor for player 2
    player2->setPosition(window.getSize().x-playerSize.x, (window.getSize().y-playerSize.y)/2.0f);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/ancient-scripts/Musica_hint.ttf"))
    {
        std::cerr << "Could not load font. No text shapes will be available." << std::endl;
    }

    sf::Text scoreText;
    scoreText.setFillColor(sf::Color::White);
    scoreText.setFont(font);
    scoreText.setCharacterSize(100);

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
                case sf::Event::KeyReleased:
                    switch(event.key.code) {
                        case sf::Keyboard::A:
                            try {
                                player1->move(stepSize);
                            } catch(const pongShapes::InvalidMovement&) {
                                std::cerr << "Invalid movement: " << stepSize << std::endl;
                            }
                            break;
                        case sf::Keyboard::S:
                            try {
                                player1->move(-stepSize);
                            } catch(const pongShapes::InvalidMovement&) {
                                std::cerr << "Invalid movement: " << stepSize << std::endl;
                            }
                            break;
                        case sf::Keyboard::J:
                            try {
                                player2->move(stepSize);
                            } catch(const pongShapes::InvalidMovement&) {
                                std::cerr << "Invalid movement: " << stepSize << std::endl;
                            }
                            break;
                        case sf::Keyboard::K:
                            try {
                                player2->move(-stepSize);
                            } catch(const pongShapes::InvalidMovement&) {
                                std::cerr << "Invalid movement: " << stepSize << std::endl;
                            }
                            break;

                        default:
                            break;
                    }
                    break;
                default:
                    // Ignore invalid events
                    break;
            }
        }

        ball.move();

        if(isHit(*player1, ball)) {
            std::cout << "Player 1 hits the ball!" << std::endl;
            ball.hit(*player1);
        }

        if(isHit(*player2, ball)) {
            std::cout << "Player 2 hits the ball!" << std::endl;
            ball.hit(*player2);
        }

        auto player1Score = std::count_if(score.begin(), score.end(), [](const utils::RoundResult& result) { return result.leftWon(); });
        auto player2Score = score.size() - player1Score;
        scoreText.setString(std::to_string(player1Score).append("-").append(std::to_string(player2Score)));
        scoreText.setPosition((window.getSize().x-scoreText.getGlobalBounds().width)/2.0f, 0);
       
        window.clear();
        window.draw(ball);
        window.draw(*player1);
        window.draw(*player2);
        std::for_each(score.begin(), score.end(), [&window](utils::RoundResult& result) { result.draw(window);});
        window.draw(scoreText);
        window.display();
    }
    return EXIT_SUCCESS;
}
