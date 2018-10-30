#include "smartBall.h"

#include <utility>

namespace pongShapes {
    SmartBall::SmartBall(float radius, const sf::Vector2u& windowSize, OutOfWindowCallback callback) :
        sf::CircleShape(radius),
        m_windowSize(windowSize),
        m_callback(std::move(callback))
    {
        resetPosition();
    }

    float SmartBall::getSpeedMagnitude() noexcept {
        return 6.0f;
    }

    void SmartBall::resetPosition() noexcept {
        setPosition(float(m_windowSize.x/2U)-getRadius(), float(m_windowSize.y/2U) - getRadius());
    }

    void SmartBall::move() noexcept {
        auto windowSize = utils::outOfWindow(m_windowSize, *this);
        switch(windowSize) {
            case utils::WindowSide::LEFT:
            case utils::WindowSide::RIGHT:
                {
                    resetPosition();
                    auto direction = m_speed.x/std::abs(m_speed.x);
                    m_speed = sf::Vector2f{-direction * getSpeedMagnitude(), 0.0f};
                    m_callback(windowSize);
                    break;
                }
            case utils::WindowSide::TOP:
            case utils::WindowSide::BOTTOM:
                m_speed.y = -m_speed.y;
                break;
            case utils::WindowSide::INSIDE:
                break;
        }
        sf::CircleShape::move(m_speed);
    }

    void SmartBall::hit(const sf::Shape& shape) noexcept {
        m_speed = utils::newSpeed(utils::collisionAngle(*this, shape), getSpeedMagnitude()); 
    }
} // namespace pongShapes
