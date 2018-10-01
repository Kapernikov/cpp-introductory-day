#include "movableRectangle.h"

namespace utils {
    MovableRectangle::MovableRectangle(const sf::Vector2f& dimensions) noexcept :
        sf::RectangleShape(dimensions)
    {
        ;
    }

    void MovableRectangle::move(float x, float y) {
        sf::RectangleShape::move(x, y);
    }

    void MovableRectangle::move(const sf::Vector2f& offset) {
        sf::RectangleShape::move(offset);
    }
} // namespace pongUtils
