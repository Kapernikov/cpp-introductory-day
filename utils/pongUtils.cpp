#include "pongUtils.h"

#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI           3.14159265358979323846f  /* pi */
#endif

namespace utils {
    WindowSide outOfWindow(const sf::Vector2u& windowSize, const sf::Shape& shape) {
        auto shapeSize = shape.getGlobalBounds();
        auto currentPosition = shape.getPosition();

        if(shapeSize.left + shapeSize.width <= 0) {
            return WindowSide::LEFT;
        }
        if(shapeSize.left >= windowSize.x) {
            return WindowSide::RIGHT;
        }
        if(shapeSize.top + shapeSize.height >= windowSize.y) {
            return WindowSide::BOTTOM;
        }
        if(shapeSize.top <= 0) {
            return WindowSide::TOP;
        }
        return WindowSide::INSIDE;
    }

    bool isOutOfWindow(const sf::Vector2u& windowSize, const sf::Shape& shape) noexcept {
        return outOfWindow(windowSize, shape) != WindowSide::INSIDE;
    }

    sf::Vector2f middlePosition(const sf::Shape& shape) noexcept {
        auto bounds = shape.getGlobalBounds();
        return shape.getPosition() + sf::Vector2f{bounds.width/2.0f, bounds.height/2.0f};
    }

    float collisionAngle(const sf::Shape& shape1, const sf::Shape& shape2) noexcept {
        auto shape1Middle = middlePosition(shape1);
        auto shape2Middle = middlePosition(shape2);

        auto collisionDistance = shape2Middle - shape1Middle;

        auto angle = (collisionDistance.y/(shape2.getGlobalBounds().height/2.0f)) * 3.0f/M_PI;

        if(collisionDistance.x > 0) {
            angle += M_PI;
        }
        return angle;
    }

    sf::Vector2f newSpeed(float angle, float speedMagnitude) noexcept {
        std::cout << "Angle = " << angle << std::endl;
        auto xSpeed = speedMagnitude * std::cos(angle);

        if(angle > M_PI/2.0f) {
            angle -= M_PI;
        }
        auto ySpeed = -speedMagnitude * std::sin(angle);
        return sf::Vector2f{xSpeed, ySpeed};
    }

    RoundResult::RoundResult(float xPosition, float yPosition, bool leftWon) noexcept :
        m_leftWon(leftWon),
        m_left(5.0f),
        m_right(5.0f)
    {
        m_left.setPosition(xPosition - 2.0f * m_left.getRadius(), yPosition);
        m_right.setPosition(xPosition + 2.0f * m_right.getRadius(), yPosition);

        m_left.setOutlineThickness(1);
        m_right.setOutlineThickness(1);

        m_left.setOutlineColor(sf::Color::White);
        m_right.setOutlineColor(sf::Color::White);

        auto& winner = leftWon ? m_left : m_right;
        auto& loser = leftWon ? m_right : m_left;

        winner.setFillColor(sf::Color::White);
        loser.setFillColor(sf::Color::Black);
    }

    void RoundResult::draw(sf::RenderWindow& window) noexcept {
        window.draw(m_left);
        window.draw(m_right);
    }

    bool RoundResult::leftWon() const noexcept {
        return m_leftWon;
    }
} // namespace utils
