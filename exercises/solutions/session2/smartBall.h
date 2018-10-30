#ifndef SMART_BALL_INCLUDE
#define SMART_BALL_INCLUDE

#include <SFML/Graphics.hpp>

namespace pongShapes {
    class SmartBall : public sf::CircleShape {
        public:
            SmartBall(float radius, const sf::Vector2u& windowSize);

            static float getSpeedMagnitude() noexcept;

            void move() noexcept;
            void resetPosition() noexcept;
            void hit(const sf::Shape& shape) noexcept;

        private:
            static float speedMagnitude;
            sf::Vector2f m_speed{getSpeedMagnitude(), 0.0f};
            sf::Vector2u m_windowSize;
    };
} // namespace utils
#endif  /* SMART_BALL_INCLUDE */
