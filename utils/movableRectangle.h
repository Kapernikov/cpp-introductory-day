#ifndef MOVABLE_RECTANGLE_INCLUDE
#define MOVABLE_RECTANGLE_INCLUDE

#include <SFML/Graphics.hpp>

namespace utils {
    class MovableRectangle : public sf::RectangleShape {
        public:
            MovableRectangle(const sf::Vector2f& dimensions) noexcept;
            virtual void move(float x, float y);
            virtual void move(const sf::Vector2f& offset);
    };
} // namespace utils

#endif  /* MOVABLE_RECTANGLE_INCLUDE */
