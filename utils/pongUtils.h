#ifndef PONG_UTILS_INCLUDE
#define PONG_UTILS_INCLUDE

#include <SFML/Graphics.hpp>

namespace utils {
    enum class WindowSide {
        INSIDE,
        TOP,
        BOTTOM,
        LEFT,
        RIGHT
    };

    /**
     * Returns the WindowSide the given shape is on
     */
    WindowSide outOfWindow(const sf::Vector2u& windowSize, const sf::Shape& shape);

    /**
     * Returns whether the given shape is within the window
     */
    bool isOutOfWindow(const sf::Vector2u& windowSize, const sf::Shape& shape) noexcept;

    sf::Vector2f middlePosition(const sf::Shape& shape) noexcept;

    float collisionAngle(const sf::Shape& shape1, const sf::Shape& shape2) noexcept;

    sf::Vector2f newSpeed(float angle, float speedMagnitude) noexcept;

    class RoundResult {
        public:
            RoundResult(float xPosition, float yPosition, bool leftWon) noexcept;

            void draw(sf::RenderWindow& window) noexcept;
            bool leftWon() const noexcept;

        private:
            bool m_leftWon;
            sf::CircleShape m_left;
            sf::CircleShape m_right;
    };
} // namespace utils

#endif  /* PONG_UTILS_INCLUDE */
