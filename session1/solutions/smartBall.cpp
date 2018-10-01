#include "smartBall.h"

#include "pongUtils.h"

namespace pongShapes {
    SmartBall::SmartBall(float radius, const sf::Vector2u& windowSize) :
        sf::CircleShape(radius),
        m_windowSize(windowSize)
    {
        setPosition(float(m_windowSize.x/2U)-radius, float(m_windowSize.y/2U) - radius);
    }

    float SmartBall::getSpeedMagnitude() noexcept {
        return 6.0f;
    }

    void SmartBall::move() noexcept {
        switch(utils::outOfWindow(m_windowSize, *this)) {
            case utils::WindowSide::LEFT:
            case utils::WindowSide::RIGHT:
                m_speed.x = -m_speed.x;
                break;
            case utils::WindowSide::TOP:
            case utils::WindowSide::BOTTOM:
                m_speed.y = -m_speed.y;
                break;
            case utils::WindowSide::INSIDE:
                break;
        }
        sf::CircleShape::move(m_speed);
    }
} // namespace pongShapes
